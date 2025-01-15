#include <stdio.h>
#include <pigpio.h>
#include <unistd.h>

#define LED_PIN 26

int main() {

    if (gpioInitialise() < 0) {
        printf("piGPIO init failed\n");
        return 1;
    }

    if (gpioSetMode(LED_PIN, PI_OUTPUT)) {
        printf("piGPIO set failed");
        return 1; 
    }

    for (int i = 0; i < 10; i++) {
        gpioWrite(LED_PIN, 1);
        gpioSleep(PI_TIME_RELATIVE, 1, 0);
        gpioWrite(LED_PIN, 0);
        gpioSleep(PI_TIME_RELATIVE, 1, 0);
    }

    gpioTerminate();

    return 0;
}