#include "ch.h"
#include "hal.h"
#include "chprintf.h"



//Main is void due to being embedded program, stack size set in make file
int main(void)
{
//Initialize HAL and Kernel
halInit();
chSysInit();

//Turn on serial using usart (Don't connect user USB!)
//sdStart(&SD2, nullptr); //Use usart 2 with default settings, then set pin modes (default serial rate defined in SERIAL_DEFAULT_BITRATE directive in halconf.h)
//palSetPadMode(GPIOA, 0, PAL_MODE_ALTERNATE(1)); //CTS
//palSetPadMode(GPIOA, 1, PAL_MODE_ALTERNATE(1)); //RTS
//palSetPadMode(GPIOA, 14, PAL_MODE_ALTERNATE(1)); //TX
//palSetPadMode(GPIOA, 15, PAL_MODE_ALTERNATE(1)); //RX



//Enable LED
palSetPadMode(GPIOA, 14, PAL_MODE_OUTPUT_PUSHPULL);
palClearPad(GPIOA, 14);


while(true)
{
palTogglePad(GPIOA, 14); //Toggle LED to show things are working OK

chThdSleepMilliseconds(1000);

//numberOfCharactersInString = iqReadTimeout(&((SerialDriver *) &SD2)->iqueue, (unsigned char *) stringBuffer, 8, 100000);

//Read from usart
//numberOfCharactersInString = sdReadTimeout(&SD2, stringBuffer, 8, 100000);

//Echo it back
//sdWrite(&SD2, stringBuffer, 11);

/*
numberOfCharactersRead =  sdReadTimeout( &SD2, stringBuffer, 256, 100);

if(numberOfCharactersRead > 0)
{
chSequentialStreamWrite((BaseSequentialStream *) &SD2, stringBuffer, numberOfCharactersRead);
}
*/



//chSequentialStreamPut((BaseSequentialStream *) &SD2, 'a');


//chprintf((BaseSequentialStream *) &SD2, "%d\r\n", numberOfCharactersRead);



}
}


