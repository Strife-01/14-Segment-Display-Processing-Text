/* 
 * File:   text_processing.h
 * Author: S y N c R o N
 *
 * Created on December 8, 2023, 10:57 AM
 */

#ifndef TEXT_PROCESSING_H
#define	TEXT_PROCESSING_H

#define SOURCE_LOCAL_TEXT 0
#define SOURCE_LOCAL_BANNER 1


typedef enum
{    
    SrcIdx_banner_0 = 0,
    SrcIdx_banner_1,
    SrcIdx_banner_2,
    SrcIdx_banner_3,
    SrcIdx_txt_payload,
    SrcIdx_max,
   
} source_index_type;

void text_processing(void);


void set_text(unsigned char *text_source, unsigned int text_offset, unsigned int text_length);
void set_banner_text(unsigned char banner_index, unsigned char * banner_source);
void choose_source(source_index_type source_indicator);

#endif	/* TEXT_PROCESSING_H */

