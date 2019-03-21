#include<QVBoxLayout>

#include"cmykcolorkeypad.h"

CMYKColorKeyPad::CMYKColorKeyPad(QWidget* parent)
:ColorKeyPad(parent),cyan(new SliderSpinBox(0,100,"C",this)),magenta(new SliderSpinBox(0,100,"M",this))
,yellow(new SliderSpinBox(0,100,"Y",this)),keyBlack(new SliderSpinBox(0,100,"K",this)){

    QVBoxLayout* l=new QVBoxLayout;
    l->addWidget(cyan);
    l->addWidget(magenta);
    l->addWidget(yellow);
    l->addWidget(keyBlack);

    setLayout(l);

    connect(cyan,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
    connect(magenta,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
    connect(yellow,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
    connect(keyBlack,SIGNAL(valueChanged(int)),this,SLOT(_valueChanged()));
}

ColorCMYK* CMYKColorKeyPad::getColor(){
    return new ColorCMYK(cyan->getValue(),magenta->getValue(),yellow->getValue(),keyBlack->getValue());
}
void CMYKColorKeyPad::setColor(const Color& c){
    const ColorCMYK* q=dynamic_cast<const ColorCMYK*>(&c);
    if(q){
        cyan->setValue(q->getCyan());
        magenta->setValue(q->getMagenta());
        yellow->setValue(q->getYellow());
        keyBlack->setValue(q->getKeyBlack());
    }else{
        throw WrongColor();
    }
}

void CMYKColorKeyPad::reset(){
    setColor(ColorCMYK(0,0,0,0));
}

CMYKColorKeyPad::~CMYKColorKeyPad(){
    delete cyan;
    delete magenta;
    delete yellow;
    delete keyBlack;
}
