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

/*
 * ps pipeline
 *
 * Complete pipeline simulation initialization
 */

#include <memory.h>
#include <stdlib.h>

#include "ps_pipeline.h"

G_RG *RV,*RDV,*EXTV;
G_RB *BV;
G_M **MAT;

G_RG *PRV,*PRDV,*PEXTV;
G_RB *PBV;
G_M **PMAT;

G_MB Mbuffer;
RG Rbuffer,Cbuffer;

G_MB PMbuffer;
RG PRbuffer,PCbuffer;

/*initialize the group RV register*/
void init_RV()
{
	int i;
	//RV->R_V->V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*RG_SIZE);
	//RV->R_V    = (RG *)malloc(sizeof(RV->R_V)*RG_NUM);
	RV = (G_RG*)malloc(sizeof(G_RG));
	/* dynamic allocation RV register memory */
	RV->R_V = (RG*)malloc(sizeof(RG)*RG_NUM);
	RV->readnum = 0;
	RV->writenum = 0;
	for(i=0;i<RG_NUM;i++)
	{
		//		RV->R_V[i] = (RG)malloc(sizeof(RG));
		RV->R_V[i].RD_S = INVALID;
		RV->R_V[i].WR_S = INVALID;
		RV->R_V[i].WRD_S = INVALID;
		RV->R_V[i].WWR_S = INVALID;
		RV->R_V[i].V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*RG_SIZE);
		memset(RV->R_V[i].V,0,sizeof(PS_ENT_TYPE)*RG_SIZE);
	}

	PRV = (G_RG*)malloc(sizeof(G_RG));
	PRV->R_V = (RG*)malloc(sizeof(RG)*RG_NUM);
	PRV->readnum = 0;
	PRV->writenum = 0;
	for(i=0;i<RG_NUM;i++)
	{
		//		RV->R_V[i] = (RG)malloc(sizeof(RG));
		PRV->R_V[i].RD_S = INVALID;
		PRV->R_V[i].WR_S = INVALID;
		PRV->R_V[i].WRD_S = INVALID;
		PRV->R_V[i].WWR_S = INVALID;
		PRV->R_V[i].V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*RG_SIZE);
		memset(PRV->R_V[i].V,0,sizeof(PS_ENT_TYPE)*RG_SIZE);
	}
}

/*initialize the group EXTV register*/
void init_EXTV()
{
	int i;
	EXTV = (G_RG*)malloc(sizeof(G_RG));
	EXTV->R_V = (RG*)malloc(sizeof(RG)*EXTV_NUM);
	EXTV->readnum = 0;
	EXTV->writenum = 0;
	for(i=0;i<EXTV_NUM;i++)
	{
		//		EXTV->R_V[i] = (RG)malloc(sizeof(RG));
		EXTV->R_V[i].RD_S = INVALID;
		EXTV->R_V[i].WR_S = INVALID;
		EXTV->R_V[i].WRD_S = INVALID;
		EXTV->R_V[i].WWR_S = INVALID;
		EXTV->R_V[i].V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*RG_SIZE);
		memset(EXTV->R_V[i].V,0,sizeof(PS_ENT_TYPE)*RG_SIZE);
	}

	PEXTV = (G_RG*)malloc(sizeof(G_RG));
	PEXTV->R_V = (RG*)malloc(sizeof(RG)*EXTV_NUM);
	PEXTV->readnum = 0;
	PEXTV->writenum = 0;
	for(i=0;i<EXTV_NUM;i++)
	{
		//		EXTV->R_V[i] = (RG)malloc(sizeof(RG));
		PEXTV->R_V[i].RD_S = INVALID;
		PEXTV->R_V[i].WR_S = INVALID;
		PEXTV->R_V[i].WRD_S = INVALID;
		PEXTV->R_V[i].WWR_S = INVALID;
		PEXTV->R_V[i].V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*RG_SIZE);
		memset(PEXTV->R_V[i].V,0,sizeof(PS_ENT_TYPE)*RG_SIZE);
	}
}

