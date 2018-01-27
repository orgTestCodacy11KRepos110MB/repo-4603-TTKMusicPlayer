#ifndef MUSICDJRADIOTHREADABSTRACT_H
#define MUSICDJRADIOTHREADABSTRACT_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2018 Greedysky Studio

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

#include "musicdownloadwyinterface.h"
#include "musicdownloadquerythreadabstract.h"

/*! @brief The class of music dj radio thread abstract.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_NETWORK_EXPORT MusicDJRadioThreadAbstract : public MusicNetworkAbstract,
                                                        protected MusicDownLoadWYInterface
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicDJRadioThreadAbstract(QObject *parent = 0);

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Release the network object.
     */
    virtual void deleteAll() override;
    /*!
     * Get suggest list items.
     */
    inline MusicResultsItems getSearchedItems() const { return m_items; }

Q_SIGNALS:
    /*!
     * Create the current category item.
     */
    void createProgramItem(const MusicResultsItem &item);

protected:
    MusicResultsItems m_items;

};

#endif // MUSICDJRADIOTHREADABSTRACT_H