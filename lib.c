void newline()
{
    putchar('\n');
}

void put_bool(bool NL = true)
{
    pushp(FP);
    FP = SP;
    Word V = *(WPtr)((FP+1));

    char c = V ? 'T' : 'F';
    putchar(c);
    if (NL) newline();

    popp(FP);
    SP += 1;
}

void put_char() // internal function called by put_str()
{
    pushp(FP);
    FP = SP;
    Word V = *(WPtr)((FP+1));

    putchar((char)V);

    popp(FP);
    SP += 1;
}

void put_int(bool NL = true)
{
    pushp(FP);
    FP = SP;
    Word V = *(WPtr)((FP+1));

    printf("%lld", V);
    if (NL) newline();

    popp(FP);
    SP += 1;
}

void put_str(bool NL = true)
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
    if (NL) newline();
    popp(FP);
    SP += 1;
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
        put_bool(false);
        if (i<len-1) putchar(' ');
    }
    newline();

    popp(FP);
    SP += 1;
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
        put_int(false);
        if (i<len-1) putchar(' ');
    }
    newline();

    popp(FP);
    SP += 1;
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
        put_str(false);
        if (i<len-1) putchar(' ');
    }
    newline();

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

    popp(FP);
    SP += 1;
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

    popp(FP);
    SP += 2;
}

int str_cmp(Word O1[], Word O2[])
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
        
        if ( str_cmp(e, (WPtr)(L[i])) == 0 )
        {
            R0 = 1;
            goto RET;
        }
    }
    R0 = 0;

RET:
    popp(FP);
    SP += 2;
}

