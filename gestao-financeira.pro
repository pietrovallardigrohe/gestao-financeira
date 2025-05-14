TEMPLATE = app
TARGET = gestao-financeira

QT += core gui widgets

SOURCES += src/main.cpp \
           src/ui/MainWindow.cpp

HEADERS += src/ui/MainWindow.h

FORMS += src/ui/MainWindow.ui

# Generated files directories
UI_DIR = src/ui

# Configuration section
CONFIG += console
