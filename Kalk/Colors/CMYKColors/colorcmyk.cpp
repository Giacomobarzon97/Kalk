#include"colorcmyk.h"

ColorCMYK::ColorCMYK(int c,int m,int y,int k):cyan(c),magenta(m),yellow(y),keyBlack(k){
    if(c<0||c>100){
        throw CyanValueNotBetweenBounds();
    }
    if(m<0||m>100){
        throw MagentaValueNotBetweenBounds();
    }
    if(y<0||y>100){
        throw YellowValueNotBetweenBounds();
    }
    if(k<0||k>100){
        throw KeyBlackValueNotBetweenBounds();
    }
}

ColorCMYK* ColorCMYK::complementary()const{
    return new ColorCMYK(100-cyan,100-magenta,100-yellow,100-keyBlack);
}
ColorCMYK* ColorCMYK::blend(const Color& c)const{
    const ColorCMYK* q=dynamic_cast<const ColorCMYK*>(&c);
    if(!q)throw IncompatibleOperands();
    return new ColorCMYK((cyan+q->cyan)/2,(magenta+q->magenta)/2,(yellow+q->yellow)/2,(keyBlack+q->keyBlack)/2);
}

ColorCMYK* ColorCMYK::operator+(const Color& c)const{
    const ColorCMYK* q=dynamic_cast<const ColorCMYK*>(&c);
    if(!q)throw IncompatibleOperands();
    return new ColorCMYK(reduceToBounds(cyan+q->cyan),reduceToBounds(magenta+q->magenta),reduceToBounds(yellow+q->yellow),reduceToBounds(keyBlack+q->keyBlack));
}

ColorCMYK* ColorCMYK::operator-(const Color& c)const{
    const ColorCMYK* q=dynamic_cast<const ColorCMYK*>(&c);
    if(!q)throw IncompatibleOperands();
    return new ColorCMYK(reduceToBounds(cyan-q->cyan),reduceToBounds(magenta-q->magenta),reduceToBounds(yellow-q->yellow),reduceToBounds(keyBlack-q->keyBlack));
}
ColorCMYK* ColorCMYK::operator*(const Color& c)const{
    const ColorCMYK* q=dynamic_cast<const ColorCMYK*>(&c);
    if(!q)throw IncompatibleOperands();
    return new ColorCMYK(reduceToBounds(cyan*q->cyan),reduceToBounds(magenta*q->magenta),reduceToBounds(yellow*q->yellow),reduceToBounds(keyBlack*q->keyBlack));
}
ColorCMYK* ColorCMYK::operator/(const Color& c)const{
    const ColorCMYK* q=dynamic_cast<const ColorCMYK*>(&c);
    if(!q)throw IncompatibleOperands();
    if(q->getCyan()==0||q->getMagenta()==0||q->getYellow()==0||q->getKeyBlack()==0)throw DivisionByZero();
    return new ColorCMYK(reduceToBounds(cyan/q->cyan),reduceToBounds(magenta/q->magenta),reduceToBounds(yellow/q->yellow),reduceToBounds(keyBlack/q->keyBlack));
}

ColorCMYK* ColorCMYK::pickCyan(const ColorCMYK& c)const{
    return new ColorCMYK(c.cyan,magenta,yellow,keyBlack);
}

ColorCMYK* ColorCMYK::pickMagenta(const ColorCMYK& c)const {
    return new ColorCMYK(cyan,c.magenta,yellow,keyBlack);
}
ColorCMYK* ColorCMYK::pickYellow(const ColorCMYK& c)const{
    return new ColorCMYK(cyan,magenta,c.yellow,keyBlack);
}
ColorCMYK* ColorCMYK::pickKeyBlack(const ColorCMYK& c)const{
    return new ColorCMYK(cyan,magenta,yellow,c.keyBlack);
}


void ColorCMYK::print(std::ostream& os)const{
    os<<"CMYK("<<cyan<<","<<magenta<<","<<yellow<<","<<keyBlack<<")";
}

int ColorCMYK::getCyan()const{
    return cyan;
}

int ColorCMYK::getMagenta()const{
    return magenta;
}

int ColorCMYK::getYellow()const{
    return yellow;
}

int ColorCMYK::getKeyBlack()const{
    return keyBlack;
}

int ColorCMYK::reduceToBounds(int a){
    if(a<=0)return 0;
    if(a>100)return a%101;
    return a;
}
