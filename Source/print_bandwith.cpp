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
 * print bandwith
 *
 * Print the simulator bandwith statistical data
 */

#include<stdio.h>
#include<stdlib.h>
#include"wintolinux.h"
#include<string.h>

#include "print_bandwith.h"
#include "bandwith_monitor.h"

FILE *fp_all_rv_in_bw;
FILE *fp_all_rv_out_bw;

FILE *fp_rv0_in_bw;
FILE *fp_rv1_in_bw;
FILE *fp_rv2_in_bw;
FILE *fp_rv3_in_bw;
FILE *fp_rv4_in_bw;
FILE *fp_rv5_in_bw;
FILE *fp_rv6_in_bw;
FILE *fp_rv7_in_bw;
FILE *fp_rv8_in_bw;
FILE *fp_rv9_in_bw;
FILE *fp_rv10_in_bw;
FILE *fp_rv11_in_bw;
FILE *fp_rv12_in_bw;
FILE *fp_rv13_in_bw;
FILE *fp_rv14_in_bw;
FILE *fp_rv15_in_bw;

FILE *fp_rv0_out_bw;
FILE *fp_rv1_out_bw;
FILE *fp_rv2_out_bw;
FILE *fp_rv3_out_bw;
FILE *fp_rv4_out_bw;
FILE *fp_rv5_out_bw;
FILE *fp_rv6_out_bw;
FILE *fp_rv7_out_bw;
FILE *fp_rv8_out_bw;
FILE *fp_rv9_out_bw;
FILE *fp_rv10_out_bw;
FILE *fp_rv11_out_bw;
FILE *fp_rv12_out_bw;
FILE *fp_rv13_out_bw;
FILE *fp_rv14_out_bw;
FILE *fp_rv15_out_bw;

FILE *fp_all_bv_in_bw;
FILE *fp_all_bv_out_bw;

FILE *fp_bv0_in_bw;
FILE *fp_bv1_in_bw;
FILE *fp_bv2_in_bw;
FILE *fp_bv3_in_bw;

FILE *fp_bv0_out_bw;
FILE *fp_bv1_out_bw;
FILE *fp_bv2_out_bw;
FILE *fp_bv3_out_bw;

FILE *fp_all_rdv_in_bw;
FILE *fp_all_rdv_out_bw;

FILE *fp_rdv0_in_bw;
FILE *fp_rdv1_in_bw;
FILE *fp_rdv2_in_bw;
FILE *fp_rdv3_in_bw;

FILE *fp_rdv0_out_bw;
FILE *fp_rdv1_out_bw;
FILE *fp_rdv2_out_bw;
FILE *fp_rdv3_out_bw;

FILE *fp_all_extv_in_bw;
FILE *fp_all_extv_out_bw;

FILE *fp_extv0_in_bw;
FILE *fp_extv1_in_bw;
FILE *fp_extv2_in_bw;
FILE *fp_extv3_in_bw;
FILE *fp_extv4_in_bw;
FILE *fp_extv5_in_bw;
FILE *fp_extv6_in_bw;
FILE *fp_extv7_in_bw;

FILE *fp_extv0_out_bw;
FILE *fp_extv1_out_bw;
FILE *fp_extv2_out_bw;
FILE *fp_extv3_out_bw;
FILE *fp_extv4_out_bw;
FILE *fp_extv5_out_bw;
FILE *fp_extv6_out_bw;
FILE *fp_extv7_out_bw;

FILE *fp_all_mat_in_bw;
FILE *fp_all_mat_out_bw;

FILE *fp_mat0_in_bw;
FILE *fp_mat1_in_bw;
FILE *fp_mat2_in_bw;
FILE *fp_mat3_in_bw;
FILE *fp_mat4_in_bw;
FILE *fp_mat5_in_bw;
FILE *fp_mat6_in_bw;
FILE *fp_mat7_in_bw;

FILE *fp_mat0_out_bw;
FILE *fp_mat1_out_bw;
FILE *fp_mat2_out_bw;
FILE *fp_mat3_out_bw;
FILE *fp_mat4_out_bw;
FILE *fp_mat5_out_bw;
FILE *fp_mat6_out_bw;
FILE *fp_mat7_out_bw;

