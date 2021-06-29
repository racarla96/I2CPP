#include "i2cpp.h"

i2cpp::i2cpp() {
}

bool i2cpp::begin(int bus, uint8_t address) {
  this->device = "/dev/i2c-" + std::to_string(bus);
  this->address = address;
  fd = open(device.c_str(), O_RDWR);
  if (ioctl(fd, I2C_SLAVE, address) < 0)
    return false;
  else
    return true;
}

bool i2cpp::writeReg(uint8_t reg, uint8_t *data, int length) {
  uint8_t t_data[length + 1];
  
  t_data[0] = reg;
  for (int i = 0; i < length; i++)
    t_data[i + 1] = data[i];

#if defined(DEBUG)
  cout << "Write send: ";
  cout << length << " -> ";
  for(int i = 0; i < length + 1; i++) cout << std::hex << "0x" << unsigned(t_data[i])  << " ";
  cout << endl;
#endif

  return write(fd, t_data, length + 1) == length + 1;
}

bool i2cpp::readReg(uint8_t reg, uint8_t *data, int length) {
  uint8_t t_data[length + 1];
  for(int i = 0; i < length + 1; i++) t_data[i] = 0;
  t_data[0] = reg;
  
#if defined(DEBUG)
  cout << "Read send: ";
  cout << length << " -> ";
  for(int i = 0; i < length + 1; i++) cout << std::hex << "0x" << unsigned(t_data[i])  << " ";
  cout << endl;
#endif

  if(read(fd, t_data, length + 1) == (length + 1)){
    for (int i = 0; i < length; i++)
      data[i] = t_data[i];

#if defined(DEBUG)
  cout << "Read recv: ";
  cout << length << " -> ";
  for(int i = 0; i < length; i++) cout << std::hex << "0x" << unsigned(t_data[i])  << " ";
  cout << endl;
#endif

    return true;
  }

  return false; 
}

bool i2cpp::close(void) {
  //return close(fd);
  return true;
}
