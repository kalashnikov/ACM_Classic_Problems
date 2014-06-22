//
// Bit Twiddling Hacks
//
// This page is scratched from  
// http://graphics.stanford.edu/~seander/bithacks.html
//

#include <stdio.h>


int main() {

    // ============================================================================ 
    // Compute the sign of an integer
    // ============================================================================ 
    int v;      // we want to find the sign of v
    int sign;   // the result goes here 

    // CHAR_BIT is the number of bits per byte (normally 8).
    sign = -(v < 0);  // if v < 0 then -1, else 0. 
    // or, to avoid branching on CPUs with flag registers (IA32):
    sign = -(int)((unsigned int)((int)v) >> (sizeof(int) * CHAR_BIT - 1));
    // or, for one less instruction (but not portable):
    sign = v >> (sizeof(int) * CHAR_BIT - 1); 
    sign = (v > 0) - (v < 0); // -1, 0, or +1
    sign = 1 ^ ((unsigned int)v >> (sizeof(int) * CHAR_BIT - 1)); // if v < 0 then 0, else 1


    // ============================================================================ 
    // Detect if two integers have opposite signs
    // ============================================================================ 
    int x, y;               // input values to compare signs
    bool f = ((x ^ y) < 0); // true iff x and y have opposite signs


    // ============================================================================ 
    // Compute the integer absolute value (abs) without branching
    // ============================================================================ 
    int v;           // we want to find the absolute value of v
    unsigned int r;  // the result goes here 
    int const mask = v >> sizeof(int) * CHAR_BIT - 1;
    r = (v + mask) ^ mask;

    
    // ============================================================================ 
    // Compute the minimum (min) or maximum (max) of two integers without branching
    // ============================================================================ 
    int x;  // we want to find the minimum of x and y
    int y;   
    int r;  // the result goes here 
    r = y ^ ((x ^ y) & -(x < y)); // min(x, y)
    r = x ^ ((x ^ y) & -(x < y)); // max(x, y)

    // If you know that INT_MIN <= x - y <= INT_MAX, 
    // then you can use the following, which are faster because (x - y) only needs to be evaluated once.
    r = y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))); // min(x, y)
    r = x - ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))); // max(x, y)


    // ============================================================================ 
    // Determining if an integer is a power of 2
    // ============================================================================ 
    unsigned int v; // we want to see if v is a power of 2
    bool f;         // the result goes here 
    f = (v & (v - 1)) == 0;
    // Note that 0 is incorrectly considered a power of 2 here. To remedy this, use:
    f = v && !(v & (v - 1));

    return 0;
}