/*initialize the group RDV register*/
void init_RDV()
{
	int i;
	RDV = (G_RG*)malloc(sizeof(G_RG));
	RDV->R_V = (RG*)malloc(sizeof(RG)*RDV_NUM);
	RDV->readnum = 0;
	RDV->writenum = 0;
	for(i=0;i<RDV_NUM;i++)
	{
		//	RDV->R_V[i] = (RG*)malloc(sizeof(RG));
		RDV->R_V[i].RD_S = INVALID;
		RDV->R_V[i].WR_S = INVALID;
		RDV->R_V[i].WRD_S = INVALID;
		RDV->R_V[i].WWR_S = INVALID;
		RDV->R_V[i].V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*RG_SIZE);
		memset(RDV->R_V[i].V,0,sizeof(PS_ENT_TYPE)*RG_SIZE);
	}

	PRDV = (G_RG*)malloc(sizeof(G_RG));
	PRDV->R_V = (RG*)malloc(sizeof(RG)*RDV_NUM);
	PRDV->readnum = 0;
	PRDV->writenum = 0;
	for(i=0;i<RDV_NUM;i++)
	{
		//	RDV->R_V[i] = (RG*)malloc(sizeof(RG));
		PRDV->R_V[i].RD_S = INVALID;
		PRDV->R_V[i].WR_S = INVALID;
		PRDV->R_V[i].WRD_S = INVALID;
		PRDV->R_V[i].WWR_S = INVALID;
		PRDV->R_V[i].V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*RG_SIZE);
		memset(PRDV->R_V[i].V,0,sizeof(PS_ENT_TYPE)*RG_SIZE);
	}
}

/*initialize the group BV register*/
void init_BV()
{
	int i;
	BV = (G_RB*)malloc(sizeof(G_RB));
	BV->R_V = (RB *)malloc(sizeof(RB)*BV_NUM);
	//BV->readnum = 0;
	//BV->writenum = 0;
	for(i=0;i<BV_NUM;i++)
	{
		//		BV->R_V[i] = (RB*)malloc(sizeof(RB));
		BV->R_V[i].RD_S = INVALID;
		BV->R_V[i].WR_S = INVALID;
		BV->R_V[i].WRD_S = INVALID;
		BV->R_V[i].WWR_S = INVALID;
		BV->R_V[i].V = (bool*)malloc(sizeof(bool)*RG_SIZE);
		memset(BV->R_V[i].V,0,sizeof(bool)*RG_SIZE);
	}

	PBV = (G_RB*)malloc(sizeof(G_RB));
	PBV->R_V = (RB *)malloc(sizeof(RB)*BV_NUM);
	//BV->readnum = 0;
	//BV->writenum = 0;
	for(i=0;i<BV_NUM;i++)
	{
		//		BV->R_V[i] = (RB*)malloc(sizeof(RB));
		PBV->R_V[i].RD_S = INVALID;
		PBV->R_V[i].WR_S = INVALID;
		PBV->R_V[i].WRD_S = INVALID;
		PBV->R_V[i].WWR_S = INVALID;
		PBV->R_V[i].V = (bool *)malloc(sizeof(bool)*RG_SIZE);
		memset(PBV->R_V[i].V,0,sizeof(bool)*RG_SIZE);
	}
}

/*initialize the MAT*/
void init_MAT()
{
	int i,j;
	MAT = (G_M **)malloc(sizeof(G_M*)*M_LAYER);
	for(i=0;i<M_LAYER;i++)
	{
		MAT[i] = (G_M*)malloc(sizeof(G_M));
		MAT[i]->M_V = (MG *)malloc(sizeof(MG)*V_NUM);
		j = 0;
		for(;j<V_NUM;j++)
		{
			//			MAT[i].M_V[j] = (MG*)malloc(sizeof(MG));
			MAT[i]->M_V[j].RD_S = INVALID;
			MAT[i]->M_V[j].WR_S = INVALID;
			MAT[i]->M_V[j].WRD_S = INVALID;
			MAT[i]->M_V[j].WWR_S = INVALID;
			MAT[i]->M_V[j].V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*V_SIZE);
			memset(MAT[i]->M_V[j].V,0,sizeof(PS_ENT_TYPE)*V_SIZE);
		}
	}

	PMAT = (G_M **)malloc(sizeof(G_M*)*M_LAYER);
	for(i=0;i<M_LAYER;i++)
	{
		PMAT[i] = (G_M*)malloc(sizeof(G_M));
		PMAT[i]->M_V = (MG *)malloc(sizeof(MG)*V_NUM);
		j = 0;
		for(;j<V_NUM;j++)
		{
			//			MAT[i].M_V[j] = (MG*)malloc(sizeof(MG));
			PMAT[i]->M_V[j].RD_S = INVALID;
			PMAT[i]->M_V[j].WR_S = INVALID;
			PMAT[i]->M_V[j].WRD_S = INVALID;
			PMAT[i]->M_V[j].WWR_S = INVALID;
			PMAT[i]->M_V[j].V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*V_SIZE);
			memset(PMAT[i]->M_V[j].V,0,sizeof(PS_ENT_TYPE)*V_SIZE);
		}
	}
}

