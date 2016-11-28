#pragma once

#include "../../Shared.h"
#include "../AbstractCommand.h"

#include "Global.h"

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <QtCore/QString>

class QObject;
class QXmlStreamWriter;

class CORE_EXPORT AtemAudioGainCommand: public AbstractCommand
{
    Q_OBJECT

    public:
        explicit AtemAudioGainCommand(QObject* parent = 0);

        virtual void readProperties(boost::property_tree::wptree& pt);
        virtual void writeProperties(QXmlStreamWriter& writer);

        const QString& getInput() const;
        float getGain() const;
        bool getTriggerOnNext() const;

        void setInput(const QString& input);
        void setGain(float gain);
        void setTriggerOnNext(bool triggerOnNext);

    private:
        QString input = Atem::DEFAULT_AUDIO_INPUT;
        float gain = Atem::DEFAULT_AUDIO_GAIN;
        bool triggerOnNext = Atem::DEFAULT_TRIGGER_ON_NEXT;

        Q_SIGNAL void inputChanged(const QString&);
        Q_SIGNAL void gainChanged(float);
        Q_SIGNAL void triggerOnNextChanged(bool);
};
