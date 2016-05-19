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

#ifndef _PS_PIPE_LINE_H
#define _PS_PIPE_LINE_H

#include "configuration.h"
#include "regsModeling.h"
#include "memModeling.h"
#include "insModeling.h"

extern long ins_num;    /* record instructions number */

#define RST_FREE 0
#define RST_BUSY 1
#define STG_FREE 0
#define STG_BUSY 1
#define STG_READY 0
#define STG_NRDY 1
#define DECODE_CYCLE 1
#define FETCH_CYCLE 1
#define SBV1 "BV0"
#define SBV2 "BV1"
#define SBV3 "BV2"
#define SBV4 "BV3"

#define SRV1 "RV0"
#define SRV2 "RV1"
#define SRV3 "RV2"
#define SRV4 "RV3"
#define SRV5 "RV4"
#define SRV6 "RV5"
#define SRV7 "RV6"
#define SRV8 "RV7"
#define SRV9 "RV8"
#define SRV10 "RV9"
#define SRV11 "RV10"
#define SRV12 "RV11"
#define SRV13 "RV12"
#define SRV14 "RV13"
#define SRV15 "RV14"
#define SRV16 "RV15"

#define SRDV1 "RDV0"
#define SRDV2 "RDV1"
#define SRDV3 "RDV2"
#define SRDV4 "RDV3"

#define SEXTV1 "EXTV0"
#define SEXTV2 "EXTV1"
#define SEXTV3 "EXTV2"
#define SEXTV4 "EXTV3"
#define SEXTV5 "EXTV4"
#define SEXTV6 "EXTV5"
#define SEXTV7 "EXTV6"
#define SEXTV8 "EXTV7"

struct pipelinestate
{
	int fetch_st;
	long fetch_ins;
	bool fetch_if0;
	bool fetch_if1;
	int fetch_cycle;

	int decode_st;
	long decode_ins;
	bool decode_if0;
	bool decode_if1;
	int decode_cycle;

	bool exe_st0;
	bool exe_st1;
	int rtlMaxWord_i1;

	int loop_st;
	bool loop_if0;
	bool loop_if1;

	int endloop_st;
	bool endloop_if0;
	bool endloop_if1;

	int load_st;
	bool load_st_func;
	long load_ins;
	bool load_if0;
	bool load_if1;
	int load_cycle;

	int launch_st;
	bool launch_st_func;
	long launch_ins;
	bool launch_if0;
	bool launch_if1;
	int launch_cycle;

	int wb_st;
	bool wb_st_func;
	long wb_ins;
	bool wb_if0;
	bool wb_if1;
	int wb_cycle;

	int store_st;
	bool store_st_func;
	long store_ins;
	bool store_if0;
	bool store_if1;
	int store_cycle;

	int mov_st;
	bool mov_st_func;
	long mov_ins;
	bool mov_if0;
	bool mov_if1;
	int mov_cycle;

	int extmov_st;
	bool extmov_st_func;
	long extmov_ins;
	bool extmov_if0;
	bool extmov_if1;
	int extmov_cycle;

	int dmalr_st;
	long dmalr_ins;
	bool dmalr_if0;
	bool dmalr_if1;
	int dmalr_cycle;

	int dmalc_st;
	long dmalc_ins;
	bool dmalc_if0;
	bool dmalc_if1;
	int dmalc_cycle;

	int dmasr_st;
	long dmasr_ins;
	bool dmasr_if0;
	bool dmasr_if1;
	int dmasr_cycle;

	int dmasc_st;
	long dmasc_ins;
	bool dmasc_if0;
	bool dmasc_if1;
	int dmasc_cycle;

	int prodvm_st;
	long prodvm_ins;
	bool prodvm_if0;
	bool prodvm_if1;
	int prodvm_cycle;
	int prodvm_cycle_func;

	int prodvmp_st;
	long prodvmp_ins;
	bool prodvmp_if0;
	bool prodvmp_if1;
	int prodvmp_cycle;
	int prodvmp_cycle_func;

