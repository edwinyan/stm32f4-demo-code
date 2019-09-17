#include "common.h"
#include "stm32f4xx_gpio.h"
#include "watchdog_drv.h"

/*----------------------------------------------------------------------------*/

//��ʼ���������Ź�
//prer:��Ƶϵ��:0~7
//rlr:�Զ���װ��ֵ,0~0XFFF.
//��Ƶ���� =4*2^prer.���ֵ256!
//rlr:��װ��ֵ: ��11λ��Ч
//ʱ�����:Tout=((4*2^prer)*rlr)/32 (ms).

void IWDG_Init(u8 prer)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable); 
	
	IWDG_SetPrescaler(prer);

	IWDG_SetReload(500);  
	IWDG_ReloadCounter(); 
	
	IWDG_Enable();
}

//ι��
void IWDG_Feed(void)
{
	IWDG_ReloadCounter();//reload
}

