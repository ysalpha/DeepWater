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
 * pulse error
 *
 * Complete pipeline simulation initialization
 */

#include <stdio.h>
#include <stdlib.h>
#include "wintolinux.h"

#include "pulse_error.h"

#define DATA_ERROR_FILE "err\\data_err.err"

FILE* data_error;

void open_err_file()
{
	if(access("err",0))
	{
		if( system("mkdir err") !=0 )
		{
			printf(" can not creat err folder.\n");
		}
	}

	data_error = fopen(DATA_ERROR_FILE,"w+");
	if(data_error == NULL)
	{
		printf("can not open %s file. \n",DATA_ERROR_FILE);
	}
}

void close_err_file()
{
	fclose(data_error);
}

void print_data_error(char* err_str,int ins_lines)
{
	fprintf(data_error,"%s in %d line.\n",err_str,ins_lines);
}
