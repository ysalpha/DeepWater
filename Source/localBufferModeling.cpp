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
 * localBuffer Modeling
 *
 * hardware model local buffer Modeling
 */

#include <stdio.h>
#include <stdlib.h>

#include "localBufferModeling.h"

struct MEM_B *buff0,*buff1,*buff2;
struct MEM_B *pbuff0,*pbuff1,*pbuff2;

bool Init_buff()
{
	int i,j;
	buff0=(struct MEM_B*)malloc(sizeof(struct MEM_B));   //Initialize buff0
	buff1=(struct MEM_B*)malloc(sizeof(struct MEM_B));  //Initialize buff1
	buff2=(struct MEM_B*)malloc(sizeof(struct MEM_B)); //Initialize buff2

	buff0->isWrite=0;
	buff0->isRead=0;
	buff1->isWrite=0;
	buff1->isRead=0;
	buff2->isWrite=0;
	buff2->isRead=0;

	buff0->MM_B = (struct MEM_B_S *)malloc(sizeof(MEM_B_S)*MEM_BUFF_ENTRY_SIZE);
	buff1->MM_B = (struct MEM_B_S *)malloc(sizeof(MEM_B_S)*MEM_BUFF_ENTRY_SIZE);
	buff2->MM_B = (struct MEM_B_S *)malloc(sizeof(MEM_B_S)*MEM_BUFF_ENTRY_SIZE);

	for(i=0;i<MEM_BUFF_ENTRY_SIZE;i++)
	{
		buff0->MM_B[i].MEM_B = (struct MEM_B_B *)malloc(sizeof(MEM_B_B)*MEM_BUFF_BANK_SIZE); 
		buff1->MM_B[i].MEM_B = (struct MEM_B_B *)malloc(sizeof(MEM_B_B)*MEM_BUFF_BANK_SIZE); 
		buff2->MM_B[i].MEM_B = (struct MEM_B_B *)malloc(sizeof(MEM_B_B)*MEM_BUFF_BANK_SIZE); 
		for(j=0;j<MEM_BUFF_BANK_SIZE;j++)
		{
			buff0->MM_B[i].MEM_B[j].MEM_D=0;
			buff1->MM_B[i].MEM_B[j].MEM_D=0;
			buff2->MM_B[i].MEM_B[j].MEM_D=0;

			buff0->MM_B[i].MEM_B[j].RD_S=INVALID;
			buff0->MM_B[i].MEM_B[j].WRD_S=INVALID;
			buff0->MM_B[i].MEM_B[j].WR_S=INVALID;
			buff0->MM_B[i].MEM_B[j].WWR_S=INVALID;

			buff1->MM_B[i].MEM_B[j].RD_S=INVALID;
			buff1->MM_B[i].MEM_B[j].WRD_S=INVALID;
			buff1->MM_B[i].MEM_B[j].WR_S=INVALID;
			buff1->MM_B[i].MEM_B[j].WWR_S=INVALID;

			buff2->MM_B[i].MEM_B[j].RD_S=INVALID;
			buff2->MM_B[i].MEM_B[j].WRD_S=INVALID;
			buff2->MM_B[i].MEM_B[j].WR_S=INVALID;
			buff2->MM_B[i].MEM_B[j].WWR_S=INVALID;
		}
	}

	pbuff0=(struct MEM_B*)malloc(sizeof(struct MEM_B));   //Initialize buff0
	pbuff1=(struct MEM_B*)malloc(sizeof(struct MEM_B));  //Initialize buff1
	pbuff2=(struct MEM_B*)malloc(sizeof(struct MEM_B)); //Initialize buff2

	pbuff0->isWrite=0;
	pbuff0->isRead=0;
	pbuff1->isWrite=0;
	pbuff1->isRead=0;
	pbuff2->isWrite=0;
	pbuff2->isRead=0;

	pbuff0->MM_B = (struct MEM_B_S *)malloc(sizeof(MEM_B_S)*MEM_BUFF_ENTRY_SIZE);
	pbuff1->MM_B = (struct MEM_B_S *)malloc(sizeof(MEM_B_S)*MEM_BUFF_ENTRY_SIZE);
	pbuff2->MM_B = (struct MEM_B_S *)malloc(sizeof(MEM_B_S)*MEM_BUFF_ENTRY_SIZE);

	for(i=0;i<MEM_BUFF_ENTRY_SIZE;i++)
	{
		pbuff0->MM_B[i].MEM_B = (struct MEM_B_B *)malloc(sizeof(MEM_B_B)*MEM_BUFF_BANK_SIZE); 
		pbuff1->MM_B[i].MEM_B = (struct MEM_B_B *)malloc(sizeof(MEM_B_B)*MEM_BUFF_BANK_SIZE); 
		pbuff2->MM_B[i].MEM_B = (struct MEM_B_B *)malloc(sizeof(MEM_B_B)*MEM_BUFF_BANK_SIZE); 
		for(j=0;j<MEM_BUFF_BANK_SIZE;j++)
		{
			pbuff0->MM_B[i].MEM_B[j].MEM_D=0;
			pbuff1->MM_B[i].MEM_B[j].MEM_D=0;
			pbuff2->MM_B[i].MEM_B[j].MEM_D=0;

			pbuff0->MM_B[i].MEM_B[j].RD_S=INVALID;
			pbuff0->MM_B[i].MEM_B[j].WRD_S=INVALID;
			pbuff0->MM_B[i].MEM_B[j].WR_S=INVALID;
			pbuff0->MM_B[i].MEM_B[j].WWR_S=INVALID;

			pbuff1->MM_B[i].MEM_B[j].RD_S=INVALID;
			pbuff1->MM_B[i].MEM_B[j].WRD_S=INVALID;
			pbuff1->MM_B[i].MEM_B[j].WR_S=INVALID;
			pbuff1->MM_B[i].MEM_B[j].WWR_S=INVALID;

			pbuff2->MM_B[i].MEM_B[j].RD_S=INVALID;
			pbuff2->MM_B[i].MEM_B[j].WRD_S=INVALID;
			pbuff2->MM_B[i].MEM_B[j].WR_S=INVALID;
			pbuff2->MM_B[i].MEM_B[j].WWR_S=INVALID;
		}
	}

	return 1;
}

