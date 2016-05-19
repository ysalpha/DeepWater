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
 * bandwith monitor
 *
 * Statistical bandwidth requirements of the hardware modules
 */

#include <stdio.h>
#include "wintolinux.h"
#include <stdlib.h>
#include <string.h>

#include "bandwith_monitor.h"

/* define variants declared in the header file of bandwinth_monitor.h*/
long addition_num=0;
long multiplication_num=0;

long Rbuffer_in_bandwith=0;
long Rbuffer_out_bandwith=0;
long Cbuffer_in_bandwith=0;
long Cbuffer_out_bandwith=0;
long Mbuffer_in_bandwith=0;
long Mbuffer_out_bandwith=0;

long *RV_in_bandwith; 
long *RV_out_bandwith;
long *BV_in_bandwith;
long *BV_out_bandwith;
long *RDV_in_bandwith;
long *RDV_out_bandwith;
long *EXTV_in_bandwith;
long *EXTV_out_bandwith;
	 
long *MAT_in_bandwith;
long *MAT_out_bandwith;

long buffer0_in_bandwith=0;
long buffer0_out_bandwith=0;
long buffer1_in_bandwith=0;
long buffer1_out_bandwith=0;
long buffer2_in_bandwith=0;
long buffer2_out_bandwith=0;

long mem_in_bandwith=0;
long mem_out_bandwith=0;

/* define the temporary variant of bandwith_monitor.h*/
long addition_num_temp=0;
long multiplication_num_temp=0;

long Rbuffer_in_bandwith_temp=0;
long Rbuffer_out_bandwith_temp=0;
long Cbuffer_in_bandwith_temp=0;
long Cbuffer_out_bandwith_temp=0;
long Mbuffer_in_bandwith_temp=0;
long Mbuffer_out_bandwith_temp=0;

long *RV_in_bandwith_temp;
long *RV_out_bandwith_temp;
long *BV_in_bandwith_temp;
long *BV_out_bandwith_temp;
long *RDV_in_bandwith_temp;
long *RDV_out_bandwith_temp;
long *EXTV_in_bandwith_temp;
long *EXTV_out_bandwith_temp;

long *MAT_in_bandwith_temp;
long *MAT_out_bandwith_temp;

long buffer0_in_bandwith_temp=0;
long buffer0_out_bandwith_temp=0;
long buffer1_in_bandwith_temp=0;
long buffer1_out_bandwith_temp=0;
long buffer2_in_bandwith_temp=0;
long buffer2_out_bandwith_temp=0;

long mem_in_bandwith_temp=0;
long mem_out_bandwith_temp=0;

