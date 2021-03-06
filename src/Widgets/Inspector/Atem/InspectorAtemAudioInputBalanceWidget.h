#pragma once

#include "../../Shared.h"
#include "ui_InspectorAtemAudioInputBalanceWidget.h"

#include "AtemDevice.h"

#include "Events/Atem/AtemDeviceChangedEvent.h"
#include "Commands/Atem/AtemAudioInputBalanceCommand.h"
#include "Events/Rundown/RundownItemSelectedEvent.h"
#include "Models/LibraryModel.h"

#include "qatemtypes.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>

#include <QtWidgets/QWidget>

class WIDGETS_EXPORT InspectorAtemAudioInputBalanceWidget : public QWidget, Ui::InspectorAtemAudioInputBalanceWidget
{
    Q_OBJECT

    public:
        explicit InspectorAtemAudioInputBalanceWidget(QWidget* parent = 0);

    private:
        LibraryModel* model;
        AtemAudioInputBalanceCommand* command;
        QMap<quint16, QAtem::InputInfo> inputs;

        void checkEmptyInput();
        void blockAllSignals(bool block);
        void loadAtemAudioInput();

        Q_SLOT void inputChanged(int);
        Q_SLOT void sliderBalanceChanged(int);
        Q_SLOT void doubleSpinBoxBalanceChanged(double);
        Q_SLOT void triggerOnNextChanged(int);
        Q_SLOT void rundownItemSelected(const RundownItemSelectedEvent&);
        Q_SLOT void atemDeviceChanged(const AtemDeviceChangedEvent&);
};
