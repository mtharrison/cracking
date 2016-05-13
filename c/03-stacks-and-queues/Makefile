CXX = gcc
CFLAGS = -I ../utils
OUTFILE = -o $@.out
INFILE = $@.c
UTILS = ../utils
STDPATTERN = $(CXX) $(CFLAGS) $(OUTFILE) $(INFILE)

03-01:
	$(STDPATTERN) $(UTILS)/LinkedList.c $(UTILS)/Stack.c
clean:
	rm *.out
