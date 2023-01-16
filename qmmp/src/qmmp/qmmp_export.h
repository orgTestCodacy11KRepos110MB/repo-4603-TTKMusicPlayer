/***************************************************************************
 *   Copyright (C) 2017-2023 by Ilya Kotov                                 *
 *   forkotov02@ya.ru                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#ifndef QMMP_EXPORT_H
#define QMMP_EXPORT_H

#include <QtGlobal>

#ifdef QMMP_LIBRARY
#  define QMMP_EXPORT Q_DECL_EXPORT
#else
#  define QMMP_EXPORT Q_DECL_IMPORT
#endif

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#  define Q_PLUGIN_METADATA(x)
#endif

#endif
