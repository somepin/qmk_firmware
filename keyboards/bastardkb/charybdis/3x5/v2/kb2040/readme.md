# KB2040 CNano configuration

This enables full duplex serial and handedness by pin, assuming there are 3 jumper wires on each shield:
```
GP29/R1 -> serial_tx (with SERIAL_USART_PIN_SWAP defined)
GP3/SCL -> split_hand (to 5.1k pullup/down resistor depending on side)
GP2/SDA -> CS
```

Since the KB2040 lacks EEPROM and has a Qwiic JST port, an [I2C EEPROM breakout](https://www.sparkfun.com/products/18355) board is used to save mouse and RGB settings.

It also uses the PMW3389 sensor from [Tindie](https://www.tindie.com/products/jkicklighter/pmw3389-motion-sensor/) instead of the standard PMW3360.
