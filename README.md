# TangoTest

Tango test device server

## Building

To build:

```
mkdir build & cd build
cmake ..
```

By default (on Linux), CMake will use pkg-config to find your installation of
tango.  This can be disabled by passing -DTango_USE_PKG_CONFIG=OFF to CMake. If
pkg-config cannot find tango, or pkg-config is disabled, CMake will try to
search for tango and its dependencies on your system.  You can provide hints to
cmake using either the -DCMAKE_PREFIX_PATH variable or the -DTango_ROOT variable
(cmake 3.12 or later).

### Notable CMake Variables

| Name                   | Default                  | Description                                                    | Notes                            |
| ---                    | ---                      | ---                                                            | ---                              |
| -DTango_USE_PKG_CONFIG | OFF (Windows) ON (Linux) | Use pkg-config to find Tango                                   |                                  |
| -DTango_FORCE_STATIC   | OFF                      | Force TangoTest to link against the static libtango library   | Fails if no static library found |
| -DCMAKE_PREFIX_PATH    | ""                       | ;-separated list of prefix paths to search for dependencies in |                                  |
| -DTango_ROOT           | ""                       | Prefix path to find Tango dependency                           | CMake 3.12 or later              |
| -DMySQL_ROOT           | ""                       | Prefix path to find MySQL dependency                           | CMake 3.12 or later              |
| -DZeroMQ_ROOT          | ""                       | Prefix path to find ZeroMQ dependency                          | CMake 3.12 or later              |
| -Dcppzmq_ROOT          | ""                       | Prefix path to find cppzmq dependency                          | CMake 3.12 or later              |
| -DomniORB4_ROOT        | ""                       | Prefix path to find omniORB4 dependency                        | CMake 3.12 or later              |

## POGO code generation

The TangoTest class was originally generated by POGO.

### Files generated:
- TangoTest.cpp:        Source code for the TangoTest class and its commands.
                        This class is derived from DeviceImpl_2 class.
                        It represents the CORBA servant obbject which
                        will be accessed from the network.
                        All commands which can be executed on the
                        TangoTest are implemented in this file.
- TangoTest.h:  Include for the TangoTest class.
                    Server class prototypes and descriptions.
- TangoTestClass.cpp:   A singleton class derived fromTangoTest.
                        It implements the command list and all properties
                        and methods required by the TangoTest once per process
- TangoTestClass.h:	Include for the TangoTestClass root class.
                        This class is represents the singleton class for
                        the TangoTest device class.
                        It contains all properties and methods which the 
                        TangoTest requires only once e.g. the commands.
- main.cpp:		C++ source for a TANGO device server main.
                        The main rule is to initialise (and create) the Tango
                        system and to create the DServerClass singleton.
                        The main should be the same for every Tango device server.
- ClassFactory.cpp:	C++ source for the class_factory method of the DServer
                        device class. This method is responsible to create
                        all class singletin for a device server. It is called
                        at device server startup
