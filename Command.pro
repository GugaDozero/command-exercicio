TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    appendtextcommand.cpp \
    commandstack.cpp \
    uppercasecommand.cpp

HEADERS += \
    icommand.h \
    appendtextcommand.h \
    commandstack.h \
    uppercasecommand.h

