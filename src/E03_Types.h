//
//  E03_Types.h
//  Unit02_Exercise03_Understanding_Types
//

#ifndef E03_Types_h
#define E03_Types_h

typedef unsigned char UInt8;

//
// Note:
//  The digits are saved in reverse order
//
// e.g:
//   number 256 will be represented as
//   {2, [0, 1]}  // 1 0 are stored in reverse order
//
struct base256Number {
    unsigned int numberOfDigits;
    UInt8 *digits;
};

typedef struct base256Number Base256Number;

#endif /* E03_Types_h */
