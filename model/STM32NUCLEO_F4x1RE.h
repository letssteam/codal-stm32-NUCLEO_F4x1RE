#ifndef STM32NUCLEO_F4x1RE_H
#define STM32NUCLEO_F4x1RE_H

#include "Button.h"
#include "CodalComponent.h"
#include "CodalDevice.h"
#include "CodalDmesg.h"
#include "CodalFiber.h"
#include "Event.h"
#include "MessageBus.h"
#include "NotifyEvents.h"
#include "STM32LowLevelTimer.h"
#include "STM32NUCLEO_F4x1REIO.h"
#include "Timer.h"

// Status flag values
#define DEVICE_INITIALIZED 0x01

/**
 * Class definition for a STM32 IOT node.
 *
 * Represents the device as a whole, and includes member variables that represent various device drivers
 * used to control aspects of the STM32 IOT node.
 */
namespace codal {
class STM32NUCLEO_F4x1RE : public CodalComponent {
  public:
    STM32LowLevelTimer lowLevelTimer;
    Timer timer;
    MessageBus messageBus;

    STM32NUCLEO_F4x1REIO io;

    // Button buttonUSER;

    /**
     * Constructor.
     */
    STM32NUCLEO_F4x1RE();

    /**
     * Post constructor initialisation method.
     */
    int init() override final;

    /**
     * Delay execution for the given amount of time.
     *
     * If the scheduler is running, this will deschedule the current fiber and perform
     * a power efficient, concurrent sleep operation.
     *
     * If the scheduler is disabled or we're running in an interrupt context, this
     * will revert to a busy wait.
     *
     * Alternatively: wait, wait_ms, wait_us can be used which will perform a blocking sleep
     * operation.
     *
     * @param milliseconds the amount of time, in ms, to wait for. This number cannot be negative.
     *
     */
    virtual void sleep(uint32_t milliseconds) { fiber_sleep(milliseconds); }

    /**
     * A periodic callback invoked by the fiber scheduler idle thread.
     * We use this for any low priority, background housekeeping.
     */
    virtual void idleCallback() { codal_dmesg_flush(); }

    /**
     * A periodic callback invoked by the fiber scheduler every SCHEDULER_TICK_PERIOD_MS.
     */
    virtual void periodicCallback() {}

    /**
     * Determine the time since this board was last reset.
     *
     * @return The time since the last reset, in milliseconds.
     *
     * @note This will value overflow after 1.6 months.
     */
    CODAL_TIMESTAMP systemTime() { return system_timer_current_time(); }
};

extern STM32NUCLEO_F4x1RE* default_device_instance;
}  // namespace codal
#endif
