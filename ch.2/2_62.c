/*
1. Compute the machine's word size
2. Initialize int 0xF as `num`
3. Initialize `msb_is_num` as `num` left shifted by (left_shift_val * 4 bits)
3. Right shift `msb_is_num` by 4 bits, the result of this can show if the machine is doing an Arithmetic Shift or Logical Shift
4. If result & msb_is_num does not equal to zero, then it is arithmetic shift, otherwise logical shift.

To test out logical shift, try: int logical_result = (unsigned int)msb_is_num >> 4;

example of step 4 (arith)
F0 00 00 00
FF 00 00 00
AND result: F0 00 00 00

example of step 4 (logical)
F0 00 00 00
0F 00 00 00
AND result: 00 00 00 00

Left Shifts:
- the most-significant bit is lost, and a 0 bit is inserted on the other end.

Logical Right Shifts:
- the least-significant bit is lost and a 0 is inserted on the other end.

Arithmetic shift:
- the least-significant bit is lost and the most-significant bit is copied.
*/

#include <stdio.h>

int int_shifts_are_arithmetic() {
  // sizeof(void *) is 4 for 32 and 8 for 64 bit platforms
  int word_size = sizeof(void *);
  int left_shift_val = word_size - 1;
  int num = 0xF;
  int msb_is_num = num << left_shift_val * 4;
  int result = msb_is_num >> 4;

  return (result & msb_is_num) != 0x0;
}

int main(void) {
  printf("%x%c", int_shifts_are_arithmetic(), '\n');
}