/*!
define a new variant to save the bandwith,
the value of bandwith subtract the value of temp_bandwith assign the variant of bandwith,
temp_bandwith is assigned by the new variant
*/
void bw_sub_temp_save()
{
	long temp_bandwith;
	temp_bandwith=addition_num;
	addition_num=addition_num-addition_num_temp;
	addition_num_temp=temp_bandwith;
	temp_bandwith=multiplication_num;
	multiplication_num=multiplication_num-multiplication_num_temp;
	multiplication_num_temp=temp_bandwith;

	temp_bandwith=Rbuffer_in_bandwith;
	Rbuffer_in_bandwith=Rbuffer_in_bandwith-Rbuffer_in_bandwith_temp;
	Rbuffer_in_bandwith_temp=temp_bandwith;
	temp_bandwith=Rbuffer_out_bandwith;
	Rbuffer_out_bandwith=Rbuffer_out_bandwith-Rbuffer_out_bandwith_temp;
	Rbuffer_out_bandwith_temp=temp_bandwith;
	temp_bandwith=Cbuffer_in_bandwith;
	Cbuffer_in_bandwith=Cbuffer_in_bandwith-Cbuffer_in_bandwith_temp;
	Cbuffer_in_bandwith_temp=temp_bandwith;
	temp_bandwith=Cbuffer_out_bandwith;
	Cbuffer_out_bandwith=Cbuffer_out_bandwith-Cbuffer_out_bandwith_temp;
	Cbuffer_out_bandwith_temp=temp_bandwith;
	temp_bandwith=Mbuffer_in_bandwith;
	Mbuffer_in_bandwith=Mbuffer_in_bandwith-Mbuffer_in_bandwith_temp;
	Mbuffer_in_bandwith_temp=temp_bandwith;
	temp_bandwith=Mbuffer_out_bandwith;
	Mbuffer_out_bandwith=Mbuffer_out_bandwith-Mbuffer_out_bandwith_temp;
	Mbuffer_out_bandwith_temp=temp_bandwith;

	temp_bandwith=buffer0_in_bandwith;
	buffer0_in_bandwith=buffer0_in_bandwith-buffer0_in_bandwith_temp;
	buffer0_in_bandwith_temp=temp_bandwith;
	temp_bandwith=buffer0_out_bandwith;
	buffer0_out_bandwith=buffer0_out_bandwith-buffer0_out_bandwith_temp;
	buffer0_out_bandwith_temp=temp_bandwith;
	temp_bandwith=buffer1_in_bandwith;
	buffer1_in_bandwith=buffer1_in_bandwith-buffer1_in_bandwith_temp;
	buffer1_in_bandwith_temp=temp_bandwith;
	temp_bandwith=buffer1_out_bandwith;
	buffer1_out_bandwith=buffer1_out_bandwith-buffer1_out_bandwith_temp;
	buffer1_out_bandwith_temp=temp_bandwith;
	temp_bandwith=buffer2_in_bandwith;
	buffer2_in_bandwith=buffer2_in_bandwith-buffer2_in_bandwith_temp;
	buffer2_in_bandwith_temp=temp_bandwith;
	temp_bandwith=buffer2_out_bandwith;
	buffer2_out_bandwith=buffer2_out_bandwith-buffer2_out_bandwith;
	buffer2_out_bandwith=temp_bandwith;

	temp_bandwith=mem_in_bandwith;
	mem_in_bandwith=mem_in_bandwith-mem_in_bandwith_temp;
	mem_in_bandwith_temp=temp_bandwith;
	temp_bandwith=mem_out_bandwith;
	mem_out_bandwith=mem_out_bandwith-mem_out_bandwith_temp;
	mem_out_bandwith_temp=temp_bandwith;

	int count_bw=0;
	for(count_bw=0;count_bw<RG_NUM;count_bw++)
	{
		temp_bandwith=RV_in_bandwith[count_bw];
		RV_in_bandwith[count_bw]=RV_in_bandwith[count_bw]-RV_in_bandwith_temp[count_bw];
		RV_in_bandwith_temp[count_bw]=temp_bandwith;
		temp_bandwith=RV_out_bandwith[count_bw];
		RV_out_bandwith[count_bw]=RV_out_bandwith[count_bw]-RV_out_bandwith_temp[count_bw];
		RV_out_bandwith_temp[count_bw]=temp_bandwith;
	}
	for(count_bw=0;count_bw<BV_NUM;count_bw++)
	{
		temp_bandwith=BV_in_bandwith[count_bw];
		BV_in_bandwith[count_bw]=BV_in_bandwith[count_bw]-BV_in_bandwith_temp[count_bw];
		BV_in_bandwith_temp[count_bw]=temp_bandwith;
		temp_bandwith=BV_out_bandwith[count_bw];
		BV_out_bandwith[count_bw]=BV_out_bandwith[count_bw]-BV_out_bandwith_temp[count_bw];
		BV_out_bandwith_temp[count_bw]=temp_bandwith;
	}
	for(count_bw=0;count_bw<RDV_NUM;count_bw++)
	{
		temp_bandwith=RDV_in_bandwith[count_bw];
		RDV_in_bandwith[count_bw]=RDV_in_bandwith[count_bw]-RDV_in_bandwith_temp[count_bw];
		RDV_in_bandwith_temp[count_bw]=temp_bandwith;
		temp_bandwith=RDV_out_bandwith[count_bw];
		RDV_out_bandwith[count_bw]=RDV_out_bandwith[count_bw]-RDV_out_bandwith_temp[count_bw];
		RDV_out_bandwith_temp[count_bw]=temp_bandwith;
	}
	for(count_bw=0;count_bw<EXTV_NUM;count_bw++)
	{
		temp_bandwith=EXTV_in_bandwith[count_bw];
		EXTV_in_bandwith[count_bw]=EXTV_in_bandwith[count_bw]-EXTV_in_bandwith_temp[count_bw];
		EXTV_in_bandwith_temp[count_bw]=temp_bandwith;
		temp_bandwith=EXTV_out_bandwith[count_bw];
		EXTV_out_bandwith[count_bw]=EXTV_out_bandwith[count_bw]-EXTV_out_bandwith_temp[count_bw];
		EXTV_out_bandwith_temp[count_bw]=temp_bandwith;
	}
	for(count_bw=0;count_bw<M_LAYER;count_bw++)
	{
		temp_bandwith=MAT_in_bandwith[count_bw];
		MAT_in_bandwith[count_bw]=MAT_in_bandwith[count_bw]-MAT_in_bandwith_temp[count_bw];
		MAT_in_bandwith_temp[count_bw]=temp_bandwith;
		temp_bandwith=MAT_out_bandwith[count_bw];
		MAT_out_bandwith[count_bw]=MAT_out_bandwith[count_bw]-MAT_out_bandwith_temp[count_bw];
		MAT_out_bandwith_temp[count_bw]=temp_bandwith;
	}


}

