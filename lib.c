#include <stdio.h>
#include <stdlib.h>

typedef long long int int64; // a MiniPython bool or int
typedef int64 * int64p; // a pointer to a str, list, or class object

int64 S[]={'h','e','l','l','o','\n', 0};

int64p IL[]={0,1,1,2,3,5,8,13,21,34,55,89};

int64 BL[]={1,0,1,0,1,0,1,0,1,0,1,0};

int64p SL[]={S,S,S,S,S};

void put_bool(int64 V)
{
    int64 c = V ? 'T' : 'F';
    putchar((char)c);
}

void put_int(int64 V)
{
    printf("%lld\n", V);
}

void put_str(int64 s[])
{
    for (int i=0; s[i] != 0; ++i)
        putchar((char)s[i]);
}

void put_bool_list(int64 A[], int64 len)
{
    for (int i=0; i<len; ++i)
        put_bool((int64)(A[i]));
}

void put_int_list(int64p A[], int64 len)
{
    for (int i=0; i<len; ++i)
        put_int((int64)(A[i]));
}

void put_str_list(int64p A[], int64 len)
{
    for (int i=0; i<len; ++i)
        put_str((int64*)(A[i]));
}

void * py_malloc(int64 bytes)
{
    return (void *)malloc((int)bytes);
}

void newline()
{
    putchar('\n');
}

int64 main()
{
    int64 b = 0;
    int64 i = 12345678901234567;

    put_bool(b);
    newline();
    put_int(i);
    newline();
    put_str(S);
    newline();
    put_bool_list(BL,sizeof(BL)/sizeof(*BL));
    newline();
    put_int_list(IL,sizeof(IL)/sizeof(*IL));
    newline();
    put_str_list(SL,sizeof(SL)/sizeof(*SL));
    newline();
    return 0;
}
