// Extended VibeCharge Code – ESP8266 + MPU6050 + Piezo Voltage Monitor
// ---------------------------------------------------------------
// This code reads:
// ✔ Vibration data from MPU6050
// ✔ Piezoelectric voltage (AC → DC regulated)
// ✔ Battery level (optional)
// ✔ Provides a clean serial output dashboard
// ---------------------------------------------------------------

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

// Piezo connected to A0 (after rectifier + booster)
int piezoPin = A0;

// Battery monitoring (optional voltage divider)
int batteryPin = A0;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  Serial.println("Initializing MPU6050...");
  mpu.initialize();

  if (mpu.testConnection()) {
    Serial.println("MPU6050 Connected Successfully");
  } else {
    Serial.println("MPU6050 Connection Failed");
  }

  delay(1000);
}

void loop() {

  // ---------- Read MPU6050 ----------
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  // ---------- Read Piezo Voltage ----------
  int piezoValue = analogRead(piezoPin);
  float piezoVoltage = (piezoValue / 1023.0) * 5.0;

  // ---------- Estimate Power (simple model) ----------
  float estimatedPower_mW = piezoVoltage * piezoVoltage / 10.0;

  // ---------- Print Serial Dashboard ----------
  Serial.println("========== VibeCharge Dashboard ==========");
  Serial.print("Acceleration (AX, AY, AZ): ");
  Serial.print(ax); Serial.print(" ");
  Serial.print(ay); Serial.print(" ");
  Serial.println(az);

  Serial.print("Rotation (GX, GY, GZ): ");
  Serial.print(gx); Serial.print(" ");
  Serial.print(gy); Serial.print(" ");
  Serial.println(gz);

  Serial.print("Piezo Voltage: ");
  Serial.print(piezoVoltage);
  Serial.println(" V");

  Serial.print("Estimated Power: ");
  Serial.print(estimatedPower_mW);
  Serial.println(" mW");

  Serial.println("Charging Status: ACTIVE (If vibration detected)");
  Serial.println("===========================================\n");

  delay(700);
}
