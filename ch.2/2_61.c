#include <stdio.h>
#include <limits.h>

/* Return 1 if any byte from x equals 1 */
int any_one_byte(int x) {
  int max = 0xFFFFFFFF;
  return x && max;
}

/* Return 1 if any byte from x equals 0 */
int any_zero_byte(int x) {
  int min = 0x0;
  int nxor_result = ~(x ^ min);
  return nxor_result || min;
}

/* Return 1 if Any bit in the LEAST sig byte of x equals 1 */
int LSB_has_one(int x) {
  int LSB = x & 0xFF; /* Zero all but LSB */
  return any_one_byte(LSB);
}

/* Return 1 if Any bit in the MOST sig byte of x equals 0 */
int MSB_has_zero(int x) {
  /* Shift by w-8 */
  int shift_val = (sizeof(int)-1)<<3;
  /* Right Arithmetic shift, MSB padded with ones on the left*/
  int xright = x >> shift_val;
  return any_zero_byte(xright);
}

int main(void) {
  printf("%x%c", any_one_byte(0x1), '\n');  // 1 true
  printf("%x%c", any_one_byte(0x0), '\n'); // 0 false

  printf("%x%c", any_zero_byte(0x0), '\n');        // 1 true
  printf("%x%c", any_zero_byte(0xFFFFFFFF), '\n'); // 0 false

  printf("%x%c",LSB_has_one(0xaabbcc10), '\n'); // 1 true
  printf("%x%c",LSB_has_one(0xaabbcc01), '\n'); // 1 true
  printf("%x%c",LSB_has_one(0xaabbcc00), '\n'); // 0 false

  printf("%x%c",MSB_has_zero(0x0fbbccdd), '\n'); // 1 true
  printf("%x%c",MSB_has_zero(0xf0bbccdd), '\n'); // 1 true
  printf("%x%c",MSB_has_zero(0xffbbccdd), '\n'); // 0 false
}
