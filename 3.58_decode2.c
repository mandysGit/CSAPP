long decode2(long x, long y, long z) {
  y = y - z;
  x = x * y;

  long result = y;

  result <<= 63;
  result >>= 63;
  result = result ^ x;

  return result;
}
