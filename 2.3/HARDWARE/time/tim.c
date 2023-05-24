#include "tim.h"
#include "led.h"
#include "hum.h"
#include "usart.h"	 

void TIM6_Init(u16 arr,u16 psc)
{  
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6, ENABLE);	//使能定时器3时钟

   //初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值  9999
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  7199 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_ICPSC_DIV1; //设置时钟分割:TDTS = Tck_tim  时钟不分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM6, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
  NVIC_InitStructure.NVIC_IRQChannel = TIM6_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//抢占优先级3
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;		//子优先级3
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
  NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器

	
  TIM_ITConfig(TIM6, TIM_IT_Update, ENABLE);//开启中断
 
	TIM_Cmd(TIM6, ENABLE);  //使能TIM3
	

}
/*******
*定义的变量
*/
u32 you_yao;
u32 you_tui_1;
u32 you_tui_2;
u32 you_tui_3;
u32 you_jiao;
u32 zuo_yao;
u32 zuo_tui_1;
u32 zuo_tui_2;
u32 zuo_tui_3 ;
u32 zuo_jiao ;

u32 you_yao_1;
u32 you_tui_1_1;
u32 you_tui_2_1 ;
u32 you_tui_3_1 ;
u32 you_jiao_1 ;
u32 zuo_yao_1 ;
u32 zuo_tui_1_1 ;
u32 zuo_tui_2_1 ;
u32 zuo_tui_3_1 ;
u32 zuo_jiao_1;

u32 you_yao_2 ;
u32 you_tui_1_2 ;
u32 you_tui_2_2 ;
u32 you_tui_3_2 ;
u32 you_jiao_2 ;
u32 zuo_yao_2 ;
u32 zuo_tui_1_2 ;
u32 zuo_tui_2_2 ;
u32 zuo_tui_3_2 ;
u32 zuo_jiao_2 ;

