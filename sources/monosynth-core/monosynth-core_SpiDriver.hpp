#pragma once

BEGIN_MONOSYNTH_CORE_NAMESPACE

template<int NumLeds>
SpiDriver<NumLeds>::SpiDriver(const FrameBuffer& inFrameBuffer)
    : mFrameBuffer(inFrameBuffer)
{
}

template<int NumLeds>
SpiDriver<NumLeds>::~SpiDriver()
{
}

// -----------------------------------------------------------------------------

template<int NumLeds>
void SpiDriver<NumLeds>::setup()
{
    // todo: setup SPI
    mIndex = 0;
}

template<int NumLeds>
void SpiDriver<NumLeds>::push()
{
    // todo: push start of frame
    // todo: push first LED and enable interrupt
    mIndex = 0;
    const LedColor& color = mFrameBuffer.getLedColor(mIndex++);
}

// -----------------------------------------------------------------------------

template<int NumLeds>
void SpiDriver<NumLeds>::sendStartOfFrame() const
{
    // send 0x00 0x00 0x00 0x00
}

template<int NumLeds>
void SpiDriver<NumLeds>::sendEndOfFrame() const
{
    static const int numBytes = (NumLeds >> 4) + 1;
    for (int i = 0; i < numBytes; ++i)
    {
        send(0xff);
    }
}

template<int NumLeds>
void SpiDriver<NumLeds>::send(byte inData)
{
    // todo: Implement me.
}

END_MONOSYNTH_CORE_NAMESPACE