FILE *fp_rbuffer_in_bw;
FILE *fp_cbuffer_in_bw;
FILE *fp_mbuffer_in_bw;
FILE *fp_buffer0_in_bw;
FILE *fp_buffer1_in_bw;
FILE *fp_buffer2_in_bw;

FILE *fp_rbuffer_out_bw;
FILE *fp_cbuffer_out_bw;
FILE *fp_mbuffer_out_bw;
FILE *fp_buffer0_out_bw;
FILE *fp_buffer1_out_bw;
FILE *fp_buffer2_out_bw;

FILE *fp_add_num;
FILE *fp_mul_num;

FILE *fp_mem_in_bw;
FILE *fp_mem_out_bw;

/* 创建bandwith需要的文件夹 */
void create_bw_floder()
{
	if(access("bandwith\\rv_bw",0))
	{
		if( system("mkdir bandwith\\rv_bw") !=0 )
		{
			printf(" cann't not creat bandwith\\rv_bw folder.\n");
			exit(0);
		}
	}
	if(access("bandwith\\bv_bw",0))
	{
		if( system("mkdir bandwith\\bv_bw") !=0 )
		{
			printf(" cann't not creat bandwith\\bv_bw folder.\n");
			exit(0);
		}
	}
	if(access("bandwith\\rdv_bw",0))
	{
		if( system("mkdir bandwith\\rdv_bw") !=0 )
		{
			printf(" cann't not creat bandwith\\rdv_bw folder.\n");
			exit(0);
		}
	}
	if(access("bandwith\\extv_bw",0))
	{
		if( system("mkdir bandwith\\extv_bw") !=0 )
		{
			printf(" cann't not creat bandwith\\extv_bw folder.\n");
			exit(0);
		}
	}
	if(access("bandwith\\mat_bw",0))
	{
		if( system("mkdir bandwith\\mat_bw") !=0 )
		{
			printf(" cann't not creat bandwith\\mat_bw folder.\n");
			exit(0);
		}
	}
	if(access("bandwith\\buffer_bw",0))
	{
		if( system("mkdir bandwith\\buffer_bw") !=0 )
		{
			printf(" cann't not creat bandwith\\buffer_bw folder.\n");
			exit(0);
		}
	}
	if(access("bandwith\\arithmetic_num",0))
	{
		if( system("mkdir bandwith\\arithmetic_num") !=0 )
		{
			printf(" cann't not creat bandwith\\arithmetic_num folder.\n");
			exit(0);
		}
	}

	if(access("bandwith\\mem_bw",0))
	{
		if( system("mkdir bandwith\\mem_bw") !=0 )
		{
			printf(" cann't not creat bandwith\\mem_bw folder.\n");
			exit(0);
		}
	}
}

