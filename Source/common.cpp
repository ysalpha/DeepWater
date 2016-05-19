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
 * common
 *
 * define some conmon function of all project
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "common.h"

/*!
by the value of buffid ,return the MEM_B point
input: buffid
return: struct MEM_B *,MEM_B declared in membuff.h
*/
struct MEM_B * get_buffp(int buffid)
{
	if(buffid==0)
	{
		return buff0;
	}
	else if(buffid==1)
	{
		return buff1;
	}
	else if(buffid==2)
	{
		return buff2;
	}
	else
	{
		printf("using  not existed buffer !\n");
		exit(0);
		return NULL;
	}
}

/*!
replace s_c in source by d_s, getting a new string assign dest
input:source,dest,s_c,d_s
return:replacing is success
*/
bool char_replace(char* source,char* dest,char s_c,char* d_s)
{
	int source_length=strlen(source);//get length of source//
	int dest_length=strlen(dest);
	int d_s_length=strlen(d_s);
	int i,j,k=0;
	for(i=0;i<source_length;i++)// look the source//
	{
		if(source[i]==s_c)
		{
			/* realize the replace s_c by d_s*/
			for(j=0;j<d_s_length;j++)
			{
				dest[k++]=d_s[j];
			}
		}
		else
		{
			dest[k++]=source[i];
		}
	}
	dest[k]='\0';
	return 1;
}
