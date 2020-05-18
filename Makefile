
SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=%.o)

CFLAGS = -O2
LDFLAGS = -s

all: init respawn

clean:
	rm -f init respawn $(OBJS)

$(OBJS):

%: %.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
