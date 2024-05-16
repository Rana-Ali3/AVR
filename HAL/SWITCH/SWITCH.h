#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "SWITCH_cfg.h"


#ifndef SWITCH_H_
/*************** function prototype of ispressed to get the value applied on the switch **************************/
      /* it take switch port and pin and state through giving it struct contain switch configration */
void ispressed(SWITCH_StrCFG* pressd_switch);

/*************** function prototype of init to init the switch depends on configration **************************/
void SWITCH_init();


#endif