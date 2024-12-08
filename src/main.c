#include "config_bits.h"
#include "display_alnum.h"
#include "frame_management.h"
#include "system_conf.h"
#include "text_processing.h"
#include <stdio.h>
#include <stdlib.h>

unsigned char TEXT_MAIN[] = "I AM ANDREI URSACHI AND I WOULD LOVE TO BECOME A NEW ASSET OF YOUR SOFTWARE TEAM";//fringilla nulla sit amet, ullamcorper felis. Ut sed risus accumsan, laoreet mi vitae, semper dolor. Ut aliquet, mauris quis efficitur posuere, metus tortor euismod ligula, vel elementum lacus orci nec tellus. Ut mattis hendrerit nisl, eu ultricies leo ornare eu. Proin consectetur ligula non libero mattis, at condimentum urna laoreet. Curabitur eget tincidunt ipsum. Etiam erat odio, tempor sed urna gravida, consequat placerat risus. Nam vitae ullamcorper velit. Etiam id nibh maximus, iaculis mauris at, egestas nulla. Mauris semper luctus dapibus. Integer lacinia consectetur ullamcorper. Vivamus eu orci lacus.";
unsigned char BANNER_0[TOTAL_DIG] = "ANDREIURSAKI";
unsigned char BANNER_1[TOTAL_DIG] = "  ANGHELINA ";
unsigned char BANNER_2[TOTAL_DIG] = "DRAGOS HINCU";
unsigned char BANNER_3[TOTAL_DIG] = "MIHAIURSACHI";

int main(int argc, char** argv)
{   
    unsigned int main_text_length = sizeof(TEXT_MAIN) / sizeof(TEXT_MAIN[0]);
   
    port_setup();

    // Set src text
    set_text(TEXT_MAIN, 0, main_text_length);
    set_banner_text(0, BANNER_0);
    set_banner_text(1, BANNER_1);
    set_banner_text(2, BANNER_2);
    set_banner_text(3, BANNER_3);
    
    choose_source(SrcIdx_txt_payload);
    
    // Turn on lowside driver

    // needed for test
    unsigned char text = 0;
    
    while(1)
    {
        print_frame();
        text_processing();
    }
    
    return (EXIT_SUCCESS);
}



