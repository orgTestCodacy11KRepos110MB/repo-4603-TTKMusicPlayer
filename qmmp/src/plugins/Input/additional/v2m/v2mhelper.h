/* =================================================
 * This file is part of the TTK qmmp plugin project
 * Copyright (C) 2015 - 2021 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#ifndef V2MHELPER_H
#define V2MHELPER_H

#include <QObject>
#include "v2mplayer.h"

typedef struct {
    uint8_t *tune;
    int len;
    int bitrate;
    V2MPlayer *player;
} v2m_info_t;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class V2MHelper
{
public:
    explicit V2MHelper(const QString &path);
    ~V2MHelper();

    void close();

    bool initialize();
    int totalTime() const;
    void seek(qint64 time);

    int bitrate() const;
    int sampleRate() const;
    int channels() const;
    int bitsPerSample() const;

    int read(unsigned char *buf, int size);

private:
    QString m_path;
    v2m_info_t *m_info;
    qint64 m_totalTime = 0;

};

#endif