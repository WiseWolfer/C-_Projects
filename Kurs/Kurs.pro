QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    speaker_enclosure.cpp

HEADERS += \
    dialog.hpp \
    mainwindow.hpp \
    speaker_enclosure.hpp

FORMS += \
    dialog.ui \
    mainwindow.ui

TRANSLATIONS += translations/Kurs_en_US.ts \
                translations/Kurs_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    translations/Kurs_en_US.ts \
    translations/Kurs_ru_RU.ts \
    translations/Kurs_ru_RU.ts
