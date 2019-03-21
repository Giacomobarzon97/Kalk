#ifndef COLORSRGBA_H
#define COLORSRGBA_H

#include"colorsrgb.h"

class ColorSRGBA:public ColorSRGB{
    public:
        ColorSRGBA(int, int, int, int);

        virtual ColorSRGBA* complementary()const override;
        virtual ColorSRGBA* blend(const Color&)const override;

        virtual ColorSRGBA* operator+(const Color&)const override;
        virtual ColorSRGBA* operator-(const Color&)const override;
        virtual ColorSRGBA* operator*(const Color&)const override;
        virtual ColorSRGBA* operator/(const Color&)const override;

        virtual ColorSRGBA* pickRed(const ColorRGB&)const override;
        virtual ColorSRGBA* pickGreen(const ColorRGB&)const override;
        virtual ColorSRGBA* pickBlue(const ColorRGB&)const override;
        ColorSRGBA* pickOpacity(const ColorRGB&)const;

        int getOpacity()const;

        virtual void print(std::ostream&)const override;
    private:
        int opacity;
};

class OpacityValueNotBetweenBounds{};

#endif
