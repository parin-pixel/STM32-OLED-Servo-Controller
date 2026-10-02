# STM32 OLED & Servo Controller

A STM32F446-based embedded project using STM32 HAL to control an SSD1306 128x64 OLED display over I2C and a servo motor using PWM.

## Features

- SSD1306 128x64 OLED control using I2C
- Custom OLED driver written using STM32 HAL
- 5x7 ASCII font rendering
- 1024-byte OLED framebuffer
- Page addressing mode
- Servo control using PWM
- 0–180° servo angle control
- Modular driver structure using .c and .h files

## Hardware

- STM32F446
- SSD1306 128x64 OLED
- Servo motor

## OLED

The OLED communicates with the STM32 using I2C.

- Controller: SSD1306
- Resolution: 128x64
- I2C address: `0x3C`
- Addressing mode: Page addressing
- Framebuffer size: 1024 bytes

The OLED driver handles:

1. SSD1306 initialization
2. Command transmission
3. Framebuffer management
4. Character rendering
5. String rendering
6. Display updates

### OLED Data Flow

  text
Application
     |
     v
oled_write_string()
     |
     v
OLED Framebuffer
     |
     v
oled_update()
     |
     v
    I2C
     |
     v
SSD1306 OLED
