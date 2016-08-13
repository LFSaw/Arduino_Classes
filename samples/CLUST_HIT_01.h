#ifndef CLUST_HIT_01_H_
#define CLUST_HIT_01_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include <avr/pgmspace.h>
 
#define CLUST_HIT_01_NUM_CELLS 9825
#define CLUST_HIT_01_SAMPLERATE 44100
 
const int8_t __attribute__((section(".progmem.data"))) CLUST_HIT_01_DATA [] =
{0, 0, 0, -1, -1, -1, 0, 0, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 2, 2,
3, 4, 4, 4, 5, 5, 6, 6, 6, 6, 5, 4, 2, -1, -5, -10, -16, -22, -29, -37, -45,
-53, -61, -68, -74, -79, -84, -87, -89, -88, -84, -80, -74, -70, -66, -63, -62,
-63, -64, -64, -62, -57, -48, -37, -25, -11, 4, 20, 36, 50, 60, 66, 67, 63, 56,
46, 35, 24, 12, 1, -9, -17, -24, -29, -31, -31, -27, -21, -11, -1, 10, 18, 23,
26, 26, 26, 24, 22, 19, 16, 14, 13, 13, 14, 15, 15, 13, 11, 7, 2, -3, -8, -13,
-15, -16, -17, -18, -19, -20, -22, -22, -20, -19, -17, -16, -15, -14, -13, -12,
-11, -12, -12, -11, -9, -6, -3, 1, 5, 9, 13, 17, 20, 19, 17, 13, 9, 6, 3, 2, 0,
-1, -2, -3, -3, -4, -5, -7, -9, -12, -15, -17, -20, -22, -24, -24, -23, -21,
-20, -19, -19, -20, -21, -22, -22, -23, -24, -25, -25, -24, -21, -19, -18, -18,
-19, -20, -22, -23, -26, -29, -32, -35, -36, -38, -40, -42, -44, -45, -44, -43,
-40, -38, -35, -32, -28, -22, -16, -10, -5, 1, 5, 10, 15, 19, 22, 26, 31, 36,
40, 44, 48, 50, 52, 54, 57, 59, 60, 59, 58, 57, 56, 55, 53, 50, 45, 39, 32, 26,
20, 13, 6, -1, -7, -13, -18, -24, -29, -34, -38, -41, -43, -45, -46, -48, -49,
-50, -51, -50, -49, -47, -44, -41, -37, -33, -32, -32, -33, -35, -36, -38, -40,
-43, -46, -48, -49, -48, -46, -43, -40, -37, -33, -28, -24, -20, -17, -14, -11,
-8, -4, -1, 2, 3, 5, 7, 9, 11, 13, 16, 20, 23, 27, 31, 33, 36, 38, 40, 41, 41,
39, 38, 36, 35, 35, 35, 35, 34, 33, 31, 29, 27, 25, 23, 21, 18, 16, 13, 10, 7,
5, 3, 1, -1, -3, -4, -6, -8, -10, -13, -15, -18, -20, -24, -28, -32, -37, -42,
-46, -49, -52, -54, -56, -58, -60, -63, -66, -68, -70, -71, -72, -73, -74, -74,
-75, -76, -76, -76, -76, -77, -76, -75, -73, -70, -65, -60, -53, -46, -39, -31,
-24, -17, -9, -1, 7, 15, 23, 29, 34, 37, 39, 40, 40, 39, 38, 37, 35, 34, 32, 30,
28, 27, 27, 27, 28, 28, 28, 28, 27, 27, 26, 25, 23, 22, 20, 19, 17, 15, 13, 10,
7, 4, 3, 1, 0, -1, -3, -4, -4, -5, -5, -5, -6, -6, -7, -7, -6, -5, -3, -1, 2, 5,
8, 12, 16, 20, 24, 28, 31, 34, 35, 36, 36, 36, 34, 31, 28, 25, 21, 17, 13, 9, 5,
1, -2, -5, -8, -11, -13, -16, -18, -20, -21, -21, -19, -16, -12, -7, -2, 4, 9,
15, 21, 28, 34, 39, 44, 47, 50, 52, 53, 53, 53, 51, 50, 49, 48, 46, 45, 43, 40,
36, 32, 27, 23, 17, 12, 6, 0, -4, -8, -11, -13, -15, -16, -16, -16, -15, -14,
-12, -10, -8, -6, -4, -1, 1, 2, 3, 2, 1, -1, -4, -8, -12, -16, -20, -23, -26,
-29, -33, -37, -41, -46, -49, -53, -56, -58, -59, -60, -59, -58, -55, -52, -49,
-45, -41, -36, -32, -27, -22, -15, -9, -2, 4, 8, 11, 13, 14, 15, 16, 16, 16, 15,
14, 12, 11, 9, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 5, 7, 10, 11, 13, 13, 14, 14, 14,
15, 16, 16, 17, 18, 18, 18, 17, 16, 14, 13, 10, 8, 6, 4, 3, 3, 4, 6, 8, 11, 14,
16, 19, 23, 27, 32, 38, 43, 47, 52, 55, 59, 61, 64, 66, 67, 68, 69, 69, 69, 68,
67, 66, 65, 63, 62, 60, 58, 56, 53, 52, 50, 48, 47, 46, 46, 45, 44, 44, 43, 42,
42, 41, 41, 39, 38, 36, 34, 31, 29, 25, 21, 16, 11, 5, -1, -7, -13, -20, -26,
-32, -38, -43, -47, -51, -54, -55, -55, -53, -49, -45, -40, -33, -26, -18, -10,
-1, 8, 17, 26, 35, 43, 50, 56, 61, 66, 71, 74, 76, 77, 77, 76, 74, 72, 70, 66,
63, 60, 58, 55, 53, 50, 48, 46, 44, 43, 42, 41, 40, 39, 38, 37, 36, 34, 33, 31,
28, 26, 23, 20, 16, 13, 9, 5, 0, -5, -11, -17, -23, -28, -32, -35, -37, -39,
-39, -39, -39, -38, -36, -34, -32, -29, -25, -21, -17, -12, -6, 0, 8, 15, 24,
32, 40, 47, 53, 57, 61, 65, 68, 71, 72, 73, 73, 72, 70, 68, 65, 62, 58, 54, 50,
45, 40, 35, 30, 25, 20, 14, 8, 2, -5, -11, -17, -23, -28, -33, -38, -42, -45,
-47, -49, -50, -51, -51, -50, -49, -49, -48, -47, -46, -44, -42, -39, -36, -33,
-31, -28, -24, -20, -16, -11, -6, -1, 4, 9, 14, 18, 23, 27, 31, 35, 38, 40, 42,
43, 44, 45, 45, 44, 43, 42, 40, 39, 37, 34, 32, 28, 25, 21, 18, 14, 10, 5, 1,
-2, -6, -9, -12, -16, -20, -24, -28, -32, -35, -38, -41, -44, -46, -47, -48,
-47, -46, -44, -42, -40, -38, -36, -34, -32, -30, -29, -26, -24, -22, -20, -19,
-17, -16, -15, -14, -14, -14, -14, -15, -16, -16, -17, -19, -20, -23, -26, -29,
-34, -38, -43, -48, -53, -57, -62, -67, -71, -74, -78, -80, -81, -82, -82, -81,
-80, -79, -77, -76, -74, -72, -70, -67, -66, -64, -64, -63, -62, -61, -60, -58,
-55, -52, -49, -46, -42, -38, -35, -32, -28, -25, -21, -17, -14, -10, -7, -4,
-1, 2, 5, 7, 8, 9, 10, 11, 11, 10, 9, 8, 6, 4, 2, -1, -4, -7, -11, -15, -19,
-22, -26, -30, -34, -37, -40, -43, -45, -47, -49, -49, -50, -50, -50, -49, -47,
-44, -41, -38, -36, -33, -31, -28, -25, -22, -18, -14, -9, -6, -2, 1, 3, 6, 7,
9, 11, 12, 14, 15, 16, 17, 18, 20, 21, 23, 24, 25, 26, 27, 27, 26, 25, 23, 22,
20, 18, 16, 13, 9, 6, 3, 0, -3, -5, -8, -10, -12, -14, -16, -17, -17, -18, -19,
-20, -20, -21, -20, -19, -17, -14, -12, -9, -7, -5, -3, -2, -1, 1, 3, 4, 5, 5,
5, 5, 5, 5, 6, 6, 7, 8, 9, 10, 11, 13, 15, 19, 23, 27, 31, 36, 40, 44, 48, 52,
56, 59, 62, 65, 66, 67, 67, 66, 64, 61, 58, 53, 49, 43, 37, 31, 25, 19, 14, 9,
4, -1, -5, -9, -12, -13, -14, -13, -12, -10, -8, -6, -3, 1, 5, 9, 14, 19, 23,
27, 31, 33, 35, 37, 38, 38, 38, 37, 35, 34, 31, 28, 25, 22, 19, 15, 12, 9, 5, 2,
-2, -5, -8, -11, -13, -15, -17, -19, -21, -24, -27, -30, -34, -37, -41, -44,
-47, -49, -51, -53, -55, -57, -59, -61, -64, -66, -69, -71, -73, -74, -76, -77,
-78, -78, -79, -79, -78, -78, -76, -74, -71, -69, -66, -63, -59, -56, -52, -48,
-44, -39, -35, -30, -26, -22, -18, -14, -10, -5, 0, 5, 10, 15, 20, 24, 29, 33,
37, 40, 44, 46, 49, 51, 53, 54, 54, 54, 54, 54, 54, 54, 54, 53, 52, 51, 51, 50,
49, 48, 46, 44, 43, 41, 39, 38, 35, 33, 31, 29, 27, 26, 24, 23, 23, 22, 21, 20,
20, 19, 18, 17, 15, 14, 12, 10, 8, 6, 4, 2, 1, 0, -1, -2, -3, -4, -5, -7, -8,
-9, -9, -9, -10, -10, -10, -10, -10, -9, -9, -9, -8, -8, -8, -8, -8, -7, -7, -7,
-8, -9, -10, -11, -13, -14, -15, -16, -18, -19, -19, -20, -21, -21, -21, -21,
-21, -20, -19, -19, -18, -17, -16, -15, -13, -10, -8, -5, -3, -1, 1, 3, 5, 7,
10, 13, 16, 19, 22, 25, 29, 33, 36, 39, 42, 44, 46, 47, 49, 50, 52, 54, 56, 57,
57, 57, 57, 57, 56, 55, 53, 50, 46, 42, 38, 35, 31, 28, 25, 23, 20, 17, 15, 12,
9, 7, 4, 3, 2, 1, 0, -1, -3, -3, -4, -3, -2, -1, -1, 0, 0, 0, 0, -1, -1, -2, -3,
-4, -6, -8, -10, -13, -15, -18, -20, -23, -25, -27, -30, -32, -34, -37, -39,
-41, -43, -44, -45, -46, -46, -45, -43, -41, -38, -36, -34, -32, -31, -29, -28,
-27, -26, -25, -25, -25, -26, -26, -26, -27, -27, -28, -29, -30, -31, -33, -35,
-36, -38, -39, -39, -40, -40, -40, -40, -40, -40, -40, -40, -40, -39, -38, -38,
-37, -36, -35, -34, -33, -32, -31, -30, -29, -29, -29, -28, -27, -27, -26, -25,
-24, -23, -22, -22, -21, -20, -19, -18, -17, -16, -14, -13, -12, -11, -10, -9,
-8, -6, -5, -4, -2, -1, 0, 2, 4, 5, 7, 8, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10,
9, 8, 7, 7, 6, 5, 4, 3, 2, 1, -2, -4, -6, -9, -11, -14, -16, -18, -21, -23, -26,
-28, -30, -32, -34, -35, -37, -38, -39, -39, -39, -38, -37, -36, -35, -34, -32,
-31, -30, -28, -26, -25, -23, -22, -21, -21, -20, -18, -17, -16, -15, -15, -15,
-15, -15, -15, -14, -13, -12, -10, -8, -6, -4, -2, 1, 3, 6, 9, 12, 15, 18, 20,
22, 24, 27, 29, 31, 33, 35, 37, 38, 40, 41, 42, 43, 44, 44, 43, 42, 41, 40, 38,
37, 35, 33, 31, 29, 27, 25, 23, 22, 20, 19, 17, 16, 14, 13, 11, 10, 10, 9, 9, 9,
9, 8, 7, 6, 5, 5, 4, 4, 3, 3, 2, 1, 0, -1, -1, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3,
3, 4, 4, 4, 5, 6, 6, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 7, 7,
7, 6, 5, 5, 5, 6, 7, 9, 10, 11, 12, 14, 15, 17, 18, 20, 21, 23, 24, 25, 26, 27,
28, 29, 30, 31, 32, 32, 32, 32, 32, 31, 30, 30, 29, 28, 26, 25, 23, 22, 20, 18,
16, 13, 10, 8, 5, 3, 1, -1, -3, -4, -6, -7, -8, -8, -8, -7, -6, -4, -2, 0, 3, 6,
10, 13, 17, 22, 26, 31, 36, 40, 45, 49, 53, 57, 61, 65, 69, 72, 75, 77, 79, 80,
81, 82, 83, 83, 82, 81, 80, 79, 77, 76, 75, 73, 71, 69, 67, 65, 63, 61, 58, 55,
52, 50, 46, 43, 40, 36, 33, 30, 27, 24, 21, 18, 15, 13, 10, 8, 6, 5, 4, 3, 2, 1,
0, -1, -1, 0, 1, 2, 4, 5, 7, 9, 11, 14, 16, 19, 22, 24, 26, 27, 29, 30, 31, 31,
31, 31, 31, 30, 29, 27, 25, 24, 22, 20, 18, 17, 14, 12, 10, 7, 5, 3, 1, -1, -3,
-6, -9, -11, -13, -14, -15, -16, -17, -18, -18, -18, -18, -17, -15, -13, -11,
-8, -6, -4, -1, 1, 4, 7, 10, 13, 15, 18, 19, 21, 23, 24, 26, 28, 30, 31, 31, 31,
31, 31, 30, 30, 30, 29, 28, 27, 25, 24, 22, 20, 19, 17, 15, 13, 11, 9, 7, 6, 5,
4, 4, 4, 3, 3, 3, 3, 4, 6, 7, 9, 10, 12, 13, 14, 16, 17, 19, 21, 23, 24, 25, 27,
28, 29, 30, 32, 34, 35, 37, 37, 38, 38, 37, 37, 37, 37, 36, 36, 35, 35, 35, 36,
36, 37, 37, 37, 37, 37, 37, 37, 36, 35, 34, 33, 31, 29, 27, 25, 22, 20, 17, 16,
14, 12, 9, 7, 5, 3, 1, 0, -2, -3, -4, -5, -6, -7, -7, -7, -6, -6, -6, -6, -6,
-6, -6, -5, -4, -3, -3, -2, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -2, -3, -3, -4,
-5, -6, -8, -9, -10, -12, -14, -15, -17, -19, -21, -23, -25, -28, -31, -35, -38,
-42, -45, -49, -52, -56, -60, -63, -67, -71, -74, -78, -81, -84, -86, -88, -90,
-91, -91, -91, -91, -90, -89, -87, -86, -85, -83, -82, -80, -77, -75, -72, -69,
-65, -62, -59, -57, -54, -51, -49, -47, -45, -43, -41, -39, -38, -36, -35, -34,
-33, -33, -32, -31, -30, -29, -28, -27, -26, -25, -25, -25, -26, -27, -28, -30,
-32, -34, -36, -38, -41, -44, -47, -50, -53, -55, -58, -61, -63, -65, -66, -67,
-68, -68, -68, -68, -68, -68, -68, -68, -67, -66, -65, -64, -62, -60, -58, -55,
-53, -50, -47, -44, -41, -38, -36, -34, -32, -29, -28, -26, -24, -23, -22, -21,
-20, -19, -18, -17, -16, -14, -13, -12, -12, -12, -12, -12, -13, -13, -14, -16,
-17, -19, -21, -23, -25, -28, -30, -32, -34, -37, -40, -42, -44, -46, -47, -48,
-48, -49, -49, -49, -49, -49, -49, -49, -48, -48, -47, -47, -46, -46, -45, -44,
-42, -40, -39, -37, -35, -33, -31, -28, -25, -22, -19, -16, -14, -11, -9, -7,
-5, -2, 0, 2, 4, 5, 7, 8, 9, 10, 11, 12, 12, 13, 13, 13, 12, 12, 12, 12, 12, 12,
11, 9, 7, 5, 3, 1, 0, -2, -3, -5, -6, -7, -8, -8, -9, -9, -9, -9, -9, -9, -9,
-9, -9, -8, -8, -8, -7, -7, -7, -8, -8, -7, -7, -6, -6, -5, -5, -5, -4, -4, -3,
-2, -1, 1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 9, 9, 9, 8, 8, 7, 7, 6, 4, 2, 1, -1,
-3, -4, -5, -6, -7, -8, -9, -9, -9, -9, -9, -8, -8, -7, -6, -4, -3, -1, 1, 3, 5,
8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 27, 28, 28, 29, 30, 31, 32, 32, 33, 34,
35, 36, 37, 38, 39, 40, 41, 42, 42, 42, 42, 43, 43, 43, 43, 44, 44, 44, 44, 44,
43, 43, 42, 41, 40, 39, 37, 35, 34, 32, 30, 29, 27, 26, 24, 22, 21, 19, 17, 16,
15, 13, 12, 11, 10, 9, 8, 8, 7, 6, 6, 5, 5, 4, 4, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0,
0, 1, 2, 2, 3, 4, 5, 6, 7, 8, 10, 11, 13, 15, 16, 18, 19, 21, 22, 23, 24, 25,
25, 25, 25, 24, 23, 23, 22, 22, 22, 21, 21, 21, 21, 21, 21, 21, 21, 22, 23, 23,
24, 25, 25, 27, 28, 29, 31, 33, 34, 35, 36, 37, 38, 39, 39, 39, 39, 38, 37, 37,
36, 35, 34, 33, 32, 31, 29, 28, 26, 25, 23, 22, 21, 19, 18, 17, 16, 15, 14, 14,
14, 13, 13, 12, 12, 11, 10, 10, 9, 9, 9, 8, 7, 7, 6, 6, 6, 6, 7, 7, 7, 8, 8, 9,
10, 11, 13, 14, 16, 17, 19, 20, 22, 23, 24, 25, 26, 26, 27, 26, 26, 26, 26, 25,
25, 24, 24, 23, 22, 22, 21, 21, 21, 21, 20, 20, 20, 20, 20, 20, 20, 21, 22, 22,
22, 22, 22, 21, 21, 20, 20, 19, 17, 16, 14, 12, 10, 8, 6, 4, 3, 0, -2, -4, -7,
-9, -12, -14, -16, -18, -21, -23, -24, -26, -27, -27, -28, -28, -28, -28, -27,
-27, -27, -26, -25, -25, -24, -23, -22, -20, -19, -17, -16, -14, -12, -10, -8,
-6, -4, -2, 0, 3, 5, 7, 9, 11, 13, 14, 16, 17, 18, 19, 20, 21, 22, 22, 23, 23,
23, 23, 23, 23, 23, 22, 21, 20, 19, 18, 17, 15, 13, 12, 9, 7, 5, 3, 1, -1, -3,
-5, -6, -8, -9, -11, -13, -15, -17, -19, -22, -24, -27, -29, -31, -33, -35, -37,
-38, -39, -40, -40, -41, -42, -42, -42, -41, -41, -40, -38, -37, -36, -34, -33,
-32, -30, -29, -28, -27, -26, -25, -24, -23, -23, -23, -23, -23, -23, -24, -24,
-25, -26, -28, -29, -30, -31, -32, -33, -35, -36, -37, -37, -38, -38, -38, -38,
-37, -36, -36, -35, -33, -32, -31, -30, -29, -28, -27, -26, -25, -24, -23, -22,
-21, -20, -19, -18, -18, -17, -16, -15, -14, -13, -12, -11, -10, -9, -8, -6, -4,
-3, -1, 1, 3, 4, 6, 7, 9, 10, 12, 13, 14, 14, 15, 16, 16, 17, 17, 17, 17, 17,
16, 15, 14, 13, 12, 11, 9, 8, 6, 5, 4, 2, 1, 0, -1, -2, -4, -5, -7, -8, -10,
-11, -12, -14, -15, -17, -19, -21, -23, -25, -27, -29, -31, -33, -34, -36, -37,
-38, -38, -39, -39, -39, -39, -39, -38, -37, -36, -35, -34, -32, -31, -29, -27,
-26, -24, -22, -19, -17, -15, -13, -11, -9, -7, -5, -3, -1, 0, 2, 3, 4, 6, 7, 9,
10, 12, 14, 15, 17, 18, 20, 21, 22, 23, 24, 25, 25, 26, 26, 26, 26, 26, 26, 26,
26, 25, 25, 24, 23, 23, 22, 21, 20, 20, 19, 18, 17, 17, 16, 16, 15, 15, 15, 15,
14, 14, 14, 13, 13, 12, 12, 11, 10, 9, 8, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -1, -2,
-2, -2, -1, 0, 0, 2, 3, 4, 6, 7, 9, 11, 12, 14, 16, 17, 19, 21, 23, 25, 26, 28,
30, 31, 32, 33, 34, 35, 36, 36, 36, 37, 37, 36, 36, 36, 35, 35, 35, 34, 34, 33,
33, 32, 30, 29, 28, 26, 25, 23, 22, 20, 18, 17, 15, 13, 11, 10, 8, 6, 5, 3, 2,
1, -1, -1, -2, -3, -3, -4, -4, -3, -3, -2, -1, 0, 2, 3, 5, 6, 8, 10, 12, 14, 16,
18, 20, 22, 23, 25, 27, 29, 30, 32, 33, 34, 35, 35, 36, 37, 38, 38, 39, 39, 39,
38, 38, 38, 37, 36, 35, 34, 33, 32, 31, 30, 28, 26, 25, 23, 21, 18, 16, 14, 12,
9, 7, 5, 3, 1, -1, -3, -5, -7, -8, -10, -11, -13, -14, -15, -16, -17, -17, -18,
-18, -18, -18, -18, -18, -17, -16, -15, -14, -13, -12, -10, -9, -8, -7, -5, -4,
-3, -1, 0, 2, 3, 4, 6, 7, 8, 9, 11, 11, 12, 13, 14, 15, 15, 16, 16, 17, 17, 17,
17, 17, 17, 16, 16, 16, 15, 15, 15, 15, 14, 14, 14, 14, 13, 13, 12, 12, 11, 11,
11, 11, 11, 11, 12, 12, 13, 13, 14, 15, 16, 17, 18, 19, 20, 21, 21, 22, 23, 23,
24, 24, 25, 25, 25, 26, 26, 26, 26, 26, 25, 24, 24, 23, 22, 21, 20, 19, 17, 16,
14, 13, 12, 10, 8, 7, 5, 3, 1, -1, -2, -4, -5, -7, -8, -10, -12, -13, -14, -16,
-17, -18, -19, -20, -21, -22, -22, -23, -23, -24, -24, -24, -24, -24, -24, -24,
-23, -23, -22, -22, -21, -20, -20, -19, -18, -17, -15, -14, -13, -12, -11, -10,
-8, -7, -6, -5, -3, -2, -1, 0, 1, 2, 3, 5, 6, 7, 8, 8, 9, 9, 10, 10, 10, 10, 10,
9, 8, 8, 7, 5, 4, 3, 2, 1, 0, -2, -3, -4, -5, -6, -7, -8, -8, -9, -10, -11, -11,
-12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -10, -10, -9, -9, -8, -8, -7,
-7, -7, -7, -8, -9, -9, -10, -11, -12, -13, -13, -14, -15, -16, -18, -19, -20,
-21, -23, -24, -25, -27, -29, -30, -32, -33, -35, -37, -38, -40, -41, -43, -44,
-45, -46, -46, -47, -47, -47, -47, -47, -47, -47, -46, -46, -45, -44, -43, -42,
-41, -40, -39, -37, -35, -34, -32, -30, -28, -26, -24, -22, -20, -18, -16, -14,
-12, -11, -9, -7, -5, -4, -3, -1, 0, 1, 2, 3, 3, 4, 4, 4, 4, 4, 3, 3, 2, 2, 1,
0, -1, -2, -3, -5, -6, -8, -9, -11, -13, -15, -17, -18, -20, -21, -23, -24, -25,
-26, -27, -27, -28, -28, -28, -28, -28, -27, -27, -26, -26, -25, -24, -23, -23,
-22, -21, -20, -19, -18, -17, -17, -16, -15, -15, -14, -13, -12, -12, -11, -10,
-10, -9, -8, -8, -7, -7, -6, -6, -5, -5, -4, -4, -3, -3, -3, -2, -2, -2, -2, -2,
-2, -2, -3, -3, -4, -4, -5, -6, -7, -8, -9, -9, -10, -11, -12, -13, -14, -15,
-15, -15, -16, -16, -16, -16, -17, -17, -17, -16, -16, -16, -15, -15, -14, -14,
-13, -13, -12, -12, -11, -10, -10, -9, -8, -8, -7, -7, -6, -6, -6, -6, -5, -6,
-6, -6, -6, -6, -6, -6, -6, -6, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7, -7,
-7, -6, -5, -5, -4, -3, -3, -2, -1, 0, 1, 2, 3, 4, 5, 5, 6, 6, 7, 8, 8, 9, 9, 9,
9, 9, 9, 9, 9, 8, 8, 8, 7, 7, 7, 6, 6, 6, 5, 5, 4, 3, 3, 2, 1, 1, 0, -1, -1, -2,
-2, -3, -3, -4, -4, -4, -5, -5, -6, -6, -6, -6, -7, -7, -7, -7, -7, -7, -6, -6,
-6, -5, -4, -4, -3, -2, -1, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 10, 11, 11, 12,
12, 13, 14, 14, 15, 15, 16, 17, 17, 18, 18, 19, 19, 19, 20, 20, 21, 21, 22, 22,
22, 23, 23, 23, 23, 23, 22, 22, 22, 22, 21, 21, 20, 20, 19, 18, 18, 17, 16, 16,
15, 15, 15, 15, 14, 14, 14, 14, 14, 15, 15, 15, 16, 16, 17, 17, 18, 18, 19, 19,
19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 17, 17, 17, 16, 16, 15, 14, 14,
13, 13, 12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 12, 13, 13, 14,
15, 15, 16, 17, 18, 18, 19, 19, 20, 20, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21,
20, 20, 19, 18, 17, 16, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 7, 6, 5, 4, 3, 1,
0, -1, -2, -3, -4, -6, -7, -8, -9, -11, -12, -13, -14, -15, -16, -17, -18, -19,
-19, -19, -19, -19, -20, -20, -20, -20, -20, -19, -19, -19, -19, -18, -18, -18,
-18, -17, -16, -15, -15, -14, -13, -12, -12, -11, -10, -9, -9, -8, -7, -7, -6,
-6, -5, -5, -5, -5, -4, -4, -4, -4, -4, -5, -5, -5, -6, -6, -7, -8, -9, -10,
-11, -12, -13, -14, -15, -16, -17, -18, -19, -19, -20, -20, -21, -21, -21, -21,
-21, -21, -21, -21, -21, -21, -20, -20, -20, -20, -19, -18, -18, -17, -16, -15,
-14, -14, -13, -12, -12, -11, -11, -10, -10, -9, -9, -8, -8, -7, -7, -6, -6, -6,
-5, -5, -5, -5, -5, -5, -5, -5, -6, -7, -7, -8, -8, -9, -10, -11, -12, -13, -14,
-16, -17, -18, -19, -21, -22, -23, -24, -26, -27, -28, -29, -29, -30, -31, -31,
-32, -33, -33, -34, -34, -34, -34, -34, -34, -34, -34, -33, -33, -32, -31, -31,
-30, -29, -28, -27, -26, -25, -23, -22, -21, -19, -18, -16, -15, -13, -11, -10,
-8, -7, -6, -4, -3, -2, -1, 0, 0, 1, 2, 2, 3, 3, 3, 3, 2, 2, 2, 1, 1, 0, 0, -1,
-2, -2, -3, -3, -3, -4, -4, -5, -5, -6, -7, -7, -8, -9, -9, -10, -10, -11, -12,
-13, -14, -15, -15, -16, -16, -17, -17, -18, -18, -19, -19, -20, -20, -20, -21,
-21, -22, -22, -22, -22, -22, -22, -22, -22, -22, -21, -21, -21, -21, -21, -21,
-21, -21, -21, -21, -21, -22, -22, -22, -23, -23, -22, -22, -22, -22, -22, -22,
-22, -22, -22, -22, -22, -21, -21, -20, -19, -19, -18, -18, -18, -17, -16, -16,
-15, -14, -13, -12, -12, -12, -12, -11, -10, -9, -8, -8, -7, -6, -6, -5, -4, -3,
-2, -1, 0, 1, 1, 2, 3, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 15, 16, 16, 16, 16,
16, 16, 16, 15, 14, 13, 11, 10, 8, 6, 4, 2, 1, -1, -3, -5, -6, -8, -9, -10, -12,
-13, -14, -15, -16, -17, -18, -19, -20, -20, -20, -20, -21, -21, -22, -21, -21,
-19, -18, -16, -15, -13, -12, -10, -9, -7, -5, -3, -2, 0, 1, 3, 5, 6, 8, 9, 10,
12, 13, 14, 14, 14, 15, 15, 16, 18, 19, 19, 20, 19, 19, 19, 20, 20, 22, 23, 23,
24, 24, 24, 25, 25, 26, 26, 26, 27, 27, 26, 26, 26, 26, 25, 25, 25, 25, 25, 25,
25, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 25, 25, 25, 26, 26,
26, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 29, 29, 28, 28, 27, 27, 26, 25,
25, 24, 24, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 22, 22, 22, 22, 22, 22, 22,
21, 21, 20, 20, 20, 19, 19, 19, 18, 18, 18, 17, 17, 17, 16, 15, 15, 14, 14, 13,
13, 13, 12, 12, 12, 11, 11, 11, 10, 10, 10, 9, 9, 9, 9, 9, 8, 8, 8, 7, 7, 6, 6,
6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 10, 10, 11, 11, 12, 13, 14, 14, 15, 16, 17, 18,
19, 20, 20, 21, 22, 23, 24, 25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 33,
34, 33, 32, 32, 32, 32, 32, 31, 31, 31, 31, 30, 30, 29, 28, 28, 27, 26, 26, 25,
25, 24, 24, 23, 23, 22, 21, 20, 19, 18, 17, 17, 16, 16, 15, 14, 14, 13, 12, 12,
11, 11, 11, 10, 10, 10, 9, 9, 9, 10, 10, 10, 10, 11, 10, 10, 10, 10, 10, 10, 10,
10, 10, 10, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 10, 10, 9, 9, 9, 8,
8, 8, 7, 7, 7, 7, 7, 7, 6, 6, 6, 7, 7, 7, 7, 8, 9, 9, 10, 10, 11, 11, 12, 13,
13, 14, 14, 14, 15, 15, 15, 14, 14, 13, 12, 12, 11, 9, 8, 7, 6, 4, 3, 1, -1, -3,
-5, -6, -8, -10, -11, -13, -15, -16, -18, -20, -21, -23, -24, -25, -26, -27,
-28, -29, -29, -30, -30, -30, -31, -31, -31, -31, -31, -31, -31, -31, -31, -31,
-32, -32, -32, -32, -32, -32, -32, -32, -32, -32, -33, -33, -33, -34, -34, -34,
-34, -34, -34, -34, -34, -33, -33, -33, -32, -32, -32, -32, -31, -31, -31, -31,
-31, -30, -30, -30, -30, -29, -29, -29, -29, -28, -28, -27, -26, -25, -25, -24,
-23, -22, -21, -19, -18, -17, -16, -15, -14, -13, -12, -11, -10, -9, -9, -8, -7,
-6, -5, -5, -4, -4, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3,
-4, -4, -5, -5, -6, -7, -8, -8, -9, -10, -11, -12, -13, -15, -16, -17, -18, -19,
-20, -21, -21, -22, -23, -23, -24, -24, -25, -25, -26, -26, -27, -27, -27, -27,
-27, -27, -27, -27, -27, -27, -27, -26, -26, -25, -25, -24, -23, -22, -21, -20,
-19, -18, -16, -15, -13, -12, -11, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2,
2, 3, 4, 4, 4, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0, 0, -1, -1, -2,
-3, -3, -4, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -9, -9, -9, -9,
-10, -10, -10, -10, -10, -10, -10, -9, -9, -8, -8, -7, -6, -5, -5, -4, -4, -3,
-2, -2, -1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2,
3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 1, 1, 1, 0, -1, -1, -1, -2, -2, -3, -3,
-4, -4, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -4, -4, -3, -3, -2, -1, -1, 0,
0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 5, 6, 7, 7, 8, 9, 10, 11, 11, 12,
12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 17, 18, 18, 19, 19, 19, 20, 20, 20,
20, 21, 21, 21, 22, 22, 22, 22, 22, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 24,
24, 23, 23, 22, 22, 21, 21, 20, 20, 19, 19, 18, 17, 16, 15, 15, 14, 13, 12, 12,
11, 10, 10, 10, 9, 9, 8, 8, 8, 7, 7, 7, 6, 6, 5, 5, 5, 4, 4, 4, 3, 3, 3, 2, 2,
2, 2, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2,
-2, -3, -3, -3, -3, -4, -4, -4, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
-5, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -1, -1, -1, 0,
0, 1, 2, 2, 3, 4, 4, 5, 6, 7, 7, 8, 9, 9, 10, 11, 12, 12, 13, 13, 13, 13, 14,
14, 14, 14, 13, 13, 13, 12, 11, 11, 10, 9, 8, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -1,
-2, -3, -3, -4, -4, -4, -5, -5, -5, -5, -5, -5, -5, -6, -5, -5, -5, -5, -5, -5,
-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -4, -3, -3, -2, -1, 0, 1, 1, 2, 3, 4, 5,
6, 6, 7, 8, 8, 9, 10, 10, 10, 11, 11, 11, 11, 10, 10, 10, 10, 9, 9, 9, 8, 8, 8,
8, 8, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 3, 3, 3, 2, 2,
2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, -1, -1, -2,
-3, -4, -4, -5, -6, -7, -8, -9, -10, -11, -11, -12, -13, -13, -14, -15, -15,
-16, -16, -17, -17, -18, -19, -19, -20, -20, -20, -20, -20, -20, -20, -20, -20,
-20, -20, -19, -19, -19, -18, -18, -18, -18, -17, -17, -17, -16, -16, -16, -15,
-15, -14, -14, -14, -13, -13, -13, -12, -12, -12, -11, -11, -11, -11, -11, -12,
-12, -12, -13, -13, -13, -14, -14, -15, -15, -15, -16, -16, -16, -16, -17, -17,
-17, -17, -17, -17, -17, -17, -17, -17, -16, -16, -16, -15, -15, -14, -14, -14,
-13, -13, -12, -11, -11, -10, -10, -10, -9, -9, -9, -8, -8, -8, -7, -7, -6, -6,
-6, -5, -5, -5, -4, -4, -4, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -2, -2, -2, -3,
-3, -4, -4, -4, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6, -6,
-6, -6, -6, -5, -5, -5, -5, -5, -4, -4, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 0, 0, 1,
1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8,
8, 9, 9, 9, 10, 10, 10, 10, 11, 11, 11, 11, 11, 10, 10, 10, 9, 9, 8, 8, 7, 7, 6,
6, 5, 4, 4, 3, 2, 2, 1, 0, 0, -1, -1, -2, -2, -3, -3, -4, -4, -5, -5, -5, -5,
-5, -5, -5, -5, -5, -5, -5, -4, -4, -4, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1,
-1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 2, 2, 2, 1, 1, 0, 0, -1, -1, -2, -2, -3, -3,
-4, -4, -4, -4, -4, -4, -4, -4, -5, -5, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6,
-6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -6, -6, -7, -7, -8, -9, -9, -10, -10,
-11, -12, -13, -13, -14, -14, -15, -15, -16, -16, -17, -17, -18, -18, -18, -19,
-19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -19, -18, -18, -18, -17, -17,
-16, -16, -15, -15, -14, -14, -13, -12, -12, -11, -10, -9, -9, -8, -7, -6, -5,
-4, -3, -2, -2, -1, -1, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
-1, -1, -1, -2, -2, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6,
-5, -5, -5, -5, -5, -5, -4, -4, -4, -4, -3, -3, -3, -3, -2, -2, -2, -2, -1, -1,
-1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, -1, -1, -2, -3,
-3, -4, -5, -5, -6, -7, -7, -8, -8, -8, -9, -9, -10, -10, -10, -10, -11, -11,
-11, -11, -11, -11, -11, -11, -10, -10, -10, -9, -9, -8, -8, -7, -7, -6, -6, -5,
-5, -4, -3, -2, -2, -1, 0, 1, 1, 2, 3, 4, 5, 5, 6, 7, 7, 8, 8, 8, 9, 9, 9, 9, 9,
9, 9, 9, 9, 9, 9, 8, 8, 8, 7, 7, 6, 6, 5, 4, 4, 3, 3, 2, 2, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 5, 6, 6, 7, 8, 9, 9, 10, 10, 11, 11, 12, 12,
12, 13, 13, 13, 13, 12, 12, 12, 12, 11, 11, 10, 10, 9, 9, 8, 8, 7, 7, 6, 5, 5,
4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4,
5, 6, 6, 7, 7, 8, 8, 9, 9, 9, 10, 10, 11, 11, 12, 12, 12, 13, 13, 13, 12, 12,
12, 12, 11, 11, 10, 9, 8, 8, 7, 6, 6, 5, 4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 7, 7, 8, 9, 9, 10, 11, 11, 12, 12, 13, 13,
14, 14, 15, 15, 16, 16, 16, 17, 17, 17, 17, 17, 17, 16, 16, 15, 15, 14, 14, 13,
12, 12, 11, 10, 9, 8, 8, 7, 6, 5, 5, 4, 3, 2, 2, 1, 0, -1, -2, -3, -3, -4, -5,
-5, -6, -6, -6, -6, -5, -5, -5, -5, -4, -4, -3, -2, -1, -1, 0, 1, 2, 3, 5, 6, 7,
8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 25, 26, 26,
27, 27, 27, 27, 27, 26, 26, 26, 25, 25, 24, 24, 23, 23, 22, 21, 20, 19, 18, 17,
16, 15, 14, 13, 11, 10, 9, 8, 6, 5, 4, 4, 3, 2, 2, 2, 2, 2, 2, 2, 3, 3, 4, 5, 5,
6, 8, 9, 10, 11, 13, 14, 16, 17, 19, 20, 22, 23, 24, 25, 26, 27, 28, 29, 29, 29,
29, 29, 29, 28, 27, 27, 26, 25, 24, 23, 22, 21, 20, 19, 17, 16, 15, 13, 12, 11,
10, 9, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -3, -4, -4, -4, -4, -4, -4, -3, -3,
-2, -2, -1, 0, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 16, 17,
17, 17, 17, 17, 17, 17, 17, 17, 17, 16, 15, 15, 14, 14, 13, 12, 12, 11, 11, 10,
9, 9, 8, 7, 6, 6, 5, 4, 4, 3, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6,
5, 5, 5, 4, 4, 4, 4, 3, 3, 2, 2, 1, 1, 1, 0, 0, -1, -1, -2, -3, -3, -3, -4, -4,
-5, -5, -6, -6, -7, -7, -7, -7, -7, -7, -6, -6, -5, -5, -4, -4, -3, -3, -2, -2,
-1, -1, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 0, -1, -2, -2, -3,
-4, -5, -6, -7, -8, -9, -9, -10, -11, -12, -13, -14, -15, -16, -17, -18, -18,
-19, -20, -20, -21, -22, -22, -22, -23, -23, -23, -24, -24, -24, -24, -24, -23,
-23, -23, -23, -22, -22, -21, -20, -19, -18, -17, -16, -15, -14, -13, -12, -11,
-10, -9, -8, -8, -7, -6, -5, -5, -4, -4, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -3, -3, -3, -4, -4, -4, -5, -5, -6, -6, -6, -7, -7, -7, -8,
-8, -8, -8, -8, -9, -9, -9, -9, -9, -9, -9, -9, -8, -8, -8, -8, -7, -7, -6, -6,
-6, -5, -5, -4, -4, -3, -3, -2, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -2, -2, -2, -2, -3, -3, -4, -4, -5,
-6, -6, -7, -7, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -7, -7, -7, -7, -6,
-6, -6, -5, -5, -4, -4, -4, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1, -1, -2, -2,
-2, -3, -3, -4, -4, -5, -6, -6, -7, -8, -9, -9, -10, -11, -11, -12, -13, -13,
-14, -14, -15, -15, -16, -16, -17, -17, -17, -17, -18, -18, -18, -18, -18, -17,
-17, -17, -17, -17, -17, -17, -16, -16, -16, -16, -15, -15, -14, -14, -13, -12,
-12, -11, -11, -10, -9, -9, -8, -7, -7, -6, -6, -5, -5, -5, -4, -4, -4, -3, -3,
-3, -3, -3, -3, -2, -2, -3, -3, -3, -3, -3, -3, -4, -4, -4, -5, -5, -5, -6, -6,
-7, -7, -8, -8, -8, -9, -9, -10, -10, -10, -10, -11, -11, -11, -11, -11, -11,
-11, -11, -10, -10, -10, -10, -9, -9, -8, -7, -7, -6, -5, -5, -4, -3, -3, -2,
-2, -1, 0, 0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 4, 4, 4,
4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, -1, -1, -2, -2, -2, -3, -3, -3, -3, -3, -3,
-3, -3, -3, -2, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 3, 3, 3, 2, 2, 1, 1, 0, 0, -1, -1, -2, -3, -3, -4, -5, -5, -6,
-6, -6, -7, -7, -7, -8, -8, -8, -8, -8, -8, -8, -8, -8, -9, -9, -9, -9, -9, -9,
-9, -9, -8, -8, -8, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -4, -3, -3, -3, -3,
-3, -3, -3, -3, -4, -4, -4, -4, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8,
-9, -9, -10, -10, -10, -11, -11, -12, -12, -12, -13, -13, -13, -13, -14, -14,
-14, -14, -14, -14, -14, -14, -14, -14, -14, -14, -13, -13, -13, -12, -12, -11,
-11, -10, -9, -9, -8, -7, -6, -6, -5, -4, -3, -2, -2, -1, 0, 0, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -4, -4, -5,
-5, -6, -6, -7, -7, -8, -8, -8, -8, -8, -8, -9, -9, -8, -8, -8, -8, -8, -8, -7,
-7, -6, -6, -5, -5, -4, -4, -3, -2, -2, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -2, -2, -3, -3, -4, -4, -5, -6, -6, -7, -7,
-8, -8, -8, -9, -9, -9, -9, -10, -10, -10, -11, -11, -11, -11, -11, -11, -11,
-11, -10, -10, -10, -9, -9, -8, -8, -7, -7, -6, -6, -5, -4, -4, -3, -2, -2, -1,
-1, 0, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1, 1, 0,
0, -1, -1, -2, -3, -3, -4, -4, -5, -6, -6, -7, -7, -8, -9, -9, -10, -10, -11,
-11, -11, -12, -12, -12, -13, -13, -13, -14, -14, -14, -14, -14, -14, -14, -14,
-14, -14, -14, -14, -13, -13, -13, -13, -13, -13, -13, -13, -13, -13, -13, -13,
-13, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -11,
-11, -11, -11, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10,
-10, -10, -10, -9, -9, -9, -8, -8, -7, -7, -6, -6, -5, -4, -4, -3, -3, -2, -1,
-1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, -1, -1, -1, -2, -2, -3, -3, -4, -4,
-5, -6, -6, -7, -7, -8, -9, -9, -10, -10, -10, -11, -11, -11, -12, -12, -12,
-13, -13, -13, -13, -13, -14, -14, -14, -14, -14, -13, -13, -13, -12, -12, -12,
-11, -10, -9, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 2, 3, 4, 4, 5, 5, 6,
7, 7, 8, 8, 9, 9, 9, 9, 9, 9, 10, 9, 9, 9, 9, 9, 8, 8, 8, 7, 7, 7, 6, 6, 5, 5,
5, 4, 4, 4, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5, 6, 6,
7, 7, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 9, 9,
9, 9, 8, 8, 8, 8, 7, 7, 7, 6, 6, 5, 5, 5, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7,
8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
9, 9, 9, 8, 8, 8, 7, 7, 7, 6, 6, 6, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 5, 5, 5, 5, 6,
6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 10, 10, 11, 11, 11, 11, 12, 12, 12, 12, 12, 13,
13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 11, 11, 11, 11, 10,
10, 9, 9, 9, 9, 8, 8, 7, 7, 7, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6,
6, 6, 7, 7, 7, 8, 8, 9, 9, 9, 10, 10, 11, 12, 12, 13, 14, 14, 15, 15, 16, 16,
17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 17, 17, 17, 16, 16, 16,
15, 15, 15, 14, 14, 13, 12, 12, 11, 11, 10, 10, 10, 9, 9, 9, 9, 8, 8, 8, 8, 8,
8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 11, 11, 10, 10, 10,
10, 10, 10, 9, 9, 9, 8, 8, 8, 7, 7, 7, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4,
4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 5, 5,
5, 4, 4, 4, 3, 3, 2, 2, 2, 1, 1, 0, 0, 0, 0, -1, -1, -1, -2, -2, -2, -2, -3, -3,
-3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -5, -5,
-5, -5, -5, -4, -4, -4, -3, -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 1, 2, 2, 3, 3,
4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
7, 7, 7, 7, 6, 6, 6, 5, 5, 5, 4, 4, 3, 3, 3, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6,
6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 6, 6, 6, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3,
3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, -1, -1, -2, -2,
-3, -3, -3, -4, -4, -4, -4, -5, -5, -4, -4, -4, -4, -4, -3, -3, -3, -2, -2, -1,
0, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
7, 6, 6, 6, 6, 6, 5, 5, 5, 5, 4, 4, 3, 3, 3, 2, 2, 1, 1, 0, 0, -1, -1, -1, -2,
-2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -1, -1, -1, -1, 0, 0, 0,
1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, -1, -1, -1, -1, -2, -2, -3, -3, -4, -4, -5, -6, -6, -7, -7, -8, -8, -9,
-9, -9, -9, -10, -10, -10, -9, -9, -9, -9, -9, -8, -8, -7, -7, -7, -6, -6, -5,
-4, -4, -3, -2, -2, -1, -1, 0, 0, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1,
0, -1, -1, -2, -2, -3, -4, -4, -5, -6, -6, -7, -8, -8, -9, -10, -10, -11, -11,
-12, -12, -13, -13, -14, -14, -14, -14, -14, -14, -14, -14, -14, -14, -13, -13,
-13, -13, -12, -12, -11, -11, -11, -10, -10, -10, -9, -9, -8, -8, -8, -7, -7,
-7, -6, -6, -6, -6, -5, -5, -5, -5, -6, -6, -6, -6, -6, -7, -7, -7, -8, -8, -8,
-8, -8, -9, -9, -9, -10, -10, -10, -11, -11, -11, -11, -12, -12, -12, -12, -12,
-12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10, -10,
-9, -9, -8, -8, -7, -7, -6, -6, -5, -5, -4, -4, -3, -3, -3, -2, -2, -2, -2, -2,
-2, -2, -2, -3, -3, -3, -4, -4, -5, -5, -6, -6, -7, -7, -8, -8, -9, -9, -10,
-10, -11, -11, -12, -12, -12, -13, -13, -13, -13, -13, -13, -14, -14, -14, -14,
-14, -14, -13, -13, -13, -13, -13, -12, -12, -12, -11, -11, -11, -10, -10, -9,
-9, -9, -8, -8, -7, -7, -6, -6, -5, -5, -5, -4, -4, -4, -4, -4, -3, -3, -3, -3,
-3, -3, -3, -4, -4, -4, -4, -4, -5, -5, -5, -6, -6, -7, -7, -8, -8, -9, -10,
-10, -11, -11, -12, -12, -13, -13, -13, -14, -14, -14, -15, -15, -15, -15, -15,
-15, -15, -15, -15, -14, -14, -14, -13, -13, -12, -12, -11, -11, -10, -10, -9,
-9, -8, -8, -8, -7, -7, -7, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -6, -6, -6,
-6, -6, -7, -7, -8, -8, -8, -9, -9, -10, -10, -11, -11, -11, -11, -12, -12, -12,
-12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -12, -11, -11, -11, -10, -10,
-10, -9, -9, -9, -8, -8, -8, -8, -8, -7, -7, -7, -7, -7, -7, -7, -7, -7, -6, -7,
-7, -7, -7, -7, -7, -7, -7, -7, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
-8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -7, -7, -7, -7, -6, -6, -5, -5, -4, -4,
-4, -3, -3, -2, -2, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, -1, -1, -2, -2, -3, -3, -4, -4,
-5, -5, -6, -7, -7, -8, -8, -8, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -8, -8,
-8, -7, -7, -7, -6, -6, -6, -5, -5, -5, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3,
-3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -3, -3, -3, -4, -4, -4, -4, -5, -5, -5, -5, -6, -6, -6, -6, -6, -6, -6, -6,
-6, -6, -6, -6, -6, -6, -6, -6, -6, -5, -5, -5, -5, -5, -5, -4, -4, -4, -4, -4,
-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4,
-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -5, -5, -5, -5,
-5, -5, -5, -5, -5, -5, -5, -4, -4, -4, -4, -4, -3, -3, -3, -3, -2, -2, -2, -1,
-1, 0, 0, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6,
6, 6, 6, 6, 6, 6, 5, 5, 5, 4, 4, 4, 4, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3,
3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 7, 7, 7, 7, 7, 6, 6,
6, 6, 6, 6, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3,
3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5,
5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10,
10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
11, 11, 11, 10, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 8, 8, 8, 8, 8, 7, 7, 7, 7, 7,
7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 7, 7, 7, 6, 6, 6, 5, 5, 5,
4, 4, 4, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, -1, -1, -1, -2, -2, -2, -2, -3, -3, -3, -4, -4, -4, -4, -4, -4, -5, -5,
-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5,
-5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -5, -4, -4, -4, -4, -4, -3, -3, -3, -2,
-2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2,
3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7,
7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10, 11, 11,
11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 11,
11, 11, 11, 10, 10, 10, 10, 9, 9, 9, 8, 8, 8, 7, 7, 6, 6, 6, 5, 5, 4, 4, 3, 2,
2, 2, 1, 1, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2,
2, 2, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, -1, -1, -1, -1,
-1, -2, -2, -2, -2, -3, -3, -4, -4, -5, -5, -5, -6, -6, -6, -7, -7, -7, -7, -8,
-8, -8, -8, -8, -8, -8, -8, -7, -7, -7, -6, -6, -6, -5, -5, -5, -4, -4, -4, -3,
-3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -4,
-4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -2, -2, -2, -1, -1, 0, 0, 1,
1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 3, 3, 3, 2, 2, 2,
1, 1, 1, 0, 0, 0, -1, -1, -2, -2, -2, -3, -4, -4, -5, -5, -6, -6, -7, -8, -8,
-8, -9, -9, -9, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10, -10,
-10, -10, -10, -10, -10, -10, -10, -10, -10, -9, -9, -9, -9, -9, -9, -9, -9, -9,
-9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -10, -10,
-10, -10, -10, -11, -11, -11, -12, -12, -13, -13, -13, -14, -14, -14, -15, -15,
-15, -15, -15, -15, -15, -14, -14, -13, -13, -13, -12, -12, -11, -11, -10, -10,
-10, -9, -9, -8, -8, -7, -7, -6, -6, -6, -5, -5, -4, -4, -4, -4, -3, -3, -3, -3,
-3, -3, -3, -3, -3, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -5, -5, -5, -6, -6,
-6, -7, -7, -8, -8, -8, -8, -9, -9, -9, -9, -9, -8, -8, -8, -7, -7, -6, -6, -5,
-5, -4, -4, -3, -3, -2, -2, -1, -1, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 4, 4, 4, 3, 3, 3, 2, 2, 1, 1, 0, 0,
-1, -1, -2, -2, -2, -3, -3, -3, -4, -4, -4, -4, -4, -4, -4, -4, -4, -4, -3, -3,
-3, -2, -2, -1, -1, -1, 0, 0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 2, 2, 1, 1, 1, 0, 0,
0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 1, 1,
1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2,
2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2,
-2, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
0, 0, 0, 0, 0, -1, -1, -1, -1, -2, -2, -2, -2, -3, -3, -3, -3, -4, -4, -4, -5,
-5, -5, -5, -6, -6, -6, -7, -7, -7, -8, -8, -8, -8, -9, -9, -10, -10, -9, -9,
-10, -10, -10, -9, -5, -2, };

#endif /* CLUST_HIT_01_H_ */