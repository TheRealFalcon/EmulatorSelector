install.path = install
install.files = qml/qmlSelector/settings.xml \
    libs/*
target.path = install
INSTALLS += target install

QT += xml

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

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()



















