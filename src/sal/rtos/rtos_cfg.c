/*
 * The MIT License (MIT)
 *
 * Copyright (c) [2015] [Marco Russi]
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

/*
 * This file rtos_cfg.c represents the source file of the RTOS configuration component.
 *
 * Author : Marco Russi
 *
 * Evolution of the file:
 * 06/08/2015 - File created - Marco Russi
 * 16/08/2015 - Added connectivity related tasks - Marco Russi
 *
*/


/* ------------- Inclusions ---------------- */

#include "../../fw_common.h"            /* common file */

#include "rtos_cfg.h"                   /* component RTOS configuration header file */

#include "../../hal/pwm.h"              /* component PWM header file */

#include "../ip/arp.h"                 /* component ARP header file */
#include "../ip/ipv4.h"                /* component IPv4 header file */
#include "../ip/icmp.h"                /* component ICMP header file */

#include "../../app_ip.h"           /* component UDP application header file */




/* -------------- Local Variables ------------------ */

/* INIT state tasks */
static task_ptr_t const initState_ap[] =
{
    /* ATTENTION: ETHMAC_Init, IPV4_Init and DHCP_Init functions are called by APP_UDP_Init */
    &APP_UDP_Init,
    NULL_PTR
};


/* NORMAL state tasks */
static task_ptr_t const normalState_ap[] =
{
    &ARP_PeriodicTask,
    &IPV4_PeriodicTask,
    &ICMP_PeriodicTask,
    &APP_UDP_PeriodicTask,
    NULL_PTR
};


/* SLEEP state tasks */
static task_ptr_t const sleepState_ap[] =
{
    NULL_PTR
};




/* ------------ Exported Variables ----------------- */

/* RTOS states array: This order shall be the same of RTOS_CFG_ke_states enum */
rtos_state_t * const RTOS_CFG_statesArray_at[RTOS_CFG_KE_STATE_MAX_NUM] =
{
    initState_ap
   ,normalState_ap
   ,sleepState_ap
};




/* End of file */
