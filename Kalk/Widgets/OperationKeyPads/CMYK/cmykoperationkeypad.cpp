#include<QPushButton>

#include"cmykoperationkeypad.h"

CMYKOperationKeyPad::CMYKOperationKeyPad(QWidget* parent)
:OperationKeyPad(parent),pickCyan(new QPushButton("pickCyan",this)),pickMagenta(new QPushButton("pickMagenta",this))
,pickYellow(new QPushButton("pickYellow",this)),pickKeyBlack(new QPushButton("pickKeyBlack",this))
,column1(new QVBoxLayout()),column2(new QVBoxLayout()),column3(new QVBoxLayout()){
    connect(pickCyan,SIGNAL(clicked()),this,SIGNAL(pickCyanClicked()));
    connect(pickMagenta,SIGNAL(clicked()),this,SIGNAL(pickMagentaClicked()));
    connect(pickYellow,SIGNAL(clicked()),this,SIGNAL(pickYellowClicked()));
    connect(pickKeyBlack,SIGNAL(clicked()),this,SIGNAL(pickKeyBlackClicked()));

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    getBlend()->setSizePolicy(sizePolicy);
    getComplementary()->setSizePolicy(sizePolicy);
    getSum()->setSizePolicy(sizePolicy);
    getSubstraction()->setSizePolicy(sizePolicy);
    getMoltiplication()->setSizePolicy(sizePolicy);
    getDivision()->setSizePolicy(sizePolicy);
    getEquals()->setSizePolicy(sizePolicy);
    pickCyan->setSizePolicy(sizePolicy);
    pickMagenta->setSizePolicy(sizePolicy);
    pickYellow->setSizePolicy(sizePolicy);
    pickKeyBlack->setSizePolicy(sizePolicy);

    QHBoxLayout* hl1=new QHBoxLayout;
    hl1->addWidget(getBlend());
    hl1->addWidget(getComplementary());
    column1->addLayout(hl1);
    column1->addWidget(pickCyan);
    column1->addWidget(pickMagenta);
    column1->addWidget(pickYellow);
    column1->addWidget(pickKeyBlack);


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

CMYKOperationKeyPad::~CMYKOperationKeyPad(){
    delete pickCyan;
    delete pickMagenta;
    delete pickYellow;
    delete pickKeyBlack;
}

QPushButton* CMYKOperationKeyPad::getPickCyan()const{
    return pickCyan;
}

QPushButton* CMYKOperationKeyPad::getPickMagenta()const{
    return pickMagenta;
}

QPushButton* CMYKOperationKeyPad::getPickYellow()const{
    return pickYellow;
}

QPushButton* CMYKOperationKeyPad::getPickKeyBlack()const{
    return pickKeyBlack;
}

QVBoxLayout* CMYKOperationKeyPad::getColumn1()const{
    return column1;
}
QVBoxLayout* CMYKOperationKeyPad::getColumn2()const{
    return column2;
}
QVBoxLayout* CMYKOperationKeyPad::getColumn3()const{
    return column3;
}
