#ifndef __THREAD_MONITOR_H__
#define __THREAD_MONITOR_H__
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "thread.h"


/********************
 * MACRO
 ********************/
#define     THREAD_MOINITOR_PRIO        2           //任务优先级
#define     THREAD_MONITOR_STK_SIZE     128         //任务堆栈大小
extern StackType_t ThreadMonitorStack[THREAD_MONITOR_STK_SIZE]; //任务堆栈
extern StaticTask_t ThreadMonitorTCB;               //任务控制块


/********************
 * VAR
 ********************/
extern thread_cb_t monitor_thread;
extern TaskHandle_t ThreadMonitor_Handler;          //任务句柄
extern SemaphoreHandle_t monitor_binary_handle;     //二值信号量




// void thread_monitor_enery(void *pvParameters);
uint8_t CommandParse(char *str);


#endif // end __THREAD_MONITOR_H__



