/*
Copyright (c) 2013-2015, SIA "Pixout". All rights reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation.

There are special exceptions to the terms and conditions of the GPL as it
is applied to this software.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA 
*/
#include "PixelMapperWithError.hpp"
#include "Common/Logger.hpp"
#include <QMessageBox>

PixelMapperWithError::PixelMapperWithError( AppSettings *settings )
    : PixelMapper(settings)
{
}

void PixelMapperWithError::Reload()
{
    if( !reload_mapping() )
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setIcon( QMessageBox::Critical );
        msgBox.setText( LOGGER.error_string() );
        msgBox.exec();
    }
}