/**
 * \file
 * \brief FreeRTOS for AVR Arduino
 */
#ifndef FreeRTOS_AVR_h
#define FreeRTOS_AVR_h



#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#ifdef __cplusplus
extern "C"{
#endif  //  __cplusplus

//------------------------------------------------------------------------------
/** FreeROS_AVR version YYYYMMDD */
#define FREE_RTOS_AVR_VERSION 20151112
//------------------------------------------------------------------------------

size_t freeHeap();

#ifdef __cplusplus
} // extern "C"
#endif  // __cplusplus
#endif  // FreeRTOS_AVR_h
