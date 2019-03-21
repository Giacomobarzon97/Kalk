#ifndef OPERATIONKEYPAD_H
#define OPERATIONKEYPAD_H

#include<QWidget>

class QPushButton;

class OperationKeyPad: public QWidget{
    Q_OBJECT
    public:
        OperationKeyPad(QWidget* =0);
        virtual ~OperationKeyPad() =0;
    protected:
        QPushButton* getBlend()const;
        QPushButton* getComplementary()const;
        QPushButton* getSum()const;
        QPushButton* getSubstraction()const;
        QPushButton* getMoltiplication()const;
        QPushButton* getDivision()const;
        QPushButton* getEquals()const;
        QPushButton* getCancel()const;
        QPushButton* getCancelEntry()const;
    signals:
        void blendClicked();
        void complementaryClicked();
        void sumClicked();
        void substractionClicked();
        void moltiplicationClicked();
        void divisionClicked();
        void equalsClicked();
        void cancelClicked();
        void cancelEntryClicked();
    private:
        QPushButton* blend;
        QPushButton* complementary;
        QPushButton* sum;
        QPushButton* substraction;
        QPushButton* moltiplication;
        QPushButton* division;
        QPushButton* equals;
        QPushButton* cancel;
        QPushButton* cancelEntry;
};

#endif // OPERATIONKEYPAD_H
