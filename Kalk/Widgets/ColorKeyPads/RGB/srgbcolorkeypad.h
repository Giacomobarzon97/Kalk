#ifndef SRGBCOLORKEYPAD_H
#define SRGBCOLORKEYPAD_H

#include<QVBoxLayout>

#include"../colorkeypad.h"
#include"../../sliderspinbox.h"
#include"../../../Colors/RGBColors/colorsrgb.h"

class SRGBColorKeyPad:public ColorKeyPad{
    public:
        SRGBColorKeyPad(QWidget* =0);
        virtual ~SRGBColorKeyPad();
        virtual ColorSRGB* getColor()override;
        virtual void setColor(const Color&)override;
        virtual void reset()override;
    protected:
        QVBoxLayout* getLayout()const;
        SliderSpinBox* getRed()const;
        SliderSpinBox* getGreen()const;
        SliderSpinBox* getBlue()const;
    private:
        SliderSpinBox* red;
        SliderSpinBox* green;
        SliderSpinBox* blue;
        QVBoxLayout* layout;
};

#endif // SRGBCOLORKEYPAD_H
