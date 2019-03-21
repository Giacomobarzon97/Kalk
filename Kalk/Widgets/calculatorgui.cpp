#include<QVBoxLayout>
#include<QMessageBox>
#include <sstream>

#include"calculatorgui.h"
#include"ColorKeyPads/RGB/srgbcolorkeypad.h"
#include"ColorKeyPads/RGB/srgbacolorkeypad.h"
#include"ColorKeyPads/RGB/scrgbcolorkeypad.h"
#include"ColorKeyPads/CMYK/cmykcolorkeypad.h"
#include"OperationKeyPads/RGB/rgboperationkeypad.h"
#include"OperationKeyPads/RGB/rgbaoperationkeypad.h"
#include"OperationKeyPads/CMYK/cmykoperationkeypad.h"

CalculatorGUI::CalculatorGUI(QWidget* parent)
:QWidget(parent),display(new Screen(this)),comboBox(new QComboBox(this))
,colorKeyPad(new SRGBColorKeyPad(this)),operationKeyPad(new RGBOperationKeyPad(this))
,layout(new QVBoxLayout(this)){
    comboBox->addItem("SRGB","SRGB");
    comboBox->addItem("SRGBA","SRGBA");
    comboBox->addItem("SCRGB","SCRGB");
    comboBox->addItem("CMYK","CMYK");

    layout->addWidget(display);
    layout->addWidget(comboBox);
    layout->addWidget(colorKeyPad);
    layout->addWidget(operationKeyPad);
    setLayout(layout);

    connect(comboBox,SIGNAL(currentIndexChanged(const QString&)),this,SLOT(changeKeyPads(const QString&)));
    keyPadsInitialization();

    RGBOperationKeyPad* q=dynamic_cast<RGBOperationKeyPad*>(operationKeyPad);
    connect(q,SIGNAL(pickRedClicked()),this,SLOT(_pickRedClicked()));
    connect(q,SIGNAL(pickGreenClicked()),this,SLOT(_pickGreenClicked()));
    connect(q,SIGNAL(pickBlueClicked()),this,SLOT(_pickBlueClicked()));

    setFixedSize(geometry().height(),geometry().width());
}

CalculatorGUI::~CalculatorGUI(){
    delete display;
    delete operationKeyPad;
    delete colorKeyPad;
    delete comboBox;
}

void CalculatorGUI::changeKeyPads(const QString& s){
    layout->removeWidget(colorKeyPad);
    colorKeyPad->close();
    delete colorKeyPad;
    layout->removeWidget(operationKeyPad);
    operationKeyPad->close();
    delete operationKeyPad;
    if(s=="SRGB"){
        colorKeyPad=new SRGBColorKeyPad(this);
        operationKeyPad=new RGBOperationKeyPad(this);
        RGBOperationKeyPad* q=dynamic_cast<RGBOperationKeyPad*>(operationKeyPad);
        connect(q,SIGNAL(pickRedClicked()),this,SLOT(_pickRedClicked()));
        connect(q,SIGNAL(pickGreenClicked()),this,SLOT(_pickGreenClicked()));
        connect(q,SIGNAL(pickBlueClicked()),this,SLOT(_pickBlueClicked()));
    }
    if(s=="SCRGB"){
        colorKeyPad=new SCRGBColorKeyPad(this);
        operationKeyPad=new RGBOperationKeyPad(this);
        RGBOperationKeyPad* q=dynamic_cast<RGBOperationKeyPad*>(operationKeyPad);
        connect(q,SIGNAL(pickRedClicked()),this,SLOT(_pickRedClicked()));
        connect(q,SIGNAL(pickGreenClicked()),this,SLOT(_pickGreenClicked()));
        connect(q,SIGNAL(pickBlueClicked()),this,SLOT(_pickBlueClicked()));
    }
    if(s=="SRGBA"){
        colorKeyPad=new SRGBAColorKeyPad(this);
        operationKeyPad=new RGBAOperationKeyPad(this);
        RGBOperationKeyPad* q=dynamic_cast<RGBAOperationKeyPad*>(operationKeyPad);
        connect(q,SIGNAL(pickRedClicked()),this,SLOT(_pickRedClicked()));
        connect(q,SIGNAL(pickGreenClicked()),this,SLOT(_pickGreenClicked()));
        connect(q,SIGNAL(pickBlueClicked()),this,SLOT(_pickBlueClicked()));
        connect(q,SIGNAL(pickOpacityClicked()),this,SLOT(_pickOpacityClicked()));
    }
    if(s=="CMYK"){
        colorKeyPad=new CMYKColorKeyPad(this);
        operationKeyPad=new CMYKOperationKeyPad(this);
        CMYKOperationKeyPad* q=dynamic_cast<CMYKOperationKeyPad*>(operationKeyPad);
        connect(q,SIGNAL(pickCyanClicked()),this,SLOT(_pickCyanClicked()));
        connect(q,SIGNAL(pickMagentaClicked()),this,SLOT(_pickMagentaClicked()));
        connect(q,SIGNAL(pickYellowClicked()),this,SLOT(_pickYellowClicked()));
        connect(q,SIGNAL(pickKeyBlackClicked()),this,SLOT(_pickKeyBlackClicked()));
    }
    keyPadsInitialization();
    layout->insertWidget(2,colorKeyPad);
    layout->insertWidget(3,operationKeyPad);
    layout->update();
}

