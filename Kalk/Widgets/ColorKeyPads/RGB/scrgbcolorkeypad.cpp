#include<QVBoxLayout>

#include"scrgbcolorkeypad.h"

SCRGBColorKeyPad::SCRGBColorKeyPad(QWidget* parent)
:ColorKeyPad(parent),red(new SliderSpinBox(-255,255,"R",this)),green(new SliderSpinBox(-255,255,"G",this))
,blue(new SliderSpinBox(-255,255,"B",this)){

    QVBoxLayout* l=new QVBoxLayout;
    l->addWidget(red);
    l->addWidget(green);
    l->addWidget(blue);

    setLayout(l);

    connect(red,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
    connect(green,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
    connect(blue,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));

}
ColorSCRGB* SCRGBColorKeyPad::getColor(){
    return new ColorSCRGB(red->getValue(),green->getValue(),blue->getValue());
}
void SCRGBColorKeyPad::setColor(const Color& c){
    const ColorSCRGB* q=dynamic_cast<const ColorSCRGB*>(&c);
    if(q){
        red->setValue(q->getRed());
        green->setValue(q->getGreen());
        blue->setValue(q->getBlue());
    }else{
        throw WrongColor();
    }
}
void SCRGBColorKeyPad::reset(){
    setColor(ColorSCRGB(0,0,0));
}
SCRGBColorKeyPad::~SCRGBColorKeyPad(){
    delete red;
    delete green;
    delete blue;
}
