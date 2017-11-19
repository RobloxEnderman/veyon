/*
 * VeyonServiceControl.cpp - class for controlling Veyon service
 *
 * Copyright (c) 2017 Tobias Junghans <tobydox@users.sf.net>
 *
 * This file is part of Veyon - http://veyon.io
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#include <QCoreApplication>
#include <QDir>

#include "PlatformCoreFunctions.h"
#include "PlatformServiceFunctions.h"
#include "VeyonServiceControl.h"


VeyonServiceControl::VeyonServiceControl( QWidget* parent ) :
	ServiceControl( name(), filePath(), arguments(), displayName(), parent )
{
}



bool VeyonServiceControl::setAutostart( bool enabled )
{
	return VeyonCore::platform().serviceFunctions().
			setStartMode( name(), enabled ? PlatformServiceFunctions::StartModeAuto :
											PlatformServiceFunctions::StartModeManual );
}



bool VeyonServiceControl::setExtraArguments( const QString& extraArguments )
{
	return VeyonCore::platform().serviceFunctions().
			setFilePathAndArguments( name(), filePath(), arguments() + ' ' + extraArguments );
}



QString VeyonServiceControl::name()
{
	return QStringLiteral( "VeyonService" );
}



QString VeyonServiceControl::filePath()
{
	return QDir::toNativeSeparators(
				QCoreApplication::applicationDirPath() +
				QDir::separator() +
				QStringLiteral("veyon-service") +
				VeyonCore::platform().coreFunctions().programFileExtension() );
}



QString VeyonServiceControl::arguments()
{
	return QStringLiteral( "-service" );
}



QString VeyonServiceControl::displayName()
{
	return tr( "Veyon Service" );
}
