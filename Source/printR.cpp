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
 * print R
 *
 * Print the simulator register statistical data
 */

#include<stdio.h>
#include<stdlib.h>
#include"wintolinux.h"

#include "ps_pipeline.h"
#include "printR.h"

FILE *fp_rv0,*fp_rv1,*fp_rv2,*fp_rv3,*fp_rv4,*fp_rv5,*fp_rv6,*fp_rv7,*fp_rv8,*fp_rv9,*fp_rv10,*fp_rv11,*fp_rv12,*fp_rv13,*fp_rv14,*fp_rv15;
FILE *fp_rbuffer,*fp_cbuffer;

FILE *fp_Mbuffer0;
FILE *fp_Mbuffer1;
FILE *fp_Mbuffer2;
FILE *fp_Mbuffer3;
FILE *fp_Mbuffer4;
FILE *fp_Mbuffer5;
FILE *fp_Mbuffer6;
FILE *fp_Mbuffer7;
FILE *fp_Mbuffer8;
FILE *fp_Mbuffer9;
FILE *fp_Mbuffer10;
FILE *fp_Mbuffer11;
FILE *fp_Mbuffer12;
FILE *fp_Mbuffer13;
FILE *fp_Mbuffer14;
FILE *fp_Mbuffer15;

void print_RV0(int clk)
{
	fprintf(fp_rv0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[0].V[0],PRV->R_V[0].V[1],PRV->R_V[0].V[2],PRV->R_V[0].V[3],PRV->R_V[0].V[4],PRV->R_V[0].V[5],PRV->R_V[0].V[6],PRV->R_V[0].V[7],PRV->R_V[0].V[8],PRV->R_V[0].V[9],PRV->R_V[0].V[10],PRV->R_V[0].V[11],PRV->R_V[0].V[12],PRV->R_V[0].V[13],PRV->R_V[0].V[14],PRV->R_V[0].V[15]);
}

void print_RV1(int clk)
{
	fprintf(fp_rv1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[1].V[0],PRV->R_V[1].V[1],PRV->R_V[1].V[2],PRV->R_V[1].V[3],PRV->R_V[1].V[4],PRV->R_V[1].V[5],PRV->R_V[1].V[6],PRV->R_V[1].V[7],PRV->R_V[1].V[8],PRV->R_V[1].V[9],PRV->R_V[1].V[10],PRV->R_V[1].V[11],PRV->R_V[1].V[12],PRV->R_V[1].V[13],PRV->R_V[1].V[14],PRV->R_V[1].V[15]);
}

void print_RV2(int clk)
{
	fprintf(fp_rv2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[2].V[0],PRV->R_V[2].V[1],PRV->R_V[2].V[2],PRV->R_V[2].V[3],PRV->R_V[2].V[4],PRV->R_V[2].V[5],PRV->R_V[2].V[6],PRV->R_V[2].V[7],PRV->R_V[2].V[8],PRV->R_V[2].V[9],PRV->R_V[2].V[10],PRV->R_V[2].V[11],PRV->R_V[2].V[12],PRV->R_V[2].V[13],PRV->R_V[2].V[14],PRV->R_V[2].V[15]);
}

void print_RV3(int clk)
{
	fprintf(fp_rv3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[3].V[0],PRV->R_V[3].V[1],PRV->R_V[3].V[2],PRV->R_V[3].V[3],PRV->R_V[3].V[4],PRV->R_V[3].V[5],PRV->R_V[3].V[6],PRV->R_V[3].V[7],PRV->R_V[3].V[8],PRV->R_V[3].V[9],PRV->R_V[3].V[10],PRV->R_V[3].V[11],PRV->R_V[3].V[12],PRV->R_V[3].V[13],PRV->R_V[3].V[14],PRV->R_V[3].V[15]);
}

void print_RV4(int clk)
{
	fprintf(fp_rv4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[4].V[0],PRV->R_V[4].V[1],PRV->R_V[4].V[2],PRV->R_V[4].V[3],PRV->R_V[4].V[4],PRV->R_V[4].V[5],PRV->R_V[4].V[6],PRV->R_V[4].V[7],PRV->R_V[4].V[8],PRV->R_V[4].V[9],PRV->R_V[4].V[10],PRV->R_V[4].V[11],PRV->R_V[4].V[12],PRV->R_V[4].V[13],PRV->R_V[4].V[14],PRV->R_V[4].V[15]);
}

