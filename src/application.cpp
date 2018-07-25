/******************************************************************************
*  Project: Manuscript
*  Purpose: GUI interface to prepare Sphinx documentation.
*  Author:  Dmitry Baryshnikov, dmitry.baryshnikov@nextgis.com
*******************************************************************************
*  Copyright (C) 2018 NextGIS, <info@nextgis.com>
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 2 of the License, or
*   (at your option) any later version.
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include "application.h"
#include "mainwindow.h"
#include "version.h"

MSApplication::MSApplication() :
    NGGUIApplication (APP_NAME, MANUSCRIPT_VERSION_STRING)
{

}


void MSApplication::createMainWindow()
{
    if(nullptr != m_wnd)
        return;
    m_wnd = new MSMainWindow();
    m_wnd->init();
}


void MSApplication::prepareCommandLineParser(QCommandLineParser &parser)
{
    NGGUIApplication::prepareCommandLineParser(parser);
    parser.addPositionalArgument("file",
                                 QCoreApplication::translate("CommandLine",
                                                             "The project to open."));
}

void MSApplication::processCommandLine(const QCommandLineParser &parser)
{
    QStringList arguments = parser.positionalArguments();
    if (!arguments.isEmpty()) {
        QString projectPath = arguments.first();
        MSMainWindow *wnd = static_cast<MSMainWindow *>(m_wnd);
        wnd->loadFile(projectPath);
    }
}
