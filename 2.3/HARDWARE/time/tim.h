#ifndef __TIM_H
#define __TIM_H
#include "sys.h"

extern u8 flag;
extern u8 flag_go;
extern u8 flag_back;
extern u32 zuo_bang;
extern u32 you_bang;
extern u32 you_yao;
extern u32 you_tui_1;
extern u32 you_tui_2;
extern u32 you_tui_3;
extern u32 you_jiao;
extern u32 zuo_yao;
extern u32 zuo_tui_1;
extern u32 zuo_tui_2;
extern u32 zuo_tui_3;
extern u32 zuo_jiao; 

extern u32 you_yao_1 ;
extern u32 you_tui_1_1  ;
extern u32 you_tui_2_1 ;
extern u32 you_tui_3_1 ;
extern u32 you_jiao_1 ;
extern u32 zuo_yao_1  ;
extern u32 zuo_tui_1_1  ;
extern u32 zuo_tui_2_1  ;
extern u32 zuo_tui_3_1  ;
extern u32 zuo_jiao_1 ;

extern u32 you_yao_2 ;
extern u32 you_tui_1_2  ;
extern u32 you_tui_2_2 ;
extern u32 you_tui_3_2 ;
extern u32 you_jiao_2  ;
extern u32 zuo_yao_2  ;
extern u32 zuo_tui_1_2  ;
extern u32 zuo_tui_2_2  ;
extern u32 zuo_tui_3_2  ;
extern u32 zuo_jiao_2  ;

void shuzi_init(void);

void TIM6_Init(u16 arr,u16 psc);
void TIM7_Init(u16 arr,u16 psc);

#endif