void print_RV5(int clk)
{
	fprintf(fp_rv5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[5].V[0],PRV->R_V[5].V[1],PRV->R_V[5].V[2],PRV->R_V[5].V[3],PRV->R_V[5].V[4],PRV->R_V[5].V[5],PRV->R_V[5].V[6],PRV->R_V[5].V[7],PRV->R_V[5].V[8],PRV->R_V[5].V[9],PRV->R_V[5].V[10],PRV->R_V[5].V[11],PRV->R_V[5].V[12],PRV->R_V[5].V[13],PRV->R_V[5].V[14],PRV->R_V[5].V[15]);
}

void print_RV6(int clk)
{
	fprintf(fp_rv6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[6].V[0],PRV->R_V[6].V[1],PRV->R_V[6].V[2],PRV->R_V[6].V[3],PRV->R_V[6].V[4],PRV->R_V[6].V[5],PRV->R_V[6].V[6],PRV->R_V[6].V[7],PRV->R_V[6].V[8],PRV->R_V[6].V[9],PRV->R_V[6].V[10],PRV->R_V[6].V[11],PRV->R_V[6].V[12],PRV->R_V[6].V[13],PRV->R_V[6].V[14],PRV->R_V[6].V[15]);
}

void print_RV7(int clk)
{
	fprintf(fp_rv7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[7].V[0],PRV->R_V[7].V[1],PRV->R_V[7].V[2],PRV->R_V[7].V[3],PRV->R_V[7].V[4],PRV->R_V[7].V[5],PRV->R_V[7].V[6],PRV->R_V[7].V[7],PRV->R_V[7].V[8],PRV->R_V[7].V[9],PRV->R_V[7].V[10],PRV->R_V[7].V[11],PRV->R_V[7].V[12],PRV->R_V[7].V[13],PRV->R_V[7].V[14],PRV->R_V[7].V[15]);
}

void print_RV8(int clk)
{
	fprintf(fp_rv8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[8].V[0],PRV->R_V[8].V[1],PRV->R_V[8].V[2],PRV->R_V[8].V[3],PRV->R_V[8].V[4],PRV->R_V[8].V[5],PRV->R_V[8].V[6],PRV->R_V[8].V[7],PRV->R_V[8].V[8],PRV->R_V[8].V[9],PRV->R_V[8].V[10],PRV->R_V[8].V[11],PRV->R_V[8].V[12],PRV->R_V[8].V[13],PRV->R_V[8].V[14],PRV->R_V[8].V[15]);
}

void print_RV9(int clk)
{
	fprintf(fp_rv9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[9].V[0],PRV->R_V[9].V[1],PRV->R_V[9].V[2],PRV->R_V[9].V[3],PRV->R_V[9].V[4],PRV->R_V[9].V[5],PRV->R_V[9].V[6],PRV->R_V[9].V[7],PRV->R_V[9].V[8],PRV->R_V[9].V[9],PRV->R_V[9].V[10],PRV->R_V[9].V[11],PRV->R_V[9].V[12],PRV->R_V[9].V[13],PRV->R_V[9].V[14],PRV->R_V[9].V[15]);
}

void print_RV10(int clk)
{
	fprintf(fp_rv10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[10].V[0],PRV->R_V[10].V[1],PRV->R_V[10].V[2],PRV->R_V[10].V[3],PRV->R_V[10].V[4],PRV->R_V[10].V[5],PRV->R_V[10].V[6],PRV->R_V[10].V[7],PRV->R_V[10].V[8],PRV->R_V[10].V[9],PRV->R_V[10].V[10],PRV->R_V[10].V[11],PRV->R_V[10].V[12],PRV->R_V[10].V[13],PRV->R_V[10].V[14],PRV->R_V[10].V[15]);
}

void print_RV11(int clk)
{
	fprintf(fp_rv11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[11].V[0],PRV->R_V[11].V[1],PRV->R_V[11].V[2],PRV->R_V[11].V[3],PRV->R_V[11].V[4],PRV->R_V[11].V[5],PRV->R_V[11].V[6],PRV->R_V[11].V[7],PRV->R_V[11].V[8],PRV->R_V[11].V[9],PRV->R_V[11].V[10],PRV->R_V[11].V[11],PRV->R_V[11].V[12],PRV->R_V[11].V[13],PRV->R_V[11].V[14],PRV->R_V[11].V[15]);
}

