
AR_RC = ar rcs
CC = gcc
CCDEPMODE = depmode=gcc3
CFLAGS = -g -O0 -Wall -pedantic -std=c11
CPP = gcc -E
CPPFLAGS = 

EXEEXT =
LIBS = -lopengl32 -lglu32 -lglut -lz -lm

OBJS =  soliar.o o_bmp.o


all: main_1$(EXEEXT)

.c.o:
	$(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<

main_1$(EXEEXT): main_1.o $(OBJS)
	$(CC) $(CFLAGS) -o $@ main_1.o $(OBJS) $(LIBS)

soliar.o: soliar.h
o_bmp.o:  o_bmp.h HS_ADAPT.h

main_1.o: o_bmp.h soliar.h

clean:
	rm *.o *.exe




