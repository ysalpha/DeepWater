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
 * data reuse
 *
 * Statistics hardware memory module reuse
 */

#include<stdio.h>
#include<stdlib.h>
#include"wintolinux.h"
#include<string.h>

#include "data_reuse.h"

//macro define the file name saving the data of message data reuse//
#ifndef _MSC_VER
#define DREUSE_RV0 "datareuse/dr_rv0.txt"
#define DREUSE_RV1 "datareuse/dr_rv1.txt"
#define DREUSE_RV2 "datareuse/dr_rv2.txt"
#define DREUSE_RV3 "datareuse/dr_rv3.txt"
#define DREUSE_RV4 "datareuse/dr_rv4.txt"
#define DREUSE_RV5 "datareuse/dr_rv5.txt"
#define DREUSE_RV6 "datareuse/dr_rv6.txt"
#define DREUSE_RV7 "datareuse/dr_rv7.txt"
#define DREUSE_RV8 "datareuse/dr_rv8.txt"
#define DREUSE_RV9 "datareuse/dr_rv9.txt"
#define DREUSE_RV10 "datareuse/dr_rv10.txt"
#define DREUSE_RV11 "datareuse/dr_rv11.txt"
#define DREUSE_RV12 "datareuse/dr_rv12.txt"
#define DREUSE_RV13 "datareuse/dr_rv13.txt"
#define DREUSE_RV14 "datareuse/dr_rv14.txt"
#define DREUSE_RV15 "datareuse/dr_rv15.txt"

#define DREUSE_MAT0 "datareuse/dr_MAT0.txt"
#define DREUSE_MAT1 "datareuse/dr_MAT1.txt"
#define DREUSE_MAT2 "datareuse/dr_MAT2.txt"
#define DREUSE_MAT3 "datareuse/dr_MAT3.txt"
#define DREUSE_MAT4 "datareuse/dr_MAT4.txt"
#define DREUSE_MAT5 "datareuse/dr_MAT5.txt"
#define DREUSE_MAT6 "datareuse/dr_MAT6.txt"
#define DREUSE_MAT7 "datareuse/dr_MAT7.txt"

#define DREUSE_RBUFFER "datareuse/dr_rbuffer.txt"
#define DREUSE_CBUFFER "datareuse/dr_cbuffer.txt"
#define DREUSE_MBUFFER "datareuse/dr_mbuffer.txt"
#else
#define DREUSE_RV0 "datareuse\\dr_rv0.txt"
#define DREUSE_RV1 "datareuse\\dr_rv1.txt"
#define DREUSE_RV2 "datareuse\\dr_rv2.txt"
#define DREUSE_RV3 "datareuse\\dr_rv3.txt"
#define DREUSE_RV4 "datareuse\\dr_rv4.txt"
#define DREUSE_RV5 "datareuse\\dr_rv5.txt"
#define DREUSE_RV6 "datareuse\\dr_rv6.txt"
#define DREUSE_RV7 "datareuse\\dr_rv7.txt"
#define DREUSE_RV8 "datareuse\\dr_rv8.txt"
#define DREUSE_RV9 "datareuse\\dr_rv9.txt"
#define DREUSE_RV10 "datareuse\\dr_rv10.txt"
#define DREUSE_RV11 "datareuse\\dr_rv11.txt"
#define DREUSE_RV12 "datareuse\\dr_rv12.txt"
#define DREUSE_RV13 "datareuse\\dr_rv13.txt"
#define DREUSE_RV14 "datareuse\\dr_rv14.txt"
#define DREUSE_RV15 "datareuse\\dr_rv15.txt"

#define DREUSE_MAT0 "datareuse\\dr_MAT0.txt"
#define DREUSE_MAT1 "datareuse\\dr_MAT1.txt"
#define DREUSE_MAT2 "datareuse\\dr_MAT2.txt"
#define DREUSE_MAT3 "datareuse\\dr_MAT3.txt"
#define DREUSE_MAT4 "datareuse\\dr_MAT4.txt"
#define DREUSE_MAT5 "datareuse\\dr_MAT5.txt"
#define DREUSE_MAT6 "datareuse\\dr_MAT6.txt"
#define DREUSE_MAT7 "datareuse\\dr_MAT7.txt"

#define DREUSE_RBUFFER "datareuse\\dr_rbuffer.txt"
#define DREUSE_CBUFFER "datareuse\\dr_cbuffer.txt"
#define DREUSE_MBUFFER "datareuse\\dr_mbuffer.txt"
#endif

data_reuse st_dr;

