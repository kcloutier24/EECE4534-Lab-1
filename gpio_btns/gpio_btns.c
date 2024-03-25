/*
  @file gpio.c
  @brief GPIO Manipulation Skeleton Code

 */

#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//LED GPIO Address
#define LED_GPIO_ADDR 0x41200000
#define BUTTONS_ADDR  0x41220000

// register offsets
#define REG_OFFSET(REG, OFF) ((REG)+(OFF))

// map GPIO peripheral; base address will be mapped to gpioregs pointer
static int map_gpio(unsigned int** gpioregs, unsigned int gpio_addr, int io_settings)
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
    size_t len = 0x10000; //Span from the one GPIO to the next
    *gpioregs = (unsigned int *)mmap(NULL, len, io_settings, MAP_SHARED, fd, gpio_addr);
    if (*gpioregs == MAP_FAILED)		// check for errors
    {
        close (fd);		// close memory before exiting
        exit(1);        // Returns 1 to the operating system;
    }
    // success
    return 0;
}

/* Function to extract a single bit at index "bit_index" (Starts from LSB index=0) from num*/
int extract_bit(int num, int bit_index)
{
    return (num & (1 << bit_index)) >> bit_index;
}

/* Function to set two adjacent bits at index ("index") and ("index" + 1) (Starts from LSB index=0) from to_set superimposed on original_num*/
int set_bit_two_leds(int original_num, int to_set, int index)
{
    return (original_num & ~(0b11 << index)) | (((to_set << 1) + to_set) << index);
}

int main(int argc, char** argv)
{
    // try to setup LEDs
    unsigned int *led_regs;
    if (map_gpio(&led_regs, LED_GPIO_ADDR, PROT_WRITE)){ return 1; }
    // reset LEDs register
    *REG_OFFSET(led_regs, 0) = 0x00;//led_state; //Set the LEDs to the state

    // try to setup buttons
    unsigned int *buttons_regs;
    if (map_gpio(&buttons_regs, BUTTONS_ADDR, PROT_READ)){ return 1; }

    unsigned int state = *REG_OFFSET(buttons_regs, 0) & 0x1F; //Only read the first five bits
    unsigned int led_state = 0;
    
    while (1)
    {
        int reading = *REG_OFFSET(buttons_regs, 0) & 0x1F; //Poll the button state
        usleep(10000); //This is necessary for the ZPanel to update properly. If it goes too fast it will crash/slow significantly. Likely can be removed for the actual board

        if(reading != state) //Print out button states only if there is a change
        {
            printf("Button Change Detected: %X\n", reading);

            led_state = set_bit_two_leds(led_state, extract_bit(reading, 4), 4); //Set LEDs for button U (4th bit, setting LEDs 4 and 5)
            led_state = set_bit_two_leds(led_state, extract_bit(reading, 1), 2); //Set LEDs for button D (1st bit, setting LEDs 3 and 2)
            led_state = set_bit_two_leds(led_state, extract_bit(reading, 3), 0); //Set LEDs for button R (3th bit, setting LEDs 0 and 1)
            led_state = set_bit_two_leds(led_state, extract_bit(reading, 2), 6); //Set LEDs for button L (2th bit, setting LEDs 6 and 7)

            state = reading;
            *REG_OFFSET(led_regs, 0) = led_state; //Set the LEDs to the state
        }
        

        
    }

  return 0;
}