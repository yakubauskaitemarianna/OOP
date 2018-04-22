TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    baze_container.cpp \
    exceptions.cpp

HEADERS += \
    matrix.h \
    baze_container.h \
    cslspace.h \
    exceptions.h \
    matrix_imp.h \
    matrix_iterator.h \
    base_iterator.h \
    base_iterator_imp.h \
    const_matrix_iterator.h \
    const_matrix_iterator_imp.h \
    matrix_iterator_imp.h
