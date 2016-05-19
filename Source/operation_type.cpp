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
 * operation type
 *
 * print instruction operation type num
 */

#include<stdio.h>
#include<stdlib.h>
#include"wintolinux.h"
#include<string.h>

#include "operation_type.h"

#ifndef _MSC_VER
#define OPTYPE_FILE "optype/all.txt"
#else
#define OPTYPE_FILE "optype\\all.txt"
#endif

FILE *fp_optype;

long VV_num_add=0;
long VV_num_mul=0;
long VM_num_add=0;
long VM_num_mul=0;
long MV_num_add=0;
long MV_num_mul=0;
long MM_num_add=0;
long MM_num_mul=0;
long IV_num_add=0;
long IV_num_mul=0;
long IM_num_add=0;
long IM_num_mul=0;
long exp_num=0;

void open_file_optype()
{
	if(access("optype",0))
	{
		if( system("mkdir optype") !=0 )
		{
			printf(" cann't not creat optype folder.\n");
			exit(0);
		}
	}
	errno_t err;
	if((err=fopen_s(&fp_optype,OPTYPE_FILE,"w+"))!=0)
	{
		printf("can not open %s file in operation_type.cpp.erron:%s\n",OPTYPE_FILE,strerror(err));
		exit(0);
	}
}

void close_file_optype()
{
	fclose(fp_optype);
}

void print_optype()
{
	open_file_optype();
	fprintf(fp_optype,"VV_num_add:%ld\nVM_num_add:%ld\nMV_num_add:%ld\nMM_num_add:%ld\nIV_num_add:%ld\nIM_num_add:%ld\nexp_num_add:%ld\n",VV_num_add,VM_num_add,MV_num_add,MM_num_add,IV_num_add,IM_num_add,exp_num);
	fprintf(fp_optype,"VV_num_mul:%ld\nVM_num_mul:%ld\nMV_num_mul:%ld\nMM_num_mul:%ld\nIV_num_mul:%ld\nIM_num_mul:%ld\n",VV_num_mul,VM_num_mul,MV_num_mul,MM_num_mul,IV_num_mul,IM_num_mul);
	close_file_optype();
}
