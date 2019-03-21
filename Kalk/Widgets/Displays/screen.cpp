#include<QLabel>
#include<QVBoxLayout>

#include"screen.h"

Screen::Screen(QWidget* parent)
:QWidget(parent),top(new QLabel("",this)),bottom(new QLabel("",this)){
    top->setAlignment(Qt::AlignRight);
    bottom->setAlignment(Qt::AlignRight);

    QVBoxLayout* l=new QVBoxLayout;

    l->addWidget(top);
    l->addWidget(bottom);
    setLayout(l);
}

Screen::~Screen(){
    delete bottom;
    delete top;
}
void Screen::setUpperScreen(std::string s){
    top->setText(QString::fromStdString(s));
}

void Screen::setLowerScreen(std::string s){
    bottom->setText(QString::fromStdString(s));
}
