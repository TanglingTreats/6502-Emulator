#include <stdio.h>
#include <stdlib.h>

// using keyword as alias
using Byte = unsigned char;
using Word = unsigned short;

struct CPU
{

  Word PC;  // Program Counter


  Byte SP;  // Stack Pointer
  Byte A, X, Y; // Accumulator, Register X, Y

  // Bit fields
  Byte C : 1; // Carry Flag
  Byte Z : 1; // Zero Flag
  Byte I : 1; // Interrupt Disable Flag
  Byte D : 1; // Decimal Mode Flag
  Byte B : 1; // Break Command Flag
  Byte V : 1; // Overflow Flag
  Byte N : 1; // Negative Flag

  void Reset()
  {
    PC = 0xFFFC;
    SP = 0x0100;
    // Clear flags
    C = Z = I = D = B = V = N = 0;

    // Clear registers
    A = X = Y = 0;
  }
}

int main()
{
  CPU cpu;
  cpu.Reset();
  return 0;
}
