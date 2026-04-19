#include "chassis.h"

//底盘初始化
void chassis_init()
{
    CANFilterInit(&hcan1); //初始化 can1总线
    hDJI[0].motorType = M3508; 
    hDJI[1].motorType = M3508;  //底盘的两个电机ID为0，1
    DJI_Init();
}

void chassis_move(float distance)
{
    positionServo(distance,&hDJI[0]);
    positionServo(-distance,&hDJI[1]);
}

//底盘速度获取
void chassis_readspeed()
{
    printf("%f",hDJI[0].AxisData.AxisVelocity);
}

//底盘位置获取
void chassis_readpos()
{
    printf("%f",hDJI[0].AxisData.AxisAngle_inDegree);
}

//底盘控制代码
