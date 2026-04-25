#include "chassis.h"

//底盘初始化
void chassis_init()
{
    CANFilterInit(&hcan1); //初始化 can1总线
    hDJI[0].motorType = M3508; 
    hDJI[1].motorType = M3508;  //底盘的两个电机ID为0，1
    DJI_Init();
}
//底盘控制
void chassis_move(float distance)
{
    positionServo(distance,&hDJI[0]);
    positionServo(-distance,&hDJI[1]);
    CanTransmit_DJI_1234(&hcan1,hDJI[0].speedPID.output,
    hDJI[1].speedPID.output,
    hDJI[2].speedPID.output,
    hDJI[3].speedPID.output);
}

//底盘速度获取
void chassis_readspeed()
{
    //打印测试
    printf("%f",hDJI[0].AxisData.AxisVelocity);
}

//底盘位置获取
void chassis_readpos()
{
    printf("%f",hDJI[0].AxisData.AxisAngle_inDegree); //打印至串口便于观察
    crane_xyz.state_x = hDJI[0].AxisData.AxisVelocity;

}

//底盘控制代码
void chassis_ctrl(float distance)
{
    while(1)
    {
        if(hDJI[0].flag == 1)
        {
            chassis_move(distance);
            hDJI[0].flag = 0;
        }
        if(hDJI[0].speedPID.output == 0)
        {
            return;
        }
    }
}