/*initialize the Rbuffer, Cbuffer, Mbuffer */
void init_BUFF()
{
	int i=0;
	Rbuffer.RD_S = INVALID;
	Rbuffer.WRD_S = INVALID;
	Rbuffer.WR_S = INVALID;
	Rbuffer.WWR_S = INVALID;
	Rbuffer.V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*V_SIZE);
	memset(Rbuffer.V,0,sizeof(PS_ENT_TYPE)*V_SIZE);

	Cbuffer.RD_S = INVALID;
	Cbuffer.WRD_S = INVALID;
	Cbuffer.WR_S = INVALID;
	Cbuffer.WWR_S = INVALID;
	Cbuffer.V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*V_SIZE);
	memset(Cbuffer.V,0,sizeof(PS_ENT_TYPE)*V_SIZE);

	Mbuffer.RD_S = INVALID;
	Mbuffer.WRD_S = INVALID;
	Mbuffer.WR_S = INVALID;
	Mbuffer.WWR_S = INVALID;
	Mbuffer.V = (PS_PTR_TYPE *)malloc(sizeof(PS_PTR_TYPE)*V_NUM);
	for(i=0;i<V_NUM;i++)
	{
		Mbuffer.V[i] = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*V_SIZE);
		memset(Mbuffer.V[i],0,sizeof(PS_ENT_TYPE)*V_SIZE);
	}
	//memset(Mbuffer.V,0,sizeof(PS_ENT_TYPE)*V_SIZE*V_NUM);

	PRbuffer.RD_S = INVALID;
	PRbuffer.WRD_S = INVALID;
	PRbuffer.WR_S = INVALID;
	PRbuffer.WWR_S = INVALID;
	PRbuffer.V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*V_SIZE);
	memset(PRbuffer.V,0,sizeof(PS_ENT_TYPE)*V_SIZE);

	PCbuffer.RD_S = INVALID;
	PCbuffer.WRD_S = INVALID;
	PCbuffer.WR_S = INVALID;
	PCbuffer.WWR_S = INVALID;
	PCbuffer.V = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*V_SIZE);
	memset(PCbuffer.V,0,sizeof(PS_ENT_TYPE)*V_SIZE);

	PMbuffer.RD_S = INVALID;
	PMbuffer.WRD_S = INVALID;
	PMbuffer.WR_S = INVALID;
	PMbuffer.WWR_S = INVALID;
	PMbuffer.V = (PS_PTR_TYPE *)malloc(sizeof(PS_PTR_TYPE)*V_NUM);
	for(i=0;i<V_NUM;i++)
	{
		PMbuffer.V[i] = (PS_PTR_TYPE)malloc(sizeof(PS_ENT_TYPE)*V_SIZE);
		memset(PMbuffer.V[i],0,sizeof(PS_ENT_TYPE)*V_SIZE);
	}
	//memset(PMbuffer.V,0,sizeof(PS_ENT_TYPE)*V_SIZE*V_NUM);

}

M_M *MM;

/* initialize the memory array */
void init_MEM()
{
	MM = (M_M *)malloc(sizeof(M_M)*INIT_MEM_SIZE);
	memset(MM,0,sizeof(M_M)*INIT_MEM_SIZE);
}

bool isFreeNeuroUnit=plNeuroCalcUnitNum;
bool isFreeMathFunc = 1;
int rtlMaxWord=0;  //default 0 show not fetch any-instructions
bool onlyDma=1;

long load_num=0;  //statistics of ins_num
long load_wait_time=0;
long load_fwait_time=0;
long load_execute_time=0;

long launch_num=0;
long launch_wait_time=0;
long launch_fwait_time=0;
long launch_execute_time=0;

long wb_num=0;
long wb_wait_time=0;
long wb_fwait_time=0;
long wb_execute_time=0;

