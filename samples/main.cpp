#include "STM32NUCLEO_F4x1RE.h"

#if defined(GPIO_SAMPLE)
#include "GPIOSample.h"
#elif defined(ADC_SAMPLE)
#include "ADCSample.h"
#elif defined(SERIAL_SAMPLE)
#include "SerialSample.h"
#elif defined(TIMER_SAMPLE)
#include "TimerSample.h"
#elif defined(HADWARE_TIMER_SAMPLE)
#include "HardwareTimerSample.h"
#else
#include "BlinkSample.h"
#endif

codal::STM32NUCLEO_F4x1RE nucleoBoard;

auto main() -> int
{
    nucleoBoard.init();
    SAMPLE_MAIN(nucleoBoard);
    codal::release_fiber();
    return 0;
}
