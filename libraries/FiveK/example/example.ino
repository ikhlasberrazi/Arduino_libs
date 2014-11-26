#include <SPI.h>
#include <RobinRamExtended.h>
#include <RobinRamNormal.h>
#include <FiveK.h>

FiveK FiveK(4,10,52,7);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  FiveK.initiate();
  for(int i = 0; i<0x80000; i++)
  {
    FiveK.writeByte(i,(byte)(millis()>>8));
  }
  //als de laatste hier terug 0 is weet je dat je alle bits gebruikt hebt
  for(int i = 0; i<0x80001; i++)
  {
    byte b = FiveK.readByte(i);
    Serial.println(b);
  }
}

void loop() {

}