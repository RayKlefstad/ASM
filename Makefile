.SUFFIXES: .c .s .out

T = fun.c str.c lib.c
	
def: asm out

asm: $(T:.c=.s)

out: $(T:.c=.out)

.c.out:
	g++ $(CCFLAGS) $< -o $@

.c.s:
	g++ $(CCFLAGS) -S $<


clean:
	/bin/rm $(T:.c=.s) $(T:.c=.out)
