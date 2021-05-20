#include <stdio.h>
#include "machine.h"

typedef long long int Word;

Word s[]={'h','e','l','l','o','\n', 0};

Word fun(Word *t, Word c)
{
    t[0] = c;
}

void put_str(Word s[])
{
    for (int i=0; s[i] != 0; ++i)
        putchar((char)s[i]);
}

int main()
{
    Word c = 'M';

    Word i = fun(s, c);

    put_str(s);
    return 0;
}
