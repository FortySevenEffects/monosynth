#pragma once

#include "monosynth-core.h"
#include "monosynth-core_Defs.h"

BEGIN_MONOSYNTH_CORE_NAMESPACE

template<int NumLeds>
class SpiDriver
{
public:
    typedef LedFrameBuffer<NumLeds> FrameBuffer;

public:
    inline  SpiDriver(const FrameBuffer& inFrameBuffer);
    inline ~SpiDriver();

public:
    inline void setup();
    inline void push();

private:
    inline void sendStartOfFrame() const;
    inline void sendEndOfFrame() const;
    inline void send(byte inData);

private:
    const FrameBuffer& mFrameBuffer;
    byte mIndex;

private:
    AVR_NON_COPYABLE(SpiDriver);
};

END_MONOSYNTH_CORE_NAMESPACE

#include "monosynth-core_SpiDriver.hpp"
