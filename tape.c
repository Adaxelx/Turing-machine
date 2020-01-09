#include "tape.h"
#include <stdlib.h>

tape_t setTape(int m, int n)
{
    tape_t tape; // deklaracja tasmy
    tape.length = m + n + 5; // ustalenie dlugosci tasmy czyli 2 liczby ktore zostana zamienione na 0 (m i n) oraz 4 znaki puste po obu stronach i 1 jedynka odzielajaca liczby(zera)
    tape.items = malloc(tape.length * sizeof(char)); // alokacja pamieci na znaki ktore beda na taśmie
    tape.activeIndex = 2; // ustalenie aktywnego indexu na pierwszy element ktory nie jest znakiem pustym
    for (int i = 0; i < tape.length; i++)
    {
        if (i < 2 || i > tape.length - 3) // ustalenie znakow pustych na 2 pierwszych i 2 ostatnich miejscach
        {
            tape.items[i] = 'B';
        }
        else if (i == m + 2) // ustalenie 1, ktora oddziela liczby po pierwszej liczbie czyli m i po 2 znakach pustych
        {
            tape.items[i] = '1';
        }
        else if (i <= n + m + 2) // na pozostalych miejscach 0(czyli nasze liczby)
        {
            tape.items[i] = '0';
        }
    }
    return tape; // zwracamy tasme
}