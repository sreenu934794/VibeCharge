#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;
int piezoPin=A0;
void setup(){Serial.begin(115200);Wire.begin();mpu.initialize();}
void loop(){
 int16_t ax,ay,az; mpu.getAcceleration(&ax,&ay,&az);
 int pv=analogRead(piezoPin); float v=pv/1023.0*5.0;
 Serial.print(ax);Serial.print(" ");Serial.println(v);
 delay(200);
}
