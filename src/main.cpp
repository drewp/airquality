#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#include "Adafruit_BME280.h"
#include "Adafruit_CCS811.h"
#include "PMS.h"
#include <Adafruit_Sensor.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_CCS811 ccs;

Adafruit_BME280 bme;

unsigned long delayTime;

PMS pms(Serial1);
PMS::DATA data;

void setup() {
  Serial.begin(115200);

  bool status;

  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  Serial.println("CCS811 test 5a");

  if (!ccs.begin(0x5a)) {
    Serial.println("Failed to start sensor! Please check your wiring.");
    while (1);
  }
  ccs.setDriveMode(CCS811_DRIVE_MODE_10SEC);
  // GPIO13/RXD2 no 16 = pms tx (pin 5)
  // GPIO15/TXD2 no 17 = pms rx (pin 4)
  Serial1.begin(9600, SERIAL_8N1, /*rxPin=*/16,/*txPin=*/17);

}

void loop() {
  if (pms.readUntil(data, 50))
  {
    Serial.print("PM 1.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_1_0);

    Serial.print("PM 2.5 (ug/m3): ");
    Serial.println(data.PM_AE_UG_2_5);

    Serial.print("PM 10.0 (ug/m3): ");
    Serial.println(data.PM_AE_UG_10_0);

    Serial.println();
  }
  Serial.print("{\"temperature_c\": ");
  float tmpr = bme.readTemperature();
  Serial.print(tmpr);
  Serial.print(",");

  Serial.print("\"pressure_hpa\": ");

  Serial.print(bme.readPressure() / 100.0F);


  Serial.print(",\"humidity\": ");
  uint8_t humid = bme.readHumidity();
  Serial.print(humid);
  Serial.print(",");

  if (ccs.available()) {
    ccs.setEnvironmentalData(humid, tmpr);
    if (!ccs.readData()) {
      Serial.print("\"CO2_ppm\": ");
      Serial.print(ccs.geteCO2());
      Serial.print(",\"TVOC_ppb\": ");
      Serial.print(ccs.getTVOC());

    }
    else {
      Serial.println("ERROR!");
      while (1);
    }
  }
  Serial.println("}");
  delay(1000);
}

