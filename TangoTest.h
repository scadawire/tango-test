/*----- PROTECTED REGION ID(TangoTest.h) ENABLED START -----*/
//=============================================================================
//
// file :        TangoTest.h
//
// description : Include file for the TangoTest class
//
// project :     TANGO Device Server for testing generic clients
//
// This file is part of Tango device class.
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
// $Author$
//
// $Revision$
// $Date$
//
// $HeadURL:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#ifndef TangoTest_H
#define TangoTest_H

#include <tango.h>



#ifndef TANGO_UNUSED
	#ifdef _TG_WINDOWS_
		#define TANGO_UNUSED(var) var
	#else
		#if __GNUC__ == 3 && __GNUC_MINOR__ >= 4
			#define TANGO_UNUSED(var) var __attribute__ ((unused))
		#elif __GNUC__ > 3
			#define TANGO_UNUSED(var) var __attribute__ ((unused))
		#else
			#define TANGO_UNUSED(var) var
		#endif
	#endif
#endif


/*----- PROTECTED REGION END -----*/	//	TangoTest.h

/**
 *  TangoTest class description:
 *    A device to test generic clients. It offers a \"echo\" like command for
 *    each TANGO data type (i.e. each command returns an exact copy of <argin>).
 */

namespace TangoTest_ns
{
enum _enum_scalarEnum {
	_LABEL0,
	_LABEL1,
	_LABEL2,
} ;
typedef _enum_scalarEnum enum_scalarEnum;

enum _enum_scalar_roEnum {
	_LABEL3,
	_LABEL4,
	_LABEL5,
} ;
typedef _enum_scalar_roEnum enum_scalar_roEnum;

enum _enum_spectrumEnum {
	_LABEL6,
	_LABEL7,
	_LABEL8,
} ;
typedef _enum_spectrumEnum enum_spectrumEnum;

enum _enum_spectrum_roEnum {
	_LABEL9,
	_LABEL10,
	_LABEL11,
} ;
typedef _enum_spectrum_roEnum enum_spectrum_roEnum;

enum _enum_image_roEnum {
	_LABEL12,
	_LABEL13,
	_LABEL14,
} ;
typedef _enum_image_roEnum enum_image_roEnum;

enum _enum_imageEnum {
	_LABEL15,
	_LABEL16,
	_LABEL17,
} ;
typedef _enum_imageEnum enum_imageEnum;

/*----- PROTECTED REGION ID(TangoTest::Additional Class Declarations) ENABLED START -----*/

//	Additional Class Declarations
class DataGenerator;
}

namespace TangoTest_ns
{

/*----- PROTECTED REGION END -----*/	//	TangoTest::Additional Class Declarations

class TangoTest : public TANGO_BASE_CLASS
{

/*----- PROTECTED REGION ID(TangoTest::Data Members) ENABLED START -----*/

//	Add your own data members
public:

	friend class DataGenerator;

	Tango::DevShort    attr_short_scalar_w_write;
	Tango::DevLong     attr_long_scalar_w_write;
	Tango::DevDouble   attr_double_scalar_w_write;
	Tango::DevShort    attr_short_scalar_write;
	Tango::DevLong     attr_long_scalar_write;
	Tango::DevDouble   attr_double_scalar_write;
	Tango::DevFloat    attr_float_scalar_write;
	Tango::DevULong    attr_ulong_scalar_write;
	Tango::DevUShort   attr_ushort_scalar_write;
	Tango::DevUChar    attr_uchar_scalar_write;
	enum_scalar_roEnum attr_enum_scalar_write;
	Tango::DevDouble   attr_ampli_write;
    Tango::DevDouble	attr_freq_write;
	Tango::DevLong64   attr_long64_scalar_write;
	Tango::DevULong64  attr_ulong64_scalar_write;
	Tango::DevString   attr_string_scalar_write;
	Tango::DevBoolean  attr_boolean_scalar_write;

	Tango::DevString	attr_string_spectrum_write;
	enum_spectrumEnum attr_enum_spectrum_write;

	Tango::DevString	attr_string_image_write;
	enum_imageEnum attr_enum_image_write;

    std::string         pi_str;
    Tango::DevLong      pi_long;
    Tango::DevShort     pi_short;