	int prodmv_st;
	long prodmv_ins;
	bool prodmv_if0;
	bool prodmv_if1;
	int prodmv_cycle;
	int prodmv_cycle_func;

	int prodmvp_st;
	long prodmvp_ins;
	bool prodmvp_if0;
	bool prodmvp_if1;
	int prodmvp_cycle;
	int prodmvp_cycle_func;

	int prodvv_st;
	long prodvv_ins;
	bool prodvv_if0;
	bool prodvv_if1;
	int prodvv_cycle;
	int prodvv_cycle_func;

	int prodvvp_st;
	long prodvvp_ins;
	bool prodvvp_if0;
	bool prodvvp_if1;
	int prodvvp_cycle;
	int prodvvp_cycle_func;

	int prodvvd_st;
	long prodvvd_ins;
	bool prodvvd_if0;
	bool prodvvd_if1;
	int prodvvd_cycle;
	int prodvvd_cycle_func;

	int addv_st;
	long addv_ins;
	bool addv_if0;
	bool addv_if1;
	int addv_cycle;
	int addv_cycle_func;

	int addm_st;
	long addm_ins;
	bool addm_if0;
	bool addm_if1;
	int addm_cycle;
	int addm_cycle_func;

	int subv_st;
	long subv_ins;
	bool subv_if0;
	bool subv_if1;
	int subv_cycle;
	int subv_cycle_func;

	int subm_st;
	long subm_ins;
	bool subm_if0;
	bool subm_if1;
	int subm_cycle;
	int subm_cycle_func;

	int sum_st;
	long sum_ins;
	bool sum_if0;
	bool sum_if1;
	int sum_cycle;
	int sum_cycle_func;

	int max_st;
	long max_ins;
	bool max_if0;
	bool max_if1;
	int max_cycle;
	int max_cycle_func;

	int scale_st;
	long scale_ins;
	bool scale_if0;
	bool scale_if1;
	int scale_cycle;
	int scale_cycle_func;

	int diff_st;
	long diff_ins;
	bool diff_if0;
	bool diff_if1;
	int diff_cycle;
	int diff_cycle_func;

	int randgen_st;
	long randgen_ins;
	bool randgen_if0;
	bool randgen_if1;
	int randgen_cycle;

	int probcmp_st;
	long probcmp_ins;
	bool probcmp_if0;
	bool probcmp_if1;
	int probcmp_cycle;
	int probcmp_cycle_func;

	int bias_st;
	long bias_ins;
	bool bias_if0;
	bool bias_if1;
	int bias_cycle;
	int bias_cycle_func;

	int act_st;
	long act_ins;
	bool act_if0;
	bool act_if1;
	int act_cycle;
	int act_cycle_func;
};
extern pipelinestate plst;

struct decodeoprand
{
	int opcode;
	long decode_ins;
	bool decode_v;
	INS_OPD op[4];
};

/* decode stage temporary queue */
//extern decodeoprand decode_i0[fetch_num],decode_i1[fetch_num];
extern decodeoprand *decode_i0,*decode_i1;
extern bool decode_end,fetch_success;

extern int decode_v_num,decode_f_num,fetch_f_num;

struct buff_fetch_ins
{
	long buff_fetch_num;
};

extern int fetch_of_num_i0,fetch_of_num_i1;
extern int decode_of_num_i1;
extern long fetch_n,*fetch_buff;
/* temporary decode stage decoded failure instructions */
//extern struct buff_fetch_ins buff_f_ins[fetch_num];
extern struct buff_fetch_ins *buff_f_ins;

struct ploprand
{
	bool is_exist_ins; //1 show to have a instruction 
	long ex_ins;
	INS_OPD op[4];
};

extern ploprand convTB[10];//temporary decode success ins,in the next cycle converted to binary

extern ploprand loop_i0[9],loop_i1[9];
extern ploprand endloop_i0[9],endloop_i1[9];

