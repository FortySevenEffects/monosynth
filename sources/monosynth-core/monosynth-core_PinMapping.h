#pragma once

#include "monosynth-core.h"
#include <io/cake_Gpio.h>
#include <io/cake_HardwareSerial.h>
#include <io/cake_Spi.h>

BEGIN_MONOSYNTH_CORE_NAMESPACE

#if !defined(__AVR_ATmega644P__)
#   error This code is not compatible with the current MCU.
#endif

/* Configuration for ATmega644P-20AU on Mobius Modular Motherboard

Pin Function        Port    Special         MMM Location
---------------------------------------------------------
 1  SPI MOSI        (B5)    Not swappable   ICSP MOSI
 2  SPI MISO        (B6)    Not swappable   ICSP MISO
 3  SPI SCK         (B7)    Not swappable   ICSP SCK
 4  N.A.            Reset   Not swappable   ICSP Reset
 5  N.A.            VCC     Not swappable
 6  N.A.            GND     Not swappable
 7  N.A.            XTAL2   Not swappable
 8  N.A.            XTAL1   Not swappable
 9  Debug RX        RX0     Not swappable   Debug In
10  Debug TX        TX0     Not swappable   Debug Out
11  MIDI RX         RX1     Not swappable   MIDI In         (no breakout)
12  MIDI TX         TX1     Not swappable   MIDI Out        (no breakout)
13  free            (D4)    OC1B            Debounce A
14  free            (D5)    OC1A                            (no breakout)
15  free            (D6)    OC2B            Mute
16  free            (D7)    OC2A            LCD Backlight   (no breakout)
17  N.A.            VCC     Not swappable
18  N.A.            GND     Not swappable
19  free            (C0)    I2C SCL         I2C             (no breakout)
20  free            (C1)    I2C SDA         I2C             (no breakout)
21  Select MCO 1    (C2)    JTAG TCK        Relay A
22  Select MCO 2    (C3)    JTAG TMS        Relay B
23  Mux A           (C4)    JTAG TDO        Relay C
24  Mux B           (C5)    JTAG TDI        Relay D
25  Mux C           (C6)                    Relay E
26  HC595 Clk       (C7)                    Relay F
27  N.A.            AVCC    Not swappable
28  N.A.            GND     Not swappable
29  N.A.            AREF    Not swappable
30  HC595 Data      (A7)    ADC             Relay I
31  HC595 Latch     (A6)    ADC             Relay H
32  Mux ADC         (A5)    ADC             Relay G
33  free            (A4)    ADC             Slide
34  free            (A3)    ADC             LED A
35  free            (A2)    ADC             LED B
36  free            (A1)    ADC             LED C
37  Gate Out        (A0)    ADC             LED D
38  N.A.            VCC     Not swappable
39  N.A.            GND     Not swappable
40  free            (B0)                    Debounce B      (no breakout)
41  free            (B1)                    Debounce D      (no breakout)
42  free            (B2)    INT2            Debounce Up     (no breakout)
43  free            (B3)    OC0A            Debounce Down   (no breakout)
44  SPI SS          (B4)    OC0B            Debounce C      (no breakout)
---------------------------------------------------------
Pin Function        Port    Special         MMM Location
 */

// Debugging -------------------------------------------------------------------

typedef cake::Pin<cake::PortA, 3>           TraceA;
typedef cake::Pin<cake::PortA, 2>           TraceB;
typedef cake::Pin<cake::PortA, 1>           TraceC;
typedef cake::Pin<cake::PortA, 0>           TraceD;

// Pins ------------------------------------------------------------------------

struct SpiTraits
{
    typedef cake::Pin<cake::PortB, 4>       SystemSsPin;
    typedef cake::Pin<cake::PortB, 5>       MosiPin;
    typedef cake::Pin<cake::PortB, 6>       MisoPin;
    typedef cake::Pin<cake::PortB, 7>       SckPin;
};

// Serial Interfaces -----------------------------------------------------------

typedef cake::Uart0             DebugUart;
typedef cake::Uart1             MidiUart;
typedef cake::SpiMaster<8>      Spi;

END_MONOSYNTH_CORE_NAMESPACE
