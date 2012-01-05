QT += xml declarative
DESTDIR = bin
TARGET = romtastic

SOURCES += main.cpp \
    romModel.cpp \
    settings.cpp \
    romFilter.cpp \
    romRegex.cpp

HEADERS += \
    emulator.h \
    romModel.h \
    rom.h \
    settings.h \
    romFilter.h \
    romRegex.h

OBJECTS_DIR = obj
MOC_DIR = moc

RESOURCES += \
    resources.qrc

RC_FILE = qmlSelector.rc
win32:DEFINES += WIN32
unix:DEFINES += UNIX
QMAKE_CXXFLAGS = -Wall -Wextra -Werror

win32:install.path = install
win32:install.files = settings.xml \
    libs/*
win32:target.path = install
win32:INSTALLS += target install

unix:settings.path = ~/.romtastic
unix:settings.files = settings.xml
unix:target.path = /usr/bin
unix:INSTALLS += target settings


