#include <REG52.H>
#include "lcd1602.h"

#define    LCD_RS   P2^0,
#define    LCD_RW   P2^1,
#define    LCD_E    P2^2,

static void lcd1602_write_cmd(unsigned char cmd)
{

}

static void lcd1602_write_data(unsigned char ddata)
{

}

static void lcd1602_set_cursor_pos(unsigned char row, unsigned char col)
{

}


void lcd1602_init()
{

}

void lcd1602_show_char(unsigned char row, unsigned char col, unsigned char ddate)
{

}

void lcd1602_show_string(unsigned char row, unsigned char col, unsigned char* str)
{

}

void lcd1602_show_number(unsigned char row, unsigned char col, unsigned char len, unsigned char num)
{

}

void lcd1602_show_signed_number(unsigned char row, unsigned char col, unsigned char len, unsigned char num)
{

}

void lcd1602_show_hex(unsigned char row, unsigned char col, unsigned char len, unsigned char num)
{

}

void lcd1602_show_binary(unsigned char row, unsigned char col, unsigned char len, unsigned char num)
{

}