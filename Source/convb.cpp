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
 * convb
 *
 * Conversion instructions into binary instructions
 */

#include<stdlib.h>
#include<string.h>

#include "convb.h"
#include "pl_kernel.h"
#include "ps_inst.h"
#include "wintolinux.h"

/* define the variant to save the name of saving binary data file*/
char save_b[] = SAVE_B_FILE;

/* open the file point to save out_order instructions and binary data*/
FILE* fp_saveRTLB;
FILE* fp_Ri;

/* initialize save binary file piont */
void init_hd_file()
{
	fp_saveRTLB = fopen(save_b,"w+");
    fp_Ri = fopen("RTL_INS.txt","w+");
    if (!fp_saveRTLB)
	{
		printf("can not open %s in convb.cpp\n", save_b);
		exit(0);
	}
	if (!fp_Ri)
	{
		printf("can not open %s in convb.cpp\n", "RTL_INS.txt");
		exit(0);
	}
}

/*!
match the BV register file and convert to binary ,saving the binary data to fp
input: ploprand declare in macro.h,inss_C is the strcuture of instrcution, op_n is the number of oprands,
fp is the file point to save the binary data
*/
void match_BV_ADDR(ploprand inss_C,int op_n,FILE* fp)
{
	char buff_b[50];
	int i,l,m;
	if(num_ofrg(inss_C,op_n,B)==0)//get the serial number of BV register file
	{
		itoa(BV0_ADDR,buff_b,2);//convert the BV0_ADDR to binary
		l=strlen(buff_b);
		m=RG_A_L-l;
		/* buff_b expand to the length of m by '0'*/
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,B)==1)
	{
		itoa(BV1_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,B)==2)
	{
		itoa(BV2_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,B)==3)
	{
		itoa(BV3_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else
	{
		fprintf(fp,"%s","[use not exist BV in convb.cpp]");
	}
}

void match_RV_ADDR(ploprand inss_C,int op_n,FILE* fp)
{
	char buff_b[50];
	int i,l,m;
	if(num_ofrg(inss_C,op_n,R)==0)
	{
		itoa(RV0_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==1)
	{
		itoa(RV1_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==2)
	{
		itoa(RV2_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==3)
	{
		itoa(RV3_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==4)
	{
		itoa(RV4_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==5)
	{
		itoa(RV5_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==6)
	{
		itoa(RV6_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==7)
	{
		itoa(RV7_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==8)
	{
		itoa(RV8_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==9)
	{
		itoa(RV9_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==10)
	{
		itoa(RV10_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==11)
	{
		itoa(RV11_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==12)
	{
		itoa(RV12_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==13)
	{
		itoa(RV13_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==14)
	{
		itoa(RV14_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==15)
	{
		itoa(RV15_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else
	{
		fprintf(fp,"%s","[use not exist RV in convb.cpp]");
	}
}

void match_RDV_ADDR(ploprand inss_C,int op_n,FILE* fp)
{
	char buff_b[50];
	int i,l,m;
	if(num_ofrg(inss_C,op_n,R)==0)
	{
		itoa(RDV0_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==1)
	{
		itoa(RDV1_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==2)
	{
		itoa(RDV2_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==3)
	{
		itoa(RDV3_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else
	{
		fprintf(fp,"%s","[use not exist RDV in convb.cpp]");
	}
}

void match_EXTV_ADDR(ploprand inss_C,int op_n,FILE* fp)
{
	char buff_b[20];
	int i,l,m;
	if(num_ofrg(inss_C,op_n,R)==0)
	{
		itoa(EXTV0_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==1)
	{
		itoa(EXTV1_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==2)
	{
		itoa(EXTV2_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==3)
	{
		itoa(EXTV3_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==4)
	{
		itoa(EXTV4_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==5)
	{
		itoa(EXTV5_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==6)
	{
		itoa(EXTV6_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(num_ofrg(inss_C,op_n,R)==7)
	{
		itoa(EXTV7_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=RG_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else
	{
		fprintf(fp,"%s","[use not exist EXTV in convb.cpp]");
	}
}

void match_BUFFER_ID_ADDR(int buffer_id,FILE* fp)
{
	char buff_b[20];
	int i,l,m;
	itoa(buffer_id,buff_b,2);
	l=strlen(buff_b);
	m=BUFF_ID_A_L-l;
	if(m>0)
	{
		for(i=0;i<=l;i++)
		{
			buff_b[l+m-i]=buff_b[l-i];
		}
		for(i=0;i<m;i++)
		{
			buff_b[i]='0';
		}
	}
	fprintf(fp,"%s",buff_b);
}

void match_LENGTH_ADDR(int length,FILE* fp,int l_A_l)
{
	char buff_b[20];
	int i,l,m;
	itoa(length-1,buff_b,2); //value of length range is between 1 and 16 in code, length address in RTL is 0-15
	l=strlen(buff_b);
	m=l_A_l-l;
	if(m>0)
	{
		for(i=0;i<=l;i++)
		{
			buff_b[l+m-i]=buff_b[l-i];
		}
		for(i=0;i<m;i++)
		{
			buff_b[i]='0';
		}
	}
	fprintf(fp,"%s",buff_b);
}

void match_BUFFER_ADDR_ADDR(long buffer_addr,FILE* fp)
{
	char buff_b[20];
	int i,l,m;
	itoa(buffer_addr,buff_b,2);
	l=strlen(buff_b);
	m=BUFFER_ADDR_A_L-l;
	if(m>0)
	{
		for(i=0;i<=l;i++)
		{
			buff_b[l+m-i]=buff_b[l-i];
		}
		for(i=0;i<m;i++)
		{
			buff_b[i]='0';
		}
	}
	fprintf(fp,"%s",buff_b);
}

void match_LAYER_ADDR_ADDR(ploprand inss_C,int op_n,FILE* fp)
{
	char buff_b[20];
	int i,l,m;
	if(inss_C.op[op_n].opd.type_MAT.mat_num == 0)
	{
		itoa(MAT0_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=MAT_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(inss_C.op[op_n].opd.type_MAT.mat_num == 1)
	{
		itoa(MAT1_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=MAT_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(inss_C.op[op_n].opd.type_MAT.mat_num == 2)
	{
		itoa(MAT2_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=MAT_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(inss_C.op[op_n].opd.type_MAT.mat_num == 3)
	{
		itoa(MAT3_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=MAT_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(inss_C.op[op_n].opd.type_MAT.mat_num == 4)
	{
		itoa(MAT4_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=MAT_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(inss_C.op[op_n].opd.type_MAT.mat_num == 5)
	{
		itoa(MAT5_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=MAT_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(inss_C.op[op_n].opd.type_MAT.mat_num == 6)
	{
		itoa(MAT6_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=MAT_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else if(inss_C.op[op_n].opd.type_MAT.mat_num == 7)
	{
		itoa(MAT7_ADDR,buff_b,2);
		l=strlen(buff_b);
		m=MAT_A_L-l;
		if(m>0)
		{
			for(i=0;i<=l;i++)
			{
				buff_b[l+m-i]=buff_b[l-i];
			}
			for(i=0;i<m;i++)
			{
				buff_b[i]='0';
			}
		}
		fprintf(fp,"%s",buff_b);
	}
	else
	{
		fprintf(fp,"%s","[use not exist MAT in convb.cpp]");
	}
}

void match_ROW_COL_ADDR(int row_col,FILE* fp)
{
	char buff_b[20];
	int i,l,m;
	itoa(row_col-1,buff_b,2);
	l=strlen(buff_b);
	m=ROW_COL_A_L-l;
	if(m>0)
	{
		for(i=0;i<=l;i++)
		{
			buff_b[l+m-i]=buff_b[l-i];
		}
		for(i=0;i<m;i++)
		{
			buff_b[i]='0';
		}
	}
	fprintf(fp,"%s",buff_b);
}

void match_MEM_ADDR_ADDR(long mem_addr,FILE* fp,char* buff_b_l)
{
	char buff_b[40];
	char buff_b_h[MEN_ADDR_H_A_L+1];
	int i,l,m,j=0;
	ltoa(mem_addr,buff_b,2);
	l=strlen(buff_b);
	m=MEM_ADDR_A_L-l;
	if(m>0)
	{
		for(i=0;i<=l;i++)
		{
			buff_b[l+m-i]=buff_b[l-i];
		}
		for(i=0;i<m;i++)
		{
			buff_b[i]='0';
		}
	}
	for(i=0;i<MEN_ADDR_H_A_L;i++)
	{
		buff_b_h[i]=buff_b[i];
	}
	buff_b_h[i]='\0';
	fprintf(fp,"%s",buff_b_h);
	for(;i<=MEM_ADDR_A_L;i++)
	{
		buff_b_l[j++]=buff_b[i];
	}
}

void match_STRIDE_ADDR(int stride,FILE* fp)
{
	char buff_b[20];
	int i,l,m;
	itoa(stride,buff_b,2);
	l=strlen(buff_b);
	m=STRIDE_A_L-l;
	if(m>0)
	{
		for(i=0;i<=l;i++)
		{
			buff_b[l+m-i]=buff_b[l-i];
		}
		for(i=0;i<m;i++)
		{
			buff_b[i]='0';
		}
	}
	fprintf(fp,"%s",buff_b);
}

void match_REPETITION_ADDR(int repetition,FILE* fp)
{
	char buff_b[20];
	int i,l,m;
	itoa(repetition,buff_b,2);
	l=strlen(buff_b);
	m=REPETITION_A_L-l;
	if(m>0)
	{
		for(i=0;i<=l;i++)
		{
			buff_b[l+m-i]=buff_b[l-i];
		}
		for(i=0;i<m;i++)
		{
			buff_b[i]='0';
		}
	}
	fprintf(fp,"%s",buff_b);
}

void match_SCALE_FACTOR_ADDR(int scale_factor,FILE* fp)
{
	char buff_b[20];
	int i,l,m;
	itoa(scale_factor,buff_b,2);
	l=strlen(buff_b);
	m=SCALE_FACTOR_A_L-l;
	if(m>0)
	{
		for(i=0;i<=l;i++)
		{
			buff_b[l+m-i]=buff_b[l-i];
		}
		for(i=0;i<m;i++)
		{
			buff_b[i]='0';
		}
	}
	fprintf(fp,"%s",buff_b);
}

void match_BIAS_ADDR(int biase,FILE* fp)
{
	char buff_b[20];
	int i,l,m;
	itoa(biase,buff_b,2);
	l=strlen(buff_b);
	m=BIASE_A_L-l;
	if(m>0)
	{
		for(i=0;i<=l;i++)
		{
			buff_b[l+m-i]=buff_b[l-i];
		}
		for(i=0;i<m;i++)
		{
			buff_b[i]='0';
		}
	}
	fprintf(fp,"%s",buff_b);
}

void match_ACT_TYPE_ADDR(int act_type,FILE* fp)
{
	char buff_b[20];
	itoa(act_type,buff_b,2);
	fprintf(fp,"%011s",buff_b);
}

void put_str_ADDR(char* str,FILE* fp)
{
	fprintf(fp,"%s",str);
}

void zeroize_ADDR(int count,FILE* fp)
{
	int i=0;
	char *a = (char*)malloc(sizeof(char)*count+1);
	for(;i<count;i++)
	{
		a[i]='0';
	}
	a[i]='\0';
	fprintf(fp,"%s",a);
	free(a);
}

void linefeed_ADDR(FILE* fp)
{
	fprintf(fp,"\n");
}

bool convert_ins_to_b(ploprand instob,FILE* fp)
{
	switch(ins[instob.ex_ins].opcode)
	{
	case LOAD_OPCODE:
		{
			fprintf(fp,"%s",LOAD0_ADDR);
			if(instob.op[0].type_flag==0)
			{
				match_BV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag==1)
			{
				match_RV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag==2)
			{
				match_RDV_ADDR(instob,0,fp);
			}
			zeroize_ADDR(1,fp);
			match_BUFFER_ID_ADDR(instob.op[2].opd.type_BUFF.buff_id,fp);
			match_LENGTH_ADDR(instob.op[1].opd.length,fp,LENGTH_A_L);
			zeroize_ADDR(ALL_LENGTH_ADDR-INST_LENGTH_ADDR-RG_A_L-BUFF_ID_A_L-LENGTH_A_L-1,fp);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",LOAD1_ADDR);
			match_BUFFER_ADDR_ADDR(instob.op[2].opd.type_BUFF.mem_b_addr,fp);
			zeroize_ADDR(ALL_LENGTH_ADDR-INST_LENGTH_ADDR-BUFFER_ADDR_A_L,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case STORE_OPCODE:
		{
			fprintf(fp,"%s",STORE0_ADDR);
			zeroize_ADDR(8,fp);
			match_BUFFER_ID_ADDR(instob.op[2].opd.type_BUFF.buff_id,fp);
			match_LENGTH_ADDR(instob.op[1].opd.length,fp,LENGTH_A_L);
			if(instob.op[0].type_flag==0)
			{
				match_BV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag==1)
			{
				match_RV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag==2)
			{
				match_RDV_ADDR(instob,0,fp);
			}
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",STORE1_ADDR);
			match_BUFFER_ADDR_ADDR(instob.op[2].opd.type_BUFF.mem_b_addr,fp);
			zeroize_ADDR(ALL_LENGTH_ADDR-INST_LENGTH_ADDR-BUFFER_ADDR_A_L,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case LAUNCH_OPCODE:
		{
			fprintf(fp,"%s",LAUNCH0_ADDR);
			match_LAYER_ADDR_ADDR(instob,0,fp);
			zeroize_ADDR(1,fp);
			match_BUFFER_ID_ADDR(instob.op[1].opd.type_BUFF.buff_id,fp);
			match_ROW_COL_ADDR(instob.op[0].opd.type_MAT.row,fp);
			zeroize_ADDR(7,fp);
			match_ROW_COL_ADDR(instob.op[0].opd.type_MAT.col,fp);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",LAUNCH1_ADDR);
			match_BUFFER_ADDR_ADDR(instob.op[1].opd.type_BUFF.mem_b_addr,fp);
			zeroize_ADDR(ALL_LENGTH_ADDR-INST_LENGTH_ADDR-BUFFER_ADDR_A_L,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case WB_OPCODE:
		{
			fprintf(fp,"%s",WB0_ADDR);
			zeroize_ADDR(8,fp);
			match_BUFFER_ID_ADDR(instob.op[1].opd.type_BUFF.buff_id,fp);
			match_ROW_COL_ADDR(instob.op[0].opd.type_MAT.row,fp);
			match_LAYER_ADDR_ADDR(instob,0,fp);
			match_ROW_COL_ADDR(instob.op[0].opd.type_MAT.col,fp);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",WB1_ADDR);
			match_BUFFER_ADDR_ADDR(instob.op[1].opd.type_BUFF.mem_b_addr,fp);
			zeroize_ADDR(ALL_LENGTH_ADDR-INST_LENGTH_ADDR-BUFFER_ADDR_A_L,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case MOV_OPCODE:
		{
			fprintf(fp,"%s",MOV_ADDR);
			if(instob.op[0].type_flag==0)
			{
				match_BV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag==1)
			{
				match_RV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag==2)
			{
				match_RDV_ADDR(instob,0,fp);
			}
			if(instob.op[1].type_flag==0)
			{
				match_BV_ADDR(instob,0,fp);
			}
			else if(instob.op[1].type_flag==1)
			{
				match_RV_ADDR(instob,0,fp);
			}
			else if(instob.op[1].type_flag==2)
			{
				match_RDV_ADDR(instob,0,fp);
			}
			zeroize_ADDR(ALL_LENGTH_ADDR-INST_LENGTH_ADDR-RG_A_L-RG_A_L,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case EXTMOV_OPCODE:
		{
			fprintf(fp,"%s",EXTMOV_ADDR);
			if(instob.op[0].type_flag==0)
			{
				match_BV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag==1)
			{
				match_RV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag==2)
			{
				match_RDV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag==7)
			{
				match_RDV_ADDR(instob,0,fp);
			}
			if(instob.op[1].type_flag==0)
			{
				match_BV_ADDR(instob,0,fp);
			}
			else if(instob.op[1].type_flag==1)
			{
				match_RV_ADDR(instob,0,fp);
			}
			else if(instob.op[1].type_flag==2)
			{
				match_RDV_ADDR(instob,0,fp);
			}
			else if(instob.op[1].type_flag==7)
			{
				match_RDV_ADDR(instob,0,fp);
			}
			zeroize_ADDR(ALL_LENGTH_ADDR-INST_LENGTH_ADDR-RG_A_L-RG_A_L,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case DMALR_OPCODE:
		{
			fprintf(fp,"%s",DMALR0_ADDR);
			char buff_b_l[MEN_ADDR_L_A_L+1];
			match_MEM_ADDR_ADDR(instob.op[0].opd.type_DMA.mem_addr,fp,buff_b_l);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",DMALR1_ADDR);
			match_BUFFER_ADDR_ADDR(instob.op[0].opd.type_DMA.buff_addr,fp);
			put_str_ADDR(buff_b_l,fp);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",DMALR2_ADDR);
			match_REPETITION_ADDR(instob.op[0].opd.type_DMA.repetition-1,fp);
			match_LENGTH_ADDR(instob.op[0].opd.type_DMA.length,fp,LENGTH_A_L);
			match_BUFFER_ID_ADDR(instob.op[0].opd.type_DMA.buff_id,fp);
			match_STRIDE_ADDR(instob.op[0].opd.type_DMA.stride,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case DMALC_OPCODE:
		{
			fprintf(fp,"%s",DMALC0_ADDR);
			char buff_b_l[MEN_ADDR_L_A_L+1];
			match_MEM_ADDR_ADDR(instob.op[0].opd.type_DMA.mem_addr,fp,buff_b_l);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",DMALC1_ADDR);
			match_BUFFER_ADDR_ADDR(instob.op[0].opd.type_DMA.buff_addr,fp);
			put_str_ADDR(buff_b_l,fp);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",DMALC2_ADDR);
			match_REPETITION_ADDR(instob.op[0].opd.type_DMA.repetition-1,fp);
			match_LENGTH_ADDR(instob.op[0].opd.type_DMA.length,fp,LENGTH_A_L);
			match_BUFFER_ID_ADDR(instob.op[0].opd.type_DMA.buff_id,fp);
			match_STRIDE_ADDR(instob.op[0].opd.type_DMA.stride,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case DMASR_OPCODE:
		{
			fprintf(fp,"%s",DMASR0_ADDR);
			char buff_b_l[MEN_ADDR_L_A_L+1];
			match_MEM_ADDR_ADDR(instob.op[0].opd.type_DMA.mem_addr,fp,buff_b_l);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",DMASR1_ADDR);
			match_BUFFER_ADDR_ADDR(instob.op[0].opd.type_DMA.buff_addr,fp);
			put_str_ADDR(buff_b_l,fp);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",DMASR2_ADDR);
			match_REPETITION_ADDR(instob.op[0].opd.type_DMA.repetition-1,fp);
			match_LENGTH_ADDR(instob.op[0].opd.type_DMA.length,fp,LENGTH_A_L);
			match_BUFFER_ID_ADDR(instob.op[0].opd.type_DMA.buff_id,fp);
			match_STRIDE_ADDR(instob.op[0].opd.type_DMA.stride,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case DMASC_OPCODE:
		{
			fprintf(fp,"%s",DMASC0_ADDR);
			char buff_b_l[MEN_ADDR_L_A_L+1];
			match_MEM_ADDR_ADDR(instob.op[0].opd.type_DMA.mem_addr,fp,buff_b_l);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",DMASC1_ADDR);
			match_BUFFER_ADDR_ADDR(instob.op[0].opd.type_DMA.buff_addr,fp);
			put_str_ADDR(buff_b_l,fp);
			linefeed_ADDR(fp);
			fprintf(fp,"%s",DMASC2_ADDR);
			match_REPETITION_ADDR(instob.op[0].opd.type_DMA.repetition-1,fp);
			match_LENGTH_ADDR(instob.op[0].opd.type_DMA.length,fp,LENGTH_A_L);
			match_BUFFER_ID_ADDR(instob.op[0].opd.type_DMA.buff_id,fp);
			match_STRIDE_ADDR(instob.op[0].opd.type_DMA.stride,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case PRODVM_OPCODE:
		{
			fprintf(fp,"%s",PRODVM_ADDR);
			match_RV_ADDR(instob,0,fp);
			if(instob.op[1].type_flag == 0)
			{
				match_BV_ADDR(instob,1,fp);
			}
			else if(instob.op[1].type_flag == 1)
			{
				match_RV_ADDR(instob,1,fp);
			}
			match_LAYER_ADDR_ADDR(instob,2,fp);
			if(instob.op[3].opd.accumul == 0)
			{
				fprintf(fp,"%c",'0');
			}
			else
			{
				fprintf(fp,"%c",'1');
			}
			zeroize_ADDR(3,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case PRODVMP_OPCODE:
		{
			fprintf(fp,"%s",PRODVMP_ADDR);
			zeroize_ADDR(7,fp);
			if(instob.op[0].type_flag == 0)
			{
				match_BV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag == 1)
			{
				match_RV_ADDR(instob,0,fp);
			}
			match_LAYER_ADDR_ADDR(instob,1,fp);
			if(instob.op[2].opd.accumul == 0)
			{
				fprintf(fp,"%c",'0');
			}
			else
			{
				fprintf(fp,"%c",'1');
			}
			zeroize_ADDR(3,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case PRODMV_OPCODE:
		{
			fprintf(fp,"%s",PRODMV_ADDR);
			match_RV_ADDR(instob,0,fp);
			if(instob.op[1].type_flag == 0)
			{
				match_BV_ADDR(instob,1,fp);
			}
			else if(instob.op[1].type_flag == 1)
			{
				match_RV_ADDR(instob,1,fp);
			}
			match_LAYER_ADDR_ADDR(instob,2,fp);
			if(instob.op[3].opd.accumul == 0)
			{
				fprintf(fp,"%c",'0');
			}
			else
			{
				fprintf(fp,"%c",'1');
			}
			zeroize_ADDR(3,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case PRODMVP_OPCODE:
		{
			fprintf(fp,"%s",PRODMVP_ADDR);
			zeroize_ADDR(7,fp);
			if(instob.op[0].type_flag == 0)
			{
				match_BV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag == 1)
			{
				match_RV_ADDR(instob,0,fp);
			}
			match_LAYER_ADDR_ADDR(instob,1,fp);
			if(instob.op[2].opd.accumul == 0)
			{
				fprintf(fp,"%c",'0');
			}
			else
			{
				fprintf(fp,"%c",'1');
			}
			zeroize_ADDR(3,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr);
			break;
		}
	case PRODVV_OPCODE:
		{
			fprintf(fp,"%s",PRODVV_ADDR);
			match_LAYER_ADDR_ADDR(instob,0,fp);
			if(instob.op[1].type_flag == 0)
			{
				match_BV_ADDR(instob,1,fp);
			}
			else if(instob.op[1].type_flag == 1)
			{
				match_RV_ADDR(instob,1,fp);
			}
			if(instob.op[2].type_flag == 0)
			{
				match_BV_ADDR(instob,2,fp);
			}
			else if(instob.op[2].type_flag == 1)
			{
				match_RV_ADDR(instob,2,fp);
			}
			if(instob.op[3].opd.accumul == 0)
			{
				fprintf(fp,"%c",'0');
			}
			else
			{
				fprintf(fp,"%c",'1');
			}
			zeroize_ADDR(3,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case PRODVVP_OPCODE:
		{
			fprintf(fp,"%s",PRODVVP_ADDR);
			zeroize_ADDR(7,fp);
			if(instob.op[0].type_flag == 0)
			{
				match_BV_ADDR(instob,0,fp);
			}
			else if(instob.op[0].type_flag == 1)
			{
				match_RV_ADDR(instob,0,fp);
			}
			if(instob.op[1].type_flag == 0)
			{
				match_BV_ADDR(instob,1,fp);
			}
			else if(instob.op[1].type_flag == 1)
			{
				match_RV_ADDR(instob,1,fp);
			}
			if(instob.op[2].opd.accumul == 0)
			{
				fprintf(fp,"%c",'0');
			}
			else
			{
				fprintf(fp,"%c",'1');
			}
			zeroize_ADDR(3,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
		case PRODVVD_OPCODE:
			{
			fprintf(fp,"%s",PRODVVD_ADDR);
			match_RV_ADDR(instob,0,fp);
			if(instob.op[1].type_flag == 0)
			{
				match_BV_ADDR(instob,1,fp);
			}
			else if(instob.op[1].type_flag == 1)
			{
				match_RV_ADDR(instob,1,fp);
			}
			if(instob.op[2].type_flag == 0)
			{
				match_BV_ADDR(instob,2,fp);
			}
			else if(instob.op[2].type_flag == 1)
			{
				match_RV_ADDR(instob,2,fp);
			}
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case DIFF_OPCODE:
		{
			fprintf(fp,"%s",DIFF_ADDR);
			match_RV_ADDR(instob,0,fp);
			match_RV_ADDR(instob,1,fp);
			zeroize_ADDR(11,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case ADDV_OPCODE:
		{
			fprintf(fp,"%s",ADDV_ADDR);
			match_RV_ADDR(instob,0,fp);
			match_RV_ADDR(instob,1,fp);
			match_RV_ADDR(instob,2,fp);
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case ADDM_OPCODE:
		{
			fprintf(fp,"%s",ADDM_ADDR);
			match_LAYER_ADDR_ADDR(instob,0,fp);
			match_LAYER_ADDR_ADDR(instob,1,fp);
			match_LAYER_ADDR_ADDR(instob,2,fp);
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case SUBV_OPCODE:
		{
			fprintf(fp,"%s",SUBV_ADDR);
			match_RV_ADDR(instob,0,fp);
			match_RV_ADDR(instob,1,fp);
			match_RV_ADDR(instob,2,fp);
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case SUBM_OPCODE:
		{
			fprintf(fp,"%s",SUBM_ADDR);
			match_LAYER_ADDR_ADDR(instob,0,fp);
			match_LAYER_ADDR_ADDR(instob,1,fp);
			match_LAYER_ADDR_ADDR(instob,2,fp);
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case MAX_OPCODE:
		{
			fprintf(fp,"%s",MAX_ADDR);
			match_RV_ADDR(instob,0,fp);
			match_RV_ADDR(instob,1,fp);
			match_RV_ADDR(instob,2,fp);
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case SCALE_OPCODE:
		{
			fprintf(fp,"%s",SCALE_ADDR);
			match_RV_ADDR(instob,0,fp);
			match_RV_ADDR(instob,1,fp);
			match_SCALE_FACTOR_ADDR(instob.op[2].opd.type_FD,fp);
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case BIAS_OPCODE:
		{
			fprintf(fp,"%s",BIAS_ADDR);
			match_RV_ADDR(instob,0,fp);
			match_RV_ADDR(instob,1,fp);
			match_BIAS_ADDR(instob.op[2].opd.type_FD,fp);
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case ACT_OPCODE:
		{
			fprintf(fp,"%s",ACT_ADDR);
			match_RV_ADDR(instob,0,fp);
			match_RV_ADDR(instob,1,fp);
			match_ACT_TYPE_ADDR(instob.op[2].opd.type_FD,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case RANDGEN_OPCODE:
		{
			fprintf(fp,"%s",RANDGEN_ADDR);
			match_RDV_ADDR(instob,0,fp);
			match_RDV_ADDR(instob,1,fp);
			match_RV_ADDR(instob,2,fp);
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	case PROBCMP_OPCODE:
		{
			fprintf(fp,"%s",PROBCMP_ADDR);
			match_BV_ADDR(instob,0,fp);
			match_RV_ADDR(instob,1,fp);
			match_RDV_ADDR(instob,2,fp);
			zeroize_ADDR(4,fp);
			linefeed_ADDR(fp);
			if(myRTLDebug)
			{
				fprintf(fp,"%s",ins[instob.ex_ins].instr); 
			}
			fprintf(fp_Ri,"%s",ins[instob.ex_ins].instr); 
			break;
		}
	default:
		{
			fprintf(fp,"%s\n","use not exit instruction");
		}
	}
	return 1;
}
