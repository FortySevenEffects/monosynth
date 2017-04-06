#pragma once

#include "monosynth-core.h"
#include "monosynth-core_Defs.h"
#include <memory/cake_RingBuffer.h>
#include <SimpleSynth/noteList.h>

BEGIN_MONOSYNTH_CORE_NAMESPACE

template<int NumLeds>
class Renderer
{
public:
    typedef LedFrameBuffer<NumLeds> FrameBuffer;
    typedef cake::RingBuffer<Defs::sMaxNoteListSize, MidiNote> DirtyBuffer;

public:
    static inline void render(FrameBuffer& inFrameBuffer,
                              DirtyBuffer& inDirtyBuffer);

private: // Helpers
    static inline LedFrame renderLedFrame(const LedColor& inColor);

    static inline byte getLedIndex(byte inMidiNote);
    static inline byte getIndexInOctave(byte inMidiNote);

private:
    static const LedColor sOctaveColors[12];
};

END_MONOSYNTH_CORE_NAMESPACE

#include "monosynth-core_Renderer.hpp"
