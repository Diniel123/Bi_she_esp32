#include "hum.h"
#include "pwm.h"
#include "tim.h"

void hum_init(void)
{
//	TIM_SetCompare4(TIM4,4500);  //s1  头
////  TIM_SetCompare1(TIM2,7500);  //s9  左膀
//	TIM_SetCompare1(TIM2,2000);  //s9  左膀
//	
//	TIM_SetCompare3(TIM3,6000);  //s7  左臂1  大 向内
//	TIM_SetCompare2(TIM5,4000);  //s2  左臂2  大 向内
////	TIM_SetCompare2(TIM8,2000);  //s18 右膀
//	TIM_SetCompare2(TIM8,7000);   //s18 右膀
//	
//	TIM_SetCompare1(TIM8,3000);  //s17 右臂2 大 张开
//  TIM_SetCompare4(TIM4,3000);  //s16 右臂
//	TIM_SetCompare1(TIM1,4500);  //s21 右臂1
	
	TIM_SetCompare2(TIM2,3200);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,3500);  //s11 左腿1  小 向后
	TIM_SetCompare3(TIM4,3300);  //s15 左腿2  小 向前
	TIM_SetCompare4(TIM2,3600);  //s12 左腿3
	TIM_SetCompare4(TIM3,4200);  //s8  左脚   小  向外


	TIM_SetCompare1(TIM4,5900);  //s13 右腰  大 向内
	TIM_SetCompare2(TIM4,5700);  //s14 右腿1
	TIM_SetCompare3(TIM5,6300);  //s3 右腿2 大 向前
	TIM_SetCompare4(TIM5,4900);  //s4 右腿3 小 向后
	TIM_SetCompare1(TIM5,4500);  //s1 右脚
}
//抬高手臂
void hum_state(void)
{
	  TIM_SetCompare1(TIM2,7500 - zuo_bang);  //s9  左膀 大 向下 
		TIM_SetCompare2(TIM8,2000+ you_bang);  //s18 右膀 大 向上	
}
void hum_dun_End (void)
{
	TIM_SetCompare2(TIM2,3200);  //s10 左腰   小 向内
	
	TIM_SetCompare3(TIM2,5500);  //s11 左腿1  大 向前
	TIM_SetCompare3(TIM4,5200);  //s15 左腿2  大 向下
	TIM_SetCompare4(TIM2,5200);  //s12 左腿3  大 向上
	TIM_SetCompare4(TIM3,4200);  //s8  左脚   
	
	TIM_SetCompare1(TIM4,5900);  //s13 右腰  大 向内
	
	TIM_SetCompare2(TIM4,3800);  //s14 右腿1 大 向后
	TIM_SetCompare3(TIM5,3000);  //s19 右腿2 大 向下 向前
	TIM_SetCompare4(TIM5,3000);  //s20 右腿3 大 后翘
	TIM_SetCompare1(TIM5,4500);  //s24 右脚
}
void hum_dun(void)
{
	TIM_SetCompare2(TIM2,you_yao);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,you_tui_1);  //s11 左腿1  小 向后
	TIM_SetCompare3(TIM4,you_tui_2);  //s15 左腿2  小 向前
	TIM_SetCompare4(TIM2,you_tui_3);  //s12 左腿3
	TIM_SetCompare4(TIM3,you_jiao);  //s8  左脚   小  向外


	TIM_SetCompare1(TIM4,zuo_yao);  //s13 右腰  大 向内
	
	TIM_SetCompare2(TIM4,zuo_tui_1);  //s14 右腿1
	TIM_SetCompare3(TIM5,zuo_tui_2);  //s19 右腿2 大 向前
	TIM_SetCompare4(TIM5,zuo_tui_3);  //s20 右腿3  
	TIM_SetCompare1(TIM5,zuo_jiao);  //s24 右脚
}
void go_end_1(void)    //第一步走的结束状态
{
	TIM_SetCompare2(TIM2,2800);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,4600);  //s11 左腿1  大 向后+
	TIM_SetCompare3(TIM4,3400);  //s15 左腿2  大 向前+
	TIM_SetCompare4(TIM2,2800);  //s12 左腿3  大 前翘+
	TIM_SetCompare4(TIM3,5300);  //s8  左脚   小 外翘
	
	
	TIM_SetCompare1(TIM4,5500);  //s13 右腰  大 向内+
	TIM_SetCompare2(TIM4,5700);  //s14 右腿1 大 向前+
	TIM_SetCompare3(TIM5,6500);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,5000);  //s4 右腿3 小 前翘+
	TIM_SetCompare1(TIM5,4800);  //s1 右脚 小 内翘+
}
void go_end_2(void)
{
		
	TIM_SetCompare2(TIM2,3450);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,3500);  //s11 左腿1  小 向后+
	TIM_SetCompare3(TIM4,3150);  //s15 左腿2  大 向前+
	TIM_SetCompare4(TIM2,3200);  //s12 左腿3  大 后翘  +
	TIM_SetCompare4(TIM3,4100);  //s8  左脚   小  外翘


	TIM_SetCompare1(TIM4,6100);  //s13 右腰  大 向内+
	TIM_SetCompare2(TIM4,6700);  //s14 右腿1 大 向前+
	TIM_SetCompare3(TIM5,7200);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,4600);  //s4 右腿3 小 前翘+
   TIM_SetCompare1(TIM5,3000);   //s1 右脚   小 内翘+
}
void hum_go_1(void)
{
	TIM_SetCompare2(TIM2,you_yao);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,you_tui_1);  //s11 左腿1  大 前进
	TIM_SetCompare3(TIM4,you_tui_2);  //s15 左腿2  小 向前
	TIM_SetCompare4(TIM2,you_tui_3);  //s12 左腿3  小 前进
	TIM_SetCompare4(TIM3,you_jiao);  //s8  左脚   小 外翘
	
	
	TIM_SetCompare1(TIM4,zuo_yao);  //s13 右腰  大 向内
	TIM_SetCompare2(TIM4,zuo_tui_1);  //s14 右腿1
	TIM_SetCompare3(TIM5,zuo_tui_2);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,zuo_tui_3);  //s4 右腿3 小 向后
	TIM_SetCompare1(TIM5,zuo_jiao);  //s1 右脚
}
void hum_go_2(void)
{
  TIM_SetCompare2(TIM2,you_yao_1);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,you_tui_1_1);  //s11 左腿1  大 前进
	TIM_SetCompare3(TIM4,you_tui_2_1);  //s15 左腿2  小 向前
	TIM_SetCompare4(TIM2,you_tui_3_1);  //s12 左腿3  小 前进
	TIM_SetCompare4(TIM3,you_jiao_1);  //s8  左脚   小 外翘
	
	
	TIM_SetCompare1(TIM4,zuo_yao_1);  //s13 右腰  大 向内
	TIM_SetCompare2(TIM4,zuo_tui_1_1);  //s14 右腿1
	TIM_SetCompare3(TIM5,zuo_tui_2_1);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,zuo_tui_3_1);  //s4 右腿3 小 向后
	TIM_SetCompare1(TIM5,zuo_jiao_1);  //s1 右脚
}
void hum_go_3(void)
{
  TIM_SetCompare2(TIM2,you_yao_2);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,you_tui_1_2);  //s11 左腿1  大 前进
	TIM_SetCompare3(TIM4,you_tui_2_2);  //s15 左腿2  小 向前
	TIM_SetCompare4(TIM2,you_tui_3_2);  //s12 左腿3  小 前进
	TIM_SetCompare4(TIM3,you_jiao_2);  //s8  左脚   小 外翘
		
	TIM_SetCompare1(TIM4,zuo_yao_2);  //s13 右腰  大 向内
	TIM_SetCompare2(TIM4,zuo_tui_1_2);  //s14 右腿1
	TIM_SetCompare3(TIM5,zuo_tui_2_2);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,zuo_tui_3_2);  //s4 右腿3 小 向后
	TIM_SetCompare1(TIM5,zuo_jiao_2);  //s1 右脚
}
void back_end_1(void)    //第一步走的结束状态
{
	TIM_SetCompare2(TIM2,2800);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,2500);  //s11 左腿1  大 向后+
	TIM_SetCompare3(TIM4,3000);  //s15 左腿2  大 向前+
	TIM_SetCompare4(TIM2,3900);  //s12 左腿3  大 前翘+
	TIM_SetCompare4(TIM3,5700);  //s8  左脚   小 外翘
	
	
	TIM_SetCompare1(TIM4,5500);  //s13 右腰  大 向内+
	TIM_SetCompare2(TIM4,5700);  //s14 右腿1 大 向前+
	TIM_SetCompare3(TIM5,6500);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,5000);  //s4 右腿3 小 前翘+
	TIM_SetCompare1(TIM5,4800);  //s1 右脚 小 内翘+
	
}
void back_end_2(void)
{
	TIM_SetCompare2(TIM2,3450);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,3400);  //s11 左腿1  小 向后+
	TIM_SetCompare3(TIM4,3100);  //s15 左腿2  大 向前+
	TIM_SetCompare4(TIM2,3200);  //s12 左腿3  大 后翘  +
	TIM_SetCompare4(TIM3,4100);  //s8  左脚   小  外翘


	TIM_SetCompare1(TIM4,6000);  //s13 右腰  大 向内+
	TIM_SetCompare2(TIM4,4900);  //s14 右腿1 大 向前+
	TIM_SetCompare3(TIM5,7000);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,6000);  //s4 右腿3 小 前翘+
   TIM_SetCompare1(TIM5,3000);   //s1 右脚   小 内翘+
}
void hum_back_1(void)
{
	TIM_SetCompare2(TIM2,you_yao);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,you_tui_1);  //s11 左腿1  大 前进
	TIM_SetCompare3(TIM4,you_tui_2);  //s15 左腿2  小 向前
	TIM_SetCompare4(TIM2,you_tui_3);  //s12 左腿3  小 前进
	TIM_SetCompare4(TIM3,you_jiao);  //s8  左脚   小 外翘
	
	
	TIM_SetCompare1(TIM4,zuo_yao);  //s13 右腰  大 向内
	TIM_SetCompare2(TIM4,zuo_tui_1);  //s14 右腿1
	TIM_SetCompare3(TIM5,zuo_tui_2);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,zuo_tui_3);  //s4 右腿3 小 向后
	TIM_SetCompare1(TIM5,zuo_jiao);  //s1 右脚
}
void hum_back_2(void)
{
	TIM_SetCompare2(TIM2,you_yao_1);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,you_tui_1_1);  //s11 左腿1  大 前进
	TIM_SetCompare3(TIM4,you_tui_2_1);  //s15 左腿2  小 向前
	TIM_SetCompare4(TIM2,you_tui_3_1);  //s12 左腿3  小 前进
	TIM_SetCompare4(TIM3,you_jiao_1);  //s8  左脚   小 外翘
	
	
	TIM_SetCompare1(TIM4,zuo_yao_1);  //s13 右腰  大 向内
	TIM_SetCompare2(TIM4,zuo_tui_1_1);  //s14 右腿1
	TIM_SetCompare3(TIM5,zuo_tui_2_1);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,zuo_tui_3_1);  //s4 右腿3 小 向后
	TIM_SetCompare1(TIM5,zuo_jiao_1);  //s1 右脚
}
void hum_back_3(void)
{
	 TIM_SetCompare2(TIM2,you_yao_2);  //s10 左腰   小 向内
	TIM_SetCompare3(TIM2,you_tui_1_2);  //s11 左腿1  大 前进
	TIM_SetCompare3(TIM4,you_tui_2_2);  //s15 左腿2  小 向前
	TIM_SetCompare4(TIM2,you_tui_3_2);  //s12 左腿3  小 前进
	TIM_SetCompare4(TIM3,you_jiao_2);  //s8  左脚   小 外翘
		
	TIM_SetCompare1(TIM4,zuo_yao_2);  //s13 右腰  大 向内
	TIM_SetCompare2(TIM4,zuo_tui_1_2);  //s14 右腿1
	TIM_SetCompare3(TIM5,zuo_tui_2_2);  //s3 右腿2 大 向后+
	TIM_SetCompare4(TIM5,zuo_tui_3_2);  //s4 右腿3 小 向后
	TIM_SetCompare1(TIM5,zuo_jiao_2);  //s1 右脚
}



