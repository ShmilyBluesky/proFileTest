#-------------------------------------------------
#
# Project created by QtCreator 2019-10-11T13:36:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proFileTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

if (contains(DEFINES,PLATFORM_ARM_ZLG)){
DEFINES += GLOBALDEFINE_PLATFORM_ARM_ZLG
}
if (contains(DEFINES,PLATFORM_ARM_TOPEET)){
DEFINES += GLOBALDEFINE_PLATFORM_ARM_TOPEET
}
if (contains(DEFINES,PLATFORM_WIN_MINGW)){
DEFINES += GLOBALDEFINE_PLATFORM_WIN_MINGW
}
if (contains(DEFINES,PLATFORM_WIN_VS)){
DEFINES += GLOBALDEFINE_PLATFORM_WIN_VS
}


win32{
# mingw
*mingw*{
DEFINES += CustomWinMingw
}
# vs
else{
DEFINES += CustomWinVS
}
}


unix{
# ARM
*arm*{
DEFINES += CustomLinuxArm
}
# x86_64
else{
DEFINES += CustomLinuxX86_64
}
}


# debug or release
CONFIG(debug, debug|release){
# 在DEBUG 版本后加入 d后缀
TARGET = $$join(TARGET,,,d)
message("debug")
}
CONFIG(release, debug|release){
message("release")
}


# bits
contains(QT_ARCH, i386) {
message("32-bit")
} else {
message("64-bit")
}


SOURCES += \
        main.cpp \
        mainwidget.cpp

HEADERS += \
        mainwidget.h

FORMS += \
        mainwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
