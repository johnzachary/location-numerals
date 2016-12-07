# Location Numerals

Playing around with [location numerals](https://en.wikipedia.org/wiki/Location_arithmetic)
in C++. 

## Dependencies

You need a C/C++ compiler (e.g. `gcc` or `clang`), `cmake`, and `make` installed.

## Build instructions

Building a project is quite straightforward.  Assuming a project directory at $ROOT, the
following commands will build your Makefile from which you can make and test your project.

	$ mkdir -p build
	$ cd build
	$ cmake .. --DCMAKE_INSTALL_PREFIX=$PREFIX
	$ make
	$ ./locnum

## Disclosure
As-is.
