#ifndef TAPE_H
#define TAPE_H

typedef struct
{
    char *items;
    int length;
    int activeIndex;
} tape_t; // struktura taśmy(items czyli znaki na taśmie, length - długość i activeIndex czyli miejsce na ktorym jestesmy na taśmie)

tape_t setTape(int m, int n); // ustalenie poczatkowej taśmy

#endif