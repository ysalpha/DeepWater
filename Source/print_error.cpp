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
 * print error
 *
 * Print instructions error
 */

#include <stdio.h>
#include <stdlib.h>
#include "wintolinux.h"
#include <string.h>

#include "print_error.h"

#define ERROR_FILE "error"
#define DIRECTORY_INSR_ERROR "error\\instError.txt"
#define decode_error "error\\decode_error.txt"

FILE *fp_instError = NULL;

void create_errorFolder()
{
	if(access(ERROR_FILE,0))
	{
		if(system("mkdir error") != 0 )
		{
			printf(" can not create error folder. \n");
			printf(" can create error folder by hand movement. \n");
			exit(0);
		}
	}
}

void open_instError()
{
	create_errorFolder();
	errno_t err;
	if((err = fopen_s(&fp_instError,DIRECTORY_INSR_ERROR,"w+")))
	{
		printf(" can not create instError.txt. error:%s\n",strerror(err));
		printf(" can create instError.txt by hand movement. \n");
		exit(0);
	}
}

void close_instError()
{
	fclose(fp_instError);
}

void print_instError(char* errorStr,long indexInst)
{
	fprintf(fp_instError,"%s %ld\n",errorStr,indexInst);
}

void print_error_ex(char* str)
{
	FILE *fp;
	create_errorFolder();
	fp = fopen(decode_error,"w+");
	if(fp==NULL)
	{
		printf("can't open error file \n");
		exit(0);
	}
	fprintf(fp,"%s\n",str);
	fclose(fp);
}
