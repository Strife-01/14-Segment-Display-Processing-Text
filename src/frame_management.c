#include "config_bits.h"
#include "display_alnum.h"
#include "frame_management.h"
#include "system_conf.h"

#define RESET_THRESHOLD 0xFFFF

#ifndef TIME
#define TIME 1800

#endif

void busy_wait(unsigned long time);

void text_convert(void);

unsigned char port_a_values_digits[TOTAL_DIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char port_b_values_digits[TOTAL_DIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


unsigned char input[TOTAL_DIG];
unsigned char port_c_values_characters[TOTAL_DIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned char port_d_values_characters[TOTAL_DIG] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

unsigned char ONE_TIME_CALL = 0;

unsigned int frame_print_counter = 0;


void dig_val_convert(void)
{
    unsigned char dig;
    
    if (ONE_TIME_CALL == 0)
    {
        for (dig = 0; dig < TOTAL_DIG; dig++)
        {
            port_a_values_digits[dig] = digit_val_conv_port_a(dig);
            port_b_values_digits[dig] = digit_val_conv_port_b(dig);
        }
        ONE_TIME_CALL = 1;
    }
    
}

void busy_wait(unsigned long time)
{
    for (unsigned long i = 0; i < time; i++)
    {
        // continue
    }
}

void print_frame(void)
{
    unsigned char dig;
    
    dig_val_convert();
    
    for (dig = 0; dig < TOTAL_DIG; dig++)
    {
        PORTA = port_a_values_digits[dig];
        PORTB = port_b_values_digits[dig];
        PORTC = port_c_values_characters[dig];
        PORTD = port_d_values_characters[dig];
        busy_wait(TIME);
    }
    
    if (frame_print_counter < RESET_THRESHOLD)
    {
        frame_print_counter++;
    }
    else
    {
        reset_frame_print_counter();
    }
    
}

void load_text(unsigned char * string)
{
    unsigned char index;
    for (index = 0; index < TOTAL_DIG; index++)
    {
        input[index] = string[index];
    }
    
    text_convert();
}

void text_convert(void)
{
    // Parse Input
    unsigned char i;
    for (i = 0; i < TOTAL_DIG; i++)
    {
        port_c_values_characters[i] = ascii_conv_port_c(input[i]);
        port_d_values_characters[i] = ascii_conv_port_d(input[i]);
    }
}

unsigned int get_frame_print_counter(void)
{
    return frame_print_counter;
}

void reset_frame_print_counter(void)
{
    frame_print_counter = 0;
}