CXX = gcc
CFLAGS = -I ../utils
OUTFILE = -o $@.out
INFILE = $@.c
UTILS = ../utils
STDPATTERN = $(CXX) $(CFLAGS) $(OUTFILE) $(INFILE)

02-01:
	$(STDPATTERN) $(UTILS)/BitVector.c
clean:
	rm *.out
