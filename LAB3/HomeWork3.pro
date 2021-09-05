TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        checklist.cpp \
        loundspeaker_enclosure.cpp \
        main.cpp \
        menu.cpp \
        speaker_enclosure_derived.cpp

HEADERS += \
    checklist.h \
    loundspeaker_enclosure.hpp \
    menu.hpp \
    speaker_enclosure_derived.hpp