extern ploprand load_i0,*load_i1;
extern ploprand launch_i0,*launch_i1;
extern ploprand wb_i0,*wb_i1;
extern ploprand store_i0,*store_i1;
extern ploprand mov_i0,*mov_i1;
extern ploprand extmov_i0,*extmov_i1;
extern ploprand dmalr_i0,dmalr_i1;
extern ploprand dmalc_i0,dmalc_i1;
extern ploprand dmasr_i0,dmasr_i1;
extern ploprand dmasc_i0,dmasc_i1;
extern ploprand prodvm_i0,*prodvm_i1;
extern ploprand prodvmp_i0,*prodvmp_i1;
extern ploprand prodmv_i0,*prodmv_i1;
extern ploprand prodmvp_i0,*prodmvp_i1;
extern ploprand prodvv_i0,*prodvv_i1;
extern ploprand prodvvp_i0,*prodvvp_i1;
extern ploprand prodvvd_i0,*prodvvd_i1;
extern ploprand addv_i0,*addv_i1;
extern ploprand addm_i0,*addm_i1;
extern ploprand subv_i0,*subv_i1;
extern ploprand subm_i0,*subm_i1;
extern ploprand sum_i0,*sum_i1;
extern ploprand max_i0,*max_i1;
extern ploprand scale_i0,*scale_i1;
extern ploprand diff_i0,*diff_i1;
extern ploprand randgen_i0,randgen_i1;
extern ploprand probcmp_i0,*probcmp_i1;
extern ploprand bias_i0,*bias_i1;
extern ploprand act_i0,*act_i1;
/*
extern ploprand load_i0,load_i1[LOAD_CYCLE+1];
extern ploprand launch_i0,launch_i1[LAUNCH_CYCLE+1];
extern ploprand wb_i0,wb_i1[WB_CYCLE+1];
extern ploprand store_i0,store_i1[STORE_CYCLE+1];
extern ploprand mov_i0,mov_i1[MOV_CYCLE+1];
extern ploprand extmov_i0,extmov_i1[EXTMOV_CYCLE+1];
extern ploprand dmalr_i0,dmalr_i1;
extern ploprand dmalc_i0,dmalc_i1;
extern ploprand dmasr_i0,dmasr_i1;
extern ploprand dmasc_i0,dmasc_i1;
extern ploprand prodvm_i0,prodvm_i1[PRODVM_CYCLE+1];
extern ploprand prodvmp_i0,prodvmp_i1[PRODVMP_CYCLE+1];
extern ploprand prodmv_i0,prodmv_i1[PRODMVP_CYCLE+1];
extern ploprand prodmvp_i0,prodmvp_i1[PRODMVP_CYCLE+1];
extern ploprand prodvv_i0,prodvv_i1[PRODVV_CYCLE+1];
extern ploprand prodvvp_i0,prodvvp_i1[PRODVVP_CYCLE+1];
extern ploprand prodvvd_i0,prodvvd_i1[PRODVVD_CYCLE+1];
extern ploprand addv_i0,addv_i1[ADDV_CYCLE+1];
extern ploprand addm_i0,addm_i1[ADDM_CYCLE+1];
extern ploprand subv_i0,subv_i1[SUBV_CYCLE+1];
extern ploprand subm_i0,subm_i1[SUBM_CYCLE+1];
extern ploprand sum_i0,sum_i1[SUM_CYCLE+1];
extern ploprand max_i0,max_i1[MAX_CYCLE+1];
extern ploprand scale_i0,scale_i1[SCALE_CYCLE+1];
extern ploprand diff_i0,diff_i1[DIFF_CYCLE+1];
extern ploprand randgen_i0,randgen_i1;
extern ploprand probcmp_i0,probcmp_i1[PROBCMP_CYCLE+1];
extern ploprand bias_i0,bias_i1[BIAS_CYCLE+1];
extern ploprand act_i0,act_i1[ACT_CYCLE+1];*/

extern void init_pl_scratchpad();

extern bool isFreeNeuroUnit;
extern bool isFreeMathFunc;
extern int rtlMaxWord;

extern bool onlyDma;

extern bool Initrgs();
extern bool Initpl();
extern bool judend();
extern void zeroDecode_i1();
extern void zeroBuff_f_ins();

#endif /* _PS_PIPE_LINE_H */
