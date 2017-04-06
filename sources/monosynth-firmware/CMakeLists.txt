target(monosynth-firmware)

target_sources(monosynth-firmware
    monosynth-firmware_Main.cpp
    monosynth-firmware_Main.h
)

target_deps(monosynth-firmware
    monosynth-core
)

build_avr_firmware(monosynth-firmware)
