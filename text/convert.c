/**
 * Katherine Cloutier
 * cloutier.k@northeastern.edu
 * 
 * 
 * 
 * Create a file convert.c in the sub directory text. 
 * The program should read a temperature value in Fahrenheit degrees from the console 
 * input and output the converted value to Celsius. 
 * In addition, if the temperature is below * 0 degrees Celsius then print a Freezing warning.

Later in lab 1 you will be using the convert program on the ZedBoard. 
In preparaion, please use fgets function to get user input instead of scanf. 
Use atof to convert from string to float.
*/

#include <stdio.h>
#include <stdlib.h>

//initialize variables 
double fahrenheit, celsius;
char input[30];

double getF()
{
    
    //read in fahrenheit from console
    printf("enter fahrenheit please: ");
    //scanf("%lf",&fahrenheit);
    fgets(input, sizeof(input),stdin);

    fahrenheit = atof(input);

    //printf("%.2lf\n", fahrenheit);

    return fahrenheit;
}

double convert()
{
    fahrenheit = getF();

    //convert fahrenheit to celsius (F - 32) * 5/9
    celsius = (fahrenheit - 32.0) * (5.0 / 9.0);

    //output celsius
    printf("celsius: %0.2lf\n", celsius);

    //if below 0 deg CELSIUS pring freeze warning
    if (celsius < 0)
    {
        printf("freezing warning!\n");
        printf("Es ist kalt! it is COLD \n");
    }

    return celsius;

}


int main()
{ 

    convert();

    return 0;
}






