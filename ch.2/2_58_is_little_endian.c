/* Write a procedure is_little_endian that will return 1 when compiled and run */
/* on a little-endian machine, and will return 0 when compiled and run on a bigendian */
/* machine. This program should run on any machine, regardless of its word */
/* size. */

#include <stdio.h>

typedef unsigned char *byte_pointer;

int is_little_endian() {
  int num = 1;
  byte_pointer start = (byte_pointer) &num;
  int result;
  
  result = ( 0x01 == start[0] ? 1 : 0 );
  return result;
}

int main (void)
{
  printf("result: %d", is_little_endian());
  return is_little_endian();
}