	Tango::DevBoolean	generic_blob_rw_has_value = false;
	Tango::DevicePipeBlob	generic_blob_rw_data;

/*----- PROTECTED REGION END -----*/	//	TangoTest::Data Members

//	Device property data members
public:
	//	Mthreaded_impl:	Multi-threaded implementation (true/false
	Tango::DevShort	mthreaded_impl;
	//	Sleep_period:	Data generation period (in ms
	Tango::DevLong	sleep_period;
	//	UShort_image_ro_size:	Size of the ushort_image_ro attribute
	Tango::DevLong	uShort_image_ro_size;

//	Attribute data members
public:
	Tango::DevBoolean	*attr_boolean_scalar_read;
	Tango::DevDouble	*attr_double_scalar_read;
	Tango::DevDouble	*attr_double_scalar_rww_read;
	Tango::DevFloat	*attr_float_scalar_read;
	Tango::DevLong64	*attr_long64_scalar_read;
	Tango::DevLong	*attr_long_scalar_read;
	Tango::DevLong	*attr_long_scalar_rww_read;
	Tango::DevLong	*attr_no_value_read;
	Tango::DevShort	*attr_short_scalar_read;
	Tango::DevShort	*attr_short_scalar_ro_read;
	Tango::DevShort	*attr_short_scalar_rww_read;
	Tango::DevString	*attr_string_scalar_read;
	Tango::DevLong	*attr_throw_exception_read;
	Tango::DevUChar	*attr_uchar_scalar_read;
	Tango::DevULong64	*attr_ulong64_scalar_read;
	Tango::DevUShort	*attr_ushort_scalar_read;
	Tango::DevULong	*attr_ulong_scalar_read;
	enum_scalarEnum	*attr_enum_scalar_read;
	enum_scalar_roEnum	*attr_enum_scalar_ro_read;
	Tango::DevBoolean	*attr_boolean_spectrum_read;
	Tango::DevBoolean	*attr_boolean_spectrum_ro_read;
	Tango::DevDouble	*attr_double_spectrum_read;
	Tango::DevDouble	*attr_double_spectrum_ro_read;
	Tango::DevFloat	*attr_float_spectrum_read;
	Tango::DevFloat	*attr_float_spectrum_ro_read;
	Tango::DevLong64	*attr_long64_spectrum_ro_read;
	Tango::DevLong	*attr_long_spectrum_read;
	Tango::DevLong	*attr_long_spectrum_ro_read;
	Tango::DevShort	*attr_short_spectrum_read;
	Tango::DevShort	*attr_short_spectrum_ro_read;
	Tango::DevString	*attr_string_spectrum_read;
	Tango::DevString	*attr_string_spectrum_ro_read;
	Tango::DevUChar	*attr_uchar_spectrum_read;
	Tango::DevUChar	*attr_uchar_spectrum_ro_read;
	Tango::DevULong64	*attr_ulong64_spectrum_ro_read;
	Tango::DevULong	*attr_ulong_spectrum_ro_read;
	Tango::DevUShort	*attr_ushort_spectrum_read;
	Tango::DevUShort	*attr_ushort_spectrum_ro_read;
	Tango::DevDouble	*attr_wave_read;
	enum_spectrumEnum	*attr_enum_spectrum_read;
	enum_spectrum_roEnum	*attr_enum_spectrum_ro_read;
	Tango::DevBoolean	*attr_boolean_image_read;
	Tango::DevBoolean	*attr_boolean_image_ro_read;
	Tango::DevDouble	*attr_double_image_read;
	Tango::DevDouble	*attr_double_image_ro_read;
	Tango::DevFloat	*attr_float_image_read;
	Tango::DevFloat	*attr_float_image_ro_read;
	Tango::DevLong64	*attr_long64_image_ro_read;
	Tango::DevLong	*attr_long_image_read;
	Tango::DevLong	*attr_long_image_ro_read;
	Tango::DevShort	*attr_short_image_read;
	Tango::DevShort	*attr_short_image_ro_read;
	Tango::DevString	*attr_string_image_read;
	Tango::DevString	*attr_string_image_ro_read;
	Tango::DevUChar	*attr_uchar_image_read;
	Tango::DevUChar	*attr_uchar_image_ro_read;
	Tango::DevULong64	*attr_ulong64_image_ro_read;
	Tango::DevULong	*attr_ulong_image_ro_read;
	Tango::DevUShort	*attr_ushort_image_read;
	Tango::DevUShort	*attr_ushort_image_ro_read;
	enum_image_roEnum	*attr_enum_image_ro_read;
	enum_imageEnum	*attr_enum_image_read;

//	Constructors and destructors
public:
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	TangoTest(Tango::DeviceClass *cl,std::string &s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device Name
	 */
	TangoTest(Tango::DeviceClass *cl,const char *s);
	/**
	 * Constructs a newly device object.
	 *
	 *	@param cl	Class.
	 *	@param s 	Device name
	 *	@param d	Device description.
	 */
	TangoTest(Tango::DeviceClass *cl,const char *s,const char *d);
	/**
	 * The device object destructor.
	 */
	~TangoTest() {delete_device();};


//	Miscellaneous methods
public:
	/*
	 *	will be called at device destruction or at init command.
	 */
	void delete_device();
	/*
	 *	Initialize the device
	 */
	virtual void init_device();
	/*
	 *	Read the device properties from database
	 */
	void get_device_property();
	/*
	 *	Always executed method before execution command method.
	 */
	virtual void always_executed_hook();


//	Attribute methods
public:
	//--------------------------------------------------------
	/*
	 *	Method      : TangoTest::read_attr_hardware()
	 *	Description : Hardware acquisition for attributes.
	 */
	//--------------------------------------------------------
	virtual void read_attr_hardware(std::vector<long> &attr_list);
	//--------------------------------------------------------
	/*
	 *	Method      : TangoTest::write_attr_hardware()
	 *	Description : Hardware writing for attributes.
	 */
	//--------------------------------------------------------
	virtual void write_attr_hardware(std::vector<long> &attr_list);

/**
 *	Attribute ampli related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void write_ampli(Tango::WAttribute &attr);
	virtual bool is_ampli_allowed(Tango::AttReqType type);
/**
 *	Attribute boolean_scalar related methods
 *	Description: A boolean scalar attribute
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Scalar
 */
	virtual void read_boolean_scalar(Tango::Attribute &attr);
	virtual void write_boolean_scalar(Tango::WAttribute &attr);
	virtual bool is_boolean_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute double_scalar related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_double_scalar(Tango::Attribute &attr);
	virtual void write_double_scalar(Tango::WAttribute &attr);
	virtual bool is_double_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute double_scalar_rww related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void read_double_scalar_rww(Tango::Attribute &attr);
	virtual void write_double_scalar_rww(Tango::WAttribute &attr);
	virtual bool is_double_scalar_rww_allowed(Tango::AttReqType type);
/**
 *	Attribute double_scalar_w related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void write_double_scalar_w(Tango::WAttribute &attr);
	virtual bool is_double_scalar_w_allowed(Tango::AttReqType type);
/**
 *	Attribute float_scalar related methods
 *	Description: A float attribute
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Scalar
 */
	virtual void read_float_scalar(Tango::Attribute &attr);
	virtual void write_float_scalar(Tango::WAttribute &attr);
	virtual bool is_float_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute long64_scalar related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong64
 *	Attr type:	Scalar
 */
	virtual void read_long64_scalar(Tango::Attribute &attr);
	virtual void write_long64_scalar(Tango::WAttribute &attr);
	virtual bool is_long64_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute long_scalar related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_long_scalar(Tango::Attribute &attr);
	virtual void write_long_scalar(Tango::WAttribute &attr);
	virtual bool is_long_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute long_scalar_rww related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_long_scalar_rww(Tango::Attribute &attr);
	virtual void write_long_scalar_rww(Tango::WAttribute &attr);
	virtual bool is_long_scalar_rww_allowed(Tango::AttReqType type);
/**
 *	Attribute long_scalar_w related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void write_long_scalar_w(Tango::WAttribute &attr);
	virtual bool is_long_scalar_w_allowed(Tango::AttReqType type);
/**
 *	Attribute no_value related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_no_value(Tango::Attribute &attr);
	virtual bool is_no_value_allowed(Tango::AttReqType type);
/**
 *	Attribute short_scalar related methods
 *	Description: 
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Scalar
 */
	virtual void read_short_scalar(Tango::Attribute &attr);
	virtual void write_short_scalar(Tango::WAttribute &attr);
	virtual bool is_short_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute short_scalar_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Scalar
 */
	virtual void read_short_scalar_ro(Tango::Attribute &attr);
	virtual bool is_short_scalar_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute short_scalar_rww related methods
 *	Description: 
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Scalar
 */
	virtual void read_short_scalar_rww(Tango::Attribute &attr);
	virtual void write_short_scalar_rww(Tango::WAttribute &attr);
	virtual bool is_short_scalar_rww_allowed(Tango::AttReqType type);
/**
 *	Attribute short_scalar_w related methods
 *	Description: 
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Scalar
 */
	virtual void write_short_scalar_w(Tango::WAttribute &attr);
	virtual bool is_short_scalar_w_allowed(Tango::AttReqType type);
/**
 *	Attribute string_scalar related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar
 */
	virtual void read_string_scalar(Tango::Attribute &attr);
	virtual void write_string_scalar(Tango::WAttribute &attr);
	virtual bool is_string_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute throw_exception related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Scalar
 */
	virtual void read_throw_exception(Tango::Attribute &attr);
	virtual bool is_throw_exception_allowed(Tango::AttReqType type);
/**
 *	Attribute uchar_scalar related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUChar
 *	Attr type:	Scalar
 */
	virtual void read_uchar_scalar(Tango::Attribute &attr);
	virtual void write_uchar_scalar(Tango::WAttribute &attr);
	virtual bool is_uchar_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute ulong64_scalar related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong64
 *	Attr type:	Scalar
 */
	virtual void read_ulong64_scalar(Tango::Attribute &attr);
	virtual void write_ulong64_scalar(Tango::WAttribute &attr);
	virtual bool is_ulong64_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute ushort_scalar related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Scalar
 */
	virtual void read_ushort_scalar(Tango::Attribute &attr);
	virtual void write_ushort_scalar(Tango::WAttribute &attr);
	virtual bool is_ushort_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute ulong_scalar related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Scalar
 */
	virtual void read_ulong_scalar(Tango::Attribute &attr);
	virtual void write_ulong_scalar(Tango::WAttribute &attr);
	virtual bool is_ulong_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute enum_scalar related methods
 *	Description:
 *
 *	Data type:	Tango::DevEnum
 *	Attr type:	Scalar
 */
	virtual void read_enum_scalar(Tango::Attribute &attr);
	virtual void write_enum_scalar(Tango::WAttribute &attr);
	virtual bool is_enum_scalar_allowed(Tango::AttReqType type);
/**
 *	Attribute freq related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar
 */
	virtual void write_freq(Tango::WAttribute &attr);
	virtual bool is_freq_allowed(Tango::AttReqType type);
/**
 *	Attribute enum_scalar_ro related methods
 *	Description:
 *
 *	Data type:	Tango::DevEnum
 *	Attr type:	Scalar
 */
	virtual void read_enum_scalar_ro(Tango::Attribute &attr);
	virtual bool is_enum_scalar_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute boolean_spectrum related methods
 *	Description: 
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_boolean_spectrum(Tango::Attribute &attr);
	virtual void write_boolean_spectrum(Tango::WAttribute &attr);
	virtual bool is_boolean_spectrum_allowed(Tango::AttReqType type);
/**
 *	Attribute boolean_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_boolean_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_boolean_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute double_spectrum related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_double_spectrum(Tango::Attribute &attr);
	virtual void write_double_spectrum(Tango::WAttribute &attr);
	virtual bool is_double_spectrum_allowed(Tango::AttReqType type);
/**
 *	Attribute double_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_double_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_double_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute float_spectrum related methods
 *	Description: A float spectrum attribute
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_float_spectrum(Tango::Attribute &attr);
	virtual void write_float_spectrum(Tango::WAttribute &attr);
	virtual bool is_float_spectrum_allowed(Tango::AttReqType type);
/**
 *	Attribute float_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_float_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_float_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute long64_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong64
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_long64_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_long64_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute long_spectrum related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_long_spectrum(Tango::Attribute &attr);
	virtual void write_long_spectrum(Tango::WAttribute &attr);
	virtual bool is_long_spectrum_allowed(Tango::AttReqType type);
/**
 *	Attribute long_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_long_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_long_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute short_spectrum related methods
 *	Description: 
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_short_spectrum(Tango::Attribute &attr);
	virtual void write_short_spectrum(Tango::WAttribute &attr);
	virtual bool is_short_spectrum_allowed(Tango::AttReqType type);
/**
 *	Attribute short_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_short_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_short_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute string_spectrum related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 256
 */
	virtual void read_string_spectrum(Tango::Attribute &attr);
	virtual void write_string_spectrum(Tango::WAttribute &attr);
	virtual bool is_string_spectrum_allowed(Tango::AttReqType type);
/**
 *	Attribute string_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Spectrum max = 256
 */
	virtual void read_string_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_string_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute uchar_spectrum related methods
 *	Description: An unsigned char spectrum attribute
 *
 *	Data type:	Tango::DevUChar
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_uchar_spectrum(Tango::Attribute &attr);
	virtual void write_uchar_spectrum(Tango::WAttribute &attr);
	virtual bool is_uchar_spectrum_allowed(Tango::AttReqType type);
/**
 *	Attribute uchar_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUChar
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_uchar_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_uchar_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute ulong64_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong64
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_ulong64_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_ulong64_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute ulong_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_ulong_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_ulong_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute ushort_spectrum related methods
 *	Description: An unsigned short spectrum attribute
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_ushort_spectrum(Tango::Attribute &attr);
	virtual void write_ushort_spectrum(Tango::WAttribute &attr);
	virtual bool is_ushort_spectrum_allowed(Tango::AttReqType type);
/**
 *	Attribute ushort_spectrum_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_ushort_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_ushort_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute wave related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_wave(Tango::Attribute &attr);
	virtual bool is_wave_allowed(Tango::AttReqType type);
/**
 *	Attribute enum_spectrum related methods
 *	Description:
 *
 *	Data type:	Tango::DevEnum
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_enum_spectrum(Tango::Attribute &attr);
	virtual void write_enum_spectrum(Tango::WAttribute &attr);
	virtual bool is_enum_spectrum_allowed(Tango::AttReqType type);
/**
 *	Attribute enum_spectrum_ro related methods
 *	Description:
 *
 *	Data type:	Tango::DevEnum
 *	Attr type:	Spectrum max = 4096
 */
	virtual void read_enum_spectrum_ro(Tango::Attribute &attr);
	virtual bool is_enum_spectrum_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute boolean_image related methods
 *	Description: 
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_boolean_image(Tango::Attribute &attr);
	virtual void write_boolean_image(Tango::WAttribute &attr);
	virtual bool is_boolean_image_allowed(Tango::AttReqType type);
/**
 *	Attribute boolean_image_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevBoolean
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_boolean_image_ro(Tango::Attribute &attr);
	virtual bool is_boolean_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute double_image related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_double_image(Tango::Attribute &attr);
	virtual void write_double_image(Tango::WAttribute &attr);
	virtual bool is_double_image_allowed(Tango::AttReqType type);
/**
 *	Attribute double_image_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_double_image_ro(Tango::Attribute &attr);
	virtual bool is_double_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute float_image related methods
 *	Description: 
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_float_image(Tango::Attribute &attr);
	virtual void write_float_image(Tango::WAttribute &attr);
	virtual bool is_float_image_allowed(Tango::AttReqType type);
/**
 *	Attribute float_image_ro related methods
 *	Description: A float image attribute
 *
 *	Data type:	Tango::DevFloat
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_float_image_ro(Tango::Attribute &attr);
	virtual bool is_float_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute long64_image_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong64
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_long64_image_ro(Tango::Attribute &attr);
	virtual bool is_long64_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute long_image related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_long_image(Tango::Attribute &attr);
	virtual void write_long_image(Tango::WAttribute &attr);
	virtual bool is_long_image_allowed(Tango::AttReqType type);
/**
 *	Attribute long_image_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevLong
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_long_image_ro(Tango::Attribute &attr);
	virtual bool is_long_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute short_image related methods
 *	Description: 
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_short_image(Tango::Attribute &attr);
	virtual void write_short_image(Tango::WAttribute &attr);
	virtual bool is_short_image_allowed(Tango::AttReqType type);
/**
 *	Attribute short_image_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevShort
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_short_image_ro(Tango::Attribute &attr);
	virtual bool is_short_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute string_image related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Image max = 256 x 256
 */
	virtual void read_string_image(Tango::Attribute &attr);
	virtual void write_string_image(Tango::WAttribute &attr);
	virtual bool is_string_image_allowed(Tango::AttReqType type);
/**
 *	Attribute string_image_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Image max = 256 x 256
 */
	virtual void read_string_image_ro(Tango::Attribute &attr);
	virtual bool is_string_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute uchar_image related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUChar
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_uchar_image(Tango::Attribute &attr);
	virtual void write_uchar_image(Tango::WAttribute &attr);
	virtual bool is_uchar_image_allowed(Tango::AttReqType type);
/**
 *	Attribute uchar_image_ro related methods
 *	Description: An unsigned char image attribute
 *
 *	Data type:	Tango::DevUChar
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_uchar_image_ro(Tango::Attribute &attr);
	virtual bool is_uchar_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute ulong64_image_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong64
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_ulong64_image_ro(Tango::Attribute &attr);
	virtual bool is_ulong64_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute ulong_image_ro related methods
 *	Description: 
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_ulong_image_ro(Tango::Attribute &attr);
	virtual bool is_ulong_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute ushort_image related methods
 *	Description: 
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_ushort_image(Tango::Attribute &attr);
	virtual void write_ushort_image(Tango::WAttribute &attr);
	virtual bool is_ushort_image_allowed(Tango::AttReqType type);
/**
 *	Attribute ushort_image_ro related methods
 *	Description: An unsigned short image attribute
 *
 *	Data type:	Tango::DevUShort
 *	Attr type:	Image max = 8192 x 8192
 */
	virtual void read_ushort_image_ro(Tango::Attribute &attr);
	virtual bool is_ushort_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute enum_image_ro related methods
 *	Description:
 *
 *	Data type:	Tango::DevEnum
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_enum_image_ro(Tango::Attribute &attr);
	virtual bool is_enum_image_ro_allowed(Tango::AttReqType type);
/**
 *	Attribute enum_image related methods
 *	Description:
 *
 *	Data type:	Tango::DevEnum
 *	Attr type:	Image max = 251 x 251
 */
	virtual void read_enum_image(Tango::Attribute &attr);
	virtual void write_enum_image(Tango::WAttribute &attr);
	virtual bool is_enum_image_allowed(Tango::AttReqType type);


	//--------------------------------------------------------
	/**
	 *	Method      : TangoTest::add_dynamic_attributes()
	 *	Description : Add dynamic attributes if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_attributes();



//	pipe related methods
public:
	//	Pipe string_long_short_ro
	bool is_string_long_short_ro_allowed(Tango::PipeReqType);
	void read_string_long_short_ro(Tango::Pipe &);
	//	Pipe generic_blob_rw
	bool is_generic_blob_rw_allowed(Tango::PipeReqType);
	void read_generic_blob_rw(Tango::Pipe &);
	void write_generic_blob_rw(Tango::WPipe &);

//	Command related methods
public:
	/**
	 *	Command CrashFromDevelopperThread related method
	 *	Description: Crashes the device!
	 *
	 */
	virtual void crash_from_developper_thread();
	virtual bool is_CrashFromDevelopperThread_allowed(const CORBA::Any &any);
	/**
	 *	Command CrashFromOmniThread related method
	 *	Description: Crashes the device!
	 *
	 */
	virtual void crash_from_omni_thread();
	virtual bool is_CrashFromOmniThread_allowed(const CORBA::Any &any);
	/**
	 *	Command DevBoolean related method
	 *	Description: A DevBoolean comand example
	 *
	 *	@param argin Any boolean value
	 *	@returns Echo of the argin value
	 */
	virtual Tango::DevBoolean dev_boolean(Tango::DevBoolean argin);
	virtual bool is_DevBoolean_allowed(const CORBA::Any &any);
	/**
	 *	Command DevDouble related method
	 *	Description: A DevDouble command example
	 *
	 *	@param argin Any DevDouble value
	 *	@returns Echo of the argin value
	 */
	virtual Tango::DevDouble dev_double(Tango::DevDouble argin);
	virtual bool is_DevDouble_allowed(const CORBA::Any &any);
	/**
	 *	Command DevFloat related method
	 *	Description: A DevFloat command example
	 *
	 *	@param argin Any DevFloat value
	 *	@returns Echo of the argin value
	 */
	virtual Tango::DevFloat dev_float(Tango::DevFloat argin);
	virtual bool is_DevFloat_allowed(const CORBA::Any &any);
	/**
	 *	Command DevLong related method
	 *	Description: A DevLong command example
	 *
	 *	@param argin Any DevLong value
	 *	@returns Echo of the argin value
	 */
	virtual Tango::DevLong dev_long(Tango::DevLong argin);
	virtual bool is_DevLong_allowed(const CORBA::Any &any);
	/**
	 *	Command DevLong64 related method
	 *	Description: A DevLong command example
	 *
	 *	@param argin Any DevLong64 value
	 *	@returns Echo of the argin value
	 */
	virtual Tango::DevLong64 dev_long64(Tango::DevLong64 argin);
	virtual bool is_DevLong64_allowed(const CORBA::Any &any);
	/**
	 *	Command DevShort related method
	 *	Description: A DevShort command example
	 *
	 *	@param argin Any DevShort value
	 *	@returns Echo of the argin value
	 */
	virtual Tango::DevShort dev_short(Tango::DevShort argin);
	virtual bool is_DevShort_allowed(const CORBA::Any &any);
	/**
	 *	Command DevString related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevString dev_string(Tango::DevString argin);
	virtual bool is_DevString_allowed(const CORBA::Any &any);
	/**
	 *	Command DevULong related method
	 *	Description: A DevULong command example
	 *
	 *	@param argin Any DevULong
	 *	@returns Echo of the argin value
	 */
	virtual Tango::DevULong dev_ulong(Tango::DevULong argin);
	virtual bool is_DevULong_allowed(const CORBA::Any &any);
	/**
	 *	Command DevULong64 related method
	 *	Description: A DevULong64 command example
	 *
	 *	@param argin Any DevULong64 value
	 *	@returns Echo of the argin value
	 */
	virtual Tango::DevULong64 dev_ulong64(Tango::DevULong64 argin);
	virtual bool is_DevULong64_allowed(const CORBA::Any &any);
	/**
	 *	Command DevUShort related method
	 *	Description: A DevUShort command example
	 *
	 *	@param argin Any DevUShort value
	 *	@returns Echo of the argin value
	 */
	virtual Tango::DevUShort dev_ushort(Tango::DevUShort argin);
	virtual bool is_DevUShort_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarCharArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarCharArray *dev_var_char_array(const Tango::DevVarCharArray *argin);
	virtual bool is_DevVarCharArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarDoubleArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarDoubleArray *dev_var_double_array(const Tango::DevVarDoubleArray *argin);
	virtual bool is_DevVarDoubleArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarDoubleStringArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarDoubleStringArray *dev_var_double_string_array(const Tango::DevVarDoubleStringArray *argin);
	virtual bool is_DevVarDoubleStringArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarFloatArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarFloatArray *dev_var_float_array(const Tango::DevVarFloatArray *argin);
	virtual bool is_DevVarFloatArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarLong64Array related method
	 *	Description: 
	 *
	 *	@param argin 
	 *	@returns 
	 */
	virtual Tango::DevVarLong64Array *dev_var_long64_array(const Tango::DevVarLong64Array *argin);
	virtual bool is_DevVarLong64Array_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarLongArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarLongArray *dev_var_long_array(const Tango::DevVarLongArray *argin);
	virtual bool is_DevVarLongArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarLongStringArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarLongStringArray *dev_var_long_string_array(const Tango::DevVarLongStringArray *argin);
	virtual bool is_DevVarLongStringArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarShortArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarShortArray *dev_var_short_array(const Tango::DevVarShortArray *argin);
	virtual bool is_DevVarShortArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarStringArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarStringArray *dev_var_string_array(const Tango::DevVarStringArray *argin);
	virtual bool is_DevVarStringArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarULong64Array related method
	 *	Description: 
	 *
	 *	@param argin 
	 *	@returns 
	 */
	virtual Tango::DevVarULong64Array *dev_var_ulong64_array(const Tango::DevVarULong64Array *argin);
	virtual bool is_DevVarULong64Array_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarULongArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarULongArray *dev_var_ulong_array(const Tango::DevVarULongArray *argin);
	virtual bool is_DevVarULongArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVarUShortArray related method
	 *	Description: none
	 *
	 *	@param argin -
	 *	@returns -
	 */
	virtual Tango::DevVarUShortArray *dev_var_ushort_array(const Tango::DevVarUShortArray *argin);
	virtual bool is_DevVarUShortArray_allowed(const CORBA::Any &any);
	/**
	 *	Command DevVoid related method
	 *	Description: A DevVoid comand example
	 *
	 */
	virtual void dev_void();
	virtual bool is_DevVoid_allowed(const CORBA::Any &any);
	/**
	 *	Command DumpExecutionState related method
	 *	Description: Forces mini dump generation
	 *
	 */
	virtual void dump_execution_state();
	virtual bool is_DumpExecutionState_allowed(const CORBA::Any &any);
	/**
	 *	Command SwitchStates related method
	 *	Description: This command changes the device state from RUNNING to FAULT or from FAULT to RUNNING
	 *
	 */
	virtual void switch_states();
	virtual bool is_SwitchStates_allowed(const CORBA::Any &any);


	//--------------------------------------------------------
	/**
	 *	Method      : TangoTest::add_dynamic_commands()
	 *	Description : Add dynamic commands if any.
	 */
	//--------------------------------------------------------
	void add_dynamic_commands();

/*----- PROTECTED REGION ID(TangoTest::Additional Method prototypes) ENABLED START -----*/

//	Additional Method prototypes
/**
 *	Generates dummy attribute values
 */
  void gen_data (void);

protected :
  //- A mutex to protect the device against race conditions
  omni_mutex lock;
  // Mutexes to protec images attributes filled in by thread
  omni_mutex boolean_image_lock;
  omni_mutex double_image_lock;
  omni_mutex float_image_lock;
  omni_mutex long64_image_lock;
  omni_mutex long_image_lock;
  omni_mutex short_image_lock;
  omni_mutex uchar_image_lock;
  omni_mutex ulong64_image_lock;
  omni_mutex ulong_image_lock;
  omni_mutex ushort_image_lock;
  omni_mutex enum_image_lock;
  // The data generator (thread)
  DataGenerator * data_gen;

  long dimShortSpectrum;
  long dimLongSpectrum;
  long dimUcharSpectrum;
  long dimUshortSpectrum;
  long dimDoubleSpectrum;
  long dimFloatSpectrum;
  long dimBooleanSpectrum;
  long dimStringSpectrum;
  long dimEnumSpectrum;

  long dimXShortImage;
  long dimXLongImage;
  long dimXFloatImage;
  long dimXUcharImage;
  long dimXUshortImage;
  long dimXDoubleImage;
  long dimXBooleanImage;
  long dimXStringImage;
  long dimXenumImage;

  long dimYShortImage;
  long dimYLongImage;
  long dimYFloatImage;
  long dimYUcharImage;
  long dimYUshortImage;
  long dimYDoubleImage;
  long dimYBooleanImage;
  long dimYStringImage;
  long dimYenumImage;

/*----- PROTECTED REGION END -----*/	//	TangoTest::Additional Method prototypes
};

/*----- PROTECTED REGION ID(TangoTest::Additional Classes Definitions) ENABLED START -----*/

//	Additional Classes Definitions

/*----- PROTECTED REGION END -----*/	//	TangoTest::Additional Classes Definitions

}	//	End of namespace

#endif   //	TangoTest_H
