#ifndef MALENA1_SOUND_H_
#define MALENA1_SOUND_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define MALENA1_SOUND_NUM_CELLS 8207
#define MALENA1_SOUND_SAMPLERATE 96000
 
const int8_t __attribute__((section(".progmem.data"))) MALENA1_SOUND_DATA [] =
{-1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -2, -2,
-2, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3,
-3, -3, -3, -3, -3, -2, -2, -2, -2, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
0, 0, -1, -1, -1, -2, -2, -2, -3, -3, -3, -3, -2, -2, -2, -1, 0, 0, 1, 1, 2, 2,
3, 3, 3, 3, 2, 2, 1, 0, 0, -1, -2, -3, -4, -4, -5, -5, -5, -5, -5, -5, -5, -5,
-4, -4, -3, -3, -2, -2, -1, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 2, 2, 2, 1, 1, 0, 0,
-1, -1, -2, -2, -2, -3, -3, -4, -4, -4, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -1, -1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 3,
3, 3, 3, 3, 2, 2, 1, 0, -1, -2, -3, -3, -4, -5, -6, -7, -8, -8, -9, -9, -9, -9,
-9, -9, -8, -7, -6, -5, -3, -2, -1, 1, 3, 4, 6, 7, 8, 9, 9, 9, 8, 7, 6, 4, 3, 1,
-1, -3, -4, -6, -7, -7, -7, -7, -6, -5, -4, -2, -1, 1, 2, 3, 4, 4, 4, 4, 3, 3,
2, 0, -1, -3, -4, -6, -7, -8, -8, -9, -9, -9, -8, -7, -6, -5, -4, -2, -1, 0, 1,
3, 3, 4, 4, 4, 4, 4, 3, 2, 1, 0, -1, -2, -4, -5, -6, -6, -7, -7, -7, -7, -6, -5,
-3, -2, 0, 1, 3, 4, 5, 7, 7, 8, 8, 8, 8, 7, 7, 5, 4, 2, 0, -2, -4, -6, -8, -10,
-11, -12, -12, -12, -12, -10, -9, -7, -4, -2, 1, 4, 7, 9, 11, 12, 13, 13, 12,
11, 8, 5, 1, -4, -9, -15, -20, -25, -29, -32, -35, -36, -36, -34, -31, -26, -19,
-11, -2, 7, 17, 27, 36, 44, 51, 56, 60, 62, 62, 60, 56, 50, 42, 34, 24, 15, 5,
-5, -14, -21, -27, -32, -35, -38, -40, -42, -44, -45, -47, -49, -52, -54, -56,
-59, -60, -62, -63, -62, -61, -58, -52, -44, -33, -20, -5, 12, 29, 47, 64, 79,
92, 102, 110, 113, 114, 111, 104, 94, 82, 68, 52, 36, 19, 4, -10, -23, -33, -41,
-48, -52, -55, -56, -55, -53, -49, -44, -39, -32, -26, -19, -13, -8, -4, -1, 0,
0, -1, -4, -7, -11, -16, -22, -27, -33, -38, -42, -46, -49, -50, -50, -47, -43,
-37, -29, -19, -7, 7, 21, 36, 51, 65, 77, 86, 93, 98, 99, 97, 92, 84, 73, 60,
46, 31, 15, 0, -14, -26, -37, -45, -50, -53, -55, -54, -51, -47, -41, -35, -28,
-22, -15, -9, -4, 0, 3, 4, 4, 3, 1, -1, -4, -8, -11, -15, -18, -22, -24, -27,
-29, -29, -30, -29, -28, -25, -22, -18, -13, -8, -2, 3, 10, 16, 22, 28, 33, 38,
43, 46, 48, 49, 49, 48, 45, 41, 36, 30, 23, 17, 10, 3, -3, -8, -13, -16, -19,
-21, -22, -22, -22, -21, -20, -20, -19, -19, -19, -20, -20, -21, -22, -23, -24,
-25, -26, -26, -25, -23, -20, -17, -12, -7, -1, 5, 12, 18, 24, 29, 33, 36, 39,
39, 39, 37, 34, 30, 24, 18, 12, 6, -1, -7, -12, -17, -20, -23, -24, -24, -23,
-22, -19, -16, -13, -10, -6, -3, 0, 2, 4, 6, 6, 6, 6, 5, 4, 2, 1, -1, -2, -4,
-5, -6, -6, -7, -7, -7, -7, -7, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 2, 3, 3, 4,
5, 6, 7, 8, 9, 9, 10, 10, 9, 9, 8, 7, 6, 5, 4, 2, 1, 0, -2, -3, -5, -6, -7, -8,
-8, -8, -8, -8, -8, -7, -7, -6, -6, -6, -5, -5, -5, -4, -4, -4, -4, -3, -3, -2,
-1, -1, -1, 0, 0, 0, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 3, 3, 4,
5, 6, 7, 7, 7, 7, 7, 6, 5, 4, 3, 2, 1, -1, -2, -2, -3, -4, -4, -4, -5, -5, -5,
-5, -5, -5, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -2,
-1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 3, 4, 5, 5, 6, 6, 6, 7, 7, 6, 6, 5, 5, 4, 3,
2, 2, 1, 0, -1, -2, -2, -3, -3, -4, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -5,
-5, -4, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 5, 6, 6, 6, 6, 6, 6, 6, 5, 5, 4, 3, 1,
0, -2, -3, -4, -5, -6, -7, -7, -7, -7, -6, -6, -5, -4, -3, -2, -1, 0, 1, 1, 2,
3, 4, 4, 5, 6, 6, 6, 6, 6, 6, 5, 5, 4, 3, 3, 2, 1, 0, -1, -2, -3, -3, -3, -4,
-4, -4, -3, -3, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
-1, -1, -2, -3, -3, -3, -4, -3, -3, -3, -3, -2, -2, -1, 0, 1, 2, 3, 4, 6, 7, 7,
8, 8, 8, 8, 7, 6, 5, 4, 3, 1, -1, -2, -3, -4, -5, -6, -6, -6, -6, -6, -6, -6,
-5, -5, -4, -4, -3, -2, -1, -1, -1, -1, -1, -1, -1, -2, -2, -3, -3, -3, -3, -3,
-3, -2, -1, -1, 0, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 7, 7, 7, 7, 6, 5, 4, 4, 3, 3,
2, 2, 2, 2, 2, 2, 1, 0, 0, -1, -1, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3, -4, -4, -5, -5,
-5, -5, -5, -5, -4, -3, -1, 0, 2, 4, 6, 8, 10, 11, 13, 13, 14, 13, 13, 12, 10,
9, 7, 5, 4, 2, 0, -1, -3, -4, -5, -5, -6, -6, -6, -6, -7, -7, -7, -7, -7, -7,
-8, -8, -8, -9, -9, -9, -9, -9, -8, -7, -6, -5, -4, -2, 0, 2, 4, 6, 8, 10, 12,
13, 15, 16, 16, 17, 16, 16, 14, 13, 11, 8, 5, 3, 0, -2, -4, -6, -8, -9, -10,
-10, -10, -10, -10, -9, -8, -7, -6, -6, -5, -4, -4, -4, -4, -5, -5, -6, -6, -7,
-7, -8, -8, -8, -8, -7, -6, -5, -4, -2, 0, 2, 4, 6, 8, 10, 12, 13, 15, 15, 16,
16, 16, 15, 14, 12, 10, 8, 5, 3, 1, -1, -3, -5, -6, -7, -8, -8, -8, -7, -7, -6,
-5, -5, -4, -3, -3, -3, -3, -4, -4, -4, -5, -5, -5, -6, -6, -6, -6, -6, -6, -5,
-4, -3, -2, -1, 1, 3, 4, 6, 7, 9, 10, 10, 10, 10, 10, 9, 8, 7, 5, 4, 2, 0, -1,
-3, -4, -5, -6, -7, -7, -7, -6, -6, -6, -5, -4, -3, -2, -1, 0, 0, 1, 1, 1, 2, 2,
2, 2, 2, 2, 2, 1, 1, 0, -1, -2, -3, -4, -4, -4, -4, -4, -4, -3, -3, -2, -1, -1,
0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, -1, -1, -2, -2, -2, -2, -3, -3, -3,
-2, -2, -2, -2, -1, -1, 0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 1, 0, 0, 0,
0, -1, -1, -2, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -2, -1, 0, 1, 2,
3, 4, 4, 5, 4, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0, -1, -1, -2, -2, -3, -3, -3, -3, -3,
-3, -3, -2, -2, -2, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, -1, -2,
-2, -2, -3, -3, -3, -3, -3, -3, -4, -4, -4, -5, -5, -6, -6, -7, -7, -7, -6, -5,
-4, -3, -2, 0, 1, 2, 4, 5, 6, 7, 8, 9, 9, 9, 8, 8, 7, 6, 4, 3, 2, 0, -1, -2, -3,
-4, -5, -5, -6, -6, -6, -6, -6, -6, -5, -5, -4, -4, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -2, -2, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0, -1,
-1, -2, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1,
-1, 0, 1, 1, 2, 3, 3, 4, 4, 5, 5, 5, 5, 4, 4, 3, 2, 1, -1, -2, -3, -4, -5, -5,
-5, -6, -6, -5, -5, -5, -5, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3,
-3, -3, -2, -2, -1, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 3, 2, 1, 1, 0, -1,
-2, -2, -3, -3, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -2,
-2, -2, -1, 0, 0, 1, 2, 3, 3, 4, 4, 4, 4, 4, 4, 3, 2, 2, 1, 0, -1, -1, -2, -2,
-3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6,
-6, -6, -6, -5, -4, -4, -3, -1, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 4, 3, 3, 2, 1, 0,
0, -1, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1, -1,
0, 0, 0, 0, -1, -1, -1, -1, -2, -3, -3, -4, -5, -5, -6, -6, -7, -7, -7, -6, -6,
-6, -5, -5, -4, -3, -1, 1, 2, 4, 5, 7, 8, 9, 9, 9, 9, 8, 8, 6, 5, 4, 2, 0, -1,
-3, -4, -5, -6, -7, -8, -8, -8, -7, -6, -6, -5, -4, -3, -2, -2, -1, -1, -1, -1,
-2, -2, -3, -4, -5, -5, -6, -6, -7, -7, -7, -7, -7, -6, -5, -3, -1, 1, 2, 4, 6,
7, 9, 10, 10, 10, 10, 10, 9, 8, 6, 5, 3, 1, -1, -2, -3, -4, -5, -6, -7, -7, -7,
-7, -6, -6, -5, -4, -3, -3, -2, -2, -1, -1, -1, -1, -2, -2, -3, -3, -4, -5, -5,
-6, -6, -6, -7, -7, -7, -6, -6, -5, -3, -2, 0, 2, 3, 5, 6, 8, 9, 9, 10, 10, 10,
9, 8, 7, 6, 5, 4, 2, 0, -1, -2, -3, -4, -4, -5, -5, -6, -6, -5, -5, -5, -5, -5,
-5, -5, -4, -5, -5, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0,
0, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 6, 6, 5, 4, 3, 3, 2, 1, 0, -1, -2, -3, -3, -4,
-4, -4, -4, -4, -4, -4, -4, -3, -3, -2, -2, -1, -1, -1, -1, -1, -1, -2, -3, -3,
-4, -5, -5, -6, -6, -6, -6, -6, -6, -5, -4, -3, -2, 0, 2, 3, 5, 6, 8, 9, 9, 10,
10, 9, 9, 8, 7, 6, 5, 4, 2, 1, -1, -3, -4, -5, -5, -6, -6, -6, -6, -5, -4, -4,
-3, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -4, -3, -3, -3, -2, -1,
0, 0, 1, 2, 3, 4, 5, 6, 6, 7, 7, 7, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -3, -4,
-4, -4, -4, -4, -4, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -2, -2, -1, -1, -1, 0, 0, 1, 1, 2, 3, 3, 3, 4, 4, 4, 4, 4, 3, 3, 2,
1, 1, 0, 0, -1, -1, -2, -2, -2, -2, -3, -3, -3, -3, -3, -2, -2, -2, -1, -1, 0,
1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 1, 0, 0, -1, -1, -2, -2, -3, -3, -3, -3,
-4, -4, -3, -3, -3, -2, -2, -2, -1, 0, 1, 2, 3, 4, 5, 5, 6, 6, 6, 6, 6, 6, 5, 4,
4, 3, 2, 1, 0, 0, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1,
-1, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1,
-1, 0, 1, 2, 3, 3, 4, 5, 5, 6, 6, 6, 6, 6, 5, 5, 4, 3, 3, 2, 1, 0, 0, -1, -1,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-2, -2, -2, -3, -3, -3, -3, -3, -2, -2, -1, 0, 1, 1, 2, 3, 4, 5, 6, 7, 7, 7, 8,
8, 7, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -3,
-3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 2, 2, 3,
3, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 3, 3, 2, 1, 1, 0, -1, -1, -1, -2, -2,
-2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -1, 0,
0, 1, 2, 3, 4, 5, 5, 6, 6, 7, 7, 7, 7, 6, 6, 5, 5, 4, 3, 2, 2, 1, 0, -1, -1, -2,
-2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -1, -1, -1, 0, 0, 1,
1, 2, 3, 3, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 2, 2, 1, 1, 0, 0, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0, 1, 1, 2, 3, 3, 4, 4,
5, 5, 5, 4, 4, 4, 3, 3, 2, 1, 0, 0, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -1,
-1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1,
-1, -1, -1, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2,
2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, 0, 0, 1, 1, 1, 2, 2,
2, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -1, -1, -1, -1,
-1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2, -2, -2, -2, -3,
-3, -3, -4, -4, -4, -4, -3, -3, -3, -2, -1, -1, 0, 1, 2, 2, 3, 4, 4, 4, 5, 5, 5,
4, 4, 3, 3, 2, 1, 1, 0, -1, -1, -2, -2, -3, -3, -3, -3, -4, -4, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -3, -2, -1, -1, 0, 1, 2, 3,
4, 4, 5, 5, 5, 6, 6, 5, 5, 4, 3, 2, 1, 0, 0, -1, -2, -3, -3, -4, -4, -4, -4, -4,
-4, -4, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1,
0, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0, -1, -1, -1, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -1, -1, 0, 0, 0, 1, 1, 1, 2, 2,
2, 2, 2, 2, 2, 1, 1, 1, 0, 0, -1, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -2, -2, -2, -1, -1, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0, -1, -1,
-1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, 0,
0, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, -1, -1, -1, -1, -1, -2, -2, -3,
-3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1,
-1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -3,
-3, -3, -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 3, 3, 3, 4, 4, 4, 4, 4, 3, 3, 3,
2, 1, 0, -1, -1, -2, -2, -3, -3, -3, -3, -4, -4, -3, -3, -3, -3, -3, -2, -2, -2,
-2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
-1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3,
-3, -3, -2, -2, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 2, 2,
2, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2,
2, 3, 3, 2, 2, 2, 2, 2, 1, 1, 0, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -1,
-1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1,
1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, -1, -1, -1, -2, -2, -2, -2,
-2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -1, -1,
-1, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1,
0, 0, -1, -1, -1, -1, -2, -2, -3, -3, -3, -2, -2, -2, -2, -2, -2, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, 0,
0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, -1, -1, -1, -1, -2,
-2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2,
-1, -1, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, -1,
-1, -1, -1, -1, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2,
-2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2,
-2, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, -1, -1,
-1, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -2, -3, -3, -3, -3, -2, -2, -2, -2,
-2, -3, -3, -2, -2, -2, -2, -2, -2, -1, -1, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2,
2, 1, 1, 1, 0, 0, -1, -1, -1, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-3, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2,
-2, -1, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0, 0, -1, -1, -1, -2,
-2, -2, -2, -3, -3, -3, -3, -3, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -2, -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 0, -1, -1, -1, -1, -1, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1,
0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1,
-1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1,
-1, -1, -1, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, -1, -1,
-1, -1, -2, -2, -2, -2, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -1, -1,
-1, -1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1,
-1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0,
1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2,
3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0, -1, -1, -1, -1, 0, 0, 1, 1, 1,
1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 1,
1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0,
-1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0,
0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0,
-1, -1, -1, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2,
2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2,
-2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,
-1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1,
1, 1, 1, 0, 0, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1,
-1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -2, -2, -2, -2, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1,
-1, -1, -1, -1, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, 0, 0, 0, -1, -1, -1,
-1, -2, -2, -3, -3, -3, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -2, -2, -2, -2, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -3, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3, -2, -2, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1,
-1, -1, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -2, -2, -2, -2, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1,
-1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,
0, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-2, -2, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
1, 1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -2, -2, -2, -2, -1, -1, 0, 0, 1,
1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0,
1, 1, 1, 1, 1, 1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 4,
5, 7, 8, 9, 9, 8, 7, 5, 3, 0, -3, -5, -6, -7, -7, -6, -5, -4, -2, 0, 1, 3, 4, 4,
4, 3, 2, 1, -1, -2, -3, -4, -5, -5, -5, -4, -3, -2, 0, 2, 4, 6, 7, 8, 9, 9, 8,
7, 5, 3, 2, 0, -1, -2, -2, -3, -2, -2, -1, -1, 0, 1, 2, 2, 2, 2, 1, 1, 0, -1,
-2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -1, 1, 2, 4, 5, 6, 6, 6, 6, 6,
5, 4, 3, 3, 2, 2, 2, 1, 1, 0, -1, -1, -1, -2, -2, -3, -3, -3, -3, -3, -2, -1, 0,
1, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1, 0, -1, -1, -2, -2, -2, -2, -1, -1, -1, 0, 0, 1,
2, 3, 4, 4, 5, 4, 3, 2, 0, -1, -3, -4, -4, -4, -4, -3, -1, 0, 2, 3, 4, 5, 5, 6,
6, 6, 5, 5, 4, 3, 2, 0, -1, -3, -4, -5, -5, -5, -4, -3, -1, 1, 3, 5, 6, 6, 5, 5,
3, 2, 1, -1, -2, -2, -3, -3, -3, -4, -4, -4, -3, -2, -1, 1, 3, 5, 6, 8, 8, 9, 8,
7, 6, 4, 2, 1, 0, -1, -3, -3, -4, -5, -5, -4, -3, -2, -1, 0, 2, 3, 5, 6, 6, 7,
6, 5, 4, 2, 0, -2, -3, -5, -6, -6, -6, -5, -4, -2, -1, 1, 3, 4, 5, 5, 5, 5, 4,
4, 4, 3, 3, 2, 2, 1, 0, -1, -2, -2, -2, -1, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, -1,
-1, -1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -1, -1, 0, 1,
3, 4, 5, 6, 6, 6, 5, 4, 3, 2, 0, -1, -2, -3, -3, -3, -3, -2, -1, 0, 1, 3, 4, 5,
6, 6, 5, 4, 3, 1, -1, -2, -3, -4, -4, -5, -5, -4, -3, -2, -1, 0, 2, 3, 5, 6, 7,
7, 6, 5, 4, 2, 1, -1, -3, -4, -4, -5, -4, -4, -3, -2, 0, 1, 2, 3, 3, 4, 4, 4, 4,
3, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1, 1, 2, 3, 4, 4, 4, 4, 3, 2, 1, 1, 0, 0,
0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -2, -2, -2, -2, -1,
0, 1, 3, 5, 6, 6, 6, 6, 5, 3, 2, 0, -1, -2, -2, -3, -2, -2, -2, -1, -1, 0, 1, 1,
2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 1, 2,
3, 4, 5, 5, 5, 5, 4, 3, 1, 0, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-1, 0, 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -1, -2, -2, -2, -2, -2, -1, 0, 1, 2, 3, 4,
4, 5, 5, 5, 4, 3, 1, 0, -2, -3, -4, -5, -5, -5, -5, -5, -4, -3, -2, -1, 1, 2, 3,
4, 4, 4, 3, 2, 1, 0, -1, -3, -3, -4, -4, -4, -4, -3, -2, -1, 0, 2, 3, 4, 5, 6,
5, 4, 3, 2, 0, -1, -2, -3, -4, -4, -4, -4, -3, -2, -1, 0, 1, 2, 2, 3, 2, 2, 1,
0, -1, -1, -2, -3, -3, -3, -3, -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2,
-2, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, 1,
1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, -1,
0, 0, 1, 1, 1, 0, 0, -1, -2, -2, -3, -3, -4, -4, -4, -3, -3, -2, -2, -1, -1, 0,
0, 0, 0, 0, 0, -1, -1, -2, -3, -4, -5, -5, -5, -5, -4, -4, -3, -2, -1, 0, 1, 1,
1, 1, 0, 0, -1, -2, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -2, -2,
-1, -1, 0, 0, 0, 0, 0, -1, -1, -2, -3, -3, -3, -3, -3, -3, -3, -2, -2, -1, 0, 1,
2, 3, 3, 4, 4, 3, 3, 2, 1, 0, -1, -2, -2, -3, -3, -4, -4, -3, -3, -3, -2, -1,
-1, 0, 0, 1, 1, 1, 0, 0, -1, -2, -3, -3, -4, -4, -4, -4, -4, -4, -3, -3, -2, -1,
-1, 0, 0, 1, 1, 1, 1, 0, 0, -1, -1, -2, -3, -3, -4, -4, -4, -4, -4, -4, -3, -3,
-2, -1, -1, 0, 0, 1, 1, 1, 1, 0, 0, 0, -1, -1, -2, -2, -3, -3, -3, -3, -3, -2,
-2, -2, -2, -2, -2, -1, -1, -1, -1, -2, -2, -2, -2, -3, -3, -3, -3, -3, -2, -2,
-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 0, 0, 0, -1, -1, -2, -2,
-2, -2, -2, -2, -3, -3, -2, -2, -3, -3, -3, -2, -2, -1, -1, -1, -1, -1, -1, -1,
-2, -2, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1,
-1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1,
0, 1, 1, 1, 1, 0, 0, -1, -2, -2, -3, -3, -4, -4, -3, -3, -3, -3, -2, -2, -1, -1,
0, 0, 0, 0, 0, 0, -1, -2, -3, -3, -4, -5, -5, -5, -4, -4, -3, -3, -2, -1, 0, 1,
1, 2, 2, 2, 2, 2, 2, 1, 1, 0, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -2,
-2, -2, -2, -1, -1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 1, 1, 1, 1, 0, 0,
-1, -1, -2, -2, -2, -2, -2, -1, 0, 1, 1, 1, 1, 1, 0, -1, -1, -2, -2, -2, -2, -2,
-2, -3, -3, -3, -3, -3, -3, -3, -2, -1, 0, 1, 1, 1, 1, 1, 0, -1, -2, -3, -3, -4,
-3, -3, -2, -2, -1, 0, 1, 2, 2, 3, 3, 2, 2, 2, 2, 2, 1, 0, 0, -1, -2, -2, -3,
-3, -3, -3, -3, -2, -2, -2, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1, -2, -3, -3, -3,
-3, -3, -3, -3, -2, -2, -1, 0, 0, 1, 2, 3, 3, 3, 3, 3, 2, 1, 0, -1, -1, -2, -2,
-2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, 0, 1, 1, 1, 1, 1, 1,
1, 0, -1, -2, -2, -2, -2, -2, -1, -1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -1, -2, -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -2, -2,
-2, -3, -3, -2, -2, -2, -1, -1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1,
1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -2, -1, -1, -1, 0, 0, 1, 2, 2, 2, 2,
2, 2, 2, 1, 1, 0, 0, -1, -1, -2, -2, -2, -1, -1, 0, 0, 1, 2, 2, 3, 3, 3, 2, 1,
0, -1, -1, -2, -2, -3, -3, -3, -2, -2, -1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, -1,
-1, -1, -1, -1, 0, 0, 1, 2, 2, 3, 3, 3, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 1,
1, 0, 0, -1, -1, -2, -2, -2, -2, -1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, -1, -1,
-1, -1, -1, -1, -1, -1, -1, 0, 1, 1, 2, 2, 3, 3, 2, 2, 1, 1, 0, 0, -1, -1, -1,
-1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, -1,
-1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, -1, -1, -1, -1,
-1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, -1, -1, -1, -1, -1,
-1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1, 0, 0, -1, -1, -1, -2, -2, -2, -2, -2, -1,
0, 0, 1, 2, 2, 3, 3, 3, 3, 3, 2, 1, 1, 0, 0, -1, -1, -1, -1, -1, -1, 0, 0, 1, 1,
1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, -1, -1, -2, -2, -1, -1, -1, 0, 0, 0, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
2, 2, 1, 1, 1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 1, 1,
1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0,
0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -1, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2,
-2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2,
-2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2,
-2, -2, -3, -3, -3, -3, -3, -3, -3, -2, -2, -1, -1, -1, -1, -1, -1, -1, -2, -2,
-2, -3, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -2, -2, -2, -1,
-1, };

#endif /* MALENA1_SOUND_H_ */