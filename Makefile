CC = gcc

default: libfactors.a

libfactors.a: factors.o
    ar rcs $@ $^

factors.o: factors.c rsa.h
    $(CC) -c $<

clean:
    rm *.o *.a
