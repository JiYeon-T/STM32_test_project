#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
#include "board_config.h"
// #include "bsp_cofig.h"
#include "../bsp_config.h"

//PC5:KEY0
#define KEY0_GPIO                  GPIO_C
#define KEY0_PORT                  5
#define KEY0_PRIEMPTION_PRIORITY   2
#define KEY0_SUB_PRIORITY          1
#define KEY0_NVIC_GROUP            2

//PA15:KEY1
#define KEY1_GPIO                  GPIO_A
#define KEY1_PORT                  15
#define KEY1_PRIEMPTION_PRIORITY   2
#define KEY1_SUB_PRIORITY          0
#define KEY1_NVIC_GROUP            2

//PA0:WK_UP
#define WKUP_GPIO                   GPIO_A
#define WKUP_PORT                   0
#define WKUP_PRIEMPTION_PRIORITY    2
#define WKUP_SUB_PRIORITY           0
#define WKUP_NVIC_GROUP             2
#endif

//通过循环扫描的方式实现按键
#define KEY0_PRES	1		//KEY0按下
#define KEY1_PRES	2		//KEY1按下
#define WKUP_PRES	3		//WK_UP按下

#define KEY0  PCin(5)   	//PC5
#define KEY1  PAin(15)	 	//PA15 
#define WK_UP PAin(0)	 	//PA0  WK_UP

// 按键模式
typedef enum{
    SINGLE_SHOT_MODE = 0,    // 不支持连续按
    CONTINUE_MODE            // 支持连按
} KEY_MODE_E;
	 
void KEY_Init(void);		//IO初始化
u8 KEY_Scan(KEY_MODE_E mode);		//按键扫描函数

//通过位带操作实现按键输入
// #define KEY0    PCin(5)     //PC5
// #define KEY1    PAin(15)    //PA15
// #define WK_UP   PAin(0)     //PA0 WK_UP

// #define KEY0    (1 << 5)    //KEY0 PC5
// #define KEY1    (1 << 15)   //KEY1 PA15
// #define WK_UP   (1 << 0)    //WK_UP PA0

// #define KEY0_GET()  ((GPIOC->IDR & (KEY0)) ? 1 : 0)
// #define KEY1_GET()  ((GPIOA->IDR & (KEY1)) ? 1 : 0)
// #define WKUP_GET()  ((GPIOA->IDR & (WK_UP)) ? 1 : 0)

