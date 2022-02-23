#List of object files
OBJS = history.o tokenizer.o
# := evaluated only once at the first occurenceg
OBJS_MAIN = $(OBJS) ui.o
OBJS_TEST = $(OBJS) tester.o

#Compiler flags -g debug -03 optimization
CFLAGS =-g -O3

#include file dependencies
tokenizer.o: tokenizer.o
history.o: history.h

all: tokenizer

#user input implementation
tokenizer: $(OBJS_MAIN)
	cc -o tokenizer $(CFLAGS) $(OBJS_MAIN)

#Tester.c implementation
tokenizer_test: $(OBJS_TEST)
	cc -o tokenizer_test $(CFLAGS) $(OBJS_TEST)

clean:
	rm -f *.o *.c~ *.h~ *~ *.c# src
run: tokenizer
	./tokenizer
test: tokenizer_test
	./tokenizer_test
