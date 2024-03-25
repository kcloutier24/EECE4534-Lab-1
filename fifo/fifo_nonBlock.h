#ifndef FIFO_NON_BLOCK
#define FIFO_NON_BLOCK
/** Interface definition for non blocking fifo */

#define FIFO_cap 32 //fifo can hold 32 characters 4 bytes = 1 char


/** write len bytes from pData into the FIFO up until FIFO is full
     returns number of bytes written */
int fifo_write(char *pData, int len);

/** read up to len bytes from FIFO into pData up until FIFO is empty
     returns number of bytes read */
int fifo_read(char *pData, int len);

/** returns how many bytes are stored  currently in the FIFO */
int fifo_fillLevel();

/** reinitialize FIFO to be empty */
void fifo_reset();


#endif