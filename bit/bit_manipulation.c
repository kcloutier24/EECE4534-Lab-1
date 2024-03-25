/**
 * Katherine Cloutier
 * cloutier.k@northeastern.edu
 * 
 * In a new directory bit, create a file bit_manipulation.c. In there implement a function "bitClear3Set7" which 
 * gets an unsigned char as an input value and returns a value of the same type. 
 * 
 * The function should perform the following two actions:

Using bit operators in C, clear bit 3 without affecting other bits. 
Note that the least significant bit is bit number 0.
Using bit operators in C, set bit 7 the without affecting other bits

The main function should print the decimal value 46 in hex format, 
call bitClear3Set7() and then print the resulting value in hex format.
 * 
*/


#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

//variables!!
int val = 46;
unsigned char unsichar;
int bits[8]; //0-7 

//gets an unsigned char as an input value and returns a value of the same type.
unsigned char bitClear3Set7(unsigned char unsichar)
{

    //two following actions happen in this function, using bit operators to clear and set bits
    //Kat: Bit shift?

    //clear bit 3 without affecting other bits
    //Kat: clear meaning set to 0?
    
    //set bit 7 without affecting other bits 
    //Kat: set bit 7 to what?

    for (int i = 0 ; i < 8 ; i++) 
    {

        bits[i] = (unsichar & (1 << i)) != 0; //finds if bit 1 or 0 then store result in bits[i]

  
	    if( i == 3)// clear bit 3
        {
            bits[i] = 0;
            //printf("%d CHANGED char: %d\n",i, bits[i]);
            continue;

        }
        if (i == 7)// set bit 7
        {
            bits[i] = 1;
	        //printf("%d CHANGED char: %d\n", i,bits[i]);
	        continue;

        }
        else
        {
	       //printf("%d NO CHANGE char: %d\n",i, bits[i]);

        }
        



    }

    int changed= 0;//set new value to 0
    //need to add back up the bits 2^....
    for(int y = 0; y<8; y++)
    {
        int place = pow(2,y);
        changed = changed + bits[y]*(place);
        //printf("%d \n",changed);

        

    }



    //need to return the value

    //printf("changed %d \n",changed);
    return changed;



}


//The main function should print the decimal value 46 in hex format, 
//call bitClear3Set7() and then print the resulting value in hex format.

int main()
{

    printf("%d in hexadecimal = %x\n",val,val);
    int result= bitClear3Set7(val);
    printf("the result after going through bitClear3Set7() is %d, and is %x\n in hexidecimal",result,result);


    return 0;
}













