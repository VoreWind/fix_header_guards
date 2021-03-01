CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    test_header_guards_fixer_test.cpp

HEADERS += \
    doctest.h

INCLUDEPATH += $$PWD/../library
LIBS += -L../library -llibrary

RESOURCES += \
    example_files.qrc
