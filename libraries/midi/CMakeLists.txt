target(midi)

target_sources(midi
    arduino-midi-library/src/midi_Namespace.h
    arduino-midi-library/src/midi_Defs.h
    arduino-midi-library/src/midi_Message.h
    arduino-midi-library/src/midi_Settings.h
    arduino-midi-library/src/MIDI.cpp
    arduino-midi-library/src/MIDI.hpp
    arduino-midi-library/src/MIDI.h

    # Extras
    arduino-midi-library/examples/SimpleSynth/noteList.cpp
    arduino-midi-library/examples/SimpleSynth/noteList.h
)

target_include_dirs(midi
	${CMAKE_CURRENT_SOURCE_DIR}/arduino-midi-library/src
    ${CMAKE_CURRENT_SOURCE_DIR}/arduino-midi-library/examples
)

build_static_library(midi)
