#include "color.h"

std::ostream& operator<<(std::ostream& os, const Color& c){
    c.print(os);
    return os;
}

Color::~Color(){}
