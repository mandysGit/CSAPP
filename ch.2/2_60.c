/* Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 − 1 */
/* (most significant). Write code for the following C function, which will return an */
/* unsigned value in which byte i of argument x has been replaced by byte b: */
/* unsigned replace_byte (unsigned x, int i, unsigned char b); */
/* Here are some examples showing how the function should work: */
/* replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678 */
/* replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB */

#include <stdio.h>

void replace_byte(unsigned x, int i, unsigned char b) {
  typedef unsigned char *byte_pointer;
  byte_pointer start = (byte_pointer) &x;
  size_t len = sizeof(x);

  for (int j = 0; j < len; j++) {
    if (j == i) {
      start[i] = b;
    }
  }

  printf("%x", x);
  printf("\n");
}

int main(void) {
  replace_byte(0x12345678, 2, 0xAB);
  replace_byte(0x12345678, 0, 0xAB);
}
