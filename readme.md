![GEEK](https://www.waveshare.com/media/catalog/product/cache/1/image/800x800/9df78eab33525d08d6e5fb8d27136e95/r/p/rp2350-geek-7.jpg)

This fixes the LCD example for the RP2350GEEK

The main fix was:

#define LCD_BL_PIN   25 //13

This example now Displays the GEEK image,
                  fades up the backlight,
                                   waits,
            the fades down the backlight.
