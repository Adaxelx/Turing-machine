#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXL 100

int main()
{
    char buf[MAXL];
    fgets(buf, MAXL, stdin);
    checkIfValid();
    return 0;
}