void open_file_bw()
{
	create_bw_floder();

	errno_t err;

	if((err=fopen_s(&fp_all_rv_in_bw,ALL_RV_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",ALL_RV_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_all_rv_out_bw,ALL_RV_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",ALL_RV_OUT_BANDWITH,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_rv0_in_bw,RV_IN_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv1_in_bw,RV_IN_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv2_in_bw,RV_IN_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv3_in_bw,RV_IN_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv4_in_bw,RV_IN_BANDWITH4,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH4,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv5_in_bw,RV_IN_BANDWITH5,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH5,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv6_in_bw,RV_IN_BANDWITH6,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH6,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv7_in_bw,RV_IN_BANDWITH7,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH7,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv8_in_bw,RV_IN_BANDWITH8,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH8,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv9_in_bw,RV_IN_BANDWITH9,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH9,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv10_in_bw,RV_IN_BANDWITH10,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH10,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv11_in_bw,RV_IN_BANDWITH11,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH11,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv12_in_bw,RV_IN_BANDWITH12,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH12,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv13_in_bw,RV_IN_BANDWITH13,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH13,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv14_in_bw,RV_IN_BANDWITH14,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH14,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv15_in_bw,RV_IN_BANDWITH15,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_IN_BANDWITH15,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_rv0_out_bw,RV_OUT_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv1_out_bw,RV_OUT_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv2_out_bw,RV_OUT_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv3_out_bw,RV_OUT_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv4_out_bw,RV_OUT_BANDWITH4,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH4,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv5_out_bw,RV_OUT_BANDWITH5,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH5,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv6_out_bw,RV_OUT_BANDWITH6,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH6,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv7_out_bw,RV_OUT_BANDWITH7,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH7,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv8_out_bw,RV_OUT_BANDWITH8,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH8,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv9_out_bw,RV_OUT_BANDWITH9,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH9,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv10_out_bw,RV_OUT_BANDWITH10,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH10,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv11_out_bw,RV_OUT_BANDWITH11,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH11,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv12_out_bw,RV_OUT_BANDWITH12,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH12,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv13_out_bw,RV_OUT_BANDWITH13,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH13,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv14_out_bw,RV_OUT_BANDWITH14,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH14,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rv15_out_bw,RV_OUT_BANDWITH15,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RV_OUT_BANDWITH15,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_all_bv_in_bw,ALL_BV_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n ",ALL_BV_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_all_bv_out_bw,ALL_BV_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n ",ALL_BV_OUT_BANDWITH,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_bv0_in_bw,BV_IN_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BV_IN_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_bv1_in_bw,BV_IN_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BV_IN_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_bv2_in_bw,BV_IN_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BV_IN_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_bv3_in_bw,BV_IN_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BV_IN_BANDWITH3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_bv0_out_bw,BV_OUT_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BV_OUT_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_bv1_out_bw,BV_OUT_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BV_OUT_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_bv2_out_bw,BV_OUT_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BV_OUT_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_bv3_out_bw,BV_OUT_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BV_OUT_BANDWITH3,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_all_rdv_in_bw,ALL_RDV_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n ",ALL_RDV_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_all_rdv_out_bw,ALL_RDV_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n ",ALL_RDV_OUT_BANDWITH,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_rdv0_in_bw,RDV_IN_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RDV_IN_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rdv1_in_bw,RDV_IN_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RDV_IN_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rdv2_in_bw,RDV_IN_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RDV_IN_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rdv3_in_bw,RDV_IN_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RDV_IN_BANDWITH3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rdv0_out_bw,RDV_OUT_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RDV_OUT_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rdv1_out_bw,RDV_OUT_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RDV_OUT_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rdv2_out_bw,RDV_OUT_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RDV_OUT_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rdv3_out_bw,RDV_OUT_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RDV_OUT_BANDWITH3,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_all_extv_in_bw,ALL_EXTV_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",ALL_EXTV_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_all_extv_out_bw,ALL_EXTV_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",ALL_EXTV_OUT_BANDWITH,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_extv0_in_bw,EXTV_IN_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_IN_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv1_in_bw,EXTV_IN_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_IN_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv2_in_bw,EXTV_IN_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_IN_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv3_in_bw,EXTV_IN_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_IN_BANDWITH3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv4_in_bw,EXTV_IN_BANDWITH4,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_IN_BANDWITH4,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv5_in_bw,EXTV_IN_BANDWITH5,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_IN_BANDWITH5,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv6_in_bw,EXTV_IN_BANDWITH6,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_IN_BANDWITH6,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv7_in_bw,EXTV_IN_BANDWITH7,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_IN_BANDWITH7,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv0_out_bw,EXTV_OUT_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_OUT_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv1_out_bw,EXTV_OUT_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_OUT_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv2_out_bw,EXTV_OUT_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_OUT_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv3_out_bw,EXTV_OUT_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_OUT_BANDWITH3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv4_out_bw,EXTV_OUT_BANDWITH4,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_OUT_BANDWITH4,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv5_out_bw,EXTV_OUT_BANDWITH5,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_OUT_BANDWITH5,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv6_out_bw,EXTV_OUT_BANDWITH6,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_OUT_BANDWITH6,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_extv7_out_bw,EXTV_OUT_BANDWITH7,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",EXTV_OUT_BANDWITH7,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_all_mat_in_bw,ALL_MAT_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n\n",ALL_MAT_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_all_mat_out_bw,ALL_MAT_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n\n",ALL_MAT_OUT_BANDWITH,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_mat0_in_bw,MAT_IN_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_IN_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat1_in_bw,MAT_IN_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_IN_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat2_in_bw,MAT_IN_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_IN_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat3_in_bw,MAT_IN_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_IN_BANDWITH3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat4_in_bw,MAT_IN_BANDWITH4,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_IN_BANDWITH4,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat5_in_bw,MAT_IN_BANDWITH5,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_IN_BANDWITH5,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat6_in_bw,MAT_IN_BANDWITH6,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_IN_BANDWITH6,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat7_in_bw,MAT_IN_BANDWITH7,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_IN_BANDWITH7,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat0_out_bw,MAT_OUT_BANDWITH0,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_OUT_BANDWITH0,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat1_out_bw,MAT_OUT_BANDWITH1,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_OUT_BANDWITH1,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat2_out_bw,MAT_OUT_BANDWITH2,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_OUT_BANDWITH2,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat3_out_bw,MAT_OUT_BANDWITH3,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_OUT_BANDWITH3,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat4_out_bw,MAT_OUT_BANDWITH4,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_OUT_BANDWITH4,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat5_out_bw,MAT_OUT_BANDWITH5,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_OUT_BANDWITH5,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat6_out_bw,MAT_OUT_BANDWITH6,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_OUT_BANDWITH6,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mat7_out_bw,MAT_OUT_BANDWITH7,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MAT_OUT_BANDWITH7,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_rbuffer_in_bw,RBUFFER_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RBUFFER_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_cbuffer_in_bw,CBUFFER_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",CBUFFER_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mbuffer_in_bw,MBUFFER_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MBUFFER_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_buffer0_in_bw,BUFFER0_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BUFFER0_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_buffer1_in_bw,BUFFER1_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BUFFER1_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_buffer2_in_bw,BUFFER2_IN_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BUFFER2_IN_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_rbuffer_out_bw,RBUFFER_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",RBUFFER_OUT_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_cbuffer_out_bw,CBUFFER_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",CBUFFER_OUT_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mbuffer_out_bw,MBUFFER_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MBUFFER_OUT_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_buffer0_out_bw,BUFFER0_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BUFFER0_OUT_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_buffer1_out_bw,BUFFER1_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BUFFER1_OUT_BANDWITH,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_buffer2_out_bw,BUFFER2_OUT_BANDWITH,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",BUFFER2_OUT_BANDWITH,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_add_num,ADD_OP_NUM,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",ADD_OP_NUM,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mul_num,MUL_OP_NUM,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MUL_OP_NUM,strerror(err));
		exit(0);
	}

	if((err=fopen_s(&fp_mem_in_bw,MEM_IN_BANDWITH_FILE,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MEM_IN_BANDWITH_FILE,strerror(err));
		exit(0);
	}
	if((err=fopen_s(&fp_mem_out_bw,MEM_OUT_BANDWITH_FILE,"w+"))!=0)
	{
		printf("can not open %s file in print_bandwith.cpp.erron:%s\n",MEM_OUT_BANDWITH_FILE,strerror(err));
		exit(0);
	}
}

void close_file_bw()
{
	fclose(fp_all_rv_in_bw);
	fclose(fp_all_rv_out_bw);

	fclose(fp_rv0_in_bw);
	fclose(fp_rv0_out_bw);
	fclose(fp_rv1_in_bw);
	fclose(fp_rv1_out_bw);
	fclose(fp_rv2_in_bw);
	fclose(fp_rv2_out_bw);
	fclose(fp_rv3_in_bw);
	fclose(fp_rv3_out_bw);
	fclose(fp_rv4_in_bw);
	fclose(fp_rv4_out_bw);
	fclose(fp_rv5_in_bw);
	fclose(fp_rv5_out_bw);
	fclose(fp_rv6_in_bw);
	fclose(fp_rv6_out_bw);
	fclose(fp_rv7_in_bw);
	fclose(fp_rv7_out_bw);
	fclose(fp_rv8_in_bw);
	fclose(fp_rv8_out_bw);
	fclose(fp_rv9_in_bw);
	fclose(fp_rv9_out_bw);
	fclose(fp_rv10_in_bw);
	fclose(fp_rv10_out_bw);
	fclose(fp_rv11_in_bw);
	fclose(fp_rv11_out_bw);
	fclose(fp_rv12_in_bw);
	fclose(fp_rv12_out_bw);
	fclose(fp_rv13_in_bw);
	fclose(fp_rv13_out_bw);
	fclose(fp_rv14_in_bw);
	fclose(fp_rv14_out_bw);
	fclose(fp_rv15_in_bw);
	fclose(fp_rv15_out_bw);

	fclose(fp_all_bv_in_bw);
	fclose(fp_all_bv_out_bw);

	fclose(fp_bv0_in_bw);
	fclose(fp_bv0_out_bw);
	fclose(fp_bv1_in_bw);
	fclose(fp_bv1_out_bw);
	fclose(fp_bv2_in_bw);
	fclose(fp_bv2_out_bw);
	fclose(fp_bv3_in_bw);
	fclose(fp_bv3_out_bw);

	fclose(fp_all_rdv_in_bw);
	fclose(fp_all_rdv_out_bw);

	fclose(fp_rdv0_in_bw);
	fclose(fp_rdv0_out_bw);
	fclose(fp_rdv1_in_bw);
	fclose(fp_rdv1_out_bw);
	fclose(fp_rdv2_in_bw);
	fclose(fp_rdv2_out_bw);
	fclose(fp_rdv3_in_bw);
	fclose(fp_rdv3_out_bw);

	fclose(fp_all_extv_in_bw);
	fclose(fp_all_extv_out_bw);

	fclose(fp_extv0_in_bw);
	fclose(fp_extv0_out_bw);
	fclose(fp_extv1_in_bw);
	fclose(fp_extv1_out_bw);
	fclose(fp_extv2_in_bw);
	fclose(fp_extv2_out_bw);
	fclose(fp_extv3_in_bw);
	fclose(fp_extv3_out_bw);
	fclose(fp_extv4_in_bw);
	fclose(fp_extv4_out_bw);
	fclose(fp_extv5_in_bw);
	fclose(fp_extv5_out_bw);
	fclose(fp_extv6_in_bw);
	fclose(fp_extv6_out_bw);
	fclose(fp_extv7_in_bw);
	fclose(fp_extv7_out_bw);

	fclose(fp_all_mat_in_bw);
	fclose(fp_all_mat_out_bw);

	fclose(fp_mat0_in_bw);
	fclose(fp_mat0_out_bw);
	fclose(fp_mat1_in_bw);
	fclose(fp_mat1_out_bw);
	fclose(fp_mat2_in_bw);
	fclose(fp_mat2_out_bw);
	fclose(fp_mat3_in_bw);
	fclose(fp_mat3_out_bw);
	fclose(fp_mat4_in_bw);
	fclose(fp_mat4_out_bw);
	fclose(fp_mat5_in_bw);
	fclose(fp_mat5_out_bw);
	fclose(fp_mat6_in_bw);
	fclose(fp_mat6_out_bw);
	fclose(fp_mat7_in_bw);
	fclose(fp_mat7_out_bw);

	fclose(fp_rbuffer_in_bw);
	fclose(fp_rbuffer_out_bw);
	fclose(fp_cbuffer_in_bw);
	fclose(fp_cbuffer_out_bw);
	fclose(fp_mbuffer_out_bw);
	fclose(fp_mbuffer_in_bw);
	fclose(fp_buffer0_in_bw);
	fclose(fp_buffer0_out_bw);
	fclose(fp_buffer1_in_bw);
	fclose(fp_buffer1_out_bw);
	fclose(fp_buffer2_in_bw);
	fclose(fp_buffer2_out_bw);

	fclose(fp_add_num);
	fclose(fp_mul_num);

	fclose(fp_mem_in_bw);
	fclose(fp_mem_out_bw);
}

void print_procedure_bw()
{
	bw_sub_temp_save();
	long temp_bandwith=0;
	int i;
	for(i=0;i<RG_NUM;i++)
	{
		temp_bandwith+=RV_in_bandwith[i];
	}
	fprintf(fp_all_rv_in_bw,"%ld\n",temp_bandwith);
	fprintf(fp_rv0_in_bw,"%ld\n",RV_in_bandwith[0]);
	fprintf(fp_rv1_in_bw,"%ld\n",RV_in_bandwith[1]);
	fprintf(fp_rv2_in_bw,"%ld\n",RV_in_bandwith[2]);
	fprintf(fp_rv3_in_bw,"%ld\n",RV_in_bandwith[3]);
	fprintf(fp_rv4_in_bw,"%ld\n",RV_in_bandwith[4]);
	fprintf(fp_rv5_in_bw,"%ld\n",RV_in_bandwith[5]);
	fprintf(fp_rv6_in_bw,"%ld\n",RV_in_bandwith[6]);
	fprintf(fp_rv7_in_bw,"%ld\n",RV_in_bandwith[7]);
	fprintf(fp_rv8_in_bw,"%ld\n",RV_in_bandwith[8]);
	fprintf(fp_rv9_in_bw,"%ld\n",RV_in_bandwith[9]);
	fprintf(fp_rv10_in_bw,"%ld\n",RV_in_bandwith[10]);
	fprintf(fp_rv11_in_bw,"%ld\n",RV_in_bandwith[11]);
	fprintf(fp_rv12_in_bw,"%ld\n",RV_in_bandwith[12]);
	fprintf(fp_rv13_in_bw,"%ld\n",RV_in_bandwith[13]);
	fprintf(fp_rv14_in_bw,"%ld\n",RV_in_bandwith[14]);
	fprintf(fp_rv15_in_bw,"%ld\n",RV_in_bandwith[15]);

	temp_bandwith=0;
	for(i=0;i<RG_NUM;i++)
	{
		temp_bandwith+=RV_out_bandwith[i];
	}
	fprintf(fp_all_rv_out_bw,"%ld\n",temp_bandwith);
	fprintf(fp_rv0_out_bw,"%ld\n",RV_out_bandwith[0]);
	fprintf(fp_rv1_out_bw,"%ld\n",RV_out_bandwith[1]);
	fprintf(fp_rv2_out_bw,"%ld\n",RV_out_bandwith[2]);
	fprintf(fp_rv3_out_bw,"%ld\n",RV_out_bandwith[3]);
	fprintf(fp_rv4_out_bw,"%ld\n",RV_out_bandwith[4]);
	fprintf(fp_rv5_out_bw,"%ld\n",RV_out_bandwith[5]);
	fprintf(fp_rv6_out_bw,"%ld\n",RV_out_bandwith[6]);
	fprintf(fp_rv7_out_bw,"%ld\n",RV_out_bandwith[7]);
	fprintf(fp_rv8_out_bw,"%ld\n",RV_out_bandwith[8]);
	fprintf(fp_rv9_out_bw,"%ld\n",RV_out_bandwith[9]);
	fprintf(fp_rv10_out_bw,"%ld\n",RV_out_bandwith[10]);
	fprintf(fp_rv11_out_bw,"%ld\n",RV_out_bandwith[11]);
	fprintf(fp_rv12_out_bw,"%ld\n",RV_out_bandwith[12]);
	fprintf(fp_rv13_out_bw,"%ld\n",RV_out_bandwith[13]);
	fprintf(fp_rv14_out_bw,"%ld\n",RV_out_bandwith[14]);
	fprintf(fp_rv15_out_bw,"%ld\n",RV_out_bandwith[15]);

	temp_bandwith=0;
	for(i=0;i<BV_NUM;i++)
	{
		temp_bandwith+=BV_in_bandwith[i];
	}
	fprintf(fp_all_bv_in_bw,"%ld\n",temp_bandwith);
	fprintf(fp_bv0_in_bw,"%ld\n",BV_in_bandwith[0]);
	fprintf(fp_bv1_in_bw,"%ld\n",BV_in_bandwith[1]);
	fprintf(fp_bv2_in_bw,"%ld\n",BV_in_bandwith[2]);
	fprintf(fp_bv3_in_bw,"%ld\n",BV_in_bandwith[3]);

	temp_bandwith=0;
	for(i=0;i<BV_NUM;i++)
	{
		temp_bandwith+=BV_out_bandwith[i];
	}
	fprintf(fp_all_bv_out_bw,"%ld\n",temp_bandwith);
	fprintf(fp_bv0_out_bw,"%ld\n",BV_out_bandwith[0]);
	fprintf(fp_bv1_out_bw,"%ld\n",BV_out_bandwith[1]);
	fprintf(fp_bv2_out_bw,"%ld\n",BV_out_bandwith[2]);
	fprintf(fp_bv3_out_bw,"%ld\n",BV_out_bandwith[3]);

	temp_bandwith=0;
	for(i=0;i<RDV_NUM;i++)
	{
		temp_bandwith+=RDV_in_bandwith[i];
	}
	fprintf(fp_all_rdv_in_bw,"%ld\n",temp_bandwith);
	fprintf(fp_rdv0_in_bw,"%ld\n",RDV_in_bandwith[0]);
	fprintf(fp_rdv1_in_bw,"%ld\n",RDV_in_bandwith[1]);
	fprintf(fp_rdv2_in_bw,"%ld\n",RDV_in_bandwith[2]);
	fprintf(fp_rdv3_in_bw,"%ld\n",RDV_in_bandwith[3]);

	temp_bandwith=0;
	for(i=0;i<RDV_NUM;i++)
	{
		temp_bandwith+=RDV_out_bandwith[i];
	}
	fprintf(fp_all_rdv_out_bw,"%ld\n",temp_bandwith);
	fprintf(fp_rdv0_out_bw,"%ld\n",RDV_out_bandwith[0]);
	fprintf(fp_rdv1_out_bw,"%ld\n",RDV_out_bandwith[1]);
	fprintf(fp_rdv2_out_bw,"%ld\n",RDV_out_bandwith[2]);
	fprintf(fp_rdv3_out_bw,"%ld\n",RDV_out_bandwith[3]);

	temp_bandwith=0;
	for(i=0;i<EXTV_NUM;i++)
	{
		temp_bandwith+=EXTV_in_bandwith[i];
	}
	fprintf(fp_all_extv_in_bw,"%ld\n",temp_bandwith);
	fprintf(fp_extv0_in_bw,"%ld\n",EXTV_in_bandwith[0]);
	fprintf(fp_extv1_in_bw,"%ld\n",EXTV_in_bandwith[1]);
	fprintf(fp_extv2_in_bw,"%ld\n",EXTV_in_bandwith[2]);
	fprintf(fp_extv3_in_bw,"%ld\n",EXTV_in_bandwith[3]);
	fprintf(fp_extv4_in_bw,"%ld\n",EXTV_in_bandwith[4]);
	fprintf(fp_extv5_in_bw,"%ld\n",EXTV_in_bandwith[5]);
	fprintf(fp_extv6_in_bw,"%ld\n",EXTV_in_bandwith[6]);
	fprintf(fp_extv7_in_bw,"%ld\n",EXTV_in_bandwith[7]);

	temp_bandwith=0;
	for(i=0;i<EXTV_NUM;i++)
	{
		temp_bandwith+=EXTV_out_bandwith[i];
	}
	fprintf(fp_all_extv_out_bw,"%ld\n",temp_bandwith);
	fprintf(fp_extv0_out_bw,"%ld\n",EXTV_out_bandwith[0]);
	fprintf(fp_extv1_out_bw,"%ld\n",EXTV_out_bandwith[1]);
	fprintf(fp_extv2_out_bw,"%ld\n",EXTV_out_bandwith[2]);
	fprintf(fp_extv3_out_bw,"%ld\n",EXTV_out_bandwith[3]);
	fprintf(fp_extv4_out_bw,"%ld\n",EXTV_out_bandwith[4]);
	fprintf(fp_extv5_out_bw,"%ld\n",EXTV_out_bandwith[5]);
	fprintf(fp_extv6_out_bw,"%ld\n",EXTV_out_bandwith[6]);
	fprintf(fp_extv7_out_bw,"%ld\n",EXTV_out_bandwith[7]);

	temp_bandwith=0;
	for(i=0;i<M_LAYER;i++)
	{
		temp_bandwith+=MAT_in_bandwith[i];
	}
	fprintf(fp_all_mat_in_bw,"%ld\n",temp_bandwith);
	fprintf(fp_mat0_in_bw,"%ld\n",MAT_in_bandwith[0]);
	fprintf(fp_mat1_in_bw,"%ld\n",MAT_in_bandwith[1]);
	fprintf(fp_mat2_in_bw,"%ld\n",MAT_in_bandwith[2]);
	fprintf(fp_mat3_in_bw,"%ld\n",MAT_in_bandwith[3]);
	fprintf(fp_mat4_in_bw,"%ld\n",MAT_in_bandwith[4]);
	fprintf(fp_mat5_in_bw,"%ld\n",MAT_in_bandwith[5]);
	fprintf(fp_mat6_in_bw,"%ld\n",MAT_in_bandwith[6]);
	fprintf(fp_mat7_in_bw,"%ld\n",MAT_in_bandwith[7]);

	temp_bandwith=0;
	for(i=0;i<M_LAYER;i++)
	{
		temp_bandwith+=MAT_out_bandwith[i];
	}
	fprintf(fp_all_mat_out_bw,"%ld\n",temp_bandwith);
	fprintf(fp_mat0_out_bw,"%ld\n",MAT_out_bandwith[0]);
	fprintf(fp_mat1_out_bw,"%ld\n",MAT_out_bandwith[1]);
	fprintf(fp_mat2_out_bw,"%ld\n",MAT_out_bandwith[2]);
	fprintf(fp_mat3_out_bw,"%ld\n",MAT_out_bandwith[3]);
	fprintf(fp_mat4_out_bw,"%ld\n",MAT_out_bandwith[4]);
	fprintf(fp_mat5_out_bw,"%ld\n",MAT_out_bandwith[5]);
	fprintf(fp_mat6_out_bw,"%ld\n",MAT_out_bandwith[6]);
	fprintf(fp_mat7_out_bw,"%ld\n",MAT_out_bandwith[7]);

	fprintf(fp_rbuffer_out_bw,"%ld\n",Rbuffer_out_bandwith);
	fprintf(fp_rbuffer_in_bw,"%ld\n",Rbuffer_in_bandwith);
	fprintf(fp_cbuffer_out_bw,"%ld\n",Cbuffer_out_bandwith);
	fprintf(fp_cbuffer_in_bw,"%ld\n",Cbuffer_in_bandwith);
	fprintf(fp_mbuffer_out_bw,"%ld\n",Mbuffer_out_bandwith);
	fprintf(fp_mbuffer_in_bw,"%ld\n",Mbuffer_in_bandwith);
	fprintf(fp_buffer0_out_bw,"%ld\n",buffer0_out_bandwith);
	fprintf(fp_buffer0_in_bw,"%ld\n",buffer0_in_bandwith);
	fprintf(fp_buffer1_out_bw,"%ld\n",buffer1_out_bandwith);
	fprintf(fp_buffer1_in_bw,"%ld\n",buffer1_in_bandwith);
	fprintf(fp_buffer2_out_bw,"%ld\n",buffer2_out_bandwith);
	fprintf(fp_buffer2_in_bw,"%ld\n",buffer2_in_bandwith);

	fprintf(fp_mem_in_bw,"%ld\n",mem_in_bandwith);
	fprintf(fp_mem_out_bw,"%ld\n",mem_out_bandwith);

	fprintf(fp_add_num,"%ld\n",addition_num);
	fprintf(fp_mul_num,"%ld\n",multiplication_num);

	save_temp_bw();
}
