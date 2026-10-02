#STM32-OLED-Servo-Controller

##Purpose- To build a weather monitoring station.

## COMPONENTS USED - 
1.Water sensor
2.Servo motor
3.OLED display
4.STM32-NULCEO-F446RE MCU
5.LDR/Photoresistor

## Water sensor- 
It detects rain . 
There are conducting strips which are seperated. 
When water comes in contact with it it completes the circuit acting as an electrolyte and a current flows. 
This is detected by the MCU by reading the pin which outputs 1/0.

## Servo motor- 
It acts as a roof controller. 
Designed such that it moves when water comes in contact with sensor. 
Could be used in rooftops of houses. 
The source and header files for Servo motor was self written using the datasheet for sg90 servo motor by controlling PWM duty cycle.
It is controlled by TIM3 CHANNEL 4 by generating PWM signals of duty cycle 5%,7.5% and 10% for angles 0,90 and 180 respectively.
Frequency set to 50hz.
Time period 20ms.

## LDR(photoresistor)-
It is used to detect the sunlight levels.
Each threshold is categorised into 'sunny', 'cloudy' or 'dark'.
It is read by using ADC to convert the analog voltage into binary.

## OLED display-
It is used to display the data.
The source and header files for OLED were self written by looking into datasheet for the ssd1306 display.
Communication with the oled occurs from I2C communictation.


