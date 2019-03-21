#include"colorscrgb.h"
#include<stdlib.h>
ColorSCRGB::ColorSCRGB(int r, int g, int b):ColorRGB(r,g,b){
    if(r<-255||r>255){
        throw RedValueNotBetweenBounds();
    }
    if(g<-255||g>255){
        throw GreenValueNotBetweenBounds();
    }
    if(b<-255||b>255){
        throw BlueValueNotBetweenBounds();
    }
}

ColorSCRGB* ColorSCRGB::complementary()const{
    return new ColorSCRGB(0-getRed(),0-getGreen(),0-getBlue());
}

ColorSCRGB* ColorSCRGB::blend(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(q)return new ColorSCRGB((getRed()+q->getRed())/2,(getGreen()+q->getGreen())/2,(getBlue()+q->getBlue())/2);
    else throw IncompatibleOperands();

}

ColorSCRGB* ColorSCRGB::operator+(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(q)return new ColorSCRGB(reduceToBounds(getRed()+q->getRed()),reduceToBounds(getGreen()+q->getGreen()),reduceToBounds(getBlue()+q->getBlue()));
    else throw IncompatibleOperands();
}

ColorSCRGB* ColorSCRGB::operator-(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(q)return new ColorSCRGB(reduceToBounds(getRed()-q->getRed()),reduceToBounds(getGreen()-q->getGreen()),reduceToBounds(getBlue()-q->getBlue()));
    else throw IncompatibleOperands();
}
ColorSCRGB* ColorSCRGB::operator*(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(q)return new ColorSCRGB(reduceToBounds(getRed()* q->getRed()),reduceToBounds(getGreen()* q->getGreen()),reduceToBounds(getBlue()* q->getBlue()));
    else throw IncompatibleOperands();
}

ColorSCRGB* ColorSCRGB::operator/(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(!q)throw IncompatibleOperands();
    if(q->getRed()==0||q->getGreen()==0||q->getBlue()==0)throw DivisionByZero();
    return new ColorSCRGB(reduceToBounds(getRed()/ q->getRed()),reduceToBounds(getGreen()/ q->getGreen()),reduceToBounds(getBlue()/ q->getBlue()));
}

ColorSCRGB* ColorSCRGB::pickRed(const ColorRGB& c)const{
    return new ColorSCRGB(reduceToBounds(c.getRed()),getBlue(),getGreen());
}
ColorSCRGB* ColorSCRGB::pickGreen(const ColorRGB& c)const{
    return new ColorSCRGB(getRed(),reduceToBounds(c.getGreen()),getBlue());
}
ColorSCRGB* ColorSCRGB::pickBlue(const ColorRGB& c)const{
    return new ColorSCRGB(getRed(),getGreen(),reduceToBounds(c.getBlue()));
}

int ColorSCRGB::reduceToBounds(int a){
    int aux;
    if(a<0) aux=-1;
    else aux=1;
    return (abs(a)%256)*aux;
}

void ColorSCRGB::print(std::ostream& os)const{
    os<<"SCRGB("<<getRed()<<","<<getGreen()<<","<<getBlue()<<")";
}
