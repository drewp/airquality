// Auto generated code by esphomeyaml
#include "esphomelib/application.h"

using namespace esphomelib;

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  App.set_name("air");
  App.set_compilation_datetime(__DATE__ ", " __TIME__);
  App.init_log(115200);
  ::WiFiComponent *_wificomponent = App.init_wifi();
  _wificomponent->set_sta(::WiFiAp{
      .ssid = "bigasterisk5",
      .password = "dancedance",
      .channel = -1,
  });
  ::OTAComponent *_otacomponent = App.init_ota();
  _otacomponent->start_safe_mode();
  App.init_mqtt("10.2.0.1", 1883, "", "");
  App.init_i2c(21, 22, false);
  ::UARTComponent *_uartcomponent = App.init_uart(17, 16, 9600);
  ::Application::MakeBME280Sensor _application_makebme280sensor = App.make_bme280_sensor("BME280 Temperature", "BME280 Pressure", "BME280 Humidity", 0x76, 15000);
  _application_makebme280sensor.bme280->set_temperature_oversampling(sensor::BME280_OVERSAMPLING_16X);
  sensor::PMSX003Component *sensor_pmsx003component = App.make_pmsx003(_uartcomponent, sensor::PMSX003_TYPE_5003);
  sensor::PMSX003Sensor *sensor_pmsx003sensor = sensor_pmsx003component->make_pm_1_0_sensor("Particulate Matter <1.0\302\265m Concentration");
  App.register_sensor(sensor_pmsx003sensor);
  sensor::PMSX003Sensor *sensor_pmsx003sensor_2 = sensor_pmsx003component->make_pm_2_5_sensor("Particulate Matter <2.5\302\265m Concentration");
  App.register_sensor(sensor_pmsx003sensor_2);
  sensor::PMSX003Sensor *sensor_pmsx003sensor_3 = sensor_pmsx003component->make_pm_10_0_sensor("Particulate Matter <10.0\302\265m Concentration");
  App.register_sensor(sensor_pmsx003sensor_3);
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
  delay(16);
}
