#include "SerialSample.h"

#include <stdio.h>

void SerialSample_main()
{
    codal::STM32NUCLEO_F4x1RE NUCLEO_F4x1RE;

    printf("\n");
    printf("*******************************************\n");
    printf("* Demonstration de la communication serie *\n");
    printf("*******************************************\n");

    NUCLEO_F4x1RE.sleep(1000);

    while (true) {
        NUCLEO_F4x1RE.io.led.setDigitalValue(1);

        printf("\nVALUE = %d.%d degC\n", 0, 0);

        NUCLEO_F4x1RE.io.led.setDigitalValue(0);
        NUCLEO_F4x1RE.sleep(1000);
    }
}
