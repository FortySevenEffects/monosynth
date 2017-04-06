#pragma once

#include "monosynth-core.h"
#include <cake.h>
#include <string.h>

BEGIN_MONOSYNTH_CORE_NAMESPACE

struct Defs
{
    static const int sNumLeds               = 88;
    static const int sLowestMidiNoteNumber  = 21;
    static const int sMaxNoteListSize       = 16;
};

struct LedColor
{
    uint8 mR;
    uint8 mG;
    uint8 mB;

    inline LedColor()
        : mR(0x00)
        , mG(0x00)
        , mB(0x00)
    {
    }
    inline LedColor(uint8 inRed, uint8 inGreen, uint8 inBlue)
        : mR(inRed)
        , mG(inGreen)
        , mB(inBlue)
    {
    }
    inline LedColor& operator=(const LedColor& inOther)
    {
        mR = inOther.mR;
        mG = inOther.mG;
        mB = inOther.mB;
        return *this;
    }
};

struct MidiNote
{
    byte mPitch;
    byte mVelocity;
    byte mChannel;
};

typedef uint32 LedFrame;

template<int NumLeds>
struct LedFrameBuffer
{
    LedFrame mData[NumLeds];

    inline void clear()
    {
        memset(mData, 0, NumLeds * sizeof(LedFrame));
    }
};

END_MONOSYNTH_CORE_NAMESPACE
