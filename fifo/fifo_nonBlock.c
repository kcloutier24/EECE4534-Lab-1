/**
 *  * Katherine CLoutier
 * cloutier.k@northeastern.edu
 * 
 * 
 * Implement FIFO which can hold 32 characters. 
 * FIFO read/write are non-blocking. 
 * If there is not enough space to write (as FIFO is too full), 
 * fewer bytes are written into the FIFO than requested. 
 * 
 * For example if the FIFO has 5 bytes remaining capacity 
 * and writing 10 bytes is requested, only the first 5 bytes are written.

For this, the write function returns the number of chars written (5 in this case). 
Read symmetrically should return the number of bytes read. 
E.g. reading on an empty fifo will return that 0 bytes are read.
 * 
 * Implement the FIFO in file fifo_nonBlock.c according to the header file fifo_nonBlock.h in the fifo sub directory. For simplicity:

No need to implement thread safe operations all access to this FIFO will be from the same thread.
FIFO is a singleton, i.e. only a single FIFO instance can exist in the program.
Memory for FIFO should be statically allocated.
*/


#include "fifo_nonBlock.h"
#include <string.h>
#include <stdio.h>


//variables!
//worm
int FIFO_front = 0;//0 to start
int FIFO_back = 0;//0 to start
char FIFO_bufferO[FIFO_cap];//one buffer at end



/** write len bytes from pData into the FIFO up until FIFO is full
     returns number of bytes written */
int fifo_write(char *pData, int len)
{
    printf("Write\n");

    //Kat: check how much space in fifo
    //Kat: How much is in fifo already
    int FIFO_occupied = FIFO_front - FIFO_back;
    int FIFO_space= FIFO_cap - FIFO_occupied;

    int FIFO_insert; //thing being written to fifo 
    //checking if the thing being written is smaller than the space available
    if( len < FIFO_space)
    {
        FIFO_insert = len;
    }
    //if it is bigger then it will not be written, womp womp
    else
    {

        FIFO_insert = FIFO_space; 
    }


    //Kat: if enough space then go write
    for( int i = 0 ; i < FIFO_insert; i++)
    {
        //put in front of fifo
        FIFO_bufferO[FIFO_front] = pData[i];
        FIFO_front = FIFO_front +1; //push front up with each char write

    }

    //return number of bytes written
    return (FIFO_insert);
}

/** read up to len bytes from FIFO into pData up until FIFO is empty
     returns number of bytes read */
int fifo_read(char *pData, int len)
{
    printf("read\n");

    //Kat: do we have enough data to read?
    int FIFO_occupied = FIFO_front - FIFO_back ;

    int FIFO_observe;
    if (len <FIFO_observe)//if we have enough data to read as what is being asked
    {
        FIFO_observe = len;

    }
    else//if we dont have enough data to provide
    {
        FIFO_observe= FIFO_occupied;
    }

    //Kat: read data if we have data
    for(int i = 0; i<FIFO_observe; i++)
    {
        //read from the back
        pData[i] = FIFO_bufferO[FIFO_back];
        FIFO_back= FIFO_back+1;

    }

    //return number of bytes red
    return (FIFO_observe);


}

/** returns how many bytes are stored  currently in the FIFO */
int fifo_fillLevel()
{
    printf("Fill level: ");

    //Kat: how full is the fifo
    int FIFO_occupied = FIFO_front - FIFO_back;
    return(FIFO_occupied);

}

/** resest back to 0 */
void fifo_reset()
{
    printf("Reset\n");
    FIFO_front = 0;
    FIFO_back = 0;
}


 