/*!
bandwith is assign by temp_bandwith
*/
void save_temp_bw()
{
	addition_num=addition_num_temp;
	multiplication_num=multiplication_num_temp;

	Rbuffer_in_bandwith=Rbuffer_in_bandwith_temp;
	Rbuffer_out_bandwith=Rbuffer_out_bandwith_temp;
	Cbuffer_in_bandwith=Cbuffer_in_bandwith_temp;
	Cbuffer_out_bandwith=Cbuffer_out_bandwith_temp;
	Mbuffer_in_bandwith=Mbuffer_in_bandwith_temp;
	Mbuffer_out_bandwith=Mbuffer_out_bandwith_temp;

	buffer0_in_bandwith=buffer0_in_bandwith_temp;
	buffer0_out_bandwith=buffer0_out_bandwith_temp;
	buffer1_in_bandwith=buffer1_in_bandwith_temp;
	buffer1_out_bandwith=buffer1_out_bandwith_temp;
	buffer2_in_bandwith=buffer2_in_bandwith_temp;
	buffer2_out_bandwith=buffer2_out_bandwith_temp;

	mem_in_bandwith=mem_in_bandwith_temp;
	mem_out_bandwith=mem_out_bandwith_temp;

	int count_bw=0;
	for(count_bw=0;count_bw<RG_NUM;count_bw++)
	{
		RV_in_bandwith[count_bw]=RV_in_bandwith_temp[count_bw];
		RV_out_bandwith[count_bw]=RV_out_bandwith_temp[count_bw];
	}
	for(count_bw=0;count_bw<BV_NUM;count_bw++)
	{
		BV_in_bandwith[count_bw]=BV_in_bandwith_temp[count_bw];
		BV_out_bandwith[count_bw]=BV_out_bandwith_temp[count_bw];
	}
	for(count_bw=0;count_bw<RDV_NUM;count_bw++)
	{
		RDV_in_bandwith[count_bw]=RDV_in_bandwith_temp[count_bw];
		RDV_out_bandwith[count_bw]=RDV_out_bandwith_temp[count_bw];
	}
	for(count_bw=0;count_bw<EXTV_NUM;count_bw++)
	{
		EXTV_in_bandwith[count_bw]=EXTV_in_bandwith_temp[count_bw];
		EXTV_out_bandwith[count_bw]=EXTV_out_bandwith_temp[count_bw];
	}
	for(count_bw=0;count_bw<M_LAYER;count_bw++)
	{
		MAT_in_bandwith[count_bw]=MAT_in_bandwith_temp[count_bw];
		MAT_out_bandwith[count_bw]=MAT_out_bandwith_temp[count_bw];
	}
}

