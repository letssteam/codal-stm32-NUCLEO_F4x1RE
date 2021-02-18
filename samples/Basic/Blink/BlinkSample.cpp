#include "BlinkSample.h"

void BlinkSample_main(){
    codal::STM32NUCLEO_F4x1RE NUCLEO_F4x1RE;
	bool state = false;
	while(true)
    {    
		NUCLEO_F4x1RE.io.led1.setDigitalValue((int)state);
        NUCLEO_F4x1RE.io.led2.setDigitalValue((int)!state);
        NUCLEO_F4x1RE.sleep(1000);
        state = !state;
    }
}