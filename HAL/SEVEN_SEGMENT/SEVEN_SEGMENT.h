#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "SEVEN_SEGMENT_cfg.h"


#ifndef SEVEN_SEGMENT_H_

#define ZERO   0
#define ONE    1
#define TWO    2
#define THREE  3
#define FOUR   4
#define FIVE   5
#define SIX    6
#define SEVEN  7
#define EIGHT  8
#define NINE   9

void Seven_segment_init();
void seven_segment_set_value(SEVEN_SEGMENT_StrCFG *selected_seven_segment,u8 local_u8Value);
void seven_segment_set_value_only(u32 local_u8Value);

#endif