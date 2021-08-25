#include "BlinkSample.h"

void BlinkSample_main(codal::STM32NUCLEO_F4x1RE& nucleoBoard)
{
    bool state = false;
    while (true) {
        nucleoBoard.io.led.setDigitalValue((int)state);
        nucleoBoard.sleep(1000);
        state = !state;
    }
}
