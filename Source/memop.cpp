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
 * memop
 *
 * memory operation function
 */

#include <stdio.h>
#include <stdlib.h>

#include "memop.h"

bool readfile(char *filename,long address,long size, M_M *read)
{
	long i,count=0;
	int buf;
	FILE *fp;
	fp=fopen(filename,"r+");
	if(!fp)
	{
		printf("can't open convolayer_mem_tmp file in readfile() file.cpp \n");
		exit(0);
	}
	while(count<address)
	{
		fscanf(fp,"%d",&buf);
		//printf("-----------------------------buf--%d\n",buf);
		count++;
	}

	for(i=0;i<size;i++)
	{
		if(!feof(fp))
		{
			fscanf(fp,"%d",&read[i].M);
		}
		else
		{
			read[i].M=0;
		}
		//printf("------------------%d\n",read[i]);
	}
	fclose(fp);
	return 1;
}

bool writefile(char *filename,long address,long size,M_M *write)
{
	long count=0;
	int b,i=0;
	FILE *fp0;
	FILE *fp1;
	char bufname[]="buf.mem";
	fp0=fopen(filename,"r");
	if(!fp0)
	{
		printf("can't open convolayer_mem_tmp file in writefile() file.cpp \n");
		exit(0);
	}
	fp1=fopen(bufname,"w+");
	if(!fp1)
	{
		printf("can't open buf.mem file in writefile() file.cpp \n");
		exit(0);
	}
	while(count<address)
	{
		fscanf(fp0,"%d",&b);
		fprintf(fp1,"%d",b);
		fprintf(fp1,"%s","\n");
		count++;
	}
	fprintf(fp1,"%d",write[i].M);
	fscanf(fp0,"%d",&b);
	for(i=1;i<size;i++)
	{
		fprintf(fp1,"%s","\n");
		fprintf(fp1,"%d",write[i].M);
		fscanf(fp0,"%d",&b);
	}

	while(!feof(fp0))
	{
		fscanf(fp0,"%d",&b);
		fprintf(fp1,"%s","\n");
		fprintf(fp1,"%d",b);
	}

	fclose(fp0);
	fclose(fp1);
	remove(filename);
	rename(bufname,filename);
	return 1;
}

/*
bool showfile(char *filename,long start,long end)
{
	short shbuff[INIT_MEM_SIZE],buf;
	long i,j,k,size,count=0;
	FILE *fs;
	size =end-start+1;
	j=size/8;
	k=size%8;
	if(k!=0)
		j=j+1;
	else
		j=j;
	fs=fopen(filename,"r");
	while(count<start)
	{
		fscanf(fs,"%d",&buf);
		count++;
	}
	for(i=0;i<size;i++)
	{
		fscanf(fs,"%6d",&shbuff[i]);
	}
	for(i=0;i<j;i++)
	{
		printf("addr: %6d %6d %6d %6d %6d %6d %6d %6d\n",start+8*i,start+8*i+1,start+8*i+2,start+8*i+3,start+8*i+4,start+8*i+5,start+8*i+6,start+8*i+7);
		printf("data: %6d %6d %6d %6d %6d %6d %6d %6d\n",shbuff[8*i],shbuff[8*i+1],shbuff[8*i+2],shbuff[8*i+3],shbuff[8*i+4],shbuff[8*i+5],shbuff[8*i+6],shbuff[8*i+7]);
	}
	return 1;
}*/
