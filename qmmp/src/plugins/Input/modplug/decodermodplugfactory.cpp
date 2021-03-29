#include <QSettings>
#include <QFile>
#include <libmodplug/stdafx.h>
#include <libmodplug/it_defs.h>
#include <libmodplug/sndfile.h>
#include "modplugmetadatamodel.h"
#include "decoder_modplug.h"
#include "archivereader.h"
#include "decodermodplugfactory.h"
#include "settingsdialog.h"

bool DecoderModPlugFactory::canDecode(QIODevice *) const
{
    return false;
}

DecoderProperties DecoderModPlugFactory::properties() const
{
    DecoderProperties properties;
    properties.name = tr("ModPlug Plugin");
    properties.filters << "*.amf" << "*.ams" << "*.dbm" << "*.dbf" << "*.dsm" << "*.far" << "*.mdl";
    properties.filters << "*.stm" << "*.ult" << "*.j2b" << "*.mt2" << "*.mdz" << "*.mdr" << "*.mdgz";
    properties.filters << "*.mdbz" << "*.mod" << "*.s3z" << "*.s3r" << "*.s3gz" << "*.s3m" << "*.xmz";
    properties.filters << "*.xmr" << "*.xmgz" << "*.itz" << "*.itr" << "*.itgz" << "*.dmf" "*.umx";
    properties.filters << "*.it" << "*.669" << "*.xm" << "*.mtm" << "*.psm" << "*.ft2" << "*.med";
    properties.description = tr("ModPlug Files");
    properties.shortName = "modplug";
    properties.hasSettings = true;
    properties.noInput = true;
    properties.protocols << "file";
    return properties;
}

Decoder *DecoderModPlugFactory::create(const QString &path, QIODevice *input)
{
    Q_UNUSED(input);
    return new DecoderModPlug(path);
}

QList<TrackInfo*> DecoderModPlugFactory::createPlayList(const QString &path, TrackInfo::Parts parts, QStringList *)
{
    QList<TrackInfo*> list;
    QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
    bool useFileName = settings.value("UseFileName", false).toBool();

    QByteArray buffer;

    ArchiveReader reader(nullptr);
    if(reader.isSupported(path))
    {
        buffer = reader.unpack(path);
    }
    else
    {
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly))
        {
            qWarning("DecoderModPlugFactory: error: %s", qPrintable(file.errorString()));
            return list;
        }
        buffer = file.readAll();
        file.close();
    }

    if(!buffer.isEmpty())
    {
        CSoundFile *soundFile = new CSoundFile();
        soundFile->Create((uchar*) buffer.data(), buffer.size() + 1);

        TrackInfo *info = new TrackInfo(path);

        if(parts & TrackInfo::MetaData)
        {
            info->setValue(Qmmp::TITLE, useFileName ? path.section('/',-1) :  QString::fromUtf8(soundFile->GetTitle()));
        }

        if(parts & TrackInfo::Properties)
        {
            QSettings settings(Qmmp::configFile(), QSettings::IniFormat);
            settings.beginGroup("SID");
            const int sample_rate = settings.value("Frequency", 44100).toInt();
            const int bps = settings.value("Bits", 16).toInt();
            const int chan = settings.value("Channels", 2).toInt();
            settings.endGroup();

            info->setValue(Qmmp::BITRATE, soundFile->GetNumChannels());
            info->setValue(Qmmp::SAMPLERATE, sample_rate);
            info->setValue(Qmmp::CHANNELS, chan);
            info->setValue(Qmmp::BITS_PER_SAMPLE, bps);
            info->setValue(Qmmp::FORMAT_NAME, ModPlugMetaDataModel::getTypeName(soundFile->GetType()));
            info->setDuration((qint64)soundFile->GetSongTime() * 1000);
        }

        list << info;
        soundFile->Destroy();
        delete soundFile;
    }
    return list;
}

MetaDataModel* DecoderModPlugFactory::createMetaDataModel(const QString &path, bool readOnly)
{
    Q_UNUSED(path);
    Q_UNUSED(readOnly);
    return new ModPlugMetaDataModel(path);
}

void DecoderModPlugFactory::showSettings(QWidget *parent)
{
    SettingsDialog *s = new SettingsDialog(parent);
    s->show();
}

#ifndef QMMP_GREATER_NEW
#include <QtPlugin>
Q_EXPORT_PLUGIN2(modplug, DecoderModPlugFactory)
#endif