void print_RV12(int clk)
{
	fprintf(fp_rv12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[12].V[0],PRV->R_V[12].V[1],PRV->R_V[12].V[2],PRV->R_V[12].V[3],PRV->R_V[12].V[4],PRV->R_V[12].V[5],PRV->R_V[12].V[6],PRV->R_V[12].V[7],PRV->R_V[12].V[8],PRV->R_V[12].V[9],PRV->R_V[12].V[10],PRV->R_V[12].V[11],PRV->R_V[12].V[12],PRV->R_V[12].V[13],PRV->R_V[12].V[14],PRV->R_V[12].V[15]);
}

void print_RV13(int clk)
{
	fprintf(fp_rv13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[13].V[0],PRV->R_V[13].V[1],PRV->R_V[13].V[2],PRV->R_V[13].V[3],PRV->R_V[13].V[4],PRV->R_V[13].V[5],PRV->R_V[13].V[6],PRV->R_V[13].V[7],PRV->R_V[13].V[8],PRV->R_V[13].V[9],PRV->R_V[13].V[10],PRV->R_V[13].V[11],PRV->R_V[13].V[12],PRV->R_V[13].V[13],PRV->R_V[13].V[14],PRV->R_V[13].V[15]);
}

void print_RV14(int clk)
{
	fprintf(fp_rv14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[14].V[0],PRV->R_V[14].V[1],PRV->R_V[14].V[2],PRV->R_V[14].V[3],PRV->R_V[14].V[4],PRV->R_V[14].V[5],PRV->R_V[14].V[6],PRV->R_V[14].V[7],PRV->R_V[14].V[8],PRV->R_V[14].V[9],PRV->R_V[14].V[10],PRV->R_V[14].V[11],PRV->R_V[14].V[12],PRV->R_V[14].V[13],PRV->R_V[14].V[14],PRV->R_V[14].V[15]);
}

void print_RV15(int clk)
{
	fprintf(fp_rv15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PRV->R_V[15].V[0],PRV->R_V[15].V[1],PRV->R_V[15].V[2],PRV->R_V[15].V[3],PRV->R_V[15].V[4],PRV->R_V[15].V[5],PRV->R_V[15].V[6],PRV->R_V[15].V[7],PRV->R_V[15].V[8],PRV->R_V[15].V[9],PRV->R_V[15].V[10],PRV->R_V[15].V[11],PRV->R_V[15].V[12],PRV->R_V[15].V[13],PRV->R_V[15].V[14],PRV->R_V[15].V[15]);
}

