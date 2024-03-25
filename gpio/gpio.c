/*
  @file gpio.c
  @brief GPIO Manipulation Skeleton Code

  Katherine Cloutier and Jared Cohen
  Lab 1
  Issue #3

  Modify the skeleton project as follows:

  Use the skeleton gpio/gpio_skel.c as a starting point. Use git to rename the file into gpio.c
  update the project settings and Makefile for compilation.
  Commit your otherwise unmodified code to git as a working starting point.

  Modify gpio.c so that it turns the LEDs (LD0-7) on the ZedBoard on and off. Be aware that in order to achieve this,
  you must properly configure the GPIO pins as outputs. The LEDs should be visibly blinking.

  HINT: To create delays, use the unix function usleep (see man usleep). Call this function with different delays for the high and low periods.


 */

#include <fcntl.h>
#include <sys/mman.h> //Kat: Unix header and is not available on Windows.
#include <stdio.h>
#include <unistd.h> //for usleep
#include <math.h> //for pow

// LED GPIO Base Address
#define LED_GPIO_ADDR 0x41200000

// register offsets
#define REG_OFFSET(REG, OFF) ((REG) + (OFF))

#define NUM_LEDS 8
int leds[NUM_LEDS] = {0, 1, 2, 3, 4, 5, 6, 7}; // GPIO pins corresponding to LEDs 0-7

// map GPIO peripheral; base address will be mapped to gpioregs pointer
static int map_gpio(unsigned int **gpioregs, unsigned int gpio_addr)
{
  int fd;

  if (!gpioregs || !gpio_addr)
  {
    printf("error ponters \n");

    // invalid pointers
    return 1;
  }

  fd = open("/dev/mem", O_RDWR | O_SYNC); // open dev mem
  if (fd < 0)
  {
    perror("Error opening /dev/mem \n");
    return 1;
  }

  // use mmap here to map the appropriate address (gpio_addr) into the gpioregs pointer passed
  // by the caller.
  // return non-zero codes on errors!
  *gpioregs = mmap(NULL, sizeof(unsigned int), PROT_WRITE, MAP_SHARED, fd, gpio_addr);
  if (*gpioregs == MAP_FAILED)
  {
    printf("error \n");
    close(fd);
    return 1;
  }

  // success
  return 0;
}

int main(int argc, char **argv)
{
  unsigned int *gpioregs;
  printf("test \n");

  // try to setup LEDs
  if (map_gpio(&gpioregs, LED_GPIO_ADDR))
  {
    printf("failed to setup!");

    // failed to setup
    return 1;
  }

  // reset control register
  *REG_OFFSET(gpioregs, 0) = 0x00;

  int count;

  while (1)
  {
    // LEDs on go up
    for (int i = 0; i < NUM_LEDS; i++)
    {
      // set GPIO pins as outputs
      int led = leds[i];
      int test = pow(2, led);

      *REG_OFFSET(gpioregs, 0x00) = pow(2, led); // turn on
      printf("%d \n", test);
      usleep(500000); // sleep for 500 ms
    }
    // LEDs on go down
    for (int i = NUM_LEDS; i > 0; i--)
    {
      // set GPIO pins as outputs
      int led = leds[i];
      int test = pow(2, led); // math used to light up the individual led

      *REG_OFFSET(gpioregs, 0x0) = pow(2, led); // turn on

      printf("%d \n", test);
      usleep(500000); // sleep for 500 ms
    }
  }

  return 0;
}
