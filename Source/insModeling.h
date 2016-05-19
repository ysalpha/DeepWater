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

#ifndef _INS_MODELING_H
#define _INS_MODELING_H

#include "regsModeling.h"
#include "dataTypeModeling.h"
#include "configuration.h"

extern long load_num;  //statistics of ins_num
extern long load_wait_time;
extern long load_fwait_time;
extern long load_execute_time;

extern long launch_num;
extern long launch_wait_time;
extern long launch_fwait_time;
extern long launch_execute_time;

extern long wb_num;
extern long wb_wait_time;
extern long wb_fwait_time;
extern long wb_execute_time;

extern long store_num;
extern long store_wait_time;
extern long store_fwait_time;
extern long store_execute_time;

extern long mov_num;
extern long mov_wait_time;
extern long mov_fwait_time;
extern long mov_execute_time;

extern long extmov_num;
extern long extmov_wait_time;
extern long extmov_fwait_time;
extern long extmov_execute_time;

extern long dmalr_num;
extern long dmalr_wait_time;
extern long dmalr_fwait_time;
extern long dmalr_execute_time;

extern long dmalc_num;
extern long dmalc_wait_time;
extern long dmalc_fwait_time;
extern long dmalc_execute_time;

extern long dmasr_num;
extern long dmasr_wait_time;
extern long dmasr_fwait_time;
extern long dmasr_execute_time;

extern long dmasc_num;
extern long dmasc_wait_time;
extern long dmasc_fwait_time;
extern long dmasc_execute_time;

extern long prodvm_num;
extern long prodvm_wait_time;
extern long prodvm_fwait_time;
extern long prodvm_execute_time;

extern long prodvmp_num;
extern long prodvmp_wait_time;
extern long prodvmp_fwait_time;
extern long prodvmp_execute_time;

extern long prodmv_num;
extern long prodmv_wait_time;
extern long prodmv_fwait_time;
extern long prodmv_execute_time;

extern long prodmvp_num;
extern long prodmvp_wait_time;
extern long prodmvp_fwait_time;
extern long prodmvp_execute_time;

extern long prodvv_num;
extern long prodvv_wait_time;
extern long prodvv_fwait_time;
extern long prodvv_execute_time;

extern long prodvvp_num;
extern long prodvvp_wait_time;
extern long prodvvp_fwait_time;
extern long prodvvp_execute_time;

extern long prodvvd_num;
extern long prodvvd_wait_time;
extern long prodvvd_fwait_time;
extern long prodvvd_execute_time;

extern long addv_num;
extern long addv_wait_time;
extern long addv_execute_time;
extern long addv_fwait_time;

extern long subv_num;
extern long subv_wait_time;
extern long subv_fwait_time;
extern long subv_execute_time;

extern long subm_num;
extern long subm_wait_time;
extern long subm_fwait_time;
extern long subm_execute_time;

extern long sum_num;
extern long sum_wait_time;
extern long sum_fwait_time;
extern long sum_execute_time;

extern long max_num;
extern long max_wait_time;
extern long max_fwait_time;
extern long max_execute_time;

extern long scale_num;
extern long scale_wait_time;
extern long scale_fwait_time;
extern long scale_execute_time;

extern long addm_num;
extern long addm_wait_time;
extern long addm_fwait_time;
extern long addm_execute_time;

extern long diff_num;
extern long diff_wait_time;
extern long diff_fwait_time;
extern long diff_execute_time;

extern long randgen_num;
extern long randgen_wait_time;
extern long randgen_fwait_time;
extern long randgen_execute_time;

extern long probcmp_num;
extern long probcmp_wait_time;
extern long probcmp_fwait_time;
extern long probcmp_execute_time;

extern long bias_num;
extern long bias_wait_time;
extern long bias_fwait_time;
extern long bias_execute_time;

extern long act_num;
extern long act_wait_time;
extern long act_fwait_time;
extern long act_execute_time;

extern long loop_num;

extern long endloop_num;


struct RVOPD_FORMAT
{
	int rg_num;
	G_RG* pRV;
};

struct BVOPD_FORMAT
{
	int  rg_num;
	G_RB* pBV;
};

struct MATOPD_FORMAT
{
	int mat_num;
	int row;
	int col;
	G_M* pMAT;
};

struct DMA_OPD
{
	long mem_addr;
	int length;
	int stride;
	int repetition;
	int buff_id;
	long buff_addr;
};

struct MEM_BUFF_OPD
{
	long mem_b_addr;
	int buff_id;
};

struct  INDIRECT_OPD
{
	int bufferId;
	int loopId;
	int addrId;
	int offset; 
};

struct LOOPID_OPD
{
	int loopId;
	int iterTimes;
};

struct LOOPADDR_OPD
{
	long stride;
	long addr;
};

union OPD
{
	DMA_OPD type_DMA;
	RVOPD_FORMAT type_RV;
	BVOPD_FORMAT type_BV;
	MATOPD_FORMAT type_MAT;
	MEM_BUFF_OPD type_BUFF;
	INDIRECT_OPD type_INDD;
	LOOPID_OPD type_LPID;
	LOOPADDR_OPD type_LPAD;
	bool accumul;
	bool indirctFlag;//标记是不是间接寻址
	PS_ENT_TYPE type_FD;
	long mem_addr;
	int length;
	int endloopid;
};

struct INS_OPD
{
	int type_flag;  // type_flag is used to mark the type of operand. '0' BV opd, '1' RV opd ,'2' RDV opd, '3' MAT opd, '4' immediate opd, '5' mem opd, '6' specialized dma opd, '7' specialized mem_buff opd
	OPD opd;
}; 


struct insStruction
{
	char instr[40];
	int opcode;
	INS_OPD op[4];    /* all of instructions are abstracted JLE four operands */
};

extern insStruction *ins;

#endif /* _INS_MODELING_H */
