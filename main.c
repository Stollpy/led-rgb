#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pigpio.h>

#define red_led 17
#define green_led 18
#define blue_led 27

void setup()
{
    gpioSetPWMrange(red_led, 255);
    gpioSetPWMrange(green_led, 255);
    gpioSetPWMrange(blue_led, 255);
}


void setColors(int red, int green, int blue)
{
  gpioPWM(red_led, red);
  gpioPWM(green_led, green);
  gpioPWM(blue_led, blue);
}

void increment(int led, int red, int green, int blue)
{
    usleep(50000);
    setColors(red, green, blue);

    for (int i = 0; i <= 255; ++i) {
        gpioPWM(led, i);
        usleep(50000);
    }
}
void decrement(int led, int red, int green, int blue)
{
    usleep(50000);
    setColors(red, green, blue);

    for (int i = 255; i >= 0; --i) {
        gpioPWM(led, i);
        usleep(50000);
    }
}

int main() {
    if (gpioInitialise() < 0) {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }

   setup();

    while(1) {
        fprintf(stderr, "increment green\n");
        increment(green_led, 255, 0, 0);
        fprintf(stderr, "decrement red\n");
        decrement(red_led, 255, 255, 0);
        fprintf(stderr, "increment blue\n");
        increment(blue_led, 0, 255, 0);
        fprintf(stderr, "decrement green\n");
        decrement(green_led, 0, 255, 255);
        fprintf(stderr, "increment red\n");
        increment(red_led, 0, 0, 255);
        fprintf(stderr, "decrement blue\n");
        decrement(blue_led, 255, 0, 255);
    }
}
