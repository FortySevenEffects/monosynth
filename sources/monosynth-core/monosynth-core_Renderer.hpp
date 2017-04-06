#pragma once

BEGIN_MONOSYNTH_CORE_NAMESPACE

template<int NumLeds>
inline void Renderer<NumLeds>::render(FrameBuffer& inFrameBuffer,
                                      DirtyBuffer& inDirtyBuffer)
{
    inFrameBuffer.clear();
    while (!inDirtyBuffer.empty())
    {
        const MidiNote& note    = inDirtyBuffer.pop();
        const byte ledIndex     = getLedIndex(note.mPitch);
        const byte octaveIndex  = getIndexInOctave(note.mPitch);
        const LedColor& color   = sOctaveColors[octaveIndex];
        inFrameBuffer.mData[ledIndex] = renderLedFrame(color);
    }
}

// -----------------------------------------------------------------------------

template<int NumLeds>
inline LedFrame Renderer<NumLeds>::renderLedFrame(const LedColor& inColor)
{
    LedFrame frame = 0xff000000; // Full brightness to avoid flicker.
    frame |= LedFrame(inColor.mR) << 16;
    frame |= LedFrame(inColor.mG) << 8;
    frame |= inColor.mB;
    return frame;
}

template<int NumLeds>
inline byte Renderer<NumLeds>::getLedIndex(byte inMidiNote)
{
    return inMidiNote - Defs::sLowestMidiNoteNumber;
}

template<int NumLeds>
inline byte Renderer<NumLeds>::getIndexInOctave(byte inMidiNote)
{
    return (inMidiNote % 12); // 0 = C, 1 = C#, etc..
}

END_MONOSYNTH_CORE_NAMESPACE
