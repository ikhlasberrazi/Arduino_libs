
#ifndef RobinRamNormal_h
#define RobinRamNormal_h

#include <Arduino.h>

#include <SPI.h>

// SRAM Instructions
#define RDMR  0x05
#define WRMR  0x01
#define WRITE 0x02
#define READ  0x03

// SRAM modes
#define BYTE_MODE       0x00
#define PAGE_MODE       0x80
#define SEQUENTIAL_MODE 0x40

class RobinRamNormal {
  public:
    // Initialize and specify the SS pin
    RobinRamNormal          (byte ss_Pin);    
    // Read a single byte from address
    byte readByte   (uint32_t address);    
    // Write a single byte to address
    void writeByte  (uint32_t address, byte data_byte);    
	void initiate ();
	void setHigh();
  private:
    byte _ss_Pin;    
};
#endif
// END OF FILE