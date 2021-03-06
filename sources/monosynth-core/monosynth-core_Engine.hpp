#pragma once

BEGIN_MONOSYNTH_CORE_NAMESPACE

inline Engine::Engine()
    : mMidi(mMidiUart)
{
}
inline Engine::~Engine()
{
}

// -----------------------------------------------------------------------------

inline void Engine::setup()
{
    initLowLevelDrivers();
    initInterfaces();
    initApplication();
    sei(); // Activate interrupts

    // AVR_DBG("Ready");
}

inline void Engine::process()
{
    mMidi.read();
}

// -----------------------------------------------------------------------------

inline void Engine::handleNoteOn(byte inChannel, byte inNote, byte inVelocity)
{
    const MidiNote note(inNote, inVelocity);
    sEngine.mNoteBuffer.add(note);
}

inline void Engine::handleNoteOff(byte inChannel, byte inNote, byte inVelocity)
{
    sEngine.mNoteBuffer.remove(inNote);
}

// -----------------------------------------------------------------------------

template<>
inline void Engine::handleInterrupt<Engine::rx1>()
{
    sEngine.mMidiUart.handleByteReceived(UDR1);
}

template<>
inline void Engine::handleInterrupt<Engine::tx1>()
{
    sEngine.mMidiUart.handleTxReady();
}

// -----------------------------------------------------------------------------

inline void Engine::initLowLevelDrivers()
{
    // mDebugUart.open<115200>();
    // cake::Debug::setPrintCallback(printDebugChar);
}

inline void Engine::initInterfaces()
{
    // MIDI
    mMidi.begin(MIDI_CHANNEL_OMNI);
    mMidi.turnThruOff();
}

inline void Engine::initApplication()
{

}

// -----------------------------------------------------------------------------

// inline void Engine::printDebugChar(char inChar)
// {
//     sEngine.mDebugUart.busyWrite(inChar);
// }

END_MONOSYNTH_CORE_NAMESPACE
