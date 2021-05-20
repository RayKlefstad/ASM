#include <stdio.h>
#include <stdlib.h>
#include "machine.h"

Word S[]={'h','e','l','l','o', 0};

Word IL[]={0,1,1,2,3,5,8,13,21,34,55,89};

Word BL[]={1,0,1,0,1,0,1,0,1,0,1,0};

WPtr SL[]={S,S,S,S,S};

void put_bool(Word V)
{
    Word c = V ? 'T' : 'F';
    putchar((char)c);
}

void put_int(Word V)
{
    printf("%lld", V);
}

void put_str(Word s[])
{
    for (int i=0; s[i] != 0; ++i)
        putchar((char)s[i]);
}

void put_bool_list(Word A[], Word len)
{
    for (int i=0; i<len; ++i)
    {
        put_bool((Word)(A[i]));
        if (i<len-1) putchar(' ');
    }
}

void put_int_list(Word A[], Word len)
{
    for (int i=0; i<len; ++i)
    {
        put_int((Word)(A[i]));
        if (i<len-1) putchar(' ');
    }
}

void put_str_list(WPtr A[], Word len)
{
    for (int i=0; i<len; ++i)
    {
        put_str((Word*)(A[i]));
        if (i<len-1) putchar(' ');
    }
}

#define BYTES_PER_BOOL 8

WPtr py_malloc(Word words)
{
    return (WPtr)malloc((int)(words * BYTES_PER_BOOL));
}

WPtr c_str_to_py_str(char *p)
{
    return 0; // TBD
}

WPtr input()
{
    char buf[BUFSIZ];
    int size = BUFSIZ;
    fgets(buf, size, stdin);
    return c_str_to_py_str(buf);
}

void newline()
{
    putchar('\n');
}

int main()
{
    Word b = 0;
    Word i = 12345678901234567;

    put_bool(b);
    put_bool(!b);
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
