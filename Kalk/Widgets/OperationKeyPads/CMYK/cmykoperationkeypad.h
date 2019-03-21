#ifndef CMYKOPERATIONKEYPAD_H
#define CMYKOPERATIONKEYPAD_H

#include<QVBoxLayout>
#include"../operationkeypad.h"

class CMYKOperationKeyPad:public OperationKeyPad{
    Q_OBJECT
    public:
        CMYKOperationKeyPad(QWidget* =0);
        ~CMYKOperationKeyPad();
    protected:
        QPushButton* getPickCyan()const;
        QPushButton* getPickMagenta()const;
        QPushButton* getPickYellow()const;
        QPushButton* getPickKeyBlack()const;

        QVBoxLayout* getColumn1()const;
        QVBoxLayout* getColumn2()const;
        QVBoxLayout* getColumn3()const;
    signals:
        void pickCyanClicked();
        void pickMagentaClicked();
        void pickYellowClicked();
        void pickKeyBlackClicked();
    private:
        QPushButton *pickCyan,*pickMagenta,*pickYellow,*pickKeyBlack;
        QVBoxLayout *column1,*column2,*column3;
};

#endif // CMYKOPERATIONKEYPAD_H
