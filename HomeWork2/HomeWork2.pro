TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        loundspeaker_enclosure.cpp \
        main.cpp \
        speaker_enclosure_derived.cpp

HEADERS += \
    loundspeaker_enclosure.hpp \
    speaker_enclosure_derived.hpp
