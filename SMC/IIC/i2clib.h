#ifndef __I2CLIB_H__
#define __I2CLIB_H__

#include <pico/stdlib.h>
#include <pico/types.h>
#include <hardware/i2c.h>



/**********************************更改下面的端口****************************** */

/* 定义IIC端口  */

void IIC_Init();

void IIC_GPIO_Init(i2c_inst_t *I2C_PORT,uint8_t SCL,uint8_t SDA);
uint8_t IIC_WriteCommand(i2c_inst_t *I2C_PORT,uint8_t ADDRESS,uint16_t Command_Mode, uint8_t Command);
uint8_t IIC_WriteData(i2c_inst_t *I2C_PORT,uint8_t ADDRESS,uint16_t Data_Mode, uint8_t *Data,uint8_t Count);
uint8_t IIC_ReadData(i2c_inst_t *I2C_PORT,uint8_t ADDRESS,uint16_t Data_Mode, uint8_t *Data,uint8_t Count);


#endif