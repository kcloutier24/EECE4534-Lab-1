# Your Makefile should compile both fifo_nonBlock.c and fifo_test.c 
#and produce the binary fifo_test. 
#The rule make test first compile and then execute the testbench.

make test: fifo_test.o fifo_nonBlock.o
	gcc fifo_test.c fifo_nonBlock.c -o output
	./output

fifo_nonBlock.o: fifo_nonBlock.c fifo_nonBlock.h
	gcc -c fifo_nonBlock.c

fifo_test.o: fifo_test.c fifo_nonBlock.h
	gcc -c fifo_test.c