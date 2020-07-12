long switch_prob(long x, long n) {
  long result = x;

  switch(n) {
    case 60:
    case 62:
      result = x * 8;
      break;
    case 63:
      result = x;
      result >>= 3;
      break;
    case 64:
      result = x
      result <<= 4
      result -= x
      x = result
    case 65:
      x = x * x;
    default:
      result = 0x4B + x
  }
  return result;
}


