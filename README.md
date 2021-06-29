# I2CPP

A C++ Library for interfacing with I2C Devices on Linux systems, particularly aimed at single board computer (SBC) such as Raspberry Pi, Jetson Nano and Beaglebone.

## Usage Example

```cpp
#include <i2cpp.hpp>

i2cpp * _i2c;

int main()
{
	_i2c = new i2cpp();
	_i2c->begin(I2C_BUS, I2C_ADDR);
	return 0;
}
```
Include the library when you compile:
```bash
g++ your_source.cpp -li2cpp
```

## Dependencies

There are no runtime dependencies, but the project requires [CMake](https://cmake.org/download/) to build.

## Building and Installation

Clone the repository, then run CMake and Make in a build directory:
```bash
git clone https://github.com/racarla96/I2CPP
mkdir I2CPP/build
cd I2CPP/build
cmake ..
make
```
The default install location is `/usr/local`. To change this, run cmake with the desired prefix (e.g. `cmake -DCMAKE_INSTALL_PREFIX=/usr ..`)

Install with `sudo make install`