bool jud_mb_entryread(int num_ofbuff,long mem_b_address)
{
	bool able=1;
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			able=jud_mb_dread(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			able=jud_mb_dread(1,mem_b_address,i);
		}
		else
			able=jud_mb_dread(2,mem_b_address,i);
		if(able==0)
		{
			return able;
		}
	}
	return able;
}

bool jud_mb_entrywrite(int num_ofbuff,long mem_b_address)
{
	bool able=1;
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			able=jud_mb_dwrite(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			able=jud_mb_dwrite(1,mem_b_address,i);
		}
		else
			able=jud_mb_dwrite(2,mem_b_address,i);
		if(able==0)
		{
			return able;
		}
	}
	return able;
}

bool set_mb_entryrd(int num_ofbuff,long mem_b_address)
{
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			set_mb_drd(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			set_mb_drd(1,mem_b_address,i);
		}
		else
			set_mb_drd(2,mem_b_address,i);
	}
	return 1;
}

bool set_mb_entrywrd(int num_ofbuff,long mem_b_address)
{
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			set_mb_dwrd(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			set_mb_dwrd(1,mem_b_address,i);
		}
		else
			set_mb_dwrd(2,mem_b_address,i);
	}
	return 1;
}

bool set_mb_entrywr(int num_ofbuff,long mem_b_address)
{
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			set_mb_dwr(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			set_mb_dwr(1,mem_b_address,i);
		}
		else
			set_mb_dwr(2,mem_b_address,i);
	}
	return 1;
}

bool set_mb_entrywwr(int num_ofbuff,long mem_b_address)
{
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			set_mb_dwwr(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			set_mb_dwwr(1,mem_b_address,i);
		}
		else
			set_mb_dwwr(2,mem_b_address,i);
	}
	return 1;
}

bool clr_mb_entryrd(int num_ofbuff,long mem_b_address)
{
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			clr_mb_drd(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			clr_mb_drd(1,mem_b_address,i);
		}
		else
			clr_mb_drd(2,mem_b_address,i);
	}
	return 1;
}

bool clr_mb_entrywrd(int num_ofbuff,long mem_b_address)
{
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			clr_mb_dwrd(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			clr_mb_dwrd(1,mem_b_address,i);
		}
		else
			clr_mb_dwrd(2,mem_b_address,i);
	}
	return 1;
}

bool clr_mb_entrywr(int num_ofbuff,long mem_b_address)
{
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			clr_mb_dwr(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			clr_mb_dwr(1,mem_b_address,i);
		}
		else
			clr_mb_dwr(2,mem_b_address,i);
	}
	return 1;
}

bool clr_mb_entrywwr(int num_ofbuff,long mem_b_address)
{
	int i;
	for(i=0;i<MEM_BUFF_BANK_SIZE;i++)
	{
		if(num_ofbuff==0)
		{
			clr_mb_dwwr(0,mem_b_address,i);
		}
		else if(num_ofbuff==1)
		{
			clr_mb_dwwr(1,mem_b_address,i);
		}
		else
			clr_mb_dwwr(2,mem_b_address,i);
	}
	return 1;
}
