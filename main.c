#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 100

int main()
{
    char buf[MAXL];
    fgets(buf, MAXL, stdin);
    int m, n;
    char *temp = malloc(MAXL * sizeof(char));
    int j = 0;
    int check = 0;
    for (int i = 0; i < strlen(buf) - 1; i++)
    {
        if ((buf[i] >= '0' && buf[i] <= '9') || buf[i] == ' ')
        {

            if (buf[i] == ' ' && check == 0)
            {
                m = atoi(temp);
                j = 0;
                memset(temp, 0, MAXL);
                check++;
                continue;
            }
            else if (buf[i] == ' ' && check == 1)
            {
                printf("Za duzo liczb. Podaj 2 liczby oddzielone spacją.\n");
                return -1;
            }

            temp[j] = buf[i];
            j++;
            if (i == strlen(buf) - 2)
            {
                check++;
                n = atoi(temp);
            }
        }
        else
        {
            printf("Złe liczby wejściowe. Błąd w miejscu: %d. Prawidłowy format to np: 12 1\n", i + 1);
            return -1;
        }
    }
    if (check != 2)
    {
        printf("Za mało liczb\n");
        return -1;
    }
    return 0;
}