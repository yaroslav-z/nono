QT += core
QT -= gui

CONFIG += c++11

INCLUDEPATH += $$(GOOGLETEST)/include
INCLUDEPATH += $$(GOOGLETEST)/include
INCLUDEPATH += ../japan_puzzle

TARGET = japan_puzzle_tests
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += $$(GOOGLETEST)/src/gtest_main.cc \
    tests/helper_tests.cpp \
    tests/standart_japan_condition_test.cpp \
    tests/standart_nono_test.cpp \
    ../japan_puzzle/puzzle_helper.cpp \
    ../japan_puzzle/simple_row_column_logic_solver_rectangular.cpp \
    ../japan_puzzle/simple_solver_rectangular_puzzle.cpp \
    ../japan_puzzle/standart_japan_puzzle.cpp \
    ../japan_puzzle/standart_japan_puzzle_condition_line_condition.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$(GOOGLETESTLIB) -lgtest
else:win32:CONFIG(debug, debug|release): LIBS += -L$$(GOOGLETESTLIB) -lgtest
else:unix: LIBS += -L$$(GOOGLETESTLIB) -lgtest

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
    ../japan_puzzle/puzzle_conditions.h \
    ../japan_puzzle/puzzle_helper.h \
    ../japan_puzzle/simple_row_column_logic_solver.h \
    ../japan_puzzle/simple_row_column_logic_solver_rectangular.h \
    ../japan_puzzle/simple_solution_generator.h \
    ../japan_puzzle/simple_solver_rectangular_puzzle.h \
    ../japan_puzzle/standart_japan_puzzle.h \
    ../japan_puzzle/standart_japan_puzzle_line_condition.h