u8 flag_go = 1;
u8 flag_back = 1;
u32 zuo_bang = 0;
u32 you_bang = 0;
void shuzi_init(void)
{
 you_yao = 3200;
 you_tui_1 = 3500;
 you_tui_2 = 3300;
 you_tui_3 = 3600;
 you_jiao = 4200;
 zuo_yao = 5900;
 zuo_tui_1 =5700;
 zuo_tui_2 = 6300;
 zuo_tui_3 = 4900;
 zuo_jiao = 4500;

// you_yao_1 = 2800;
// you_tui_1_1 = 4600;
// you_tui_2_1 = 3400;
// you_tui_3_1 =2800;
// you_jiao_1 = 5300;
// zuo_yao_1 = 5500;
// zuo_tui_1_1 =5700;
// zuo_tui_2_1 = 6500;
// zuo_tui_3_1 = 5000;
// zuo_jiao_1 = 4800;

// you_yao_2 = 3450;
// you_tui_1_2 = 3500;
// you_tui_2_2 = 3150;
// you_tui_3_2 = 3200;
// you_jiao_2 = 4100;
// zuo_yao_2 = 6100;
// zuo_tui_1_2 =6700;
// zuo_tui_2_2 = 7200;
// zuo_tui_3_2 = 4600;
// zuo_jiao_2 = 3000;
}
//定时器定的时间是100ms
u32 i;
void TIM6_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM6,TIM_IT_Update)!= RESET)
	{
		TIM_ClearITPendingBit(TIM6,TIM_IT_Update);
		
			if(flag == 1)
			{
			//右边
			you_yao = you_yao;
			//you_yao = you_yao > 3200?3200:you_yao;
			you_tui_1 = you_tui_1 + 80;
			you_tui_1 = you_tui_1 > 5500?5500:you_tui_1;
			you_tui_2 = you_tui_2 + 76;
    	you_tui_2 = you_tui_2 > 5200?5200:you_tui_2;
			you_tui_3 = you_tui_3 + 64;
   	  you_tui_3 = you_tui_3 > 5200?5200:you_tui_3;
		  you_jiao = you_jiao;
			//左边
			zuo_yao = zuo_yao;
			//zuo_yao = zuo_yao > 5900?5900:zuo_yao;
			zuo_tui_1 = zuo_tui_1 - 76;
			zuo_tui_1 = zuo_tui_1 < 3800?3800:zuo_tui_1;
			zuo_tui_2 = zuo_tui_2 - 132;
			zuo_tui_2 = zuo_tui_2 < 3000?3000:zuo_tui_2;
			zuo_tui_3 = zuo_tui_3 - 76;
			zuo_tui_3 = zuo_tui_3 < 3000?3000:zuo_tui_3;	
				zuo_jiao =zuo_jiao;
			}	
		  if(flag == 2)
			{
			//右边
			you_yao = you_yao;
			//you_yao = you_yao < 3000?3000:you_yao;
			you_tui_1 = you_tui_1 - 80;
			you_tui_1 = you_tui_1 < 3500?3500:you_tui_1;
			you_tui_2 = you_tui_2 - 76;
    	you_tui_2 = you_tui_2 < 3300?3300:you_tui_2;
			you_tui_3 = you_tui_3 - 64;
   	  you_tui_3 = you_tui_3 < 3600?3600:you_tui_3;
				you_jiao = you_jiao;
				
			//左边
			zuo_yao = zuo_yao;
			//zuo_yao = zuo_yao < 5800?5800:zuo_yao;
			zuo_tui_1 = zuo_tui_1 + 76;
			zuo_tui_1 = zuo_tui_1 > 5700?5700:zuo_tui_1;
			zuo_tui_2 = zuo_tui_2 + 132;
			zuo_tui_2 = zuo_tui_2 > 6300?6300:zuo_tui_2;
			zuo_tui_3 = zuo_tui_3 + 76;
			zuo_tui_3 = zuo_tui_3 > 4900?4900:zuo_tui_3;	
				zuo_jiao =zuo_jiao;
			}	
			if(flag == 3)
			{
				if(flag_go == 1)
				{
					you_yao = you_yao - 16;
					you_yao = you_yao < 2800?2800:you_yao;
					you_tui_1 = you_tui_1 + 44;
					you_tui_1 = you_tui_1 > 4600?4600:you_tui_1;
					you_tui_2 = you_tui_2 + 4; 
					you_tui_2 = you_tui_2 > 3400?3400:you_tui_2;
					you_tui_3 = you_tui_3 - 32;
					you_tui_3 = you_tui_3 < 2800?2800:you_tui_3;
					you_jiao = you_jiao + 44;
					you_jiao = you_jiao > 5300?5300:you_jiao;
					//左边
					zuo_yao = zuo_yao - 16;
					zuo_yao = zuo_yao < 5500?5500:zuo_yao;
					zuo_tui_1 = zuo_tui_1;
		//			zuo_tui_1 = zuo_tui_1 > 5700?5700:zuo_tui_1;
					zuo_tui_2 = zuo_tui_2 + 8;
					zuo_tui_2 = zuo_tui_2 > 6500?6500:zuo_tui_2;
					zuo_tui_3 = zuo_tui_3 + 4;
					zuo_tui_3 = zuo_tui_3 > 5000?5000:zuo_tui_3;
					zuo_jiao =zuo_jiao + 12;
					zuo_jiao = zuo_jiao > 4800?4800:zuo_jiao;

				}
				if(flag_go == 2)
				{
					you_yao_1 = you_yao_1 + 26;
					you_yao_1 = you_yao_1 > 3450?3450:you_yao_1;
					you_tui_1_1 = you_tui_1_1 - 44;
					you_tui_1_1 = you_tui_1_1 < 3500?3500:you_tui_1_1;
					you_tui_2_1 = you_tui_2_1 -10;
					you_tui_2_1 = you_tui_2_1 < 3150?3150:you_tui_2_1;		
					you_tui_3_1 = you_tui_3_1 + 16;
					you_tui_3_1 = you_tui_3_1 > 3200?3200:you_tui_3_1;
					you_jiao_1 = you_jiao_1 - 48;
					you_jiao_1 = you_jiao_1 < 4100?4100:you_jiao_1;
					//左边
					zuo_yao_1 = zuo_yao_1 + 24;
					zuo_yao_1 = zuo_yao_1 > 6100?6100:zuo_yao_1;
					zuo_tui_1_1 = zuo_tui_1_1 + 40;
					zuo_tui_1_1 = zuo_tui_1_1 > 6700?6700:zuo_tui_1_1;
					zuo_tui_2_1 = zuo_tui_2_1 + 28;
					zuo_tui_2_1 = zuo_tui_2_1 > 7200?7200:zuo_tui_2_1;
					zuo_tui_3_1 = zuo_tui_3_1 - 16;
					zuo_tui_3_1 = zuo_tui_3_1 < 4600?4600:zuo_tui_3_1;			
					zuo_jiao_1 =zuo_jiao_1 - 72;
					zuo_jiao_1 = zuo_jiao_1 < 3000?3000:zuo_jiao_1;

				}
				 if(flag_go == 3)
				{
			you_yao_2 = you_yao_2 - 10;
			you_yao_2 = you_yao_2 < 3200?3200:you_yao_2;
			you_tui_1_2 = you_tui_1_2;
			you_tui_1_2 = you_tui_1_2 < 3500?3500:you_tui_1_2;
			you_tui_2_2 = you_tui_2_2 + 6;
			you_tui_2_2 = you_tui_2_2 > 3300?3300:you_tui_2_2;		
			you_tui_3_2 = you_tui_3_2 + 16;
   	  you_tui_3_2 = you_tui_3_2 > 3600?3600:you_tui_3_2;
			you_jiao_2 = you_jiao_2 + 8;
			you_jiao_2 = you_jiao_2 > 4200?4200:you_jiao_2;
			//左边
			zuo_yao_2 = zuo_yao_2 - 8;
			zuo_yao_2 = zuo_yao_2 < 5900?5900:zuo_yao_2;
			zuo_tui_1_2 = zuo_tui_1_2 - 40;
			zuo_tui_1_2 = zuo_tui_1_2 < 5700?5700:zuo_tui_1_2;
			zuo_tui_2_2 = zuo_tui_2_2 - 36;
			zuo_tui_2_2 = zuo_tui_2_2 < 6300?6300:zuo_tui_2_2;
			zuo_tui_3_2 = zuo_tui_3_2 + 12;
			zuo_tui_3_2 = zuo_tui_3_2 > 4900?4900:zuo_tui_3_2;			
      zuo_jiao_2 =zuo_jiao_2 + 60;
			zuo_jiao_2 = zuo_jiao_2 > 4500?4500:zuo_jiao_2;

		}
	    }
		  if(flag == 4)
				{
						if(flag_back == 1)
						{
							you_yao = you_yao - 16;
							you_yao = you_yao < 2800?2800:you_yao;
							you_tui_1 = you_tui_1 - 40;
							you_tui_1 = you_tui_1 < 2500?2500:you_tui_1;
							you_tui_2 = you_tui_2 - 12; 
							you_tui_2 = you_tui_2 < 3000?3000:you_tui_2;
							you_tui_3 = you_tui_3 +12;
							you_tui_3 = you_tui_3 > 3900?3900:you_tui_3;
							you_jiao = you_jiao + 60;
							you_jiao = you_jiao > 5700?5700:you_jiao;
							//左边
							zuo_yao = zuo_yao - 16;
							zuo_yao = zuo_yao < 5500?5500:zuo_yao;
							zuo_tui_1 = zuo_tui_1;
				//			zuo_tui_1 = zuo_tui_1 > 5700?5700:zuo_tui_1;
							zuo_tui_2 = zuo_tui_2 + 8;
							zuo_tui_2 = zuo_tui_2 > 6500?6500:zuo_tui_2;
							zuo_tui_3 = zuo_tui_3 + 4;
							zuo_tui_3 = zuo_tui_3 > 5000?5000:zuo_tui_3;
							zuo_jiao =zuo_jiao + 12;
							zuo_jiao = zuo_jiao > 4800?4800:zuo_jiao;
						}
						if(flag_back == 2)
						{
							you_yao_1 = you_yao_1 + 26;
							you_yao_1 = you_yao_1 > 3450?3450:you_yao_1;
							you_tui_1_1 = you_tui_1_1 + 36;
							you_tui_1_1 = you_tui_1_1 > 3400?3400:you_tui_1_1;
							you_tui_2_1 = you_tui_2_1 + 4;
							you_tui_2_1 = you_tui_2_1 > 3100?3100:you_tui_2_1;		
							you_tui_3_1 = you_tui_3_1 - 28;
							you_tui_3_1 = you_tui_3_1 < 3200?3200:you_tui_3_1;
							you_jiao_1 = you_jiao_1 - 64;
							you_jiao_1 = you_jiao_1 < 4100?4100:you_jiao_1;
							//左边
							zuo_yao_1 = zuo_yao_1 + 20;
							zuo_yao_1 = zuo_yao_1 > 6000?6000:zuo_yao_1;
							zuo_tui_1_1 = zuo_tui_1_1 - 32;
							zuo_tui_1_1 = zuo_tui_1_1 < 4900?4900:zuo_tui_1_1;
							zuo_tui_2_1 = zuo_tui_2_1 + 20;
							zuo_tui_2_1 = zuo_tui_2_1 > 7000?7000:zuo_tui_2_1;
							zuo_tui_3_1 = zuo_tui_3_1 + 40;
							zuo_tui_3_1 = zuo_tui_3_1 > 6000?6000:zuo_tui_3_1;			
							zuo_jiao_1 =zuo_jiao_1 - 72;
							zuo_jiao_1 = zuo_jiao_1 < 3000?3000:zuo_jiao_1;
						}
					 if(flag_back == 3)
						{
							you_yao_2 = you_yao_2 - 10;
							you_yao_2 = you_yao_2 < 3200?3200:you_yao_2;
							you_tui_1_2 = you_tui_1_2 + 4;
							you_tui_1_2 = you_tui_1_2 > 3500?3500:you_tui_1_2;
							you_tui_2_2 = you_tui_2_2 + 8;
							you_tui_2_2 = you_tui_2_2 > 3300?3300:you_tui_2_2;		
							you_tui_3_2 = you_tui_3_2 + 16;
							you_tui_3_2 = you_tui_3_2 > 3600?3600:you_tui_3_2;
							you_jiao_2 = you_jiao_2 + 4;
							you_jiao_2 = you_jiao_2 > 4200?4200:you_jiao_2;
							//左边
							zuo_yao_2 = zuo_yao_2 - 4;
							zuo_yao_2 = zuo_yao_2 < 5900?5900:zuo_yao_2;
							zuo_tui_1_2 = zuo_tui_1_2 + 32;
							zuo_tui_1_2 = zuo_tui_1_2 > 5700?5700:zuo_tui_1_2;
							zuo_tui_2_2 = zuo_tui_2_2 - 28;
							zuo_tui_2_2 = zuo_tui_2_2 < 6300?6300:zuo_tui_2_2;
							zuo_tui_3_2 = zuo_tui_3_2 - 44;
							zuo_tui_3_2 = zuo_tui_3_2 < 4900?4900:zuo_tui_3_2;			
							zuo_jiao_2 =zuo_jiao_2 + 60;
							zuo_jiao_2 = zuo_jiao_2 > 4500?4500:zuo_jiao_2;
							}
				}
			if(i>200)
				i =0;
			i++;
			
	}
}


