#include <stdio.h>
#include <pigpio.h>
#include <unistd.h>

// utilizing GPIO pin 26
#define LED_PIN 26

int main() {

    if (gpioInitialise() < 0) {
        printf("piGPIO init failed\n");
        return 1;
    }
    
    // open to out
    if (gpioSetMode(LED_PIN, PI_OUTPUT)) {
        printf("piGPIO set to out failed\n");
        return 1; 
    }

    // set to 1 (on) for 1 second, off (0) for 1 second, repeat...
    for (int i = 0; i < 10; i++) {
        gpioWrite(LED_PIN, 1);
        gpioSleep(PI_TIME_RELATIVE, 1, 0);
        gpioWrite(LED_PIN, 0);
        gpioSleep(PI_TIME_RELATIVE, 1, 0);
    }

    // reinstate to in
    if (gpioSetMode(LED_PIN, PI_INPUT)) {
        printf("piGPIO set to in failed\n");
    }
    gpioTerminate();

    return 0;
}