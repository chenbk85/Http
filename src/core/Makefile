CFLAGS = -g -Wall


_OBJS = $(shell ls *.c)
OBJS = $(_OBJS:.c=.o)


all: $(OBJS)


%.o: %.c
	cc $(CFLAGS) -o $@ -c $<


clean:
	rm -fr $(OBJS) 

