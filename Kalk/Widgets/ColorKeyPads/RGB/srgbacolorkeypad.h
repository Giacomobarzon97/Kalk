#ifndef SRGBACOLORKEYPAD_H
#define SRGBACOLORKEYPAD_H

#include"srgbcolorkeypad.h"
#include"../../../Colors/RGBColors/colorsrgba.h"

class SRGBAColorKeyPad:public SRGBColorKeyPad{
    public:
        SRGBAColorKeyPad(QWidget* =0);
        virtual ColorSRGBA* getColor()override;
        virtual void setColor(const Color&)override;
        virtual void reset()override;
        ~SRGBAColorKeyPad();
    private:
        SliderSpinBox* opacity;
};

#endif // SRGBACOLORKEYPAD_H
