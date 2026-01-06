/*****************************************************************************
* | File      	:   Splash.c
* | Function    :   show splash screen on startup
* | Info        :
*----------------
* |	This version:   V1.0
* | Date        :   2025-12-08
* | Info        :
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documnetation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to  whom the Software is
# furished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS OR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
******************************************************************************/
#include "Splash.h"
#include "../lib/LCD/LCD_1in14_V2.h"
#include "../lib/Images/Rp2350Geek.h"

/* 
bool reserved_addr(uint8_t addr)
{
    return (addr & 0x78) == 0 || (addr & 0x78) == 0x78;
}
*/

int Splash_Show(void)
{
 
    printf("Splash_Show().\r\n");
    if (DEV_Module_Init() != 0)
    {
        return -1;
    }
    DEV_SET_PWM(0);
    /* LCD Init */
    printf("LCD_1IN14_V2_Init\r\n");
    LCD_1IN14_V2_Init(HORIZONTAL);
    LCD_1IN14_V2_Clear(BLACK);
    UDOUBLE Imagesize = LCD_1IN14_V2_HEIGHT * LCD_1IN14_V2_WIDTH * 2;
    UWORD *BlackImage;
    if ((BlackImage = (UWORD *)malloc(Imagesize)) == NULL)
    {
        printf("Failed to malloc black memory...\r\n");
        exit(0);
    }
    // /*1.Create a new image cache named IMAGE_RGB??? and fill it with white*/
    Paint_NewImage((UBYTE *)BlackImage, LCD_1IN14_V2.WIDTH, LCD_1IN14_V2.HEIGHT, 0, WHITE);
    Paint_SetScale(65);
    Paint_Clear(BLACK);
    Paint_SetRotate(ROTATE_0);
    Paint_Clear(BLACK);
 
    // Splash
    printf("Paint_DrawImage.\r\n");
    Paint_DrawImage(gGeek_Image, 0, 0, 240, 135);
    LCD_1IN14_V2_Display(BlackImage);
    
    for (int i = 0; i < 100; i++){
        DEV_SET_PWM(i); 
        DEV_Delay_ms(100);
    }
    DEV_Delay_ms(6000);
   for (int i = 100; i > 0; i--){
        DEV_SET_PWM(i); 
        DEV_Delay_ms(200);
    }    
    DEV_SET_PWM(100); 

    return 0;
}
