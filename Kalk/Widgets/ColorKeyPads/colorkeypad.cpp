#include"Widgets/ColorKeyPads/colorkeypad.h"

ColorKeyPad::ColorKeyPad(QWidget* parent):QWidget(parent){}
ColorKeyPad::~ColorKeyPad(){}
void ColorKeyPad::_valueChanged(){
    Color* aux=getColor();
    emit valueChanged(*aux);
    delete aux;
}
