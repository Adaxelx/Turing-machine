#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tape.h"
#include "turing.h"

#define MAXL 100 // definicja największej długości podanego napisu(czyli liczb)

int main()
{
    char buf[MAXL]; // deklaracja tablicy ktora będzie przechowywała liczby podane przez uzytkownika(jako chary)
    fgets(buf, MAXL, stdin); // pobranie od uzytkownika podanych liczb
    int m, n; // deklaracja m i n
    char *temp = malloc(MAXL * sizeof(char)); // alokacja pamięci dla zmiennej przechowującej jedną liczbę
    int j = 0; // index  do temp   
    int check = 0; // zmienna do sprawdzenia czy zostały podane 2 liczby
    for (int i = 0; i < strlen(buf) - 1; i++)
    {
        if ((buf[i] >= '0' && buf[i] <= '9') || buf[i] == ' ')  // uzytkownik moze podać tylko liczbe i oddzielic je spacja
        {

            if (buf[i] == ' ' && check == 0) // to powinna byc pierwsza liczba
            {
                m = atoi(temp); // zamieniamy przechowany napis na typ int 
                j = 0; // zerujemy index aby zapisac 2 liczbe
                memset(temp, 0, MAXL); // czyscimy tablice
                check++; // zaznaczamy ze jedna liczba juz zostala podana
                continue;
            }
            else if (buf[i] == ' ' && check == 1) // jezeli jedna liczba zostala podana i spotkamy spacje traktujemy to jako podanie kolejnej liczby(3)
            {
                printf("Za duzo liczb. Podaj 2 liczby oddzielone spacją.\n");
                return -1;
            }

            temp[j] = buf[i]; // dodajemy znak do zmiennej tymczasowej i zwiekszamy index j;
            j++;
            if (i == strlen(buf) - 2) // jezeli jestesmy na ostatnim znaku napisu znaczy ze ostatnia liczba zostala podana
            {
                check++; // zwiekszamy zmiena przechowujaca ilosc podanych liczb
                n = atoi(temp);
            }
        }
        else // gdy podamy cos innego niz liczbe lub spacje
        {
            printf("Złe liczby wejściowe. Błąd w miejscu: %d. Prawidłowy format to np: 12 1\n", i + 1);
            return -1;
        }
    }
    if (check != 2) // jezeli nie ma 2 liczb to znaczy ze zostalo podane 1 lub 0 liczb(gdyz 3 lub wiecej sprawdzalismy w petli)
    {
        printf("Za mało liczb\n");
        return -1;
    }
    
    printf("%d-%d=%d\n",m,n,checkTuring(turing(setTape(m,n),0))); // wyswietlenie wyniku po ustawieniu tasmy i przejsciu po niej
    return 0;
}