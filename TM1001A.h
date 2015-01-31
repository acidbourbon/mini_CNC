// This code is based on the work of Frank H. (franky1969) from the
// Mikrocontroller.net forum.
// I modified the code thusly that it runs on an ATMega8 with more than 8 MHz
// (make use of the counter 0 overflow interrupt to count to numbers greater
// than 255) and added a set of functions that make your life easy,
// i.e. spare you the work of crawling through the ADB register documentation yourself.
//
// You cannot use counter 0 for any other thing when using the touchpad!
//
// Have fun! - Michael W. (acidbourbon)
//
// acidbourbon.wordpress.com
// June 2013

#include <avr/interrupt.h>

// define here the port and the pin where you cave connected
// the ADB (I/O) line from your TM1001A touchpad
#define ADB_BIT (1<<0)
#define ADB_PIN PIND
#define ADB_POUT PORTD
#define ADB_PDIR DDRD

// when touchpad is in keypad mode the next two defines set the number
// of rows and columns of the
#define PAD_ROWS 2
#define PAD_COLS 3


#define MIN_ABS_X 150
#define MAX_ABS_X 1450
#define MIN_ABS_Y 210
#define MAX_ABS_Y 1130

#define PAD_WIDTH (MAX_ABS_X-MIN_ABS_X)
#define PAD_HEIGHT (MAX_ABS_Y-MIN_ABS_Y)
#define PAD_COL_WIDTH (PAD_WIDTH/PAD_COLS)
#define PAD_ROW_HEIGHT (PAD_HEIGHT/PAD_ROWS)

typedef unsigned char u08;
typedef unsigned short int u16;


ISR( TIMER0_OVF_vect);

uint16_t t0ext(void);

void t0rst(void);

u08 adb(void);

void touchpad_init(void);

uint8_t touchpad_read(void);

void touchpad_set_abs_mode(void);

void touchpad_set_rel_mode_100dpi(void);

void touchpad_set_rel_mode_200dpi(void);

uint8_t z_pressure(void);

uint16_t x_abs(void);

uint16_t y_abs(void);

int8_t delta_y(void);

int8_t delta_x(void);

uint8_t decode_field(void);
