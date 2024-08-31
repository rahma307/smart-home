#ifndef LCD_INT_H_
#define LCD_INT_H_

#define lcd_Clear           0x01          /* replace all characters with ASCII 'space'                       */
#define lcd_Home            0x02          /* return cursor to first position on first line                   */
#define lcd_EntryMode       0x06          // shift cursor from left to right on read/write
#define lcd_DisplayOff      0x08          // turn display off
#define lcd_DisplayOn       0x0C          // display on, cursor off, don't blink character
#define lcd_FunctionReset   0x30          // reset the LCD
#define lcd_FunctionSet8bit 0x38          // 8-bit data, 2-line display, 5 x 7 font
#define lcd_SetCursor       0x80          // set cursor position
#define Shift_to_the_right 0b00011100
#define Shift_to_the_left  0b00011000

#define line1   0
#define line2   1

#define CG_RAM_ADDRESS    0b01000000

 void LCD_INIT(void);
 void LCD_WRITE_COMMAND(u8 Copy_u8command);
 void LCD_WRITE_Char(u8 Copy_u8char);
 void LCD_WRITE_STRING(u8 *copy_string );
 u8 LCD_GO_TO(u8 line , u8 colummn);
 void Lcd_voidDisplayNumber(s32 Copy_s32Number);
void LCD_store_customchar(u8 index,u8 *customchar);//index is thate store data in CG RAM //*CUSTOMCHAR IS 1D ARRAY 5*8 FOR EACH INDEX
// SAY I USED index 1  0b01000010 make index1 is 1 and otherwise is 0
void LCD_DISPLAY_CUSTOM_CHAR(u8 index);

#endif /* LCD_INT_H_ */
