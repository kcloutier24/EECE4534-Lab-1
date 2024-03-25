/**
    Katherine Cloutier and Jared Cohen
    Lab 1
    Issue #2


    Done Connect to the physcial ZedBoard and validate that the hello world program works (see hello directory) on the ZedBoard.

    DONE Create a new directory convert which will late house the program to convert Fahrenheit to Celsius (last of prereq assignment).

    DONE  Resuse and update the makefile and the .vscode directory if using VS Code.

    Notes for VS Code:
    DONE In VS Code open the directory of the program being worked on (e.g. hello or convert) as a folder.
    Note that there is a hidden folder (.vscode) in the hello which contains files that
    specify the project configuration for Visual Studio Code. This must be also copied over to convert.

    DONE In the .vscode/launch.json file, change the program field to point to your executable (in this case change the main part to convert).

    DONE Valildate that the hello world works after renaming. Commit the code to git before modifying.

    DONE Copy and paste the code from one of the lab parters' prerequisite to to read a temperature value in Fahrenheit degrees from the console input and output the converted value to Celsius. In addition, if the temperature is below 0 degrees Celsius then print a “Freezing” warning.

    Run the program on the Zedboard by using the “Zedboard Debug” debug configuration. Note, due to the remote execution through debug and ssh the standard input does not work. The program will just run to completion. In order to make the input work, run the program directly on the ZedBoard (i.e. through ssh).

*/

#include <stdio.h>
#include <stdlib.h>

// initialize variables
double fahrenheit, celsius;
char input[30];

double getF()
{

    // read in fahrenheit from console
    printf("enter fahrenheit please: ");
    // scanf("%lf",&fahrenheit);
    fgets(input, sizeof(input), stdin);

    fahrenheit = atof(input);

    // printf("%.2lf\n", fahrenheit);

    return fahrenheit;
}

double convert()
{
    fahrenheit = getF();

    // convert fahrenheit to celsius (F - 32) * 5/9
    celsius = (fahrenheit - 32.0) * (5.0 / 9.0);

    // output celsius
    printf("celsius: %0.2lf\n", celsius);

    // if below 0 deg CELSIUS pring freeze warning
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
