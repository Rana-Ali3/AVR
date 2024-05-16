/************************************************************************/
/**************** Name    : Mohamed Ahmed Abdelhamid ********************/
/**************** Date    :       18/06/2020         ********************/
/**************** Driver  :       BIT_MATH_H         ********************/
/**************** Version :          1.0             ********************/
/************************************************************************/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(REG,BITNO) ((REG)|=(1<<(BITNO)))
#define CLR_BIT(REG,BITNO) ((REG)&=~(1<<(BITNO)))
#define TOG_BIT(REG,BITNO) ((REG)^=(1<<(BITNO)))
#define GET_BIT(REG,BITNO) (((REG)>>(BITNO))&1)
#define GET_LOW_NIB(REG) (REG&=(0x0F))

/*#define BV(bit)   (1<<bit)
#define SET_BIT(byte,bit)  (byte|=BV(bit))
#define CLR_BIT(byte,bit)  (byte &= ~BV(bit))
#define GET_BIT(byte,bit) (((byte)>>(bit))&0x01)*/

#endif