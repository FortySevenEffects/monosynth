#pragma once

#include "monosynth-core.h"
#include <io/cake_Gpio.h>
#include <io/cake_HardwareSerial.h>
#include <io/cake_Spi.h>

BEGIN_MONOSYNTH_CORE_NAMESPACE

#if !defined(__AVR_ATmega32U4__)
#   error This code is not compatible with the current MCU.
#endif

// Debugging -------------------------------------------------------------------

// typedef cake::Pin<cake::PortA, 3>           TraceA;
// typedef cake::Pin<cake::PortA, 2>           TraceB;
// typedef cake::Pin<cake::PortA, 1>           TraceC;
// typedef cake::Pin<cake::PortA, 0>           TraceD;

// Pins ------------------------------------------------------------------------



// Serial Interfaces -----------------------------------------------------------

typedef cake::Uart1 MidiUart;

END_MONOSYNTH_CORE_NAMESPACE
