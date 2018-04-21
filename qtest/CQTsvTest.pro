TEMPLATE = app

QT += widgets

TARGET = CQTsvTest

DEPENDPATH += .

MOC_DIR = .moc

QMAKE_CXXFLAGS += -std=c++14

CONFIG += debug

SOURCES += \
CQTsvTest.cpp \

HEADERS += \
CQTsvTest.h \

DESTDIR     = ../bin
OBJECTS_DIR = ../obj
LIB_DIR     = ../lib

PRE_TARGETDEPS = \
$(LIB_DIR)/libCQTsv.a \

INCLUDEPATH = \
. \
../include \
../qinclude \

unix:LIBS += \
-L$$LIB_DIR \
-L../../CQTsv/lib \
\
-lCQTsv \
