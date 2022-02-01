#include "decoder_bp.h"
#include "bphelper.h"

DecoderBp::DecoderBp(const QString &path)
    : Decoder()
{
    m_helper = new BpHelper(path);
}

DecoderBp::~DecoderBp()
{
    delete m_helper;
}

bool DecoderBp::initialize()
{
    if(!m_helper->initialize())
    {
        qWarning("DecoderBp: initialize failed");
        return false;
    }

    const int rate = m_helper->sampleRate();
    const int channels = m_helper->channels();
    if(rate == 0 || channels == 0)
    {
        qWarning("DecoderBp: rate or channel invalid");
        return false;
    }

    configure(rate, channels, Qmmp::PCM_U8);
    qDebug("DecoderBp: initialize success");
    return true;
}

qint64 DecoderBp::totalTime() const
{
    return m_helper->totalTime();
}

int DecoderBp::bitrate() const
{
    return m_helper->bitrate();
}

qint64 DecoderBp::read(unsigned char *data, qint64 maxSize)
{
    return m_helper->read(data, maxSize);
}

void DecoderBp::seek(qint64 time)
{
    m_helper->seek(time);
}