#include <stdio.h>

typedef long long int int64;

int64 sum(int64 a, int64 b, int64 c)
{
    return a + b + c;
}

int64 main()
{
    int64 a = 2, b = 4, c = 6;

    int64 i = sum(a, b, c);

    printf("I is %lld\n", i);
    return 0;
}
