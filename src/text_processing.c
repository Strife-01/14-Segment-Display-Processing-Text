#include "text_processing.h"
#include "frame_management.h"
#include "system_conf.h"

#define SUCCESS 0
#define TEXT_LENGTH_ERROR 1
#define NR_BANNERS 4
#define PRINT_COUNTR_LIMIT 40
#define SHIFTING_NR_CHARACTERS 1

void manage_payload_text(void);

unsigned char *local_text_source;
unsigned int local_text_offset;
unsigned int local_text_length;
unsigned char padding_num = 0;
source_index_type local_text_indicator = 0;
unsigned char fresh_text_flag = 0;
unsigned char add_padding_flag = 0;
unsigned long frame_counter_block = 0;

unsigned char banner_0[TOTAL_DIG];
unsigned char banner_1[TOTAL_DIG];
unsigned char banner_2[TOTAL_DIG];
unsigned char banner_3[TOTAL_DIG];
unsigned char padding_buffer[TOTAL_DIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void text_processing(void)
{
    unsigned int print_counter;
    // Get the latest nr of frame prints
    print_counter = get_frame_print_counter();
    
    if (print_counter < PRINT_COUNTR_LIMIT)
    {
        // Keep printing until the frame-rate
    }
    else
    {
        // Reset the counter
        reset_frame_print_counter();
        
        // Choose source
        switch (local_text_indicator)
        {
            case SrcIdx_banner_0:
            {
                load_text(banner_0);
            }
            break;
            
            case SrcIdx_banner_1:
            {
                load_text(banner_1);
            }
            break;
            
            case SrcIdx_banner_2:
            {
                load_text(banner_2);
            }
            break;
            
            case SrcIdx_banner_3:
            {
                load_text(banner_3);
            }
            break;
            
            case SrcIdx_txt_payload:
            {
                manage_payload_text();
            }
            break;
        }
    }
}

void set_text(unsigned char *text_source, unsigned int text_offset, unsigned int text_length)
{
    local_text_source = text_source;
    local_text_offset = text_offset;
    local_text_length = text_length;
    
    // Signalize we have new payload text
    fresh_text_flag = 1;
}

void set_banner_text(unsigned char banner_index, unsigned char * banner_source)
{
    unsigned char *buffer;
    unsigned char index;

    
    if (banner_index < NR_BANNERS)
    {
    
        switch (banner_index)
        {
            case 0:
            {
                buffer = banner_0;
            }
            break;

            case 1:
            {
                buffer = banner_1;
            }
            break;

            case 2:
            {
                buffer = banner_2;
            }
            break;

            case 3:
            {
                buffer = banner_3;
            }
            break;
        }

        for (index = 0; index < TOTAL_DIG; index++)
        {
            buffer[index] = banner_source[index];
        }
    }
}

void choose_source(source_index_type source_indicator)
{
    if (source_indicator < SrcIdx_max)
    {
        // Save local text source indicator
        local_text_indicator = source_indicator;
    }
    else
    {
        // Do nothing, BAD PARAMETER
    }
}

void manage_payload_text(void)
{
    // Reset index
    unsigned char index;
    unsigned long position = 0;
    unsigned long total_dig_blocks = 0;
    unsigned char * txt_src;
    unsigned long location;
    //unsigned char * ptr_last_text_char = (unsigned char *)(&(txt_src[local_text_length - 1]));
    unsigned long last_char_index = local_text_length - 1;
    unsigned long current_start_index_block;
    
    if (fresh_text_flag == 1)
    {
        // Manage padding
        padding_num = local_text_length % TOTAL_DIG;
        total_dig_blocks = local_text_length / TOTAL_DIG;
        if ((local_text_offset + TOTAL_DIG) > local_text_length)
        {
            // Signalize padding
            add_padding_flag = 1;
            
            // Clean padding buffer
            for (index = 0; index < TOTAL_DIG; index++)
            {
                padding_buffer[index] = 0;
            }
            
            // Populate padding buffer until total dig - padding
            for (index = 0; index < TOTAL_DIG - padding_num; index++)
            {
                position = local_text_offset + frame_counter_block * TOTAL_DIG;
                padding_buffer[index] = local_text_source[position + index];
            }
        }
        else
        {
            add_padding_flag = 0;
        }
    }
    
    if (frame_counter_block < (total_dig_blocks * TOTAL_DIG))
    {
        location = local_text_offset + frame_counter_block * SHIFTING_NR_CHARACTERS;
        current_start_index_block = location;
        txt_src = (unsigned char *)(&(local_text_source[location]));
    }
    else
    {
        txt_src = padding_buffer;
    }
    
    
    load_text(txt_src);
    
    // Slice next frame of text
    frame_counter_block++;
    
    if (current_start_index_block + TOTAL_DIG > last_char_index)
    {
        frame_counter_block = 0;   
        //txt_src = (unsigned char *)(&(local_text_source[local_text_offset]));
    }
    else
    {
        // DO NOTHING
    }
    
}