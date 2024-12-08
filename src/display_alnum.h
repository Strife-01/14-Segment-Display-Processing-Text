#ifndef DISPLAY_ALNUM_H

#define	DISPLAY_ALNUM_H

// Returns the binary value of PORT A
unsigned char digit_val_conv_port_a(unsigned char digit_index);

// Returns the binary value of PORT B
unsigned char digit_val_conv_port_b(unsigned char digit_index);

// Returns the binary value of PORT C
unsigned char ascii_conv_port_c(unsigned char c);

// Returns the binary value of PORT D
unsigned char ascii_conv_port_d(unsigned char c);


#endif	/* DISPLAY_ALNUM_H */