long store_num=0;
long store_wait_time=0;
long store_fwait_time=0;
long store_execute_time=0;

long mov_num=0;
long mov_wait_time=0;
long mov_fwait_time=0;
long mov_execute_time=0;

long extmov_num=0;
long extmov_wait_time=0;
long extmov_fwait_time=0;
long extmov_execute_time=0;

long dmalr_num;
long dmalr_wait_time;
long dmalr_fwait_time;
long dmalr_execute_time;

long dmalc_num;
long dmalc_wait_time;
long dmalc_fwait_time;
long dmalc_execute_time;

long dmasr_num;
long dmasr_wait_time;
long dmasr_fwait_time;
long dmasr_execute_time;

long dmasc_num;
long dmasc_wait_time;
long dmasc_fwait_time;
long dmasc_execute_time;

long prodvm_num=0;
long prodvm_wait_time=0;
long prodvm_fwait_time=0;
long prodvm_execute_time=0;

long prodvmp_num=0;
long prodvmp_wait_time=0;
long prodvmp_fwait_time=0;
long prodvmp_execute_time=0;

long prodmv_num=0;
long prodmv_wait_time=0;
long prodmv_fwait_time=0;
long prodmv_execute_time=0;

long prodmvp_num=0;
long prodmvp_wait_time=0;
long prodmvp_fwait_time=0;
long prodmvp_execute_time=0;

long prodvv_num=0;
long prodvv_wait_time=0;
long prodvv_fwait_time=0;
long prodvv_execute_time=0;

long prodvvp_num=0;
long prodvvp_wait_time=0;
long prodvvp_fwait_time=0;
long prodvvp_execute_time=0;

long prodvvd_num=0;
long prodvvd_wait_time=0;
long prodvvd_fwait_time=0;
long prodvvd_execute_time=0;

long addv_num=0;
long addv_wait_time=0;
long addv_execute_time=0;
long addv_fwait_time=0;

long subv_num=0;
long subv_wait_time=0;
long subv_fwait_time=0;
long subv_execute_time=0;

long subm_num=0;
long subm_wait_time=0;
long subm_fwait_time=0;
long subm_execute_time=0;

long sum_num=0;
long sum_wait_time=0;
long sum_fwait_time=0;
long sum_execute_time=0;

long max_num=0;
long max_wait_time=0;
long max_fwait_time=0;
long max_execute_time=0;

long scale_num=0;
long scale_wait_time=0;
long scale_fwait_time=0;
long scale_execute_time=0;

long addm_num=0;
long addm_wait_time=0;
long addm_fwait_time=0;
long addm_execute_time=0;

long diff_num=0;
long diff_wait_time=0;
long diff_fwait_time=0;
long diff_execute_time=0;

long randgen_num=0;
long randgen_wait_time=0;
long randgen_fwait_time=0;
long randgen_execute_time=0;

long probcmp_num=0;
long probcmp_wait_time=0;
long probcmp_fwait_time=0;
long probcmp_execute_time=0;

long bias_num=0;
long bias_wait_time=0;
long bias_fwait_time=0;
long bias_execute_time=0;

long act_num=0;
long act_wait_time=0;
long act_fwait_time=0;
long act_execute_time=0;

long loop_num=0;

long endloop_num=0;

insStruction *ins;

long ins_num = 0;

pipelinestate plst;


decodeoprand *decode_i0,*decode_i1;
bool decode_end=0,fetch_success=1;

int decode_v_num=0,decode_f_num=0,fetch_f_num=0;

int fetch_of_num_i0=0,fetch_of_num_i1=0;
int decode_of_num_i1=0;
/* fetch stage instruction address temporary */
long fetch_n=0,*fetch_buff;
struct buff_fetch_ins *buff_f_ins;

ploprand convTB[10];

ploprand loop_i0[9],loop_i1[9];
ploprand endloop_i0[9],endloop_i1[9];

