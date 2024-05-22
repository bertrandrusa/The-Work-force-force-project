This is the Qt project file. It defines the project configuration and includes all necessary source files and libraries.

⁠ plaintext
# WorkforcePro.pro - Qt Project File

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WorkforcePro
TEMPLATE = app

SOURCES += \
    ../src/main.cpp \
    ../src/database.cpp \
    ../src/ui.cpp

HEADERS += \
    ../src/database.h \
    ../src/ui.h

INCLUDEPATH += ../include

LIBS += -L$$PWD/../lib -lsqlite3

FORMS += \
    mainwindow.ui
