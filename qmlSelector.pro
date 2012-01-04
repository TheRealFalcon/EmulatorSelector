QT += xml declarative

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

RESOURCES += \
    resources.qrc

RC_FILE = qmlSelector.rc

install.path = install
install.files = settings.xml \
    libs/*
target.path = install
INSTALLS += target install