void open_file_register()
{
	if(access("rv",0))
	{
		if( system("mkdir rv") !=0 )
		{
			printf(" cann't not creat rv folder.\n");
		}
	}
	fp_rv0=fopen(FILE_RV0,"w+");
	if(fp_rv0==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV0);
		exit(0);
	}
	fp_rv1=fopen(FILE_RV1,"w+");
	if(fp_rv1==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV1);
		exit(0);
	}
	fp_rv2=fopen(FILE_RV2,"w+");
	if(fp_rv2==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV2);
		exit(0);
	}
	fp_rv3=fopen(FILE_RV3,"w+");
	if(fp_rv3==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV3);
		exit(0);
	}
	fp_rv4=fopen(FILE_RV4,"w+");
	if(fp_rv4==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV4);
		exit(0);
	}
	fp_rv5=fopen(FILE_RV5,"w+");
	if(fp_rv5==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV5);
		exit(0);
	}
	fp_rv6=fopen(FILE_RV6,"w+");
	if(fp_rv6==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV6);
		exit(0);
	}
	fp_rv7=fopen(FILE_RV7,"w+");
	if(fp_rv7==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV7);
		exit(0);
	}
	fp_rv8=fopen(FILE_RV8,"w+");
	if(fp_rv8==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV8);
		exit(0);
	}
	fp_rv9=fopen(FILE_RV9,"w+");
	if(fp_rv9==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV9);
		exit(0);
	}
	fp_rv10=fopen(FILE_RV10,"w+");
	if(fp_rv10==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV10);
		exit(0);
	}
	fp_rv11=fopen(FILE_RV11,"w+");
	if(fp_rv11==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV11);
		exit(0);
	}
	fp_rv12=fopen(FILE_RV12,"w+");
	if(fp_rv12==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV12);
		exit(0);
	}
	fp_rv13=fopen(FILE_RV13,"w+");
	if(fp_rv13==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV13);
		exit(0);
	}
	fp_rv14=fopen(FILE_RV14,"w+");
	if(fp_rv14==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV14);
		exit(0);
	}
	fp_rv15=fopen(FILE_RV15,"w+");
	if(fp_rv15==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RV15);
		exit(0);
	}

	if(access("buff",0))
	{
		if(system("mkdir buff") !=0 )
		{
			printf(" cann't not creat buff folder.\n");
		}
	}
	fp_rbuffer=fopen(FILE_RBUFFER,"w+");
	if(fp_rbuffer==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_RBUFFER);
		exit(0);
	}
	fp_cbuffer=fopen(FILE_CBUFFER,"w+");
	if(fp_cbuffer==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",FILE_CBUFFER);
		exit(0);
	}

	fp_Mbuffer0=fopen(MBUFFER0,"w+");
	if(fp_Mbuffer0==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER0);
		exit(0);
	}
	fp_Mbuffer1=fopen(MBUFFER1,"w+");
	if(fp_Mbuffer1==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER1);
		exit(0);
	}
	fp_Mbuffer2=fopen(MBUFFER2,"w+");
	if(fp_Mbuffer2==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER2);
		exit(0);
	}
	fp_Mbuffer3=fopen(MBUFFER3,"w+");
	if(fp_Mbuffer3==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER3);
		exit(0);
	}
	fp_Mbuffer4=fopen(MBUFFER4,"w+");
	if(fp_Mbuffer4==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER4);
		exit(0);
	}
	fp_Mbuffer5=fopen(MBUFFER5,"w+");
	if(fp_Mbuffer5==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER5);
		exit(0);
	}
	fp_Mbuffer6=fopen(MBUFFER6,"w+");
	if(fp_Mbuffer6==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER6);
		exit(0);
	}
	fp_Mbuffer7=fopen(MBUFFER7,"w+");
	if(fp_Mbuffer7==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER7);
		exit(0);
	}
	fp_Mbuffer8=fopen(MBUFFER8,"w+");
	if(fp_Mbuffer8==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER8);
		exit(0);
	}
	fp_Mbuffer9=fopen(MBUFFER9,"w+");
	if(fp_Mbuffer9==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER9);
		exit(0);
	}
	fp_Mbuffer10=fopen(MBUFFER10,"w+");
	if(fp_Mbuffer10==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER10);
		exit(0);
	}
	fp_Mbuffer11=fopen(MBUFFER11,"w+");
	if(fp_Mbuffer11==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER11);
		exit(0);
	}
	fp_Mbuffer12=fopen(MBUFFER12,"w+");
	if(fp_Mbuffer12==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER12);
		exit(0);
	}
	fp_Mbuffer13=fopen(MBUFFER13,"w+");
	if(fp_Mbuffer13==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER13);
		exit(0);
	}
	fp_Mbuffer14=fopen(MBUFFER14,"w+");
	if(fp_Mbuffer14==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER14);
		exit(0);
	}
	fp_Mbuffer15=fopen(MBUFFER15,"w+");
	if(fp_Mbuffer15==NULL)
	{
		printf("cann't open file %s in printR.cpp \n",MBUFFER15);
		exit(0);
	}
}

