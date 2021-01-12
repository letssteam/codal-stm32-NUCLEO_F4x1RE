#include "Sensor.h"
#include "GPIOSample.h"

using namespace codal;

void onSampleEvent(Event e){
    int value = default_device_instance->io.A3.getAnalogValue();
    default_device_instance->io.D5.setAnalogValue(value);
    printf("A3 = %d\n", value);
}


void GPIOSample_main(){
    codal::STM32NUCLEO_F411RE NUCLEO_F411RE;
    printf("\n");
    printf("*******************************************\n");
    printf("*           Demonstration de I/O          *\n");
    printf("*******************************************\n");
    //NUCLEO_F411RE.io.A1.setAnalogValue(512);
    NUCLEO_F411RE.sleep(1000);
    system_timer_event_every(1000, ID_PIN_P0, SENSOR_UPDATE_NEEDED);
    EventModel::defaultEventBus->listen(ID_PIN_P0, SENSOR_UPDATE_NEEDED, onSampleEvent);

    while(1) {
        NUCLEO_F411RE.io.led1.setDigitalValue(1);
        NUCLEO_F411RE.sleep(1000);

        NUCLEO_F411RE.io.led1.setDigitalValue(0);
        NUCLEO_F411RE.sleep(1000);
    }
}