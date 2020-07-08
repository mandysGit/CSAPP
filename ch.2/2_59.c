#include <stdio.h>

int main(void) {
  int x = 0x89ABCDEF; // 8 digits
  int y = 0x76543210;

  int least_sig_byte = 0x000000FF & x;
  int most_sig_bytes = 0xFFFFFF00 & y;
  int test = least_sig_byte | most_sig_bytes;

  printf("%x", least_sig_byte);
  printf("\n");
  printf("%x", most_sig_bytes);
  printf("\n");
  printf("%x", test);
  printf("\n");
}
