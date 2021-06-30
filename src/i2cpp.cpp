#include "i2cpp.h"

i2cpp::i2cpp() {
}

bool i2cpp::begin(int bus, uint8_t address) {
  this->device = "/dev/i2c-" + std::to_string(bus);
  this->address = address;
  if (fd = open(device.c_str(), O_RDWR) < 0)
    return false;
  else
    return true;
}

bool i2cpp::writeReg(uint8_t reg, uint8_t *data, int length) {

  uint8_t value;
  if (ioctl(fd, I2C_SLAVE, address) < 0)
  {
#if defined(DEBUG)
    cout << "Failed to acquire bus access and/or talk to slave." << endl;
#endif
    return false;;
  }

  uint8_t buf[2];
  int ret;
  for(int i = 0; i < length; i++){
    value = data[i];
    buf[0] = reg;
    buf[1] = value;
    ret = write(fd, buf, 2);
    reg++;

    if(ret != 2) return false;
  }

#if defined(DEBUG)
  cout << "Write: ";
  cout << length << " -> ";
  for(int i = 0; i < length + 1; i++) cout << std::hex << "0x" << unsigned(data[i])  << " ";
  cout << endl;
#endif

  return true;
}

bool i2cpp::readReg(uint8_t reg, uint8_t *data, int length) {

  if (ioctl(fd, I2C_SLAVE, address) < 0)
  {
#if defined(DEBUG)
    cout << "Failed to acquire bus access and/or talk to slave." << endl;
#endif
    return false;;
  }

  uint8_t u8Ret;
  for(int i = 0; i < length; i++){
    write(fd, &reg, 1);
    read(fd, &u8Ret, 1);
    data[i] = u8Ret;
    reg++;
  }

#if defined(DEBUG)
  cout << "Read: ";
  cout << length << " -> ";
  for(int i = 0; i < length; i++) cout << std::hex << "0x" << unsigned(data[i])  << " ";
  cout << endl;
#endif

  return true; 
}

/*
bool i2cpp::close(void) {
  return close(&fd) == 0;
}*/
