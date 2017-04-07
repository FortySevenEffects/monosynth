#pragma once

#include "monosynth-core.h"
#include "monosynth-core_Defs.h"
#include "monosynth-core_PinMapping.h"
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
        rx1 = 0,
        tx1,
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
    // static inline void printDebugChar(char inChar);

private:
    typedef midi::MidiInterface<MidiUart>       MidiInterface;
    typedef MidiNoteList<Defs::sNoteBufferSize> NoteBuffer;

private: // Interfaces
    MidiUart    mMidiUart;

private: // Models
    MidiInterface   mMidi;
    NoteBuffer      mNoteBuffer;
};

extern Engine sEngine;

END_MONOSYNTH_CORE_NAMESPACE

#include "monosynth-core_Engine.hpp"
