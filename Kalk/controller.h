#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"Widgets/calculatorgui.h"
#include"model.h"
class Controller{
    public:
        Controller(CalculatorGUI*);
        ~Controller();
    private:
        CalculatorGUI* view;
        Model* model;
};

#endif // CONTROLLER_H