void close_file_register()
{
	fclose(fp_rv0);
	fclose(fp_rv1);
	fclose(fp_rv2);
	fclose(fp_rv3);
	fclose(fp_rv4);
	fclose(fp_rv5);
	fclose(fp_rv6);
	fclose(fp_rv7);
	fclose(fp_rv8);
	fclose(fp_rv9);
	fclose(fp_rv10);
	fclose(fp_rv11);
	fclose(fp_rv12);
	fclose(fp_rv13);
	fclose(fp_rv14);
	fclose(fp_rv15);

	fclose(fp_rbuffer);
	fclose(fp_cbuffer);

	fclose(fp_Mbuffer0);
	fclose(fp_Mbuffer1);
	fclose(fp_Mbuffer2);
	fclose(fp_Mbuffer3);
	fclose(fp_Mbuffer4);
	fclose(fp_Mbuffer5);
	fclose(fp_Mbuffer6);
	fclose(fp_Mbuffer7);
	fclose(fp_Mbuffer8);
	fclose(fp_Mbuffer9);
	fclose(fp_Mbuffer10);
	fclose(fp_Mbuffer11);
	fclose(fp_Mbuffer12);
	fclose(fp_Mbuffer13);
	fclose(fp_Mbuffer14);
	fclose(fp_Mbuffer15);
}

