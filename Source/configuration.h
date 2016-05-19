/*
 * Copyright (c) 2016
 * Research Group: ERA (Efficient and Resilient Architecture group) 
 * Contributors:  Shijun Gong, Wenyan Lu, Jiajun Li, Shuhao Jiang, Jingya Wu, and Guihai Yan  
 * Affiliation: State Key Laboratory of Computer Architecture, Institute of Computing Technology, Chinese Academy of Sciences
 * Contact Info.:   {gongshijun, yan}@ict.ac.cn
 * Web: http://www.carch.ac.cn/~yan
 * Address:  P.O.Box 2704, Beijing, 100190, China
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

#include <stdio.h>

extern void matchConfLabel(FILE **fp_conf,int repStr,char*);
extern void matchConfINS(FILE **fp_conf);
extern int configurePS();

#include "ins_opcode.h"

/* [regs] */
/* #register entry size */
extern int RG_SIZE;
/* #RV register number */
extern int RG_NUM;
/* #BV register number */
extern int BV_NUM;
/* #RDV register number */
extern int RDV_NUM;
/* #EXTV register number */
extern int EXTV_NUM;
/* #MAT structure entry size */
extern int V_SIZE;
/* #MAT structure number */
extern int V_NUM;
/* #NAT structure layer number */
extern int M_LAYER;


/* [memory]
#initial memory size */
extern int INIT_MEM_SIZE;

/* [ins] */
extern char SLOAD[20];
extern int LOAD_CYCLE;
extern int loadWordConsumed;

extern char SSTORE[20];
extern int STORE_CYCLE;
extern int storeWordConsumed;

extern char SLAUNCH[20];
extern int LAUNCH_CYCLE;
extern int launchWordConsumed;

extern char SWB[20];
extern int WB_CYCLE;
extern int wbWordConsumed;

extern char SMOV[20];
extern int MOV_CYCLE;
extern int movWordConsumed;

extern char SEXTMOV[20];
extern int EXTMOV_CYCLE;
extern int extmovWordConsumed;

extern char SDMALR[20];
extern int DMALR_CYCLE;
extern int dmalrWordConsumed;

extern char SDMALC[20];
extern int DMALC_CYCLE;
extern int dmalcWordConsumed;

extern char SDMASR[20];
extern int DMASR_CYCLE;
extern int dmasrWordConsumed;

extern char SDMASC[20];
extern int DMASC_CYCLE;
extern int dmascWordConsumed;

extern char SPRODVM[20];
extern int PRODVM_CYCLE;
extern int prodvmWordConsumed;

extern char SPRODVMP[20];
extern int PRODVMP_CYCLE;
extern int prodvmpWordConsumed;

extern char SPRODMV[20];
extern int PRODMV_CYCLE;
extern int prodmvWordConsumed;

extern char SPRODMVP[20];
extern int PRODMVP_CYCLE;
extern int prodmvpWordConsumed;

extern char SPRODVV[20];
extern int PRODVV_CYCLE;
extern int prodvvWordConsumed;

extern char SPRODVVP[20];
extern int PRODVVP_CYCLE;
extern int prodvvpWordConsumed;

extern char SPRODVVD[20];
extern int PRODVVD_CYCLE;
extern int prodvvdWordConsumed;

extern char SADDV[20];
extern int ADDV_CYCLE;
extern int addvWordConsumed;

extern char SSUBV[20];
extern int SUBV_CYCLE;
extern int subvWordConsumed;

extern char SSUBM[20];
extern int SUBM_CYCLE;
extern int submWordConsumed;

extern char SSUM[20];
extern int SUM_CYCLE;
extern int SUM_CYCLE_FUNC;
extern int sumWordConsumed;

extern char SMAX[20];
extern int MAX_CYCLE;
extern int MAX_CYCLE_FUNC;
extern int maxWordConsumed;

extern char SSCALE[20];
extern int SCALE_CYCLE;
extern int SCALE_CYCLE_FUNC;
extern int scaleWordConsumed;

extern char SADDM[20];
extern int ADDM_CYCLE;
extern int ADDM_CYCLE_FUNC;
extern int addmWordConsumed;

extern char SDIFF[20];
extern int DIFF_CYCLE;
extern int DIFF_CYCLE_FUNC;
extern int diffWordConsumed;

