CC = gcc
DEBUG = -g
CFLAGS = -Wall $(DEBUG)
LDFLAGS = -Wall $(DEBUG)
EXEC = Grafo
OBJS = Grafo.o lista.o
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(EXEC)
Grafo.o: Grafo.c
	$(CC) $(CFLAGS) -c Grafo.c
lista.o: lista.c lista.h
	$(CC) $(CFLAGS) -c lista.c
clean:
	find . -name ’*.o’ -type f -delete
	rm -f $(EXEC) $(OBJS)
