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
 * print INAddr
 *
 * Print the simulator long instruction address data
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "printINAddr.h"
#include "wintolinux.h"

#define FILE_ADDR "addr.txt"

FILE * fp_addr_IN;

void openprintAddr()
{
	errno_t err;
	err = fopen_s(&fp_addr_IN,FILE_ADDR,"w+");
	if(err != 0)
	{
		printf("can not creat %s file .-----%s\n",FILE_ADDR,strerror(err));
		exit(0);
	}
}

void closeprintAddr()
{
	fclose(fp_addr_IN);
}

void printAddr(long inaddr)
{
	fprintf(fp_addr_IN,"%ld\n",inaddr);
}