/*!
save the value of bandwith to file
*/
void print_bandwith()
{
	if(access("bandwith",0)) // if the folder of .\bandwith not exist , call windows system function to create it//
	{
		if( system("mkdir bandwith") !=0 )
		{
			printf(" cann't not creat bandwith folder.\n");
			exit(0);
		}
	}
	FILE *fp = fopen(BANDWITN,"w+");// open the file to write,BANDWITN is the macro defined in bandwith_monitor.h//
	if(fp==NULL)
	{
		printf(" cann't not creat %s folder.\n",BANDWITN);
		exit(0);
	}
	fprintf(fp,"*************************************************");
	fprintf(fp,"************* bandwith !******************");
	
	fprintf(fp,"\n");
	fprintf(fp,"addition_num : %d\n",addition_num);
	fprintf(fp,"multiplication_num : %d\n",multiplication_num);
	fprintf(fp,"\n");

	fprintf(fp,"Rbuffer_in_bandwith : %ld\n",Rbuffer_in_bandwith);
	fprintf(fp,"Rbuffer_out_bandwith : %ld\n",Rbuffer_out_bandwith);
	fprintf(fp,"Cbuffer_in_bandwith : %ld\n",Cbuffer_in_bandwith);
	fprintf(fp,"Cbuffer_out_bandwith : %ld\n",Cbuffer_out_bandwith);
	fprintf(fp,"Mbuffer_in_bandwith : %ld\n",Mbuffer_in_bandwith);
	fprintf(fp,"Mbuffer_out_bandwith : %ld\n",Mbuffer_out_bandwith);
	fprintf(fp,"\n");

	long  temp_bandwith=0;
	long temp2_bandwith=0;
	int i=0;
	for(i=0;i<RG_NUM;i++)
	{
		temp_bandwith+=RV_in_bandwith[i];
	}
	fprintf(fp,"ALL_of_RV_in_bandwith : %ld\n",temp_bandwith);
	for(i=0;i<RG_NUM;i++)
	{
		fprintf(fp,"RV%d_in_bandwith : %ld\n",i,RV_in_bandwith[i]);
	}
	fprintf(fp,"\n");
	for(i=0;i<RG_NUM;i++)
	{
		temp_bandwith+=RV_out_bandwith[i];
	}
	fprintf(fp,"ALL_of_RV_out_bandwith : %ld\n",temp_bandwith);
	for(i=0;i<RG_NUM;i++)
	{
		fprintf(fp,"RV%d_out_bandwith : %ld\n",i,RV_out_bandwith[i]);
	}
	fprintf(fp,"\n");

	for(i=0;i<BV_NUM;i++)
	{
		temp_bandwith+=BV_in_bandwith[i];
	}
	fprintf(fp,"ALL_of_BV_in_bandwith : %ld\n",temp_bandwith);
	for(i=0;i<BV_NUM;i++)
	{
		fprintf(fp,"BV%d_in_bandwith : %ld\n",i,BV_in_bandwith[i]);
	}
	fprintf(fp,"\n");
	for(i=0;i<BV_NUM;i++)
	{
		temp_bandwith+=BV_out_bandwith[i];
	}
	fprintf(fp,"ALL_of_BV_out_bandwith : %ld\n",temp_bandwith);
	for(i=0;i<BV_NUM;i++)
	{
		fprintf(fp,"BV%d_out_bandwith : %ld\n",i,BV_out_bandwith[i]);
	}
	fprintf(fp,"\n");

	for(i=0;i<RDV_NUM;i++)
	{
		temp_bandwith+=RDV_in_bandwith[i];
	}
	fprintf(fp,"ALL_of_RDV_in_bandwith : %ld\n",temp_bandwith);
	for(i=0;i<RDV_NUM;i++)
	{
		fprintf(fp,"RDV%d_in_bandwith : %ld\n",i,RDV_in_bandwith[i]);
	}
	fprintf(fp,"\n");
	for(i=0;i<RDV_NUM;i++)
	{
		temp_bandwith+=RDV_out_bandwith[i];
	}
	fprintf(fp,"ALL_of_RDV_out_bandwith : %ld\n",temp_bandwith);
	for(i=0;i<RDV_NUM;i++)
	{
		fprintf(fp,"RDV%d_out_bandwith : %ld\n",i,RDV_out_bandwith[i]);
	}
	fprintf(fp,"\n");

	for(i=0;i<EXTV_NUM;i++)
	{
		temp_bandwith+=EXTV_in_bandwith[i];
	}
	fprintf(fp,"ALL_of_EXTV_in_bandwith : %ld\n",temp_bandwith);
	for(i=0;i<EXTV_NUM;i++)
	{
		fprintf(fp,"EXTV%d_in_bandwith : %ld\n",i,EXTV_in_bandwith[i]);
	}
	fprintf(fp,"\n");
	for(i=0;i<EXTV_NUM;i++)
	{
		temp_bandwith+=EXTV_out_bandwith[i];
	}
	fprintf(fp,"ALL_of_EXTV_out_bandwith : %ld\n",temp_bandwith);
	for(i=0;i<EXTV_NUM;i++)
	{
		fprintf(fp,"EXTV%d_out_bandwith : %ld\n",i,EXTV_out_bandwith[i]);
	}
	fprintf(fp,"\n");

	for(i=0;i<M_LAYER;i++)
	{
		fprintf(fp,"MAT%d_in_bandwith : %ld\n",i,MAT_in_bandwith[i]);
		fprintf(fp,"MAT%d_out_bandwith : %ld\n",i,MAT_out_bandwith[i]);
		temp2_bandwith+=MAT_out_bandwith[i];
		temp_bandwith+=MAT_in_bandwith[i];
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n");
	fprintf(fp,"ALL_of_MAT%d_in_bandwith : %ld\n",i,temp_bandwith);
	fprintf(fp,"ALL_of_MAT%d_out_bandwith : %ld\n",i,temp2_bandwith);
	fprintf(fp,"\n");
	fprintf(fp,"\n");

	fprintf(fp,"buffer0_in_bandwith : %ld\n",buffer0_in_bandwith);
	fprintf(fp,"buffer0_out_bandwith : %ld\n",buffer0_out_bandwith);
	fprintf(fp,"buffer1_in_bandwith : %ld\n",buffer1_in_bandwith);
	fprintf(fp,"buffer1_out_bandwith : %ld\n",buffer1_out_bandwith);
	fprintf(fp,"buffer2_in_bandwith : %ld\n",buffer2_in_bandwith);
	fprintf(fp,"buffer2_out_bandwith : %ld\n",buffer2_out_bandwith);

	fprintf(fp,"\n");

	fprintf(fp,"mem_in_bandwith : %ld\n",mem_in_bandwith);
	fprintf(fp,"mem_out_bandwith : %ld\n",mem_out_bandwith);

	fclose(fp);//close the file pointer//

}


void init_bw_sd()
{
	RV_in_bandwith = (long *)malloc(sizeof(long)*RG_NUM); 
	memset(RV_in_bandwith,0,sizeof(long)*RDV_NUM);

	RV_out_bandwith = (long *)malloc(sizeof(long)*RG_NUM);
	memset(RV_out_bandwith,0,sizeof(long)*RG_NUM);

	BV_in_bandwith = (long *)malloc(sizeof(long)*BV_NUM);
	memset(BV_in_bandwith,0,sizeof(long)*BV_NUM);

	BV_out_bandwith = (long *)malloc(sizeof(long)*BV_NUM);
	memset(BV_out_bandwith,0,sizeof(long)*BV_NUM);

	RDV_in_bandwith = (long *)malloc(sizeof(long)*RDV_NUM);
	memset(RDV_in_bandwith,0,sizeof(long)*RDV_NUM);

	RDV_out_bandwith = (long *)malloc(sizeof(long)*RDV_NUM);
	memset(RDV_out_bandwith,0,sizeof(long)*RDV_NUM);

	EXTV_in_bandwith = (long *)malloc(sizeof(long)*EXTV_NUM);
	memset(EXTV_in_bandwith,0,sizeof(long)*EXTV_NUM);

	EXTV_out_bandwith = (long *)malloc(sizeof(long)*EXTV_NUM);
	memset(EXTV_out_bandwith,0,sizeof(long)*EXTV_NUM);

	MAT_in_bandwith = (long *)malloc(sizeof(long)*M_LAYER);
	memset(MAT_in_bandwith,0,sizeof(long)*M_LAYER);

	MAT_out_bandwith = (long*)malloc(sizeof(long)*M_LAYER);
	memset(MAT_out_bandwith,0,sizeof(long)*M_LAYER);

	RV_in_bandwith_temp = (long *)malloc(sizeof(long)*RG_NUM);
	memset(RV_in_bandwith_temp,0,sizeof(long)*RG_NUM);

	RV_out_bandwith_temp = (long*)malloc(sizeof(long)*RG_NUM);
	memset(RV_out_bandwith_temp,0,sizeof(long)*RG_NUM);

	BV_in_bandwith_temp = (long *)malloc(sizeof(long)*BV_NUM);
	memset(BV_in_bandwith_temp,0,sizeof(long)*BV_NUM);

	BV_out_bandwith_temp = (long *)malloc(sizeof(long)*BV_NUM);
	memset(BV_out_bandwith_temp,0,sizeof(long)*BV_NUM);

	RDV_in_bandwith_temp = (long *)malloc(sizeof(long)*RDV_NUM);
	memset(RDV_in_bandwith_temp,0,sizeof(long)*RDV_NUM);

	RDV_out_bandwith_temp = (long*)malloc(sizeof(long)*RDV_NUM);
	memset(RDV_out_bandwith,0,sizeof(long)*RDV_NUM);

	EXTV_in_bandwith_temp = (long *)malloc(sizeof(long)*EXTV_NUM);
	memset(EXTV_in_bandwith_temp,0,sizeof(long)*EXTV_NUM);

	EXTV_out_bandwith_temp = (long *)malloc(sizeof(long)*EXTV_NUM);
	memset(EXTV_out_bandwith_temp,0,sizeof(long)*EXTV_NUM);

	MAT_in_bandwith_temp = (long *)malloc(sizeof(long)*M_LAYER);
	memset(MAT_in_bandwith_temp,0,sizeof(long)*M_LAYER);

	MAT_out_bandwith_temp = (long *)malloc(sizeof(long)*M_LAYER);
	memset(MAT_out_bandwith_temp,0,sizeof(long)*M_LAYER);;
}
