#ifndef RGBOPERATIONKEYPAD_H
#define RGBOPERATIONKEYPAD_H

#include<QVBoxLayout>

#include"../operationkeypad.h"

class RGBOperationKeyPad:public OperationKeyPad{
    Q_OBJECT
    public:
        RGBOperationKeyPad(QWidget* =0);
        ~RGBOperationKeyPad();
    protected:
        QVBoxLayout* getColumn1()const;
        QVBoxLayout* getColumn2()const;
        QVBoxLayout* getColumn3()const;

        QPushButton* getPickRed()const;
        QPushButton* getPickGreen()const;
        QPushButton* getPickBlue()const;
    signals:
        void pickRedClicked();
        void pickGreenClicked();
        void pickBlueClicked();
    private:
        QPushButton* pickRed;
        QPushButton* pickGreen;
        QPushButton* pickBlue;

        QVBoxLayout* column1;
        QVBoxLayout* column2;
        QVBoxLayout* column3;
};

#endif // RGBOPERATIONKEYPAD_H
