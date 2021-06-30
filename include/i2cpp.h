#ifndef I2C_H_INCLUDE
#define I2C_H_INCLUDE

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

#include <cstdint>
#include <string>

using namespace std;

//#define DEBUG

#if defined(DEBUG)

  #include <iostream>
  #include <string>

#endif

class i2cpp {
 private:
  int fd;
  uint8_t address;
  string device;

 public:
  i2cpp();
  bool begin(int bus, uint8_t address);
  bool writeReg(uint8_t reg, uint8_t *data, int length);
  bool readReg(uint8_t reg, uint8_t *data, int length);
  //bool close(void);
};
#endif
