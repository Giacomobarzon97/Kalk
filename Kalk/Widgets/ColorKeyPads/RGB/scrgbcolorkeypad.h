#ifndef SCRGBCOLORKEYPAD_H
#define SCRGBCOLORKEYPAD_H

#include"../colorkeypad.h"
#include"../../sliderspinbox.h"
#include"../../../Colors/RGBColors/colorscrgb.h"

class SCRGBColorKeyPad:public ColorKeyPad{
    public:
        SCRGBColorKeyPad(QWidget* =0);
        virtual ColorSCRGB* getColor()override;
        virtual void setColor(const Color&)override;
        virtual void reset()override;
        virtual ~SCRGBColorKeyPad();
    private:
        SliderSpinBox* red;
        SliderSpinBox* green;
        SliderSpinBox* blue;
};

#endif // SCRGBCOLORKEYPAD_H
