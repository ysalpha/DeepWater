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
 * print
 *
 * Some common print function definition
 */

#include<stdio.h>
#include<stdlib.h>

#include "print.h"
#include "ps_pipeline.h"
#include "options.h"
#include "localBufferModeling.h"
#include "fileVariant.h"

FILE* freport;

void init_dbP_file()
{
	freport=fopen(rpname,"w+");
}

bool myprintregB(RB rg)
{
	int i;
	for(i=0;i<16;i++)
		printf("%6d ",rg.V[i]);
	printf("\n");
	return 1;
}

bool myprintreg(RG rg)
{
	int i;
	for(i=0;i<16;i++)
		printf("%6d ",rg.V[i]);
	printf("\n");
	return 1;
}

bool myprint_BV()
{
	printf("\n**********************************************************************************************************************\n");
	printf("BV:\n");
	int i=0;
	for(;i<BV_NUM;i++)
	{
		printf("BV%d: ",i+1);
		myprintregB(BV->R_V[i]);
	}
	//printf("BV1: ");
	//myprintregB(BV->R_V[0]);
	//printf("BV2: ");
	//myprintregB(BV->R_V[1]);
	//printf("BV3: ");
	//myprintregB(BV->R_V[2]);
	//printf("BV4: ");
	//myprintregB(BV->R_V[3]);
	//printf("BV5: ");
	//myprintregB(BV->R_V[4]);
	printf("**********************************************************************************************************************\n\n");
	return 1;
}

bool myprint_RV()
{
	printf("\n**********************************************************************************************************************\n");
	int i=0;
	printf("RV:\n");
	for(;i<RG_NUM;i++)
	{
		printf("RV%d: ",i+1);
		myprintreg(RV->R_V[i]);
	}
	//printf("RV:\n");
	//printf("RV1: ");
	//myprintreg(RV->R_V[0]);
	//printf("RV2: ");
	//myprintreg(RV->R_V[1]);
	//printf("RV3: ");
	//myprintreg(RV->R_V[2]);
	//printf("RV4: ");
	//myprintreg(RV->R_V[3]);
	//printf("RV5: ");
	//myprintreg(RV->R_V[4]);
	printf("**********************************************************************************************************************\n\n");
	return 1;
}

bool myprint_RDV()
{
	printf("\n**********************************************************************************************************************\n");
	printf("RDV:\n");
	int i=0;
	for(;i<RDV_NUM;i++)
	{
		printf("RDV%d: ",i+1);
		myprintreg(RDV->R_V[i]);
	}
	//printf("RDV1: ");
	//myprintreg(RDV->R_V[0]);
	//printf("RDV2: ");
	//myprintreg(RDV->R_V[1]);
	//printf("RDV3: ");
	//myprintreg(RDV->R_V[2]);
	//printf("RDV4: ");
	//myprintreg(RDV->R_V[3]);
	//printf("RDV5: ");
	//myprintreg(RDV->R_V[4]);
	printf("**********************************************************************************************************************\n\n");
	return 1;
}

bool myprint_EXTV()
{
	printf("\n**********************************************************************************************************************\n");
	printf("EXTV:\n");
	int i=0;
	for(;i<EXTV_NUM;i++)
	{
		printf("EXTV%d: ",i+1);
		myprintreg(EXTV->R_V[i]);
	}
	printf("**********************************************************************************************************************\n\n");
	return 1;
}

bool myprint_MAT()
{
	int i,j;
	printf("\n**********************************************************************************************************************\n");
	printf("MAT:\n");
	for(i=0;i<M_LAYER;i++)
	{
		for(j=0;j<V_NUM;j++)
		{
			printf("num of layer %d\n",i);
			printf("ad%3d:%6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d\n",16*j,MAT[i]->M_V[j].V[0],MAT[i]->M_V[j].V[1],MAT[i]->M_V[j].V[2],MAT[i]->M_V[j].V[3],MAT[i]->M_V[j].V[4],MAT[i]->M_V[j].V[5],MAT[i]->M_V[j].V[6],MAT[i]->M_V[j].V[7],MAT[i]->M_V[j].V[8],MAT[i]->M_V[j].V[9],MAT[i]->M_V[j].V[10],MAT[i]->M_V[j].V[11],MAT[i]->M_V[j].V[12],MAT[i]->M_V[j].V[13],MAT[i]->M_V[j].V[14],MAT[i]->M_V[j].V[15]);
	
		}
	}
	printf("**********************************************************************************************************************\n\n");
	return 1;
}

