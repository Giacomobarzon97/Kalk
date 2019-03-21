#include"srgbacolorkeypad.h"

SRGBAColorKeyPad::SRGBAColorKeyPad(QWidget* parent)
:SRGBColorKeyPad(parent),opacity(new SliderSpinBox(0,100,"O",this)){
    getLayout()->addWidget(opacity);
    getLayout()->update();
    connect(opacity,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
}

SRGBAColorKeyPad::~SRGBAColorKeyPad(){
    delete opacity;
}
ColorSRGBA* SRGBAColorKeyPad::getColor(){
    return new ColorSRGBA(getRed()->getValue(),getGreen()->getValue(),getBlue()->getValue(),opacity->getValue());
}
void SRGBAColorKeyPad::setColor(const Color& c){
    const ColorSRGBA* q=dynamic_cast<const ColorSRGBA*>(&c);
    if(q){
        getRed()->setValue(q->getRed());
        getGreen()->setValue(q->getGreen());
        getBlue()->setValue(q->getBlue());
        opacity->setValue(q->getOpacity());
    }else{
        throw WrongColor();
    }
}
void SRGBAColorKeyPad::reset(){
    setColor(ColorSRGBA(0,0,0,0));
}
