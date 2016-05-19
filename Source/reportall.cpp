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
 * report all
 *
 * define some function about information of DWsim
*/

#include<stdio.h>
#include<stdlib.h>
#include"wintolinux.h"
#include<string.h>
#include<time.h>


#include "reportall.h"
#include "print.h"
#include "ps_pipeline.h"
#include "data_reuse.h"
#include "operation_type.h"
#include "bandwith_monitor.h"
#include "reportString.h"

#ifndef _MSC_VER
#define REPORTFILE "report//DWsim.rpt"
#define REPORTFILEDR "report//datareuse.dr"
#else
#define REPORTFILE "report\\DWsim.rpt"
#define REPORTFILEDR "report\\datareuse.dr"
#endif

FILE *fp_reportall;
FILE *fp_datareuse;

bool print_data_rs_allreport(reuse_num* pRS,char* str)
{
	reuse_num *current_p=pRS;
	node_rs_clk *current_p_clk;
	int flag = 1;
	if(current_p->dnext != NULL)
	{
		fprintf(fp_reportall,"%-20s\t",str);
		fprintf(fp_datareuse,"%s\n",str);
	}
	else
	{
		return 0;
	}
	while(current_p->dnext != NULL)
	{
		fprintf(fp_datareuse,"%ld\t",current_p->dnext->count_num);
		current_p_clk=current_p->dnext->pReuseCLK;
		while(current_p_clk->pnext != NULL)
		{
			if(flag == 1)
			{
				flag = 0;
				fprintf(fp_datareuse,"%ld",current_p_clk->pnext->clk_num);
			}
			else
			{
				fprintf(fp_datareuse,"->%ld",current_p_clk->pnext->clk_num);
			}
			current_p_clk=current_p_clk->pnext;
		}
		flag = 1;
		fprintf(fp_datareuse,"\n");
		current_p=current_p->dnext;
	}
	fprintf(fp_reportall,"%-20ld\t",current_p->count_num);
	fprintf(fp_reportall,"\n");
	return 1;
}

void print_report_block_one()
{
	fprintf(fp_reportall,"%s",REPORT_BLOCK_ONE);
	fprintf(fp_reportall,"%-20s\t%-20s\t%-20s\t%-20s\t%-20s\n","insName","insNum","waitCycle","waitFuncUnitCycle","exeCycle");
	fprintf(fp_reportall,"\n");
	if(load_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"load",load_num,load_wait_time,load_fwait_time,load_execute_time);
	}
	if(store_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"store",store_num,store_wait_time,store_fwait_time,store_execute_time);
	}
	if(launch_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"launch",launch_num,launch_wait_time,launch_fwait_time,launch_execute_time);
	}
	if(wb_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"wb",wb_num,wb_wait_time,wb_fwait_time,wb_execute_time);

	}
	if(mov_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"mov",mov_num,mov_wait_time,mov_fwait_time,mov_execute_time);

	}
	if(extmov_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"extmov",extmov_num,extmov_wait_time,extmov_fwait_time,extmov_execute_time);

	}
	if(dmalr_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"mapir",dmalr_num,dmalr_wait_time,dmalr_fwait_time,dmalr_execute_time);

	}
	if(dmalc_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"mapic",dmalc_num,dmalc_wait_time,dmalc_fwait_time,dmalc_execute_time);

	}
	if(dmasr_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"mapor",dmasr_num,dmasr_wait_time,dmasr_fwait_time,dmasr_execute_time);

	}
	if(dmasc_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"mapoc",dmasc_num,dmasc_wait_time,dmasc_fwait_time,dmasc_execute_time);

	}
	if(prodvm_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"prodvm",prodvm_num,prodvm_wait_time,prodvm_fwait_time,prodvm_execute_time);

	}
	if(prodvmp_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"prodvmp",prodvmp_num,prodvmp_wait_time,prodvmp_fwait_time,prodvmp_execute_time);

	}
	if(prodmv_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"prodmv",prodmv_num,prodmv_wait_time,prodmv_fwait_time,prodmv_execute_time);

	}
	if(prodmvp_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"prodmvp",prodmvp_num,prodmvp_wait_time,prodmvp_fwait_time,prodmvp_execute_time);
	}
	if(prodvv_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"prodvv",prodvv_num,prodvv_wait_time,prodvv_fwait_time,prodvv_execute_time);

	}
	if(prodvvp_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"prodvvp",prodvvp_num,prodvvp_wait_time,prodvvp_fwait_time,prodvvp_execute_time);

	}
	if(prodvvd_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"prodvvd",prodvvd_num,prodvvd_wait_time,prodvvd_fwait_time,prodvvd_execute_time);

	}
	if(addv_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"addv",addv_num,addv_wait_time,addv_fwait_time,addv_execute_time);

	}
	if(addm_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"addm",addm_num,addm_wait_time,addm_fwait_time,addm_execute_time);

	}
	if(subv_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"subv",subv_num,subv_wait_time,subv_fwait_time,subv_execute_time);

	}
	if(subm_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"subm",subm_num,subm_wait_time,subm_fwait_time,subm_execute_time);

	}
	if(max_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"max",max_num,max_wait_time,max_fwait_time,max_execute_time);
	}
	if(diff_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"diff",diff_num,diff_wait_time,diff_fwait_time,diff_execute_time);

	}
	if(scale_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"scale",scale_num,scale_wait_time,scale_fwait_time,scale_execute_time);

	}
	if(bias_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"scale",scale_num,scale_wait_time,scale_fwait_time,scale_execute_time);

	}
	if(probcmp_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"probcmp",probcmp_num,probcmp_wait_time,probcmp_fwait_time,probcmp_execute_time);

	}
	if(randgen_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_ONE_DATA_FORMAT,"randgen",randgen_num,randgen_wait_time,randgen_fwait_time,randgen_execute_time);
	}

}

