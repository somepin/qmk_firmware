# KB2040 CNano configuration

This enables half duplex serial and handedness by pin, assuming there are 3 jumper wires on each shield:
```
GP29/R1 -> serial_tx
GP3/SCL -> split_hand (to 5.1k pullup/down resistor depending on side)
GP2/SDA -> CS
```

Since the KB2040 lacks EEPROM and has a Qwiic JST port, an [I2C EEPROM breakout](https://www.sparkfun.com/products/18355) board is used to save mouse and RGB settings.

The KB2040 lacks onboard VBUS detection as well, so a hardware voltage divider was modded on to GP1. VBUS is exposed on the KB2040 via a pad on the backside, but make sure that it is not accidentally jumped to the RAW/5V pad. The header pin on GP1 from the KB2040 to the shield is also left disconnected, as GP29 is used for serial communication instead.

[![image.png](https://i.postimg.cc/Wp6xntMB/image.png)](https://postimg.cc/4ny84f2P)

[Schematic source](https://github.com/plut0nium/0xB2)

It also uses the PMW3389 sensor from [Tindie](https://www.tindie.com/products/jkicklighter/pmw3389-motion-sensor/) instead of the standard PMW3360.