//define relative file point// 
FILE* fp_dr;
FILE* fp_dr_rv0;
FILE* fp_dr_rv1;
FILE* fp_dr_rv2;
FILE* fp_dr_rv3;
FILE* fp_dr_rv4;
FILE* fp_dr_rv5;
FILE* fp_dr_rv6;
FILE* fp_dr_rv7;
FILE* fp_dr_rv8;
FILE* fp_dr_rv9;
FILE* fp_dr_rv10;
FILE* fp_dr_rv11;
FILE* fp_dr_rv12;
FILE* fp_dr_rv13;
FILE* fp_dr_rv14;
FILE* fp_dr_rv15;

FILE* fp_dr_mat0;
FILE* fp_dr_mat1;
FILE* fp_dr_mat2;
FILE* fp_dr_mat3;
FILE* fp_dr_mat4;
FILE* fp_dr_mat5;
FILE* fp_dr_mat6;
FILE* fp_dr_mat7;

FILE* fp_dr_rbuffer;
FILE* fp_dr_cbuffer;
FILE* fp_dr_mbuffer;

//define the global variant to save the data//
reuse_num RV_dreuse[16];

reuse_num MAT_dreuse[8];

reuse_num Rbuffer_dreuse;
reuse_num Cbuffer_dreuse;
reuse_num Mbuffer_dreuse;

/*initialize the signal of judging the data reuse*/
void Init_signal_datareuse()
{
	st_dr.mbuffer_clk=0;
	st_dr.mbuffer_hdata=0;
	st_dr.mbuffer_isupdate=0;
	st_dr.cbuffer_clk=0;
	st_dr.cbuffer_hdata=0;
	st_dr.cbuffer_isupdate=0;
	st_dr.rbuffer_clk=0;
	st_dr.rbuffer_hdata=0;
	st_dr.rbuffer_isupdate=0;

	memset(st_dr.mat_clk,0,sizeof(st_dr.mat_clk));
	memset(st_dr.mat_hdata,0,sizeof(st_dr.mat_hdata));
	memset(st_dr.mat_isupdate,0,sizeof(st_dr.mat_isupdate));

	memset(st_dr.rv_clk,0,sizeof(st_dr.rv_clk));
	memset(st_dr.rv_hdata,0,sizeof(st_dr.rv_hdata));
	memset(st_dr.rv_isupdate,0,sizeof(st_dr.rv_isupdate));
}

