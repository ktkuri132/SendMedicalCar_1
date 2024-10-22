#include <i2clib.h>

void IIC_Init()
{
	
}

void IIC_GPIO_Init(i2c_inst_t *I2C_PORT,uint8_t SCL,uint8_t SDA)	
{
	gpio_init(SDA);
    gpio_init(SCL);

    gpio_set_function(SDA, GPIO_FUNC_I2C);
    gpio_set_function(SCL, GPIO_FUNC_I2C);

	gpio_pull_up(SDA);
	gpio_pull_up(SCL);

    i2c_init(I2C_PORT, 2500000);
}

//IIC写命令 无需写入长度
uint8_t IIC_WriteCommand(i2c_inst_t *I2C_PORT, uint8_t ADDRESS,uint16_t Command_Mode, uint8_t Command)
{
    
	uint8_t data[2] = {Command_Mode, Command};
    i2c_write_blocking(I2C_PORT, ADDRESS, data, 2, false);
	return 0;
}

//IIC写数据 需要写入长度
uint8_t IIC_WriteData(i2c_inst_t *I2C_PORT,uint8_t ADDRESS,uint16_t Data_Mode, uint8_t *Data,uint8_t Count)
{
	uint8_t data[Count + 1];
	data[0] = Data_Mode;
	memcpy(data + 1, Data, Count);
	i2c_write_blocking(I2C_PORT, ADDRESS, data, Count + 1, false);
	return 0;
}

uint8_t IIC_ReadData(i2c_inst_t *I2C_PORT,uint8_t ADDRESS,uint16_t Data_Mode, uint8_t *Data,uint8_t Count)
{
	uint8_t data[1] = {Data_Mode};
	i2c_write_blocking(I2C_PORT, ADDRESS, data, 1, true);
	i2c_read_blocking(I2C_PORT, ADDRESS, Data, Count, false);
	return 0;
}

