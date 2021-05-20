#include <stdio.h>
#include "machine.h"

typedef long long int Word;

Word sum(Word a, Word b, Word c)
{
    return a + b + c;
}

int main()
{
    Word a = 2, b = 4, c = 6;

    Word i = sum(a, b, c);

    printf("I is %lld\n", i);
    return 0;
}
