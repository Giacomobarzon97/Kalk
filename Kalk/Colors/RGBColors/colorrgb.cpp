#include"colorrgb.h"

ColorRGB::ColorRGB(int r, int g, int b)
    :red(r),green(g),blue(b){}

int ColorRGB::getRed()const{
    return red;
}

int ColorRGB::getGreen()const{
    return green;
}

int ColorRGB::getBlue()const{
    return blue;
}

void ColorRGB::print(std::ostream& os)const{
    os<<"RGB("<<(red)<<","<<green<<","<<blue<<")";
}
