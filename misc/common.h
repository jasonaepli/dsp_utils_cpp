#ifndef COMMON_H
#define COMMON_H

enum SampFormat {
  ComplexUint,  // Complex Unsigned Integer
  ComplexInt,   // Complex Integer
  ComplexReal,  // Complex Real, e.g., complex<float>
  Uint,         // Unsigned Integer
  Int,          // Signed Integer
  Real,         // Real, e.g., float, double
};

enum BitDepth {
  b8,   // 8 bit samples
  b10,  // 10 bit samples
  b12,  // 12 bit samples
  b14,  // 14 bit samples
  b16,  // 16 bit samples
  b32,  // 32 bit samples
  b64   // 64 bit samples
};

#endif