ploprand load_i0,*load_i1;
ploprand launch_i0,*launch_i1;
ploprand wb_i0,*wb_i1;
ploprand store_i0,*store_i1;
ploprand mov_i0,*mov_i1;
ploprand extmov_i0,*extmov_i1;
ploprand dmalr_i0,dmalr_i1;
ploprand dmalc_i0,dmalc_i1;
ploprand dmasr_i0,dmasr_i1;
ploprand dmasc_i0,dmasc_i1;
ploprand prodvm_i0,*prodvm_i1;
ploprand prodvmp_i0,*prodvmp_i1;
ploprand prodmv_i0,*prodmv_i1;
ploprand prodmvp_i0,*prodmvp_i1;
ploprand prodvv_i0,*prodvv_i1;
ploprand prodvvp_i0,*prodvvp_i1;
ploprand prodvvd_i0,*prodvvd_i1;
ploprand addv_i0,*addv_i1;
ploprand addm_i0,*addm_i1;
ploprand subv_i0,*subv_i1;
ploprand subm_i0,*subm_i1;
ploprand sum_i0,*sum_i1;
ploprand max_i0,*max_i1;
ploprand scale_i0,*scale_i1;
ploprand diff_i0,*diff_i1;
ploprand randgen_i0,randgen_i1;
ploprand probcmp_i0,*probcmp_i1;
ploprand bias_i0,*bias_i1;
ploprand act_i0,*act_i1;

/* initialize the execution unit temporary storage decoded instruction */
void init_pl_scratchpad()
{
	memset(convTB,0,sizeof(convTB));

	load_i1 = (ploprand *)malloc(sizeof(ploprand)*(LOAD_CYCLE+1));
	memset(load_i1,0,sizeof(ploprand)*(LOAD_CYCLE+1));

	launch_i1 = (ploprand*)malloc(sizeof(ploprand)*(LAUNCH_CYCLE+1));
	memset(launch_i1,0,sizeof(ploprand)*(LAUNCH_CYCLE+1));

	wb_i1 = (ploprand*)malloc(sizeof(ploprand)*(WB_CYCLE+1));
	memset(wb_i1,0,sizeof(ploprand)*(WB_CYCLE+1));

	store_i1 = (ploprand*)malloc(sizeof(ploprand)*(STORE_CYCLE+1));
	memset(store_i1,0,sizeof(ploprand)*(STORE_CYCLE+1));

	mov_i1 = (ploprand*)malloc(sizeof(ploprand)*(MOV_CYCLE+1));
	memset(mov_i1,0,sizeof(ploprand)*(MOV_CYCLE+1));

	extmov_i1 = (ploprand*)malloc(sizeof(ploprand)*(EXTMOV_CYCLE+1));
	memset(extmov_i1,0,sizeof(ploprand)*(EXTMOV_CYCLE+1));

	prodvm_i1 = (ploprand*)malloc(sizeof(ploprand)*(PRODVM_CYCLE+1));
	memset(prodvm_i1,0,sizeof(ploprand)*(PRODVM_CYCLE+1));

	prodvmp_i1 = (ploprand*)malloc(sizeof(ploprand)*(PRODVMP_CYCLE+1));
	memset(prodvmp_i1,0,sizeof(ploprand)*(PRODVMP_CYCLE+1));

	prodmv_i1 = (ploprand*)malloc(sizeof(ploprand)*(PRODMV_CYCLE+1));
	memset(prodmv_i1,0,sizeof(ploprand)*(PRODMV_CYCLE+1));

	prodmvp_i1 = (ploprand*)malloc(sizeof(ploprand)*(PRODMVP_CYCLE+1));
	memset(prodmvp_i1,0,sizeof(ploprand)*(PRODMVP_CYCLE+1));

	prodvv_i1 = (ploprand*)malloc(sizeof(ploprand)*(PRODVV_CYCLE+1));
	memset(prodvv_i1,0,sizeof(ploprand)*(PRODVV_CYCLE+1));

	prodvvp_i1 = (ploprand*)malloc(sizeof(ploprand)*(PRODVVP_CYCLE+1));
	memset(prodvvp_i1,0,sizeof(ploprand)*(PRODVVP_CYCLE+1));

	prodvvd_i1 = (ploprand*)malloc(sizeof(ploprand)*(PRODVVD_CYCLE+1));
	memset(prodvvd_i1,0,sizeof(ploprand)*(PRODVVD_CYCLE+1));

	addv_i1 = (ploprand*)malloc(sizeof(ploprand)*(ADDV_CYCLE+1));
	memset(addv_i1,0,sizeof(ploprand)*(ADDV_CYCLE+1));

	addm_i1 = (ploprand*)malloc(sizeof(ploprand)*(ADDM_CYCLE+1));
	memset(addm_i1,0,sizeof(ploprand)*(ADDM_CYCLE+1));

	subv_i1  = (ploprand*)malloc(sizeof(ploprand)*(SUBV_CYCLE+1));
	memset(subv_i1,0,sizeof(ploprand)*(SUBV_CYCLE+1));

	subm_i1 = (ploprand*)malloc(sizeof(ploprand)*(SUBM_CYCLE+1));
	memset(subm_i1,0,sizeof(ploprand)*(SUBM_CYCLE+1));

	sum_i1 = (ploprand*)malloc(sizeof(ploprand)*(SUM_CYCLE+1));
	memset(sum_i1,0,sizeof(ploprand)*(SUM_CYCLE+1));

	max_i1 = (ploprand*)malloc(sizeof(ploprand)*(MAX_CYCLE+1));
	memset(max_i1,0,sizeof(ploprand)*(MAX_CYCLE+1));

	scale_i1 = (ploprand*)malloc(sizeof(ploprand)*(SCALE_CYCLE+1));
	memset(scale_i1,0,sizeof(ploprand)*(SCALE_CYCLE+1));

	diff_i1 = (ploprand*)malloc(sizeof(ploprand)*(DIFF_CYCLE+1));
	memset(diff_i1,0,sizeof(ploprand)*(DIFF_CYCLE+1));

	probcmp_i1 = (ploprand*)malloc(sizeof(ploprand)*(PROBCMP_CYCLE+1));
	memset(probcmp_i1,0,sizeof(ploprand)*(PROBCMP_CYCLE+1));

	bias_i1 = (ploprand*)malloc(sizeof(ploprand)*(BIAS_CYCLE+1));
	memset(bias_i1,0,sizeof(ploprand)*(BIAS_CYCLE+1));

	act_i1 = (ploprand*)malloc(sizeof(ploprand)*(ACT_CYCLE+1));
	memset(act_i1,0,sizeof(ploprand)*(ACT_CYCLE+1));
}

