#include <avr/io.h> 
#include <stdlib.h>
#include "USBtoSerial.h"
#include "misc.h"


char stringbuffer[16];

// convert an unsigned integer to string
void my_uitoa(uint32_t zahl, char* string, uint8_t no_digits, char leading_char) {
  int8_t i; // schleifenzähler

  string[no_digits] = '\0'; // String Terminator
  for (i = (no_digits - 1); i >= 0; i--) {
    if (zahl == 0 && i < (no_digits - 1)) {
      string[i] = leading_char;
    } else {
      string[i] = (zahl % 10) + '0';
    } // Modulo rechnen, dann den ASCII-Code von '0' addieren
    zahl /= 10;
  }

}

uint32_t times_ten_pow(uint8_t exponent) {
  uint32_t val = 1;
  for (uint8_t i = 1; i <= exponent; i++) {
    val *= 10;
  }
  return val;
}

int8_t sign(int16_t x) {
  return (x > 0) - (x < 0);
}


void uart_print_number(uint32_t zahl, uint8_t no_digits) {
  my_uitoa(zahl,stringbuffer,no_digits,' ');
  uart_puts(stringbuffer);
}


void uart_print_number_wlzeros(uint32_t zahl, uint8_t no_digits) {
  my_uitoa(zahl,stringbuffer,no_digits,'0');
  uart_puts(stringbuffer);
}

void uart_print_signed_number(int32_t zahl, uint8_t no_digits) {
  my_uitoa(abs(zahl),stringbuffer,no_digits,' ');
  if (zahl < 0) {
    uart_putc('-');
  } else {
    uart_putc('+');
  }
  uart_puts(stringbuffer);
  
}

void uart_print_sign(int32_t zahl){
  if (zahl < 0) {
    uart_putc('-');
  } else {
    uart_putc('+');
  }
}