#ifndef MUSITEXTSLIDERWIDGET_H
#define MUSITEXTSLIDERWIDGET_H

/* =================================================
 * This file is part of the TTK Music Player project
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

#include <QWidget>
#include "musicglobaldefine.h"

/*! @brief The class of the text slider widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicTextSliderWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicTextSliderWidget)
public:
    /*!
     * Object contsructor.
     */
    explicit MusicTextSliderWidget(QWidget *parent = nullptr);

    ~MusicTextSliderWidget();

    /*!
     * Set max value.
     */
    void setMaxValue(int max);
    /*!
     * Set current value.
     */
    void setValue(int value);
    /*!
     * Set front text value.
     */
    void setFrontText(const QString &text);
    /*!
     * Set back text value.
     */
    void setBackText(const QString &text);

protected:
    /*!
     * Override the widget event.
     */
    virtual void paintEvent(QPaintEvent *event) override;

    int m_maxValue, m_currentValue;
    QString m_frontText, m_backText;

};

#endif // MUSITEXTSLIDERWIDGET_H