void TIM7_Init(u16 arr,u16 psc)
{  
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7, ENABLE);	//使能定时器3时钟

   //初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值  9999
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值  7199 
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_ICPSC_DIV1; //设置时钟分割:TDTS = Tck_tim  时钟不分割
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM7, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
  NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0 ;//抢占优先级3
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;		//子优先级3
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
  NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器

	
  TIM_ITConfig(TIM7, TIM_IT_Update, ENABLE);//开启中断
 
	TIM_Cmd(TIM7, ENABLE);  //使能TIM3
	

}
u32 a = 0;
void TIM7_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM7,TIM_IT_Update)!= RESET)
	{
		TIM_ClearITPendingBit(TIM7,TIM_IT_Update);
	if(flag == 3)
	{	
		if(flag_go == 1)
		{

			if(a > 40)
			{
			 you_yao_1 = 2800;
			 you_tui_1_1 = 4600;
			 you_tui_2_1 = 3400;
			 you_tui_3_1 =2800;
			 you_jiao_1 = 5300;
			 zuo_yao_1 = 5500;
			 zuo_tui_1_1 =5700;
			 zuo_tui_2_1 = 6500;
			 zuo_tui_3_1 = 5000;
			 zuo_jiao_1 = 4800;

				flag_go = 2;  
				a = 0;
				
			}
	  }    
		if(flag_go == 2)
		{

			if(a > 40)
			{
			 you_yao_2 = 3450;
			 you_tui_1_2 = 3500;
			 you_tui_2_2 = 3150;
			 you_tui_3_2 = 3200;
			 you_jiao_2 = 4100;
			 zuo_yao_2 = 6100;
			 zuo_tui_1_2 =6700;
			 zuo_tui_2_2 = 7200;
			 zuo_tui_3_2 = 4600;
			 zuo_jiao_2 = 3000;

				flag_go = 3;  
				a = 0;
				
			}
	  }
		if(flag_go == 3)
		{

			if(a > 40)
			{
			 you_yao = 3200;
			 you_tui_1 = 3500;
			 you_tui_2 = 3300;
			 you_tui_3 = 3600;
			 you_jiao = 4200;
			 zuo_yao = 5900;
			 zuo_tui_1 =5700;
			 zuo_tui_2 = 6300;
			 zuo_tui_3 = 4900;
			 zuo_jiao = 4500;
				flag_go = 1;  
				a = 0;
			}
	  }
	}
	if(flag == 4)
	{	
	 if(flag_back == 1)
		{
			if(a > 40)
			{
			 you_yao_1 = 2800;
			 you_tui_1_1 = 2500;
			 you_tui_2_1 = 3000;
			 you_tui_3_1 = 3900;
			 you_jiao_1 = 5700;
			 zuo_yao_1 = 5500;
			 zuo_tui_1_1 =5700;
			 zuo_tui_2_1 = 6500;
			 zuo_tui_3_1 = 5000;
			 zuo_jiao_1 = 4800;
			 flag_back = 2;  
				a = 0;
			}
	  }
  if(flag_back == 2)
		{

			if(a > 40)
			{
			 you_yao_2 = 3450;
			 you_tui_1_2 = 3400;
			 you_tui_2_2 = 3100;
			 you_tui_3_2 = 3200;
			 you_jiao_2 = 4100;
			 zuo_yao_2 =  6000;
			 zuo_tui_1_2 =4900;
			 zuo_tui_2_2 = 7000;
			 zuo_tui_3_2 = 6000;
			 zuo_jiao_2 = 3000;
				flag_back = 3;  
				a = 0;
			}
	  }
		if(flag_back == 3)
		{

			if(a > 40)
			{
			 you_yao = 3200;
			 you_tui_1 = 3500;
			 you_tui_2 = 3300;
			 you_tui_3 = 3600;
			 you_jiao = 4200;
			 zuo_yao = 5900;
			 zuo_tui_1 =5700;
			 zuo_tui_2 = 6300;
			 zuo_tui_3 = 4900;
			 zuo_jiao = 4500;
			  flag_back = 1;  
				a = 0;
			}
	  }
	}	
	  if(flag == 1)
		{

			if(a > 50)
			{
			 you_yao = 3200;
			 you_tui_1 = 5500;
			 you_tui_2 = 5200;
			 you_tui_3 = 5200;
			 you_jiao = 4200;
			 zuo_yao = 5900;
			 zuo_tui_1 =3800;
			 zuo_tui_2 = 3000;
			 zuo_tui_3 = 3000;
			 zuo_jiao = 4500;
				a = 0;
			}
	  }	
		if(flag == 2)
		{

			if(a > 50)
			{
			 you_yao = 3200;
			 you_tui_1 = 3500;
			 you_tui_2 = 3300;
			 you_tui_3 = 3600;
			 you_jiao = 4200;
			 zuo_yao = 5900;
			 zuo_tui_1 =5700;
			 zuo_tui_2 = 6300;
			 zuo_tui_3 = 4900;
			 zuo_jiao = 4500;  
				a = 0;
			}
	  }
		a++;
	}
}


