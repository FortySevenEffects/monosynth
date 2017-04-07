target(monosynth-core)

target_sources(monosynth-core
    monosynth-core.cpp
    monosynth-core.h
    monosynth-core_Defs.h
    monosynth-core_Engine.cpp
    monosynth-core_Engine.hpp
    monosynth-core_Engine.h
    monosynth-core_PinMapping.h
)

target_deps(monosynth-core
    cake
    midi
    pco-interfaces
)

build_static_library(monosynth-core)
