#readme.md

This fixes the LCD example for the RP2350GEEK

The main fix was:

#define LCD_BL_PIN   25 //13

This example now Displays the GEEK image,
                  fades up the backlight,
                                   waits,
            the fades down the backlight.