void print_RBUFFER(int)
{
	fprintf(fp_rbuffer,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",Rbuffer.V[0],Rbuffer.V[1],Rbuffer.V[2],Rbuffer.V[3],Rbuffer.V[4],Rbuffer.V[5],Rbuffer.V[6],Rbuffer.V[7],Rbuffer.V[8],Rbuffer.V[9],Rbuffer.V[10],Rbuffer.V[11],Rbuffer.V[12],Rbuffer.V[13],Rbuffer.V[14],Rbuffer.V[15]);
}

void print_CBUFFER(int)
{
	fprintf(fp_cbuffer,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",Cbuffer.V[0],Cbuffer.V[1],Cbuffer.V[2],Cbuffer.V[3],Cbuffer.V[4],Cbuffer.V[5],Cbuffer.V[6],Cbuffer.V[7],Cbuffer.V[8],Cbuffer.V[9],Cbuffer.V[10],Cbuffer.V[11],Cbuffer.V[12],Cbuffer.V[13],Cbuffer.V[14],Cbuffer.V[15]);
}

void print_MBUFFER0()
{
	fprintf(fp_Mbuffer0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[0][0],PMbuffer.V[0][1],PMbuffer.V[0][2],PMbuffer.V[0][3],PMbuffer.V[0][4],PMbuffer.V[0][5],PMbuffer.V[0][6],PMbuffer.V[0][7],PMbuffer.V[0][8],PMbuffer.V[0][9],PMbuffer.V[0][10],PMbuffer.V[0][11],PMbuffer.V[0][12],PMbuffer.V[0][13],PMbuffer.V[0][14],PMbuffer.V[0][15]);

}
void print_MBUFFER1()
{
	fprintf(fp_Mbuffer1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[1][0],PMbuffer.V[1][1],PMbuffer.V[1][2],PMbuffer.V[1][3],PMbuffer.V[1][4],PMbuffer.V[1][5],PMbuffer.V[1][6],PMbuffer.V[1][7],PMbuffer.V[1][8],PMbuffer.V[1][9],PMbuffer.V[1][10],PMbuffer.V[1][11],PMbuffer.V[1][12],PMbuffer.V[1][13],PMbuffer.V[1][14],PMbuffer.V[1][15]);

}
void print_MBUFFER2()
{
	fprintf(fp_Mbuffer2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[2][0],PMbuffer.V[2][1],PMbuffer.V[2][2],PMbuffer.V[2][3],PMbuffer.V[2][4],PMbuffer.V[2][5],PMbuffer.V[2][6],PMbuffer.V[2][7],PMbuffer.V[2][8],PMbuffer.V[2][9],PMbuffer.V[2][10],PMbuffer.V[2][11],PMbuffer.V[2][12],PMbuffer.V[2][13],PMbuffer.V[2][14],PMbuffer.V[2][15]);

}
void print_MBUFFER3()
{
	fprintf(fp_Mbuffer3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[3][0],PMbuffer.V[3][1],PMbuffer.V[3][2],PMbuffer.V[3][3],PMbuffer.V[3][4],PMbuffer.V[3][5],PMbuffer.V[3][6],PMbuffer.V[3][7],PMbuffer.V[3][8],PMbuffer.V[3][9],PMbuffer.V[3][10],PMbuffer.V[3][11],PMbuffer.V[3][12],PMbuffer.V[3][13],PMbuffer.V[3][14],PMbuffer.V[3][15]);

}
void print_MBUFFER4()
{
	fprintf(fp_Mbuffer4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[4][0],PMbuffer.V[4][1],PMbuffer.V[4][2],PMbuffer.V[4][3],PMbuffer.V[4][4],PMbuffer.V[4][5],PMbuffer.V[4][6],PMbuffer.V[4][7],PMbuffer.V[4][8],PMbuffer.V[4][9],PMbuffer.V[4][10],PMbuffer.V[4][11],PMbuffer.V[4][12],PMbuffer.V[4][13],PMbuffer.V[4][14],PMbuffer.V[4][15]);

}
void print_MBUFFER5()
{
	fprintf(fp_Mbuffer5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[5][0],PMbuffer.V[5][1],PMbuffer.V[5][2],PMbuffer.V[5][3],PMbuffer.V[5][4],PMbuffer.V[5][5],PMbuffer.V[5][6],PMbuffer.V[5][7],PMbuffer.V[5][8],PMbuffer.V[5][9],PMbuffer.V[5][10],PMbuffer.V[5][11],PMbuffer.V[5][12],PMbuffer.V[5][13],PMbuffer.V[5][14],PMbuffer.V[5][15]);

}
void print_MBUFFER6()
{
	fprintf(fp_Mbuffer6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[6][0],PMbuffer.V[6][1],PMbuffer.V[6][2],PMbuffer.V[6][3],PMbuffer.V[6][4],PMbuffer.V[6][5],PMbuffer.V[6][6],PMbuffer.V[6][7],PMbuffer.V[6][8],PMbuffer.V[6][9],PMbuffer.V[6][10],PMbuffer.V[6][11],PMbuffer.V[6][12],PMbuffer.V[6][13],PMbuffer.V[6][14],PMbuffer.V[6][15]);

}
void print_MBUFFER7()
{
	fprintf(fp_Mbuffer7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[7][0],PMbuffer.V[7][1],PMbuffer.V[7][2],PMbuffer.V[7][3],PMbuffer.V[7][4],PMbuffer.V[7][5],PMbuffer.V[7][6],PMbuffer.V[7][7],PMbuffer.V[7][8],PMbuffer.V[7][9],PMbuffer.V[7][10],PMbuffer.V[7][11],PMbuffer.V[7][12],PMbuffer.V[7][13],PMbuffer.V[7][14],PMbuffer.V[7][15]);

}
void print_MBUFFER8()
{
	fprintf(fp_Mbuffer8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[8][0],PMbuffer.V[8][1],PMbuffer.V[8][2],PMbuffer.V[8][3],PMbuffer.V[8][4],PMbuffer.V[8][5],PMbuffer.V[8][6],PMbuffer.V[8][7],PMbuffer.V[8][8],PMbuffer.V[8][9],PMbuffer.V[8][10],PMbuffer.V[8][11],PMbuffer.V[8][12],PMbuffer.V[8][13],PMbuffer.V[8][14],PMbuffer.V[8][15]);

}
void print_MBUFFER9()
{
	fprintf(fp_Mbuffer9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[9][0],PMbuffer.V[9][1],PMbuffer.V[9][2],PMbuffer.V[9][3],PMbuffer.V[9][4],PMbuffer.V[9][5],PMbuffer.V[9][6],PMbuffer.V[9][7],PMbuffer.V[9][8],PMbuffer.V[9][9],PMbuffer.V[9][10],PMbuffer.V[9][11],PMbuffer.V[9][12],PMbuffer.V[9][13],PMbuffer.V[9][14],PMbuffer.V[9][15]);

}
void print_MBUFFER10()
{
	fprintf(fp_Mbuffer10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[10][0],PMbuffer.V[10][1],PMbuffer.V[10][2],PMbuffer.V[10][3],PMbuffer.V[10][4],PMbuffer.V[10][5],PMbuffer.V[10][6],PMbuffer.V[10][7],PMbuffer.V[10][8],PMbuffer.V[10][9],PMbuffer.V[10][10],PMbuffer.V[10][11],PMbuffer.V[10][12],PMbuffer.V[10][13],PMbuffer.V[10][14],PMbuffer.V[10][15]);

}
void print_MBUFFER11()
{
	fprintf(fp_Mbuffer11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[11][0],PMbuffer.V[11][1],PMbuffer.V[11][2],PMbuffer.V[11][3],PMbuffer.V[11][4],PMbuffer.V[11][5],PMbuffer.V[11][6],PMbuffer.V[11][7],PMbuffer.V[11][8],PMbuffer.V[11][9],PMbuffer.V[11][10],PMbuffer.V[11][11],PMbuffer.V[11][12],PMbuffer.V[11][13],PMbuffer.V[11][14],PMbuffer.V[11][15]);

}
void print_MBUFFER12()
{
	fprintf(fp_Mbuffer12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[12][0],PMbuffer.V[12][1],PMbuffer.V[12][2],PMbuffer.V[12][3],PMbuffer.V[12][4],PMbuffer.V[12][5],PMbuffer.V[12][6],PMbuffer.V[12][7],PMbuffer.V[12][8],PMbuffer.V[12][9],PMbuffer.V[12][10],PMbuffer.V[12][11],PMbuffer.V[12][12],PMbuffer.V[12][13],PMbuffer.V[12][14],PMbuffer.V[12][15]);

}
void print_MBUFFER13()
{
	fprintf(fp_Mbuffer13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[13][0],PMbuffer.V[13][1],PMbuffer.V[13][2],PMbuffer.V[13][3],PMbuffer.V[13][4],PMbuffer.V[13][5],PMbuffer.V[13][6],PMbuffer.V[13][7],PMbuffer.V[13][8],PMbuffer.V[13][9],PMbuffer.V[13][10],PMbuffer.V[13][11],PMbuffer.V[13][12],PMbuffer.V[13][13],PMbuffer.V[13][14],PMbuffer.V[13][15]);

}
void print_MBUFFER14()
{
	fprintf(fp_Mbuffer14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[14][0],PMbuffer.V[14][1],PMbuffer.V[14][2],PMbuffer.V[14][3],PMbuffer.V[14][4],PMbuffer.V[14][5],PMbuffer.V[14][6],PMbuffer.V[14][7],PMbuffer.V[14][8],PMbuffer.V[14][9],PMbuffer.V[14][10],PMbuffer.V[14][11],PMbuffer.V[14][12],PMbuffer.V[14][13],PMbuffer.V[14][14],PMbuffer.V[14][15]);

}
void print_MBUFFER15()
{
	fprintf(fp_Mbuffer15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMbuffer.V[15][0],PMbuffer.V[15][1],PMbuffer.V[15][2],PMbuffer.V[15][3],PMbuffer.V[15][4],PMbuffer.V[15][5],PMbuffer.V[15][6],PMbuffer.V[15][7],PMbuffer.V[15][8],PMbuffer.V[15][9],PMbuffer.V[15][10],PMbuffer.V[15][11],PMbuffer.V[15][12],PMbuffer.V[15][13],PMbuffer.V[15][14],PMbuffer.V[15][15]);

}

void print_all_register(int clk)
{
	print_RV0(clk);
	print_RV1(clk);
	print_RV2(clk);
	print_RV3(clk);
	print_RV4(clk);
	print_RV5(clk);
	print_RV6(clk);
	print_RV7(clk);
	print_RV8(clk);
	print_RV9(clk);
	print_RV10(clk);
	print_RV11(clk);
	print_RV12(clk);
	print_RV13(clk);
	print_RV14(clk);
	print_RV15(clk);

	print_RBUFFER(clk);
	print_CBUFFER(clk);

	print_MBUFFER0();
	print_MBUFFER1();
	print_MBUFFER2();
	print_MBUFFER3();
	print_MBUFFER4();
	print_MBUFFER5();
	print_MBUFFER6();
	print_MBUFFER7();
	print_MBUFFER8();
	print_MBUFFER9();
	print_MBUFFER10();
	print_MBUFFER11();
	print_MBUFFER12();
	print_MBUFFER13();
	print_MBUFFER14();
	print_MBUFFER15();
}

void zeroize_print_all_register(int num_zore)
{
	int i_count_print_rv;
	for(i_count_print_rv=0;i_count_print_rv<num_zore;i_count_print_rv++)
	{
		fprintf(fp_rv0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rv15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_rbuffer,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_cbuffer,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
		fprintf(fp_Mbuffer15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	}


}