bool Initrgs()
{
	init_RV();
	init_EXTV();
	init_RDV();
	init_BV();
	init_MAT();
	init_BUFF();
	init_MEM();
	return 1;
}

/* set decode_i1 zero */
void zeroDecode_i1()
{
	memset(decode_i1,0,sizeof(decodeoprand)*fetch_num);
}

/* set buff_f_ins zero */
void zeroBuff_f_ins()
{
	memset(buff_f_ins,0,sizeof(buff_fetch_ins)*fetch_num);
}

/* initialize pipeline data structure */
bool initPlSD()
{
	decode_i0 = (decodeoprand *)malloc(sizeof(decodeoprand)*fetch_num);
	memset(decode_i0,0,sizeof(decodeoprand)*fetch_num);
	decode_i1 = (decodeoprand *)malloc(sizeof(decodeoprand)*fetch_num);
	memset(decode_i1,0,sizeof(decodeoprand)*fetch_num);
	fetch_buff = (long*)malloc(sizeof(long)*fetch_num);
	memset(fetch_buff,0,sizeof(long)*fetch_num);

	buff_f_ins = (struct buff_fetch_ins *)malloc(sizeof(buff_fetch_ins)*fetch_num);
	memset(buff_f_ins,0,sizeof(buff_fetch_ins)*fetch_num);



	return 1;
}

