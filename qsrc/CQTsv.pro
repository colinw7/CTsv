TEMPLATE = lib

TARGET = CQTsv

DEPENDPATH += .

QT += widgets

CONFIG += staticlib

QMAKE_CXXFLAGS += -std=c++14

MOC_DIR = .moc

SOURCES += \
CQTsvModel.cpp \
CQTsvTable.cpp \

HEADERS += \
../qinclude/CQTsvModel.h \
../qinclude/CQTsvTable.h \

OBJECTS_DIR = ../obj

DESTDIR = ../lib

INCLUDEPATH += \
../qinclude \
../include \
../../CQBaseModel/include \
../../CQUtil/include \
