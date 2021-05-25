#include "machine.h"
#include <stdio.h>
#include <stdlib.h>

void put_bool()
{
    pushp(FP);
    FP = SP;
    Word V = *(WPtr)((FP+1));

    char c = V ? 'T' : 'F';
    putchar(c);

    SP += 1;
    popp(FP);
}

void put_char()
{
    pushp(FP);
    FP = SP;
    Word V = *(WPtr)((FP+1));

    putchar((char)V);

    SP += 1;
    popp(FP);
}

void put_int()
{
    pushp(FP);
    FP = SP;
    Word V = *(WPtr)((FP+1));

    printf("%lld\n", V);

    SP += 1;
    popp(FP);
}

void put_str()
{
    pushp(FP);
    FP = SP;
    WPtr O = (WPtr)*(WPtr)((FP+1));

    Word max = O[0];
    Word len = O[1];
    WPtr A = &(O[2]);
    for (int i=0; i<len; ++i)
    {
        pushw(A[i]);
        put_char();
    }
    SP += 1;
    popp(FP);
}

void put_bool_list()
{
    pushp(FP);
    FP = SP;
    WPtr O = (WPtr)*(WPtr)((FP+1));

    Word max = O[0];
    Word len = O[1];
    WPtr A = &(O[2]);
    for (int i=0; i<len; ++i)
    {
        pushw(A[i]);
        put_bool();
        if (i<len-1) putchar(' ');
    }

    SP += 1;
    popp(FP);
}

void put_int_list()
{
    pushp(FP);
    FP = SP;
    WPtr O = (WPtr)*(WPtr)((FP+1));

    Word max = O[0];
    Word len = O[1];
    WPtr A = &(O[2]);
    for (int i=0; i<len; ++i)
    {
        pushw(A[i]);
        put_int();
        if (i<len-1) putchar(' ');
    }
    SP += 1;
    popp(FP);
}

void put_str_list()
{
    pushp(FP);
    FP = SP;
    WPtr O = (WPtr)*(WPtr)((FP+1));

    Word max = O[0];
    Word len = O[1];
    WPtr A = &(O[2]);
    for (int i=0; i<len; ++i)
    {
        pushp(A[i]);
        put_str();
        if (i<len-1) putchar(' ');
    }

    SP += 1;
    popp(FP);
}

#define BYTES_PER_BOOL 8

void py_malloc()
{
    pushp(FP);
    FP = SP;
    Word words = *(WPtr)((FP+1));

    R0 = (Word)malloc((int)(words * BYTES_PER_BOOL));

    SP += 1;
    popp(FP);
}

void int_in_list()
{
    pushp(FP);
    FP = SP;
    Word e = *((WPtr)((FP+1)));
    WPtr O = (WPtr)*((WPtr)((FP+2)));
    Word len = O[1];
    WPtr L = &(O[2]);

    for (int i=0; i<len; ++i)
        if ( e  == L[i] )
        {
            R0 = 1;
            break;
        }
    R0 = 0;

    SP += 2;
    popp(FP);
}

int str_n_cmp(Word O1[], Word O2[])
{
    Word len1 = O1[1];
    Word len2 = O2[1];
    WPtr S1 = &(O1[2]);
    WPtr S2 = &(O2[2]);
    
    for (int i=0; i<len1 && i < len2; ++i)
    {
        if ( S1[i] != S2[i] )
        {
            return S2[i] - S1[i];
        }
    }
    return len2 - len1;
}

void str_in_str()
{
    pushp(FP);
    FP = SP;
    WPtr e = (WPtr)*((WPtr)((FP+1)));
    WPtr O = (WPtr)*((WPtr)((FP+2)));
    Word len = O[1];
    WPtr L = &(O[2]);

    for (int i=0; i<len; ++i)
    {
        printf("Checking %lld in %lld\n", e, L[i]);
        
        if ( str_n_cmp(e, (WPtr)(L[i])) == 0 )
        {
            R0 = 1;
            goto RET;
        }
    }
    R0 = 0;

RET:
    SP += 2;
    popp(FP);
}

