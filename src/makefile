IDIR=../include
CC=g++
CFLAGS =-I$(IDIR) -ftest-coverage -fprofile-arcs
EXT=c

ODIR=obj
LDIR=../lib

GTESTLIBS = -lgtest
LIBS=$(GTESTLIBS) -lm

_DEPS=conversor.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=main.o conversor.o 
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.$(EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

conversor: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~core $(INCDIR)/*~
