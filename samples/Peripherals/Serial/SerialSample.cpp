#include "SerialSample.h"

void SerialSample_main(){
    codal::STM32NUCLEO_F411RE NUCLEO_F411RE;
    
    printf("\n");
    printf("*******************************************\n");
    printf("* Demonstration de la communication serie *\n");
    printf("*******************************************\n");
    
    NUCLEO_F411RE.sleep(1000);
    
    while(1) {
        NUCLEO_F411RE.io.led1.setDigitalValue(1);

        printf("\nVALUE = %d.%d degC\n", 0, 0);

        NUCLEO_F411RE.io.led1.setDigitalValue(0);
        NUCLEO_F411RE.sleep(1000);
    }
}