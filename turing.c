#include "turing.h"
#include <stdio.h>
#include <stdlib.h>

int checkTuring(tape_t tape){ 
    int result = 0; // ustawienie wyniku na 0
    for(int i=0;i<tape.length;i++){
        if(tape.items[i]=='0'){ // ilosc 0 oznacza wynik koncowy
            result++;
        }
    }
    return result;
}

tape_t turing(tape_t tape, int state)
{
    char *pointer = malloc((tape.length)*sizeof(char)); // zaalokowanie pamieci na wskaznik ktory wskazuje aktualna pozycje na taśmie
    for (int i = 0; i < tape.length; i++)
    {
        if (i == tape.activeIndex) // w miejsce aktualnego indexu wstawiamy v(ktore imituje strzalke), a w pozostale miejsca spacje
        {
            pointer[i] = 'v';
            continue;
        }
        pointer[i]=' ';
    }
    printf("%s\n", pointer); // wypisujemy wskaznik 
    printf("%s\n", tape.items); // wypisujemy tasnme
    if (state != 6) // jezeli stan nie jest 6(q6) maszyna Turinga dziala
    {
        int i = tape.activeIndex; // skrocenie nazwy zeby latwiej sie wpisywalo
        int prevIndex = i; // index przed przesunieciem tasmy(potrzebny do wypisania)
        printf("q%d: %c->", state, tape.items[i]); // wypisanie aktualnego stanu oraz wartosci na tasmie przed przesunieciem
        switch (state) // instrukcja warunkowa ktora pozwala wybrac nam odpowiedni stan(case) a nastepnie w zaleznosci od znaku na tasmie dobrac odpowiednie przesuniecie i ewentualna zamiane tego znaku
        {
        case 0:
            if (tape.items[i] == '0')
            {

                tape.items[i] = 'B';
                tape.activeIndex++; // ++ przesuniecie w prawo
                state = 1;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                state = 5;
            }
            break;
        case 1:
            if (tape.items[i] == '0')
            {
                tape.items[i] = '0';
                tape.activeIndex++;
                state = 1;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = '1';
                tape.activeIndex++;
                state = 2;
            }
            break;
        case 2:
            if (tape.items[i] == '0')
            {
                tape.items[i] = '1';
                tape.activeIndex--; // -- przesuniecie w lewo
                state = 3;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = '1';
                tape.activeIndex++;
                state = 2;
            }
            else
            {
                tape.items[i] = 'B';
                tape.activeIndex--;
                state = 4;
            }
            break;
        case 3:
            if (tape.items[i] == '0')
            {
                tape.items[i] = '0';
                tape.activeIndex--;
                state = 3;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = '1';
                tape.activeIndex--;
                state = 3;
            }
            else
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                state = 0;
            }
            break;
        case 4:
            if (tape.items[i] == '0')
            {
                tape.items[i] = '0';
                tape.activeIndex--;
                state = 4;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = 'B';
                tape.activeIndex--;
                state = 4;
            }
            else
            {
                tape.items[i] = '0';
                tape.activeIndex++;
                state = 6;
            }
            break;
        case 5:
            if (tape.items[i] == '0')
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                state = 5;
            }
            else if (tape.items[i] == '1')
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                state = 5;
            }
            else
            {
                tape.items[i] = 'B';
                tape.activeIndex++;
                state = 6;
            }
            break;
        }
        char dir = tape.activeIndex>prevIndex ? 'R' : 'L'; // ustalenie przesuniecia w zaleznosci od zmiany indexu(jezeli poprzedni byl wiekszy to w lewo jezeli mniejszy to w prawo)
        printf("%c, %c\n\n", tape.items[i],dir); // wypisanie zmienionego znaku i przesuniecia
        return turing(tape, state); // powtorzenie czynnosci az do dojscia do stanu 6
    }
    else
        return tape; // gdy dojdziemy do stanu 6 zwracamy naszą taśmę
}