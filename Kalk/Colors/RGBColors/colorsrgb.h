#ifndef COLORSRGB_H
#define COLORSRGB_H

#include "colorrgb.h"

class ColorSRGB:public ColorRGB{
    public:
        ColorSRGB(int, int, int);

        virtual ColorSRGB* complementary()const;
        virtual ColorSRGB* blend(const Color&)const;

        virtual ColorSRGB* operator+(const Color&)const override;
        virtual ColorSRGB* operator-(const Color&)const override;
        virtual ColorSRGB* operator*(const Color&)const override;
        virtual ColorSRGB* operator/(const Color&)const override;


        virtual ColorSRGB* pickRed(const ColorRGB&)const override;
        virtual ColorSRGB* pickGreen(const ColorRGB&)const override;
        virtual ColorSRGB* pickBlue(const ColorRGB&)const override;

        virtual void print(std::ostream&)const override;
    protected:
        static int reduceToBounds(int);
};

#endif
