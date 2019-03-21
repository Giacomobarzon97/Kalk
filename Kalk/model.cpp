#include"model.h"

#include"Colors/RGBColors/colorrgb.h"
#include"Colors/RGBColors/colorscrgb.h"
#include"Colors/RGBColors/colorsrgb.h"
#include"Colors/RGBColors/colorsrgba.h"
#include"Colors/CMYKColors/colorcmyk.h"

Model::Model():color(0),operation(null){}
Model::~Model(){
    if(color!=0)delete color;
}

void Model::generalOperation(Operations o, Color* c){
    if(color!=0){
        delete color;
    }
    color=c;
    operation=o;
}

void Model::blendClicked(Color* c){
    generalOperation(blend,c);
}
void Model::sumClicked(Color* c){
    generalOperation(sum,c);
}

void Model::substractionClicked(Color* c){
    generalOperation(substraction,c);
}

void Model::moltiplicationClicked(Color* c){
    generalOperation(moltiplication,c);
}

void Model::divisionClicked(Color* c){
    generalOperation(division,c);
}

void Model::complementaryClicked(Color* c){
    if(color!=0){
        delete color;
        color=0;
    }
    operation=null;
    Color* aux=c->complementary();
    emit result(*aux);
    delete aux;
    delete c;
}

void Model::equalsClicked(Color* c)try{
    if(color!=0 && operation!=null){
        Color* aux=0;
        if(operation==blend){
            aux=color->blend(*c);
        }
        if(operation==sum){
            aux=color->operator+(*c);
        }
        if(operation==substraction){
            aux=color->operator-(*c);
        }
        if(operation==moltiplication){
            aux=color->operator*(*c);
        }
        if(operation==division){
            aux=color->operator/(*c);
        }
        if(operation==pickRed){
            ColorRGB* q1=dynamic_cast<ColorRGB*>(color);
            ColorRGB* q2=dynamic_cast<ColorRGB*>(c);
            if(q1!=0 && q2!=0) aux=q1->pickRed(*q2);
        }
        if(operation==pickGreen){
            ColorRGB* q1=dynamic_cast<ColorRGB*>(color);
            ColorRGB* q2=dynamic_cast<ColorRGB*>(c);
            if(q1!=0 && q2!=0) aux=q1->pickGreen(*q2);
        }
        if(operation==pickBlue){
            ColorRGB* q1=dynamic_cast<ColorRGB*>(color);
            ColorRGB* q2=dynamic_cast<ColorRGB*>(c);
            if(q1!=0 && q2!=0) aux=q1->pickBlue(*q2);
        }
        if(operation==pickOpacity){
            ColorSRGBA* q1=dynamic_cast<ColorSRGBA*>(color);
            ColorRGB* q2=dynamic_cast<ColorRGB*>(c);
            if(q1!=0 && q2!=0) aux=q1->pickOpacity(*q2);
        }
        if(operation==pickCyan){
            ColorCMYK* q1=dynamic_cast<ColorCMYK*>(color);
            ColorCMYK* q2=dynamic_cast<ColorCMYK*>(c);
            if(q1!=0 && q2!=0) aux=q1->pickCyan(*q2);
        }
        if(operation==pickMagenta){
            ColorCMYK* q1=dynamic_cast<ColorCMYK*>(color);
            ColorCMYK* q2=dynamic_cast<ColorCMYK*>(c);
            if(q1!=0 && q2!=0) aux=q1->pickMagenta(*q2);
        }
        if(operation==pickYellow){
            ColorCMYK* q1=dynamic_cast<ColorCMYK*>(color);
            ColorCMYK* q2=dynamic_cast<ColorCMYK*>(c);
            if(q1!=0 && q2!=0) aux=q1->pickYellow(*q2);
        }
        if(operation==pickKeyBlack){
            ColorCMYK* q1=dynamic_cast<ColorCMYK*>(color);
            ColorCMYK* q2=dynamic_cast<ColorCMYK*>(c);
            if(q1!=0 && q2!=0) aux=q1->pickKeyBlack(*q2);
        }
        delete c;
        delete color;
        color=0;
        operation=null;
        if(aux!=0){
            emit result(*aux);
            delete aux;
        }else{
            throw OperationNotAvailable();
        }
    }else{
        delete c;
    }
}
catch(IncompatibleOperands){emit error("Impossibile effettuare l'operazione tra questi due tipi");}
catch(DivisionByZero){emit error("Impossibile effettuare divisioni per zero");}
catch(...){emit error("Qualcosa è andato storto durante l'operazione. Riprova ;)");}

void Model::cancelClicked(){
    if(color!=0){
        delete color;
        color=0;
    }
    operation=null;
}

void Model::pickRedClicked(Color* c){
    generalOperation(pickRed,c);
}

void Model::pickGreenClicked(Color* c){
    generalOperation(pickGreen,c);
}

void Model::pickBlueClicked(Color* c){
    generalOperation(pickBlue,c);
}

void Model::pickOpacityClicked(Color* c){
    generalOperation(pickOpacity,c);
}
void Model::pickCyanClicked(Color* c){
    generalOperation(pickCyan,c);
}

void Model::pickMagentaClicked(Color* c){
    generalOperation(pickMagenta,c);
}

void Model::pickYellowClicked(Color* c){
    generalOperation(pickYellow,c);
}

void Model::pickKeyBlackClicked(Color* c){
    generalOperation(pickKeyBlack,c);
}
