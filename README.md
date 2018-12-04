# Intro

This project is a cheap air quality sensor node. It runs on an ESP32
microcontroller board and sends measurements over wifi to an MQTT
broker. The microcontroller runs code generated
by [esphomelib](https://esphomelib.com/). Esphomelib works with Home
Assistant, but I am using it just as a service that broadcasts on
MQTT.

# Parts


| Part | Product | Datasheet | AliExpress | Price |
| ---- | ------- | --------- | ---------- | ----- |
|PMS5003 air particle sensor|[Product](http://www.plantower.com/en/content/?108.html)|[Datasheet](http://www.aqmd.gov/docs/default-source/aq-spec/resources-page/plantower-pms5003-manual_v2-3.pdf)|[AliExpress](https://www.aliexpress.com/item/x/32834164058.html)|$17.19|
|CCS811 VOC sensor|[Product](https://ams.com/ccs811)|[Datasheet](https://ams.com/documents/20143/36005/CCS811_DS000459_6-00.pdf/c7091525-c7e5-37ac-eedb-b6c6828b0dcf)|[AliExpress](https://www.aliexpress.com/item/x/32782864505.html)|$8.67|
|BME280 temperature, humidity, pressure |[Product](https://www.bosch-sensortec.com/bst/products/all_products/bme280) |[Datasheet](https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST-BME280_DS002.pdf) |[AliExpress](https://www.aliexpress.com/item/x/32832009083.html) |$2.22 |
|ESP32 microcontroller with wifi and bluetooth |[Product](https://www.espressif.com/en/products/hardware/esp32/overview) |[Datasheet](https://wiki.wemos.cc/products:lolin32:lolin32) |[AliExpress](https://www.aliexpress.com/item/x/32843534185.html) |$4.61|

Listed prices are current on AliExpress on 2018-12-03. Prices add to
$32.69.

# Install

get esphomeyaml, then
esphomeyaml air.yaml run

# To do

What's next:
- add CCS811 sensor to esphomelib
- propose all my fixes to the upstream barnch
- write MQTT listener service that sends data to purpleair, influxdb (the db I use at home), etc. Prepare it in a docker image.
- design outdoor-safe case that still lets air through
- update PMS5003 sensor driver to shut the sensor off most of the time to reduce wear
- document BOM, assembly, configuration

# Related projects


# License

MIT License. See [LICENSE] file.

Note that [esphomelib uses the GPL](https://github.com/OttoWinter/esphomelib/blob/dev/LICENSE).
