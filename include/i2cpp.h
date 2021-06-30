#ifndef I2C_H_INCLUDE
#define I2C_H_INCLUDE

#include <cstdint>
#include <string>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>

#include <linux/types.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