bool Initpl()
{
	initPlSD();
	plst.fetch_st=STG_FREE;
	plst.fetch_if0=STG_NRDY;
	plst.fetch_if1=STG_READY;
	plst.fetch_cycle=0;

	plst.decode_st=STG_FREE;
	plst.decode_if0=STG_NRDY;
	plst.decode_if1=STG_NRDY;
	plst.decode_cycle=0;

	plst.exe_st0=STG_FREE;
	plst.exe_st1=STG_FREE;
	plst.rtlMaxWord_i1=0;

	plst.loop_st=STG_FREE;
	plst.loop_if0=STG_NRDY;
	plst.loop_if1=STG_NRDY;

	plst.endloop_st=STG_FREE;
	plst.endloop_if0=STG_NRDY;
	plst.endloop_if1=STG_NRDY;

	plst.load_st=STG_FREE;
	plst.load_st_func=STG_FREE;
	plst.load_ins=0;
	plst.load_if0=STG_NRDY;
	plst.load_if1=STG_NRDY;
	plst.load_cycle=0;

	plst.launch_st=STG_FREE;
	plst.launch_st_func=STG_FREE;
	plst.launch_ins=0;
	plst.launch_if0=STG_NRDY;
	plst.launch_if1=STG_NRDY;
	plst.launch_cycle=0;

	plst.wb_st=STG_FREE;
	plst.wb_st_func=STG_FREE;
	plst.wb_ins=0;
	plst.wb_if0=STG_NRDY;
	plst.wb_if1=STG_NRDY;
	plst.wb_cycle=0;

	plst.store_st=STG_FREE;
	plst.store_st_func=STG_FREE;
	plst.store_ins=0;
	plst.store_if0=STG_NRDY;
	plst.store_if1=STG_NRDY;
	plst.store_cycle=0;

	plst.mov_st=STG_FREE;
	plst.mov_st_func=STG_FREE;
	plst.mov_ins=0;
	plst.mov_if0=STG_NRDY;
	plst.mov_if1=STG_NRDY;
	plst.mov_cycle=0;

	plst.extmov_st=STG_FREE;
	plst.extmov_st_func=STG_FREE;
	plst.extmov_ins=0;
	plst.extmov_if0=STG_NRDY;
	plst.extmov_if1=STG_NRDY;
	plst.extmov_cycle=0;

	plst.dmalr_st=STG_FREE;
	plst.dmalr_ins=0;
	plst.dmalr_if0=STG_NRDY;
	plst.dmalr_if1=STG_NRDY;
	plst.dmalr_cycle=0;

	plst.dmalc_st=STG_FREE;
	plst.dmalc_ins=0;
	plst.dmalc_if0=STG_NRDY;
	plst.dmalc_if1=STG_NRDY;
	plst.dmalc_cycle=0;

	plst.dmasr_st=STG_FREE;
	plst.dmasr_ins=0;
	plst.dmasr_if0=STG_NRDY;
	plst.dmasr_if1=STG_NRDY;
	plst.dmasr_cycle=0;

	plst.dmasc_st=STG_FREE;
	plst.dmasc_ins=0;
	plst.dmasc_if0=STG_NRDY;
	plst.dmasc_if1=STG_NRDY;
	plst.dmasc_cycle=0;

	plst.prodvm_st=STG_FREE;
	plst.prodvm_ins=0;
	plst.prodvm_if0=STG_NRDY;
	plst.prodvm_if1=STG_NRDY;
	plst.prodvm_cycle=0;
	plst.prodvm_cycle_func=0;

	plst.prodvmp_st=STG_FREE;
	plst.prodvmp_ins=0;
	plst.prodvmp_if0=STG_NRDY;
	plst.prodvmp_if1=STG_NRDY;
	plst.prodvmp_cycle=0;
	plst.prodvmp_cycle_func=0;

	plst.prodmv_st=STG_FREE;
	plst.prodmv_ins=0;
	plst.prodmv_if0=STG_NRDY;
	plst.prodmv_if1=STG_NRDY;
	plst.prodmv_cycle=0;
	plst.prodmv_cycle_func=0;

	plst.prodmvp_st=STG_FREE;
	plst.prodmvp_ins=0;
	plst.prodmvp_if0=STG_NRDY;
	plst.prodmvp_if1=STG_NRDY;
	plst.prodmvp_cycle=0;
	plst.prodmvp_cycle_func=0;

	plst.prodvv_st=STG_FREE;
	plst.prodvv_ins=0;
	plst.prodvv_if0=STG_NRDY;
	plst.prodvv_if1=STG_NRDY;
	plst.prodvv_cycle=0;
	plst.prodvv_cycle_func=0;

	plst.prodvvp_st=STG_FREE;
	plst.prodvvp_ins=0;
	plst.prodvvp_if0=STG_NRDY;
	plst.prodvvp_if1=STG_NRDY;
	plst.prodvvp_cycle=0;
	plst.prodvvp_cycle_func=0;

	plst.prodvvd_st=STG_FREE;
	plst.prodvvd_ins=0;
	plst.prodvvd_if0=STG_NRDY;
	plst.prodvvd_if1=STG_NRDY;
	plst.prodvvd_cycle=0;
	plst.prodvvd_cycle_func=0;

	plst.addv_st=STG_FREE;
	plst.addv_ins=0;
	plst.addv_if0=STG_NRDY;
	plst.addv_if1=STG_NRDY;
	plst.addv_cycle=0;
	plst.addv_cycle_func=0;

	plst.addm_st=STG_FREE;
	plst.addm_ins=0;
	plst.addm_if0=STG_NRDY;
	plst.addm_if1=STG_NRDY;
	plst.addm_cycle=0;
	plst.addm_cycle_func=0;

	plst.subv_st=STG_FREE;
	plst.subv_ins=0;
	plst.subv_if0=STG_NRDY;
	plst.subv_if1=STG_NRDY;
	plst.subv_cycle=0;
	plst.subv_cycle_func=0;

	plst.subm_st=STG_FREE;
	plst.subm_ins=0;
	plst.subm_if0=STG_NRDY;
	plst.subm_if1=STG_NRDY;
	plst.subm_cycle=0;
	plst.subm_cycle_func=0;

	plst.sum_st=STG_FREE;
	plst.sum_ins=0;
	plst.sum_if0=STG_NRDY;
	plst.sum_if1=STG_NRDY;
	plst.sum_cycle=0;
	plst.sum_cycle_func=0;

	plst.max_st=STG_FREE;
	plst.max_ins=0;
	plst.max_if0=STG_NRDY;
	plst.max_if1=STG_NRDY;
	plst.max_cycle=0;
	plst.max_cycle_func=0;

	plst.scale_st=STG_FREE;
	plst.scale_ins=0;
	plst.scale_if0=STG_NRDY;
	plst.scale_if1=STG_NRDY;
	plst.scale_cycle=0;
	plst.scale_cycle_func=0;

	plst.diff_st=STG_FREE;
	plst.diff_ins=0;
	plst.diff_if0=STG_NRDY;
	plst.diff_if1=STG_NRDY;
	plst.diff_cycle=0;
	plst.diff_cycle_func=0;

	plst.randgen_st=STG_FREE;
	plst.randgen_ins=0;
	plst.randgen_if0=STG_NRDY;
	plst.randgen_if1=STG_NRDY;
	plst.randgen_cycle=0;

	plst.probcmp_st=STG_FREE;
	plst.probcmp_ins=0;
	plst.probcmp_if0=STG_NRDY;
	plst.probcmp_if1=STG_NRDY;
	plst.probcmp_cycle=0;
	plst.probcmp_cycle_func=0;

	plst.bias_st=STG_FREE;
	plst.bias_ins=0;
	plst.bias_if0=STG_NRDY;
	plst.bias_if1=STG_NRDY;
	plst.bias_cycle=0;
	plst.bias_cycle_func=0;

	plst.act_st=STG_FREE;
	plst.act_ins=0;
	plst.act_if0=STG_NRDY;
	plst.act_if1=STG_NRDY;
	plst.act_cycle=0;
	plst.act_cycle_func=0;

	return 1;
}

