#ifndef PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS
#define PICO_STDIO_USB_CONNECT_WAIT_TIMEOUT_MS (5000)
#endif

#include <stdio.h>
#include "pico/stdlib.h"

#include "c/Splash.h"

int main(void)
{

    stdio_init_all();

    sleep_ms(2000);  //usb is connected but minicom must need more time

    Splash_Show();

    return 0;
}
