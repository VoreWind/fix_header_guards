QT += core
QT -= gui

CONFIG += c++17

TARGET = fix_header_guards
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++17

SOURCES += main.cpp \
    comment_in_file_start_finder.cpp \
    header_guard_fixer_test.cpp \
    header_file_cleaner.cpp \
    header_guard_fixer.cpp \
    header_guard_maker.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    comment_in_file_start_finder.h \
    doctest.h \
    header_file_cleaner.h \
    header_guard_fixer.h \
    header_guard_maker.h
