/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/Xilinx/workspace/LED_stream/LED_stream/LED.vhd";
extern char *IEEE_P_2592010699;

char *ieee_p_2592010699_sub_393209765_503743352(char *, char *, char *, char *);


static void work_a_3181028076_3212880686_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    int t9;
    unsigned char t10;
    char *t11;
    int t12;
    char *t13;

LAB0:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2272U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 4600);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(56, ng0);
    t4 = (t0 + 2928U);
    t8 = *((char **)t4);
    t9 = *((int *)t8);
    t10 = (t9 == 32999999);
    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t12 = (t9 + 1);
    t2 = (t0 + 2928U);
    t5 = *((char **)t2);
    t2 = (t5 + 0);
    *((int *)t2) = t12;

LAB9:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2928U);
    t4 = *((char **)t2);
    t9 = *((int *)t4);
    t1 = (t9 <= 16499999);
    if (t1 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(64, ng0);
    t2 = (t0 + 4696);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t8 = (t5 + 56U);
    t11 = *((char **)t8);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);

LAB12:    goto LAB3;

LAB5:    t4 = (t0 + 2312U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(57, ng0);
    t4 = (t0 + 2928U);
    t11 = *((char **)t4);
    t4 = (t11 + 0);
    *((int *)t4) = 0;
    goto LAB9;

LAB11:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 4696);
    t5 = (t2 + 56U);
    t8 = *((char **)t5);
    t11 = (t8 + 56U);
    t13 = *((char **)t11);
    *((unsigned char *)t13) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    goto LAB12;

}

static void work_a_3181028076_3212880686_p_1(char *t0)
{
    char t18[16];
    char t21[16];
    unsigned char t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    unsigned char t6;
    unsigned char t7;
    char *t8;
    char *t9;
    unsigned char t10;
    unsigned int t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned int t19;
    unsigned int t20;
    int t22;
    unsigned int t23;

LAB0:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 2432U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t22 = (0 - 0);
    t11 = (t22 * 1);
    t19 = (1U * t11);
    t20 = (0 + t19);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 4824);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t22 = (1 - 0);
    t11 = (t22 * 1);
    t19 = (1U * t11);
    t20 = (0 + t19);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 4888);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t22 = (2 - 0);
    t11 = (t22 * 1);
    t19 = (1U * t11);
    t20 = (0 + t19);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 4952);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t22 = (3 - 0);
    t11 = (t22 * 1);
    t19 = (1U * t11);
    t20 = (0 + t19);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 5016);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t22 = (4 - 0);
    t11 = (t22 * 1);
    t19 = (1U * t11);
    t20 = (0 + t19);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 5080);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(85, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t22 = (5 - 0);
    t11 = (t22 * 1);
    t19 = (1U * t11);
    t20 = (0 + t19);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 5144);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t22 = (6 - 0);
    t11 = (t22 * 1);
    t19 = (1U * t11);
    t20 = (0 + t19);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 5208);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(87, ng0);
    t2 = (t0 + 2632U);
    t4 = *((char **)t2);
    t22 = (7 - 0);
    t11 = (t22 * 1);
    t19 = (1U * t11);
    t20 = (0 + t19);
    t2 = (t4 + t20);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 5272);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast_port(t5);
    t2 = (t0 + 4616);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(73, ng0);
    t4 = (t0 + 3048U);
    t8 = *((char **)t4);
    t4 = (t0 + 7689);
    t10 = 1;
    if (9U == 9U)
        goto LAB11;

LAB12:    t10 = 0;

LAB13:    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 3048U);
    t4 = *((char **)t2);
    t11 = (8 - 7);
    t19 = (t11 * 1U);
    t20 = (0 + t19);
    t2 = (t4 + t20);
    t5 = (t21 + 0U);
    t8 = (t5 + 0U);
    *((int *)t8) = 7;
    t8 = (t5 + 4U);
    *((int *)t8) = 0;
    t8 = (t5 + 8U);
    *((int *)t8) = -1;
    t22 = (0 - 7);
    t23 = (t22 * -1);
    t23 = (t23 + 1);
    t8 = (t5 + 12U);
    *((unsigned int *)t8) = t23;
    t8 = ieee_p_2592010699_sub_393209765_503743352(IEEE_P_2592010699, t18, t2, t21);
    t9 = (t18 + 12U);
    t23 = *((unsigned int *)t9);
    t23 = (t23 * 1U);
    t1 = (8U != t23);
    if (t1 == 1)
        goto LAB17;

LAB18:    t12 = (t0 + 4760);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t8, 8U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(77, ng0);
    t2 = (t0 + 3048U);
    t4 = *((char **)t2);
    t2 = xsi_vhdl_bitvec_sll(t2, t4, 9U, 1);
    t5 = (t0 + 3048U);
    t8 = *((char **)t5);
    t5 = (t8 + 0);
    memcpy(t5, t2, 9U);

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 2472U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(74, ng0);
    t14 = (t0 + 7698);
    t16 = (t0 + 3048U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t14, 9U);
    goto LAB9;

LAB11:    t11 = 0;

LAB14:    if (t11 < 9U)
        goto LAB15;
    else
        goto LAB13;

LAB15:    t12 = (t8 + t11);
    t13 = (t4 + t11);
    if (*((unsigned char *)t12) != *((unsigned char *)t13))
        goto LAB12;

LAB16:    t11 = (t11 + 1);
    goto LAB14;

LAB17:    xsi_size_not_matching(8U, t23, 0);
    goto LAB18;

}


extern void work_a_3181028076_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3181028076_3212880686_p_0,(void *)work_a_3181028076_3212880686_p_1};
	xsi_register_didat("work_a_3181028076_3212880686", "isim/LED_stream_test_isim_beh.exe.sim/work/a_3181028076_3212880686.didat");
	xsi_register_executes(pe);
}
