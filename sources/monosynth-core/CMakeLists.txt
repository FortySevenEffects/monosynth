target(monosynth-core)

target_sources(monosynth-core
    monosynth-core.cpp
    monosynth-core.h
    monosynth-core_Defs.h
    monosynth-core_Engine.cpp
    monosynth-core_Engine.hpp
    monosynth-core_Engine.h
    monosynth-core_SpiDriver.cpp
    monosynth-core_SpiDriver.hpp
    monosynth-core_SpiDriver.h
    monosynth-core_Renderer.cpp
    monosynth-core_Renderer.hpp
    monosynth-core_Renderer.h
    monosynth-core_PinMapping.h
)

target_deps(monosynth-core
    cake
    midi
)

build_static_library(monosynth-core)
