# I2CPP

A C++ Library for interfacing with I2C Devices on Linux systems, particularly aimed at single board computer (SBC) such as Raspberry Pi, Jetson Nano and Beaglebone.

## Usage Example

```cpp
#include <i2cpp.h>

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

## Usage Example 2

Read BNO055 Chip Identification

```cpp
#include <i2cpp.h>
#include <iostream>

using namespace std;

i2cpp * _i2c;

int main()
{
        bool ret;

        _i2c = new i2cpp();
        ret = _i2c->begin(1, 0x29);
        std::cout << std::boolalpha << ret << std::endl;
        if(ret == false) return -1;

        uint8_t data;
        ret = _i2c->readReg(0x00, &data, 1);
        std::cout << std::boolalpha << ret << std::endl;
        if(ret == false) return -1;
        cout << "Chip identification code, read-only fixed value 0xA0 == 0x" << std::hex << unsigned(data) << endl;

        return 0;
}
```

Include the library when you compile:
```bash
g++ example.cpp -li2cpp
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

## Permissions

`sudo usermod -aG i2c ${USER}`
