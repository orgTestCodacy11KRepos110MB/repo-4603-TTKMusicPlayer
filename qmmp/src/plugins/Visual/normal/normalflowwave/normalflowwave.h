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

#ifndef NORMALFLOWWAVE_H
#define NORMALFLOWWAVE_H

#include <qmmp/visual.h>
#include "colorwidget.h"

/*!
 * @author Greedysky <greedysky@163.com>
 */
class NormalFlowWave : public Visual
{
    Q_OBJECT
public:
    explicit NormalFlowWave(QWidget *parent = nullptr);
    virtual ~NormalFlowWave();

public slots:
    virtual void start() override;
    virtual void stop() override;

private slots:
    void starTimeout();
    void readSettings();
    void writeSettings();
    void changeStarState(bool state);
    void changeStarColor();

private:
    virtual void hideEvent(QHideEvent *e) override;
    virtual void showEvent(QShowEvent *e) override;
    virtual void paintEvent(QPaintEvent *e) override;
    virtual void contextMenuEvent(QContextMenuEvent *e) override;

    virtual void process(float *left, float *right) override;
    void draw(QPainter *p);

    QAction *m_starAction;
    QColor m_starColor;
    QList<StarPoint*> m_starPoints;
    QTimer *m_starTimer;
    int *m_x_scale = nullptr;
    double m_analyzer_falloff = 2.2;
    QSize m_cell_size = QSize(15, 6);

};

#endif