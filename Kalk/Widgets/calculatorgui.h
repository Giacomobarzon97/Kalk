#ifndef CALCULATORGUI_H
#define CALCULATORGUI_H

#include<QWidget>
#include<QComboBox>
#include<QVBoxLayout>

#include"Displays/screen.h"
#include"ColorKeyPads/colorkeypad.h"
#include"OperationKeyPads/operationkeypad.h"

class CalculatorGUI:public QWidget{
    Q_OBJECT
    public:
        CalculatorGUI(QWidget* =0);
        CalculatorGUI(const CalculatorGUI&);
        ~CalculatorGUI();
    signals:
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
    public slots:
        void getResult(const Color&);
        void getError(std::string);
    private:
        Screen* display;
        QComboBox* comboBox;
        ColorKeyPad* colorKeyPad;
        OperationKeyPad* operationKeyPad;
        QVBoxLayout* layout;

        static std::string colorToString(const Color&);
        void keyPadsInitialization();
    private slots:
        void _blendClicked();
        void _complementaryClicked();
        void _sumClicked();
        void _substractionClicked();
        void _moltiplicationClicked();
        void _divisionClicked();
        void _equalsClicked();
        void _cancelClicked();

        void _pickRedClicked();
        void _pickGreenClicked();
        void _pickBlueClicked();
        void _pickOpacityClicked();

        void _pickCyanClicked();
        void _pickMagentaClicked();
        void _pickYellowClicked();
        void _pickKeyBlackClicked();

        void changeKeyPads(const QString&);
        void colorKeyPadValueChanged(const Color&);
        void cancelEntryClicked();
};
#endif // CALCULATORGUI_H
