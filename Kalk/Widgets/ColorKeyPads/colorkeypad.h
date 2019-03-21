#ifndef COLORKEYPAD_H
#define COLORKEYPAD_H

#include<QWidget>
#include"../../Colors/color.h"
class ColorKeyPad:public QWidget{
    Q_OBJECT
    public:
        ColorKeyPad(QWidget* =0);
        virtual Color* getColor()=0;
        virtual void setColor(const Color&)=0;
        virtual void reset()=0;
        virtual ~ColorKeyPad()=0;
    signals:
        void valueChanged(const Color&);
    protected slots:
        void _valueChanged();
};
class WrongColor{};
#endif // COLORKEYPAD_H
