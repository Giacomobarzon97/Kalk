#ifndef COLOR_H
#define COLOR_H

#include<iostream>

class Color{
    public:
        virtual Color* complementary()const =0;
        virtual Color* blend(const Color&)const =0;

        virtual Color* operator+(const Color&)const =0;
        virtual Color* operator-(const Color&)const =0;
        virtual Color* operator*(const Color&)const =0;
        virtual Color* operator/(const Color&)const=0;

        virtual void print(std::ostream&)const=0;
        virtual ~Color();

};

std::ostream& operator<<(std::ostream&, const Color&);

class IncompatibleOperands{};
class DivisionByZero{};
#endif
