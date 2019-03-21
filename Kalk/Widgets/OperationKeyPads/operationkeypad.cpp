#include<QPushButton>

#include"Widgets/OperationKeyPads/operationkeypad.h"

OperationKeyPad::OperationKeyPad(QWidget* parent)
:QWidget(parent),blend(new QPushButton("blend",this)),complementary(new QPushButton("comp",this))
,sum(new QPushButton("+",this)),substraction(new QPushButton("-",this)),moltiplication(new QPushButton("*",this))
,division(new QPushButton("/",this)),equals(new QPushButton("=",this))
,cancel(new QPushButton("C",this)),cancelEntry(new QPushButton("CE",this)){
    connect(blend,SIGNAL(clicked()),this,SIGNAL(blendClicked()));
    connect(complementary,SIGNAL(clicked()),this,SIGNAL(complementaryClicked()));
    connect(sum,SIGNAL(clicked()),this,SIGNAL(sumClicked()));
    connect(substraction,SIGNAL(clicked()),this,SIGNAL(substractionClicked()));
    connect(moltiplication,SIGNAL(clicked()),this,SIGNAL(moltiplicationClicked()));
    connect(division,SIGNAL(clicked()),this,SIGNAL(divisionClicked()));
    connect(equals,SIGNAL(clicked()),this,SIGNAL(equalsClicked()));
    connect(cancel,SIGNAL(clicked()),this,SIGNAL(cancelClicked()));
    connect(cancelEntry,SIGNAL(clicked()),this,SIGNAL(cancelEntryClicked()));
}

OperationKeyPad::~OperationKeyPad(){
    delete equals;
    delete division;
    delete moltiplication;
    delete substraction;
    delete sum;
    delete complementary;
    delete blend;
}

QPushButton* OperationKeyPad::getBlend()const{
    return blend;
}

QPushButton* OperationKeyPad::getComplementary()const{
    return complementary;
}

QPushButton* OperationKeyPad::getSum()const{
    return sum;
}

QPushButton* OperationKeyPad::getSubstraction()const{
    return substraction;
}

QPushButton* OperationKeyPad::getMoltiplication()const{
    return moltiplication;
}

QPushButton* OperationKeyPad::getDivision()const{
    return division;
}

QPushButton* OperationKeyPad::getEquals()const{
    return equals;
}
QPushButton* OperationKeyPad::getCancel()const{
    return cancel;
}
QPushButton* OperationKeyPad::getCancelEntry()const{
    return cancelEntry;
}
