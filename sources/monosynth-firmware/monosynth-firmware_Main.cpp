#include "monosynth-firmware_Main.h"
// #include <test-core_Engine.h>
#include <io/cake_Gpio.h>
#include <time/cake_Timer.h>

BEGIN_MONOSYNTH_FIRMWARE_NAMESPACE

END_MONOSYNTH_FIRMWARE_NAMESPACE

typedef cake::Pin<cake::PortB, 0> LedPin;
typedef cake::Timer<0, 8> Timer;

// -----------------------------------------------------------------------------

int main()
{
    // test_core::sEngine.setup();
    LedPin::setOutput();
    Timer::enableInterruptOverflow();
    Timer::start();

    sei();

    for (;;)
    {
        // test_core::sEngine.process();
    }

    return 0;
}

ISR(TIMER0_OVF_vect)
{
    LedPin::toggle();
}
