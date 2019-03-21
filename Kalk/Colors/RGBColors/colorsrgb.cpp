#include"colorsrgb.h"
ColorSRGB::ColorSRGB(int r,int g,int b)
:ColorRGB(r,g,b){
    if(r<0||r>255){
        throw RedValueNotBetweenBounds();
    }
    if(g<0||g>255){
        throw GreenValueNotBetweenBounds();
    }
    if(b<0||b>255){
        throw BlueValueNotBetweenBounds();
    }
}

ColorSRGB* ColorSRGB::complementary() const{
    return new ColorSRGB(255-getRed(),255-getGreen(),255-getBlue());
}

ColorSRGB* ColorSRGB::blend(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(q)return new ColorSRGB(reduceToBounds((getRed()+q->getRed())/2),reduceToBounds((getGreen()+q->getGreen())/2),reduceToBounds((getBlue()+q->getBlue())/2));
    else throw IncompatibleOperands();

}

ColorSRGB* ColorSRGB::operator+(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(q)return new ColorSRGB(reduceToBounds(getRed()+q->getRed()),reduceToBounds(getGreen()+q->getGreen()),reduceToBounds(getBlue()+q->getBlue()));
    else throw IncompatibleOperands();
}

ColorSRGB* ColorSRGB::operator-(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(q)return new ColorSRGB(reduceToBounds(getRed()-q->getRed()),reduceToBounds(getGreen()-q->getGreen()),reduceToBounds(getBlue()-q->getBlue()));
    else throw IncompatibleOperands();
}
ColorSRGB* ColorSRGB::operator*(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(q)return new ColorSRGB(reduceToBounds(getRed()* q->getRed()),reduceToBounds(getGreen()* q->getGreen()),reduceToBounds(getBlue()* q->getBlue()));
    else throw IncompatibleOperands();
}

ColorSRGB* ColorSRGB::operator/(const Color& c)const{
    const ColorRGB* q=dynamic_cast<const ColorRGB*>(&c);
    if(!q)throw IncompatibleOperands();
    if(q->getRed()==0||q->getGreen()==0||q->getBlue()==0)throw DivisionByZero();
    return new ColorSRGB(reduceToBounds(getRed()/ q->getRed()),reduceToBounds(getGreen()/ q->getGreen()),reduceToBounds(getBlue()/ q->getBlue()));
}

ColorSRGB* ColorSRGB::pickRed(const ColorRGB& c)const{
    return new ColorSRGB(reduceToBounds(c.getRed()),getGreen(),getBlue());
}
ColorSRGB* ColorSRGB::pickGreen(const ColorRGB& c)const{
    return new ColorSRGB(getRed(),reduceToBounds(c.getGreen()),getBlue());
}

ColorSRGB* ColorSRGB::pickBlue(const ColorRGB& c)const{
    return new ColorSRGB(getRed(),getGreen(),reduceToBounds(c.getBlue()));
}

int ColorSRGB::reduceToBounds(int a){
    if(a<=0){
        return 0;
    }else{
        return a%256;
    }
}

void ColorSRGB::print(std::ostream& os)const{
    os<<"SRGB("<<getRed()<<","<<getGreen()<<","<<getBlue()<<")";
}
