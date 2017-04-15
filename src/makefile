IDIR=../include
CC=g++
CFLAGS =-I$(IDIR)
EXT=c

ODIR=obj
LDIR=../lib

GTESTLIBS = -lgtest
LIBS=$(GTESTLIBS) -lm

_DEPS=grafo.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ=testa_grafo.o grafo.o 
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.$(EXT) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

grafo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~core $(INCDIR)/*~
