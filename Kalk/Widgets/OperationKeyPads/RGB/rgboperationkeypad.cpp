#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>

#include"rgboperationkeypad.h"

RGBOperationKeyPad::RGBOperationKeyPad(QWidget* parent)
:OperationKeyPad(parent),pickRed(new QPushButton("pickRed",this)),pickGreen(new QPushButton("pickGreen",this))
,pickBlue(new QPushButton("pickBlue",this)),column1(new QVBoxLayout),column2(new QVBoxLayout),column3(new QVBoxLayout){

    connect(pickRed,SIGNAL(clicked()),this,SIGNAL(pickRedClicked()));
    connect(pickGreen,SIGNAL(clicked()),this,SIGNAL(pickGreenClicked()));
    connect(pickBlue,SIGNAL(clicked()),this,SIGNAL(pickBlueClicked()));

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    getBlend()->setSizePolicy(sizePolicy);
    getComplementary()->setSizePolicy(sizePolicy);
    getSum()->setSizePolicy(sizePolicy);
    getSubstraction()->setSizePolicy(sizePolicy);
    getMoltiplication()->setSizePolicy(sizePolicy);
    getDivision()->setSizePolicy(sizePolicy);
    getEquals()->setSizePolicy(sizePolicy);
    pickRed->setSizePolicy(sizePolicy);
    pickGreen->setSizePolicy(sizePolicy);
    pickBlue->setSizePolicy(sizePolicy);


    QHBoxLayout* hl1=new QHBoxLayout;
    hl1->addWidget(getBlend());
    hl1->addWidget(getComplementary());
    column1->addLayout(hl1);
    column1->addWidget(pickRed);
    column1->addWidget(pickGreen);
    column1->addWidget(pickBlue);

    column2->addWidget(getDivision());
    column2->addWidget(getMoltiplication());
    column2->addWidget(getSubstraction());
    column2->addWidget(getSum());

    QHBoxLayout* hl2=new QHBoxLayout;
    hl2->addWidget(getCancel());
    hl2->addWidget(getCancelEntry());

    column3->addLayout(hl2);
    column3->addWidget(getEquals());

    QHBoxLayout* hl3=new QHBoxLayout;
    hl3->addLayout(column1);
    hl3->addLayout(column2);
    hl3->addLayout(column3);
    setLayout(hl3);
}

RGBOperationKeyPad::~RGBOperationKeyPad(){
    delete pickBlue;
    delete pickGreen;
    delete pickRed;
}
QPushButton* RGBOperationKeyPad::getPickRed()const{
    return pickRed;
}
QPushButton* RGBOperationKeyPad::getPickGreen()const{
    return pickGreen;
}
QPushButton* RGBOperationKeyPad::getPickBlue()const{
    return pickBlue;
}
QVBoxLayout* RGBOperationKeyPad::getColumn1()const{
    return column1;
}

QVBoxLayout* RGBOperationKeyPad::getColumn2()const{
    return column2;
}

QVBoxLayout* RGBOperationKeyPad::getColumn3()const{
    return column3;
}

