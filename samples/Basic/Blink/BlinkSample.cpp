#include "BlinkSample.h"

void BlinkSample_main(){
    codal::STM32NUCLEO_F4x1RE NUCLEO_F4x1RE;
	int state = 0;
	while(1)
    {    
		NUCLEO_F4x1RE.io.led1.setDigitalValue(state);
        NUCLEO_F4x1RE.io.led2.setDigitalValue(!state);
        NUCLEO_F4x1RE.sleep(1000);
        state = !state;
    }
}