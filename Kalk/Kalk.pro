#-------------------------------------------------
#
# Project created by QtCreator 2017-12-28T12:34:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kalk
TEMPLATE = app


SOURCES += main.cpp \
    Colors/color.cpp \
    Colors/RGBColors/colorrgb.cpp \
    Colors/RGBColors/colorscrgb.cpp \
    Colors/RGBColors/colorsrgb.cpp \
    Colors/RGBColors/colorsrgba.cpp \
    Colors/CMYKColors/colorcmyk.cpp \
    Widgets/OperationKeyPads/operationkeypad.cpp \
    Widgets/ColorKeyPads/colorkeypad.cpp \
    Widgets/OperationKeyPads/RGB/rgboperationkeypad.cpp \
    Widgets/sliderspinbox.cpp \
    Widgets/ColorKeyPads/RGB/srgbcolorkeypad.cpp \
    Widgets/ColorKeyPads/RGB/scrgbcolorkeypad.cpp \
    Widgets/calculatorgui.cpp \
    Widgets/ColorKeyPads/RGB/srgbacolorkeypad.cpp \
    Widgets/OperationKeyPads/RGB/rgbaoperationkeypad.cpp \
    Widgets/OperationKeyPads/CMYK/cmykoperationkeypad.cpp \
    Widgets/ColorKeyPads/CMYK/cmykcolorkeypad.cpp \
    model.cpp \
    controller.cpp \
    Widgets/Displays/screen.cpp

HEADERS  += \
    Colors/color.h \
    Colors/RGBColors/colorrgb.h \
    Colors/RGBColors/colorsrgb.h \
    Colors/RGBColors/colorsrgba.h \
    Colors/RGBColors/colorscrgb.h \
    Colors/CMYKColors/colorcmyk.h \
    Widgets/calculatorgui.h \
    Widgets/ColorKeyPads/colorkeypad.h \
    Widgets/OperationKeyPads/operationkeypad.h \
    Widgets/OperationKeyPads/RGB/rgboperationkeypad.h \
    Widgets/sliderspinbox.h \
    Widgets/ColorKeyPads/RGB/srgbcolorkeypad.h \
    Widgets/ColorKeyPads/RGB/scrgbcolorkeypad.h \
    Widgets/ColorKeyPads/RGB/srgbacolorkeypad.h \
    Widgets/OperationKeyPads/RGB/rgbaoperationkeypad.h \
    Widgets/OperationKeyPads/CMYK/cmykoperationkeypad.h \
    Widgets/ColorKeyPads/CMYK/cmykcolorkeypad.h \
    controller.h \
    model.h \
    Widgets/Displays/screen.h

FORMS    +=
