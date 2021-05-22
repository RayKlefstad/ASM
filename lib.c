#include <stdio.h>
#include <stdlib.h>
#include "machine.h"

/*
Word S[]={'h','e','l','l','o', 0};
Word IL[]={0,1,1,2,3,5,8,13,21,34,55,89};
Word BL[]={1,0,1,0,1,0,1,0,1,0,1,0};
WPtr SL[]={S,S,S,S,S};
*/

void put_char(Word V)
{
    Word c = (char)V;
    putchar(c);
}

void put_bool(Word V)
{
    char c = V ? 'T' : 'F';
    putchar(c);
}

void put_int(Word V)
{
    printf("%lld", V);
}

void put_str(Word A[])
{
    Word len = A[-1];
    for (int i=0; i<len; ++i)
        put_char(A[i]);
}

void put_bool_list(Word A[])
{
    Word len = A[-1];
    for (int i=0; i<len; ++i)
    {
        put_bool(A[i]);
        if (i<len-1) putchar(' ');
    }
}

void put_int_list(Word A[])
{
    Word len = A[-1];
    for (int i=0; i<len; ++i)
    {
        put_int(A[i]);
        if (i<len-1) putchar(' ');
    }
}

void put_str_list(Word A[])
{
    Word len = A[-1];
    for (int i=0; i<len; ++i)
    {
        put_str((WPtr)(A[i]));
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

struct WordList {
    Word max;
    Word len;
    Word data[];
};

#define DATA(x) ((Word)(x+2))

Word Str[]={10,5,'h','e','l','l','o',0,0,0,0,0};
Word IntList[]={20,12,0,1,1,2,3,5,8,13,21,34,55,89,0,0,0,0,0,0,0,0};
Word BoolList[]={15,12,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0};
Word StrList[]={10,5,DATA(Str),DATA(Str),DATA(Str),DATA(Str),DATA(Str),0,0,0,0,0};

int main()
{
    WordList * sp = (WordList*)(Str);
    WordList * ip = (WordList*)(IntList);
    WordList * bp = (WordList*)(BoolList);
    WordList * slp = (WordList*)(StrList);

    newline();
    put_bool(bp->data[0]);
    newline();
    put_int(bp->max);
    newline();
    put_int(bp->len);
    newline();
    put_bool_list(bp->data);
    newline();

    newline();
    put_char(sp->data[0]);
    newline();
    put_int(sp->max);
    newline();
    put_int(sp->len);
    newline();
    put_str(sp->data);
    newline();

    newline();
    put_int(ip->data[0]);
    newline();
    put_int(ip->max);
    newline();
    put_int(ip->len);
    newline();
    put_int_list(ip->data);
    newline();

    newline();
    put_str((WPtr)(slp->data[0]));
    newline();
    put_int(slp->max);
    newline();
    put_int(slp->len);
    newline();
    put_str_list(slp->data);
    newline();

    newline();
    printf("WordList size = %d\n", sizeof(WordList));
    
    /*
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
    */
    return 0;
}
