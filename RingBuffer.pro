TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    test_runner.h \
    profile.h \
    ringbufdeq.h \
    ringbufarr.h


QMAKE_CXXFLAGS += -O3
