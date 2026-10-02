#ifndef __OLED_H
#define __OLED_H
#include <stdint.h>


void oled_init(void);
void oled_update(void);
void oled_write_char(uint8_t x,uint8_t page,char ch);
void oled_write_string(uint8_t x,uint8_t page,char *str);
void oled_clear(void);

#endif
