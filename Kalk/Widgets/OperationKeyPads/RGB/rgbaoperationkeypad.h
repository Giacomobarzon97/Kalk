#ifndef RGBAOPERATIONKEYPAD_H
#define RGBAOPERATIONKEYPAD_H

#include"rgboperationkeypad.h"

class RGBAOperationKeyPad:public RGBOperationKeyPad{
    Q_OBJECT
    public:
        RGBAOperationKeyPad(QWidget* =0);
        ~RGBAOperationKeyPad();
    protected:
        QPushButton* getPickOpacity();
    signals:
        void pickOpacityClicked();
    private:
        QPushButton* pickOpacity;
};

#endif // RGBAOPERATIONKEYPAD_H