void print_report_block_two()
{
	fprintf(fp_reportall,"%s",REPORT_BLOCK_TWO);
	fprintf(fp_reportall,"%-20s\t%-20s\n","opType","num");
	fprintf(fp_reportall,"\n");
	if(addition_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_TWO_DATA_FORMAT,"add    ",addition_num);
	}
	if(multiplication_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_TWO_DATA_FORMAT,"mul",multiplication_num);
	}
	if(exp_num != 0)
	{
		fprintf(fp_reportall,REPORT_BLOCK_TWO_DATA_FORMAT,"EXP",exp_num);
	}

#define IN_DATAFO "%-20s\t%-20ld\t%-20ld\n"
	fprintf(fp_reportall,"\n%-20s\t%-20s\t%-20s\n","opModel","addOPNum","mulOPNum");
	fprintf(fp_reportall,"\n");
	if((VV_num_add != 0) || (VV_num_mul != 0))
	{
		fprintf(fp_reportall,IN_DATAFO,"VV",VV_num_add,VV_num_mul);
	}
	if((VM_num_add != 0) || (VM_num_mul != 0))
	{
		fprintf(fp_reportall,IN_DATAFO,"VM",VM_num_add,VM_num_mul);
	}
	if((MV_num_add != 0) || (MV_num_mul != 0))
	{
		fprintf(fp_reportall,IN_DATAFO,"MV",MV_num_add,MV_num_mul);
	}
	if((MM_num_add != 0) || (MM_num_mul != 0))
	{
		fprintf(fp_reportall,IN_DATAFO,"MM",MM_num_add,MM_num_mul);
	}
	if((IV_num_add != 0) || (IV_num_mul != 0))
	{
		fprintf(fp_reportall,IN_DATAFO,"IV",IV_num_add,IV_num_mul);
	}
	if((IM_num_add != 0) || (IM_num_mul != 0))
	{
		fprintf(fp_reportall,IN_DATAFO,"IM",IM_num_add,IM_num_mul);
	}
}

