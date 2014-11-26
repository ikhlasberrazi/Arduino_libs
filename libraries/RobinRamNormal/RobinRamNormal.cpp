
#include <RobinRamNormal.h>

RobinRamNormal::RobinRamNormal(byte ss_Pin){
  _ss_Pin = ss_Pin;                     // Store Slave Select pin
}
void RobinRamNormal::setHigh()
{
	digitalWrite(_ss_Pin, HIGH);
}
void RobinRamNormal::initiate(){ 
  pinMode(_ss_Pin,OUTPUT);
  digitalWrite(_ss_Pin,LOW);
  SPI.begin();
  SPI.setClockDivider(21);  //84MHZ/84
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);//Rising Edge en Actief Hoog
  SPI.transfer(WRMR);//mode instellen
  SPI.transfer(BYTE_MODE);//byte mode gebruiken
  digitalWrite(_ss_Pin,HIGH);
}

byte RobinRamNormal::readByte(uint32_t address) {
  digitalWrite(_ss_Pin,LOW);
  SPI.transfer(READ);
  SPI.transfer((byte)(address>>16));
  SPI.transfer((byte)(address>>8));
  SPI.transfer((byte)address);
  byte returnByte  = SPI.transfer((byte)(0x00));
  digitalWrite(_ss_Pin,HIGH);
  return(returnByte);
}

void RobinRamNormal::writeByte(uint32_t address, byte data_byte) {
  digitalWrite(_ss_Pin,LOW);
  SPI.transfer(WRITE);
  SPI.transfer((byte)(address>>16));
  SPI.transfer((byte)(address>>8));
  SPI.transfer((byte)address);
  SPI.transfer(data_byte);
  digitalWrite(_ss_Pin,HIGH);
}