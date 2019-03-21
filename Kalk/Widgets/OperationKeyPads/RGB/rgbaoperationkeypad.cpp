#include"rgbaoperationkeypad.h"
#include<QPushButton>

RGBAOperationKeyPad::RGBAOperationKeyPad(QWidget* parent)
:RGBOperationKeyPad(parent),pickOpacity(new QPushButton("pickOpacity",this)){
    connect(pickOpacity,SIGNAL(clicked()),this,SIGNAL(pickOpacityClicked()));

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    pickOpacity->setSizePolicy(sizePolicy);
    getColumn1()->addWidget(pickOpacity);
}

RGBAOperationKeyPad::~RGBAOperationKeyPad(){
    delete pickOpacity;
}
QPushButton* RGBAOperationKeyPad::getPickOpacity(){
    return pickOpacity;
}

