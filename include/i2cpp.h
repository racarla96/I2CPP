#ifndef I2C_H_INCLUDE
#define I2C_H_INCLUDE

#include <cstdint>
#include <string>

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

#if defined(DEBUG)
  using namespace std;
  #include <iostream>
#endif

class i2cpp {
 private:
  int fd;
  uint8_t address;
  std::string device;

 public:
  i2cpp();
  bool begin(int bus, uint8_t address);
  bool writeReg(uint8_t reg, uint8_t *data, int length);
  bool readReg(uint8_t reg, uint8_t *data, int length);
  //bool close(void);
};
#endif
