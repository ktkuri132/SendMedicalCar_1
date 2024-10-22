#include <mpu6050.h>


u8 MPU_Read_Byte(u8 reg)
{
    
    u8 data;
    IIC_ReadData(MPU_IIC_PORT,MPU6050_ADDR,reg,&data,1);
    return data;
}