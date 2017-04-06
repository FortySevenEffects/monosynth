#pragma once

#include "monosynth-core.h"
#include "monosynth-core_Defs.h"
#include "monosynth-core_PinMapping.h"
#include "monosynth-core_SpiDriver.h"
#include "monosynth-core_Renderer.h"
#include <MIDI.h>
#include <SimpleSynth/noteList.h>
#include <cake_Assert.h>

BEGIN_MONOSYNTH_CORE_NAMESPACE

class Engine
{
public:
    inline  Engine();
    inline ~Engine();

public:
    inline void setup();
    inline void process();

public: // Interrupt handlers
    enum
    {
        rx0 = 0,
        tx0,
        rx1,
        tx1,
        spi
    };

    template<int Interrupt>
    static inline void handleInterrupt();

public: // MIDI input callbacks
    static inline void handleNoteOn(byte inChannel, byte inNote, byte inVelocity);
    static inline void handleNoteOff(byte inChannel, byte inNote, byte inVelocity);
    static inline void handleControlChange(byte inChannel, byte inControl, byte inValue);
    static inline void handleProgramChange(byte inChannel, byte inProgram);

private:
    inline void initLowLevelDrivers();
    inline void initInterfaces();
    inline void initApplication();

private:
    static inline void printDebugChar(char inChar);

private:
    typedef midi::MidiInterface<MidiUart>   MidiInterface;
    typedef MidiNoteList<Defs::sNumLeds>    NoteBuffer;
    typedef LedFrameBuffer<Defs::sNumLeds>  FrameBuffer;

private: // Interfaces
    MidiUart    mMidiUart;
    DebugUart   mDebugUart;

private: // Models
    MidiInterface   mMidi;
    NoteBuffer      mNoteBuffer;
    FrameBuffer     mFrameBuffer;
};

extern Engine sEngine;

END_MONOSYNTH_CORE_NAMESPACE

#include "monosynth-core_Engine.hpp"
