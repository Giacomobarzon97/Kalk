#include"colorsrgba.h"

ColorSRGBA::ColorSRGBA(int r, int g, int b, int o):ColorSRGB(r,g,b),opacity(o){
    if(o<0||o>100){
        throw OpacityValueNotBetweenBounds();
    }
}

ColorSRGBA* ColorSRGBA::complementary()const{
    return new ColorSRGBA(255-getRed(),255-getGreen(),255-getBlue(),100-opacity);
}

ColorSRGBA* ColorSRGBA::blend(const Color& c)const{
    const ColorRGB* p=dynamic_cast<const ColorRGB*>(&c);
    if(!p) throw IncompatibleOperands();
    int o=100;
    const ColorSRGBA* q=dynamic_cast<const ColorSRGBA*>(&c);
    if(q){
        o=q->opacity;
    }
    return new ColorSRGBA(reduceToBounds((getRed()+p->getRed())/2),reduceToBounds((getGreen()+p->getGreen())/2),reduceToBounds((getBlue()+p->getBlue())/2),(opacity+o)/2);
}

ColorSRGBA* ColorSRGBA::operator+(const Color& c)const{
    const ColorRGB* p=dynamic_cast<const ColorRGB*>(&c);
    if(!p) throw IncompatibleOperands();
    int o=100;
    const ColorSRGBA* q=dynamic_cast<const ColorSRGBA*>(&c);
    if(q){
        o=q->opacity;
    }
    return new ColorSRGBA(reduceToBounds(getRed()+p->getRed()),reduceToBounds(getGreen()+p->getGreen()),reduceToBounds(getBlue()+p->getBlue()),(opacity+o)%101);
}

ColorSRGBA* ColorSRGBA::operator-(const Color& c)const{
    const ColorRGB* p=dynamic_cast<const ColorRGB*>(&c);
    if(!p) throw IncompatibleOperands();
    int o=0;
    const ColorSRGBA* q=dynamic_cast<const ColorSRGBA*>(&c);
    if(q){
        o=opacity-q->opacity;
    }else{
        o=opacity-100;
    }
    if(o<0)o=0;
    return new ColorSRGBA(reduceToBounds(getRed()-p->getRed()),reduceToBounds(getGreen()-p->getGreen()),reduceToBounds(getBlue()-p->getBlue()),o%101);
}

ColorSRGBA* ColorSRGBA::operator*(const Color& c)const{
    const ColorRGB* p=dynamic_cast<const ColorRGB*>(&c);
    if(!p) throw IncompatibleOperands();
    int o=100;
    const ColorSRGBA* q=dynamic_cast<const ColorSRGBA*>(&c);
    if(q){
        o=q->opacity;
    }
    return new ColorSRGBA(reduceToBounds(getRed()*p->getRed()),reduceToBounds(getGreen()*p->getGreen()),reduceToBounds(getBlue()*p->getBlue()),(opacity*o)%101);
}

ColorSRGBA* ColorSRGBA::operator/(const Color& c)const{
    const ColorRGB* p=dynamic_cast<const ColorRGB*>(&c);
    if(!p) throw IncompatibleOperands();
    int o=100;
    const ColorSRGBA* q=dynamic_cast<const ColorSRGBA*>(&c);
    if(q){
        o=q->opacity;
    }
    if(p->getRed()==0||p->getGreen()==0||p->getBlue()==0||o==0)throw DivisionByZero();
    return new ColorSRGBA(reduceToBounds(getRed()/p->getRed()),reduceToBounds(getGreen()/p->getGreen()),reduceToBounds(getBlue()/p->getBlue()),(opacity/o)%101);
}

ColorSRGBA* ColorSRGBA::pickRed(const ColorRGB& c)const{
    int r=c.getRed()%255;
    if(r<0)r=0;
    return new ColorSRGBA(r,getGreen(),getBlue(),opacity);
}
ColorSRGBA* ColorSRGBA::pickGreen(const ColorRGB& c)const{
    int r=c.getGreen()%255;
    if(r<0)r=0;
    return new ColorSRGBA(getRed(),r,getBlue(),opacity);
}

ColorSRGBA* ColorSRGBA::pickBlue(const ColorRGB& c)const{
    int r=c.getBlue()%255;
    if(r<0)r=0;
    return new ColorSRGBA(getRed(),getGreen(),r,opacity);
}

ColorSRGBA* ColorSRGBA::pickOpacity(const ColorRGB& c)const{
    const ColorSRGBA* q=dynamic_cast<const ColorSRGBA*>(&c);
    int o=100;
    if(q){
        o=q->opacity;
    }
    return new ColorSRGBA(getRed(),getGreen(),getBlue(),o);
}

int ColorSRGBA::getOpacity()const{
    return opacity;
}

void ColorSRGBA::print(std::ostream& os)const{
    os<<"SRGBA("<<getRed()<<","<<getGreen()<<","<<getBlue()<<","<<opacity<<")";
}
