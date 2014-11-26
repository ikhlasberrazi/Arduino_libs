
#ifndef FiveK_h
#define FiveK_h

#include <Arduino.h>
#include <RobinRamNormal.h>


class FiveK {
  public:
    // Initialize and specify the SS pins
    FiveK(byte p0,byte p1, byte p2, byte p3):rn1(p0),rn2(p1),rn3(p2),rn4(p3){};    
    // Read a single byte from address
    byte readByte   (uint32_t address);    
    // Write a single byte to address
    void writeByte  (uint32_t address, byte data_byte);    
	void initiate ();
  private:
	RobinRamNormal rn1;
	RobinRamNormal rn2;
	RobinRamNormal rn3;
	RobinRamNormal rn4;
};
#endif
// END OF FILE