void CalculatorGUI::keyPadsInitialization(){
    connect(colorKeyPad,SIGNAL(valueChanged(const Color&)),this,SLOT(colorKeyPadValueChanged(const Color&)));

    connect(operationKeyPad,SIGNAL(blendClicked()),this,SLOT(_blendClicked()));
    connect(operationKeyPad,SIGNAL(complementaryClicked()),this,SLOT(_complementaryClicked()));
    connect(operationKeyPad,SIGNAL(sumClicked()),this,SLOT(_sumClicked()));
    connect(operationKeyPad,SIGNAL(substractionClicked()),this,SLOT(_substractionClicked()));
    connect(operationKeyPad,SIGNAL(moltiplicationClicked()),this,SLOT(_moltiplicationClicked()));
    connect(operationKeyPad,SIGNAL(divisionClicked()),this,SLOT(_divisionClicked()));

    connect(operationKeyPad,SIGNAL(equalsClicked()),this,SLOT(_equalsClicked()));
    connect(operationKeyPad,SIGNAL(cancelClicked()),this,SLOT(_cancelClicked()));
    connect(operationKeyPad,SIGNAL(cancelEntryClicked()),this,SLOT(cancelEntryClicked()));

    Color* aux=colorKeyPad->getColor();
    display->setLowerScreen(colorToString(*aux));
    delete aux;
}


std::string CalculatorGUI::colorToString(const Color& c){
    std::stringstream ss;
    c.print(ss);
    return ss.str();
}
void CalculatorGUI::getResult(const Color& c){
    display->setLowerScreen(colorToString(c));
    if(dynamic_cast<const ColorSRGB*>(&c)&&(!dynamic_cast<SRGBColorKeyPad*>(colorKeyPad)||dynamic_cast<SRGBAColorKeyPad*>(colorKeyPad))){
        comboBox->setCurrentIndex(comboBox->findData("SRGB"));
    }
    if(dynamic_cast<const ColorSRGBA*>(&c)&&!dynamic_cast<SRGBAColorKeyPad*>(colorKeyPad)){
        comboBox->setCurrentIndex(comboBox->findData("SRGBA"));
    }
    if(dynamic_cast<const ColorSCRGB*>(&c)&&!dynamic_cast<SCRGBColorKeyPad*>(colorKeyPad)){
        comboBox->setCurrentIndex(comboBox->findData("SCRGB"));
    }
    if(dynamic_cast<const ColorCMYK*>(&c)&&!dynamic_cast<CMYKColorKeyPad*>(colorKeyPad)){
        comboBox->setCurrentIndex(comboBox->findData("CMYK"));
    }
    colorKeyPad->setColor(c);
}
void CalculatorGUI::getError(std::string s){
    QMessageBox errorBox(this);
    errorBox.setText(QString::fromStdString(s));
    errorBox.exec();
    cancelClicked();
}

void CalculatorGUI::_blendClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"blend");
    cancelEntryClicked();
    emit blendClicked(aux);
}

void CalculatorGUI::_complementaryClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"complementary");
    emit complementaryClicked(aux);
}

void CalculatorGUI::_sumClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"+");
    cancelEntryClicked();
    emit sumClicked(aux);
}
void CalculatorGUI::_substractionClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"-");
    cancelEntryClicked();
    emit substractionClicked(aux);
}

void CalculatorGUI::_moltiplicationClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"*");
    cancelEntryClicked();
    emit moltiplicationClicked(aux);
}

void CalculatorGUI::_divisionClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"/");
    cancelEntryClicked();
    emit divisionClicked(aux);
}

void CalculatorGUI::_equalsClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen("");
    cancelEntryClicked();
    emit equalsClicked(aux);
}

void CalculatorGUI::_cancelClicked(){
    display->setUpperScreen("");
    cancelEntryClicked();
    emit cancelClicked();
}

void CalculatorGUI::_pickRedClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"pickRed");
    cancelEntryClicked();
    emit pickRedClicked(aux);
}
void CalculatorGUI::_pickGreenClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"pickGreen");
    cancelEntryClicked();
    emit pickGreenClicked(aux);
}

void CalculatorGUI::_pickBlueClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"pickBlue");
    cancelEntryClicked();
    emit pickBlueClicked(aux);
}

void CalculatorGUI::CalculatorGUI::_pickOpacityClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"pickOpacity");
    cancelEntryClicked();
    emit pickOpacityClicked(aux);
}
void CalculatorGUI::_pickCyanClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"pickCyan");
    cancelEntryClicked();
    emit pickCyanClicked(aux);
}

void CalculatorGUI::_pickMagentaClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"pickMagenta");
    cancelEntryClicked();
    emit pickMagentaClicked(aux);
}

void CalculatorGUI::_pickYellowClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"pickYellow");
    cancelEntryClicked();
    emit pickYellowClicked(aux);
}

void CalculatorGUI::_pickKeyBlackClicked(){
    Color* aux=colorKeyPad->getColor();
    display->setUpperScreen(colorToString(*aux)+"pickKeyBlack");
    cancelEntryClicked();
    emit pickKeyBlackClicked(aux);
}

void CalculatorGUI::colorKeyPadValueChanged(const Color& c){
    display->setLowerScreen(colorToString(c));
}

void CalculatorGUI::cancelEntryClicked(){
    colorKeyPad->reset();
    Color* aux=colorKeyPad->getColor();
    display->setLowerScreen(colorToString(*aux));
    delete aux;
}
