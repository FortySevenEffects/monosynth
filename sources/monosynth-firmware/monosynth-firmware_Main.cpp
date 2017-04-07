#include "monosynth-firmware_Main.h"
#include <monosynth-core_Engine.h>

BEGIN_MONOSYNTH_FIRMWARE_NAMESPACE

END_MONOSYNTH_FIRMWARE_NAMESPACE

// -----------------------------------------------------------------------------

int main()
{
    monosynth_core::sEngine.setup();

    for (;;)
    {
        monosynth_core::sEngine.process();
    }

    return 0;
}