void print_report_block_three()
{
	fprintf(fp_reportall,"%s",REPORT_BLOCK_THREE);
	fprintf(fp_reportall,"%-20s\t%-20s\t%-20s\n","moduleName","inBW","outBW");
	fprintf(fp_reportall,"\n");
	if((Rbuffer_in_bandwith != 0) || (Rbuffer_out_bandwith != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"Rbuffer    ",Rbuffer_in_bandwith,Rbuffer_out_bandwith);

	}
	if((Cbuffer_in_bandwith != 0) || (Cbuffer_out_bandwith != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"Cbuffer    ",Cbuffer_in_bandwith,Cbuffer_out_bandwith);

	}
	if((Mbuffer_in_bandwith != 0) || (Mbuffer_out_bandwith != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"Mbuffer    ",Mbuffer_in_bandwith,Mbuffer_out_bandwith);

	}

	if((RV_in_bandwith[0] != 0) || (RV_out_bandwith[0] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV0",RV_in_bandwith[0],RV_out_bandwith[0]);

	}
	if((RV_in_bandwith[1] != 0) || (RV_out_bandwith[1] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV1",RV_in_bandwith[1],RV_out_bandwith[1]);

	}
	if((RV_in_bandwith[2] != 0) || (RV_out_bandwith[2] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV2",RV_in_bandwith[2],RV_out_bandwith[2]);

	}
	if((RV_in_bandwith[3] != 0) || (RV_out_bandwith[3] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV3",RV_in_bandwith[3],RV_out_bandwith[3]);

	}
	if((RV_in_bandwith[4] != 0) || (RV_out_bandwith[4] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV4",RV_in_bandwith[4],RV_out_bandwith[4]);

	}
	if((RV_in_bandwith[5] != 0) || (RV_out_bandwith[5] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV5",RV_in_bandwith[5],RV_out_bandwith[5]);

	}
	if((RV_in_bandwith[6] != 0) || (RV_out_bandwith[6] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV6",RV_in_bandwith[6],RV_out_bandwith[6]);

	}
	if((RV_in_bandwith[7] != 0) || (RV_out_bandwith[7] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV7",RV_in_bandwith[7],RV_out_bandwith[7]);

	}
	if((RV_in_bandwith[8] != 0) || (RV_out_bandwith[8] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV8",RV_in_bandwith[8],RV_out_bandwith[8]);

	}
	if((RV_in_bandwith[9] != 0) || (RV_out_bandwith[9] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV9",RV_in_bandwith[9],RV_out_bandwith[9]);

	}
	if((RV_in_bandwith[10] != 0) || (RV_out_bandwith[10] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV10",RV_in_bandwith[10],RV_out_bandwith[10]);

	}
	if((RV_in_bandwith[11] != 0) || (RV_out_bandwith[11] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV11",RV_in_bandwith[11],RV_out_bandwith[11]);

	}
	if((RV_in_bandwith[12] != 0) || (RV_out_bandwith[12] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV12",RV_in_bandwith[12],RV_out_bandwith[12]);

	}
	if((RV_in_bandwith[13] != 0) || (RV_out_bandwith[13] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV13",RV_in_bandwith[13],RV_out_bandwith[13]);

	}
	if((RV_in_bandwith[14] != 0) || (RV_out_bandwith[14] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV14",RV_in_bandwith[14],RV_out_bandwith[14]);

	}
	if((RV_in_bandwith[15] != 0) || (RV_out_bandwith[15] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RV15",RV_in_bandwith[15],RV_out_bandwith[15]);

	}

	if((BV_in_bandwith[0] != 0) || (BV_out_bandwith[0] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"BV0",BV_in_bandwith[0],BV_out_bandwith[0]);

	}
	if((BV_in_bandwith[1] != 0) || (BV_out_bandwith[1] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"BV1",BV_in_bandwith[1],BV_out_bandwith[1]);

	}
	if((BV_in_bandwith[2] != 0) || (BV_out_bandwith[2] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"BV2",BV_in_bandwith[2],BV_out_bandwith[2]);

	}
	if((BV_in_bandwith[3] != 0) || (BV_out_bandwith[3] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"BV3",BV_in_bandwith[3],BV_out_bandwith[3]);

	}

	if((RDV_in_bandwith[0] != 0) || (RDV_out_bandwith[0] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RDV0",RDV_in_bandwith[0],RDV_out_bandwith[0]);

	}
	if((RDV_in_bandwith[1] != 0) || (RDV_out_bandwith[1] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RDV1",RDV_in_bandwith[1],RDV_out_bandwith[1]);

	}
	if((RDV_in_bandwith[2] != 0) || (RDV_out_bandwith[2] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RDV2",RDV_in_bandwith[2],RDV_out_bandwith[2]);

	}
	if((RDV_in_bandwith[3] != 0) || (RDV_out_bandwith[3] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"RDV3",RDV_in_bandwith[3],RDV_out_bandwith[3]);

	}

	if((EXTV_in_bandwith[0] != 0) || (EXTV_out_bandwith[0] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"EXTV0",EXTV_in_bandwith[0],EXTV_out_bandwith[0]);

	}
	if((EXTV_in_bandwith[1] != 0) || (EXTV_out_bandwith[1] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"EXTV1",EXTV_in_bandwith[1],EXTV_out_bandwith[1]);

	}
	if((EXTV_in_bandwith[2] != 0) || (EXTV_out_bandwith[2] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"EXTV2",EXTV_in_bandwith[2],EXTV_out_bandwith[2]);

	}
	if((EXTV_in_bandwith[3] != 0) || (EXTV_out_bandwith[3] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"EXTV3",EXTV_in_bandwith[3],EXTV_out_bandwith[3]);

	}
	if((EXTV_in_bandwith[4] != 0) || (EXTV_out_bandwith[4] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"EXTV4",EXTV_in_bandwith[4],EXTV_out_bandwith[4]);

	}
	if((EXTV_in_bandwith[5] != 0) || (EXTV_out_bandwith[5] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"EXTV5",EXTV_in_bandwith[5],EXTV_out_bandwith[5]);

	}
	if((EXTV_in_bandwith[6] != 0) || (EXTV_out_bandwith[6] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"EXTV6",EXTV_in_bandwith[6],EXTV_out_bandwith[6]);

	}
	if((EXTV_in_bandwith[7] != 0) || (EXTV_out_bandwith[7] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"EXTV7",EXTV_in_bandwith[7],EXTV_out_bandwith[7]);

	}


	if((MAT_in_bandwith[0] != 0) || (MAT_out_bandwith[0] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"MAT0",MAT_in_bandwith[0],MAT_out_bandwith[0]);

	}
	if((MAT_in_bandwith[1] != 0) || (MAT_out_bandwith[1] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"MAT1",MAT_in_bandwith[1],MAT_out_bandwith[1]);

	}
	if((MAT_in_bandwith[2] != 0) || (MAT_out_bandwith[2] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"MAT2",MAT_in_bandwith[2],MAT_out_bandwith[2]);

	}
	if((MAT_in_bandwith[3] != 0) || (MAT_out_bandwith[3] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"MAT3",MAT_in_bandwith[3],MAT_out_bandwith[3]);

	}
	if((MAT_in_bandwith[4] != 0) || (MAT_out_bandwith[4] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"MAT4",MAT_in_bandwith[4],MAT_out_bandwith[4]);

	}
	if((MAT_in_bandwith[5] != 0) || (MAT_out_bandwith[5] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"MAT5",MAT_in_bandwith[5],MAT_out_bandwith[5]);

	}
	if((MAT_in_bandwith[6] != 0) || (MAT_out_bandwith[6] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"MAT6",MAT_in_bandwith[6],MAT_out_bandwith[6]);

	}
	if((MAT_in_bandwith[7] != 0) || (MAT_out_bandwith[7] != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"MAT7",MAT_in_bandwith[7],MAT_out_bandwith[7]);

	}

	if((buffer0_in_bandwith != 0) || (buffer0_out_bandwith != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"buffer0   ",buffer0_in_bandwith,buffer0_out_bandwith);

	}
	if((buffer1_in_bandwith != 0) || (buffer1_out_bandwith != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"buffer1   ",buffer1_in_bandwith,buffer1_out_bandwith);

	}
	if((buffer2_in_bandwith != 0) || (buffer2_out_bandwith != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"buffer2   ",buffer2_in_bandwith,buffer2_out_bandwith);

	}
	if((mem_in_bandwith != 0) || (mem_out_bandwith != 0))
	{
		fprintf(fp_reportall,RPORT_BLOCK_THREE_DATA_FORMAT,"memory   ",mem_in_bandwith,mem_out_bandwith);

	}
}

void print_report_block_four()
{
	if(access("report",0))
	{
		if( system("mkdir report") !=0 )
		{
			printf(" can not creat report folder.\n");
			exit(0);
		}
	}
	errno_t err;
	if((err=fopen_s(&fp_datareuse,REPORTFILEDR,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",REPORTFILE,strerror(err));
		exit(0);
	}

	fprintf(fp_reportall,"%s",REPORT_BLOCK_FOUR);   
	fprintf(fp_reportall,"%-20s\t%-20s\n","moduleName","allUpdateTimes");
	fprintf(fp_reportall,"\n");

	fprintf(fp_datareuse,"print format:%s\t%s\treuseDistance\n","moduleName","allUpdateTimes");

	print_data_rs_allreport(&RV_dreuse[0],"RV0");
	print_data_rs_allreport(&RV_dreuse[1],"RV1");
	print_data_rs_allreport(&RV_dreuse[2],"RV2");
	print_data_rs_allreport(&RV_dreuse[3],"RV3");
	print_data_rs_allreport(&RV_dreuse[4],"RV4");
	print_data_rs_allreport(&RV_dreuse[5],"RV5");
	print_data_rs_allreport(&RV_dreuse[6],"RV6");
	print_data_rs_allreport(&RV_dreuse[7],"RV7");
	print_data_rs_allreport(&RV_dreuse[8],"RV8");
	print_data_rs_allreport(&RV_dreuse[9],"RV9");
	print_data_rs_allreport(&RV_dreuse[10],"RV10");
	print_data_rs_allreport(&RV_dreuse[11],"RV11");
	print_data_rs_allreport(&RV_dreuse[12],"RV12");
	print_data_rs_allreport(&RV_dreuse[13],"RV13");
	print_data_rs_allreport(&RV_dreuse[14],"RV14");
	print_data_rs_allreport(&RV_dreuse[15],"RV15");

	print_data_rs_allreport(&MAT_dreuse[0],"MAT0");
	print_data_rs_allreport(&MAT_dreuse[1],"MAT1");
	print_data_rs_allreport(&MAT_dreuse[2],"MAT2");
	print_data_rs_allreport(&MAT_dreuse[3],"MAT3");
	print_data_rs_allreport(&MAT_dreuse[4],"MAT4");
	print_data_rs_allreport(&MAT_dreuse[5],"MAT5");
	print_data_rs_allreport(&MAT_dreuse[6],"MAT6");
	print_data_rs_allreport(&MAT_dreuse[7],"MAT7");

	print_data_rs_allreport(&Rbuffer_dreuse,"Rbuffer");
	print_data_rs_allreport(&Cbuffer_dreuse,"Cbuffer");
	print_data_rs_allreport(&Mbuffer_dreuse,"Mbuffer");

}

void print_repor(int clk,double cost_time,long ins_n,long d_ins_n)
{
	if(access("report",0))
	{
		if( system("mkdir report") !=0 )
		{
			printf(" can not creat report folder.\n");
			exit(0);
		}
	}
	errno_t err;
	if((err=fopen_s(&fp_reportall,REPORTFILE,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",REPORTFILE,strerror(err));
		exit(0);
	}

	fprintf(fp_reportall,"%s",REPORT_HEAD_FORMAT_ONE);
	time_t c_time;
	struct tm* tm_time = (struct tm*)malloc(sizeof(struct tm));
	time(&c_time);
	errno_t err_int = gmtime_s(tm_time,&c_time);
	if(err_int != 0)
	{
		printf(" can not get current time:%s\n",strerror(err_int));
	}
	else
	{
		fprintf(fp_reportall,"%04d/%02d/%02d\n",tm_time->tm_year+1900,tm_time->tm_mon+1,tm_time->tm_mday);

	}
	fprintf(fp_reportall,"%s",REPORT_HEAD_FORMAT_TWO);


	fprintf(fp_reportall,"%s%ld\n%s%ld\n%s%ld\n%s%.2f\n%s%.2f\n",REPORT_HEAD,ins_n,"Total dynamic instruction:",d_ins_n,REPORT_HEAD_SECODE,clk-1,
		"static IPC:",(float)ins_n/(clk-1),"dynamic IPC:",(float)d_ins_n/(clk-1));
	fprintf(fp_reportall,"\n%s%.3f\n",REPORT_HEAD_SECODE_BY,cost_time);
	fprintf(fp_reportall,"%s%.2f\n","Simulation performance (KIPS):",(float)ins_n/cost_time);

	if(allF || !qGetD)
	{
		//\CA\E4\B3\F6bandwith
	    long  temp_bandwith=0;
	    int i=0;
	    for(i=0;i<RG_NUM;i++)
	    {
	    	temp_bandwith+=RV_in_bandwith[i];
	    }
	    for(i=0;i<RG_NUM;i++)
	    {
	    	temp_bandwith+=RV_out_bandwith[i];
	    }
	    for(i=0;i<BV_NUM;i++)
	    {
	    	temp_bandwith+=BV_in_bandwith[i];
	    }
	    for(i=0;i<BV_NUM;i++)
	    {
	    	temp_bandwith+=BV_out_bandwith[i];
	    }
	    for(i=0;i<RDV_NUM;i++)
	    {
	    	temp_bandwith+=RDV_in_bandwith[i];
	    }
	    for(i=0;i<RDV_NUM;i++)
	    {
	    	temp_bandwith+=RDV_out_bandwith[i];
	    }
	    for(i=0;i<EXTV_NUM;i++)
	    {
	    	temp_bandwith+=EXTV_in_bandwith[i];
	    }
	    for(i=0;i<EXTV_NUM;i++)
	    {
	    	temp_bandwith+=EXTV_out_bandwith[i];
	    }
	    fprintf(fp_reportall,"\n%s%ld\n","..regfile to localstore:",temp_bandwith);
	    temp_bandwith = 0;
	    for(i=0;i<M_LAYER;i++)
	    {
	    	temp_bandwith+=MAT_out_bandwith[i];
	    	temp_bandwith+=MAT_in_bandwith[i];
	    }
	    fprintf(fp_reportall,"%s%ld\n","..matfile to localstore:",temp_bandwith);
	    
	    fprintf(fp_reportall,"..localstore to memory:%ld\n\n\n\n\n",mem_in_bandwith+mem_out_bandwith);
	    
	    print_report_block_one();
	    print_report_block_two();
	    print_report_block_three();
	    print_report_block_four();
	}

	fclose(fp_reportall);
}
