#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
 int i;
 for (i = 0; i < len; i++)
 printf(" %.2x", start[i]);
 printf("\n");
}

void show_int(int x) {
 show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
 show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
 show_bytes((byte_pointer) &x, sizeof(void *));
}


void test_show_bytes(int val) {
  int ival = val;
  float fval = (float) ival;
  int *pval = &ival;

  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}

int main(void) {
  test_show_bytes(12345);
  // 39 30 00 00
  // 00 e4 40 46
  // 08 01 84 c6 fe 7f 00 00
  test_show_bytes(9090);
  // 82 23 00 00
  // 00 08 0e 46
  // 68 00 56 7b ff 7f 00 00
}
