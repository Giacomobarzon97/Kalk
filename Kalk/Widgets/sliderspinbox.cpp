#include<QLabel>
#include<QSlider>
#include<QSpinBox>
#include<QSizePolicy>
#include<QHBoxLayout>

#include "sliderspinbox.h"


SliderSpinBox::SliderSpinBox(int min , int max, std::string s, QWidget* parent)
:QWidget(parent),label(new QLabel(QString::fromStdString(s),this)),slider(new QSlider(Qt::Horizontal,this))
,textBox(new QSpinBox(this)){
    QSizePolicy s1(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QSizePolicy s2(QSizePolicy::Expanding, QSizePolicy::Fixed);

    label->setSizePolicy(s1);
    label->setAlignment(Qt::AlignCenter);

    slider->setRange(min,max);
    slider->setSizePolicy(s2);

    textBox->setMinimum(min);
    textBox->setMaximum(max);
    textBox->setButtonSymbols( QAbstractSpinBox::NoButtons );
    textBox->setSizePolicy(s1);

    QHBoxLayout* l=new QHBoxLayout;
    l->addWidget(label);
    l->addWidget(slider);
    l->addWidget(textBox);

    setLayout(l);

    connect(slider,SIGNAL(valueChanged(int)),textBox,SLOT(setValue(int)));
    connect(textBox,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    connect(slider,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));
}
int SliderSpinBox::getValue()const{
    return textBox->value();
}
void SliderSpinBox::setValue(int a){
    textBox->setValue(a);
}
