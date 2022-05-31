/*----- PROTECTED REGION ID(TangoTest::ClassFactory.cpp) ENABLED START -----*/
//+=============================================================================
//
// file :        ClassFactory.cpp
//
// description : C++ source for the class_factory method of the DServer
//               device class. This method is responsible to create
//               all class singletin for a device server. It is called
//               at device server startup
//
// project :     TANGO Device Server
//
// $Author$
//
// Copyright (C) :      2004,2005,2006,2007,2008,2009,2010
//						Synchrotron SOLEIL
//                		L'Orme des Merisiers
//                		Saint-Aubin - BP 48 - France
//
// This file is part of Tango.
//
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
//
// $Revision$
//
// $Log$
// Revision 1.5  2007/12/11 19:07:52  nleclercq
// added a "no_value" and a "throw_exception" attribute
//
// Revision 1.6  2006/05/17 17:07:53  leclercq
// Update NL du 17.05.06 (Tango 5.4.2)
//
// Revision 1.4  2006/02/08 16:14:26  nleclercq
// Minor modifs in RW spectrum and image attributes
//
//-=============================================================================
//
//  		This file is generated by POGO
//	(Program Obviously used to Generate tango Object)
//
//         (c) - Software Engineering Group - ESRF
//=============================================================================


#include <tango.h>
#include <TangoTestClass.h>

/**
 *	Create TangoTestClass singleton and store it in DServer object.
 */

void Tango::DServer::class_factory()
{

	add_class(TangoTest_ns::TangoTestClass::init("TangoTest"));

}
/*----- PROTECTED REGION END -----*/	//	TangoTest::ClassFactory.cpp
