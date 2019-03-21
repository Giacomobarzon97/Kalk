#ifndef COLORSCRGB_H
#define COLORSCRGB_H

#include"colorrgb.h"

class ColorSCRGB:public ColorRGB{
    public:
        ColorSCRGB(int, int, int);

        virtual ColorSCRGB* complementary()const;
        virtual ColorSCRGB* blend(const Color&)const;

        virtual ColorSCRGB* operator+(const Color&)const override;
        virtual ColorSCRGB* operator-(const Color&)const override;
        virtual ColorSCRGB* operator*(const Color&)const override;
        virtual ColorSCRGB* operator/(const Color&)const override;

        virtual ColorSCRGB* pickRed(const ColorRGB&)const override;
        virtual ColorSCRGB* pickGreen(const ColorRGB&)const override;
        virtual ColorSCRGB* pickBlue(const ColorRGB&)const override;

        virtual void print(std::ostream&)const override;
    private:
        static int reduceToBounds(int);
};

#endif
