#ifndef SLIDERSPINBOX_H
#define SLIDERSPINBOX_H
#include<QWidget>

class QSpinBox;
class QSlider;
class QLabel;


class SliderSpinBox:public QWidget{
    Q_OBJECT
    public:
        SliderSpinBox(int,int,std::string ="",QWidget* =0);
        int getValue()const;
        void setValue(int);
    signals:
        void valueChanged(int);
    private:
        QLabel* label;
        QSlider* slider;
        QSpinBox* textBox;
};

#endif // SLIDERSPINBOX_H
