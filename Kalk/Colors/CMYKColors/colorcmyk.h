#ifndef COLORCMYK_H
#define COLORCMYK_H

#include"../color.h"

class ColorCMYK:public Color{
    public:
        ColorCMYK(int,int,int,int);

        virtual ColorCMYK* complementary()const;
        virtual ColorCMYK* blend(const Color&)const;

        virtual ColorCMYK* operator+(const Color&)const override;
        virtual ColorCMYK* operator-(const Color&)const override;
        virtual ColorCMYK* operator*(const Color&)const override;
        virtual ColorCMYK* operator/(const Color&)const override;

        ColorCMYK* pickCyan(const ColorCMYK&)const;
        ColorCMYK* pickMagenta(const ColorCMYK&)const;
        ColorCMYK* pickYellow(const ColorCMYK&)const;
        ColorCMYK* pickKeyBlack(const ColorCMYK&)const;


        virtual void print(std::ostream&)const override;

        int getCyan()const;
        int getMagenta()const;
        int getYellow()const;
        int getKeyBlack()const;
    private:
        int cyan,magenta,yellow,keyBlack;
        static int reduceToBounds(int);
};

class CyanValueNotBetweenBounds{};
class MagentaValueNotBetweenBounds{};
class YellowValueNotBetweenBounds{};
class KeyBlackValueNotBetweenBounds{};



#endif // COLORCMYK_H
