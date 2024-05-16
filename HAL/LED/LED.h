#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "LED_cfg.h"

#ifndef LED_H_

/*********************** Function to init LED ************************************/
          /* depends on configuration you assign to then */
void LED_init();
/*********************** Function to make LED ON ************************************/
     /* it take input of it struct of led which contain led parameter */
void LED_OFF(LED_StrCFG* ledOff);
/*********************** Function to make LED OFF ************************************/
     /* it take input of it struct of led which contain led parameter */
void LED_ON(LED_StrCFG* ledOn);

#endif