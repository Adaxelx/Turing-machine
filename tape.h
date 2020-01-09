#ifndef TAPE_H
#define TAPE_H

typedef struct
{
    char *items;
    int length;
    int activeIndex;
} tape_t;

tape_t setTape(int m, int n);

void moveTape(tape_t, int);

#endif