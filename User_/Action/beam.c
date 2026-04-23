#include "beam.h"


//横梁初始化
void beam_Init()
{
    hDJI[2].motorType = M3508;
    DJI_Init();
}


//
void beam_move(float distance)
{
    speedServo(distace,hDJI[2]);
    CanTransmit_DJI_1234(&hcan1,hDJI[0].speedPID.output,
    hDJI[1].speedPID.output,
    hDJI[2].speedPID.output,
    hDJI[3].speedPID.output);
}


//控制横梁机构移动到指定坐标对应的位置

void beam_ctrl(float pos) //坐标
{
    beam_move(pos - y);
}




