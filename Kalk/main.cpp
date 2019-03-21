#include<QApplication>
#include"Widgets/calculatorgui.h"
#include"controller.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    CalculatorGUI b;
    Controller c(&b);
    b.show();
    return a.exec();
}