bool myprint_BUFFER()
{
	int i,j;
	printf("\n**********************************************************************************************************************\n");
	printf("buff0:\n");
	for(i=0;i<MEM_BUFF_ENTRY_SIZE;i++)
	{
		printf("%3d:",i);
		for(j=0;j<MEM_BUFF_BANK_SIZE;j++)
		{
			printf("%6d \t",buff0->MM_B[i].MEM_B[j].MEM_D);
		}
		printf("\n");
	}
	printf("\n");

	printf("buff1:\n");
	for(i=0;i<MEM_BUFF_ENTRY_SIZE;i++)
	{
		printf("%3d:",i);
		for(j=0;j<MEM_BUFF_BANK_SIZE;j++)
		{
			printf("%6d \t",buff1->MM_B[i].MEM_B[j].MEM_D);
		}
		printf("\n");
	}
	printf("\n");

	printf("buff2:\n");
	for(i=0;i<MEM_BUFF_ENTRY_SIZE;i++)
	{
		printf("%3d:",i);
		for(j=0;j<MEM_BUFF_BANK_SIZE;j++)
		{
			printf("%6d \t",buff2->MM_B[i].MEM_B[j].MEM_D);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n**********************************************************************************************************************\n");

	printf("\n**********************************************************************************************************************\n");
	printf("Rbuffer:\n");
	for(i=0;i<RG_SIZE;i++)
	{
		printf("%6d \t",Rbuffer.V[i]);
	}
    printf("\n");
	printf("Cbuffer:\n");
	for(i=0;i<RG_SIZE;i++)
	{
		printf("%6d \t",Cbuffer.V[i]);
	}
	printf("\n");
	printf("Mbuffer:\n");
	for(i=0;i<V_NUM;i++)
	{
		printf("%3d:",i);
		for(j=0;j<V_SIZE;j++)
		{
			printf("%6d \t ",Mbuffer.V[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n**********************************************************************************************************************\n");

	return 1;
}

void myprint_fatal(char *s)
{
	printf("\n**********************************************************************************************************************\n");
	printf("\n\n                    %s\n\n",s);
	printf("**********************************************************************************************************************\n\n");
	exit(0);
}

bool myprint_report(char *s0, long n0, char *s1, long n1, char *s2, long n2)
{
	if(report_fl==0)
		return 0;
	fprintf(freport,"%s",s0);
	if(n0!=NULL)
		fprintf(freport,"%d",n0);
	fprintf(freport,"%s",s1);
	if(n1!=NULL)
		fprintf(freport,"%d",n1);
	fprintf(freport,"%s",s2);
	if(n2!=NULL)
		fprintf(freport,"%d",n2);
	return 1;
}

bool myprint_report0(char *s0, long n0, char *s1, long n1, char *s2, long n2)
{
	/*fprintf(freport,"%s",s0);
	if(n0!=NULL)
		fprintf(freport,"%d",n0);
	fprintf(freport,"%27s",s1);
	fprintf(freport,"%6d",n1);
	fprintf(freport,"%s",s2);
	if(n2!=NULL)
		fprintf(freport,"%d",n2);*/
	fprintf(freport,"%s",s0);
	if(n0!=NULL)
		fprintf(freport,"%d",n0);
	fprintf(freport,"%s",s1);
	if(n1!=NULL)
		fprintf(freport,"%d",n1);
	fprintf(freport,"%s",s2);
	if(n2!=NULL)
		fprintf(freport,"%d",n2);
	return 1;
}

void myprintreg_rb(RB rg)
{
	int i;
	for(i=0;i<16;i++)
	{
		fprintf(freport,"%6d",rg.V[i]);
		fprintf(freport,"%s"," ");
	}
	fprintf(freport,"%s","\n");
}

void myprintreg_rp(RG rg)
{
	int i;
	for(i=0;i<16;i++)
	{
		fprintf(freport,"%6d",rg.V[i]);
		fprintf(freport,"%s"," ");
	}
	fprintf(freport,"%s","\n");
}

bool myprint_BV_rp()
{
	if(report_fl==0)
		return 0;
	fprintf(freport,"%s","\n     BV:\n");
	fprintf(freport,"%s","     BV1 : ");
	myprintreg_rb(BV->R_V[0]);
	fprintf(freport,"%s","     BV2 : ");
	myprintreg_rb(BV->R_V[1]);
	fprintf(freport,"%s","     BV3 : ");
	myprintreg_rb(BV->R_V[2]);
	fprintf(freport,"%s","     BV4 : ");
	myprintreg_rb(BV->R_V[3]);
	//fprintf(freport,"%s","     BV5 : ");
	//myprintreg_rb(BV->R_V[4]);
	return 1;
}

bool myprint_RV_rp()
{
	if(report_fl==0)
		return 0;
	fprintf(freport,"%s","\n     RV:\n");
	int i=0;
	for(;i<RG_NUM;i++)
	{
		fprintf(freport,"%s%d%s","     RV",i+1," : ");
		myprintreg_rp(RV->R_V[i]);
	}
	//fprintf(freport,"%s","     RV1 : ");
	//myprintreg_rp(RV->R_V[0]);
	//fprintf(freport,"%s","     RV2 : ");
	//myprintreg_rp(RV->R_V[1]);
	//fprintf(freport,"%s","     RV3 : ");
	//myprintreg_rp(RV->R_V[2]);
	//fprintf(freport,"%s","     RV4 : ");
	//myprintreg_rp(RV->R_V[3]);
	//fprintf(freport,"%s","     RV5 : ");
	//myprintreg_rp(RV->R_V[4]);
	return 1;
}

bool myprint_RDV_rp()
{
	if(report_fl==0)
		return 0;
	fprintf(freport,"%s","\n     RDV:\n");
	fprintf(freport,"%s","     RDV1 : ");
	myprintreg_rp(RDV->R_V[0]);
	fprintf(freport,"%s","     RDV2 : ");
	myprintreg_rp(RDV->R_V[1]);
	fprintf(freport,"%s","     RDV3 : ");
	myprintreg_rp(RDV->R_V[2]);
	fprintf(freport,"%s","     RDV4 : ");
	myprintreg_rp(RDV->R_V[3]);
	//fprintf(freport,"%s","     RDV5 : ");
	//myprintreg_rp(RDV->R_V[4]);
	return 1;
}

bool myprint_EXTV_rp()
{
	if(report_fl==0)
		return 0;
	fprintf(freport,"%s","\n     EXTV:\n");
	int i=0;
	for(;i<EXTV_NUM;i++)
	{
		fprintf(freport,"%s%d%s","     EXTV",i+1," : ");
		myprintreg_rp(EXTV->R_V[i]);
	}
	return 1;
}

bool myprint_MAT_rp()
{
	if(report_fl==0)
		return 0;
	int i,j;
	fprintf(freport,"%s","\n     MAT:\n");
	for(i=0;i<8;i++)
	{
		fprintf(freport,"num of layer %d\n",i);
		for(j=0;j<16;j++)
		{
			fprintf(freport,"ad%3d:%6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d %6d\n",16*j,MAT[i]->M_V[j].V[0],MAT[i]->M_V[j].V[1],MAT[i]->M_V[j].V[2],MAT[i]->M_V[j].V[3],MAT[i]->M_V[j].V[4],MAT[i]->M_V[j].V[5],MAT[i]->M_V[j].V[6],MAT[i]->M_V[j].V[7],MAT[i]->M_V[j].V[8],MAT[i]->M_V[j].V[9],MAT[i]->M_V[j].V[10],MAT[i]->M_V[j].V[11],MAT[i]->M_V[j].V[12],MAT[i]->M_V[j].V[13],MAT[i]->M_V[j].V[14],MAT[i]->M_V[j].V[15]);
	
		}
	}
	return 1;
}

bool myprint_BUFFER_rp()
{
	if(report_fl==0)
		return 0;
	int i,j;
	fprintf(freport,"%s","\n     buff0:\n");
	for(i=0;i<MEM_BUFF_ENTRY_SIZE;i++)
	{
		fprintf(freport,"%3d %s",i,":");
		for(j=0;j<MEM_BUFF_BANK_SIZE;j++)
		{
			fprintf(freport,"%6d \t",buff0->MM_B[i].MEM_B[j].MEM_D);
		}
		fprintf(freport,"\n");
	}
	
	fprintf(freport,"%s","\n     buff1:\n");
	for(i=0;i<MEM_BUFF_ENTRY_SIZE;i++)
	{
		fprintf(freport,"%3d %s",i,":");
		for(j=0;j<MEM_BUFF_BANK_SIZE;j++)
		{
			fprintf(freport,"%6d \t",buff1->MM_B[i].MEM_B[j].MEM_D);
		}
		fprintf(freport,"\n");
	}

	fprintf(freport,"%s","\n     buff2:\n");
	for(i=0;i<MEM_BUFF_ENTRY_SIZE;i++)
	{
		fprintf(freport,"%3d %s",i,":");
		for(j=0;j<MEM_BUFF_BANK_SIZE;j++)
		{
			fprintf(freport,"%6d \t",buff2->MM_B[i].MEM_B[j].MEM_D);
		}
		fprintf(freport,"\n");
	}

	fprintf(freport,"%s","\n     Rbuffer:\n");
	for(i=0;i<RG_SIZE;i++)
	{
		fprintf(freport,"%6d \t",Rbuffer.V[i]);
	}
	fprintf(freport,"%s","\n     Cbuffer:\n");
	for(i=0;i<RG_SIZE;i++)
	{
		fprintf(freport,"%6d \t",Cbuffer.V[i]);
	}
	fprintf(freport,"%s","\n     RMbuffer:\n");
	for(i=0;i<V_NUM;i++)
	{
		fprintf(freport,"%3d %s",i,":");
		for(j=0;j<V_SIZE;j++)
		{
			fprintf(freport,"%6d \t",Mbuffer.V[i][j]);
		}
		fprintf(freport,"\n");
	}
	
	return 1;
}
