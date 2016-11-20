QT += core
QT -= gui

CONFIG += c++11

TARGET = regex_search3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

LIBS += -L/usr/local/boost_1_62_0/stage/lib -lboost_regex

SOURCES += main.cpp
