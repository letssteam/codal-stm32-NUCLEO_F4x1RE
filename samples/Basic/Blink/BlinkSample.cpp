#include "BlinkSample.h"

void BlinkSample_main(){
    codal::STM32NUCLEO_F411RE NUCLEO_F411RE;
	int state = 0;
	while(1)
    {    
		NUCLEO_F411RE.io.led1.setDigitalValue(state);
        NUCLEO_F411RE.io.led2.setDigitalValue(!state);
        NUCLEO_F411RE.sleep(1000);
        state = !state;
    }
}