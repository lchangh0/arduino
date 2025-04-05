#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define SEA_LEVEL_PRESSURE 1013.25

Adafruit_BMP280 bmp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  if (!bmp.begin(0x76))
  {
    Serial.println("BMP280 Not Found");
    while(1);
  }

  // BMP280 설정
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL, // 정상 동작 모드
    Adafruit_BMP280::SAMPLING_X2, // 온도 오버샘플링 x2
    Adafruit_BMP280::SAMPLING_X16, // 압력 오버샘플링 x16
    Adafruit_BMP280::FILTER_X16,  // 필터 x16
    Adafruit_BMP280::STANDBY_MS_500); // 대기 시간 500ms
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F;
  float altitude = bmp.readAltitude(SEA_LEVEL_PRESSURE);

  Serial.print("Temp:");
  Serial.print(temperature);
  Serial.print("C, Pressure:");
  Serial.print(pressure);
  Serial.print("hPa, Altitude:");
  Serial.print(altitude);
  Serial.println("m");

  delay(1000);
}
