#ifndef COLORRGB_H
#define COLORRGB_H

#include"../color.h"

class ColorRGB:public Color{
    public:
        ColorRGB(int,int,int);

        virtual ColorRGB* pickRed(const ColorRGB&)const =0;
        virtual ColorRGB* pickGreen(const ColorRGB&)const =0;
        virtual ColorRGB* pickBlue(const ColorRGB&)const =0;

        int getRed() const;
        int getGreen() const;
        int getBlue() const;

        virtual void print(std::ostream&)const override;
    private:
        int red,green, blue;
};

class RedValueNotBetweenBounds{};
class GreenValueNotBetweenBounds{};
class BlueValueNotBetweenBounds{};

#endif // COLORRGB_H
