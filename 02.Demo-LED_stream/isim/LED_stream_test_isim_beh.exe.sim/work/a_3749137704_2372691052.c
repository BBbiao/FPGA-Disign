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
static const char *ng0 = "D:/Xilinx/workspace/LED_stream/LED_stream/LED_stream_test.vhd";
extern char *IEEE_P_2592010699;

char *ieee_p_2592010699_sub_393209765_503743352(char *, char *, char *, char *);


static void work_a_3749137704_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3872U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 4520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(93, ng0);
    t2 = (t0 + 2768U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3680);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 4520);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 2768U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3680);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_3749137704_2372691052_p_1(char *t0)
{
    char t18[16];
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
    int t19;
    unsigned int t20;
    unsigned int t21;

LAB0:    xsi_set_current_line(105, ng0);
    t2 = (t0 + 992U);
    t3 = xsi_signal_has_event(t2);
    if (t3 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:
LAB3:    t2 = (t0 + 4440);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(106, ng0);
    t4 = (t0 + 2888U);
    t8 = *((char **)t4);
    t4 = (t0 + 7732);
    t10 = 1;
    if (8U == 8U)
        goto LAB11;

LAB12:    t10 = 0;

LAB13:    if (t10 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 2888U);
    t4 = *((char **)t2);
    t2 = (t0 + 7668U);
    t5 = ieee_p_2592010699_sub_393209765_503743352(IEEE_P_2592010699, t18, t4, t2);
    t8 = (t18 + 12U);
    t11 = *((unsigned int *)t8);
    t11 = (t11 * 1U);
    t1 = (8U != t11);
    if (t1 == 1)
        goto LAB17;

LAB18:    t9 = (t0 + 4584);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    t14 = (t13 + 56U);
    t15 = *((char **)t14);
    memcpy(t15, t5, 8U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 2888U);
    t4 = *((char **)t2);
    t2 = xsi_vhdl_bitvec_sll(t2, t4, 8U, 1);
    t5 = (t0 + 2888U);
    t8 = *((char **)t5);
    t5 = (t8 + 0);
    memcpy(t5, t2, 8U);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t19 = (0 - 0);
    t11 = (t19 * 1);
    t20 = (1U * t11);
    t21 = (0 + t20);
    t2 = (t4 + t21);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 4648);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t19 = (1 - 0);
    t11 = (t19 * 1);
    t20 = (1U * t11);
    t21 = (0 + t20);
    t2 = (t4 + t21);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 4712);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(113, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t19 = (2 - 0);
    t11 = (t19 * 1);
    t20 = (1U * t11);
    t21 = (0 + t20);
    t2 = (t4 + t21);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 4776);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t19 = (3 - 0);
    t11 = (t19 * 1);
    t20 = (1U * t11);
    t21 = (0 + t20);
    t2 = (t4 + t21);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 4840);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t19 = (4 - 0);
    t11 = (t19 * 1);
    t20 = (1U * t11);
    t21 = (0 + t20);
    t2 = (t4 + t21);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 4904);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t19 = (5 - 0);
    t11 = (t19 * 1);
    t20 = (1U * t11);
    t21 = (0 + t20);
    t2 = (t4 + t21);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 4968);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t19 = (6 - 0);
    t11 = (t19 * 1);
    t20 = (1U * t11);
    t21 = (0 + t20);
    t2 = (t4 + t21);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 5032);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 2472U);
    t4 = *((char **)t2);
    t19 = (7 - 0);
    t11 = (t19 * 1);
    t20 = (1U * t11);
    t21 = (0 + t20);
    t2 = (t4 + t21);
    t1 = *((unsigned char *)t2);
    t5 = (t0 + 5096);
    t8 = (t5 + 56U);
    t9 = *((char **)t8);
    t12 = (t9 + 56U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = t1;
    xsi_driver_first_trans_fast(t5);

LAB9:    goto LAB3;

LAB5:    t4 = (t0 + 1032U);
    t5 = *((char **)t4);
    t6 = *((unsigned char *)t5);
    t7 = (t6 == (unsigned char)3);
    t1 = t7;
    goto LAB7;

LAB8:    xsi_set_current_line(107, ng0);
    t14 = (t0 + 7740);
    t16 = (t0 + 2888U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t14, 8U);
    goto LAB9;

LAB11:    t11 = 0;

LAB14:    if (t11 < 8U)
        goto LAB15;
    else
        goto LAB13;

LAB15:    t12 = (t8 + t11);
    t13 = (t4 + t11);
    if (*((unsigned char *)t12) != *((unsigned char *)t13))
        goto LAB12;

LAB16:    t11 = (t11 + 1);
    goto LAB14;

LAB17:    xsi_size_not_matching(8U, t11, 0);
    goto LAB18;

}


extern void work_a_3749137704_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3749137704_2372691052_p_0,(void *)work_a_3749137704_2372691052_p_1};
	xsi_register_didat("work_a_3749137704_2372691052", "isim/LED_stream_test_isim_beh.exe.sim/work/a_3749137704_2372691052.didat");
	xsi_register_executes(pe);
}
