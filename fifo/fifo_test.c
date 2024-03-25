/**
 * Katherine CLoutier
 * cloutier.k@northeastern.edu
 * 
 * Implement single-threaded testbench fifo_test.c to validate correctness of the FIFO with test cases.
*/

#include <string.h>
#include <stdio.h>
#include "fifo_nonBlock.h"

int main()
{

    //printf("does the makefile work?\n");

    //create fifo
    fifo_reset();


    //get how full it is
    int test = fifo_fillLevel();
    printf("%d\n",test);


    //write something to it
    //4 bytes 1 char
    char first_write[] = "Hello FIFO!!";
    int write = fifo_write( first_write, sizeof(first_write)-1);
    printf("chars written to FIFO: %d \n", write);


    //get how full it is
    test = fifo_fillLevel();
    printf("%d\n",test);

    //read something from it
    char first_read[8];
    int read = fifo_read(first_read, sizeof(first_read));
    printf("chars read from FIFO: %d \n", read);


    //get how full it is
    test = fifo_fillLevel();
    printf("%d\n",test);

    //reset it
    fifo_reset();

    //get how full it is
    test = fifo_fillLevel();
    printf("%d\n",test);

    //fill it up 
    //write something to it
    //4 bytes 1 char
    char second_write[] = "This is my second write, Hello!!";
    write = fifo_write( second_write, sizeof(second_write)-1);
    printf("chars written to FIFO: %d \n", write);


    //get how full it is
    test = fifo_fillLevel();
    printf("%d\n",test);

    //read something from it
    char second_read[32];
    read = fifo_read(second_read, sizeof(second_read));
    printf("chars read from FIFO: %d \n", read);

    //get how full it is
    test = fifo_fillLevel();
    printf("%d\n",test);



    return 0;

}




