#include "tape.h"
#include <stdlib.h>
#include <stdio.h>
tape_t setTape(int m, int n)
{
    tape_t tape;
    tape.length = m + n + 5;
    tape.items = malloc(tape.length * sizeof(char));
    tape.activeIndex = 2;
    for (int i = 0; i < tape.length; i++)
    {

        if (i < 2 || i > tape.length - 3)
        {
            tape.items[i] = 'B';
        }
        else if (i == m + 2)
        {
            tape.items[i] = '1';
        }
        else if (i <= n + m + 2)
        {
            tape.items[i] = '0';
        }
    }
    return tape;
}