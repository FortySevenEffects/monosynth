#include "monosynth-core_Engine.h"

BEGIN_MONOSYNTH_CORE_NAMESPACE

Engine sEngine;

END_MONOSYNTH_CORE_NAMESPACE

// -----------------------------------------------------------------------------

USING_MONOSYNTH_CORE_NAMESPACE;

ISR(USART1_RX_vect)
{
    Engine::handleInterrupt<Engine::rx1>();
}

ISR(USART1_UDRE_vect)
{
    Engine::handleInterrupt<Engine::tx1>();
}