extern char SRANDGEN[20];
extern int RANDGEN_CYCLE;
extern int randgenWordConsumed;

extern char SPROBCMP[20];
extern int PROBCMP_CYCLE;
extern int PROBCMP_CYCLE_FUNC;
extern int probcmpWordConsumed;

extern char SBIAS[20];
extern int BIAS_CYCLE;
extern int BIAS_CYCLE_FUNC;
extern int biasWordConsumed;

extern char SACT[20];
extern int ACT_CYCLE;
extern int ACT_CYCLE_FUNC;
extern int actWordConsumed;

extern char SLOOP[20];
extern int loopWordConsumed;

extern char SENDLOOP[20];
extern int endloopWordConsumed;


/* [pipeline] */
extern int fetch_num;
extern int RTL_A_WORD;

/*[localBuffer]*/
extern int MEM_BUFF_ENTRY_SIZE;
extern int MEM_BUFF_BANK_SIZE;

/* [pulsesim mode] */
/* ps_mode = 1 -> pulsesim just quickly get program-running data
ps_mode = 2 -> pulsesim will generate some data of performance
ps_mode = 3 -> pulsesim will generate RTL binary code
ps_mode = 4 -> pulsesim include ps_mode = 2 and ps_mode = 3
ps_mode = 5 -> pulsesim will generate DEBUG information
*/
extern short ps_mode;
extern short qGetD;
extern short rtlD;
extern short perfD;
extern short allF;
extern short dugD;

/*
#define RG_SIZE 16 //the size of every register file
#define RG_NUM 16 // the register vector number of a register group
#define BV_NUM 4 // the register vector number of BV register group
#define RDV_NUM 4 // the register vector number of RDV register group
#define EXTV_NUM 8 // the register vector number of EXTV register group
//#define R_RD_PORT 2 //the read port number of one register group
//#define R_WR_PORT 1 //the write port number of one register group

#define V_SIZE 16 //the element number of every row
#define V_NUM 16 // the row number for every MAT layer
#define M_LAYER 8 //the total mat layer number

#define INIT_MEM_SIZE 8192*/
extern long MM_add_start,MM_add_end;

