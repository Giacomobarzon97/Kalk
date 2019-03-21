#include<QVBoxLayout>

#include"srgbcolorkeypad.h"

SRGBColorKeyPad::SRGBColorKeyPad(QWidget* parent)
:ColorKeyPad(parent),red(new SliderSpinBox(0,255,"R",this)),green(new SliderSpinBox(0,255,"G",this))
,blue(new SliderSpinBox(0,255,"B",this)){

    layout=new QVBoxLayout;
    layout->addWidget(red);
    layout->addWidget(green);
    layout->addWidget(blue);

    setLayout(layout);

    connect(red,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
    connect(green,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
    connect(blue,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
}

SRGBColorKeyPad::~SRGBColorKeyPad(){
    delete red;
    delete green;
    delete blue;
}
QVBoxLayout* SRGBColorKeyPad::getLayout()const{
    return layout;
}
ColorSRGB* SRGBColorKeyPad::getColor(){
    return new ColorSRGB(red->getValue(),green->getValue(),blue->getValue());
}
void SRGBColorKeyPad::setColor(const Color& c){
    const ColorSRGB* q=dynamic_cast<const ColorSRGB*>(&c);
    if(q){
        red->setValue(q->getRed());
        green->setValue(q->getGreen());
        blue->setValue(q->getBlue());
    }else{
        throw WrongColor();
    }
}
void SRGBColorKeyPad::reset(){
    setColor(ColorSRGB(0,0,0));
}

SliderSpinBox* SRGBColorKeyPad::getRed()const{
    return red;
}
SliderSpinBox* SRGBColorKeyPad::getGreen()const{
    return green;
}
SliderSpinBox* SRGBColorKeyPad::getBlue()const{
    return blue;
}
