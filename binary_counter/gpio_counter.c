/*
  @file gpio.c
  @brief GPIO Manipulation Skeleton Code

 */

#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// example: LED GPIO Address
#define LED_GPIO_ADDR 0x41200000

// register offsets
#define REG_OFFSET(REG, OFF) ((REG)+(OFF))

// map GPIO peripheral; base address will be mapped to gpioregs pointer
static int map_gpio(unsigned int** gpioregs, unsigned int gpio_addr)
{
    int fd;

    if (!gpioregs || !gpio_addr)
    {
        // invalid pointers
        return 1;
    }

    fd = open( "/dev/mem", (O_RDWR | O_SYNC)); //Open /dev/mem and check for errors
	if (fd == -1)
	{
        printf("/dev/mem could not be opened\n");
        return 1;
	}

    // use mmap here to map the appropriate address (gpio_addr) into the gpioregs pointer passed
    // by the caller.
    // return non-zero codes on errors!
    size_t len = 0x10000; //Span from the LEDs to before the switches
    *gpioregs = (unsigned int *)mmap(NULL, len, (PROT_WRITE), MAP_SHARED, fd, gpio_addr);
    if (*gpioregs == MAP_FAILED)		// check for errors
    {
        close (fd);		// close memory before exiting
        exit(1);        // Returns 1 to the operating system;
    }
    // success
    return 0;
}

int main(int argc, char** argv)
{
    unsigned int *gpioregs;

    // try to setup LEDs
    if (map_gpio(&gpioregs, LED_GPIO_ADDR))
    {
        // failed to setup
        return 1;
    }

    // reset control register
    *REG_OFFSET(gpioregs, 0) = 0x00;
    char input[32];
    while (1)
    {
        printf("Input a number to change the LEDs: "); //Get a number input
        if(fgets(input, 32, stdin) == NULL) //"Throw" error if input fails
        {
            printf("Couldn't get input...\n");
            return -1;
        }
        
        char num = (char)(atoi(input)); //Convert the number to a char

        *REG_OFFSET(gpioregs, 0) = num; //Set the LEDs to the number
    }

  return 0;
}
