#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pigpio.h>

#define red_led 17
#define green_led 18
#define blue_led 27

void setupLed()
{
    gpioSetPWMrange(red_led, 100);
    gpioSetPWMrange(green_led, 100);
    gpioSetPWMrange(blue_led, 100);
}


void setColors(int red, int green, int blue)
{
  gpioPWM(red_led, red);
  gpioPWM(green_led, green);
  gpioPWM(blue_led, blue);
}

int main() {
    if (gpioInitialise() < 0) {
        fprintf(stderr, "pigpio initialisation failed\n");
        return 1;
    }

   setupLed();

    int r;
    int g;
    int b;

    while(1) {
        r=rand()%100;
        g=rand()%100;
        b=rand()%100;

        setColors(r, g, b);
        printf("r=%d, g=%d, b=%d \n",r,g,b);
        usleep(200000);
    }
}
