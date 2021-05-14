#include <stdio.h>

typedef long long int int64;

int64 s[]={'h','e','l','l','o','\n', 0};

int64 fun(int64 *t, int64 c)
{
    t[0] = c;
}

void put_str(int64 s[])
{
    for (int i=0; s[i] != 0; ++i)
        putchar((char)s[i]);
}

int64 main()
{
    int64 c = 'M';

    int64 i = fun(s, c);

    put_str(s);
    return 0;
}
