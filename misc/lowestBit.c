#include<stdio.h>
//
// Position of lowest bit set
// Ref: http://bits.stephan-brumme.com/lowestBitSet.html
//
const unsigned int MultiplyDeBruijnBitPosition[32] =
{
  // precomputed lookup table
  0,  1, 28,  2, 29, 14, 24,  3, 30, 22, 20, 15, 25, 17,  4,  8,
  31, 27, 13, 23, 21, 19, 16,  7, 26, 12, 18,  6, 11,  5, 10,  9
};

//
// A negative number is usually represented by the two-complement: −x = not(x)+1
//
// The formula x & −x = x & (not(x) + 1) deletes all but the lowest set bit (line 35).
//
// That means after line 35 we have a power of 2 and there are obviously only 32 possibilities left.
// When multiplied by the DeBruijn constant 0x077CB531 (line 37), the upper 5 bits are unique for each power of 2.
// A small lookup table resolves the actual position of the lowest bit set (line 5 to 10, line 39).
// The overall performance of this algorithm is mainly determined by the lookup table and
// the numbers given below are based on full cache hits.
//
// Note: DeBruijn sequences are extensively explained by Wikipedia, too.
//
// The simple version performs surprisingly well for randomly distributed input:
// 50% of all integers are odd and their result will be 0. Another 25% result will be 1, therefore the loop terminates pretty early.
// When numbers with long spans of zeros are processed, timings become significantly worse.
// The observed break-even was lowestBitSet(32) on a Pentium D, your mileage may vary.
//
// The fastest way on almost all modern x86/x64 CPU bases on the built-in BSF instruction.
//
// Restriction: designed for 32 bits
//
unsigned int lowestBitSet(unsigned int x)
{
  // only lowest bit will remain 1, all others become 0
  x  &= -((int)x);
  // DeBruijn constant
  x  *= 0x077CB531;
  // the upper 5 bits are unique, skip the rest (32 - 5 = 27)
  x >>= 27;
  // convert to actual position
  return MultiplyDeBruijnBitPosition[x];
}

int main(){

  unsigned int a=96;
  printf("%d\n",lowestBitSet(a));

  return 0;
}
