CC=gcc
CFLAGS=-std=c99
RM=rm

all: clean serv

serv: FileSystem.c FileSystemTest.c FileSystem.h
		$(CC) $(CFLAGS) -o serv FileSystem.c FileSystemTest.c FileSystem.h

clean:
		$(RM) -rf serv *.dSYM

