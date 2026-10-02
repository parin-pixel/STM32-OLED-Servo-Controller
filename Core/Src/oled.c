#include "main.h"
#include "oled.h"
#include "fonts.h"
#include <stdint.h>
#include <string.h>

#define OLED_ADDR (0x3C << 1)

extern I2C_HandleTypeDef hi2c1;

static uint8_t oled_buffer[1024];

static void oled_command(uint8_t cmd)
{
    uint8_t data[2];

    data[0] = 0x00;
    data[1] = cmd;

    HAL_I2C_Master_Transmit(
        &hi2c1,
        OLED_ADDR,
        data,
        2,
        HAL_MAX_DELAY
    );
}

void oled_init(void)
{
    HAL_Delay(100);

    oled_command(0xAE); // Display OFF

    oled_command(0xD5); // Display clock
    oled_command(0x80);

    oled_command(0xA8); // Multiplex ratio
    oled_command(0x3F); // 64 rows

    oled_command(0xD3); // Display offset
    oled_command(0x00);

    oled_command(0x40); // Start line = 0

    oled_command(0x8D); // Charge pump
    oled_command(0x14);

    oled_command(0x20); // Memory addressing mode
    oled_command(0x02); // Page addressing mode

    oled_command(0xA1); // Segment remap

    oled_command(0xC8); // COM scan direction

    oled_command(0xDA); // COM pins
    oled_command(0x12);

    oled_command(0x81); // Contrast
    oled_command(0x7F);

    oled_command(0xD9); // Pre-charge
    oled_command(0xF1);

    oled_command(0xDB); // VCOMH
    oled_command(0x40);

    oled_command(0xA4); // Display follows RAM

    oled_command(0xA6); // Normal display

    oled_command(0xAF); // Display ON

    oled_clear();
    oled_update();
}

void oled_update(void)
{
    uint8_t data[129];

    data[0] = 0x40; // Following bytes are display data

    for (uint8_t page = 0; page < 8; page++)
    {
        oled_command(0xB0 + page); // Select page

        oled_command(0x00);        // Column lower nibble
        oled_command(0x10);        // Column upper nibble

        memcpy(
            &data[1],
            &oled_buffer[page * 128],
            128
        );

        HAL_I2C_Master_Transmit(
            &hi2c1,
            OLED_ADDR,
            data,
            129,
            HAL_MAX_DELAY
        );
    }
}

void oled_clear(void)
{
    memset(oled_buffer, 0x00, sizeof(oled_buffer));
}

void oled_write_char(uint8_t x, uint8_t page, char ch)
{
    if (ch < 32 || ch > 126)
        ch = '?';

    uint16_t start = x + (128 * page);

    for (uint8_t i = 0; i < 5; i++)
    {
        oled_buffer[start + i] = Font5x7[ch - 32][i];
    }

    oled_buffer[start + 5] = 0x00;
}

void oled_write_string(uint8_t x, uint8_t page, char *str)
{
    while (*str != '\0')
    {
        oled_write_char(x, page, *str);

        x += 6;
        str++;
    }
}