bool judend()
{
	if((plst.fetch_st==STG_FREE)&&(plst.decode_st==STG_FREE)&&(plst.load_st==STG_FREE)&&(plst.launch_st==STG_FREE)\
		&&(plst.wb_st==STG_FREE)&&(plst.store_st==STG_FREE)&&(plst.mov_st==STG_FREE)&&(plst.extmov_st==STG_FREE)\
		&&(plst.dmalr_st==STG_FREE)&&(plst.dmalc_st==STG_FREE)&&(plst.dmasr_st==STG_FREE)&&(plst.dmasc_st==STG_FREE)\
		&&(plst.prodvm_st==STG_FREE)&&(plst.prodvmp_st==STG_FREE)&&(plst.prodmv_st==STG_FREE)&&(plst.prodmvp_st==STG_FREE)\
		&&(plst.prodvv_st==STG_FREE)&&(plst.prodvvp_st==STG_FREE)&&(plst.prodvvd_st==STG_FREE)\
		&&(plst.addv_st==STG_FREE)&&(plst.addm_st==STG_FREE)&&(plst.subv_st==STG_FREE)&&(plst.subm_st==STG_FREE)\
		&&(plst.max_st==STG_FREE)&&(plst.scale_st==STG_FREE)&&(plst.diff_st==STG_FREE)&&(plst.randgen_st==STG_FREE)\
		&&(plst.probcmp_st==STG_FREE)&&(plst.bias_st==STG_FREE)&&(plst.act_st==STG_FREE))
		return 1;
	else
	{
		return 0;
	}
}
