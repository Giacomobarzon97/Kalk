#ifndef SCREEN_H
#define SCREEN_H

#include<QWidget>

class QLabel;

class Screen:public QWidget{
    public:
        Screen(QWidget* =0);
        virtual ~Screen();
   public slots:
        void setUpperScreen(std::string);
        void setLowerScreen(std::string);
    private:
        QLabel* top;
        QLabel* bottom;
};

#endif // SCREEN_H