/* initialize the all variant*/
void Init_Data_Reuse()
{
	Init_signal_datareuse();
	if(access("datareuse",0))
	{
		if( system("mkdir datareuse") !=0 )//create the floder of datareuse. datareuse defined in data_reuse.h//
		{
			printf(" cann't not creat datareuse folder.\n");
			exit(0);
		}
	}
	errno_t err;
	if((err=fopen_s(&fp_dr,REUSE_FILE,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",REUSE_FILE,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv0,DREUSE_RV0,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv1,DREUSE_RV1,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv2,DREUSE_RV2,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv3,DREUSE_RV3,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv4,DREUSE_RV4,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV4,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv5,DREUSE_RV5,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV5,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv6,DREUSE_RV6,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV6,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv7,DREUSE_RV7,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV7,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv8,DREUSE_RV8,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV8,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv9,DREUSE_RV9,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV9,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv10,DREUSE_RV10,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV10,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv11,DREUSE_RV11,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV11,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv12,DREUSE_RV12,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV12,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv13,DREUSE_RV13,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV13,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv14,DREUSE_RV14,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV14,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_rv15,DREUSE_RV15,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RV15,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_dr_mat0,DREUSE_MAT0,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_MAT0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_mat1,DREUSE_MAT1,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_MAT1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_mat2,DREUSE_MAT2,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_MAT2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_mat3,DREUSE_MAT3,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_MAT3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_mat4,DREUSE_MAT4,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_MAT4,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_mat5,DREUSE_MAT5,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_MAT5,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_mat6,DREUSE_MAT6,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_MAT6,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_mat7,DREUSE_MAT7,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_MAT7,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_dr_rbuffer,DREUSE_RBUFFER,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_RBUFFER,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_cbuffer,DREUSE_CBUFFER,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_CBUFFER,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_dr_mbuffer,DREUSE_MBUFFER,"w+"))!=0)
	{
		printf("can not open %s file in data_reuse.cpp.erron:%s\n",DREUSE_MBUFFER,strerror(err));
		exit(0);
	}
}

void add_node_rs_clk(reuse_num* pRS,long clk_num)
{
	reuse_num *current_p;
	node_rs_clk *count_p,*new_p;
	current_p=pRS;
	while(current_p->dnext != NULL)
	{
		current_p=current_p->dnext;
	}
	count_p=current_p->pReuseCLK;
	while(count_p->pnext != NULL)
	{
		count_p=count_p->pnext;
	}
	new_p = (node_rs_clk *)malloc(sizeof(node_rs_clk));
	new_p->clk_num=clk_num;
	new_p->pnext=NULL;
	count_p->pnext=new_p;
}

/*!
create a node to record of the memory structure data reuse message,besides,add a data head node to save 
input:reuse_num* pRS,the head point of memory structure
*/
void creat_node_rs_num(reuse_num* pRS)
{
	reuse_num *current_p,*new_p;
	current_p = pRS;
	while(current_p->dnext != NULL)
	{
		current_p=current_p->dnext;
	}
	new_p=(reuse_num*)malloc(sizeof(reuse_num));
	new_p->count_num=current_p->count_num+1;
	new_p->dnext=NULL;
	new_p->pReuseCLK=(node_rs_clk*)malloc(sizeof(node_rs_clk));
	new_p->pReuseCLK->clk_num=0;
	new_p->pReuseCLK->pnext=NULL;
	current_p->dnext=new_p;
}

void free_Data_Reuse(reuse_num* pRS)
{
	reuse_num *current_p=pRS,*free_p;
	node_rs_clk *current_p_n,*free_p_n;
	while(current_p->dnext != NULL)
	{
		current_p_n=current_p->dnext->pReuseCLK;
		while(current_p_n->pnext != NULL)
		{
			free_p_n=current_p_n->pnext;
			current_p_n->pnext=current_p_n->pnext->pnext;
			free(free_p_n);
		}
		free(current_p_n);
		free_p=current_p->dnext;
		current_p->dnext=current_p->dnext->dnext;
		free(free_p);
	}
	fclose(fp_dr);
}

void print_data_rs(reuse_num* pRS,char* str)
{
	fprintf(fp_dr,"*************Data Reuse of %s*************\n",str);
	fprintf(fp_dr,"Update times            Cycle Gap Of Data Reuse\n");
	reuse_num *current_p=pRS;
	node_rs_clk *current_p_clk;
	while(current_p->dnext != NULL)
	{
		fprintf(fp_dr,"%ld\t",current_p->dnext->count_num);
		current_p_clk=current_p->dnext->pReuseCLK;
		while(current_p_clk->pnext != NULL)
		{
			fprintf(fp_dr,"%ld\t",current_p_clk->pnext->clk_num);
			current_p_clk=current_p_clk->pnext;
		}
		fprintf(fp_dr,"\n");
		current_p=current_p->dnext;
	}
	fprintf(fp_dr,"******************************************\n");
}

void print_data_rs_only_clk(reuse_num* pRS,FILE* fp)
{
	reuse_num *current_p=pRS;
	node_rs_clk *current_p_clk;
	while(current_p->dnext != NULL)
	{
		current_p_clk=current_p->dnext->pReuseCLK;
		while(current_p_clk->pnext != NULL)
		{
			fprintf(fp,"%ld\t",current_p_clk->pnext->clk_num);
			current_p_clk=current_p_clk->pnext;
		}
		fprintf(fp,"\n");
		current_p=current_p->dnext;
	}
	fclose(fp);
}

void print_all_data_rs_only_clk()
{
	print_data_rs_only_clk(&RV_dreuse[0],fp_dr_rv0);
	print_data_rs_only_clk(&RV_dreuse[1],fp_dr_rv1);
	print_data_rs_only_clk(&RV_dreuse[2],fp_dr_rv2);
	print_data_rs_only_clk(&RV_dreuse[3],fp_dr_rv3);
	print_data_rs_only_clk(&RV_dreuse[4],fp_dr_rv4);
	print_data_rs_only_clk(&RV_dreuse[5],fp_dr_rv5);
	print_data_rs_only_clk(&RV_dreuse[6],fp_dr_rv6);
	print_data_rs_only_clk(&RV_dreuse[7],fp_dr_rv7);
	print_data_rs_only_clk(&RV_dreuse[8],fp_dr_rv8);
	print_data_rs_only_clk(&RV_dreuse[9],fp_dr_rv9);
	print_data_rs_only_clk(&RV_dreuse[10],fp_dr_rv10);
	print_data_rs_only_clk(&RV_dreuse[11],fp_dr_rv11);
	print_data_rs_only_clk(&RV_dreuse[12],fp_dr_rv12);
	print_data_rs_only_clk(&RV_dreuse[13],fp_dr_rv13);
	print_data_rs_only_clk(&RV_dreuse[14],fp_dr_rv14);
	print_data_rs_only_clk(&RV_dreuse[15],fp_dr_rv15);
						   
	print_data_rs_only_clk(&MAT_dreuse[0],fp_dr_mat0);
	print_data_rs_only_clk(&MAT_dreuse[1],fp_dr_mat1);
	print_data_rs_only_clk(&MAT_dreuse[2],fp_dr_mat2);
	print_data_rs_only_clk(&MAT_dreuse[3],fp_dr_mat3);
	print_data_rs_only_clk(&MAT_dreuse[4],fp_dr_mat4);
	print_data_rs_only_clk(&MAT_dreuse[5],fp_dr_mat5);
	print_data_rs_only_clk(&MAT_dreuse[6],fp_dr_mat6);
	print_data_rs_only_clk(&MAT_dreuse[7],fp_dr_mat7);
						   
	print_data_rs_only_clk(&Rbuffer_dreuse,fp_dr_rbuffer);
	print_data_rs_only_clk(&Cbuffer_dreuse,fp_dr_cbuffer);
	print_data_rs_only_clk(&Mbuffer_dreuse,fp_dr_mbuffer);
}

void print_all_data_rs()
{
	print_data_rs(&RV_dreuse[0],"RV0");
	print_data_rs(&RV_dreuse[1],"RV1");
	print_data_rs(&RV_dreuse[2],"RV2");
	print_data_rs(&RV_dreuse[3],"RV3");
	print_data_rs(&RV_dreuse[4],"RV4");
	print_data_rs(&RV_dreuse[5],"RV5");
	print_data_rs(&RV_dreuse[6],"RV6");
	print_data_rs(&RV_dreuse[7],"RV7");
	print_data_rs(&RV_dreuse[8],"RV8");
	print_data_rs(&RV_dreuse[9],"RV9");
	print_data_rs(&RV_dreuse[10],"RV10");
	print_data_rs(&RV_dreuse[11],"RV11");
	print_data_rs(&RV_dreuse[12],"RV12");
	print_data_rs(&RV_dreuse[13],"RV13");
	print_data_rs(&RV_dreuse[14],"RV14");
	print_data_rs(&RV_dreuse[15],"RV15");

	print_data_rs(&MAT_dreuse[0],"MAT0");
	print_data_rs(&MAT_dreuse[1],"MAT1");
	print_data_rs(&MAT_dreuse[2],"MAT2");
	print_data_rs(&MAT_dreuse[3],"MAT3");
	print_data_rs(&MAT_dreuse[4],"MAT4");
	print_data_rs(&MAT_dreuse[5],"MAT5");
	print_data_rs(&MAT_dreuse[6],"MAT6");
	print_data_rs(&MAT_dreuse[7],"MAT7");

	print_data_rs(&Rbuffer_dreuse,"Rbuffer");
	print_data_rs(&Cbuffer_dreuse,"Cbuffer");
	print_data_rs(&Mbuffer_dreuse,"Mbuffer");

	print_all_data_rs_only_clk();
}

void free_all_data_reuse()
{
	free_Data_Reuse(&RV_dreuse[0]);
	free_Data_Reuse(&RV_dreuse[1]);
	free_Data_Reuse(&RV_dreuse[2]);
	free_Data_Reuse(&RV_dreuse[3]);
	free_Data_Reuse(&RV_dreuse[4]);
	free_Data_Reuse(&RV_dreuse[5]);
	free_Data_Reuse(&RV_dreuse[6]);
	free_Data_Reuse(&RV_dreuse[7]);
	free_Data_Reuse(&RV_dreuse[8]);
	free_Data_Reuse(&RV_dreuse[9]);
	free_Data_Reuse(&RV_dreuse[10]);
	free_Data_Reuse(&RV_dreuse[11]);
	free_Data_Reuse(&RV_dreuse[12]);
	free_Data_Reuse(&RV_dreuse[13]);
	free_Data_Reuse(&RV_dreuse[14]);
	free_Data_Reuse(&RV_dreuse[15]);
	
	free_Data_Reuse(&MAT_dreuse[0]);
	free_Data_Reuse(&MAT_dreuse[1]);
	free_Data_Reuse(&MAT_dreuse[2]);
	free_Data_Reuse(&MAT_dreuse[3]);
	free_Data_Reuse(&MAT_dreuse[4]);
	free_Data_Reuse(&MAT_dreuse[5]);
	free_Data_Reuse(&MAT_dreuse[6]);
	free_Data_Reuse(&MAT_dreuse[7]);
	
	free_Data_Reuse(&Rbuffer_dreuse);
	free_Data_Reuse(&Cbuffer_dreuse);
	free_Data_Reuse(&Mbuffer_dreuse);
}
