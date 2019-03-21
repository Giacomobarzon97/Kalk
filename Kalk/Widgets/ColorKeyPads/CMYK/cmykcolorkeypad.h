#ifndef CMYKCOLORKEYPAD_H
#define CMYKCOLORKEYPAD_H

#include"../colorkeypad.h"
#include"../../sliderspinbox.h"
#include"../../../Colors/CMYKColors/colorcmyk.h"

class CMYKColorKeyPad:public ColorKeyPad{
    public:
        CMYKColorKeyPad(QWidget* =0);
        virtual ColorCMYK* getColor()override;
        virtual void setColor(const Color&)override;
        virtual void reset()override;
        virtual ~CMYKColorKeyPad();
    private:
        SliderSpinBox *cyan,*magenta,*yellow,*keyBlack;
};

#endif // CMYKCOLORKEYPAD_H
