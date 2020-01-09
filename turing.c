#include "turing.h"
#include <stdio.h>
#include <stdlib.h>

tape_t turing(tape_t tape, int state)
{
    int stateR;
    char *pointer = malloc(tape.length);
    for (int i = 0; i < tape.length; i++)
    {
        if (i == tape.activeIndex)
        {
            pointer[i] = 'v';
            continue;
        }
        pointer[i] = ' ';
    }

    printf("%s\n", pointer);
    printf("%s\n", tape.items);
    if (state != 6)
    {

        int i = tape.activeIndex;
        int prevIndex = i;
        printf("q%d: %c->", state, tape.items[i]);
        switch (state)
        {
        case 0:
            if (tape.items[i] == '0')
            {

                tape.items[i] = 'B';
                tape.activeIndex++;
                stateR = 1;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                stateR = 5;
            }
            break;
        case 1:
            if (tape.items[i] == '0')
            {
                tape.items[i] = '0';
                tape.activeIndex++;
                stateR = 1;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = '1';
                tape.activeIndex++;
                stateR = 2;
            }
            break;
        case 2:
            if (tape.items[i] == '0')
            {
                tape.items[i] = '1';
                tape.activeIndex--;
                stateR = 3;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = '1';
                tape.activeIndex++;
                stateR = 2;
            }
            else
            {
                tape.items[i] = 'B';
                tape.activeIndex--;
                stateR = 4;
            }
            break;
        case 3:
            if (tape.items[i] == '0')
            {
                tape.items[i] = '0';
                tape.activeIndex--;
                stateR = 3;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = '1';
                tape.activeIndex--;
                stateR = 3;
            }
            else
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                stateR = 0;
            }
            break;
        case 4:
            if (tape.items[i] == '0')
            {
                tape.items[i] = '0';
                tape.activeIndex--;
                stateR = 4;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = 'B';
                tape.activeIndex--;
                stateR = 4;
            }
            else
            {
                tape.items[i] = '0';
                tape.activeIndex++;
                stateR = 6;
            }
            break;
        case 5:
            if (tape.items[i] == '0')
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                stateR = 5;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                stateR = 5;
            }
            else
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                stateR = 6;
            }
            break;
        }
        char dir = tape.activeIndex>prevIndex ? 'R' : 'L';
        printf("%c, %c\n\n", tape.items[i],dir);
        return turing(tape, stateR);
    }
    else
        return tape;
}