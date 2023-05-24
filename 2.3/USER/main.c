#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
#include "usart.h"
#include "hum.h"
#include "tim.h"
//ALIENTEK Mini STM32开发板范例代码8
//PWM输出实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

//设置频率为50Hz，公式为：溢出时间Tout（单位秒）=(arr+1)(psc+1)/Tclk	 20MS = (59999+1)*(23+1)/72000000
                          //Tclk为通用定时器的时钟，如果APB1没有分频，则就为系统时钟，72MHZ
//                          //PWM时钟频率=72000000/(59999+1)*(23+1) = 50HZ (20ms),设置自动装载值60000,预分频系数24
u8 flag = 0;
int main(void)
 {		
	delay_init();	    	 //延时函数初始化	 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应优先级	 
	 UART5_init(9600);
	 BEEP_Init();
	 shuzi_init();
//	LED_Init();		  	//初始化与LED连接的硬件接口
	 TIM1_PWM_Init(59999,23); 
	 TIM2_PWM_Init(59999,23);
	 TIM3_PWM_Init(59999,23);	
	 TIM4_PWM_Init(59999,23);
	 TIM5_PWM_Init(59999,23);
	 TIM8_PWM_Init(59999,23); 
	 TIM6_Init(999,7199);  //定时100ms
	 TIM7_Init(999,7199);  //定时100ms
	 hum_init();//机器人初始化

	 //1500  0°   3000  45°   4500  90°    7500  180°
	 //蓝牙     RX:PD2   TX:PC12    UART5
	 //TIM3:3:PB0 4:PB1;TIM2完全映射：PA15,PB3,PB10,PB11;TIM4:PB6,PB7,PB8,PB9 TIM5: 1:PA0,2:PA1 TIM8:PC6,PC7,PC8,PC9,
	 //TIM1: 1:PA8  4:PA11
	 delay_ms(2000);
   	while(1)
	{
	if(Res == '1' )	{				
    flag = 1;		
		beep = 1;
		hum_dun();
	}
	if(Res == '2' ){
		flag = 2;
		beep = 0;
		hum_dun();
	}
  if(Res == '3' ){
    flag = 3;
	if(flag_go == 1)
    hum_go_1();
	if(flag_go == 2)
		hum_go_2();
	if(flag_go == 3)
		hum_go_3();
	}

  if(Res == '4' ){
	    flag = 4;
		if(flag_back == 1)
		   	hum_back_1();
		if(flag_back == 2)
			   hum_back_2();
		if(flag_back == 3)
			   hum_back_3();
}



//		hum_dun_End();
	} 
}

