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
 * fix comp
 *
 * Correction data manipulation
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "fixcomp.h"
#include "bandwith_monitor.h"
#include "pulse_error.h"

short fixadd(short a, short b,int ins_line)
{
	addition_num++;
	int a0,b0,c;
	a0=a;
	b0=b;
	c=a0+b0;
	if(c>32767)
	{
		if(!qGetD){
			print_data_error("The data is greater than the maximum number of short can said",ins_line);
		}
		return 32767;
	}
	else if (c<-32768)
	{
		if(!qGetD){
			print_data_error("The data is less than the minimum number can short said",ins_line);
		}
		return -32768;
	}
	else
	{
		return c;
	}
}

short fixmul(short a, short b,int ins_line)
{
	multiplication_num++;
	long a0,b0,c;
	a0=a;
	b0=b;
	c=a0*b0;
	c=(c>>10)+((c>>9)&1);
	if(c>32767)
	{
		if(!qGetD){
		print_data_error("The data is greater than the maximum number of short can said",ins_line);
		}
		return 32767;
	}
	else if(c<-32768)
	{
		if(!qGetD){
		print_data_error("The data is less than the minimum number can short said",ins_line);
		}
		return -32768;
	}
	else
	{
		return short(c);
	}

}

short fixactexp(short a,int ins_line)
{
	double a0;
	a0 = 1 + exp(float(-a/1024.0000));
	a0 = 1/a0;
	long b0;
	b0 = (a0 * 1024);
	if(b0>32767)
	{
		if(!qGetD){
		print_data_error("The data is greater than the maximum number of short can said",ins_line);
		}
		return 32767;
	}
	else if(b0<-32768)
	{
		if(!qGetD){
		print_data_error("The data is less than the minimum number can short said",ins_line);
		}
		return -32768;
	}
	else
	{
		return short(b0);
	}
}
