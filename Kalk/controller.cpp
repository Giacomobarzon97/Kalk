#include<QObject>
#include"controller.h"
Controller::Controller(CalculatorGUI* c):view(c),model(new Model()){
    QObject::connect(view,SIGNAL(blendClicked(Color*)),model,SLOT(blendClicked(Color*)));
    QObject::connect(view,SIGNAL(complementaryClicked(Color*)),model,SLOT(complementaryClicked(Color*)));
    QObject::connect(view,SIGNAL(sumClicked(Color*)),model,SLOT(sumClicked(Color*)));
    QObject::connect(view,SIGNAL(substractionClicked(Color*)),model,SLOT(substractionClicked(Color*)));
    QObject::connect(view,SIGNAL(moltiplicationClicked(Color*)),model,SLOT(moltiplicationClicked(Color*)));
    QObject::connect(view,SIGNAL(divisionClicked(Color*)),model,SLOT(divisionClicked(Color*)));

    QObject::connect(view,SIGNAL(cancelClicked()),model,SLOT(cancelClicked()));
    QObject::connect(view,SIGNAL(equalsClicked(Color*)),model,SLOT(equalsClicked(Color*)));

    QObject::connect(view,SIGNAL(pickRedClicked(Color*)),model,SLOT(pickRedClicked(Color*)));
    QObject::connect(view,SIGNAL(pickGreenClicked(Color*)),model,SLOT(pickGreenClicked(Color*)));
    QObject::connect(view,SIGNAL(pickBlueClicked(Color*)),model,SLOT(pickBlueClicked(Color*)));
    QObject::connect(view,SIGNAL(pickOpacityClicked(Color*)),model,SLOT(pickOpacityClicked(Color*)));

    QObject::connect(view,SIGNAL(pickCyanClicked(Color*)),model,SLOT(pickCyanClicked(Color*)));
    QObject::connect(view,SIGNAL(pickMagentaClicked(Color*)),model,SLOT(pickMagentaClicked(Color*)));
    QObject::connect(view,SIGNAL(pickYellowClicked(Color*)),model,SLOT(pickYellowClicked(Color*)));
    QObject::connect(view,SIGNAL(pickKeyBlackClicked(Color*)),model,SLOT(pickKeyBlackClicked(Color*)));

    QObject::connect(model,SIGNAL(result(const Color&)),view,SLOT(getResult(const Color&)));
    QObject::connect(model,SIGNAL(error(std::string)),view,SLOT(getError(std::string)));
}
Controller::~Controller(){
    delete model;
}
