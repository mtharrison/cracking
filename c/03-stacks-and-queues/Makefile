CXX = gcc
CFLAGS = -I ../utils -g
OUTFILE = -o $@.out
INFILE = $@.c
UTILS = ../utils
STDPATTERN = $(CXX) $(CFLAGS) $(OUTFILE) $(INFILE)

03-01:
	$(STDPATTERN) $(UTILS)/LinkedList.c $(UTILS)/Stack.c
03-02:
	$(STDPATTERN) $(UTILS)/LinkedList.c
clean:
	rm *.out
