#-------------------------------------------------
#
# Project created by QtCreator 2011-02-15T13:25:31
#
#-------------------------------------------------

QT       += core gui xml

TARGET = Selector
TEMPLATE = app
DESTDIR = bin
OBJECTS_DIR = generated/obj
MOC_DIR = generated/moc
UI_HEADERS_DIR = generated/uic
INCLUDEPATH = .
#CONFIG += console

SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/emulatorConfig.cpp \
    src/globalConfig.cpp \
    src/filterConfig.cpp \
    src/settings.cpp \
    src/emulatorModel.cpp \
    src/fileModel.cpp \
    src/test.cpp

HEADERS  += include/mainwindow.h \
    include/emulatorConfig.h \
    include/globalConfig.h \
    include/filterConfig.h \
    include/settings.h \
    src/emulatorModel.h \
    include/emulatorModel.h \
    include/fileModel.h \
    include/test.h

FORMS    += \
    forms/emulatorConfig.ui \
    forms/globalConfig.ui \
    forms/filterConfig.ui \
    forms/mainwindow.ui \
    forms/test.ui
