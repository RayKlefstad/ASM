.SUFFIXES: .c .s .out

CFLAGS = -std=c99

T = fun.c str.c lib.c
	
def: asm out

asm: $(T:.c=.s)

out: $(T:.c=.out)

.c.out:
	gcc $(CFLAGS) $< -o $@

.c.s:
	gcc $(CFLAGS) -S $<


clean:
	/bin/rm $(T:.c=.s) $(T:.c=.out)