/*
#define SLOAD "load"
#define LOAD_CYCLE 3
#define LOAD_OPCODE 0
#define loadWordConsumed 2

#define SLAUNCH "launch"
#define LAUNCH_CYCLE 3
#define LAUNCH_OPCODE 2
#define launchWordConsumed 2

#define SWB "wb"
#define WB_CYCLE 2
#define WB_OPCODE 6
#define wbWordConsumed 2

#define SSTORE "store"
#define STORE_CYCLE 2
#define STORE_OPCODE 3
#define storeWordConsumed 2

#define SMOV "mov"
#define MOV_CYCLE 2
#define MOV_OPCODE 4
#define movWordConsumed 1

#define SEXTMOV "extmov"
#define EXTMOV_CYCLE 2
#define EXTMOV_OPCODE 5
#define extmovWordConsumed 1

#define SDMALR "dmalr"
#define DMALR_CYCLE 256
#define DMALR_OPCODE 30
#define dmalrWordConsumed 3

#define SDMALC "dmalc"
#define DMALC_CYCLE 256
#define DMALC_OPCODE 31
#define dmalcWordConsumed 3

#define SDMASR "dmasr"
#define DMASR_CYCLE 256
#define DMASR_OPCODE 32
#define dmasrWordConsumed 3

#define SDMASC "dmasc"
#define DMASC_CYCLE 256
#define DMASC_OPCODE 33
#define dmascWordConsumed 3

#define SPRODVM "prodvm"
#define PRODVM_CYCLE 5
#define PRODVM_OPCODE 8
#define prodvmWordConsumed 1

#define SPRODVMP "prodvmp"
#define PRODVMP_CYCLE 5
#define PRODVMP_OPCODE 13
#define prodvmpWordConsumed 1

#define SPRODMV "prodmv"
#define PRODMV_CYCLE 5
#define PRODMV_OPCODE 9
#define prodmvWordConsumed 1

#define SPRODMVP "prodmvp"
#define PRODMVP_CYCLE 5
#define PRODMVP_OPCODE 14
#define prodmvpWordConsumed 1

#define SPRODVV "prodvv"
#define PRODVV_CYCLE 5
#define PRODVV_OPCODE 10
#define prodvvWordConsumed 1

#define SPRODVVP "prodvvp"
#define PRODVVP_CYCLE 5
#define PRODVVP_OPCODE 15
#define prodvvpWordConsumed 1

#define SPRODVVD "prodvvd"
#define PRODVVD_CYCLE 5
#define PRODVVD_OPCODE 11
#define prodvvdWordConsumed 1

#define SADDV "addv"
#define ADDV_CYCLE 5
#define ADDV_OPCODE 12
#define addvWordConsumed 1

#define SSUBV "subv"
#define SUBV_CYCLE 5
#define SUBV_OPCODE 16
#define subvWordConsumed 1

#define SSUBM "subm"
#define SUBM_CYCLE 5
#define SUBM_OPCODE 17
#define submWordConsumed 1

#define SSUM "sum"
#define SUM_CYCLE 5
#define SUM_CYCLE_FUNC 1
#define SUM_OPCODE 18
#define sumWordConsumed 1

#define SMAX "max"
#define MAX_CYCLE 5
#define MAX_CYCLE_FUNC 1
#define MAX_OPCODE 19
#define maxWordConsumed 1

#define SSCALE "scale"
#define SCALE_CYCLE 5
#define SCALE_CYCLE_FUNC 1
#define SCALE_OPCODE 20
#define scaleWordConsumed 1

#define SADDM "addm"
#define ADDM_CYCLE 5
#define ADDM_CYCLE_FUNC 1
#define ADDM_OPCODE 21
#define addmWordConsumed 1

#define SDIFF "diff"
#define DIFF_CYCLE 5
#define DIFF_CYCLE_FUNC 1
#define DIFF_OPCODE 22
#define diffWordConsumed 1

#define SRANDGEN "randgen"
#define RANDGEN_CYCLE 2
#define RANDGEN_OPCODE 23
#define randgenWordConsumed 1

#define SPROBCMP "probcmp"
#define PROBCMP_CYCLE 5
#define PROBCMP_CYCLE_FUNC 1
#define PROBCMP_OPCODE 24
#define probcmpWordConsumed 1

#define SBIAS "bias"
#define BIAS_CYCLE 5
#define BIAS_CYCLE_FUNC 1
#define BIAS_OPCODE 25
#define biasWordConsumed 1

#define SACT "act"
#define ACT_CYCLE 5
#define ACT_CYCLE_FUNC 1
#define ACT_OPCODE 26
#define actWordConsumed 1

#define SLOOP "loop"
#define LOOP_OPCODE 27
#define loopWordConsumed 1

#define SENDLOOP "endloop"
#define ENDLOOP_OPCODE 28
#define endloopWordConsumed 1
*/

/* option configuration */
#define OP_VALID 0
#define OP_NVALID 1

#define DEFAULT_REPORT 0
#define DEBUG_REPORT 1

#define DEFAULT_DEBUG 0
#define DEFAULT_PBRD 0

extern bool stdebug_fl;
extern bool report_fl;
extern bool stdebug_ck;
extern bool print_br_data;
extern bool print_rv_mat_data; //mark whether print regs and mat data\A3\ACdefault not print\A3\ACnot print in development mode
extern bool development_model; //mark whether in development mode,1 show in development mode

extern long delay_times;  // delay_times show the pipeline to be delaying cycles
extern bool allow_delay;  // 1 show the pipeline to allow delay
extern long delay_insAddr; // show to delay pipeline after the number that is about of instructions is delay_insAddr
extern bool isDelay;  // 1 show to delay pipeline a cycle in the next cycle 

/* local buffer configuration */
//#define MEM_BUFF_ENTRY_SIZE 1024
//#define MEM_BUFF_BANK_SIZE 256

#define MEM_BUFF_BOLCK_NUM 16
#define MEM_BUFF_BOLCK_SIZE 16


//#define fetch_num 10

#define plNeuroCalcUnitNum 1
#define noNeurCalcUnit 0

//#define RTL_A_WORD 5

/* pipeline kernel */
//mark is the stall cycle of pipeline//
extern bool isDecodeDelay;

//declare th variant of the cycle number of stall cycle//
extern long decodeDelayCycle;
extern bool isToRTL;

#endif
