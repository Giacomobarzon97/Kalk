#ifndef MODEL_H
#define MODEL_H

#include<QObject>
#include"Colors/color.h"
enum Operations
{null,blend,sum,substraction,moltiplication,division
,pickRed,pickGreen,pickBlue,pickOpacity
,pickCyan,pickMagenta,pickYellow,pickKeyBlack};

class Model:public QObject{
    Q_OBJECT
    public:
        Model();
        ~Model();
    signals:
        void result(const Color&);
        void error(std::string);
    public slots:
        void blendClicked(Color*);
        void complementaryClicked(Color*);
        void sumClicked(Color*);
        void substractionClicked(Color*);
        void moltiplicationClicked(Color*);
        void divisionClicked(Color*);
        void equalsClicked(Color*);
        void cancelClicked();

        void pickRedClicked(Color*);
        void pickGreenClicked(Color*);
        void pickBlueClicked(Color*);
        void pickOpacityClicked(Color*);

        void pickCyanClicked(Color*);
        void pickMagentaClicked(Color*);
        void pickYellowClicked(Color*);
        void pickKeyBlackClicked(Color*);
    private:
        Color* color;
        Operations operation;
        void generalOperation(Operations, Color*);
};

class OperationNotAvailable{};
#endif // MODEL_H
