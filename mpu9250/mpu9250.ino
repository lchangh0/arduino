#include <Wire.h>

#define MPU6500_ADDR 0x68  // MPU6500 I2C 주소

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // MPU6500 초기화
  Wire.beginTransmission(MPU6500_ADDR);
  Wire.write(0x6B);  // PWR_MGMT_1 레지스터
  Wire.write(0);     // 전원을 켬
  Wire.endTransmission(true);
}

void loop() {
  int16_t accelX, accelY, accelZ, gyroX, gyroY, gyroZ;
  
  // 가속도 데이터 읽기
  Wire.beginTransmission(MPU6500_ADDR);
  Wire.write(0x3B);  // ACCEL_XOUT_H 레지스터
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6500_ADDR, 6, true);
  
  accelX = (Wire.read() << 8) | Wire.read();
  accelY = (Wire.read() << 8) | Wire.read();
  accelZ = (Wire.read() << 8) | Wire.read();
  
  // 자이로 데이터 읽기
  Wire.beginTransmission(MPU6500_ADDR);
  Wire.write(0x43);  // GYRO_XOUT_H 레지스터
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6500_ADDR, 6, true);
  
  gyroX = (Wire.read() << 8) | Wire.read();
  gyroY = (Wire.read() << 8) | Wire.read();
  gyroZ = (Wire.read() << 8) | Wire.read();
  
  // 데이터 출력
  Serial.print("Accel: ");
  Serial.print(accelX); Serial.print(", ");
  Serial.print(accelY); Serial.print(", ");
  Serial.print(accelZ); Serial.print(" | ");
  
  Serial.print("Gyro: ");
  Serial.print(gyroX); Serial.print(", ");
  Serial.print(gyroY); Serial.print(", ");
  Serial.println(gyroZ);
  
  delay(500);
}