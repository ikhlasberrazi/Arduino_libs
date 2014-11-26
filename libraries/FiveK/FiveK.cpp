#include <FiveK.h>
#include <RobinRamNormal.h>

// FiveK::FiveK(byte ep0,byte ep1, byte ep2, byte np1)
// {
// rn1 = new RobinRamNormal(np1);
// re1 = new RobinRamExtended(ep0);
// re2 = new RobinRamExtended(ep1);
// re3 = new RobinRamExtended(ep2);	
// }

void FiveK::initiate(){
	rn1.initiate();
	rn2.initiate();
	rn3.initiate();
	rn4.initiate();
}

byte FiveK::readByte(uint32_t address) {
	if (address < 0x20000 && address >= 0)
	{
		return(rn1.readByte(address));
	}
	else if (address >= 0x20000 && address < 0x40000)
	{
		return(rn2.readByte(address - 0x20000));
	}
	else if (address >= 0x40000 && address < 0x60000)
	{
		return(rn3.readByte(address - 0x40000));
	}
	else if (address >= 0x60000 && address < 0x80000)
	{
		return(rn4.readByte(address - 0x60000));
	}
}

void FiveK::writeByte(uint32_t address, byte data_byte) {
	if (address < 0x20000 && address >= 0)
	{
		rn1.writeByte(address, data_byte);
	}
	else if (address >= 0x20000 && address < 0x40000)
	{
		rn2.writeByte(address - 0x20000, data_byte);
	}
	else if (address >= 0x40000 && address < 0x60000)
	{
		rn3.writeByte(address - 0x40000, data_byte);
	}
	else if (address >= 0x60000 && address < 0x80000)
	{
		rn4.writeByte(address - 0x60000, data_byte);
	}
}