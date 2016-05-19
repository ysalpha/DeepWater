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
 * Print the simulator MAT hardware module statistical data
 */

#include<stdio.h>
#include<stdlib.h>
#include"wintolinux.h"

#include "print_mat.h"
#include "ps_pipeline.h"


FILE *fp_mat0_0;
FILE *fp_mat0_1;
FILE *fp_mat0_2;
FILE *fp_mat0_3;
FILE *fp_mat0_4;
FILE *fp_mat0_5;
FILE *fp_mat0_6;
FILE *fp_mat0_7;
FILE *fp_mat0_8;
FILE *fp_mat0_9;
FILE *fp_mat0_10;
FILE *fp_mat0_11;
FILE *fp_mat0_12;
FILE *fp_mat0_13;
FILE *fp_mat0_14;
FILE *fp_mat0_15;

FILE *fp_mat1_0;
FILE *fp_mat1_1;
FILE *fp_mat1_2;
FILE *fp_mat1_3;
FILE *fp_mat1_4;
FILE *fp_mat1_5;
FILE *fp_mat1_6;
FILE *fp_mat1_7;
FILE *fp_mat1_8;
FILE *fp_mat1_9;
FILE *fp_mat1_10;
FILE *fp_mat1_11;
FILE *fp_mat1_12;
FILE *fp_mat1_13;
FILE *fp_mat1_14;
FILE *fp_mat1_15;

FILE *fp_mat2_0;
FILE *fp_mat2_1;
FILE *fp_mat2_2;
FILE *fp_mat2_3;
FILE *fp_mat2_4;
FILE *fp_mat2_5;
FILE *fp_mat2_6;
FILE *fp_mat2_7;
FILE *fp_mat2_8;
FILE *fp_mat2_9;
FILE *fp_mat2_10;
FILE *fp_mat2_11;
FILE *fp_mat2_12;
FILE *fp_mat2_13;
FILE *fp_mat2_14;
FILE *fp_mat2_15;

FILE *fp_mat3_0;
FILE *fp_mat3_1;
FILE *fp_mat3_2;
FILE *fp_mat3_3;
FILE *fp_mat3_4;
FILE *fp_mat3_5;
FILE *fp_mat3_6;
FILE *fp_mat3_7;
FILE *fp_mat3_8;
FILE *fp_mat3_9;
FILE *fp_mat3_10;
FILE *fp_mat3_11;
FILE *fp_mat3_12;
FILE *fp_mat3_13;
FILE *fp_mat3_14;
FILE *fp_mat3_15;

FILE *fp_mat4_0;
FILE *fp_mat4_1;
FILE *fp_mat4_2;
FILE *fp_mat4_3;
FILE *fp_mat4_4;
FILE *fp_mat4_5;
FILE *fp_mat4_6;
FILE *fp_mat4_7;
FILE *fp_mat4_8;
FILE *fp_mat4_9;
FILE *fp_mat4_10;
FILE *fp_mat4_11;
FILE *fp_mat4_12;
FILE *fp_mat4_13;
FILE *fp_mat4_14;
FILE *fp_mat4_15;

FILE *fp_mat5_0;
FILE *fp_mat5_1;
FILE *fp_mat5_2;
FILE *fp_mat5_3;
FILE *fp_mat5_4;
FILE *fp_mat5_5;
FILE *fp_mat5_6;
FILE *fp_mat5_7;
FILE *fp_mat5_8;
FILE *fp_mat5_9;
FILE *fp_mat5_10;
FILE *fp_mat5_11;
FILE *fp_mat5_12;
FILE *fp_mat5_13;
FILE *fp_mat5_14;
FILE *fp_mat5_15;

FILE *fp_mat6_0;
FILE *fp_mat6_1;
FILE *fp_mat6_2;
FILE *fp_mat6_3;
FILE *fp_mat6_4;
FILE *fp_mat6_5;
FILE *fp_mat6_6;
FILE *fp_mat6_7;
FILE *fp_mat6_8;
FILE *fp_mat6_9;
FILE *fp_mat6_10;
FILE *fp_mat6_11;
FILE *fp_mat6_12;
FILE *fp_mat6_13;
FILE *fp_mat6_14;
FILE *fp_mat6_15;

FILE *fp_mat7_0;
FILE *fp_mat7_1;
FILE *fp_mat7_2;
FILE *fp_mat7_3;
FILE *fp_mat7_4;
FILE *fp_mat7_5;
FILE *fp_mat7_6;
FILE *fp_mat7_7;
FILE *fp_mat7_8;
FILE *fp_mat7_9;
FILE *fp_mat7_10;
FILE *fp_mat7_11;
FILE *fp_mat7_12;
FILE *fp_mat7_13;
FILE *fp_mat7_14;
FILE *fp_mat7_15;

//FILE *fp_mat8_0;
//FILE *fp_mat8_1;
//FILE *fp_mat8_2;
//FILE *fp_mat8_3;
//FILE *fp_mat8_4;
//FILE *fp_mat8_5;
//FILE *fp_mat8_6;
//FILE *fp_mat8_7;
//FILE *fp_mat8_8;
//FILE *fp_mat8_9;
//FILE *fp_mat8_10;
//FILE *fp_mat8_11;
//FILE *fp_mat8_12;
//FILE *fp_mat8_13;
//FILE *fp_mat8_14;
//FILE *fp_mat8_15;
//
//FILE *fp_mat9_0;
//FILE *fp_mat9_1;
//FILE *fp_mat9_2;
//FILE *fp_mat9_3;
//FILE *fp_mat9_4;
//FILE *fp_mat9_5;
//FILE *fp_mat9_6;
//FILE *fp_mat9_7;
//FILE *fp_mat9_8;
//FILE *fp_mat9_9;
//FILE *fp_mat9_10;
//FILE *fp_mat9_11;
//FILE *fp_mat9_12;
//FILE *fp_mat9_13;
//FILE *fp_mat9_14;
//FILE *fp_mat9_15;
//
//FILE *fp_mat10_0;
//FILE *fp_mat10_1;
//FILE *fp_mat10_2;
//FILE *fp_mat10_3;
//FILE *fp_mat10_4;
//FILE *fp_mat10_5;
//FILE *fp_mat10_6;
//FILE *fp_mat10_7;
//FILE *fp_mat10_8;
//FILE *fp_mat10_9;
//FILE *fp_mat10_10;
//FILE *fp_mat10_11;
//FILE *fp_mat10_12;
//FILE *fp_mat10_13;
//FILE *fp_mat10_14;
//FILE *fp_mat10_15;
//
//FILE *fp_mat11_0;
//FILE *fp_mat11_1;
//FILE *fp_mat11_2;
//FILE *fp_mat11_3;
//FILE *fp_mat11_4;
//FILE *fp_mat11_5;
//FILE *fp_mat11_6;
//FILE *fp_mat11_7;
//FILE *fp_mat11_8;
//FILE *fp_mat11_9;
//FILE *fp_mat11_10;
//FILE *fp_mat11_11;
//FILE *fp_mat11_12;
//FILE *fp_mat11_13;
//FILE *fp_mat11_14;
//FILE *fp_mat11_15;
//
//FILE *fp_mat12_0;
//FILE *fp_mat12_1;
//FILE *fp_mat12_2;
//FILE *fp_mat12_3;
//FILE *fp_mat12_4;
//FILE *fp_mat12_5;
//FILE *fp_mat12_6;
//FILE *fp_mat12_7;
//FILE *fp_mat12_8;
//FILE *fp_mat12_9;
//FILE *fp_mat12_10;
//FILE *fp_mat12_11;
//FILE *fp_mat12_12;
//FILE *fp_mat12_13;
//FILE *fp_mat12_14;
//FILE *fp_mat12_15;
//
//FILE *fp_mat13_0;
//FILE *fp_mat13_1;
//FILE *fp_mat13_2;
//FILE *fp_mat13_3;
//FILE *fp_mat13_4;
//FILE *fp_mat13_5;
//FILE *fp_mat13_6;
//FILE *fp_mat13_7;
//FILE *fp_mat13_8;
//FILE *fp_mat13_9;
//FILE *fp_mat13_10;
//FILE *fp_mat13_11;
//FILE *fp_mat13_12;
//FILE *fp_mat13_13;
//FILE *fp_mat13_14;
//FILE *fp_mat13_15;
//
//FILE *fp_mat14_0;
//FILE *fp_mat14_1;
//FILE *fp_mat14_2;
//FILE *fp_mat14_3;
//FILE *fp_mat14_4;
//FILE *fp_mat14_5;
//FILE *fp_mat14_6;
//FILE *fp_mat14_7;
//FILE *fp_mat14_8;
//FILE *fp_mat14_9;
//FILE *fp_mat14_10;
//FILE *fp_mat14_11;
//FILE *fp_mat14_12;
//FILE *fp_mat14_13;
//FILE *fp_mat14_14;
//FILE *fp_mat14_15;
//
//FILE *fp_mat15_0;
//FILE *fp_mat15_1;
//FILE *fp_mat15_2;
//FILE *fp_mat15_3;
//FILE *fp_mat15_4;
//FILE *fp_mat15_5;
//FILE *fp_mat15_6;
//FILE *fp_mat15_7;
//FILE *fp_mat15_8;
//FILE *fp_mat15_9;
//FILE *fp_mat15_10;
//FILE *fp_mat15_11;
//FILE *fp_mat15_12;
//FILE *fp_mat15_13;
//FILE *fp_mat15_14;
//FILE *fp_mat15_15;

void print_mat0_0()
{
	fprintf(fp_mat0_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[0].V[0],MAT[0]->M_V[0].V[1],MAT[0]->M_V[0].V[2],MAT[0]->M_V[0].V[3],MAT[0]->M_V[0].V[4],MAT[0]->M_V[0].V[5],MAT[0]->M_V[0].V[6],MAT[0]->M_V[0].V[7],MAT[0]->M_V[0].V[8],MAT[0]->M_V[0].V[9],MAT[0]->M_V[0].V[10],MAT[0]->M_V[0].V[11],MAT[0]->M_V[0].V[12],MAT[0]->M_V[0].V[13],MAT[0]->M_V[0].V[14],MAT[0]->M_V[0].V[15]);
}

void print_mat0_1()
{
	fprintf(fp_mat0_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[1].V[0],MAT[0]->M_V[1].V[1],MAT[0]->M_V[1].V[2],MAT[0]->M_V[1].V[3],MAT[0]->M_V[1].V[4],MAT[0]->M_V[1].V[5],MAT[0]->M_V[1].V[6],MAT[0]->M_V[1].V[7],MAT[0]->M_V[1].V[8],MAT[0]->M_V[1].V[9],MAT[0]->M_V[1].V[10],MAT[0]->M_V[1].V[11],MAT[0]->M_V[1].V[12],MAT[0]->M_V[1].V[13],MAT[0]->M_V[1].V[14],MAT[0]->M_V[1].V[15]);
}

void print_mat0_2()
{
	 fprintf(fp_mat0_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[2].V[0],MAT[0]->M_V[2].V[1],MAT[0]->M_V[2].V[2],MAT[0]->M_V[2].V[3],MAT[0]->M_V[2].V[4],MAT[0]->M_V[2].V[5],MAT[0]->M_V[2].V[6],MAT[0]->M_V[2].V[7],MAT[0]->M_V[2].V[8],MAT[0]->M_V[2].V[9],MAT[0]->M_V[2].V[10],MAT[0]->M_V[2].V[11],MAT[0]->M_V[2].V[12],MAT[0]->M_V[2].V[13],MAT[0]->M_V[2].V[14],MAT[0]->M_V[2].V[15]);
}

void print_mat0_3()
{
	fprintf(fp_mat0_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[3].V[0],MAT[0]->M_V[3].V[1],MAT[0]->M_V[3].V[2],MAT[0]->M_V[3].V[3],MAT[0]->M_V[3].V[4],MAT[0]->M_V[3].V[5],MAT[0]->M_V[3].V[6],MAT[0]->M_V[3].V[7],MAT[0]->M_V[3].V[8],MAT[0]->M_V[3].V[9],MAT[0]->M_V[3].V[10],MAT[0]->M_V[3].V[11],MAT[0]->M_V[3].V[12],MAT[0]->M_V[3].V[13],MAT[0]->M_V[3].V[14],MAT[0]->M_V[3].V[15]);    
}

void print_mat0_4()
{
	fprintf(fp_mat0_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[4].V[0],MAT[0]->M_V[4].V[1],MAT[0]->M_V[4].V[2],MAT[0]->M_V[4].V[3],MAT[0]->M_V[4].V[4],MAT[0]->M_V[4].V[5],MAT[0]->M_V[4].V[6],MAT[0]->M_V[4].V[7],MAT[0]->M_V[4].V[8],MAT[0]->M_V[4].V[9],MAT[0]->M_V[4].V[10],MAT[0]->M_V[4].V[11],MAT[0]->M_V[4].V[12],MAT[0]->M_V[4].V[13],MAT[0]->M_V[4].V[14],MAT[0]->M_V[4].V[15]);
}

void print_mat0_5()
{
	fprintf(fp_mat0_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[5].V[0],MAT[0]->M_V[5].V[1],MAT[0]->M_V[5].V[2],MAT[0]->M_V[5].V[3],MAT[0]->M_V[5].V[4],MAT[0]->M_V[5].V[5],MAT[0]->M_V[5].V[6],MAT[0]->M_V[5].V[7],MAT[0]->M_V[5].V[8],MAT[0]->M_V[5].V[9],MAT[0]->M_V[5].V[10],MAT[0]->M_V[5].V[11],MAT[0]->M_V[5].V[12],MAT[0]->M_V[5].V[13],MAT[0]->M_V[5].V[14],MAT[0]->M_V[5].V[15]);
}

void print_mat0_6()
{
	fprintf(fp_mat0_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[6].V[0],MAT[0]->M_V[6].V[1],MAT[0]->M_V[6].V[2],MAT[0]->M_V[6].V[3],MAT[0]->M_V[6].V[4],MAT[0]->M_V[6].V[5],MAT[0]->M_V[6].V[6],MAT[0]->M_V[6].V[7],MAT[0]->M_V[6].V[8],MAT[0]->M_V[6].V[9],MAT[0]->M_V[6].V[10],MAT[0]->M_V[6].V[11],MAT[0]->M_V[6].V[12],MAT[0]->M_V[6].V[13],MAT[0]->M_V[6].V[14],MAT[0]->M_V[6].V[15]);
}

void print_mat0_7()
{
	fprintf(fp_mat0_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[7].V[0],MAT[0]->M_V[7].V[1],MAT[0]->M_V[7].V[2],MAT[0]->M_V[7].V[3],MAT[0]->M_V[7].V[4],MAT[0]->M_V[7].V[5],MAT[0]->M_V[7].V[6],MAT[0]->M_V[7].V[7],MAT[0]->M_V[7].V[8],MAT[0]->M_V[7].V[9],MAT[0]->M_V[7].V[10],MAT[0]->M_V[7].V[11],MAT[0]->M_V[7].V[12],MAT[0]->M_V[7].V[13],MAT[0]->M_V[7].V[14],MAT[0]->M_V[0].V[15]);
}

void print_mat0_8()
{
	fprintf(fp_mat0_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[8].V[0],MAT[0]->M_V[8].V[1],MAT[0]->M_V[8].V[2],MAT[0]->M_V[8].V[3],MAT[0]->M_V[8].V[4],MAT[0]->M_V[8].V[5],MAT[0]->M_V[8].V[6],MAT[0]->M_V[8].V[7],MAT[0]->M_V[8].V[8],MAT[0]->M_V[8].V[9],MAT[0]->M_V[8].V[10],MAT[0]->M_V[8].V[11],MAT[0]->M_V[8].V[12],MAT[0]->M_V[8].V[13],MAT[0]->M_V[8].V[14],MAT[0]->M_V[8].V[15]);
}

void print_mat0_9()
{
	fprintf(fp_mat0_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[9].V[0],MAT[0]->M_V[9].V[1],MAT[0]->M_V[9].V[2],MAT[0]->M_V[9].V[3],MAT[0]->M_V[9].V[4],MAT[0]->M_V[9].V[5],MAT[0]->M_V[9].V[6],MAT[0]->M_V[9].V[7],MAT[0]->M_V[9].V[8],MAT[0]->M_V[9].V[9],MAT[0]->M_V[9].V[10],MAT[0]->M_V[9].V[11],MAT[0]->M_V[9].V[12],MAT[0]->M_V[9].V[13],MAT[0]->M_V[9].V[14],MAT[0]->M_V[9].V[15]);
}

void print_mat0_10()
{
	fprintf(fp_mat0_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[10].V[0],MAT[0]->M_V[10].V[1],MAT[0]->M_V[10].V[2],MAT[0]->M_V[10].V[3],MAT[0]->M_V[10].V[4],MAT[0]->M_V[10].V[5],MAT[0]->M_V[10].V[6],MAT[0]->M_V[10].V[7],MAT[0]->M_V[10].V[8],MAT[0]->M_V[10].V[9],MAT[0]->M_V[10].V[10],MAT[0]->M_V[10].V[11],MAT[0]->M_V[10].V[12],MAT[0]->M_V[10].V[13],MAT[0]->M_V[10].V[14],MAT[0]->M_V[10].V[15]);
}

void print_mat0_11()
{
	fprintf(fp_mat0_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[11].V[0],MAT[0]->M_V[11].V[1],MAT[0]->M_V[12].V[2],MAT[0]->M_V[11].V[3],MAT[0]->M_V[11].V[4],MAT[0]->M_V[11].V[5],MAT[0]->M_V[11].V[6],MAT[0]->M_V[11].V[7],MAT[0]->M_V[11].V[8],MAT[0]->M_V[11].V[9],MAT[0]->M_V[11].V[10],MAT[0]->M_V[11].V[11],MAT[0]->M_V[11].V[12],MAT[0]->M_V[11].V[13],MAT[0]->M_V[11].V[14],MAT[0]->M_V[11].V[15]);
}

void print_mat0_12()
{
	fprintf(fp_mat0_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[12].V[0],MAT[0]->M_V[12].V[1],MAT[0]->M_V[13].V[2],MAT[0]->M_V[12].V[3],MAT[0]->M_V[12].V[4],MAT[0]->M_V[12].V[5],MAT[0]->M_V[12].V[6],MAT[0]->M_V[12].V[7],MAT[0]->M_V[12].V[8],MAT[0]->M_V[12].V[9],MAT[0]->M_V[12].V[10],MAT[0]->M_V[12].V[11],MAT[0]->M_V[12].V[12],MAT[0]->M_V[12].V[13],MAT[0]->M_V[12].V[14],MAT[0]->M_V[12].V[15]);
}

void print_mat0_13()
{
	fprintf(fp_mat0_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[13].V[0],MAT[0]->M_V[13].V[1],MAT[0]->M_V[14].V[2],MAT[0]->M_V[13].V[3],MAT[0]->M_V[13].V[4],MAT[0]->M_V[13].V[5],MAT[0]->M_V[13].V[6],MAT[0]->M_V[13].V[7],MAT[0]->M_V[13].V[8],MAT[0]->M_V[13].V[9],MAT[0]->M_V[13].V[10],MAT[0]->M_V[13].V[11],MAT[0]->M_V[13].V[12],MAT[0]->M_V[13].V[13],MAT[0]->M_V[13].V[14],MAT[0]->M_V[13].V[15]);
}

void print_mat0_14()
{
	fprintf(fp_mat0_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[14].V[0],MAT[0]->M_V[14].V[1],MAT[0]->M_V[15].V[2],MAT[0]->M_V[14].V[3],MAT[0]->M_V[14].V[4],MAT[0]->M_V[14].V[5],MAT[0]->M_V[14].V[6],MAT[0]->M_V[14].V[7],MAT[0]->M_V[14].V[8],MAT[0]->M_V[14].V[9],MAT[0]->M_V[14].V[10],MAT[0]->M_V[14].V[11],MAT[0]->M_V[14].V[12],MAT[0]->M_V[14].V[13],MAT[0]->M_V[14].V[14],MAT[0]->M_V[14].V[15]);
}

void print_mat0_15()
{
	fprintf(fp_mat0_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[0]->M_V[15].V[0],MAT[0]->M_V[15].V[1],MAT[0]->M_V[16].V[2],MAT[0]->M_V[15].V[3],MAT[0]->M_V[15].V[4],MAT[0]->M_V[15].V[5],MAT[0]->M_V[15].V[6],MAT[0]->M_V[15].V[7],MAT[0]->M_V[15].V[8],MAT[0]->M_V[15].V[9],MAT[0]->M_V[15].V[10],MAT[0]->M_V[15].V[11],MAT[0]->M_V[15].V[12],MAT[0]->M_V[15].V[13],MAT[0]->M_V[15].V[14],MAT[0]->M_V[15].V[15]);
}

void print_mat1_0()
{
	fprintf(fp_mat1_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[0].V[0],MAT[1]->M_V[0].V[1],MAT[1]->M_V[0].V[2],MAT[1]->M_V[0].V[3],MAT[1]->M_V[0].V[4],MAT[1]->M_V[0].V[5],MAT[1]->M_V[0].V[6],MAT[1]->M_V[0].V[7],MAT[1]->M_V[0].V[8],MAT[1]->M_V[0].V[9],MAT[1]->M_V[0].V[10],MAT[1]->M_V[0].V[11],MAT[1]->M_V[0].V[12],MAT[1]->M_V[0].V[13],MAT[1]->M_V[0].V[14],MAT[1]->M_V[0].V[15]);
}

void print_mat1_1()
{
	fprintf(fp_mat1_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[1].V[0],MAT[1]->M_V[1].V[1],MAT[1]->M_V[1].V[2],MAT[1]->M_V[1].V[3],MAT[1]->M_V[1].V[4],MAT[1]->M_V[1].V[5],MAT[1]->M_V[1].V[6],MAT[1]->M_V[1].V[7],MAT[1]->M_V[1].V[8],MAT[1]->M_V[1].V[9],MAT[1]->M_V[1].V[10],MAT[1]->M_V[1].V[11],MAT[1]->M_V[1].V[12],MAT[1]->M_V[1].V[13],MAT[1]->M_V[1].V[14],MAT[1]->M_V[1].V[15]);
}

void print_mat1_2()
{
	fprintf(fp_mat1_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[2].V[0],MAT[1]->M_V[2].V[1],MAT[1]->M_V[2].V[2],MAT[1]->M_V[2].V[3],MAT[1]->M_V[2].V[4],MAT[1]->M_V[2].V[5],MAT[1]->M_V[2].V[6],MAT[1]->M_V[2].V[7],MAT[1]->M_V[2].V[8],MAT[1]->M_V[2].V[9],MAT[1]->M_V[2].V[10],MAT[1]->M_V[2].V[11],MAT[1]->M_V[2].V[12],MAT[1]->M_V[2].V[13],MAT[1]->M_V[2].V[14],MAT[1]->M_V[2].V[15]);
}

void print_mat1_3()
{
	fprintf(fp_mat1_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[3].V[0],MAT[1]->M_V[3].V[1],MAT[1]->M_V[3].V[2],MAT[1]->M_V[3].V[3],MAT[1]->M_V[3].V[4],MAT[1]->M_V[3].V[5],MAT[1]->M_V[3].V[6],MAT[1]->M_V[3].V[7],MAT[1]->M_V[3].V[8],MAT[1]->M_V[3].V[9],MAT[1]->M_V[3].V[10],MAT[1]->M_V[3].V[11],MAT[1]->M_V[3].V[12],MAT[1]->M_V[3].V[13],MAT[1]->M_V[3].V[14],MAT[1]->M_V[3].V[15]);    
}

void print_mat1_4()
{
	fprintf(fp_mat1_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[4].V[0],MAT[1]->M_V[4].V[1],MAT[1]->M_V[4].V[2],MAT[1]->M_V[4].V[3],MAT[1]->M_V[4].V[4],MAT[1]->M_V[4].V[5],MAT[1]->M_V[4].V[6],MAT[1]->M_V[4].V[7],MAT[1]->M_V[4].V[8],MAT[1]->M_V[4].V[9],MAT[1]->M_V[4].V[10],MAT[1]->M_V[4].V[11],MAT[1]->M_V[4].V[12],MAT[1]->M_V[4].V[13],MAT[1]->M_V[4].V[14],MAT[1]->M_V[4].V[15]);
}

void print_mat1_5()
{
	fprintf(fp_mat1_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[5].V[0],MAT[1]->M_V[5].V[1],MAT[1]->M_V[5].V[2],MAT[1]->M_V[5].V[3],MAT[1]->M_V[5].V[4],MAT[1]->M_V[5].V[5],MAT[1]->M_V[5].V[6],MAT[1]->M_V[5].V[7],MAT[1]->M_V[5].V[8],MAT[1]->M_V[5].V[9],MAT[1]->M_V[5].V[10],MAT[1]->M_V[5].V[11],MAT[1]->M_V[5].V[12],MAT[1]->M_V[5].V[13],MAT[1]->M_V[5].V[14],MAT[1]->M_V[5].V[15]);
}

void print_mat1_6()
{
	fprintf(fp_mat1_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[6].V[0],MAT[1]->M_V[6].V[1],MAT[1]->M_V[6].V[2],MAT[1]->M_V[6].V[3],MAT[1]->M_V[6].V[4],MAT[1]->M_V[6].V[5],MAT[1]->M_V[6].V[6],MAT[1]->M_V[6].V[7],MAT[1]->M_V[6].V[8],MAT[1]->M_V[6].V[9],MAT[1]->M_V[6].V[10],MAT[1]->M_V[6].V[11],MAT[1]->M_V[6].V[12],MAT[1]->M_V[6].V[13],MAT[1]->M_V[6].V[14],MAT[1]->M_V[6].V[15]);

}

void print_mat1_7()
{
	fprintf(fp_mat1_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[7].V[0],MAT[1]->M_V[7].V[1],MAT[1]->M_V[7].V[2],MAT[1]->M_V[7].V[3],MAT[1]->M_V[7].V[4],MAT[1]->M_V[7].V[5],MAT[1]->M_V[7].V[6],MAT[1]->M_V[7].V[7],MAT[1]->M_V[7].V[8],MAT[1]->M_V[7].V[9],MAT[1]->M_V[7].V[10],MAT[1]->M_V[7].V[11],MAT[1]->M_V[7].V[12],MAT[1]->M_V[7].V[13],MAT[1]->M_V[7].V[14],MAT[1]->M_V[0].V[15]);
 
}

void print_mat1_8()
{
	fprintf(fp_mat1_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[8].V[0],MAT[1]->M_V[8].V[1],MAT[1]->M_V[8].V[2],MAT[1]->M_V[8].V[3],MAT[1]->M_V[8].V[4],MAT[1]->M_V[8].V[5],MAT[1]->M_V[8].V[6],MAT[1]->M_V[8].V[7],MAT[1]->M_V[8].V[8],MAT[1]->M_V[8].V[9],MAT[1]->M_V[8].V[10],MAT[1]->M_V[8].V[11],MAT[1]->M_V[8].V[12],MAT[1]->M_V[8].V[13],MAT[1]->M_V[8].V[14],MAT[1]->M_V[8].V[15]);
}

void print_mat1_9()
{
	fprintf(fp_mat1_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[9].V[0],MAT[1]->M_V[9].V[1],MAT[1]->M_V[9].V[2],MAT[1]->M_V[9].V[3],MAT[1]->M_V[9].V[4],MAT[1]->M_V[9].V[5],MAT[1]->M_V[9].V[6],MAT[1]->M_V[9].V[7],MAT[1]->M_V[9].V[8],MAT[1]->M_V[9].V[9],MAT[1]->M_V[9].V[10],MAT[1]->M_V[9].V[11],MAT[1]->M_V[9].V[12],MAT[1]->M_V[9].V[13],MAT[1]->M_V[9].V[14],MAT[1]->M_V[9].V[15]);
}

void print_mat1_10()
{
	fprintf(fp_mat1_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[10].V[0],MAT[1]->M_V[10].V[1],MAT[1]->M_V[10].V[2],MAT[1]->M_V[10].V[3],MAT[1]->M_V[10].V[4],MAT[1]->M_V[10].V[5],MAT[1]->M_V[10].V[6],MAT[1]->M_V[10].V[7],MAT[1]->M_V[10].V[8],MAT[1]->M_V[10].V[9],MAT[1]->M_V[10].V[10],MAT[1]->M_V[10].V[11],MAT[1]->M_V[10].V[12],MAT[1]->M_V[10].V[13],MAT[1]->M_V[10].V[14],MAT[1]->M_V[10].V[15]);
}

void print_mat1_11()
{
	fprintf(fp_mat1_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[11].V[0],MAT[1]->M_V[11].V[1],MAT[1]->M_V[12].V[2],MAT[1]->M_V[11].V[3],MAT[1]->M_V[11].V[4],MAT[1]->M_V[11].V[5],MAT[1]->M_V[11].V[6],MAT[1]->M_V[11].V[7],MAT[1]->M_V[11].V[8],MAT[1]->M_V[11].V[9],MAT[1]->M_V[11].V[10],MAT[1]->M_V[11].V[11],MAT[1]->M_V[11].V[12],MAT[1]->M_V[11].V[13],MAT[1]->M_V[11].V[14],MAT[1]->M_V[11].V[15]);
}

void print_mat1_12()
{
	fprintf(fp_mat1_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[12].V[0],MAT[1]->M_V[12].V[1],MAT[1]->M_V[13].V[2],MAT[1]->M_V[12].V[3],MAT[1]->M_V[12].V[4],MAT[1]->M_V[12].V[5],MAT[1]->M_V[12].V[6],MAT[1]->M_V[12].V[7],MAT[1]->M_V[12].V[8],MAT[1]->M_V[12].V[9],MAT[1]->M_V[12].V[10],MAT[1]->M_V[12].V[11],MAT[1]->M_V[12].V[12],MAT[1]->M_V[12].V[13],MAT[1]->M_V[12].V[14],MAT[1]->M_V[12].V[15]);
}

void print_mat1_13()
{
	fprintf(fp_mat1_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[13].V[0],MAT[1]->M_V[13].V[1],MAT[1]->M_V[14].V[2],MAT[1]->M_V[13].V[3],MAT[1]->M_V[13].V[4],MAT[1]->M_V[13].V[5],MAT[1]->M_V[13].V[6],MAT[1]->M_V[13].V[7],MAT[1]->M_V[13].V[8],MAT[1]->M_V[13].V[9],MAT[1]->M_V[13].V[10],MAT[1]->M_V[13].V[11],MAT[1]->M_V[13].V[12],MAT[1]->M_V[13].V[13],MAT[1]->M_V[13].V[14],MAT[1]->M_V[13].V[15]);
}

void print_mat1_14()
{
	fprintf(fp_mat1_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[14].V[0],MAT[1]->M_V[14].V[1],MAT[1]->M_V[15].V[2],MAT[1]->M_V[14].V[3],MAT[1]->M_V[14].V[4],MAT[1]->M_V[14].V[5],MAT[1]->M_V[14].V[6],MAT[1]->M_V[14].V[7],MAT[1]->M_V[14].V[8],MAT[1]->M_V[14].V[9],MAT[1]->M_V[14].V[10],MAT[1]->M_V[14].V[11],MAT[1]->M_V[14].V[12],MAT[1]->M_V[14].V[13],MAT[1]->M_V[14].V[14],MAT[1]->M_V[14].V[15]);
}

void print_mat1_15()
{
	fprintf(fp_mat1_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[1]->M_V[15].V[0],MAT[1]->M_V[15].V[1],MAT[1]->M_V[16].V[2],MAT[1]->M_V[15].V[3],MAT[1]->M_V[15].V[4],MAT[1]->M_V[15].V[5],MAT[1]->M_V[15].V[6],MAT[1]->M_V[15].V[7],MAT[1]->M_V[15].V[8],MAT[1]->M_V[15].V[9],MAT[1]->M_V[15].V[10],MAT[1]->M_V[15].V[11],MAT[1]->M_V[15].V[12],MAT[1]->M_V[15].V[13],MAT[1]->M_V[15].V[14],MAT[1]->M_V[15].V[15]);
}


void print_mat2_0()
{
	fprintf(fp_mat2_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[0].V[0],MAT[2]->M_V[0].V[1],MAT[2]->M_V[0].V[2],MAT[2]->M_V[0].V[3],MAT[2]->M_V[0].V[4],MAT[2]->M_V[0].V[5],MAT[2]->M_V[0].V[6],MAT[2]->M_V[0].V[7],MAT[2]->M_V[0].V[8],MAT[2]->M_V[0].V[9],MAT[2]->M_V[0].V[10],MAT[2]->M_V[0].V[11],MAT[2]->M_V[0].V[12],MAT[2]->M_V[0].V[13],MAT[2]->M_V[0].V[14],MAT[2]->M_V[0].V[15]);
}

void print_mat2_1()
{
	fprintf(fp_mat2_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[1].V[0],MAT[2]->M_V[1].V[1],MAT[2]->M_V[1].V[2],MAT[2]->M_V[1].V[3],MAT[2]->M_V[1].V[4],MAT[2]->M_V[1].V[5],MAT[2]->M_V[1].V[6],MAT[2]->M_V[1].V[7],MAT[2]->M_V[1].V[8],MAT[2]->M_V[1].V[9],MAT[2]->M_V[1].V[10],MAT[2]->M_V[1].V[11],MAT[2]->M_V[1].V[12],MAT[2]->M_V[1].V[13],MAT[2]->M_V[1].V[14],MAT[2]->M_V[1].V[15]);
}

void print_mat2_2()
{
	fprintf(fp_mat2_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[2].V[0],MAT[2]->M_V[2].V[1],MAT[2]->M_V[2].V[2],MAT[2]->M_V[2].V[3],MAT[2]->M_V[2].V[4],MAT[2]->M_V[2].V[5],MAT[2]->M_V[2].V[6],MAT[2]->M_V[2].V[7],MAT[2]->M_V[2].V[8],MAT[2]->M_V[2].V[9],MAT[2]->M_V[2].V[10],MAT[2]->M_V[2].V[11],MAT[2]->M_V[2].V[12],MAT[2]->M_V[2].V[13],MAT[2]->M_V[2].V[14],MAT[2]->M_V[2].V[15]);
}

void print_mat2_3()
{
	fprintf(fp_mat2_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[3].V[0],MAT[2]->M_V[3].V[1],MAT[2]->M_V[3].V[2],MAT[2]->M_V[3].V[3],MAT[2]->M_V[3].V[4],MAT[2]->M_V[3].V[5],MAT[2]->M_V[3].V[6],MAT[2]->M_V[3].V[7],MAT[2]->M_V[3].V[8],MAT[2]->M_V[3].V[9],MAT[2]->M_V[3].V[10],MAT[2]->M_V[3].V[11],MAT[2]->M_V[3].V[12],MAT[2]->M_V[3].V[13],MAT[2]->M_V[3].V[14],MAT[2]->M_V[3].V[15]);    
}

void print_mat2_4()
{
	fprintf(fp_mat2_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[4].V[0],MAT[2]->M_V[4].V[1],MAT[2]->M_V[4].V[2],MAT[2]->M_V[4].V[3],MAT[2]->M_V[4].V[4],MAT[2]->M_V[4].V[5],MAT[2]->M_V[4].V[6],MAT[2]->M_V[4].V[7],MAT[2]->M_V[4].V[8],MAT[2]->M_V[4].V[9],MAT[2]->M_V[4].V[10],MAT[2]->M_V[4].V[11],MAT[2]->M_V[4].V[12],MAT[2]->M_V[4].V[13],MAT[2]->M_V[4].V[14],MAT[2]->M_V[4].V[15]);
}

void print_mat2_5()
{
	fprintf(fp_mat2_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[5].V[0],MAT[2]->M_V[5].V[1],MAT[2]->M_V[5].V[2],MAT[2]->M_V[5].V[3],MAT[2]->M_V[5].V[4],MAT[2]->M_V[5].V[5],MAT[2]->M_V[5].V[6],MAT[2]->M_V[5].V[7],MAT[2]->M_V[5].V[8],MAT[2]->M_V[5].V[9],MAT[2]->M_V[5].V[10],MAT[2]->M_V[5].V[11],MAT[2]->M_V[5].V[12],MAT[2]->M_V[5].V[13],MAT[2]->M_V[5].V[14],MAT[2]->M_V[5].V[15]);
}

void print_mat2_6()
{
	fprintf(fp_mat2_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[6].V[0],MAT[2]->M_V[6].V[1],MAT[2]->M_V[6].V[2],MAT[2]->M_V[6].V[3],MAT[2]->M_V[6].V[4],MAT[2]->M_V[6].V[5],MAT[2]->M_V[6].V[6],MAT[2]->M_V[6].V[7],MAT[2]->M_V[6].V[8],MAT[2]->M_V[6].V[9],MAT[2]->M_V[6].V[10],MAT[2]->M_V[6].V[11],MAT[2]->M_V[6].V[12],MAT[2]->M_V[6].V[13],MAT[2]->M_V[6].V[14],MAT[2]->M_V[6].V[15]);
}

void print_mat2_7()
{
	 fprintf(fp_mat2_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[7].V[0],MAT[2]->M_V[7].V[1],MAT[2]->M_V[7].V[2],MAT[2]->M_V[7].V[3],MAT[2]->M_V[7].V[4],MAT[2]->M_V[7].V[5],MAT[2]->M_V[7].V[6],MAT[2]->M_V[7].V[7],MAT[2]->M_V[7].V[8],MAT[2]->M_V[7].V[9],MAT[2]->M_V[7].V[10],MAT[2]->M_V[7].V[11],MAT[2]->M_V[7].V[12],MAT[2]->M_V[7].V[13],MAT[2]->M_V[7].V[14],MAT[2]->M_V[0].V[15]);
}

void print_mat2_8()
{
	fprintf(fp_mat2_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[8].V[0],MAT[2]->M_V[8].V[1],MAT[2]->M_V[8].V[2],MAT[2]->M_V[8].V[3],MAT[2]->M_V[8].V[4],MAT[2]->M_V[8].V[5],MAT[2]->M_V[8].V[6],MAT[2]->M_V[8].V[7],MAT[2]->M_V[8].V[8],MAT[2]->M_V[8].V[9],MAT[2]->M_V[8].V[10],MAT[2]->M_V[8].V[11],MAT[2]->M_V[8].V[12],MAT[2]->M_V[8].V[13],MAT[2]->M_V[8].V[14],MAT[2]->M_V[8].V[15]);
}

void print_mat2_9()
{
	fprintf(fp_mat2_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[9].V[0],MAT[2]->M_V[9].V[1],MAT[2]->M_V[9].V[2],MAT[2]->M_V[9].V[3],MAT[2]->M_V[9].V[4],MAT[2]->M_V[9].V[5],MAT[2]->M_V[9].V[6],MAT[2]->M_V[9].V[7],MAT[2]->M_V[9].V[8],MAT[2]->M_V[9].V[9],MAT[2]->M_V[9].V[10],MAT[2]->M_V[9].V[11],MAT[2]->M_V[9].V[12],MAT[2]->M_V[9].V[13],MAT[2]->M_V[9].V[14],MAT[2]->M_V[9].V[15]);
 
}

void print_mat2_10()
{
	fprintf(fp_mat2_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[10].V[0],MAT[2]->M_V[10].V[1],MAT[2]->M_V[10].V[2],MAT[2]->M_V[10].V[3],MAT[2]->M_V[10].V[4],MAT[2]->M_V[10].V[5],MAT[2]->M_V[10].V[6],MAT[2]->M_V[10].V[7],MAT[2]->M_V[10].V[8],MAT[2]->M_V[10].V[9],MAT[2]->M_V[10].V[10],MAT[2]->M_V[10].V[11],MAT[2]->M_V[10].V[12],MAT[2]->M_V[10].V[13],MAT[2]->M_V[10].V[14],MAT[2]->M_V[10].V[15]);
}

void print_mat2_11()
{
	fprintf(fp_mat2_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[11].V[0],MAT[2]->M_V[11].V[1],MAT[2]->M_V[12].V[2],MAT[2]->M_V[11].V[3],MAT[2]->M_V[11].V[4],MAT[2]->M_V[11].V[5],MAT[2]->M_V[11].V[6],MAT[2]->M_V[11].V[7],MAT[2]->M_V[11].V[8],MAT[2]->M_V[11].V[9],MAT[2]->M_V[11].V[10],MAT[2]->M_V[11].V[11],MAT[2]->M_V[11].V[12],MAT[2]->M_V[11].V[13],MAT[2]->M_V[11].V[14],MAT[2]->M_V[11].V[15]);
}

void print_mat2_12()
{
	fprintf(fp_mat2_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[12].V[0],MAT[2]->M_V[12].V[1],MAT[2]->M_V[13].V[2],MAT[2]->M_V[12].V[3],MAT[2]->M_V[12].V[4],MAT[2]->M_V[12].V[5],MAT[2]->M_V[12].V[6],MAT[2]->M_V[12].V[7],MAT[2]->M_V[12].V[8],MAT[2]->M_V[12].V[9],MAT[2]->M_V[12].V[10],MAT[2]->M_V[12].V[11],MAT[2]->M_V[12].V[12],MAT[2]->M_V[12].V[13],MAT[2]->M_V[12].V[14],MAT[2]->M_V[12].V[15]);
}

void print_mat2_13()
{
	fprintf(fp_mat2_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[13].V[0],MAT[2]->M_V[13].V[1],MAT[2]->M_V[14].V[2],MAT[2]->M_V[13].V[3],MAT[2]->M_V[13].V[4],MAT[2]->M_V[13].V[5],MAT[2]->M_V[13].V[6],MAT[2]->M_V[13].V[7],MAT[2]->M_V[13].V[8],MAT[2]->M_V[13].V[9],MAT[2]->M_V[13].V[10],MAT[2]->M_V[13].V[11],MAT[2]->M_V[13].V[12],MAT[2]->M_V[13].V[13],MAT[2]->M_V[13].V[14],MAT[2]->M_V[13].V[15]);
}

void print_mat2_14()
{
	fprintf(fp_mat2_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[14].V[0],MAT[2]->M_V[14].V[1],MAT[2]->M_V[15].V[2],MAT[2]->M_V[14].V[3],MAT[2]->M_V[14].V[4],MAT[2]->M_V[14].V[5],MAT[2]->M_V[14].V[6],MAT[2]->M_V[14].V[7],MAT[2]->M_V[14].V[8],MAT[2]->M_V[14].V[9],MAT[2]->M_V[14].V[10],MAT[2]->M_V[14].V[11],MAT[2]->M_V[14].V[12],MAT[2]->M_V[14].V[13],MAT[2]->M_V[14].V[14],MAT[2]->M_V[14].V[15]);
}

void print_mat2_15()
{
	 fprintf(fp_mat2_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[2]->M_V[15].V[0],MAT[2]->M_V[15].V[1],MAT[2]->M_V[16].V[2],MAT[2]->M_V[15].V[3],MAT[2]->M_V[15].V[4],MAT[2]->M_V[15].V[5],MAT[2]->M_V[15].V[6],MAT[2]->M_V[15].V[7],MAT[2]->M_V[15].V[8],MAT[2]->M_V[15].V[9],MAT[2]->M_V[15].V[10],MAT[2]->M_V[15].V[11],MAT[2]->M_V[15].V[12],MAT[2]->M_V[15].V[13],MAT[2]->M_V[15].V[14],MAT[2]->M_V[15].V[15]);
}


void print_mat3_0()
{
	fprintf(fp_mat3_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[0].V[0],MAT[3]->M_V[0].V[1],MAT[3]->M_V[0].V[2],MAT[3]->M_V[0].V[3],MAT[3]->M_V[0].V[4],MAT[3]->M_V[0].V[5],MAT[3]->M_V[0].V[6],MAT[3]->M_V[0].V[7],MAT[3]->M_V[0].V[8],MAT[3]->M_V[0].V[9],MAT[3]->M_V[0].V[10],MAT[3]->M_V[0].V[11],MAT[3]->M_V[0].V[12],MAT[3]->M_V[0].V[13],MAT[3]->M_V[0].V[14],MAT[3]->M_V[0].V[15]);
 
}

void print_mat3_1()
{
	fprintf(fp_mat3_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[1].V[0],MAT[3]->M_V[1].V[1],MAT[3]->M_V[1].V[2],MAT[3]->M_V[1].V[3],MAT[3]->M_V[1].V[4],MAT[3]->M_V[1].V[5],MAT[3]->M_V[1].V[6],MAT[3]->M_V[1].V[7],MAT[3]->M_V[1].V[8],MAT[3]->M_V[1].V[9],MAT[3]->M_V[1].V[10],MAT[3]->M_V[1].V[11],MAT[3]->M_V[1].V[12],MAT[3]->M_V[1].V[13],MAT[3]->M_V[1].V[14],MAT[3]->M_V[1].V[15]);
}

void print_mat3_2()
{
	fprintf(fp_mat3_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[2].V[0],MAT[3]->M_V[2].V[1],MAT[3]->M_V[2].V[2],MAT[3]->M_V[2].V[3],MAT[3]->M_V[2].V[4],MAT[3]->M_V[2].V[5],MAT[3]->M_V[2].V[6],MAT[3]->M_V[2].V[7],MAT[3]->M_V[2].V[8],MAT[3]->M_V[2].V[9],MAT[3]->M_V[2].V[10],MAT[3]->M_V[2].V[11],MAT[3]->M_V[2].V[12],MAT[3]->M_V[2].V[13],MAT[3]->M_V[2].V[14],MAT[3]->M_V[2].V[15]);
}

void print_mat3_3()
{
	fprintf(fp_mat3_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[3].V[0],MAT[3]->M_V[3].V[1],MAT[3]->M_V[3].V[2],MAT[3]->M_V[3].V[3],MAT[3]->M_V[3].V[4],MAT[3]->M_V[3].V[5],MAT[3]->M_V[3].V[6],MAT[3]->M_V[3].V[7],MAT[3]->M_V[3].V[8],MAT[3]->M_V[3].V[9],MAT[3]->M_V[3].V[10],MAT[3]->M_V[3].V[11],MAT[3]->M_V[3].V[12],MAT[3]->M_V[3].V[13],MAT[3]->M_V[3].V[14],MAT[3]->M_V[3].V[15]);    
}

void print_mat3_4()
{
	fprintf(fp_mat3_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[4].V[0],MAT[3]->M_V[4].V[1],MAT[3]->M_V[4].V[2],MAT[3]->M_V[4].V[3],MAT[3]->M_V[4].V[4],MAT[3]->M_V[4].V[5],MAT[3]->M_V[4].V[6],MAT[3]->M_V[4].V[7],MAT[3]->M_V[4].V[8],MAT[3]->M_V[4].V[9],MAT[3]->M_V[4].V[10],MAT[3]->M_V[4].V[11],MAT[3]->M_V[4].V[12],MAT[3]->M_V[4].V[13],MAT[3]->M_V[4].V[14],MAT[3]->M_V[4].V[15]);
}

void print_mat3_5()
{
	fprintf(fp_mat3_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[5].V[0],MAT[3]->M_V[5].V[1],MAT[3]->M_V[5].V[2],MAT[3]->M_V[5].V[3],MAT[3]->M_V[5].V[4],MAT[3]->M_V[5].V[5],MAT[3]->M_V[5].V[6],MAT[3]->M_V[5].V[7],MAT[3]->M_V[5].V[8],MAT[3]->M_V[5].V[9],MAT[3]->M_V[5].V[10],MAT[3]->M_V[5].V[11],MAT[3]->M_V[5].V[12],MAT[3]->M_V[5].V[13],MAT[3]->M_V[5].V[14],MAT[3]->M_V[5].V[15]);
}

void print_mat3_6()
{
	fprintf(fp_mat3_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[6].V[0],MAT[3]->M_V[6].V[1],MAT[3]->M_V[6].V[2],MAT[3]->M_V[6].V[3],MAT[3]->M_V[6].V[4],MAT[3]->M_V[6].V[5],MAT[3]->M_V[6].V[6],MAT[3]->M_V[6].V[7],MAT[3]->M_V[6].V[8],MAT[3]->M_V[6].V[9],MAT[3]->M_V[6].V[10],MAT[3]->M_V[6].V[11],MAT[3]->M_V[6].V[12],MAT[3]->M_V[6].V[13],MAT[3]->M_V[6].V[14],MAT[3]->M_V[6].V[15]);
}

void print_mat3_7()
{
	fprintf(fp_mat3_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[7].V[0],MAT[3]->M_V[7].V[1],MAT[3]->M_V[7].V[2],MAT[3]->M_V[7].V[3],MAT[3]->M_V[7].V[4],MAT[3]->M_V[7].V[5],MAT[3]->M_V[7].V[6],MAT[3]->M_V[7].V[7],MAT[3]->M_V[7].V[8],MAT[3]->M_V[7].V[9],MAT[3]->M_V[7].V[10],MAT[3]->M_V[7].V[11],MAT[3]->M_V[7].V[12],MAT[3]->M_V[7].V[13],MAT[3]->M_V[7].V[14],MAT[3]->M_V[0].V[15]);
}

void print_mat3_8()
{
	fprintf(fp_mat3_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[8].V[0],MAT[3]->M_V[8].V[1],MAT[3]->M_V[8].V[2],MAT[3]->M_V[8].V[3],MAT[3]->M_V[8].V[4],MAT[3]->M_V[8].V[5],MAT[3]->M_V[8].V[6],MAT[3]->M_V[8].V[7],MAT[3]->M_V[8].V[8],MAT[3]->M_V[8].V[9],MAT[3]->M_V[8].V[10],MAT[3]->M_V[8].V[11],MAT[3]->M_V[8].V[12],MAT[3]->M_V[8].V[13],MAT[3]->M_V[8].V[14],MAT[3]->M_V[8].V[15]);
}

void print_mat3_9()
{
	fprintf(fp_mat3_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[9].V[0],MAT[3]->M_V[9].V[1],MAT[3]->M_V[9].V[2],MAT[3]->M_V[9].V[3],MAT[3]->M_V[9].V[4],MAT[3]->M_V[9].V[5],MAT[3]->M_V[9].V[6],MAT[3]->M_V[9].V[7],MAT[3]->M_V[9].V[8],MAT[3]->M_V[9].V[9],MAT[3]->M_V[9].V[10],MAT[3]->M_V[9].V[11],MAT[3]->M_V[9].V[12],MAT[3]->M_V[9].V[13],MAT[3]->M_V[9].V[14],MAT[3]->M_V[9].V[15]);
}

void print_mat3_10()
{
	fprintf(fp_mat3_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[10].V[0],MAT[3]->M_V[10].V[1],MAT[3]->M_V[10].V[2],MAT[3]->M_V[10].V[3],MAT[3]->M_V[10].V[4],MAT[3]->M_V[10].V[5],MAT[3]->M_V[10].V[6],MAT[3]->M_V[10].V[7],MAT[3]->M_V[10].V[8],MAT[3]->M_V[10].V[9],MAT[3]->M_V[10].V[10],MAT[3]->M_V[10].V[11],MAT[3]->M_V[10].V[12],MAT[3]->M_V[10].V[13],MAT[3]->M_V[10].V[14],MAT[3]->M_V[10].V[15]);
}

void print_mat3_11()
{
	fprintf(fp_mat3_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[11].V[0],MAT[3]->M_V[11].V[1],MAT[3]->M_V[12].V[2],MAT[3]->M_V[11].V[3],MAT[3]->M_V[11].V[4],MAT[3]->M_V[11].V[5],MAT[3]->M_V[11].V[6],MAT[3]->M_V[11].V[7],MAT[3]->M_V[11].V[8],MAT[3]->M_V[11].V[9],MAT[3]->M_V[11].V[10],MAT[3]->M_V[11].V[11],MAT[3]->M_V[11].V[12],MAT[3]->M_V[11].V[13],MAT[3]->M_V[11].V[14],MAT[3]->M_V[11].V[15]);
}

void print_mat3_12()
{
	fprintf(fp_mat3_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[12].V[0],MAT[3]->M_V[12].V[1],MAT[3]->M_V[13].V[2],MAT[3]->M_V[12].V[3],MAT[3]->M_V[12].V[4],MAT[3]->M_V[12].V[5],MAT[3]->M_V[12].V[6],MAT[3]->M_V[12].V[7],MAT[3]->M_V[12].V[8],MAT[3]->M_V[12].V[9],MAT[3]->M_V[12].V[10],MAT[3]->M_V[12].V[11],MAT[3]->M_V[12].V[12],MAT[3]->M_V[12].V[13],MAT[3]->M_V[12].V[14],MAT[3]->M_V[12].V[15]);
}

void print_mat3_13()
{
	fprintf(fp_mat3_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[13].V[0],MAT[3]->M_V[13].V[1],MAT[3]->M_V[14].V[2],MAT[3]->M_V[13].V[3],MAT[3]->M_V[13].V[4],MAT[3]->M_V[13].V[5],MAT[3]->M_V[13].V[6],MAT[3]->M_V[13].V[7],MAT[3]->M_V[13].V[8],MAT[3]->M_V[13].V[9],MAT[3]->M_V[13].V[10],MAT[3]->M_V[13].V[11],MAT[3]->M_V[13].V[12],MAT[3]->M_V[13].V[13],MAT[3]->M_V[13].V[14],MAT[3]->M_V[13].V[15]);
}

void print_mat3_14()
{
	fprintf(fp_mat3_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[14].V[0],MAT[3]->M_V[14].V[1],MAT[3]->M_V[15].V[2],MAT[3]->M_V[14].V[3],MAT[3]->M_V[14].V[4],MAT[3]->M_V[14].V[5],MAT[3]->M_V[14].V[6],MAT[3]->M_V[14].V[7],MAT[3]->M_V[14].V[8],MAT[3]->M_V[14].V[9],MAT[3]->M_V[14].V[10],MAT[3]->M_V[14].V[11],MAT[3]->M_V[14].V[12],MAT[3]->M_V[14].V[13],MAT[3]->M_V[14].V[14],MAT[3]->M_V[14].V[15]);
}

void print_mat3_15()
{
	fprintf(fp_mat3_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[3]->M_V[15].V[0],MAT[3]->M_V[15].V[1],MAT[3]->M_V[16].V[2],MAT[3]->M_V[15].V[3],MAT[3]->M_V[15].V[4],MAT[3]->M_V[15].V[5],MAT[3]->M_V[15].V[6],MAT[3]->M_V[15].V[7],MAT[3]->M_V[15].V[8],MAT[3]->M_V[15].V[9],MAT[3]->M_V[15].V[10],MAT[3]->M_V[15].V[11],MAT[3]->M_V[15].V[12],MAT[3]->M_V[15].V[13],MAT[3]->M_V[15].V[14],MAT[3]->M_V[15].V[15]);
}


void print_mat4_0()
{
	fprintf(fp_mat4_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[0].V[0],MAT[4]->M_V[0].V[1],MAT[4]->M_V[0].V[2],MAT[4]->M_V[0].V[3],MAT[4]->M_V[0].V[4],MAT[4]->M_V[0].V[5],MAT[4]->M_V[0].V[6],MAT[4]->M_V[0].V[7],MAT[4]->M_V[0].V[8],MAT[4]->M_V[0].V[9],MAT[4]->M_V[0].V[10],MAT[4]->M_V[0].V[11],MAT[4]->M_V[0].V[12],MAT[4]->M_V[0].V[13],MAT[4]->M_V[0].V[14],MAT[4]->M_V[0].V[15]);
}

void print_mat4_1()
{
	fprintf(fp_mat4_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[1].V[0],MAT[4]->M_V[1].V[1],MAT[4]->M_V[1].V[2],MAT[4]->M_V[1].V[3],MAT[4]->M_V[1].V[4],MAT[4]->M_V[1].V[5],MAT[4]->M_V[1].V[6],MAT[4]->M_V[1].V[7],MAT[4]->M_V[1].V[8],MAT[4]->M_V[1].V[9],MAT[4]->M_V[1].V[10],MAT[4]->M_V[1].V[11],MAT[4]->M_V[1].V[12],MAT[4]->M_V[1].V[13],MAT[4]->M_V[1].V[14],MAT[4]->M_V[1].V[15]);
}

void print_mat4_2()
{
	fprintf(fp_mat4_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[2].V[0],MAT[4]->M_V[2].V[1],MAT[4]->M_V[2].V[2],MAT[4]->M_V[2].V[3],MAT[4]->M_V[2].V[4],MAT[4]->M_V[2].V[5],MAT[4]->M_V[2].V[6],MAT[4]->M_V[2].V[7],MAT[4]->M_V[2].V[8],MAT[4]->M_V[2].V[9],MAT[4]->M_V[2].V[10],MAT[4]->M_V[2].V[11],MAT[4]->M_V[2].V[12],MAT[4]->M_V[2].V[13],MAT[4]->M_V[2].V[14],MAT[4]->M_V[2].V[15]);
}

void print_mat4_3()
{
	fprintf(fp_mat4_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[3].V[0],MAT[4]->M_V[3].V[1],MAT[4]->M_V[3].V[2],MAT[4]->M_V[3].V[3],MAT[4]->M_V[3].V[4],MAT[4]->M_V[3].V[5],MAT[4]->M_V[3].V[6],MAT[4]->M_V[3].V[7],MAT[4]->M_V[3].V[8],MAT[4]->M_V[3].V[9],MAT[4]->M_V[3].V[10],MAT[4]->M_V[3].V[11],MAT[4]->M_V[3].V[12],MAT[4]->M_V[3].V[13],MAT[4]->M_V[3].V[14],MAT[4]->M_V[3].V[15]);    
}

void print_mat4_4()
{
	fprintf(fp_mat4_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[4].V[0],MAT[4]->M_V[4].V[1],MAT[4]->M_V[4].V[2],MAT[4]->M_V[4].V[3],MAT[4]->M_V[4].V[4],MAT[4]->M_V[4].V[5],MAT[4]->M_V[4].V[6],MAT[4]->M_V[4].V[7],MAT[4]->M_V[4].V[8],MAT[4]->M_V[4].V[9],MAT[4]->M_V[4].V[10],MAT[4]->M_V[4].V[11],MAT[4]->M_V[4].V[12],MAT[4]->M_V[4].V[13],MAT[4]->M_V[4].V[14],MAT[4]->M_V[4].V[15]);
}

void print_mat4_5()
{
	fprintf(fp_mat4_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[5].V[0],MAT[4]->M_V[5].V[1],MAT[4]->M_V[5].V[2],MAT[4]->M_V[5].V[3],MAT[4]->M_V[5].V[4],MAT[4]->M_V[5].V[5],MAT[4]->M_V[5].V[6],MAT[4]->M_V[5].V[7],MAT[4]->M_V[5].V[8],MAT[4]->M_V[5].V[9],MAT[4]->M_V[5].V[10],MAT[4]->M_V[5].V[11],MAT[4]->M_V[5].V[12],MAT[4]->M_V[5].V[13],MAT[4]->M_V[5].V[14],MAT[4]->M_V[5].V[15]);
}

void print_mat4_6()
{
	fprintf(fp_mat4_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[6].V[0],MAT[4]->M_V[6].V[1],MAT[4]->M_V[6].V[2],MAT[4]->M_V[6].V[3],MAT[4]->M_V[6].V[4],MAT[4]->M_V[6].V[5],MAT[4]->M_V[6].V[6],MAT[4]->M_V[6].V[7],MAT[4]->M_V[6].V[8],MAT[4]->M_V[6].V[9],MAT[4]->M_V[6].V[10],MAT[4]->M_V[6].V[11],MAT[4]->M_V[6].V[12],MAT[4]->M_V[6].V[13],MAT[4]->M_V[6].V[14],MAT[4]->M_V[6].V[15]);
}

void print_mat4_7()
{
	fprintf(fp_mat4_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[7].V[0],MAT[4]->M_V[7].V[1],MAT[4]->M_V[7].V[2],MAT[4]->M_V[7].V[3],MAT[4]->M_V[7].V[4],MAT[4]->M_V[7].V[5],MAT[4]->M_V[7].V[6],MAT[4]->M_V[7].V[7],MAT[4]->M_V[7].V[8],MAT[4]->M_V[7].V[9],MAT[4]->M_V[7].V[10],MAT[4]->M_V[7].V[11],MAT[4]->M_V[7].V[12],MAT[4]->M_V[7].V[13],MAT[4]->M_V[7].V[14],MAT[4]->M_V[0].V[15]);
}

void print_mat4_8()
{
	fprintf(fp_mat4_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[8].V[0],MAT[4]->M_V[8].V[1],MAT[4]->M_V[8].V[2],MAT[4]->M_V[8].V[3],MAT[4]->M_V[8].V[4],MAT[4]->M_V[8].V[5],MAT[4]->M_V[8].V[6],MAT[4]->M_V[8].V[7],MAT[4]->M_V[8].V[8],MAT[4]->M_V[8].V[9],MAT[4]->M_V[8].V[10],MAT[4]->M_V[8].V[11],MAT[4]->M_V[8].V[12],MAT[4]->M_V[8].V[13],MAT[4]->M_V[8].V[14],MAT[4]->M_V[8].V[15]);
}

void print_mat4_9()
{
	fprintf(fp_mat4_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[9].V[0],MAT[4]->M_V[9].V[1],MAT[4]->M_V[9].V[2],MAT[4]->M_V[9].V[3],MAT[4]->M_V[9].V[4],MAT[4]->M_V[9].V[5],MAT[4]->M_V[9].V[6],MAT[4]->M_V[9].V[7],MAT[4]->M_V[9].V[8],MAT[4]->M_V[9].V[9],MAT[4]->M_V[9].V[10],MAT[4]->M_V[9].V[11],MAT[4]->M_V[9].V[12],MAT[4]->M_V[9].V[13],MAT[4]->M_V[9].V[14],MAT[4]->M_V[9].V[15]);
}

void print_mat4_10()
{
	fprintf(fp_mat4_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[10].V[0],MAT[4]->M_V[10].V[1],MAT[4]->M_V[10].V[2],MAT[4]->M_V[10].V[3],MAT[4]->M_V[10].V[4],MAT[4]->M_V[10].V[5],MAT[4]->M_V[10].V[6],MAT[4]->M_V[10].V[7],MAT[4]->M_V[10].V[8],MAT[4]->M_V[10].V[9],MAT[4]->M_V[10].V[10],MAT[4]->M_V[10].V[11],MAT[4]->M_V[10].V[12],MAT[4]->M_V[10].V[13],MAT[4]->M_V[10].V[14],MAT[4]->M_V[10].V[15]);
}

void print_mat4_11()
{
	fprintf(fp_mat4_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[11].V[0],MAT[4]->M_V[11].V[1],MAT[4]->M_V[12].V[2],MAT[4]->M_V[11].V[3],MAT[4]->M_V[11].V[4],MAT[4]->M_V[11].V[5],MAT[4]->M_V[11].V[6],MAT[4]->M_V[11].V[7],MAT[4]->M_V[11].V[8],MAT[4]->M_V[11].V[9],MAT[4]->M_V[11].V[10],MAT[4]->M_V[11].V[11],MAT[4]->M_V[11].V[12],MAT[4]->M_V[11].V[13],MAT[4]->M_V[11].V[14],MAT[4]->M_V[11].V[15]);
}

void print_mat4_12()
{
	fprintf(fp_mat4_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[12].V[0],MAT[4]->M_V[12].V[1],MAT[4]->M_V[13].V[2],MAT[4]->M_V[12].V[3],MAT[4]->M_V[12].V[4],MAT[4]->M_V[12].V[5],MAT[4]->M_V[12].V[6],MAT[4]->M_V[12].V[7],MAT[4]->M_V[12].V[8],MAT[4]->M_V[12].V[9],MAT[4]->M_V[12].V[10],MAT[4]->M_V[12].V[11],MAT[4]->M_V[12].V[12],MAT[4]->M_V[12].V[13],MAT[4]->M_V[12].V[14],MAT[4]->M_V[12].V[15]);
}

void print_mat4_13()
{
	fprintf(fp_mat4_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[13].V[0],MAT[4]->M_V[13].V[1],MAT[4]->M_V[14].V[2],MAT[4]->M_V[13].V[3],MAT[4]->M_V[13].V[4],MAT[4]->M_V[13].V[5],MAT[4]->M_V[13].V[6],MAT[4]->M_V[13].V[7],MAT[4]->M_V[13].V[8],MAT[4]->M_V[13].V[9],MAT[4]->M_V[13].V[10],MAT[4]->M_V[13].V[11],MAT[4]->M_V[13].V[12],MAT[4]->M_V[13].V[13],MAT[4]->M_V[13].V[14],MAT[4]->M_V[13].V[15]);
}

void print_mat4_14()
{
	fprintf(fp_mat4_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[14].V[0],MAT[4]->M_V[14].V[1],MAT[4]->M_V[15].V[2],MAT[4]->M_V[14].V[3],MAT[4]->M_V[14].V[4],MAT[4]->M_V[14].V[5],MAT[4]->M_V[14].V[6],MAT[4]->M_V[14].V[7],MAT[4]->M_V[14].V[8],MAT[4]->M_V[14].V[9],MAT[4]->M_V[14].V[10],MAT[4]->M_V[14].V[11],MAT[4]->M_V[14].V[12],MAT[4]->M_V[14].V[13],MAT[4]->M_V[14].V[14],MAT[4]->M_V[14].V[15]);
}

void print_mat4_15()
{
	fprintf(fp_mat4_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[4]->M_V[15].V[0],MAT[4]->M_V[15].V[1],MAT[4]->M_V[16].V[2],MAT[4]->M_V[15].V[3],MAT[4]->M_V[15].V[4],MAT[4]->M_V[15].V[5],MAT[4]->M_V[15].V[6],MAT[4]->M_V[15].V[7],MAT[4]->M_V[15].V[8],MAT[4]->M_V[15].V[9],MAT[4]->M_V[15].V[10],MAT[4]->M_V[15].V[11],MAT[4]->M_V[15].V[12],MAT[4]->M_V[15].V[13],MAT[4]->M_V[15].V[14],MAT[4]->M_V[15].V[15]);
}


void print_mat5_0()
{
	fprintf(fp_mat5_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[0].V[0],MAT[5]->M_V[0].V[1],MAT[5]->M_V[0].V[2],MAT[5]->M_V[0].V[3],MAT[5]->M_V[0].V[4],MAT[5]->M_V[0].V[5],MAT[5]->M_V[0].V[6],MAT[5]->M_V[0].V[7],MAT[5]->M_V[0].V[8],MAT[5]->M_V[0].V[9],MAT[5]->M_V[0].V[10],MAT[5]->M_V[0].V[11],MAT[5]->M_V[0].V[12],MAT[5]->M_V[0].V[13],MAT[5]->M_V[0].V[14],MAT[5]->M_V[0].V[15]);
}

void print_mat5_1()
{
	fprintf(fp_mat5_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[1].V[0],MAT[5]->M_V[1].V[1],MAT[5]->M_V[1].V[2],MAT[5]->M_V[1].V[3],MAT[5]->M_V[1].V[4],MAT[5]->M_V[1].V[5],MAT[5]->M_V[1].V[6],MAT[5]->M_V[1].V[7],MAT[5]->M_V[1].V[8],MAT[5]->M_V[1].V[9],MAT[5]->M_V[1].V[10],MAT[5]->M_V[1].V[11],MAT[5]->M_V[1].V[12],MAT[5]->M_V[1].V[13],MAT[5]->M_V[1].V[14],MAT[5]->M_V[1].V[15]);
}

void print_mat5_2()
{
	fprintf(fp_mat5_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[2].V[0],MAT[5]->M_V[2].V[1],MAT[5]->M_V[2].V[2],MAT[5]->M_V[2].V[3],MAT[5]->M_V[2].V[4],MAT[5]->M_V[2].V[5],MAT[5]->M_V[2].V[6],MAT[5]->M_V[2].V[7],MAT[5]->M_V[2].V[8],MAT[5]->M_V[2].V[9],MAT[5]->M_V[2].V[10],MAT[5]->M_V[2].V[11],MAT[5]->M_V[2].V[12],MAT[5]->M_V[2].V[13],MAT[5]->M_V[2].V[14],MAT[5]->M_V[2].V[15]);
}

void print_mat5_3()
{
	fprintf(fp_mat5_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[3].V[0],MAT[5]->M_V[3].V[1],MAT[5]->M_V[3].V[2],MAT[5]->M_V[3].V[3],MAT[5]->M_V[3].V[4],MAT[5]->M_V[3].V[5],MAT[5]->M_V[3].V[6],MAT[5]->M_V[3].V[7],MAT[5]->M_V[3].V[8],MAT[5]->M_V[3].V[9],MAT[5]->M_V[3].V[10],MAT[5]->M_V[3].V[11],MAT[5]->M_V[3].V[12],MAT[5]->M_V[3].V[13],MAT[5]->M_V[3].V[14],MAT[5]->M_V[3].V[15]);    
}

void print_mat5_4()
{
	fprintf(fp_mat5_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[4].V[0],MAT[5]->M_V[4].V[1],MAT[5]->M_V[4].V[2],MAT[5]->M_V[4].V[3],MAT[5]->M_V[4].V[4],MAT[5]->M_V[4].V[5],MAT[5]->M_V[4].V[6],MAT[5]->M_V[4].V[7],MAT[5]->M_V[4].V[8],MAT[5]->M_V[4].V[9],MAT[5]->M_V[4].V[10],MAT[5]->M_V[4].V[11],MAT[5]->M_V[4].V[12],MAT[5]->M_V[4].V[13],MAT[5]->M_V[4].V[14],MAT[5]->M_V[4].V[15]);
}

void print_mat5_5()
{
	fprintf(fp_mat5_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[5].V[0],MAT[5]->M_V[5].V[1],MAT[5]->M_V[5].V[2],MAT[5]->M_V[5].V[3],MAT[5]->M_V[5].V[4],MAT[5]->M_V[5].V[5],MAT[5]->M_V[5].V[6],MAT[5]->M_V[5].V[7],MAT[5]->M_V[5].V[8],MAT[5]->M_V[5].V[9],MAT[5]->M_V[5].V[10],MAT[5]->M_V[5].V[11],MAT[5]->M_V[5].V[12],MAT[5]->M_V[5].V[13],MAT[5]->M_V[5].V[14],MAT[5]->M_V[5].V[15]);
}

void print_mat5_6()
{
	fprintf(fp_mat5_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[6].V[0],MAT[5]->M_V[6].V[1],MAT[5]->M_V[6].V[2],MAT[5]->M_V[6].V[3],MAT[5]->M_V[6].V[4],MAT[5]->M_V[6].V[5],MAT[5]->M_V[6].V[6],MAT[5]->M_V[6].V[7],MAT[5]->M_V[6].V[8],MAT[5]->M_V[6].V[9],MAT[5]->M_V[6].V[10],MAT[5]->M_V[6].V[11],MAT[5]->M_V[6].V[12],MAT[5]->M_V[6].V[13],MAT[5]->M_V[6].V[14],MAT[5]->M_V[6].V[15]);
}

void print_mat5_7()
{
	fprintf(fp_mat5_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[7].V[0],MAT[5]->M_V[7].V[1],MAT[5]->M_V[7].V[2],MAT[5]->M_V[7].V[3],MAT[5]->M_V[7].V[4],MAT[5]->M_V[7].V[5],MAT[5]->M_V[7].V[6],MAT[5]->M_V[7].V[7],MAT[5]->M_V[7].V[8],MAT[5]->M_V[7].V[9],MAT[5]->M_V[7].V[10],MAT[5]->M_V[7].V[11],MAT[5]->M_V[7].V[12],MAT[5]->M_V[7].V[13],MAT[5]->M_V[7].V[14],MAT[5]->M_V[0].V[15]);
}

void print_mat5_8()
{
	fprintf(fp_mat5_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[8].V[0],MAT[5]->M_V[8].V[1],MAT[5]->M_V[8].V[2],MAT[5]->M_V[8].V[3],MAT[5]->M_V[8].V[4],MAT[5]->M_V[8].V[5],MAT[5]->M_V[8].V[6],MAT[5]->M_V[8].V[7],MAT[5]->M_V[8].V[8],MAT[5]->M_V[8].V[9],MAT[5]->M_V[8].V[10],MAT[5]->M_V[8].V[11],MAT[5]->M_V[8].V[12],MAT[5]->M_V[8].V[13],MAT[5]->M_V[8].V[14],MAT[5]->M_V[8].V[15]);
}

void print_mat5_9()
{
	fprintf(fp_mat5_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[9].V[0],MAT[5]->M_V[9].V[1],MAT[5]->M_V[9].V[2],MAT[5]->M_V[9].V[3],MAT[5]->M_V[9].V[4],MAT[5]->M_V[9].V[5],MAT[5]->M_V[9].V[6],MAT[5]->M_V[9].V[7],MAT[5]->M_V[9].V[8],MAT[5]->M_V[9].V[9],MAT[5]->M_V[9].V[10],MAT[5]->M_V[9].V[11],MAT[5]->M_V[9].V[12],MAT[5]->M_V[9].V[13],MAT[5]->M_V[9].V[14],MAT[5]->M_V[9].V[15]);
}

void print_mat5_10()
{
	fprintf(fp_mat5_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[10].V[0],MAT[5]->M_V[10].V[1],MAT[5]->M_V[10].V[2],MAT[5]->M_V[10].V[3],MAT[5]->M_V[10].V[4],MAT[5]->M_V[10].V[5],MAT[5]->M_V[10].V[6],MAT[5]->M_V[10].V[7],MAT[5]->M_V[10].V[8],MAT[5]->M_V[10].V[9],MAT[5]->M_V[10].V[10],MAT[5]->M_V[10].V[11],MAT[5]->M_V[10].V[12],MAT[5]->M_V[10].V[13],MAT[5]->M_V[10].V[14],MAT[5]->M_V[10].V[15]);
}

void print_mat5_11()
{
	fprintf(fp_mat5_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[11].V[0],MAT[5]->M_V[11].V[1],MAT[5]->M_V[12].V[2],MAT[5]->M_V[11].V[3],MAT[5]->M_V[11].V[4],MAT[5]->M_V[11].V[5],MAT[5]->M_V[11].V[6],MAT[5]->M_V[11].V[7],MAT[5]->M_V[11].V[8],MAT[5]->M_V[11].V[9],MAT[5]->M_V[11].V[10],MAT[5]->M_V[11].V[11],MAT[5]->M_V[11].V[12],MAT[5]->M_V[11].V[13],MAT[5]->M_V[11].V[14],MAT[5]->M_V[11].V[15]);
}

void print_mat5_12()
{
	fprintf(fp_mat5_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[12].V[0],MAT[5]->M_V[12].V[1],MAT[5]->M_V[13].V[2],MAT[5]->M_V[12].V[3],MAT[5]->M_V[12].V[4],MAT[5]->M_V[12].V[5],MAT[5]->M_V[12].V[6],MAT[5]->M_V[12].V[7],MAT[5]->M_V[12].V[8],MAT[5]->M_V[12].V[9],MAT[5]->M_V[12].V[10],MAT[5]->M_V[12].V[11],MAT[5]->M_V[12].V[12],MAT[5]->M_V[12].V[13],MAT[5]->M_V[12].V[14],MAT[5]->M_V[12].V[15]);
}

void print_mat5_13()
{
	fprintf(fp_mat5_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[13].V[0],MAT[5]->M_V[13].V[1],MAT[5]->M_V[14].V[2],MAT[5]->M_V[13].V[3],MAT[5]->M_V[13].V[4],MAT[5]->M_V[13].V[5],MAT[5]->M_V[13].V[6],MAT[5]->M_V[13].V[7],MAT[5]->M_V[13].V[8],MAT[5]->M_V[13].V[9],MAT[5]->M_V[13].V[10],MAT[5]->M_V[13].V[11],MAT[5]->M_V[13].V[12],MAT[5]->M_V[13].V[13],MAT[5]->M_V[13].V[14],MAT[5]->M_V[13].V[15]);
}

void print_mat5_14()
{
	fprintf(fp_mat5_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[14].V[0],MAT[5]->M_V[14].V[1],MAT[5]->M_V[15].V[2],MAT[5]->M_V[14].V[3],MAT[5]->M_V[14].V[4],MAT[5]->M_V[14].V[5],MAT[5]->M_V[14].V[6],MAT[5]->M_V[14].V[7],MAT[5]->M_V[14].V[8],MAT[5]->M_V[14].V[9],MAT[5]->M_V[14].V[10],MAT[5]->M_V[14].V[11],MAT[5]->M_V[14].V[12],MAT[5]->M_V[14].V[13],MAT[5]->M_V[14].V[14],MAT[5]->M_V[14].V[15]);
}

void print_mat5_15()
{
	fprintf(fp_mat5_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[5]->M_V[15].V[0],MAT[5]->M_V[15].V[1],MAT[5]->M_V[16].V[2],MAT[5]->M_V[15].V[3],MAT[5]->M_V[15].V[4],MAT[5]->M_V[15].V[5],MAT[5]->M_V[15].V[6],MAT[5]->M_V[15].V[7],MAT[5]->M_V[15].V[8],MAT[5]->M_V[15].V[9],MAT[5]->M_V[15].V[10],MAT[5]->M_V[15].V[11],MAT[5]->M_V[15].V[12],MAT[5]->M_V[15].V[13],MAT[5]->M_V[15].V[14],MAT[5]->M_V[15].V[15]);
}


void print_mat6_0()
{
	fprintf(fp_mat6_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[0].V[0],MAT[6]->M_V[0].V[1],MAT[6]->M_V[0].V[2],MAT[6]->M_V[0].V[3],MAT[6]->M_V[0].V[4],MAT[6]->M_V[0].V[5],MAT[6]->M_V[0].V[6],MAT[6]->M_V[0].V[7],MAT[6]->M_V[0].V[8],MAT[6]->M_V[0].V[9],MAT[6]->M_V[0].V[10],MAT[6]->M_V[0].V[11],MAT[6]->M_V[0].V[12],MAT[6]->M_V[0].V[13],MAT[6]->M_V[0].V[14],MAT[6]->M_V[0].V[15]);
}

void print_mat6_1()
{
	fprintf(fp_mat6_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[1].V[0],MAT[6]->M_V[1].V[1],MAT[6]->M_V[1].V[2],MAT[6]->M_V[1].V[3],MAT[6]->M_V[1].V[4],MAT[6]->M_V[1].V[5],MAT[6]->M_V[1].V[6],MAT[6]->M_V[1].V[7],MAT[6]->M_V[1].V[8],MAT[6]->M_V[1].V[9],MAT[6]->M_V[1].V[10],MAT[6]->M_V[1].V[11],MAT[6]->M_V[1].V[12],MAT[6]->M_V[1].V[13],MAT[6]->M_V[1].V[14],MAT[6]->M_V[1].V[15]);
}

void print_mat6_2()
{
	fprintf(fp_mat6_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[2].V[0],MAT[6]->M_V[2].V[1],MAT[6]->M_V[2].V[2],MAT[6]->M_V[2].V[3],MAT[6]->M_V[2].V[4],MAT[6]->M_V[2].V[5],MAT[6]->M_V[2].V[6],MAT[6]->M_V[2].V[7],MAT[6]->M_V[2].V[8],MAT[6]->M_V[2].V[9],MAT[6]->M_V[2].V[10],MAT[6]->M_V[2].V[11],MAT[6]->M_V[2].V[12],MAT[6]->M_V[2].V[13],MAT[6]->M_V[2].V[14],MAT[6]->M_V[2].V[15]);
}

void print_mat6_3()
{
	fprintf(fp_mat6_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[3].V[0],MAT[6]->M_V[3].V[1],MAT[6]->M_V[3].V[2],MAT[6]->M_V[3].V[3],MAT[6]->M_V[3].V[4],MAT[6]->M_V[3].V[5],MAT[6]->M_V[3].V[6],MAT[6]->M_V[3].V[7],MAT[6]->M_V[3].V[8],MAT[6]->M_V[3].V[9],MAT[6]->M_V[3].V[10],MAT[6]->M_V[3].V[11],MAT[6]->M_V[3].V[12],MAT[6]->M_V[3].V[13],MAT[6]->M_V[3].V[14],MAT[6]->M_V[3].V[15]);    
}

void print_mat6_4()
{
	fprintf(fp_mat6_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[4].V[0],MAT[6]->M_V[4].V[1],MAT[6]->M_V[4].V[2],MAT[6]->M_V[4].V[3],MAT[6]->M_V[4].V[4],MAT[6]->M_V[4].V[5],MAT[6]->M_V[4].V[6],MAT[6]->M_V[4].V[7],MAT[6]->M_V[4].V[8],MAT[6]->M_V[4].V[9],MAT[6]->M_V[4].V[10],MAT[6]->M_V[4].V[11],MAT[6]->M_V[4].V[12],MAT[6]->M_V[4].V[13],MAT[6]->M_V[4].V[14],MAT[6]->M_V[4].V[15]);
}

void print_mat6_5()
{
	fprintf(fp_mat6_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[5].V[0],MAT[6]->M_V[5].V[1],MAT[6]->M_V[5].V[2],MAT[6]->M_V[5].V[3],MAT[6]->M_V[5].V[4],MAT[6]->M_V[5].V[5],MAT[6]->M_V[5].V[6],MAT[6]->M_V[5].V[7],MAT[6]->M_V[5].V[8],MAT[6]->M_V[5].V[9],MAT[6]->M_V[5].V[10],MAT[6]->M_V[5].V[11],MAT[6]->M_V[5].V[12],MAT[6]->M_V[5].V[13],MAT[6]->M_V[5].V[14],MAT[6]->M_V[5].V[15]);
}

void print_mat6_6()
{
	 fprintf(fp_mat6_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[6].V[0],MAT[6]->M_V[6].V[1],MAT[6]->M_V[6].V[2],MAT[6]->M_V[6].V[3],MAT[6]->M_V[6].V[4],MAT[6]->M_V[6].V[5],MAT[6]->M_V[6].V[6],MAT[6]->M_V[6].V[7],MAT[6]->M_V[6].V[8],MAT[6]->M_V[6].V[9],MAT[6]->M_V[6].V[10],MAT[6]->M_V[6].V[11],MAT[6]->M_V[6].V[12],MAT[6]->M_V[6].V[13],MAT[6]->M_V[6].V[14],MAT[6]->M_V[6].V[15]);
}

void print_mat6_7()
{
	fprintf(fp_mat6_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[7].V[0],MAT[6]->M_V[7].V[1],MAT[6]->M_V[7].V[2],MAT[6]->M_V[7].V[3],MAT[6]->M_V[7].V[4],MAT[6]->M_V[7].V[5],MAT[6]->M_V[7].V[6],MAT[6]->M_V[7].V[7],MAT[6]->M_V[7].V[8],MAT[6]->M_V[7].V[9],MAT[6]->M_V[7].V[10],MAT[6]->M_V[7].V[11],MAT[6]->M_V[7].V[12],MAT[6]->M_V[7].V[13],MAT[6]->M_V[7].V[14],MAT[6]->M_V[0].V[15]);
}

void print_mat6_8()
{
	fprintf(fp_mat6_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[8].V[0],MAT[6]->M_V[8].V[1],MAT[6]->M_V[8].V[2],MAT[6]->M_V[8].V[3],MAT[6]->M_V[8].V[4],MAT[6]->M_V[8].V[5],MAT[6]->M_V[8].V[6],MAT[6]->M_V[8].V[7],MAT[6]->M_V[8].V[8],MAT[6]->M_V[8].V[9],MAT[6]->M_V[8].V[10],MAT[6]->M_V[8].V[11],MAT[6]->M_V[8].V[12],MAT[6]->M_V[8].V[13],MAT[6]->M_V[8].V[14],MAT[6]->M_V[8].V[15]);
}

void print_mat6_9()
{
	fprintf(fp_mat6_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[9].V[0],MAT[6]->M_V[9].V[1],MAT[6]->M_V[9].V[2],MAT[6]->M_V[9].V[3],MAT[6]->M_V[9].V[4],MAT[6]->M_V[9].V[5],MAT[6]->M_V[9].V[6],MAT[6]->M_V[9].V[7],MAT[6]->M_V[9].V[8],MAT[6]->M_V[9].V[9],MAT[6]->M_V[9].V[10],MAT[6]->M_V[9].V[11],MAT[6]->M_V[9].V[12],MAT[6]->M_V[9].V[13],MAT[6]->M_V[9].V[14],MAT[6]->M_V[9].V[15]);
}

void print_mat6_10()
{
	fprintf(fp_mat6_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[10].V[0],MAT[6]->M_V[10].V[1],MAT[6]->M_V[10].V[2],MAT[6]->M_V[10].V[3],MAT[6]->M_V[10].V[4],MAT[6]->M_V[10].V[5],MAT[6]->M_V[10].V[6],MAT[6]->M_V[10].V[7],MAT[6]->M_V[10].V[8],MAT[6]->M_V[10].V[9],MAT[6]->M_V[10].V[10],MAT[6]->M_V[10].V[11],MAT[6]->M_V[10].V[12],MAT[6]->M_V[10].V[13],MAT[6]->M_V[10].V[14],MAT[6]->M_V[10].V[15]);
}

void print_mat6_11()
{
	fprintf(fp_mat6_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[11].V[0],MAT[6]->M_V[11].V[1],MAT[6]->M_V[12].V[2],MAT[6]->M_V[11].V[3],MAT[6]->M_V[11].V[4],MAT[6]->M_V[11].V[5],MAT[6]->M_V[11].V[6],MAT[6]->M_V[11].V[7],MAT[6]->M_V[11].V[8],MAT[6]->M_V[11].V[9],MAT[6]->M_V[11].V[10],MAT[6]->M_V[11].V[11],MAT[6]->M_V[11].V[12],MAT[6]->M_V[11].V[13],MAT[6]->M_V[11].V[14],MAT[6]->M_V[11].V[15]);
}

void print_mat6_12()
{
	 fprintf(fp_mat6_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[12].V[0],MAT[6]->M_V[12].V[1],MAT[6]->M_V[13].V[2],MAT[6]->M_V[12].V[3],MAT[6]->M_V[12].V[4],MAT[6]->M_V[12].V[5],MAT[6]->M_V[12].V[6],MAT[6]->M_V[12].V[7],MAT[6]->M_V[12].V[8],MAT[6]->M_V[12].V[9],MAT[6]->M_V[12].V[10],MAT[6]->M_V[12].V[11],MAT[6]->M_V[12].V[12],MAT[6]->M_V[12].V[13],MAT[6]->M_V[12].V[14],MAT[6]->M_V[12].V[15]);
}

void print_mat6_13()
{
	fprintf(fp_mat6_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[13].V[0],MAT[6]->M_V[13].V[1],MAT[6]->M_V[14].V[2],MAT[6]->M_V[13].V[3],MAT[6]->M_V[13].V[4],MAT[6]->M_V[13].V[5],MAT[6]->M_V[13].V[6],MAT[6]->M_V[13].V[7],MAT[6]->M_V[13].V[8],MAT[6]->M_V[13].V[9],MAT[6]->M_V[13].V[10],MAT[6]->M_V[13].V[11],MAT[6]->M_V[13].V[12],MAT[6]->M_V[13].V[13],MAT[6]->M_V[13].V[14],MAT[6]->M_V[13].V[15]);
}

void print_mat6_14()
{
	fprintf(fp_mat6_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[14].V[0],MAT[6]->M_V[14].V[1],MAT[6]->M_V[15].V[2],MAT[6]->M_V[14].V[3],MAT[6]->M_V[14].V[4],MAT[6]->M_V[14].V[5],MAT[6]->M_V[14].V[6],MAT[6]->M_V[14].V[7],MAT[6]->M_V[14].V[8],MAT[6]->M_V[14].V[9],MAT[6]->M_V[14].V[10],MAT[6]->M_V[14].V[11],MAT[6]->M_V[14].V[12],MAT[6]->M_V[14].V[13],MAT[6]->M_V[14].V[14],MAT[6]->M_V[14].V[15]);
}

void print_mat6_15()
{
	fprintf(fp_mat6_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[6]->M_V[15].V[0],MAT[6]->M_V[15].V[1],MAT[6]->M_V[16].V[2],MAT[6]->M_V[15].V[3],MAT[6]->M_V[15].V[4],MAT[6]->M_V[15].V[5],MAT[6]->M_V[15].V[6],MAT[6]->M_V[15].V[7],MAT[6]->M_V[15].V[8],MAT[6]->M_V[15].V[9],MAT[6]->M_V[15].V[10],MAT[6]->M_V[15].V[11],MAT[6]->M_V[15].V[12],MAT[6]->M_V[15].V[13],MAT[6]->M_V[15].V[14],MAT[6]->M_V[15].V[15]);
}


void print_mat7_0()
{
	fprintf(fp_mat7_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[0].V[0],MAT[7]->M_V[0].V[1],MAT[7]->M_V[0].V[2],MAT[7]->M_V[0].V[3],MAT[7]->M_V[0].V[4],MAT[7]->M_V[0].V[5],MAT[7]->M_V[0].V[6],MAT[7]->M_V[0].V[7],MAT[7]->M_V[0].V[8],MAT[7]->M_V[0].V[9],MAT[7]->M_V[0].V[10],MAT[7]->M_V[0].V[11],MAT[7]->M_V[0].V[12],MAT[7]->M_V[0].V[13],MAT[7]->M_V[0].V[14],MAT[7]->M_V[0].V[15]);
 
}

void print_mat7_1()
{
	fprintf(fp_mat7_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[1].V[0],MAT[7]->M_V[1].V[1],MAT[7]->M_V[1].V[2],MAT[7]->M_V[1].V[3],MAT[7]->M_V[1].V[4],MAT[7]->M_V[1].V[5],MAT[7]->M_V[1].V[6],MAT[7]->M_V[1].V[7],MAT[7]->M_V[1].V[8],MAT[7]->M_V[1].V[9],MAT[7]->M_V[1].V[10],MAT[7]->M_V[1].V[11],MAT[7]->M_V[1].V[12],MAT[7]->M_V[1].V[13],MAT[7]->M_V[1].V[14],MAT[7]->M_V[1].V[15]);
}

void print_mat7_2()
{
	fprintf(fp_mat7_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[2].V[0],MAT[7]->M_V[2].V[1],MAT[7]->M_V[2].V[2],MAT[7]->M_V[2].V[3],MAT[7]->M_V[2].V[4],MAT[7]->M_V[2].V[5],MAT[7]->M_V[2].V[6],MAT[7]->M_V[2].V[7],MAT[7]->M_V[2].V[8],MAT[7]->M_V[2].V[9],MAT[7]->M_V[2].V[10],MAT[7]->M_V[2].V[11],MAT[7]->M_V[2].V[12],MAT[7]->M_V[2].V[13],MAT[7]->M_V[2].V[14],MAT[7]->M_V[2].V[15]);
}

void print_mat7_3()
{
	fprintf(fp_mat7_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[3].V[0],MAT[7]->M_V[3].V[1],MAT[7]->M_V[3].V[2],MAT[7]->M_V[3].V[3],MAT[7]->M_V[3].V[4],MAT[7]->M_V[3].V[5],MAT[7]->M_V[3].V[6],MAT[7]->M_V[3].V[7],MAT[7]->M_V[3].V[8],MAT[7]->M_V[3].V[9],MAT[7]->M_V[3].V[10],MAT[7]->M_V[3].V[11],MAT[7]->M_V[3].V[12],MAT[7]->M_V[3].V[13],MAT[7]->M_V[3].V[14],MAT[7]->M_V[3].V[15]);    
}

void print_mat7_4()
{
	fprintf(fp_mat7_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[4].V[0],MAT[7]->M_V[4].V[1],MAT[7]->M_V[4].V[2],MAT[7]->M_V[4].V[3],MAT[7]->M_V[4].V[4],MAT[7]->M_V[4].V[5],MAT[7]->M_V[4].V[6],MAT[7]->M_V[4].V[7],MAT[7]->M_V[4].V[8],MAT[7]->M_V[4].V[9],MAT[7]->M_V[4].V[10],MAT[7]->M_V[4].V[11],MAT[7]->M_V[4].V[12],MAT[7]->M_V[4].V[13],MAT[7]->M_V[4].V[14],MAT[7]->M_V[4].V[15]);
}

void print_mat7_5()
{
	 fprintf(fp_mat7_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[5].V[0],MAT[7]->M_V[5].V[1],MAT[7]->M_V[5].V[2],MAT[7]->M_V[5].V[3],MAT[7]->M_V[5].V[4],MAT[7]->M_V[5].V[5],MAT[7]->M_V[5].V[6],MAT[7]->M_V[5].V[7],MAT[7]->M_V[5].V[8],MAT[7]->M_V[5].V[9],MAT[7]->M_V[5].V[10],MAT[7]->M_V[5].V[11],MAT[7]->M_V[5].V[12],MAT[7]->M_V[5].V[13],MAT[7]->M_V[5].V[14],MAT[7]->M_V[5].V[15]);
}

void print_mat7_6()
{
	fprintf(fp_mat7_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[6].V[0],MAT[7]->M_V[6].V[1],MAT[7]->M_V[6].V[2],MAT[7]->M_V[6].V[3],MAT[7]->M_V[6].V[4],MAT[7]->M_V[6].V[5],MAT[7]->M_V[6].V[6],MAT[7]->M_V[6].V[7],MAT[7]->M_V[6].V[8],MAT[7]->M_V[6].V[9],MAT[7]->M_V[6].V[10],MAT[7]->M_V[6].V[11],MAT[7]->M_V[6].V[12],MAT[7]->M_V[6].V[13],MAT[7]->M_V[6].V[14],MAT[7]->M_V[6].V[15]);
}

void print_mat7_7()
{
	fprintf(fp_mat7_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[7].V[0],MAT[7]->M_V[7].V[1],MAT[7]->M_V[7].V[2],MAT[7]->M_V[7].V[3],MAT[7]->M_V[7].V[4],MAT[7]->M_V[7].V[5],MAT[7]->M_V[7].V[6],MAT[7]->M_V[7].V[7],MAT[7]->M_V[7].V[8],MAT[7]->M_V[7].V[9],MAT[7]->M_V[7].V[10],MAT[7]->M_V[7].V[11],MAT[7]->M_V[7].V[12],MAT[7]->M_V[7].V[13],MAT[7]->M_V[7].V[14],MAT[7]->M_V[0].V[15]);
}

void print_mat7_8()
{
	fprintf(fp_mat7_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[8].V[0],MAT[7]->M_V[8].V[1],MAT[7]->M_V[8].V[2],MAT[7]->M_V[8].V[3],MAT[7]->M_V[8].V[4],MAT[7]->M_V[8].V[5],MAT[7]->M_V[8].V[6],MAT[7]->M_V[8].V[7],MAT[7]->M_V[8].V[8],MAT[7]->M_V[8].V[9],MAT[7]->M_V[8].V[10],MAT[7]->M_V[8].V[11],MAT[7]->M_V[8].V[12],MAT[7]->M_V[8].V[13],MAT[7]->M_V[8].V[14],MAT[7]->M_V[8].V[15]);
}

void print_mat7_9()
{
	fprintf(fp_mat7_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[9].V[0],MAT[7]->M_V[9].V[1],MAT[7]->M_V[9].V[2],MAT[7]->M_V[9].V[3],MAT[7]->M_V[9].V[4],MAT[7]->M_V[9].V[5],MAT[7]->M_V[9].V[6],MAT[7]->M_V[9].V[7],MAT[7]->M_V[9].V[8],MAT[7]->M_V[9].V[9],MAT[7]->M_V[9].V[10],MAT[7]->M_V[9].V[11],MAT[7]->M_V[9].V[12],MAT[7]->M_V[9].V[13],MAT[7]->M_V[9].V[14],MAT[7]->M_V[9].V[15]);
}

void print_mat7_10()
{
	fprintf(fp_mat7_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[10].V[0],MAT[7]->M_V[10].V[1],MAT[7]->M_V[10].V[2],MAT[7]->M_V[10].V[3],MAT[7]->M_V[10].V[4],MAT[7]->M_V[10].V[5],MAT[7]->M_V[10].V[6],MAT[7]->M_V[10].V[7],MAT[7]->M_V[10].V[8],MAT[7]->M_V[10].V[9],MAT[7]->M_V[10].V[10],MAT[7]->M_V[10].V[11],MAT[7]->M_V[10].V[12],MAT[7]->M_V[10].V[13],MAT[7]->M_V[10].V[14],MAT[7]->M_V[10].V[15]);
}

void print_mat7_11()
{
	fprintf(fp_mat7_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[11].V[0],MAT[7]->M_V[11].V[1],MAT[7]->M_V[12].V[2],MAT[7]->M_V[11].V[3],MAT[7]->M_V[11].V[4],MAT[7]->M_V[11].V[5],MAT[7]->M_V[11].V[6],MAT[7]->M_V[11].V[7],MAT[7]->M_V[11].V[8],MAT[7]->M_V[11].V[9],MAT[7]->M_V[11].V[10],MAT[7]->M_V[11].V[11],MAT[7]->M_V[11].V[12],MAT[7]->M_V[11].V[13],MAT[7]->M_V[11].V[14],MAT[7]->M_V[11].V[15]);
}

void print_mat7_12()
{
	fprintf(fp_mat7_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[12].V[0],MAT[7]->M_V[12].V[1],MAT[7]->M_V[13].V[2],MAT[7]->M_V[12].V[3],MAT[7]->M_V[12].V[4],MAT[7]->M_V[12].V[5],MAT[7]->M_V[12].V[6],MAT[7]->M_V[12].V[7],MAT[7]->M_V[12].V[8],MAT[7]->M_V[12].V[9],MAT[7]->M_V[12].V[10],MAT[7]->M_V[12].V[11],MAT[7]->M_V[12].V[12],MAT[7]->M_V[12].V[13],MAT[7]->M_V[12].V[14],MAT[7]->M_V[12].V[15]);
}

void print_mat7_13()
{
	fprintf(fp_mat7_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[13].V[0],MAT[7]->M_V[13].V[1],MAT[7]->M_V[14].V[2],MAT[7]->M_V[13].V[3],MAT[7]->M_V[13].V[4],MAT[7]->M_V[13].V[5],MAT[7]->M_V[13].V[6],MAT[7]->M_V[13].V[7],MAT[7]->M_V[13].V[8],MAT[7]->M_V[13].V[9],MAT[7]->M_V[13].V[10],MAT[7]->M_V[13].V[11],MAT[7]->M_V[13].V[12],MAT[7]->M_V[13].V[13],MAT[7]->M_V[13].V[14],MAT[7]->M_V[13].V[15]);
}

void print_mat7_14()
{
	fprintf(fp_mat7_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[14].V[0],MAT[7]->M_V[14].V[1],MAT[7]->M_V[15].V[2],MAT[7]->M_V[14].V[3],MAT[7]->M_V[14].V[4],MAT[7]->M_V[14].V[5],MAT[7]->M_V[14].V[6],MAT[7]->M_V[14].V[7],MAT[7]->M_V[14].V[8],MAT[7]->M_V[14].V[9],MAT[7]->M_V[14].V[10],MAT[7]->M_V[14].V[11],MAT[7]->M_V[14].V[12],MAT[7]->M_V[14].V[13],MAT[7]->M_V[14].V[14],MAT[7]->M_V[14].V[15]);
}

void print_mat7_15()
{
	fprintf(fp_mat7_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[7]->M_V[15].V[0],MAT[7]->M_V[15].V[1],MAT[7]->M_V[16].V[2],MAT[7]->M_V[15].V[3],MAT[7]->M_V[15].V[4],MAT[7]->M_V[15].V[5],MAT[7]->M_V[15].V[6],MAT[7]->M_V[15].V[7],MAT[7]->M_V[15].V[8],MAT[7]->M_V[15].V[9],MAT[7]->M_V[15].V[10],MAT[7]->M_V[15].V[11],MAT[7]->M_V[15].V[12],MAT[7]->M_V[15].V[13],MAT[7]->M_V[15].V[14],MAT[7]->M_V[15].V[15]);
}


//void print_mat8_0()
//{
//	fprintf(fp_mat8_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[0].V[0],MAT[8]->M_V[0].V[1],MAT[8]->M_V[0].V[2],MAT[8]->M_V[0].V[3],MAT[8]->M_V[0].V[4],MAT[8]->M_V[0].V[5],MAT[8]->M_V[0].V[6],MAT[8]->M_V[0].V[7],MAT[8]->M_V[0].V[8],MAT[8]->M_V[0].V[9],MAT[8]->M_V[0].V[10],MAT[8]->M_V[0].V[11],MAT[8]->M_V[0].V[12],MAT[8]->M_V[0].V[13],MAT[8]->M_V[0].V[14],MAT[8]->M_V[0].V[15]);
//}
//
//void print_mat8_1()
//{
//	fprintf(fp_mat8_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[1].V[0],MAT[8]->M_V[1].V[1],MAT[8]->M_V[1].V[2],MAT[8]->M_V[1].V[3],MAT[8]->M_V[1].V[4],MAT[8]->M_V[1].V[5],MAT[8]->M_V[1].V[6],MAT[8]->M_V[1].V[7],MAT[8]->M_V[1].V[8],MAT[8]->M_V[1].V[9],MAT[8]->M_V[1].V[10],MAT[8]->M_V[1].V[11],MAT[8]->M_V[1].V[12],MAT[8]->M_V[1].V[13],MAT[8]->M_V[1].V[14],MAT[8]->M_V[1].V[15]);
//}
//
//void print_mat8_2()
//{
//	fprintf(fp_mat8_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[2].V[0],MAT[8]->M_V[2].V[1],MAT[8]->M_V[2].V[2],MAT[8]->M_V[2].V[3],MAT[8]->M_V[2].V[4],MAT[8]->M_V[2].V[5],MAT[8]->M_V[2].V[6],MAT[8]->M_V[2].V[7],MAT[8]->M_V[2].V[8],MAT[8]->M_V[2].V[9],MAT[8]->M_V[2].V[10],MAT[8]->M_V[2].V[11],MAT[8]->M_V[2].V[12],MAT[8]->M_V[2].V[13],MAT[8]->M_V[2].V[14],MAT[8]->M_V[2].V[15]);
//}
//
//void print_mat8_3()
//{
//	fprintf(fp_mat8_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[3].V[0],MAT[8]->M_V[3].V[1],MAT[8]->M_V[3].V[2],MAT[8]->M_V[3].V[3],MAT[8]->M_V[3].V[4],MAT[8]->M_V[3].V[5],MAT[8]->M_V[3].V[6],MAT[8]->M_V[3].V[7],MAT[8]->M_V[3].V[8],MAT[8]->M_V[3].V[9],MAT[8]->M_V[3].V[10],MAT[8]->M_V[3].V[11],MAT[8]->M_V[3].V[12],MAT[8]->M_V[3].V[13],MAT[8]->M_V[3].V[14],MAT[8]->M_V[3].V[15]);    
//}
//
//void print_mat8_4()
//{
//	fprintf(fp_mat8_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[4].V[0],MAT[8]->M_V[4].V[1],MAT[8]->M_V[4].V[2],MAT[8]->M_V[4].V[3],MAT[8]->M_V[4].V[4],MAT[8]->M_V[4].V[5],MAT[8]->M_V[4].V[6],MAT[8]->M_V[4].V[7],MAT[8]->M_V[4].V[8],MAT[8]->M_V[4].V[9],MAT[8]->M_V[4].V[10],MAT[8]->M_V[4].V[11],MAT[8]->M_V[4].V[12],MAT[8]->M_V[4].V[13],MAT[8]->M_V[4].V[14],MAT[8]->M_V[4].V[15]);
//}
//
//void print_mat8_5()
//{
//	fprintf(fp_mat8_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[5].V[0],MAT[8]->M_V[5].V[1],MAT[8]->M_V[5].V[2],MAT[8]->M_V[5].V[3],MAT[8]->M_V[5].V[4],MAT[8]->M_V[5].V[5],MAT[8]->M_V[5].V[6],MAT[8]->M_V[5].V[7],MAT[8]->M_V[5].V[8],MAT[8]->M_V[5].V[9],MAT[8]->M_V[5].V[10],MAT[8]->M_V[5].V[11],MAT[8]->M_V[5].V[12],MAT[8]->M_V[5].V[13],MAT[8]->M_V[5].V[14],MAT[8]->M_V[5].V[15]);
//}
//
//void print_mat8_6()
//{
//	 fprintf(fp_mat8_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[6].V[0],MAT[8]->M_V[6].V[1],MAT[8]->M_V[6].V[2],MAT[8]->M_V[6].V[3],MAT[8]->M_V[6].V[4],MAT[8]->M_V[6].V[5],MAT[8]->M_V[6].V[6],MAT[8]->M_V[6].V[7],MAT[8]->M_V[6].V[8],MAT[8]->M_V[6].V[9],MAT[8]->M_V[6].V[10],MAT[8]->M_V[6].V[11],MAT[8]->M_V[6].V[12],MAT[8]->M_V[6].V[13],MAT[8]->M_V[6].V[14],MAT[8]->M_V[6].V[15]);
//}
//
//void print_mat8_7()
//{
//	fprintf(fp_mat8_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[7].V[0],MAT[8]->M_V[7].V[1],MAT[8]->M_V[7].V[2],MAT[8]->M_V[7].V[3],MAT[8]->M_V[7].V[4],MAT[8]->M_V[7].V[5],MAT[8]->M_V[7].V[6],MAT[8]->M_V[7].V[7],MAT[8]->M_V[7].V[8],MAT[8]->M_V[7].V[9],MAT[8]->M_V[7].V[10],MAT[8]->M_V[7].V[11],MAT[8]->M_V[7].V[12],MAT[8]->M_V[7].V[13],MAT[8]->M_V[7].V[14],MAT[8]->M_V[0].V[15]);
//}
//
//void print_mat8_8()
//{
//	fprintf(fp_mat8_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[8].V[0],MAT[8]->M_V[8].V[1],MAT[8]->M_V[8].V[2],MAT[8]->M_V[8].V[3],MAT[8]->M_V[8].V[4],MAT[8]->M_V[8].V[5],MAT[8]->M_V[8].V[6],MAT[8]->M_V[8].V[7],MAT[8]->M_V[8].V[8],MAT[8]->M_V[8].V[9],MAT[8]->M_V[8].V[10],MAT[8]->M_V[8].V[11],MAT[8]->M_V[8].V[12],MAT[8]->M_V[8].V[13],MAT[8]->M_V[8].V[14],MAT[8]->M_V[8].V[15]);
//}
//
//void print_mat8_9()
//{
//	fprintf(fp_mat8_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[9].V[0],MAT[8]->M_V[9].V[1],MAT[8]->M_V[9].V[2],MAT[8]->M_V[9].V[3],MAT[8]->M_V[9].V[4],MAT[8]->M_V[9].V[5],MAT[8]->M_V[9].V[6],MAT[8]->M_V[9].V[7],MAT[8]->M_V[9].V[8],MAT[8]->M_V[9].V[9],MAT[8]->M_V[9].V[10],MAT[8]->M_V[9].V[11],MAT[8]->M_V[9].V[12],MAT[8]->M_V[9].V[13],MAT[8]->M_V[9].V[14],MAT[8]->M_V[9].V[15]);
//}
//
//void print_mat8_10()
//{
//	fprintf(fp_mat8_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[10].V[0],MAT[8]->M_V[10].V[1],MAT[8]->M_V[10].V[2],MAT[8]->M_V[10].V[3],MAT[8]->M_V[10].V[4],MAT[8]->M_V[10].V[5],MAT[8]->M_V[10].V[6],MAT[8]->M_V[10].V[7],MAT[8]->M_V[10].V[8],MAT[8]->M_V[10].V[9],MAT[8]->M_V[10].V[10],MAT[8]->M_V[10].V[11],MAT[8]->M_V[10].V[12],MAT[8]->M_V[10].V[13],MAT[8]->M_V[10].V[14],MAT[8]->M_V[10].V[15]);
//}
//
//void print_mat8_11()
//{
//	fprintf(fp_mat8_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[11].V[0],MAT[8]->M_V[11].V[1],MAT[8]->M_V[12].V[2],MAT[8]->M_V[11].V[3],MAT[8]->M_V[11].V[4],MAT[8]->M_V[11].V[5],MAT[8]->M_V[11].V[6],MAT[8]->M_V[11].V[7],MAT[8]->M_V[11].V[8],MAT[8]->M_V[11].V[9],MAT[8]->M_V[11].V[10],MAT[8]->M_V[11].V[11],MAT[8]->M_V[11].V[12],MAT[8]->M_V[11].V[13],MAT[8]->M_V[11].V[14],MAT[8]->M_V[11].V[15]);
//}
//
//void print_mat8_12()
//{
//	fprintf(fp_mat8_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[12].V[0],MAT[8]->M_V[12].V[1],MAT[8]->M_V[13].V[2],MAT[8]->M_V[12].V[3],MAT[8]->M_V[12].V[4],MAT[8]->M_V[12].V[5],MAT[8]->M_V[12].V[6],MAT[8]->M_V[12].V[7],MAT[8]->M_V[12].V[8],MAT[8]->M_V[12].V[9],MAT[8]->M_V[12].V[10],MAT[8]->M_V[12].V[11],MAT[8]->M_V[12].V[12],MAT[8]->M_V[12].V[13],MAT[8]->M_V[12].V[14],MAT[8]->M_V[12].V[15]);
//}
//
//void print_mat8_13()
//{
//	fprintf(fp_mat8_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[13].V[0],MAT[8]->M_V[13].V[1],MAT[8]->M_V[14].V[2],MAT[8]->M_V[13].V[3],MAT[8]->M_V[13].V[4],MAT[8]->M_V[13].V[5],MAT[8]->M_V[13].V[6],MAT[8]->M_V[13].V[7],MAT[8]->M_V[13].V[8],MAT[8]->M_V[13].V[9],MAT[8]->M_V[13].V[10],MAT[8]->M_V[13].V[11],MAT[8]->M_V[13].V[12],MAT[8]->M_V[13].V[13],MAT[8]->M_V[13].V[14],MAT[8]->M_V[13].V[15]);
//}
//
//void print_mat8_14()
//{
//	fprintf(fp_mat8_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[14].V[0],MAT[8]->M_V[14].V[1],MAT[8]->M_V[15].V[2],MAT[8]->M_V[14].V[3],MAT[8]->M_V[14].V[4],MAT[8]->M_V[14].V[5],MAT[8]->M_V[14].V[6],MAT[8]->M_V[14].V[7],MAT[8]->M_V[14].V[8],MAT[8]->M_V[14].V[9],MAT[8]->M_V[14].V[10],MAT[8]->M_V[14].V[11],MAT[8]->M_V[14].V[12],MAT[8]->M_V[14].V[13],MAT[8]->M_V[14].V[14],MAT[8]->M_V[14].V[15]);
//}
//
//void print_mat8_15()
//{
//	fprintf(fp_mat8_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[15].V[0],MAT[8]->M_V[15].V[1],MAT[8]->M_V[16].V[2],MAT[8]->M_V[15].V[3],MAT[8]->M_V[15].V[4],MAT[8]->M_V[15].V[5],MAT[8]->M_V[15].V[6],MAT[8]->M_V[15].V[7],MAT[8]->M_V[15].V[8],MAT[8]->M_V[15].V[9],MAT[8]->M_V[15].V[10],MAT[8]->M_V[15].V[11],MAT[8]->M_V[15].V[12],MAT[8]->M_V[15].V[13],MAT[8]->M_V[15].V[14],MAT[8]->M_V[15].V[15]);
//}
//
//
//void print_mat9_0()
//{
//	 fprintf(fp_mat9_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[0].V[0],MAT[9]->M_V[0].V[1],MAT[9]->M_V[0].V[2],MAT[9]->M_V[0].V[3],MAT[9]->M_V[0].V[4],MAT[9]->M_V[0].V[5],MAT[9]->M_V[0].V[6],MAT[9]->M_V[0].V[7],MAT[9]->M_V[0].V[8],MAT[9]->M_V[0].V[9],MAT[9]->M_V[0].V[10],MAT[9]->M_V[0].V[11],MAT[9]->M_V[0].V[12],MAT[9]->M_V[0].V[13],MAT[9]->M_V[0].V[14],MAT[9]->M_V[0].V[15]);
//}
//
//void print_mat9_1()
//{
//	fprintf(fp_mat9_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[1].V[0],MAT[9]->M_V[1].V[1],MAT[9]->M_V[1].V[2],MAT[9]->M_V[1].V[3],MAT[9]->M_V[1].V[4],MAT[9]->M_V[1].V[5],MAT[9]->M_V[1].V[6],MAT[9]->M_V[1].V[7],MAT[9]->M_V[1].V[8],MAT[9]->M_V[1].V[9],MAT[9]->M_V[1].V[10],MAT[9]->M_V[1].V[11],MAT[9]->M_V[1].V[12],MAT[9]->M_V[1].V[13],MAT[9]->M_V[1].V[14],MAT[9]->M_V[1].V[15]);
//}
//
//void print_mat9_2()
//{
//	fprintf(fp_mat9_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[2].V[0],MAT[9]->M_V[2].V[1],MAT[9]->M_V[2].V[2],MAT[9]->M_V[2].V[3],MAT[9]->M_V[2].V[4],MAT[9]->M_V[2].V[5],MAT[9]->M_V[2].V[6],MAT[9]->M_V[2].V[7],MAT[9]->M_V[2].V[8],MAT[9]->M_V[2].V[9],MAT[9]->M_V[2].V[10],MAT[9]->M_V[2].V[11],MAT[9]->M_V[2].V[12],MAT[9]->M_V[2].V[13],MAT[9]->M_V[2].V[14],MAT[9]->M_V[2].V[15]);
//}
//
//void print_mat9_3()
//{
//	 fprintf(fp_mat9_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[3].V[0],MAT[9]->M_V[3].V[1],MAT[9]->M_V[3].V[2],MAT[9]->M_V[3].V[3],MAT[9]->M_V[3].V[4],MAT[9]->M_V[3].V[5],MAT[9]->M_V[3].V[6],MAT[9]->M_V[3].V[7],MAT[9]->M_V[3].V[8],MAT[9]->M_V[3].V[9],MAT[9]->M_V[3].V[10],MAT[9]->M_V[3].V[11],MAT[9]->M_V[3].V[12],MAT[9]->M_V[3].V[13],MAT[9]->M_V[3].V[14],MAT[9]->M_V[3].V[15]);    
//}
//
//void print_mat9_4()
//{
//	fprintf(fp_mat9_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[4].V[0],MAT[9]->M_V[4].V[1],MAT[9]->M_V[4].V[2],MAT[9]->M_V[4].V[3],MAT[9]->M_V[4].V[4],MAT[9]->M_V[4].V[5],MAT[9]->M_V[4].V[6],MAT[9]->M_V[4].V[7],MAT[9]->M_V[4].V[8],MAT[9]->M_V[4].V[9],MAT[9]->M_V[4].V[10],MAT[9]->M_V[4].V[11],MAT[9]->M_V[4].V[12],MAT[9]->M_V[4].V[13],MAT[9]->M_V[4].V[14],MAT[9]->M_V[4].V[15]);
//}
//
//void print_mat9_5()
//{
//	fprintf(fp_mat9_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[5].V[0],MAT[9]->M_V[5].V[1],MAT[9]->M_V[5].V[2],MAT[9]->M_V[5].V[3],MAT[9]->M_V[5].V[4],MAT[9]->M_V[5].V[5],MAT[9]->M_V[5].V[6],MAT[9]->M_V[5].V[7],MAT[9]->M_V[5].V[8],MAT[9]->M_V[5].V[9],MAT[9]->M_V[5].V[10],MAT[9]->M_V[5].V[11],MAT[9]->M_V[5].V[12],MAT[9]->M_V[5].V[13],MAT[9]->M_V[5].V[14],MAT[9]->M_V[5].V[15]);
//}
//
//void print_mat9_6()
//{
//	fprintf(fp_mat9_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[6].V[0],MAT[9]->M_V[6].V[1],MAT[9]->M_V[6].V[2],MAT[9]->M_V[6].V[3],MAT[9]->M_V[6].V[4],MAT[9]->M_V[6].V[5],MAT[9]->M_V[6].V[6],MAT[9]->M_V[6].V[7],MAT[9]->M_V[6].V[8],MAT[9]->M_V[6].V[9],MAT[9]->M_V[6].V[10],MAT[9]->M_V[6].V[11],MAT[9]->M_V[6].V[12],MAT[9]->M_V[6].V[13],MAT[9]->M_V[6].V[14],MAT[9]->M_V[6].V[15]);
//}
//
//void print_mat9_7()
//{
//	 fprintf(fp_mat9_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[7].V[0],MAT[9]->M_V[7].V[1],MAT[9]->M_V[7].V[2],MAT[9]->M_V[7].V[3],MAT[9]->M_V[7].V[4],MAT[9]->M_V[7].V[5],MAT[9]->M_V[7].V[6],MAT[9]->M_V[7].V[7],MAT[9]->M_V[7].V[8],MAT[9]->M_V[7].V[9],MAT[9]->M_V[7].V[10],MAT[9]->M_V[7].V[11],MAT[9]->M_V[7].V[12],MAT[9]->M_V[7].V[13],MAT[9]->M_V[7].V[14],MAT[9]->M_V[0].V[15]);
//}
//
//void print_mat9_8()
//{
//	 fprintf(fp_mat9_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[8].V[0],MAT[9]->M_V[8].V[1],MAT[9]->M_V[8].V[2],MAT[9]->M_V[8].V[3],MAT[9]->M_V[8].V[4],MAT[9]->M_V[8].V[5],MAT[9]->M_V[8].V[6],MAT[9]->M_V[8].V[7],MAT[9]->M_V[8].V[8],MAT[9]->M_V[8].V[9],MAT[9]->M_V[8].V[10],MAT[9]->M_V[8].V[11],MAT[9]->M_V[8].V[12],MAT[9]->M_V[8].V[13],MAT[9]->M_V[8].V[14],MAT[9]->M_V[8].V[15]);
//}
//
//void print_mat9_9()
//{
//	fprintf(fp_mat9_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[9].V[0],MAT[9]->M_V[9].V[1],MAT[9]->M_V[9].V[2],MAT[9]->M_V[9].V[3],MAT[9]->M_V[9].V[4],MAT[9]->M_V[9].V[5],MAT[9]->M_V[9].V[6],MAT[9]->M_V[9].V[7],MAT[9]->M_V[9].V[8],MAT[9]->M_V[9].V[9],MAT[9]->M_V[9].V[10],MAT[9]->M_V[9].V[11],MAT[9]->M_V[9].V[12],MAT[9]->M_V[9].V[13],MAT[9]->M_V[9].V[14],MAT[9]->M_V[9].V[15]);
//}
//
//void print_mat9_10()
//{
//	fprintf(fp_mat9_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[10].V[0],MAT[9]->M_V[10].V[1],MAT[9]->M_V[10].V[2],MAT[9]->M_V[10].V[3],MAT[9]->M_V[10].V[4],MAT[9]->M_V[10].V[5],MAT[9]->M_V[10].V[6],MAT[9]->M_V[10].V[7],MAT[9]->M_V[10].V[8],MAT[9]->M_V[10].V[9],MAT[9]->M_V[10].V[10],MAT[9]->M_V[10].V[11],MAT[9]->M_V[10].V[12],MAT[9]->M_V[10].V[13],MAT[9]->M_V[10].V[14],MAT[9]->M_V[10].V[15]);
//}
//
//void print_mat9_11()
//{
//	fprintf(fp_mat9_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[11].V[0],MAT[9]->M_V[11].V[1],MAT[9]->M_V[12].V[2],MAT[9]->M_V[11].V[3],MAT[9]->M_V[11].V[4],MAT[9]->M_V[11].V[5],MAT[9]->M_V[11].V[6],MAT[9]->M_V[11].V[7],MAT[9]->M_V[11].V[8],MAT[9]->M_V[11].V[9],MAT[9]->M_V[11].V[10],MAT[9]->M_V[11].V[11],MAT[9]->M_V[11].V[12],MAT[9]->M_V[11].V[13],MAT[9]->M_V[11].V[14],MAT[9]->M_V[11].V[15]);
//}
//
//void print_mat9_12()
//{
//	fprintf(fp_mat9_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[12].V[0],MAT[9]->M_V[12].V[1],MAT[9]->M_V[13].V[2],MAT[9]->M_V[12].V[3],MAT[9]->M_V[12].V[4],MAT[9]->M_V[12].V[5],MAT[9]->M_V[12].V[6],MAT[9]->M_V[12].V[7],MAT[9]->M_V[12].V[8],MAT[9]->M_V[12].V[9],MAT[9]->M_V[12].V[10],MAT[9]->M_V[12].V[11],MAT[9]->M_V[12].V[12],MAT[9]->M_V[12].V[13],MAT[9]->M_V[12].V[14],MAT[9]->M_V[12].V[15]);
//}
//
//void print_mat9_13()
//{
//	fprintf(fp_mat9_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[13].V[0],MAT[9]->M_V[13].V[1],MAT[9]->M_V[14].V[2],MAT[9]->M_V[13].V[3],MAT[9]->M_V[13].V[4],MAT[9]->M_V[13].V[5],MAT[9]->M_V[13].V[6],MAT[9]->M_V[13].V[7],MAT[9]->M_V[13].V[8],MAT[9]->M_V[13].V[9],MAT[9]->M_V[13].V[10],MAT[9]->M_V[13].V[11],MAT[9]->M_V[13].V[12],MAT[9]->M_V[13].V[13],MAT[9]->M_V[13].V[14],MAT[9]->M_V[13].V[15]);
//}
//
//void print_mat9_14()
//{
//	 fprintf(fp_mat9_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[14].V[0],MAT[9]->M_V[14].V[1],MAT[9]->M_V[15].V[2],MAT[9]->M_V[14].V[3],MAT[9]->M_V[14].V[4],MAT[9]->M_V[14].V[5],MAT[9]->M_V[14].V[6],MAT[9]->M_V[14].V[7],MAT[9]->M_V[14].V[8],MAT[9]->M_V[14].V[9],MAT[9]->M_V[14].V[10],MAT[9]->M_V[14].V[11],MAT[9]->M_V[14].V[12],MAT[9]->M_V[14].V[13],MAT[9]->M_V[14].V[14],MAT[9]->M_V[14].V[15]);
//}
//
//void print_mat9_15()
//{
//	 fprintf(fp_mat9_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[15].V[0],MAT[9]->M_V[15].V[1],MAT[9]->M_V[16].V[2],MAT[9]->M_V[15].V[3],MAT[9]->M_V[15].V[4],MAT[9]->M_V[15].V[5],MAT[9]->M_V[15].V[6],MAT[9]->M_V[15].V[7],MAT[9]->M_V[15].V[8],MAT[9]->M_V[15].V[9],MAT[9]->M_V[15].V[10],MAT[9]->M_V[15].V[11],MAT[9]->M_V[15].V[12],MAT[9]->M_V[15].V[13],MAT[9]->M_V[15].V[14],MAT[9]->M_V[15].V[15]);
//}
//
//
//void print_mat10_0()
//{
//	 fprintf(fp_mat10_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[0].V[0],MAT[10]->M_V[0].V[1],MAT[10]->M_V[0].V[2],MAT[10]->M_V[0].V[3],MAT[10]->M_V[0].V[4],MAT[10]->M_V[0].V[5],MAT[10]->M_V[0].V[6],MAT[10]->M_V[0].V[7],MAT[10]->M_V[0].V[8],MAT[10]->M_V[0].V[9],MAT[10]->M_V[0].V[10],MAT[10]->M_V[0].V[11],MAT[10]->M_V[0].V[12],MAT[10]->M_V[0].V[13],MAT[10]->M_V[0].V[14],MAT[10]->M_V[0].V[15]);
//}
//
//void print_mat10_1()
//{
//	fprintf(fp_mat10_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[1].V[0],MAT[10]->M_V[1].V[1],MAT[10]->M_V[1].V[2],MAT[10]->M_V[1].V[3],MAT[10]->M_V[1].V[4],MAT[10]->M_V[1].V[5],MAT[10]->M_V[1].V[6],MAT[10]->M_V[1].V[7],MAT[10]->M_V[1].V[8],MAT[10]->M_V[1].V[9],MAT[10]->M_V[1].V[10],MAT[10]->M_V[1].V[11],MAT[10]->M_V[1].V[12],MAT[10]->M_V[1].V[13],MAT[10]->M_V[1].V[14],MAT[10]->M_V[1].V[15]);
//}
//
//void print_mat10_2()
//{
//	fprintf(fp_mat10_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[2].V[0],MAT[10]->M_V[2].V[1],MAT[10]->M_V[2].V[2],MAT[10]->M_V[2].V[3],MAT[10]->M_V[2].V[4],MAT[10]->M_V[2].V[5],MAT[10]->M_V[2].V[6],MAT[10]->M_V[2].V[7],MAT[10]->M_V[2].V[8],MAT[10]->M_V[2].V[9],MAT[10]->M_V[2].V[10],MAT[10]->M_V[2].V[11],MAT[10]->M_V[2].V[12],MAT[10]->M_V[2].V[13],MAT[10]->M_V[2].V[14],MAT[10]->M_V[2].V[15]);
//}
//
//void print_mat10_3()
//{
//	fprintf(fp_mat10_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[3].V[0],MAT[10]->M_V[3].V[1],MAT[10]->M_V[3].V[2],MAT[10]->M_V[3].V[3],MAT[10]->M_V[3].V[4],MAT[10]->M_V[3].V[5],MAT[10]->M_V[3].V[6],MAT[10]->M_V[3].V[7],MAT[10]->M_V[3].V[8],MAT[10]->M_V[3].V[9],MAT[10]->M_V[3].V[10],MAT[10]->M_V[3].V[11],MAT[10]->M_V[3].V[12],MAT[10]->M_V[3].V[13],MAT[10]->M_V[3].V[14],MAT[10]->M_V[3].V[15]);    
//}
//
//void print_mat10_4()
//{
//	fprintf(fp_mat10_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[4].V[0],MAT[10]->M_V[4].V[1],MAT[10]->M_V[4].V[2],MAT[10]->M_V[4].V[3],MAT[10]->M_V[4].V[4],MAT[10]->M_V[4].V[5],MAT[10]->M_V[4].V[6],MAT[10]->M_V[4].V[7],MAT[10]->M_V[4].V[8],MAT[10]->M_V[4].V[9],MAT[10]->M_V[4].V[10],MAT[10]->M_V[4].V[11],MAT[10]->M_V[4].V[12],MAT[10]->M_V[4].V[13],MAT[10]->M_V[4].V[14],MAT[10]->M_V[4].V[15]);
//}
//
//void print_mat10_5()
//{
//	fprintf(fp_mat10_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[5].V[0],MAT[10]->M_V[5].V[1],MAT[10]->M_V[5].V[2],MAT[10]->M_V[5].V[3],MAT[10]->M_V[5].V[4],MAT[10]->M_V[5].V[5],MAT[10]->M_V[5].V[6],MAT[10]->M_V[5].V[7],MAT[10]->M_V[5].V[8],MAT[10]->M_V[5].V[9],MAT[10]->M_V[5].V[10],MAT[10]->M_V[5].V[11],MAT[10]->M_V[5].V[12],MAT[10]->M_V[5].V[13],MAT[10]->M_V[5].V[14],MAT[10]->M_V[5].V[15]);
//}
//
//void print_mat10_6()
//{
//	fprintf(fp_mat10_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[6].V[0],MAT[10]->M_V[6].V[1],MAT[10]->M_V[6].V[2],MAT[10]->M_V[6].V[3],MAT[10]->M_V[6].V[4],MAT[10]->M_V[6].V[5],MAT[10]->M_V[6].V[6],MAT[10]->M_V[6].V[7],MAT[10]->M_V[6].V[8],MAT[10]->M_V[6].V[9],MAT[10]->M_V[6].V[10],MAT[10]->M_V[6].V[11],MAT[10]->M_V[6].V[12],MAT[10]->M_V[6].V[13],MAT[10]->M_V[6].V[14],MAT[10]->M_V[6].V[15]);
//}
//
//void print_mat10_7()
//{
//	fprintf(fp_mat10_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[7].V[0],MAT[10]->M_V[7].V[1],MAT[10]->M_V[7].V[2],MAT[10]->M_V[7].V[3],MAT[10]->M_V[7].V[4],MAT[10]->M_V[7].V[5],MAT[10]->M_V[7].V[6],MAT[10]->M_V[7].V[7],MAT[10]->M_V[7].V[8],MAT[10]->M_V[7].V[9],MAT[10]->M_V[7].V[10],MAT[10]->M_V[7].V[11],MAT[10]->M_V[7].V[12],MAT[10]->M_V[7].V[13],MAT[10]->M_V[7].V[14],MAT[10]->M_V[0].V[15]);
//}
//
//void print_mat10_8()
//{
//	 fprintf(fp_mat10_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[8].V[0],MAT[10]->M_V[8].V[1],MAT[10]->M_V[8].V[2],MAT[10]->M_V[8].V[3],MAT[10]->M_V[8].V[4],MAT[10]->M_V[8].V[5],MAT[10]->M_V[8].V[6],MAT[10]->M_V[8].V[7],MAT[10]->M_V[8].V[8],MAT[10]->M_V[8].V[9],MAT[10]->M_V[8].V[10],MAT[10]->M_V[8].V[11],MAT[10]->M_V[8].V[12],MAT[10]->M_V[8].V[13],MAT[10]->M_V[8].V[14],MAT[10]->M_V[8].V[15]);
//}
//
//void print_mat10_9()
//{
//	fprintf(fp_mat10_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[9].V[0],MAT[10]->M_V[9].V[1],MAT[10]->M_V[9].V[2],MAT[10]->M_V[9].V[3],MAT[10]->M_V[9].V[4],MAT[10]->M_V[9].V[5],MAT[10]->M_V[9].V[6],MAT[10]->M_V[9].V[7],MAT[10]->M_V[9].V[8],MAT[10]->M_V[9].V[9],MAT[10]->M_V[9].V[10],MAT[10]->M_V[9].V[11],MAT[10]->M_V[9].V[12],MAT[10]->M_V[9].V[13],MAT[10]->M_V[9].V[14],MAT[10]->M_V[9].V[15]);
//}
//
//void print_mat10_10()
//{
//	fprintf(fp_mat10_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[10].V[0],MAT[10]->M_V[10].V[1],MAT[10]->M_V[10].V[2],MAT[10]->M_V[10].V[3],MAT[10]->M_V[10].V[4],MAT[10]->M_V[10].V[5],MAT[10]->M_V[10].V[6],MAT[10]->M_V[10].V[7],MAT[10]->M_V[10].V[8],MAT[10]->M_V[10].V[9],MAT[10]->M_V[10].V[10],MAT[10]->M_V[10].V[11],MAT[10]->M_V[10].V[12],MAT[10]->M_V[10].V[13],MAT[10]->M_V[10].V[14],MAT[10]->M_V[10].V[15]);
//}
//
//void print_mat10_11()
//{
//	fprintf(fp_mat10_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[11].V[0],MAT[10]->M_V[11].V[1],MAT[10]->M_V[12].V[2],MAT[10]->M_V[11].V[3],MAT[10]->M_V[11].V[4],MAT[10]->M_V[11].V[5],MAT[10]->M_V[11].V[6],MAT[10]->M_V[11].V[7],MAT[10]->M_V[11].V[8],MAT[10]->M_V[11].V[9],MAT[10]->M_V[11].V[10],MAT[10]->M_V[11].V[11],MAT[10]->M_V[11].V[12],MAT[10]->M_V[11].V[13],MAT[10]->M_V[11].V[14],MAT[10]->M_V[11].V[15]);
//}
//
//void print_mat10_12()
//{
//	fprintf(fp_mat10_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[12].V[0],MAT[10]->M_V[12].V[1],MAT[10]->M_V[13].V[2],MAT[10]->M_V[12].V[3],MAT[10]->M_V[12].V[4],MAT[10]->M_V[12].V[5],MAT[10]->M_V[12].V[6],MAT[10]->M_V[12].V[7],MAT[10]->M_V[12].V[8],MAT[10]->M_V[12].V[9],MAT[10]->M_V[12].V[10],MAT[10]->M_V[12].V[11],MAT[10]->M_V[12].V[12],MAT[10]->M_V[12].V[13],MAT[10]->M_V[12].V[14],MAT[10]->M_V[12].V[15]);
//}
//
//void print_mat10_13()
//{
//	fprintf(fp_mat10_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[13].V[0],MAT[10]->M_V[13].V[1],MAT[10]->M_V[14].V[2],MAT[10]->M_V[13].V[3],MAT[10]->M_V[13].V[4],MAT[10]->M_V[13].V[5],MAT[10]->M_V[13].V[6],MAT[10]->M_V[13].V[7],MAT[10]->M_V[13].V[8],MAT[10]->M_V[13].V[9],MAT[10]->M_V[13].V[10],MAT[10]->M_V[13].V[11],MAT[10]->M_V[13].V[12],MAT[10]->M_V[13].V[13],MAT[10]->M_V[13].V[14],MAT[10]->M_V[13].V[15]);
//}
//
//void print_mat10_14()
//{
//	fprintf(fp_mat10_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[14].V[0],MAT[10]->M_V[14].V[1],MAT[10]->M_V[15].V[2],MAT[10]->M_V[14].V[3],MAT[10]->M_V[14].V[4],MAT[10]->M_V[14].V[5],MAT[10]->M_V[14].V[6],MAT[10]->M_V[14].V[7],MAT[10]->M_V[14].V[8],MAT[10]->M_V[14].V[9],MAT[10]->M_V[14].V[10],MAT[10]->M_V[14].V[11],MAT[10]->M_V[14].V[12],MAT[10]->M_V[14].V[13],MAT[10]->M_V[14].V[14],MAT[10]->M_V[14].V[15]);
//}
//
//void print_mat10_15()
//{
//	fprintf(fp_mat10_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[15].V[0],MAT[10]->M_V[15].V[1],MAT[10]->M_V[16].V[2],MAT[10]->M_V[15].V[3],MAT[10]->M_V[15].V[4],MAT[10]->M_V[15].V[5],MAT[10]->M_V[15].V[6],MAT[10]->M_V[15].V[7],MAT[10]->M_V[15].V[8],MAT[10]->M_V[15].V[9],MAT[10]->M_V[15].V[10],MAT[10]->M_V[15].V[11],MAT[10]->M_V[15].V[12],MAT[10]->M_V[15].V[13],MAT[10]->M_V[15].V[14],MAT[10]->M_V[15].V[15]);
//}
//
//
//void print_mat11_0()
//{
//	fprintf(fp_mat11_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[0].V[0],MAT[11]->M_V[0].V[1],MAT[11]->M_V[0].V[2],MAT[11]->M_V[0].V[3],MAT[11]->M_V[0].V[4],MAT[11]->M_V[0].V[5],MAT[11]->M_V[0].V[6],MAT[11]->M_V[0].V[7],MAT[11]->M_V[0].V[8],MAT[11]->M_V[0].V[9],MAT[11]->M_V[0].V[10],MAT[11]->M_V[0].V[11],MAT[11]->M_V[0].V[12],MAT[11]->M_V[0].V[13],MAT[11]->M_V[0].V[14],MAT[11]->M_V[0].V[15]);
//}
//
//void print_mat11_1()
//{
//	fprintf(fp_mat11_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[1].V[0],MAT[11]->M_V[1].V[1],MAT[11]->M_V[1].V[2],MAT[11]->M_V[1].V[3],MAT[11]->M_V[1].V[4],MAT[11]->M_V[1].V[5],MAT[11]->M_V[1].V[6],MAT[11]->M_V[1].V[7],MAT[11]->M_V[1].V[8],MAT[11]->M_V[1].V[9],MAT[11]->M_V[1].V[10],MAT[11]->M_V[1].V[11],MAT[11]->M_V[1].V[12],MAT[11]->M_V[1].V[13],MAT[11]->M_V[1].V[14],MAT[11]->M_V[1].V[15]);
//}
//
//void print_mat11_2()
//{
//	 fprintf(fp_mat11_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[2].V[0],MAT[11]->M_V[2].V[1],MAT[11]->M_V[2].V[2],MAT[11]->M_V[2].V[3],MAT[11]->M_V[2].V[4],MAT[11]->M_V[2].V[5],MAT[11]->M_V[2].V[6],MAT[11]->M_V[2].V[7],MAT[11]->M_V[2].V[8],MAT[11]->M_V[2].V[9],MAT[11]->M_V[2].V[10],MAT[11]->M_V[2].V[11],MAT[11]->M_V[2].V[12],MAT[11]->M_V[2].V[13],MAT[11]->M_V[2].V[14],MAT[11]->M_V[2].V[15]);
//}
//
//void print_mat11_3()
//{
//	fprintf(fp_mat11_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[3].V[0],MAT[11]->M_V[3].V[1],MAT[11]->M_V[3].V[2],MAT[11]->M_V[3].V[3],MAT[11]->M_V[3].V[4],MAT[11]->M_V[3].V[5],MAT[11]->M_V[3].V[6],MAT[11]->M_V[3].V[7],MAT[11]->M_V[3].V[8],MAT[11]->M_V[3].V[9],MAT[11]->M_V[3].V[10],MAT[11]->M_V[3].V[11],MAT[11]->M_V[3].V[12],MAT[11]->M_V[3].V[13],MAT[11]->M_V[3].V[14],MAT[11]->M_V[3].V[15]);    
//}
//
//void print_mat11_4()
//{
//	fprintf(fp_mat11_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[4].V[0],MAT[11]->M_V[4].V[1],MAT[11]->M_V[4].V[2],MAT[11]->M_V[4].V[3],MAT[11]->M_V[4].V[4],MAT[11]->M_V[4].V[5],MAT[11]->M_V[4].V[6],MAT[11]->M_V[4].V[7],MAT[11]->M_V[4].V[8],MAT[11]->M_V[4].V[9],MAT[11]->M_V[4].V[10],MAT[11]->M_V[4].V[11],MAT[11]->M_V[4].V[12],MAT[11]->M_V[4].V[13],MAT[11]->M_V[4].V[14],MAT[11]->M_V[4].V[15]);
//}
//
//void print_mat11_5()
//{
//	fprintf(fp_mat11_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[5].V[0],MAT[11]->M_V[5].V[1],MAT[11]->M_V[5].V[2],MAT[11]->M_V[5].V[3],MAT[11]->M_V[5].V[4],MAT[11]->M_V[5].V[5],MAT[11]->M_V[5].V[6],MAT[11]->M_V[5].V[7],MAT[11]->M_V[5].V[8],MAT[11]->M_V[5].V[9],MAT[11]->M_V[5].V[10],MAT[11]->M_V[5].V[11],MAT[11]->M_V[5].V[12],MAT[11]->M_V[5].V[13],MAT[11]->M_V[5].V[14],MAT[11]->M_V[5].V[15]);
//}
//
//void print_mat11_6()
//{
//	fprintf(fp_mat11_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[6].V[0],MAT[11]->M_V[6].V[1],MAT[11]->M_V[6].V[2],MAT[11]->M_V[6].V[3],MAT[11]->M_V[6].V[4],MAT[11]->M_V[6].V[5],MAT[11]->M_V[6].V[6],MAT[11]->M_V[6].V[7],MAT[11]->M_V[6].V[8],MAT[11]->M_V[6].V[9],MAT[11]->M_V[6].V[10],MAT[11]->M_V[6].V[11],MAT[11]->M_V[6].V[12],MAT[11]->M_V[6].V[13],MAT[11]->M_V[6].V[14],MAT[11]->M_V[6].V[15]);
//}
//
//void print_mat11_7()
//{
//	fprintf(fp_mat11_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[7].V[0],MAT[11]->M_V[7].V[1],MAT[11]->M_V[7].V[2],MAT[11]->M_V[7].V[3],MAT[11]->M_V[7].V[4],MAT[11]->M_V[7].V[5],MAT[11]->M_V[7].V[6],MAT[11]->M_V[7].V[7],MAT[11]->M_V[7].V[8],MAT[11]->M_V[7].V[9],MAT[11]->M_V[7].V[10],MAT[11]->M_V[7].V[11],MAT[11]->M_V[7].V[12],MAT[11]->M_V[7].V[13],MAT[11]->M_V[7].V[14],MAT[11]->M_V[0].V[15]);
//}
//
//void print_mat11_8()
//{
//	fprintf(fp_mat11_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[8].V[0],MAT[11]->M_V[8].V[1],MAT[11]->M_V[8].V[2],MAT[11]->M_V[8].V[3],MAT[11]->M_V[8].V[4],MAT[11]->M_V[8].V[5],MAT[11]->M_V[8].V[6],MAT[11]->M_V[8].V[7],MAT[11]->M_V[8].V[8],MAT[11]->M_V[8].V[9],MAT[11]->M_V[8].V[10],MAT[11]->M_V[8].V[11],MAT[11]->M_V[8].V[12],MAT[11]->M_V[8].V[13],MAT[11]->M_V[8].V[14],MAT[11]->M_V[8].V[15]);
//}
//
//void print_mat11_9()
//{
//	fprintf(fp_mat11_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[9].V[0],MAT[11]->M_V[9].V[1],MAT[11]->M_V[9].V[2],MAT[11]->M_V[9].V[3],MAT[11]->M_V[9].V[4],MAT[11]->M_V[9].V[5],MAT[11]->M_V[9].V[6],MAT[11]->M_V[9].V[7],MAT[11]->M_V[9].V[8],MAT[11]->M_V[9].V[9],MAT[11]->M_V[9].V[10],MAT[11]->M_V[9].V[11],MAT[11]->M_V[9].V[12],MAT[11]->M_V[9].V[13],MAT[11]->M_V[9].V[14],MAT[11]->M_V[9].V[15]);
//}
//
//void print_mat11_10()
//{
//	fprintf(fp_mat11_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[10].V[0],MAT[11]->M_V[10].V[1],MAT[11]->M_V[10].V[2],MAT[11]->M_V[10].V[3],MAT[11]->M_V[10].V[4],MAT[11]->M_V[10].V[5],MAT[11]->M_V[10].V[6],MAT[11]->M_V[10].V[7],MAT[11]->M_V[10].V[8],MAT[11]->M_V[10].V[9],MAT[11]->M_V[10].V[10],MAT[11]->M_V[10].V[11],MAT[11]->M_V[10].V[12],MAT[11]->M_V[10].V[13],MAT[11]->M_V[10].V[14],MAT[11]->M_V[10].V[15]);
//}
//
//void print_mat11_11()
//{
//	fprintf(fp_mat11_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[11].V[0],MAT[11]->M_V[11].V[1],MAT[11]->M_V[12].V[2],MAT[11]->M_V[11].V[3],MAT[11]->M_V[11].V[4],MAT[11]->M_V[11].V[5],MAT[11]->M_V[11].V[6],MAT[11]->M_V[11].V[7],MAT[11]->M_V[11].V[8],MAT[11]->M_V[11].V[9],MAT[11]->M_V[11].V[10],MAT[11]->M_V[11].V[11],MAT[11]->M_V[11].V[12],MAT[11]->M_V[11].V[13],MAT[11]->M_V[11].V[14],MAT[11]->M_V[11].V[15]);
//}
//
//void print_mat11_12()
//{
//	fprintf(fp_mat11_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[12].V[0],MAT[11]->M_V[12].V[1],MAT[11]->M_V[13].V[2],MAT[11]->M_V[12].V[3],MAT[11]->M_V[12].V[4],MAT[11]->M_V[12].V[5],MAT[11]->M_V[12].V[6],MAT[11]->M_V[12].V[7],MAT[11]->M_V[12].V[8],MAT[11]->M_V[12].V[9],MAT[11]->M_V[12].V[10],MAT[11]->M_V[12].V[11],MAT[11]->M_V[12].V[12],MAT[11]->M_V[12].V[13],MAT[11]->M_V[12].V[14],MAT[11]->M_V[12].V[15]);
//}
//
//void print_mat11_13()
//{
//	fprintf(fp_mat11_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[13].V[0],MAT[11]->M_V[13].V[1],MAT[11]->M_V[14].V[2],MAT[11]->M_V[13].V[3],MAT[11]->M_V[13].V[4],MAT[11]->M_V[13].V[5],MAT[11]->M_V[13].V[6],MAT[11]->M_V[13].V[7],MAT[11]->M_V[13].V[8],MAT[11]->M_V[13].V[9],MAT[11]->M_V[13].V[10],MAT[11]->M_V[13].V[11],MAT[11]->M_V[13].V[12],MAT[11]->M_V[13].V[13],MAT[11]->M_V[13].V[14],MAT[11]->M_V[13].V[15]);
//}
//
//void print_mat11_14()
//{
//	fprintf(fp_mat11_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[14].V[0],MAT[11]->M_V[14].V[1],MAT[11]->M_V[15].V[2],MAT[11]->M_V[14].V[3],MAT[11]->M_V[14].V[4],MAT[11]->M_V[14].V[5],MAT[11]->M_V[14].V[6],MAT[11]->M_V[14].V[7],MAT[11]->M_V[14].V[8],MAT[11]->M_V[14].V[9],MAT[11]->M_V[14].V[10],MAT[11]->M_V[14].V[11],MAT[11]->M_V[14].V[12],MAT[11]->M_V[14].V[13],MAT[11]->M_V[14].V[14],MAT[11]->M_V[14].V[15]);
//}
//
//void print_mat11_15()
//{
//	fprintf(fp_mat11_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[15].V[0],MAT[11]->M_V[15].V[1],MAT[11]->M_V[16].V[2],MAT[11]->M_V[15].V[3],MAT[11]->M_V[15].V[4],MAT[11]->M_V[15].V[5],MAT[11]->M_V[15].V[6],MAT[11]->M_V[15].V[7],MAT[11]->M_V[15].V[8],MAT[11]->M_V[15].V[9],MAT[11]->M_V[15].V[10],MAT[11]->M_V[15].V[11],MAT[11]->M_V[15].V[12],MAT[11]->M_V[15].V[13],MAT[11]->M_V[15].V[14],MAT[11]->M_V[15].V[15]);
//}
//
//
//void print_mat12_0()
//{
//	fprintf(fp_mat12_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[0].V[0],MAT[12]->M_V[0].V[1],MAT[12]->M_V[0].V[2],MAT[12]->M_V[0].V[3],MAT[12]->M_V[0].V[4],MAT[12]->M_V[0].V[5],MAT[12]->M_V[0].V[6],MAT[12]->M_V[0].V[7],MAT[12]->M_V[0].V[8],MAT[12]->M_V[0].V[9],MAT[12]->M_V[0].V[10],MAT[12]->M_V[0].V[11],MAT[12]->M_V[0].V[12],MAT[12]->M_V[0].V[13],MAT[12]->M_V[0].V[14],MAT[12]->M_V[0].V[15]);
//}
//
//void print_mat12_1()
//{
//	fprintf(fp_mat12_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[1].V[0],MAT[12]->M_V[1].V[1],MAT[12]->M_V[1].V[2],MAT[12]->M_V[1].V[3],MAT[12]->M_V[1].V[4],MAT[12]->M_V[1].V[5],MAT[12]->M_V[1].V[6],MAT[12]->M_V[1].V[7],MAT[12]->M_V[1].V[8],MAT[12]->M_V[1].V[9],MAT[12]->M_V[1].V[10],MAT[12]->M_V[1].V[11],MAT[12]->M_V[1].V[12],MAT[12]->M_V[1].V[13],MAT[12]->M_V[1].V[14],MAT[12]->M_V[1].V[15]);
//}
//
//void print_mat12_2()
//{
//	fprintf(fp_mat12_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[2].V[0],MAT[12]->M_V[2].V[1],MAT[12]->M_V[2].V[2],MAT[12]->M_V[2].V[3],MAT[12]->M_V[2].V[4],MAT[12]->M_V[2].V[5],MAT[12]->M_V[2].V[6],MAT[12]->M_V[2].V[7],MAT[12]->M_V[2].V[8],MAT[12]->M_V[2].V[9],MAT[12]->M_V[2].V[10],MAT[12]->M_V[2].V[11],MAT[12]->M_V[2].V[12],MAT[12]->M_V[2].V[13],MAT[12]->M_V[2].V[14],MAT[12]->M_V[2].V[15]);
//}
//
//void print_mat12_3()
//{
//	fprintf(fp_mat12_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[3].V[0],MAT[12]->M_V[3].V[1],MAT[12]->M_V[3].V[2],MAT[12]->M_V[3].V[3],MAT[12]->M_V[3].V[4],MAT[12]->M_V[3].V[5],MAT[12]->M_V[3].V[6],MAT[12]->M_V[3].V[7],MAT[12]->M_V[3].V[8],MAT[12]->M_V[3].V[9],MAT[12]->M_V[3].V[10],MAT[12]->M_V[3].V[11],MAT[12]->M_V[3].V[12],MAT[12]->M_V[3].V[13],MAT[12]->M_V[3].V[14],MAT[12]->M_V[3].V[15]);    
//}
//
//void print_mat12_4()
//{
//	fprintf(fp_mat12_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[4].V[0],MAT[12]->M_V[4].V[1],MAT[12]->M_V[4].V[2],MAT[12]->M_V[4].V[3],MAT[12]->M_V[4].V[4],MAT[12]->M_V[4].V[5],MAT[12]->M_V[4].V[6],MAT[12]->M_V[4].V[7],MAT[12]->M_V[4].V[8],MAT[12]->M_V[4].V[9],MAT[12]->M_V[4].V[10],MAT[12]->M_V[4].V[11],MAT[12]->M_V[4].V[12],MAT[12]->M_V[4].V[13],MAT[12]->M_V[4].V[14],MAT[12]->M_V[4].V[15]);
//}
//
//void print_mat12_5()
//{
//	fprintf(fp_mat12_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[5].V[0],MAT[12]->M_V[5].V[1],MAT[12]->M_V[5].V[2],MAT[12]->M_V[5].V[3],MAT[12]->M_V[5].V[4],MAT[12]->M_V[5].V[5],MAT[12]->M_V[5].V[6],MAT[12]->M_V[5].V[7],MAT[12]->M_V[5].V[8],MAT[12]->M_V[5].V[9],MAT[12]->M_V[5].V[10],MAT[12]->M_V[5].V[11],MAT[12]->M_V[5].V[12],MAT[12]->M_V[5].V[13],MAT[12]->M_V[5].V[14],MAT[12]->M_V[5].V[15]);
//}
//
//void print_mat12_6()
//{
//	fprintf(fp_mat12_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[6].V[0],MAT[12]->M_V[6].V[1],MAT[12]->M_V[6].V[2],MAT[12]->M_V[6].V[3],MAT[12]->M_V[6].V[4],MAT[12]->M_V[6].V[5],MAT[12]->M_V[6].V[6],MAT[12]->M_V[6].V[7],MAT[12]->M_V[6].V[8],MAT[12]->M_V[6].V[9],MAT[12]->M_V[6].V[10],MAT[12]->M_V[6].V[11],MAT[12]->M_V[6].V[12],MAT[12]->M_V[6].V[13],MAT[12]->M_V[6].V[14],MAT[12]->M_V[6].V[15]);
//}
//
//void print_mat12_7()
//{
//	fprintf(fp_mat12_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[7].V[0],MAT[12]->M_V[7].V[1],MAT[12]->M_V[7].V[2],MAT[12]->M_V[7].V[3],MAT[12]->M_V[7].V[4],MAT[12]->M_V[7].V[5],MAT[12]->M_V[7].V[6],MAT[12]->M_V[7].V[7],MAT[12]->M_V[7].V[8],MAT[12]->M_V[7].V[9],MAT[12]->M_V[7].V[10],MAT[12]->M_V[7].V[11],MAT[12]->M_V[7].V[12],MAT[12]->M_V[7].V[13],MAT[12]->M_V[7].V[14],MAT[12]->M_V[0].V[15]);
//}
//
//void print_mat12_8()
//{
//	fprintf(fp_mat12_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[8].V[0],MAT[12]->M_V[8].V[1],MAT[12]->M_V[8].V[2],MAT[12]->M_V[8].V[3],MAT[12]->M_V[8].V[4],MAT[12]->M_V[8].V[5],MAT[12]->M_V[8].V[6],MAT[12]->M_V[8].V[7],MAT[12]->M_V[8].V[8],MAT[12]->M_V[8].V[9],MAT[12]->M_V[8].V[10],MAT[12]->M_V[8].V[11],MAT[12]->M_V[8].V[12],MAT[12]->M_V[8].V[13],MAT[12]->M_V[8].V[14],MAT[12]->M_V[8].V[15]);
//}
//
//void print_mat12_9()
//{
//	fprintf(fp_mat12_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[9].V[0],MAT[12]->M_V[9].V[1],MAT[12]->M_V[9].V[2],MAT[12]->M_V[9].V[3],MAT[12]->M_V[9].V[4],MAT[12]->M_V[9].V[5],MAT[12]->M_V[9].V[6],MAT[12]->M_V[9].V[7],MAT[12]->M_V[9].V[8],MAT[12]->M_V[9].V[9],MAT[12]->M_V[9].V[10],MAT[12]->M_V[9].V[11],MAT[12]->M_V[9].V[12],MAT[12]->M_V[9].V[13],MAT[12]->M_V[9].V[14],MAT[12]->M_V[9].V[15]);
//}
//
//void print_mat12_10()
//{
//	fprintf(fp_mat12_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[10].V[0],MAT[12]->M_V[10].V[1],MAT[12]->M_V[10].V[2],MAT[12]->M_V[10].V[3],MAT[12]->M_V[10].V[4],MAT[12]->M_V[10].V[5],MAT[12]->M_V[10].V[6],MAT[12]->M_V[10].V[7],MAT[12]->M_V[10].V[8],MAT[12]->M_V[10].V[9],MAT[12]->M_V[10].V[10],MAT[12]->M_V[10].V[11],MAT[12]->M_V[10].V[12],MAT[12]->M_V[10].V[13],MAT[12]->M_V[10].V[14],MAT[12]->M_V[10].V[15]);
//}
//
//void print_mat12_11()
//{
//	fprintf(fp_mat12_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[11].V[0],MAT[12]->M_V[11].V[1],MAT[12]->M_V[12].V[2],MAT[12]->M_V[11].V[3],MAT[12]->M_V[11].V[4],MAT[12]->M_V[11].V[5],MAT[12]->M_V[11].V[6],MAT[12]->M_V[11].V[7],MAT[12]->M_V[11].V[8],MAT[12]->M_V[11].V[9],MAT[12]->M_V[11].V[10],MAT[12]->M_V[11].V[11],MAT[12]->M_V[11].V[12],MAT[12]->M_V[11].V[13],MAT[12]->M_V[11].V[14],MAT[12]->M_V[11].V[15]);
//}
//
//void print_mat12_12()
//{
//	fprintf(fp_mat12_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[12].V[0],MAT[12]->M_V[12].V[1],MAT[12]->M_V[13].V[2],MAT[12]->M_V[12].V[3],MAT[12]->M_V[12].V[4],MAT[12]->M_V[12].V[5],MAT[12]->M_V[12].V[6],MAT[12]->M_V[12].V[7],MAT[12]->M_V[12].V[8],MAT[12]->M_V[12].V[9],MAT[12]->M_V[12].V[10],MAT[12]->M_V[12].V[11],MAT[12]->M_V[12].V[12],MAT[12]->M_V[12].V[13],MAT[12]->M_V[12].V[14],MAT[12]->M_V[12].V[15]);
//}
//
//void print_mat12_13()
//{
//	 fprintf(fp_mat12_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[13].V[0],MAT[12]->M_V[13].V[1],MAT[12]->M_V[14].V[2],MAT[12]->M_V[13].V[3],MAT[12]->M_V[13].V[4],MAT[12]->M_V[13].V[5],MAT[12]->M_V[13].V[6],MAT[12]->M_V[13].V[7],MAT[12]->M_V[13].V[8],MAT[12]->M_V[13].V[9],MAT[12]->M_V[13].V[10],MAT[12]->M_V[13].V[11],MAT[12]->M_V[13].V[12],MAT[12]->M_V[13].V[13],MAT[12]->M_V[13].V[14],MAT[12]->M_V[13].V[15]);
//}
//
//void print_mat12_14()
//{
//	fprintf(fp_mat12_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[14].V[0],MAT[12]->M_V[14].V[1],MAT[12]->M_V[15].V[2],MAT[12]->M_V[14].V[3],MAT[12]->M_V[14].V[4],MAT[12]->M_V[14].V[5],MAT[12]->M_V[14].V[6],MAT[12]->M_V[14].V[7],MAT[12]->M_V[14].V[8],MAT[12]->M_V[14].V[9],MAT[12]->M_V[14].V[10],MAT[12]->M_V[14].V[11],MAT[12]->M_V[14].V[12],MAT[12]->M_V[14].V[13],MAT[12]->M_V[14].V[14],MAT[12]->M_V[14].V[15]);
//}
//
//void print_mat12_15()
//{
//	fprintf(fp_mat12_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[15].V[0],MAT[12]->M_V[15].V[1],MAT[12]->M_V[16].V[2],MAT[12]->M_V[15].V[3],MAT[12]->M_V[15].V[4],MAT[12]->M_V[15].V[5],MAT[12]->M_V[15].V[6],MAT[12]->M_V[15].V[7],MAT[12]->M_V[15].V[8],MAT[12]->M_V[15].V[9],MAT[12]->M_V[15].V[10],MAT[12]->M_V[15].V[11],MAT[12]->M_V[15].V[12],MAT[12]->M_V[15].V[13],MAT[12]->M_V[15].V[14],MAT[12]->M_V[15].V[15]);
//}
//
//
//void print_mat13_0()
//{
//	fprintf(fp_mat13_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[0].V[0],MAT[13]->M_V[0].V[1],MAT[13]->M_V[0].V[2],MAT[13]->M_V[0].V[3],MAT[13]->M_V[0].V[4],MAT[13]->M_V[0].V[5],MAT[13]->M_V[0].V[6],MAT[13]->M_V[0].V[7],MAT[13]->M_V[0].V[8],MAT[13]->M_V[0].V[9],MAT[13]->M_V[0].V[10],MAT[13]->M_V[0].V[11],MAT[13]->M_V[0].V[12],MAT[13]->M_V[0].V[13],MAT[13]->M_V[0].V[14],MAT[13]->M_V[0].V[15]);
//}
//
//void print_mat13_1()
//{
//	fprintf(fp_mat13_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[1].V[0],MAT[13]->M_V[1].V[1],MAT[13]->M_V[1].V[2],MAT[13]->M_V[1].V[3],MAT[13]->M_V[1].V[4],MAT[13]->M_V[1].V[5],MAT[13]->M_V[1].V[6],MAT[13]->M_V[1].V[7],MAT[13]->M_V[1].V[8],MAT[13]->M_V[1].V[9],MAT[13]->M_V[1].V[10],MAT[13]->M_V[1].V[11],MAT[13]->M_V[1].V[12],MAT[13]->M_V[1].V[13],MAT[13]->M_V[1].V[14],MAT[13]->M_V[1].V[15]);
//}
//
//void print_mat13_2()
//{
//	fprintf(fp_mat13_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[2].V[0],MAT[13]->M_V[2].V[1],MAT[13]->M_V[2].V[2],MAT[13]->M_V[2].V[3],MAT[13]->M_V[2].V[4],MAT[13]->M_V[2].V[5],MAT[13]->M_V[2].V[6],MAT[13]->M_V[2].V[7],MAT[13]->M_V[2].V[8],MAT[13]->M_V[2].V[9],MAT[13]->M_V[2].V[10],MAT[13]->M_V[2].V[11],MAT[13]->M_V[2].V[12],MAT[13]->M_V[2].V[13],MAT[13]->M_V[2].V[14],MAT[13]->M_V[2].V[15]);
//}
//
//void print_mat13_3()
//{
//	fprintf(fp_mat13_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[3].V[0],MAT[13]->M_V[3].V[1],MAT[13]->M_V[3].V[2],MAT[13]->M_V[3].V[3],MAT[13]->M_V[3].V[4],MAT[13]->M_V[3].V[5],MAT[13]->M_V[3].V[6],MAT[13]->M_V[3].V[7],MAT[13]->M_V[3].V[8],MAT[13]->M_V[3].V[9],MAT[13]->M_V[3].V[10],MAT[13]->M_V[3].V[11],MAT[13]->M_V[3].V[12],MAT[13]->M_V[3].V[13],MAT[13]->M_V[3].V[14],MAT[13]->M_V[3].V[15]);    
//}
//
//void print_mat13_4()
//{
//	fprintf(fp_mat13_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[4].V[0],MAT[13]->M_V[4].V[1],MAT[13]->M_V[4].V[2],MAT[13]->M_V[4].V[3],MAT[13]->M_V[4].V[4],MAT[13]->M_V[4].V[5],MAT[13]->M_V[4].V[6],MAT[13]->M_V[4].V[7],MAT[13]->M_V[4].V[8],MAT[13]->M_V[4].V[9],MAT[13]->M_V[4].V[10],MAT[13]->M_V[4].V[11],MAT[13]->M_V[4].V[12],MAT[13]->M_V[4].V[13],MAT[13]->M_V[4].V[14],MAT[13]->M_V[4].V[15]);
//}
//
//void print_mat13_5()
//{
//	 fprintf(fp_mat13_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[5].V[0],MAT[13]->M_V[5].V[1],MAT[13]->M_V[5].V[2],MAT[13]->M_V[5].V[3],MAT[13]->M_V[5].V[4],MAT[13]->M_V[5].V[5],MAT[13]->M_V[5].V[6],MAT[13]->M_V[5].V[7],MAT[13]->M_V[5].V[8],MAT[13]->M_V[5].V[9],MAT[13]->M_V[5].V[10],MAT[13]->M_V[5].V[11],MAT[13]->M_V[5].V[12],MAT[13]->M_V[5].V[13],MAT[13]->M_V[5].V[14],MAT[13]->M_V[5].V[15]);
//}
//
//void print_mat13_6()
//{
//	 fprintf(fp_mat13_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[6].V[0],MAT[13]->M_V[6].V[1],MAT[13]->M_V[6].V[2],MAT[13]->M_V[6].V[3],MAT[13]->M_V[6].V[4],MAT[13]->M_V[6].V[5],MAT[13]->M_V[6].V[6],MAT[13]->M_V[6].V[7],MAT[13]->M_V[6].V[8],MAT[13]->M_V[6].V[9],MAT[13]->M_V[6].V[10],MAT[13]->M_V[6].V[11],MAT[13]->M_V[6].V[12],MAT[13]->M_V[6].V[13],MAT[13]->M_V[6].V[14],MAT[13]->M_V[6].V[15]);
//}
//
//void print_mat13_7()
//{
//	fprintf(fp_mat13_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[7].V[0],MAT[13]->M_V[7].V[1],MAT[13]->M_V[7].V[2],MAT[13]->M_V[7].V[3],MAT[13]->M_V[7].V[4],MAT[13]->M_V[7].V[5],MAT[13]->M_V[7].V[6],MAT[13]->M_V[7].V[7],MAT[13]->M_V[7].V[8],MAT[13]->M_V[7].V[9],MAT[13]->M_V[7].V[10],MAT[13]->M_V[7].V[11],MAT[13]->M_V[7].V[12],MAT[13]->M_V[7].V[13],MAT[13]->M_V[7].V[14],MAT[13]->M_V[0].V[15]);
//}
//
//void print_mat13_8()
//{
//	fprintf(fp_mat13_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[8].V[0],MAT[13]->M_V[8].V[1],MAT[13]->M_V[8].V[2],MAT[13]->M_V[8].V[3],MAT[13]->M_V[8].V[4],MAT[13]->M_V[8].V[5],MAT[13]->M_V[8].V[6],MAT[13]->M_V[8].V[7],MAT[13]->M_V[8].V[8],MAT[13]->M_V[8].V[9],MAT[13]->M_V[8].V[10],MAT[13]->M_V[8].V[11],MAT[13]->M_V[8].V[12],MAT[13]->M_V[8].V[13],MAT[13]->M_V[8].V[14],MAT[13]->M_V[8].V[15]);
//}
//
//void print_mat13_9()
//{
//	fprintf(fp_mat13_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[9].V[0],MAT[13]->M_V[9].V[1],MAT[13]->M_V[9].V[2],MAT[13]->M_V[9].V[3],MAT[13]->M_V[9].V[4],MAT[13]->M_V[9].V[5],MAT[13]->M_V[9].V[6],MAT[13]->M_V[9].V[7],MAT[13]->M_V[9].V[8],MAT[13]->M_V[9].V[9],MAT[13]->M_V[9].V[10],MAT[13]->M_V[9].V[11],MAT[13]->M_V[9].V[12],MAT[13]->M_V[9].V[13],MAT[13]->M_V[9].V[14],MAT[13]->M_V[9].V[15]);
//}
//
//void print_mat13_10()
//{
//	fprintf(fp_mat13_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[10].V[0],MAT[13]->M_V[10].V[1],MAT[13]->M_V[10].V[2],MAT[13]->M_V[10].V[3],MAT[13]->M_V[10].V[4],MAT[13]->M_V[10].V[5],MAT[13]->M_V[10].V[6],MAT[13]->M_V[10].V[7],MAT[13]->M_V[10].V[8],MAT[13]->M_V[10].V[9],MAT[13]->M_V[10].V[10],MAT[13]->M_V[10].V[11],MAT[13]->M_V[10].V[12],MAT[13]->M_V[10].V[13],MAT[13]->M_V[10].V[14],MAT[13]->M_V[10].V[15]);
//}
//
//void print_mat13_11()
//{
//	 fprintf(fp_mat13_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[11].V[0],MAT[13]->M_V[11].V[1],MAT[13]->M_V[12].V[2],MAT[13]->M_V[11].V[3],MAT[13]->M_V[11].V[4],MAT[13]->M_V[11].V[5],MAT[13]->M_V[11].V[6],MAT[13]->M_V[11].V[7],MAT[13]->M_V[11].V[8],MAT[13]->M_V[11].V[9],MAT[13]->M_V[11].V[10],MAT[13]->M_V[11].V[11],MAT[13]->M_V[11].V[12],MAT[13]->M_V[11].V[13],MAT[13]->M_V[11].V[14],MAT[13]->M_V[11].V[15]);
//}
//
//void print_mat13_12()
//{
//	fprintf(fp_mat13_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[12].V[0],MAT[13]->M_V[12].V[1],MAT[13]->M_V[13].V[2],MAT[13]->M_V[12].V[3],MAT[13]->M_V[12].V[4],MAT[13]->M_V[12].V[5],MAT[13]->M_V[12].V[6],MAT[13]->M_V[12].V[7],MAT[13]->M_V[12].V[8],MAT[13]->M_V[12].V[9],MAT[13]->M_V[12].V[10],MAT[13]->M_V[12].V[11],MAT[13]->M_V[12].V[12],MAT[13]->M_V[12].V[13],MAT[13]->M_V[12].V[14],MAT[13]->M_V[12].V[15]);
//}
//
//void print_mat13_13()
//{
//	fprintf(fp_mat13_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[13].V[0],MAT[13]->M_V[13].V[1],MAT[13]->M_V[14].V[2],MAT[13]->M_V[13].V[3],MAT[13]->M_V[13].V[4],MAT[13]->M_V[13].V[5],MAT[13]->M_V[13].V[6],MAT[13]->M_V[13].V[7],MAT[13]->M_V[13].V[8],MAT[13]->M_V[13].V[9],MAT[13]->M_V[13].V[10],MAT[13]->M_V[13].V[11],MAT[13]->M_V[13].V[12],MAT[13]->M_V[13].V[13],MAT[13]->M_V[13].V[14],MAT[13]->M_V[13].V[15]);
//}
//
//void print_mat13_14()
//{
//	fprintf(fp_mat13_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[14].V[0],MAT[13]->M_V[14].V[1],MAT[13]->M_V[15].V[2],MAT[13]->M_V[14].V[3],MAT[13]->M_V[14].V[4],MAT[13]->M_V[14].V[5],MAT[13]->M_V[14].V[6],MAT[13]->M_V[14].V[7],MAT[13]->M_V[14].V[8],MAT[13]->M_V[14].V[9],MAT[13]->M_V[14].V[10],MAT[13]->M_V[14].V[11],MAT[13]->M_V[14].V[12],MAT[13]->M_V[14].V[13],MAT[13]->M_V[14].V[14],MAT[13]->M_V[14].V[15]);
//}
//
//void print_mat13_15()
//{
//	fprintf(fp_mat13_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[15].V[0],MAT[13]->M_V[15].V[1],MAT[13]->M_V[16].V[2],MAT[13]->M_V[15].V[3],MAT[13]->M_V[15].V[4],MAT[13]->M_V[15].V[5],MAT[13]->M_V[15].V[6],MAT[13]->M_V[15].V[7],MAT[13]->M_V[15].V[8],MAT[13]->M_V[15].V[9],MAT[13]->M_V[15].V[10],MAT[13]->M_V[15].V[11],MAT[13]->M_V[15].V[12],MAT[13]->M_V[15].V[13],MAT[13]->M_V[15].V[14],MAT[13]->M_V[15].V[15]);
//}
//
//
//void print_mat14_0()
//{
//	 fprintf(fp_mat14_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[0].V[0],MAT[14]->M_V[0].V[1],MAT[14]->M_V[0].V[2],MAT[14]->M_V[0].V[3],MAT[14]->M_V[0].V[4],MAT[14]->M_V[0].V[5],MAT[14]->M_V[0].V[6],MAT[14]->M_V[0].V[7],MAT[14]->M_V[0].V[8],MAT[14]->M_V[0].V[9],MAT[14]->M_V[0].V[10],MAT[14]->M_V[0].V[11],MAT[14]->M_V[0].V[12],MAT[14]->M_V[0].V[13],MAT[14]->M_V[0].V[14],MAT[14]->M_V[0].V[15]);
//}
//
//void print_mat14_1()
//{
//	fprintf(fp_mat14_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[1].V[0],MAT[14]->M_V[1].V[1],MAT[14]->M_V[1].V[2],MAT[14]->M_V[1].V[3],MAT[14]->M_V[1].V[4],MAT[14]->M_V[1].V[5],MAT[14]->M_V[1].V[6],MAT[14]->M_V[1].V[7],MAT[14]->M_V[1].V[8],MAT[14]->M_V[1].V[9],MAT[14]->M_V[1].V[10],MAT[14]->M_V[1].V[11],MAT[14]->M_V[1].V[12],MAT[14]->M_V[1].V[13],MAT[14]->M_V[1].V[14],MAT[14]->M_V[1].V[15]);
//}
//
//void print_mat14_2()
//{
//	fprintf(fp_mat14_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[2].V[0],MAT[14]->M_V[2].V[1],MAT[14]->M_V[2].V[2],MAT[14]->M_V[2].V[3],MAT[14]->M_V[2].V[4],MAT[14]->M_V[2].V[5],MAT[14]->M_V[2].V[6],MAT[14]->M_V[2].V[7],MAT[14]->M_V[2].V[8],MAT[14]->M_V[2].V[9],MAT[14]->M_V[2].V[10],MAT[14]->M_V[2].V[11],MAT[14]->M_V[2].V[12],MAT[14]->M_V[2].V[13],MAT[14]->M_V[2].V[14],MAT[14]->M_V[2].V[15]);
//}
//
//void print_mat14_3()
//{
//	fprintf(fp_mat14_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[3].V[0],MAT[14]->M_V[3].V[1],MAT[14]->M_V[3].V[2],MAT[14]->M_V[3].V[3],MAT[14]->M_V[3].V[4],MAT[14]->M_V[3].V[5],MAT[14]->M_V[3].V[6],MAT[14]->M_V[3].V[7],MAT[14]->M_V[3].V[8],MAT[14]->M_V[3].V[9],MAT[14]->M_V[3].V[10],MAT[14]->M_V[3].V[11],MAT[14]->M_V[3].V[12],MAT[14]->M_V[3].V[13],MAT[14]->M_V[3].V[14],MAT[14]->M_V[3].V[15]);    
//}
//
//void print_mat14_4()
//{
//	fprintf(fp_mat14_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[4].V[0],MAT[14]->M_V[4].V[1],MAT[14]->M_V[4].V[2],MAT[14]->M_V[4].V[3],MAT[14]->M_V[4].V[4],MAT[14]->M_V[4].V[5],MAT[14]->M_V[4].V[6],MAT[14]->M_V[4].V[7],MAT[14]->M_V[4].V[8],MAT[14]->M_V[4].V[9],MAT[14]->M_V[4].V[10],MAT[14]->M_V[4].V[11],MAT[14]->M_V[4].V[12],MAT[14]->M_V[4].V[13],MAT[14]->M_V[4].V[14],MAT[14]->M_V[4].V[15]);
//}
//
//void print_mat14_5()
//{
//	fprintf(fp_mat14_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[5].V[0],MAT[14]->M_V[5].V[1],MAT[14]->M_V[5].V[2],MAT[14]->M_V[5].V[3],MAT[14]->M_V[5].V[4],MAT[14]->M_V[5].V[5],MAT[14]->M_V[5].V[6],MAT[14]->M_V[5].V[7],MAT[14]->M_V[5].V[8],MAT[14]->M_V[5].V[9],MAT[14]->M_V[5].V[10],MAT[14]->M_V[5].V[11],MAT[14]->M_V[5].V[12],MAT[14]->M_V[5].V[13],MAT[14]->M_V[5].V[14],MAT[14]->M_V[5].V[15]);
//}
//
//void print_mat14_6()
//{
//	fprintf(fp_mat14_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[6].V[0],MAT[14]->M_V[6].V[1],MAT[14]->M_V[6].V[2],MAT[14]->M_V[6].V[3],MAT[14]->M_V[6].V[4],MAT[14]->M_V[6].V[5],MAT[14]->M_V[6].V[6],MAT[14]->M_V[6].V[7],MAT[14]->M_V[6].V[8],MAT[14]->M_V[6].V[9],MAT[14]->M_V[6].V[10],MAT[14]->M_V[6].V[11],MAT[14]->M_V[6].V[12],MAT[14]->M_V[6].V[13],MAT[14]->M_V[6].V[14],MAT[14]->M_V[6].V[15]);
//}
//
//void print_mat14_7()
//{
//	 fprintf(fp_mat14_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[7].V[0],MAT[14]->M_V[7].V[1],MAT[14]->M_V[7].V[2],MAT[14]->M_V[7].V[3],MAT[14]->M_V[7].V[4],MAT[14]->M_V[7].V[5],MAT[14]->M_V[7].V[6],MAT[14]->M_V[7].V[7],MAT[14]->M_V[7].V[8],MAT[14]->M_V[7].V[9],MAT[14]->M_V[7].V[10],MAT[14]->M_V[7].V[11],MAT[14]->M_V[7].V[12],MAT[14]->M_V[7].V[13],MAT[14]->M_V[7].V[14],MAT[14]->M_V[0].V[15]);
//}
//
//void print_mat14_8()
//{
//	fprintf(fp_mat14_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[8].V[0],MAT[14]->M_V[8].V[1],MAT[14]->M_V[8].V[2],MAT[14]->M_V[8].V[3],MAT[14]->M_V[8].V[4],MAT[14]->M_V[8].V[5],MAT[14]->M_V[8].V[6],MAT[14]->M_V[8].V[7],MAT[14]->M_V[8].V[8],MAT[14]->M_V[8].V[9],MAT[14]->M_V[8].V[10],MAT[14]->M_V[8].V[11],MAT[14]->M_V[8].V[12],MAT[14]->M_V[8].V[13],MAT[14]->M_V[8].V[14],MAT[14]->M_V[8].V[15]);
//}
//
//void print_mat14_9()
//{
//	fprintf(fp_mat14_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[9].V[0],MAT[14]->M_V[9].V[1],MAT[14]->M_V[9].V[2],MAT[14]->M_V[9].V[3],MAT[14]->M_V[9].V[4],MAT[14]->M_V[9].V[5],MAT[14]->M_V[9].V[6],MAT[14]->M_V[9].V[7],MAT[14]->M_V[9].V[8],MAT[14]->M_V[9].V[9],MAT[14]->M_V[9].V[10],MAT[14]->M_V[9].V[11],MAT[14]->M_V[9].V[12],MAT[14]->M_V[9].V[13],MAT[14]->M_V[9].V[14],MAT[14]->M_V[9].V[15]);
//}
//
//void print_mat14_10()
//{
//	 fprintf(fp_mat14_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[10].V[0],MAT[14]->M_V[10].V[1],MAT[14]->M_V[10].V[2],MAT[14]->M_V[10].V[3],MAT[14]->M_V[10].V[4],MAT[14]->M_V[10].V[5],MAT[14]->M_V[10].V[6],MAT[14]->M_V[10].V[7],MAT[14]->M_V[10].V[8],MAT[14]->M_V[10].V[9],MAT[14]->M_V[10].V[10],MAT[14]->M_V[10].V[11],MAT[14]->M_V[10].V[12],MAT[14]->M_V[10].V[13],MAT[14]->M_V[10].V[14],MAT[14]->M_V[10].V[15]);
//}
//
//void print_mat14_11()
//{
//	fprintf(fp_mat14_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[11].V[0],MAT[14]->M_V[11].V[1],MAT[14]->M_V[12].V[2],MAT[14]->M_V[11].V[3],MAT[14]->M_V[11].V[4],MAT[14]->M_V[11].V[5],MAT[14]->M_V[11].V[6],MAT[14]->M_V[11].V[7],MAT[14]->M_V[11].V[8],MAT[14]->M_V[11].V[9],MAT[14]->M_V[11].V[10],MAT[14]->M_V[11].V[11],MAT[14]->M_V[11].V[12],MAT[14]->M_V[11].V[13],MAT[14]->M_V[11].V[14],MAT[14]->M_V[11].V[15]);
//}
//
//void print_mat14_12()
//{
//	fprintf(fp_mat14_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[12].V[0],MAT[14]->M_V[12].V[1],MAT[14]->M_V[13].V[2],MAT[14]->M_V[12].V[3],MAT[14]->M_V[12].V[4],MAT[14]->M_V[12].V[5],MAT[14]->M_V[12].V[6],MAT[14]->M_V[12].V[7],MAT[14]->M_V[12].V[8],MAT[14]->M_V[12].V[9],MAT[14]->M_V[12].V[10],MAT[14]->M_V[12].V[11],MAT[14]->M_V[12].V[12],MAT[14]->M_V[12].V[13],MAT[14]->M_V[12].V[14],MAT[14]->M_V[12].V[15]);
//}
//
//void print_mat14_13()
//{
//	 fprintf(fp_mat14_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[13].V[0],MAT[14]->M_V[13].V[1],MAT[14]->M_V[14].V[2],MAT[14]->M_V[13].V[3],MAT[14]->M_V[13].V[4],MAT[14]->M_V[13].V[5],MAT[14]->M_V[13].V[6],MAT[14]->M_V[13].V[7],MAT[14]->M_V[13].V[8],MAT[14]->M_V[13].V[9],MAT[14]->M_V[13].V[10],MAT[14]->M_V[13].V[11],MAT[14]->M_V[13].V[12],MAT[14]->M_V[13].V[13],MAT[14]->M_V[13].V[14],MAT[14]->M_V[13].V[15]);
//}
//
//void print_mat14_14()
//{
//	fprintf(fp_mat14_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[14].V[0],MAT[14]->M_V[14].V[1],MAT[14]->M_V[15].V[2],MAT[14]->M_V[14].V[3],MAT[14]->M_V[14].V[4],MAT[14]->M_V[14].V[5],MAT[14]->M_V[14].V[6],MAT[14]->M_V[14].V[7],MAT[14]->M_V[14].V[8],MAT[14]->M_V[14].V[9],MAT[14]->M_V[14].V[10],MAT[14]->M_V[14].V[11],MAT[14]->M_V[14].V[12],MAT[14]->M_V[14].V[13],MAT[14]->M_V[14].V[14],MAT[14]->M_V[14].V[15]);
//}
//
//void print_mat14_15()
//{
//	 fprintf(fp_mat14_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[15].V[0],MAT[14]->M_V[15].V[1],MAT[14]->M_V[16].V[2],MAT[14]->M_V[15].V[3],MAT[14]->M_V[15].V[4],MAT[14]->M_V[15].V[5],MAT[14]->M_V[15].V[6],MAT[14]->M_V[15].V[7],MAT[14]->M_V[15].V[8],MAT[14]->M_V[15].V[9],MAT[14]->M_V[15].V[10],MAT[14]->M_V[15].V[11],MAT[14]->M_V[15].V[12],MAT[14]->M_V[15].V[13],MAT[14]->M_V[15].V[14],MAT[14]->M_V[15].V[15]);
//}
//
//
//void print_mat15_0()
//{
//	fprintf(fp_mat15_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[0].V[0],MAT[15]->M_V[0].V[1],MAT[15]->M_V[0].V[2],MAT[15]->M_V[0].V[3],MAT[15]->M_V[0].V[4],MAT[15]->M_V[0].V[5],MAT[15]->M_V[0].V[6],MAT[15]->M_V[0].V[7],MAT[15]->M_V[0].V[8],MAT[15]->M_V[0].V[9],MAT[15]->M_V[0].V[10],MAT[15]->M_V[0].V[11],MAT[15]->M_V[0].V[12],MAT[15]->M_V[0].V[13],MAT[15]->M_V[0].V[14],MAT[15]->M_V[0].V[15]);
//}
//
//void print_mat15_1()
//{
//	fprintf(fp_mat15_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[1].V[0],MAT[15]->M_V[1].V[1],MAT[15]->M_V[1].V[2],MAT[15]->M_V[1].V[3],MAT[15]->M_V[1].V[4],MAT[15]->M_V[1].V[5],MAT[15]->M_V[1].V[6],MAT[15]->M_V[1].V[7],MAT[15]->M_V[1].V[8],MAT[15]->M_V[1].V[9],MAT[15]->M_V[1].V[10],MAT[15]->M_V[1].V[11],MAT[15]->M_V[1].V[12],MAT[15]->M_V[1].V[13],MAT[15]->M_V[1].V[14],MAT[15]->M_V[1].V[15]);
//}
//
//void print_mat15_2()
//{
//	fprintf(fp_mat15_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[2].V[0],MAT[15]->M_V[2].V[1],MAT[15]->M_V[2].V[2],MAT[15]->M_V[2].V[3],MAT[15]->M_V[2].V[4],MAT[15]->M_V[2].V[5],MAT[15]->M_V[2].V[6],MAT[15]->M_V[2].V[7],MAT[15]->M_V[2].V[8],MAT[15]->M_V[2].V[9],MAT[15]->M_V[2].V[10],MAT[15]->M_V[2].V[11],MAT[15]->M_V[2].V[12],MAT[15]->M_V[2].V[13],MAT[15]->M_V[2].V[14],MAT[15]->M_V[2].V[15]);
//}
//
//void print_mat15_3()
//{
//	fprintf(fp_mat15_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[3].V[0],MAT[15]->M_V[3].V[1],MAT[15]->M_V[3].V[2],MAT[15]->M_V[3].V[3],MAT[15]->M_V[3].V[4],MAT[15]->M_V[3].V[5],MAT[15]->M_V[3].V[6],MAT[15]->M_V[3].V[7],MAT[15]->M_V[3].V[8],MAT[15]->M_V[3].V[9],MAT[15]->M_V[3].V[10],MAT[15]->M_V[3].V[11],MAT[15]->M_V[3].V[12],MAT[15]->M_V[3].V[13],MAT[15]->M_V[3].V[14],MAT[15]->M_V[3].V[15]);    
//}
//
//void print_mat15_4()
//{
//	fprintf(fp_mat15_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[4].V[0],MAT[15]->M_V[4].V[1],MAT[15]->M_V[4].V[2],MAT[15]->M_V[4].V[3],MAT[15]->M_V[4].V[4],MAT[15]->M_V[4].V[5],MAT[15]->M_V[4].V[6],MAT[15]->M_V[4].V[7],MAT[15]->M_V[4].V[8],MAT[15]->M_V[4].V[9],MAT[15]->M_V[4].V[10],MAT[15]->M_V[4].V[11],MAT[15]->M_V[4].V[12],MAT[15]->M_V[4].V[13],MAT[15]->M_V[4].V[14],MAT[15]->M_V[4].V[15]);
//}
//
//void print_mat15_5()
//{
//	fprintf(fp_mat15_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[5].V[0],MAT[15]->M_V[5].V[1],MAT[15]->M_V[5].V[2],MAT[15]->M_V[5].V[3],MAT[15]->M_V[5].V[4],MAT[15]->M_V[5].V[5],MAT[15]->M_V[5].V[6],MAT[15]->M_V[5].V[7],MAT[15]->M_V[5].V[8],MAT[15]->M_V[5].V[9],MAT[15]->M_V[5].V[10],MAT[15]->M_V[5].V[11],MAT[15]->M_V[5].V[12],MAT[15]->M_V[5].V[13],MAT[15]->M_V[5].V[14],MAT[15]->M_V[5].V[15]);
//}
//
//void print_mat15_6()
//{
//	fprintf(fp_mat15_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[6].V[0],MAT[15]->M_V[6].V[1],MAT[15]->M_V[6].V[2],MAT[15]->M_V[6].V[3],MAT[15]->M_V[6].V[4],MAT[15]->M_V[6].V[5],MAT[15]->M_V[6].V[6],MAT[15]->M_V[6].V[7],MAT[15]->M_V[6].V[8],MAT[15]->M_V[6].V[9],MAT[15]->M_V[6].V[10],MAT[15]->M_V[6].V[11],MAT[15]->M_V[6].V[12],MAT[15]->M_V[6].V[13],MAT[15]->M_V[6].V[14],MAT[15]->M_V[6].V[15]);
//}
//
//void print_mat15_7()
//{
//	fprintf(fp_mat15_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[7].V[0],MAT[15]->M_V[7].V[1],MAT[15]->M_V[7].V[2],MAT[15]->M_V[7].V[3],MAT[15]->M_V[7].V[4],MAT[15]->M_V[7].V[5],MAT[15]->M_V[7].V[6],MAT[15]->M_V[7].V[7],MAT[15]->M_V[7].V[8],MAT[15]->M_V[7].V[9],MAT[15]->M_V[7].V[10],MAT[15]->M_V[7].V[11],MAT[15]->M_V[7].V[12],MAT[15]->M_V[7].V[13],MAT[15]->M_V[7].V[14],MAT[15]->M_V[0].V[15]);
//}
//
//void print_mat15_8()
//{
//	fprintf(fp_mat15_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[8].V[0],MAT[15]->M_V[8].V[1],MAT[15]->M_V[8].V[2],MAT[15]->M_V[8].V[3],MAT[15]->M_V[8].V[4],MAT[15]->M_V[8].V[5],MAT[15]->M_V[8].V[6],MAT[15]->M_V[8].V[7],MAT[15]->M_V[8].V[8],MAT[15]->M_V[8].V[9],MAT[15]->M_V[8].V[10],MAT[15]->M_V[8].V[11],MAT[15]->M_V[8].V[12],MAT[15]->M_V[8].V[13],MAT[15]->M_V[8].V[14],MAT[15]->M_V[8].V[15]);
//}
//
//void print_mat15_9()
//{
//	fprintf(fp_mat15_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[9].V[0],MAT[15]->M_V[9].V[1],MAT[15]->M_V[9].V[2],MAT[15]->M_V[9].V[3],MAT[15]->M_V[9].V[4],MAT[15]->M_V[9].V[5],MAT[15]->M_V[9].V[6],MAT[15]->M_V[9].V[7],MAT[15]->M_V[9].V[8],MAT[15]->M_V[9].V[9],MAT[15]->M_V[9].V[10],MAT[15]->M_V[9].V[11],MAT[15]->M_V[9].V[12],MAT[15]->M_V[9].V[13],MAT[15]->M_V[9].V[14],MAT[15]->M_V[9].V[15]);
//}
//
//void print_mat15_10()
//{
//	fprintf(fp_mat15_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[10].V[0],MAT[15]->M_V[10].V[1],MAT[15]->M_V[10].V[2],MAT[15]->M_V[10].V[3],MAT[15]->M_V[10].V[4],MAT[15]->M_V[10].V[5],MAT[15]->M_V[10].V[6],MAT[15]->M_V[10].V[7],MAT[15]->M_V[10].V[8],MAT[15]->M_V[10].V[9],MAT[15]->M_V[10].V[10],MAT[15]->M_V[10].V[11],MAT[15]->M_V[10].V[12],MAT[15]->M_V[10].V[13],MAT[15]->M_V[10].V[14],MAT[15]->M_V[10].V[15]);
//}
//
//void print_mat15_11()
//{
//	 fprintf(fp_mat15_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[11].V[0],MAT[15]->M_V[11].V[1],MAT[15]->M_V[12].V[2],MAT[15]->M_V[11].V[3],MAT[15]->M_V[11].V[4],MAT[15]->M_V[11].V[5],MAT[15]->M_V[11].V[6],MAT[15]->M_V[11].V[7],MAT[15]->M_V[11].V[8],MAT[15]->M_V[11].V[9],MAT[15]->M_V[11].V[10],MAT[15]->M_V[11].V[11],MAT[15]->M_V[11].V[12],MAT[15]->M_V[11].V[13],MAT[15]->M_V[11].V[14],MAT[15]->M_V[11].V[15]);
//}
//
//void print_mat15_12()
//{
//	fprintf(fp_mat15_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[12].V[0],MAT[15]->M_V[12].V[1],MAT[15]->M_V[13].V[2],MAT[15]->M_V[12].V[3],MAT[15]->M_V[12].V[4],MAT[15]->M_V[12].V[5],MAT[15]->M_V[12].V[6],MAT[15]->M_V[12].V[7],MAT[15]->M_V[12].V[8],MAT[15]->M_V[12].V[9],MAT[15]->M_V[12].V[10],MAT[15]->M_V[12].V[11],MAT[15]->M_V[12].V[12],MAT[15]->M_V[12].V[13],MAT[15]->M_V[12].V[14],MAT[15]->M_V[12].V[15]);
//}
//
//void print_mat15_13()
//{
//	fprintf(fp_mat15_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[13].V[0],MAT[15]->M_V[13].V[1],MAT[15]->M_V[14].V[2],MAT[15]->M_V[13].V[3],MAT[15]->M_V[13].V[4],MAT[15]->M_V[13].V[5],MAT[15]->M_V[13].V[6],MAT[15]->M_V[13].V[7],MAT[15]->M_V[13].V[8],MAT[15]->M_V[13].V[9],MAT[15]->M_V[13].V[10],MAT[15]->M_V[13].V[11],MAT[15]->M_V[13].V[12],MAT[15]->M_V[13].V[13],MAT[15]->M_V[13].V[14],MAT[15]->M_V[13].V[15]);
//}
//
//void print_mat15_14()
//{
//	fprintf(fp_mat15_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[14].V[0],MAT[15]->M_V[14].V[1],MAT[15]->M_V[15].V[2],MAT[15]->M_V[14].V[3],MAT[15]->M_V[14].V[4],MAT[15]->M_V[14].V[5],MAT[15]->M_V[14].V[6],MAT[15]->M_V[14].V[7],MAT[15]->M_V[14].V[8],MAT[15]->M_V[14].V[9],MAT[15]->M_V[14].V[10],MAT[15]->M_V[14].V[11],MAT[15]->M_V[14].V[12],MAT[15]->M_V[14].V[13],MAT[15]->M_V[14].V[14],MAT[15]->M_V[14].V[15]);
//}
//
//void print_mat15_15()
//{
//	fprintf(fp_mat15_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[15].V[0],MAT[15]->M_V[15].V[1],MAT[15]->M_V[16].V[2],MAT[15]->M_V[15].V[3],MAT[15]->M_V[15].V[4],MAT[15]->M_V[15].V[5],MAT[15]->M_V[15].V[6],MAT[15]->M_V[15].V[7],MAT[15]->M_V[15].V[8],MAT[15]->M_V[15].V[9],MAT[15]->M_V[15].V[10],MAT[15]->M_V[15].V[11],MAT[15]->M_V[15].V[12],MAT[15]->M_V[15].V[13],MAT[15]->M_V[15].V[14],MAT[15]->M_V[15].V[15]);
//}

void open_file_mat()
{
	 if(access("mat",0))
    {
    	if( system("mkdir mat") !=0 )
		{
			printf(" cann't not creat mat folder.\n");
		}
	 }
	fp_mat0_0 = fopen(MAT0_0,"w+");
	if(fp_mat0_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_0);
		exit(0);
	}
	fp_mat0_1 = fopen(MAT0_1,"w+");
	if(fp_mat0_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_1);
		exit(0);
	}
	fp_mat0_2 = fopen(MAT0_2,"w+");
	if(fp_mat0_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_2);
		exit(0);
	}
	fp_mat0_3 = fopen(MAT0_3,"w+");
	if(fp_mat0_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_3);
		exit(0);
	}
	fp_mat0_4 = fopen(MAT0_4,"w+");
	if(fp_mat0_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_4);
		exit(0);
	}
	fp_mat0_5 = fopen(MAT0_5,"w+");
	if(fp_mat0_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_5);
		exit(0);
	}
	fp_mat0_6 = fopen(MAT0_6,"w+");
	if(fp_mat0_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_6);
		exit(0);
	}
	fp_mat0_7 = fopen(MAT0_7,"w+");
	if(fp_mat0_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_7);
		exit(0);
	}
	fp_mat0_8 = fopen(MAT0_8,"w+");
	if(fp_mat0_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_8);
		exit(0);
	}
	fp_mat0_9 = fopen(MAT0_9,"w+");
	if(fp_mat0_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_9);
		exit(0);
	}
	fp_mat0_10 = fopen(MAT0_10,"w+");
	if(fp_mat0_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_10);
		exit(0);
	}
	fp_mat0_11 = fopen(MAT0_11,"w+");
	if(fp_mat0_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_11);
		exit(0);
	}
	fp_mat0_12 = fopen(MAT0_12,"w+");
	if(fp_mat0_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_12);
		exit(0);
	}
	fp_mat0_13 = fopen(MAT0_13,"w+");
	if(fp_mat0_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_13);
		exit(0);
	}
	fp_mat0_14 = fopen(MAT0_14,"w+");
	if(fp_mat0_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_14);
		exit(0);
	}
	fp_mat0_15 = fopen(MAT0_15,"w+");
	if(fp_mat0_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT0_15);
		exit(0);
	}
	
	fp_mat1_0 = fopen(MAT1_0,"w+");
	if(fp_mat1_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_0);
		exit(0);
	}
	fp_mat1_1 = fopen(MAT1_1,"w+");
	if(fp_mat1_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_1);
		exit(0);
	}
	fp_mat1_2 = fopen(MAT1_2,"w+");
	if(fp_mat1_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_2);
		exit(0);
	}
	fp_mat1_3 = fopen(MAT1_3,"w+");
	if(fp_mat1_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_3);
		exit(0);
	}
	fp_mat1_4 = fopen(MAT1_4,"w+");
	if(fp_mat1_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_4);
		exit(0);
	}
	fp_mat1_5 = fopen(MAT1_5,"w+");
	if(fp_mat1_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_5);
		exit(0);
	}
	fp_mat1_6 = fopen(MAT1_6,"w+");
	if(fp_mat1_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_6);
		exit(0);
	}
	fp_mat1_7 = fopen(MAT1_7,"w+");
	if(fp_mat1_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_7);
		exit(0);
	}
	fp_mat1_8 = fopen(MAT1_8,"w+");
	if(fp_mat1_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_8);
		exit(0);
	}
	fp_mat1_9 = fopen(MAT1_9,"w+");
	if(fp_mat1_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_9);
		exit(0);
	}
	fp_mat1_10 = fopen(MAT1_10,"w+");
	if(fp_mat1_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_10);
		exit(0);
	}
	fp_mat1_11 = fopen(MAT1_11,"w+");
	if(fp_mat1_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_11);
		exit(0);
	}
	fp_mat1_12 = fopen(MAT1_12,"w+");
	if(fp_mat1_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_12);
		exit(0);
	}
	fp_mat1_13 = fopen(MAT1_13,"w+");
	if(fp_mat1_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_13);
		exit(0);
	}
	fp_mat1_14 = fopen(MAT1_14,"w+");
	if(fp_mat1_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_14);
		exit(0);
	}
	fp_mat1_15 = fopen(MAT1_15,"w+");
	if(fp_mat1_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT1_15);
		exit(0);
	}

	fp_mat2_0 = fopen(MAT2_0,"w+");
	if(fp_mat2_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_0);
		exit(0);
	}
	fp_mat2_1 = fopen(MAT2_1,"w+");
	if(fp_mat2_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_1);
		exit(0);
	}
	fp_mat2_2 = fopen(MAT2_2,"w+");
	if(fp_mat2_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_2);
		exit(0);
	}
	fp_mat2_3 = fopen(MAT2_3,"w+");
	if(fp_mat2_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_3);
		exit(0);
	}
	fp_mat2_4 = fopen(MAT2_4,"w+");
	if(fp_mat2_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_4);
		exit(0);
	}
	fp_mat2_5 = fopen(MAT2_5,"w+");
	if(fp_mat2_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_5);
		exit(0);
	}
	fp_mat2_6 = fopen(MAT2_6,"w+");
	if(fp_mat2_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_6);
		exit(0);
	}
	fp_mat2_7 = fopen(MAT2_7,"w+");
	if(fp_mat2_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_7);
		exit(0);
	}
	fp_mat2_8 = fopen(MAT2_8,"w+");
	if(fp_mat2_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_8);
		exit(0);
	}
	fp_mat2_9 = fopen(MAT2_9,"w+");
	if(fp_mat2_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_9);
		exit(0);
	}
	fp_mat2_10 = fopen(MAT2_10,"w+");
	if(fp_mat2_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_10);
		exit(0);
	}
	fp_mat2_11 = fopen(MAT2_11,"w+");
	if(fp_mat2_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_11);
		exit(0);
	}
	fp_mat2_12 = fopen(MAT2_12,"w+");
	if(fp_mat2_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_12);
		exit(0);
	}
	fp_mat2_13 = fopen(MAT2_13,"w+");
	if(fp_mat2_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_13);
		exit(0);
	}
	fp_mat2_14 = fopen(MAT2_14,"w+");
	if(fp_mat2_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_14);
		exit(0);
	}
	fp_mat2_15 = fopen(MAT2_15,"w+");
	if(fp_mat2_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT2_15);
		exit(0);
	}

	fp_mat3_0 = fopen(MAT3_0,"w+");
	if(fp_mat3_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_0);
		exit(0);
	}
	fp_mat3_1 = fopen(MAT3_1,"w+");
	if(fp_mat3_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_1);
		exit(0);
	}
	fp_mat3_2 = fopen(MAT3_2,"w+");
	if(fp_mat3_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_2);
		exit(0);
	}
	fp_mat3_3 = fopen(MAT3_3,"w+");
	if(fp_mat3_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_3);
		exit(0);
	}
	fp_mat3_4 = fopen(MAT3_4,"w+");
	if(fp_mat3_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_4);
		exit(0);
	}
	fp_mat3_5 = fopen(MAT3_5,"w+");
	if(fp_mat3_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_5);
		exit(0);
	}
	fp_mat3_6 = fopen(MAT3_6,"w+");
	if(fp_mat3_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_6);
		exit(0);
	}
	fp_mat3_7 = fopen(MAT3_7,"w+");
	if(fp_mat3_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_7);
		exit(0);
	}
	fp_mat3_8 = fopen(MAT3_8,"w+");
	if(fp_mat3_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_8);
		exit(0);
	}
	fp_mat3_9 = fopen(MAT3_9,"w+");
	if(fp_mat3_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_9);
		exit(0);
	}
	fp_mat3_10 = fopen(MAT3_10,"w+");
	if(fp_mat3_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_10);
		exit(0);
	}
	fp_mat3_11 = fopen(MAT3_11,"w+");
	if(fp_mat3_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_11);
		exit(0);
	}
	fp_mat3_12 = fopen(MAT3_12,"w+");
	if(fp_mat3_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_12);
		exit(0);
	}
	fp_mat3_13 = fopen(MAT3_13,"w+");
	if(fp_mat3_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_13);
		exit(0);
	}
	fp_mat3_14 = fopen(MAT3_14,"w+");
	if(fp_mat3_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_14);
		exit(0);
	}
	fp_mat3_15 = fopen(MAT3_15,"w+");
	if(fp_mat3_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT3_15);
		exit(0);
	}

	fp_mat4_0 = fopen(MAT4_0,"w+");
	if(fp_mat4_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_0);
		exit(0);
	}
	fp_mat4_1 = fopen(MAT4_1,"w+");
	if(fp_mat4_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_1);
		exit(0);
	}
	fp_mat4_2 = fopen(MAT4_2,"w+");
	if(fp_mat4_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_2);
		exit(0);
	}
	fp_mat4_3 = fopen(MAT4_3,"w+");
	if(fp_mat4_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_3);
		exit(0);
	}
	fp_mat4_4 = fopen(MAT4_4,"w+");
	if(fp_mat4_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_4);
		exit(0);
	}
	fp_mat4_5 = fopen(MAT4_5,"w+");
	if(fp_mat4_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_5);
		exit(0);
	}
	fp_mat4_6 = fopen(MAT4_6,"w+");
	if(fp_mat4_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_6);
		exit(0);
	}
	fp_mat4_7 = fopen(MAT4_7,"w+");
	if(fp_mat4_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_7);
		exit(0);
	}
	fp_mat4_8 = fopen(MAT4_8,"w+");
	if(fp_mat4_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_8);
		exit(0);
	}
	fp_mat4_9 = fopen(MAT4_9,"w+");
	if(fp_mat4_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_9);
		exit(0);
	}
	fp_mat4_10 = fopen(MAT4_10,"w+");
	if(fp_mat4_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_10);
		exit(0);
	}
	fp_mat4_11 = fopen(MAT4_11,"w+");
	if(fp_mat4_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_11);
		exit(0);
	}
	fp_mat4_12 = fopen(MAT4_12,"w+");
	if(fp_mat4_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_12);
		exit(0);
	}
	fp_mat4_13 = fopen(MAT4_13,"w+");
	if(fp_mat4_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_13);
		exit(0);
	}
	fp_mat4_14 = fopen(MAT4_14,"w+");
	if(fp_mat4_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_14);
		exit(0);
	}
	fp_mat4_15 = fopen(MAT4_15,"w+");
	if(fp_mat4_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT4_15);
		exit(0);
	}

	fp_mat5_0 = fopen(MAT5_0,"w+");
	if(fp_mat5_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_0);
		exit(0);
	}
	fp_mat5_1 = fopen(MAT5_1,"w+");
	if(fp_mat5_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_1);
		exit(0);
	}
	fp_mat5_2 = fopen(MAT5_2,"w+");
	if(fp_mat5_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_2);
		exit(0);
	}
	fp_mat5_3 = fopen(MAT5_3,"w+");
	if(fp_mat5_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_3);
		exit(0);
	}
	fp_mat5_4 = fopen(MAT5_4,"w+");
	if(fp_mat5_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_4);
		exit(0);
	}
	fp_mat5_5 = fopen(MAT5_5,"w+");
	if(fp_mat5_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_5);
		exit(0);
	}
	fp_mat5_6 = fopen(MAT5_6,"w+");
	if(fp_mat5_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_6);
		exit(0);
	}
	fp_mat5_7 = fopen(MAT5_7,"w+");
	if(fp_mat5_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_7);
		exit(0);
	}
	fp_mat5_8 = fopen(MAT5_8,"w+");
	if(fp_mat5_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_8);
		exit(0);
	}
	fp_mat5_9 = fopen(MAT5_9,"w+");
	if(fp_mat5_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_9);
		exit(0);
	}
	fp_mat5_10 = fopen(MAT5_10,"w+");
	if(fp_mat5_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_10);
		exit(0);
	}
	fp_mat5_11 = fopen(MAT5_11,"w+");
	if(fp_mat5_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_11);
		exit(0);
	}
	fp_mat5_12 = fopen(MAT5_12,"w+");
	if(fp_mat5_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_12);
		exit(0);
	}
	fp_mat5_13 = fopen(MAT5_13,"w+");
	if(fp_mat5_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_13);
		exit(0);
	}
	fp_mat5_14 = fopen(MAT5_14,"w+");
	if(fp_mat5_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_14);
		exit(0);
	}
	fp_mat5_15 = fopen(MAT5_15,"w+");
	if(fp_mat5_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT5_15);
		exit(0);
	}

	fp_mat6_0 = fopen(MAT6_0,"w+");
	if(fp_mat6_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_0);
		exit(0);
	}
	fp_mat6_1 = fopen(MAT6_1,"w+");
	if(fp_mat6_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_1);
		exit(0);
	}
	fp_mat6_2 = fopen(MAT6_2,"w+");
	if(fp_mat6_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_2);
		exit(0);
	}
	fp_mat6_3 = fopen(MAT6_3,"w+");
	if(fp_mat6_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_3);
		exit(0);
	}
	fp_mat6_4 = fopen(MAT6_4,"w+");
	if(fp_mat6_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_4);
		exit(0);
	}
	fp_mat6_5 = fopen(MAT6_5,"w+");
	if(fp_mat6_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_5);
		exit(0);
	}
	fp_mat6_6 = fopen(MAT6_6,"w+");
	if(fp_mat6_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_6);
		exit(0);
	}
	fp_mat6_7 = fopen(MAT6_7,"w+");
	if(fp_mat6_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_7);
		exit(0);
	}
	fp_mat6_8 = fopen(MAT6_8,"w+");
	if(fp_mat6_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_8);
		exit(0);
	}
	fp_mat6_9 = fopen(MAT6_9,"w+");
	if(fp_mat6_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_9);
		exit(0);
	}
	fp_mat6_10 = fopen(MAT6_10,"w+");
	if(fp_mat6_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_10);
		exit(0);
	}
	fp_mat6_11 = fopen(MAT6_11,"w+");
	if(fp_mat6_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_11);
		exit(0);
	}
	fp_mat6_12 = fopen(MAT6_12,"w+");
	if(fp_mat6_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_12);
		exit(0);
	}
	fp_mat6_13 = fopen(MAT6_13,"w+");
	if(fp_mat6_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_13);
		exit(0);
	}
	fp_mat6_14 = fopen(MAT6_14,"w+");
	if(fp_mat6_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_14);
		exit(0);
	}
	fp_mat6_15 = fopen(MAT6_15,"w+");
	if(fp_mat6_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT6_15);
		exit(0);
	}

	fp_mat7_0 = fopen(MAT7_0,"w+");
	if(fp_mat7_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_0);
		exit(0);
	}
	fp_mat7_1 = fopen(MAT7_1,"w+");
	if(fp_mat7_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_1);
		exit(0);
	}
	fp_mat7_2 = fopen(MAT7_2,"w+");
	if(fp_mat7_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_2);
		exit(0);
	}
	fp_mat7_3 = fopen(MAT7_3,"w+");
	if(fp_mat7_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_3);
		exit(0);
	}
	fp_mat7_4 = fopen(MAT7_4,"w+");
	if(fp_mat7_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_4);
		exit(0);
	}
	fp_mat7_5 = fopen(MAT7_5,"w+");
	if(fp_mat7_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_5);
		exit(0);
	}
	fp_mat7_6 = fopen(MAT7_6,"w+");
	if(fp_mat7_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_6);
		exit(0);
	}
	fp_mat7_7 = fopen(MAT7_7,"w+");
	if(fp_mat7_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_7);
		exit(0);
	}
	fp_mat7_8 = fopen(MAT7_8,"w+");
	if(fp_mat7_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_8);
		exit(0);
	}
	fp_mat7_9 = fopen(MAT7_9,"w+");
	if(fp_mat7_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_9);
		exit(0);
	}
	fp_mat7_10 = fopen(MAT7_10,"w+");
	if(fp_mat7_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_10);
		exit(0);
	}
	fp_mat7_11 = fopen(MAT7_11,"w+");
	if(fp_mat7_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_11);
		exit(0);
	}
	fp_mat7_12 = fopen(MAT7_12,"w+");
	if(fp_mat7_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_12);
		exit(0);
	}
	fp_mat7_13 = fopen(MAT7_13,"w+");
	if(fp_mat7_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_13);
		exit(0);
	}
	fp_mat7_14 = fopen(MAT7_14,"w+");
	if(fp_mat7_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_14);
		exit(0);
	}
	fp_mat7_15 = fopen(MAT7_15,"w+");
	if(fp_mat7_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT7_15);
		exit(0);
	}

	/*fp_mat8_0 = fopen(MAT8_0,"w+");
	if(fp_mat8_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_0);
		exit(0);
	}
	fp_mat8_1 = fopen(MAT8_1,"w+");
	if(fp_mat8_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_1);
		exit(0);
	}
	fp_mat8_2 = fopen(MAT8_2,"w+");
	if(fp_mat8_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_2);
		exit(0);
	}
	fp_mat8_3 = fopen(MAT8_3,"w+");
	if(fp_mat8_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_3);
		exit(0);
	}
	fp_mat8_4 = fopen(MAT8_4,"w+");
	if(fp_mat8_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_4);
		exit(0);
	}
	fp_mat8_5 = fopen(MAT8_5,"w+");
	if(fp_mat8_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_5);
		exit(0);
	}
	fp_mat8_6 = fopen(MAT8_6,"w+");
	if(fp_mat8_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_6);
		exit(0);
	}
	fp_mat8_7 = fopen(MAT8_7,"w+");
	if(fp_mat8_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_7);
		exit(0);
	}
	fp_mat8_8 = fopen(MAT8_8,"w+");
	if(fp_mat8_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_8);
		exit(0);
	}
	fp_mat8_9 = fopen(MAT8_9,"w+");
	if(fp_mat8_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_9);
		exit(0);
	}
	fp_mat8_10 = fopen(MAT8_10,"w+");
	if(fp_mat8_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_10);
		exit(0);
	}
	fp_mat8_11 = fopen(MAT8_11,"w+");
	if(fp_mat8_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_11);
		exit(0);
	}
	fp_mat8_12 = fopen(MAT8_12,"w+");
	if(fp_mat8_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_12);
	    exit(0);
	}
	fp_mat8_13 = fopen(MAT8_13,"w+");
	if(fp_mat8_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_13);
		exit(0);
	}
	fp_mat8_14 = fopen(MAT8_14,"w+");
	if(fp_mat8_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_14);
		exit(0);
	}
	fp_mat8_15 = fopen(MAT8_15,"w+");
	if(fp_mat8_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT8_15);
		exit(0);
	}

	fp_mat9_0 = fopen(MAT9_0,"w+");
	if(fp_mat9_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_0);
		exit(0);
	}
	fp_mat9_1 = fopen(MAT9_1,"w+");
	if(fp_mat9_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_1);
		exit(0);
	}
	fp_mat9_2 = fopen(MAT9_2,"w+");
	if(fp_mat9_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_2);
		exit(0);
	}
	fp_mat9_3 = fopen(MAT9_3,"w+");
	if(fp_mat9_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_3);
		exit(0);
	}
	fp_mat9_4 = fopen(MAT9_4,"w+");
	if(fp_mat9_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_4);
		exit(0);
	}
	fp_mat9_5 = fopen(MAT9_5,"w+");
	if(fp_mat9_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_5);
		exit(0);
	}
	fp_mat9_6 = fopen(MAT9_6,"w+");
	if(fp_mat9_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_6);
		exit(0);
	}
	fp_mat9_7 = fopen(MAT9_7,"w+");
	if(fp_mat9_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_7);
		exit(0);
	}
	fp_mat9_8 = fopen(MAT9_8,"w+");
	if(fp_mat9_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_8);
		exit(0);
	}
	fp_mat9_9 = fopen(MAT9_9,"w+");
	if(fp_mat9_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_9);
		exit(0);
	}
	fp_mat9_10 = fopen(MAT9_10,"w+");
	if(fp_mat9_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_10);
		exit(0);
	}
	fp_mat9_11 = fopen(MAT9_11,"w+");
	if(fp_mat9_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_11);
		exit(0);
	}
	fp_mat9_12 = fopen(MAT9_12,"w+");
	if(fp_mat9_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_12);
		exit(0);
	}
	fp_mat9_13 = fopen(MAT9_13,"w+");
	if(fp_mat9_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_13);
		exit(0);
	}
	fp_mat9_14 = fopen(MAT9_14,"w+");
	if(fp_mat9_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_14);
		exit(0);
	}
	fp_mat9_15 = fopen(MAT9_15,"w+");
	if(fp_mat9_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT9_15);
		exit(0);
	}

	fp_mat10_0 = fopen(MAT10_0,"w+");
	if(fp_mat10_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_0);
		exit(0);
	}
	fp_mat10_1 = fopen(MAT10_1,"w+");
	if(fp_mat10_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_1);
		exit(0);
	}
	fp_mat10_2 = fopen(MAT10_2,"w+");
	if(fp_mat10_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_2);
		exit(0);
	}
	fp_mat10_3 = fopen(MAT10_3,"w+");
	if(fp_mat10_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_3);
		exit(0);
	}
	fp_mat10_4 = fopen(MAT10_4,"w+");
	if(fp_mat10_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_4);
		exit(0);
	}
	fp_mat10_5 = fopen(MAT10_5,"w+");
	if(fp_mat10_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_5);
		exit(0);
	}
	fp_mat10_6 = fopen(MAT10_6,"w+");
	if(fp_mat10_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_6);
		exit(0);
	}
	fp_mat10_7 = fopen(MAT10_7,"w+");
	if(fp_mat10_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_7);
		exit(0);
	}
	fp_mat10_8 = fopen(MAT10_8,"w+");
	if(fp_mat10_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_8);
		exit(0);
	}
	fp_mat10_9 = fopen(MAT10_9,"w+");
	if(fp_mat10_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_9);
		exit(0);
	}
	fp_mat10_10 = fopen(MAT10_10,"w+");
	if(fp_mat10_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_10);
		exit(0);
	}
	fp_mat10_11 = fopen(MAT10_11,"w+");
	if(fp_mat10_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_11);
		exit(0);
	}
	fp_mat10_12 = fopen(MAT10_12,"w+");
	if(fp_mat10_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_12);
		exit(0);
	}
	fp_mat10_13 = fopen(MAT10_13,"w+");
	if(fp_mat10_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_13);
		exit(0);
	}
	fp_mat10_14 = fopen(MAT10_14,"w+");
	if(fp_mat10_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_14);
		exit(0);
	}
	fp_mat10_15 = fopen(MAT10_15,"w+");
	if(fp_mat10_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT10_15);
		exit(0);
	}

	fp_mat11_0 = fopen(MAT11_0,"w+");
	if(fp_mat11_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_0);
		exit(0);
	}
	fp_mat11_1 = fopen(MAT11_1,"w+");
	if(fp_mat11_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_1);
		exit(0);
	}
	fp_mat11_2 = fopen(MAT11_2,"w+");
	if(fp_mat11_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_2);
		exit(0);
	}
	fp_mat11_3 = fopen(MAT11_3,"w+");
	if(fp_mat11_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_3);
		exit(0);
	}
	fp_mat11_4 = fopen(MAT11_4,"w+");
	if(fp_mat11_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_4);
		exit(0);
	}
	fp_mat11_5 = fopen(MAT11_5,"w+");
	if(fp_mat11_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_5);
		exit(0);
	}
	fp_mat11_6 = fopen(MAT11_6,"w+");
	if(fp_mat11_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_6);
		exit(0);
	}
	fp_mat11_7 = fopen(MAT11_7,"w+");
	if(fp_mat11_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_7);
		exit(0);
	}
	fp_mat11_8 = fopen(MAT11_8,"w+");
	if(fp_mat11_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_8);
		exit(0);
	}
	fp_mat11_9 = fopen(MAT11_9,"w+");
	if(fp_mat11_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_9);
		exit(0);
	}
	fp_mat11_10 = fopen(MAT11_10,"w+");
	if(fp_mat11_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_10);
		exit(0);
	}
	fp_mat11_11 = fopen(MAT11_11,"w+");
	if(fp_mat11_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_11);
		exit(0);
	}
	fp_mat11_12 = fopen(MAT11_12,"w+");
	if(fp_mat11_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_12);
		exit(0);
	}
	fp_mat11_13 = fopen(MAT11_13,"w+");
	if(fp_mat11_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_13);
		exit(0);
	}
	fp_mat11_14 = fopen(MAT11_14,"w+");
	if(fp_mat11_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_14);
		exit(0);
	}
	fp_mat11_15 = fopen(MAT11_15,"w+");
	if(fp_mat11_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT11_15);
		exit(0);
	}

	fp_mat12_0 = fopen(MAT12_0,"w+");
	if(fp_mat12_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_0);
		exit(0);
	}
	fp_mat12_1 = fopen(MAT12_1,"w+");
	if(fp_mat12_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_1);
		exit(0);
	}
	fp_mat12_2 = fopen(MAT12_2,"w+");
	if(fp_mat12_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_2);
		exit(0);
	}
	fp_mat12_3 = fopen(MAT12_3,"w+");
	if(fp_mat12_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_3);
		exit(0);
	}
	fp_mat12_4 = fopen(MAT12_4,"w+");
	if(fp_mat12_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_4);
		exit(0);
	}
	fp_mat12_5 = fopen(MAT12_5,"w+");
	if(fp_mat12_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_5);
		exit(0);
	}
	fp_mat12_6 = fopen(MAT12_6,"w+");
	if(fp_mat12_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_6);
		exit(0);
	}
	fp_mat12_7 = fopen(MAT12_7,"w+");
	if(fp_mat12_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_7);
		exit(0);
	}
	fp_mat12_8 = fopen(MAT12_8,"w+");
	if(fp_mat12_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_8);
		exit(0);
	}
	fp_mat12_9 = fopen(MAT12_9,"w+");
	if(fp_mat12_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_9);
		exit(0);
	}
	fp_mat12_10 = fopen(MAT12_10,"w+");
	if(fp_mat12_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_10);
		exit(0);
	}
	fp_mat12_11 = fopen(MAT12_11,"w+");
	if(fp_mat12_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_11);
		exit(0);
	}
	fp_mat12_12 = fopen(MAT12_12,"w+");
	if(fp_mat12_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_12);
		exit(0);
	}
	fp_mat12_13 = fopen(MAT12_13,"w+");
	if(fp_mat12_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_13);
		exit(0);
	}
	fp_mat12_14 = fopen(MAT12_14,"w+");
	if(fp_mat12_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_14);
		exit(0);
	}
	fp_mat12_15 = fopen(MAT12_15,"w+");
	if(fp_mat12_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT12_15);
		exit(0);
	}

	fp_mat13_0 = fopen(MAT13_0,"w+");
	if(fp_mat13_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_0);
		exit(0);
	}
	fp_mat13_1 = fopen(MAT13_1,"w+");
	if(fp_mat13_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_1);
		exit(0);
	}
	fp_mat13_2 = fopen(MAT13_2,"w+");
	if(fp_mat13_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_2);
		exit(0);
	}
	fp_mat13_3 = fopen(MAT13_3,"w+");
	if(fp_mat13_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_3);
		exit(0);
	}
	fp_mat13_4 = fopen(MAT13_4,"w+");
	if(fp_mat13_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_4);
		exit(0);
	}
	fp_mat13_5 = fopen(MAT13_5,"w+");
	if(fp_mat13_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_5);
		exit(0);
	}
	fp_mat13_6 = fopen(MAT13_6,"w+");
	if(fp_mat13_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_6);
		exit(0);
	}
	fp_mat13_7 = fopen(MAT13_7,"w+");
	if(fp_mat13_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_7);
	}
	fp_mat13_8 = fopen(MAT13_8,"w+");
	if(fp_mat13_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_8);
		exit(0);
	}
	fp_mat13_9 = fopen(MAT13_9,"w+");
	if(fp_mat13_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_9);
		exit(0);
	}
	fp_mat13_10 = fopen(MAT13_10,"w+");
	if(fp_mat13_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_10);
		exit(0);
	}
	fp_mat13_11 = fopen(MAT13_11,"w+");
	if(fp_mat13_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_11);
		exit(0);
	}
	fp_mat13_12 = fopen(MAT13_12,"w+");
	if(fp_mat13_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_12);
		exit(0);
	}
	fp_mat13_13 = fopen(MAT13_13,"w+");
	if(fp_mat13_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_12);
		exit(0);
	}
	fp_mat13_14 = fopen(MAT13_14,"w+");
	if(fp_mat13_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_14);
		exit(0);
	}
	fp_mat13_15 = fopen(MAT13_15,"w+");
	if(fp_mat13_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT13_15);
		exit(0);
	}

	fp_mat14_0 = fopen(MAT14_0,"w+");
	if(fp_mat14_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_0);
		exit(0);
	}
	fp_mat14_1 = fopen(MAT14_1,"w+");
	if(fp_mat14_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_1);
		exit(0);
	}
	fp_mat14_2 = fopen(MAT14_2,"w+");
	if(fp_mat14_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_2);
		exit(0);
	}
	fp_mat14_3 = fopen(MAT14_3,"w+");
	if(fp_mat14_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_3);
		exit(0);
	}
	fp_mat14_4 = fopen(MAT14_4,"w+");
	if(fp_mat14_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_4);
		exit(0);
	}
	fp_mat14_5 = fopen(MAT14_5,"w+");
	if(fp_mat14_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_5);
		exit(0);
	}
	fp_mat14_6 = fopen(MAT14_6,"w+");
	if(fp_mat14_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_6);
		exit(0);
	}
	fp_mat14_7 = fopen(MAT14_7,"w+");
	if(fp_mat14_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_7);
		exit(0);
	}
	fp_mat14_8 = fopen(MAT14_8,"w+");
	if(fp_mat14_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_8);
		exit(0);
	}
	fp_mat14_9 = fopen(MAT14_9,"w+");
	if(fp_mat14_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_9);
		exit(0);
	}
	fp_mat14_10 = fopen(MAT14_10,"w+");
	if(fp_mat14_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_10);
		exit(0);
	}
	fp_mat14_11 = fopen(MAT14_11,"w+");
	if(fp_mat14_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_11);
		exit(0);
	}
	fp_mat14_12 = fopen(MAT14_12,"w+");
	if(fp_mat14_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_12);
		exit(0);
	}
	fp_mat14_13 = fopen(MAT14_13,"w+");
	if(fp_mat14_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_13);
		exit(0);
	}
	fp_mat14_14 = fopen(MAT14_14,"w+");
	if(fp_mat14_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_14);
		exit(0);
	}
	fp_mat14_15 = fopen(MAT14_15,"w+");
	if(fp_mat14_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT14_15);
		exit(0);
	}

	fp_mat15_0 = fopen(MAT15_0,"w+");
	if(fp_mat15_0==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_0);
		exit(0);
	}
	fp_mat15_1 = fopen(MAT15_1,"w+");
	if(fp_mat15_1==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_1);
		exit(0);
	}
	fp_mat15_2 = fopen(MAT15_2,"w+");
	if(fp_mat15_2==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_2);
		exit(0);
	}
	fp_mat15_3 = fopen(MAT15_3,"w+");
	if(fp_mat15_3==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_3);
		exit(0);
	}
	fp_mat15_4 = fopen(MAT15_4,"w+");
	if(fp_mat15_4==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_4);
		exit(0);
	}
	fp_mat15_5 = fopen(MAT15_5,"w+");
	if(fp_mat15_5==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_5);
		exit(0);
	}
	fp_mat15_6 = fopen(MAT15_6,"w+");
	if(fp_mat15_6==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_6);
		exit(0);
	}
	fp_mat15_7 = fopen(MAT15_7,"w+");
	if(fp_mat15_7==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_7);
		exit(0);
	}
	fp_mat15_8 = fopen(MAT15_8,"w+");
	if(fp_mat15_8==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_8);
		exit(0);
	}
	fp_mat15_9 = fopen(MAT15_9,"w+");
	if(fp_mat15_9==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_9);
		exit(0);
	}
	fp_mat15_10 = fopen(MAT15_10,"w+");
	if(fp_mat15_10==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_10);
		exit(0);
	}
	fp_mat15_11 = fopen(MAT15_11,"w+");
	if(fp_mat15_11==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_11);
		exit(0);
	}
	fp_mat15_12 = fopen(MAT15_12,"w+");
	if(fp_mat15_12==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_12);
		exit(0);
	}
	fp_mat15_13 = fopen(MAT15_13,"w+");
	if(fp_mat15_13==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_13);
		exit(0);
	}
	fp_mat15_14 = fopen(MAT15_14,"w+");
	if(fp_mat15_14==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_14);
		exit(0);
	}
	fp_mat15_15 = fopen(MAT15_15,"w+");
	if(fp_mat15_15==NULL)
	{
		printf("cann't open %s file in print_mat.\n",MAT15_15);
		exit(0);
	}*/
}

void close_file_mat()
{
	fclose(fp_mat0_0);
	fclose(fp_mat0_1);
	fclose(fp_mat0_2);
	fclose(fp_mat0_3);
	fclose(fp_mat0_4);
	fclose(fp_mat0_5);
	fclose(fp_mat0_6);
	fclose(fp_mat0_7);
	fclose(fp_mat0_8);
	fclose(fp_mat0_9);
	fclose(fp_mat0_10);
	fclose(fp_mat0_11);
	fclose(fp_mat0_12);
	fclose(fp_mat0_13);
	fclose(fp_mat0_14);
	fclose(fp_mat0_15);

	fclose(fp_mat1_0);
	fclose(fp_mat1_1);
	fclose(fp_mat1_2);
	fclose(fp_mat1_3);
	fclose(fp_mat1_4);
	fclose(fp_mat1_5);
	fclose(fp_mat1_6);
	fclose(fp_mat1_7);
	fclose(fp_mat1_8);
	fclose(fp_mat1_9);
	fclose(fp_mat1_10);
	fclose(fp_mat1_11);
	fclose(fp_mat1_12);
	fclose(fp_mat1_13);
	fclose(fp_mat1_14);
	fclose(fp_mat1_15);

	fclose(fp_mat2_0);
	fclose(fp_mat2_1);
	fclose(fp_mat2_2);
	fclose(fp_mat2_3);
	fclose(fp_mat2_4);
	fclose(fp_mat2_5);
	fclose(fp_mat2_6);
	fclose(fp_mat2_7);
	fclose(fp_mat2_8);
	fclose(fp_mat2_9);
	fclose(fp_mat2_10);
	fclose(fp_mat2_11);
	fclose(fp_mat2_12);
	fclose(fp_mat2_13);
	fclose(fp_mat2_14);
	fclose(fp_mat2_15);

	fclose(fp_mat3_0);
	fclose(fp_mat3_1);
	fclose(fp_mat3_2);
	fclose(fp_mat3_3);
	fclose(fp_mat3_4);
	fclose(fp_mat3_5);
	fclose(fp_mat3_6);
	fclose(fp_mat3_7);
	fclose(fp_mat3_8);
	fclose(fp_mat3_9);
	fclose(fp_mat3_10);
	fclose(fp_mat3_11);
	fclose(fp_mat3_12);
	fclose(fp_mat3_13);
	fclose(fp_mat3_14);
	fclose(fp_mat3_15);

	fclose(fp_mat4_0);
	fclose(fp_mat4_1);
	fclose(fp_mat4_2);
	fclose(fp_mat4_3);
	fclose(fp_mat4_4);
	fclose(fp_mat4_5);
	fclose(fp_mat4_6);
	fclose(fp_mat4_7);
	fclose(fp_mat4_8);
	fclose(fp_mat4_9);
	fclose(fp_mat4_10);
	fclose(fp_mat4_11);
	fclose(fp_mat4_12);
	fclose(fp_mat4_13);
	fclose(fp_mat4_14);
	fclose(fp_mat4_15);

	fclose(fp_mat5_0);
	fclose(fp_mat5_1);
	fclose(fp_mat5_2);
	fclose(fp_mat5_3);
	fclose(fp_mat5_4);
	fclose(fp_mat5_5);
	fclose(fp_mat5_6);
	fclose(fp_mat5_7);
	fclose(fp_mat5_8);
	fclose(fp_mat5_9);
	fclose(fp_mat5_10);
	fclose(fp_mat5_11);
	fclose(fp_mat5_12);
	fclose(fp_mat5_13);
	fclose(fp_mat5_14);
	fclose(fp_mat5_15);

	fclose(fp_mat6_0);
	fclose(fp_mat6_1);
	fclose(fp_mat6_2);
	fclose(fp_mat6_3);
	fclose(fp_mat6_4);
	fclose(fp_mat6_5);
	fclose(fp_mat6_6);
	fclose(fp_mat6_7);
	fclose(fp_mat6_8);
	fclose(fp_mat6_9);
	fclose(fp_mat6_10);
	fclose(fp_mat6_11);
	fclose(fp_mat6_12);
	fclose(fp_mat6_13);
	fclose(fp_mat6_14);
	fclose(fp_mat6_15);
				 
	fclose(fp_mat7_0);
	fclose(fp_mat7_1);
	fclose(fp_mat7_2);
	fclose(fp_mat7_3);
	fclose(fp_mat7_4);
	fclose(fp_mat7_5);
	fclose(fp_mat7_6);
	fclose(fp_mat7_7);
	fclose(fp_mat7_8);
	fclose(fp_mat7_9);
	fclose(fp_mat7_10);
	fclose(fp_mat7_11);
	fclose(fp_mat7_12);
	fclose(fp_mat7_13);
	fclose(fp_mat7_14);
	fclose(fp_mat7_15);

	/*fclose(fp_mat8_0);
	fclose(fp_mat8_1);
	fclose(fp_mat8_2);
	fclose(fp_mat8_3);
	fclose(fp_mat8_4);
	fclose(fp_mat8_5);
	fclose(fp_mat8_6);
	fclose(fp_mat8_7);
	fclose(fp_mat8_8);
	fclose(fp_mat8_9);
	fclose(fp_mat8_10);
	fclose(fp_mat8_11);
	fclose(fp_mat8_12);
	fclose(fp_mat8_13);
	fclose(fp_mat8_14);
	fclose(fp_mat8_15);

	fclose(fp_mat9_0);
	fclose(fp_mat9_1);
	fclose(fp_mat9_2);
	fclose(fp_mat9_3);
	fclose(fp_mat9_4);
	fclose(fp_mat9_5);
	fclose(fp_mat9_6);
	fclose(fp_mat9_7);
	fclose(fp_mat9_8);
	fclose(fp_mat9_9);
	fclose(fp_mat9_10);
	fclose(fp_mat9_11);
	fclose(fp_mat9_12);
	fclose(fp_mat9_13);
	fclose(fp_mat9_14);
	fclose(fp_mat9_15);

	fclose(fp_mat10_0);
	fclose(fp_mat10_1);
	fclose(fp_mat10_2);
	fclose(fp_mat10_3);
	fclose(fp_mat10_4);
	fclose(fp_mat10_5);
	fclose(fp_mat10_6);
	fclose(fp_mat10_7);
	fclose(fp_mat10_8);
	fclose(fp_mat10_9);
	fclose(fp_mat10_10);
	fclose(fp_mat10_11);
	fclose(fp_mat10_12);
	fclose(fp_mat10_13);
	fclose(fp_mat10_14);
	fclose(fp_mat10_15);

	fclose(fp_mat11_0);
	fclose(fp_mat11_1);
	fclose(fp_mat11_2);
	fclose(fp_mat11_3);
	fclose(fp_mat11_4);
	fclose(fp_mat11_5);
	fclose(fp_mat11_6);
	fclose(fp_mat11_7);
	fclose(fp_mat11_8);
	fclose(fp_mat11_9);
	fclose(fp_mat11_10);
	fclose(fp_mat11_11);
	fclose(fp_mat11_12);
	fclose(fp_mat11_13);
	fclose(fp_mat11_14);
	fclose(fp_mat11_15);

	fclose(fp_mat12_0);
	fclose(fp_mat12_1);
	fclose(fp_mat12_2);
	fclose(fp_mat12_3);
	fclose(fp_mat12_4);
	fclose(fp_mat12_5);
	fclose(fp_mat12_6);
	fclose(fp_mat12_7);
	fclose(fp_mat12_8);
	fclose(fp_mat12_9);
	fclose(fp_mat12_10);
	fclose(fp_mat12_11);
	fclose(fp_mat12_12);
	fclose(fp_mat12_13);
	fclose(fp_mat12_14);
	fclose(fp_mat12_15);

	fclose(fp_mat13_0);
	fclose(fp_mat13_1);
	fclose(fp_mat13_2);
	fclose(fp_mat13_3);
	fclose(fp_mat13_4);
	fclose(fp_mat13_5);
	fclose(fp_mat13_6);
	fclose(fp_mat13_7);
	fclose(fp_mat13_8);
	fclose(fp_mat13_9);
	fclose(fp_mat13_10);
	fclose(fp_mat13_11);
	fclose(fp_mat13_12);
	fclose(fp_mat13_13);
	fclose(fp_mat13_14);
	fclose(fp_mat13_15);

	fclose(fp_mat14_0);
	fclose(fp_mat14_1);
	fclose(fp_mat14_2);
	fclose(fp_mat14_3);
	fclose(fp_mat14_4);
	fclose(fp_mat14_5);
	fclose(fp_mat14_6);
	fclose(fp_mat14_7);
	fclose(fp_mat14_8);
	fclose(fp_mat14_9);
	fclose(fp_mat14_10);
	fclose(fp_mat14_11);
	fclose(fp_mat14_12);
	fclose(fp_mat14_13);
	fclose(fp_mat14_14);
	fclose(fp_mat14_15);

	fclose(fp_mat15_0);
	fclose(fp_mat15_1);
	fclose(fp_mat15_2);
	fclose(fp_mat15_3);
	fclose(fp_mat15_4);
	fclose(fp_mat15_5);
	fclose(fp_mat15_6);
	fclose(fp_mat15_7);
	fclose(fp_mat15_8);
	fclose(fp_mat15_9);
	fclose(fp_mat15_10);
	fclose(fp_mat15_11);
	fclose(fp_mat15_12);
	fclose(fp_mat15_13);
	fclose(fp_mat15_14);
	fclose(fp_mat15_15);*/

}

void print_all_mat()
{
	/*print_mat0_0();
	print_mat0_1();
	print_mat0_2();
	print_mat0_3();
	print_mat0_4();
	print_mat0_5();
	print_mat0_6();
	print_mat0_7();
	print_mat0_8();
	print_mat0_9();
	print_mat0_10();
	print_mat0_11();
	print_mat0_12();
	print_mat0_13();
	print_mat0_14();
	print_mat0_15();

	print_mat1_0();
	print_mat1_1();
	print_mat1_2();
	print_mat1_3();
	print_mat1_4();
	print_mat1_5();
	print_mat1_6();
	print_mat1_7();
	print_mat1_8();
	print_mat1_9();
	print_mat1_10();
	print_mat1_11();
	print_mat1_12();
	print_mat1_13();
	print_mat1_14();
	print_mat1_15();

	print_mat2_0();
	print_mat2_1();
	print_mat2_2();
	print_mat2_3();
	print_mat2_4();
	print_mat2_5();
	print_mat2_6();
	print_mat2_7();
	print_mat2_8();
	print_mat2_9();
	print_mat2_10();
	print_mat2_11();
	print_mat2_12();
	print_mat2_13();
	print_mat2_14();
	print_mat2_15();

	print_mat3_0();
	print_mat3_1();
	print_mat3_2();
	print_mat3_3();
	print_mat3_4();
	print_mat3_5();
	print_mat3_6();
	print_mat3_7();
	print_mat3_8();
	print_mat3_9();
	print_mat3_10();
	print_mat3_11();
	print_mat3_12();
	print_mat3_13();
	print_mat3_14();
	print_mat3_15();

	print_mat4_0();
	print_mat4_1();
	print_mat4_2();
	print_mat4_3();
	print_mat4_4();
	print_mat4_5();
	print_mat4_6();
	print_mat4_7();
	print_mat4_8();
	print_mat4_9();
	print_mat4_10();
	print_mat4_11();
	print_mat4_12();
	print_mat4_13();
	print_mat4_14();
	print_mat4_15();

	print_mat5_0();
	print_mat5_1();
	print_mat5_2();
	print_mat5_3();
	print_mat5_4();
	print_mat5_5();
	print_mat5_6();
	print_mat5_7();
	print_mat5_8();
	print_mat5_9();
	print_mat5_10();
	print_mat5_11();
	print_mat5_12();
	print_mat5_13();
	print_mat5_14();
	print_mat5_15();

	print_mat6_0();
	print_mat6_1();
	print_mat6_2();
	print_mat6_3();
	print_mat6_4();
	print_mat6_5();
	print_mat6_6();
	print_mat6_7();
	print_mat6_8();
	print_mat6_9();
	print_mat6_10();
	print_mat6_11();
	print_mat6_12();
	print_mat6_13();
	print_mat6_14();
	print_mat6_15();

	print_mat7_0();
	print_mat7_1();
	print_mat7_2();
	print_mat7_3();
	print_mat7_4();
	print_mat7_5();
	print_mat7_6();
	print_mat7_7();
	print_mat7_8();
	print_mat7_9();
	print_mat7_10();
	print_mat7_11();
	print_mat7_12();
	print_mat7_13();
	print_mat7_14();
	print_mat7_15();

	print_mat8_0();
	print_mat8_1();
	print_mat8_2();
	print_mat8_3();
	print_mat8_4();
	print_mat8_5();
	print_mat8_6();
	print_mat8_7();
	print_mat8_8();
	print_mat8_9();
	print_mat8_10();
	print_mat8_11();
	print_mat8_12();
	print_mat8_13();
	print_mat8_14();
	print_mat8_15();

	print_mat9_0();
	print_mat9_1();
	print_mat9_2();
	print_mat9_3();
	print_mat9_4();
	print_mat9_5();
	print_mat9_6();
	print_mat9_7();
	print_mat9_8();
	print_mat9_9();
	print_mat9_10();
	print_mat9_11();
	print_mat9_12();
	print_mat9_13();
	print_mat9_14();
	print_mat9_15();

	print_mat10_0();
	print_mat10_1();
	print_mat10_2();
	print_mat10_3();
	print_mat10_4();
	print_mat10_5();
	print_mat10_6();
	print_mat10_7();
	print_mat10_8();
	print_mat10_9();
	print_mat10_10();
	print_mat10_11();
	print_mat10_12();
	print_mat10_13();
	print_mat10_14();
	print_mat10_15();

	print_mat11_0();
	print_mat11_1();
	print_mat11_2();
	print_mat11_3();
	print_mat11_4();
	print_mat11_5();
	print_mat11_6();
	print_mat11_7();
	print_mat11_8();
	print_mat11_9();
	print_mat11_10();
	print_mat11_11();
	print_mat11_12();
	print_mat11_13();
	print_mat11_14();
	print_mat11_15();

	print_mat12_0();
	print_mat12_1();
	print_mat12_2();
	print_mat12_3();
	print_mat12_4();
	print_mat12_5();
	print_mat12_6();
	print_mat12_7();
	print_mat12_8();
	print_mat12_9();
	print_mat12_10();
	print_mat12_11();
	print_mat12_12();
	print_mat12_13();
	print_mat12_14();
	print_mat12_15();

	print_mat13_0();
	print_mat13_1();
	print_mat13_2();
	print_mat13_3();
	print_mat13_4();
	print_mat13_5();
	print_mat13_6();
	print_mat13_7();
	print_mat13_8();
	print_mat13_9();
	print_mat13_10();
	print_mat13_11();
	print_mat13_12();
	print_mat13_13();
	print_mat13_14();
	print_mat13_15();

	print_mat14_0();
	print_mat14_1();
	print_mat14_2();
	print_mat14_3();
	print_mat14_4();
	print_mat14_5();
	print_mat14_6();
	print_mat14_7();
	print_mat14_8();
	print_mat14_9();
	print_mat14_10();
	print_mat14_11();
	print_mat14_12();
	print_mat14_13();
	print_mat14_14();
	print_mat14_15();

	print_mat15_0();
	print_mat15_1();
	print_mat15_2();
	print_mat15_3();
	print_mat15_4();
	print_mat15_5();
	print_mat15_6();
	print_mat15_7();
	print_mat15_8();
	print_mat15_9();
	print_mat15_10();
	print_mat15_11();
	print_mat15_12();
	print_mat15_13();
	print_mat15_14();
	print_mat15_15();*/

   
    fprintf(fp_mat0_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[0].V[0],PMAT[0]->M_V[0].V[1],PMAT[0]->M_V[0].V[2],PMAT[0]->M_V[0].V[3],PMAT[0]->M_V[0].V[4],PMAT[0]->M_V[0].V[5],PMAT[0]->M_V[0].V[6],PMAT[0]->M_V[0].V[7],PMAT[0]->M_V[0].V[8],PMAT[0]->M_V[0].V[9],PMAT[0]->M_V[0].V[10],PMAT[0]->M_V[0].V[11],PMAT[0]->M_V[0].V[12],PMAT[0]->M_V[0].V[13],PMAT[0]->M_V[0].V[14],PMAT[0]->M_V[0].V[15]);
    
    fprintf(fp_mat0_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[1].V[0],PMAT[0]->M_V[1].V[1],PMAT[0]->M_V[1].V[2],PMAT[0]->M_V[1].V[3],PMAT[0]->M_V[1].V[4],PMAT[0]->M_V[1].V[5],PMAT[0]->M_V[1].V[6],PMAT[0]->M_V[1].V[7],PMAT[0]->M_V[1].V[8],PMAT[0]->M_V[1].V[9],PMAT[0]->M_V[1].V[10],PMAT[0]->M_V[1].V[11],PMAT[0]->M_V[1].V[12],PMAT[0]->M_V[1].V[13],PMAT[0]->M_V[1].V[14],PMAT[0]->M_V[1].V[15]);
    
    fprintf(fp_mat0_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[2].V[0],PMAT[0]->M_V[2].V[1],PMAT[0]->M_V[2].V[2],PMAT[0]->M_V[2].V[3],PMAT[0]->M_V[2].V[4],PMAT[0]->M_V[2].V[5],PMAT[0]->M_V[2].V[6],PMAT[0]->M_V[2].V[7],PMAT[0]->M_V[2].V[8],PMAT[0]->M_V[2].V[9],PMAT[0]->M_V[2].V[10],PMAT[0]->M_V[2].V[11],PMAT[0]->M_V[2].V[12],PMAT[0]->M_V[2].V[13],PMAT[0]->M_V[2].V[14],PMAT[0]->M_V[2].V[15]);
    
    fprintf(fp_mat0_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[3].V[0],PMAT[0]->M_V[3].V[1],PMAT[0]->M_V[3].V[2],PMAT[0]->M_V[3].V[3],PMAT[0]->M_V[3].V[4],PMAT[0]->M_V[3].V[5],PMAT[0]->M_V[3].V[6],PMAT[0]->M_V[3].V[7],PMAT[0]->M_V[3].V[8],PMAT[0]->M_V[3].V[9],PMAT[0]->M_V[3].V[10],PMAT[0]->M_V[3].V[11],PMAT[0]->M_V[3].V[12],PMAT[0]->M_V[3].V[13],PMAT[0]->M_V[3].V[14],PMAT[0]->M_V[3].V[15]);    
    
    fprintf(fp_mat0_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[4].V[0],PMAT[0]->M_V[4].V[1],PMAT[0]->M_V[4].V[2],PMAT[0]->M_V[4].V[3],PMAT[0]->M_V[4].V[4],PMAT[0]->M_V[4].V[5],PMAT[0]->M_V[4].V[6],PMAT[0]->M_V[4].V[7],PMAT[0]->M_V[4].V[8],PMAT[0]->M_V[4].V[9],PMAT[0]->M_V[4].V[10],PMAT[0]->M_V[4].V[11],PMAT[0]->M_V[4].V[12],PMAT[0]->M_V[4].V[13],PMAT[0]->M_V[4].V[14],PMAT[0]->M_V[4].V[15]);
    
    fprintf(fp_mat0_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[5].V[0],PMAT[0]->M_V[5].V[1],PMAT[0]->M_V[5].V[2],PMAT[0]->M_V[5].V[3],PMAT[0]->M_V[5].V[4],PMAT[0]->M_V[5].V[5],PMAT[0]->M_V[5].V[6],PMAT[0]->M_V[5].V[7],PMAT[0]->M_V[5].V[8],PMAT[0]->M_V[5].V[9],PMAT[0]->M_V[5].V[10],PMAT[0]->M_V[5].V[11],PMAT[0]->M_V[5].V[12],PMAT[0]->M_V[5].V[13],PMAT[0]->M_V[5].V[14],PMAT[0]->M_V[5].V[15]);
    
    fprintf(fp_mat0_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[6].V[0],PMAT[0]->M_V[6].V[1],PMAT[0]->M_V[6].V[2],PMAT[0]->M_V[6].V[3],PMAT[0]->M_V[6].V[4],PMAT[0]->M_V[6].V[5],PMAT[0]->M_V[6].V[6],PMAT[0]->M_V[6].V[7],PMAT[0]->M_V[6].V[8],PMAT[0]->M_V[6].V[9],PMAT[0]->M_V[6].V[10],PMAT[0]->M_V[6].V[11],PMAT[0]->M_V[6].V[12],PMAT[0]->M_V[6].V[13],PMAT[0]->M_V[6].V[14],PMAT[0]->M_V[6].V[15]);
    
    fprintf(fp_mat0_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[7].V[0],PMAT[0]->M_V[7].V[1],PMAT[0]->M_V[7].V[2],PMAT[0]->M_V[7].V[3],PMAT[0]->M_V[7].V[4],PMAT[0]->M_V[7].V[5],PMAT[0]->M_V[7].V[6],PMAT[0]->M_V[7].V[7],PMAT[0]->M_V[7].V[8],PMAT[0]->M_V[7].V[9],PMAT[0]->M_V[7].V[10],PMAT[0]->M_V[7].V[11],PMAT[0]->M_V[7].V[12],PMAT[0]->M_V[7].V[13],PMAT[0]->M_V[7].V[14],PMAT[0]->M_V[0].V[15]);
    
    fprintf(fp_mat0_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[8].V[0],PMAT[0]->M_V[8].V[1],PMAT[0]->M_V[8].V[2],PMAT[0]->M_V[8].V[3],PMAT[0]->M_V[8].V[4],PMAT[0]->M_V[8].V[5],PMAT[0]->M_V[8].V[6],PMAT[0]->M_V[8].V[7],PMAT[0]->M_V[8].V[8],PMAT[0]->M_V[8].V[9],PMAT[0]->M_V[8].V[10],PMAT[0]->M_V[8].V[11],PMAT[0]->M_V[8].V[12],PMAT[0]->M_V[8].V[13],PMAT[0]->M_V[8].V[14],PMAT[0]->M_V[8].V[15]);
    
    fprintf(fp_mat0_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[9].V[0],PMAT[0]->M_V[9].V[1],PMAT[0]->M_V[9].V[2],PMAT[0]->M_V[9].V[3],PMAT[0]->M_V[9].V[4],PMAT[0]->M_V[9].V[5],PMAT[0]->M_V[9].V[6],PMAT[0]->M_V[9].V[7],PMAT[0]->M_V[9].V[8],PMAT[0]->M_V[9].V[9],PMAT[0]->M_V[9].V[10],PMAT[0]->M_V[9].V[11],PMAT[0]->M_V[9].V[12],PMAT[0]->M_V[9].V[13],PMAT[0]->M_V[9].V[14],PMAT[0]->M_V[9].V[15]);
    
    fprintf(fp_mat0_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[10].V[0],PMAT[0]->M_V[10].V[1],PMAT[0]->M_V[10].V[2],PMAT[0]->M_V[10].V[3],PMAT[0]->M_V[10].V[4],PMAT[0]->M_V[10].V[5],PMAT[0]->M_V[10].V[6],PMAT[0]->M_V[10].V[7],PMAT[0]->M_V[10].V[8],PMAT[0]->M_V[10].V[9],PMAT[0]->M_V[10].V[10],PMAT[0]->M_V[10].V[11],PMAT[0]->M_V[10].V[12],PMAT[0]->M_V[10].V[13],PMAT[0]->M_V[10].V[14],PMAT[0]->M_V[10].V[15]);
    
    fprintf(fp_mat0_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[11].V[0],PMAT[0]->M_V[11].V[1],PMAT[0]->M_V[11].V[2],PMAT[0]->M_V[11].V[3],PMAT[0]->M_V[11].V[4],PMAT[0]->M_V[11].V[5],PMAT[0]->M_V[11].V[6],PMAT[0]->M_V[11].V[7],PMAT[0]->M_V[11].V[8],PMAT[0]->M_V[11].V[9],PMAT[0]->M_V[11].V[10],PMAT[0]->M_V[11].V[11],PMAT[0]->M_V[11].V[12],PMAT[0]->M_V[11].V[13],PMAT[0]->M_V[11].V[14],PMAT[0]->M_V[11].V[15]);
    
    fprintf(fp_mat0_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[12].V[0],PMAT[0]->M_V[12].V[1],PMAT[0]->M_V[12].V[2],PMAT[0]->M_V[12].V[3],PMAT[0]->M_V[12].V[4],PMAT[0]->M_V[12].V[5],PMAT[0]->M_V[12].V[6],PMAT[0]->M_V[12].V[7],PMAT[0]->M_V[12].V[8],PMAT[0]->M_V[12].V[9],PMAT[0]->M_V[12].V[10],PMAT[0]->M_V[12].V[11],PMAT[0]->M_V[12].V[12],PMAT[0]->M_V[12].V[13],PMAT[0]->M_V[12].V[14],PMAT[0]->M_V[12].V[15]);
    
    fprintf(fp_mat0_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[13].V[0],PMAT[0]->M_V[13].V[1],PMAT[0]->M_V[13].V[2],PMAT[0]->M_V[13].V[3],PMAT[0]->M_V[13].V[4],PMAT[0]->M_V[13].V[5],PMAT[0]->M_V[13].V[6],PMAT[0]->M_V[13].V[7],PMAT[0]->M_V[13].V[8],PMAT[0]->M_V[13].V[9],PMAT[0]->M_V[13].V[10],PMAT[0]->M_V[13].V[11],PMAT[0]->M_V[13].V[12],PMAT[0]->M_V[13].V[13],PMAT[0]->M_V[13].V[14],PMAT[0]->M_V[13].V[15]);
    
    fprintf(fp_mat0_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[14].V[0],PMAT[0]->M_V[14].V[1],PMAT[0]->M_V[14].V[2],PMAT[0]->M_V[14].V[3],PMAT[0]->M_V[14].V[4],PMAT[0]->M_V[14].V[5],PMAT[0]->M_V[14].V[6],PMAT[0]->M_V[14].V[7],PMAT[0]->M_V[14].V[8],PMAT[0]->M_V[14].V[9],PMAT[0]->M_V[14].V[10],PMAT[0]->M_V[14].V[11],PMAT[0]->M_V[14].V[12],PMAT[0]->M_V[14].V[13],PMAT[0]->M_V[14].V[14],PMAT[0]->M_V[14].V[15]);
    
    fprintf(fp_mat0_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[0]->M_V[15].V[0],PMAT[0]->M_V[15].V[1],PMAT[0]->M_V[15].V[2],PMAT[0]->M_V[15].V[3],PMAT[0]->M_V[15].V[4],PMAT[0]->M_V[15].V[5],PMAT[0]->M_V[15].V[6],PMAT[0]->M_V[15].V[7],PMAT[0]->M_V[15].V[8],PMAT[0]->M_V[15].V[9],PMAT[0]->M_V[15].V[10],PMAT[0]->M_V[15].V[11],PMAT[0]->M_V[15].V[12],PMAT[0]->M_V[15].V[13],PMAT[0]->M_V[15].V[14],PMAT[0]->M_V[15].V[15]);
    
    
    fprintf(fp_mat1_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[0].V[0],PMAT[1]->M_V[0].V[1],PMAT[1]->M_V[0].V[2],PMAT[1]->M_V[0].V[3],PMAT[1]->M_V[0].V[4],PMAT[1]->M_V[0].V[5],PMAT[1]->M_V[0].V[6],PMAT[1]->M_V[0].V[7],PMAT[1]->M_V[0].V[8],PMAT[1]->M_V[0].V[9],PMAT[1]->M_V[0].V[10],PMAT[1]->M_V[0].V[11],PMAT[1]->M_V[0].V[12],PMAT[1]->M_V[0].V[13],PMAT[1]->M_V[0].V[14],PMAT[1]->M_V[0].V[15]);
    
    fprintf(fp_mat1_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[1].V[0],PMAT[1]->M_V[1].V[1],PMAT[1]->M_V[1].V[2],PMAT[1]->M_V[1].V[3],PMAT[1]->M_V[1].V[4],PMAT[1]->M_V[1].V[5],PMAT[1]->M_V[1].V[6],PMAT[1]->M_V[1].V[7],PMAT[1]->M_V[1].V[8],PMAT[1]->M_V[1].V[9],PMAT[1]->M_V[1].V[10],PMAT[1]->M_V[1].V[11],PMAT[1]->M_V[1].V[12],PMAT[1]->M_V[1].V[13],PMAT[1]->M_V[1].V[14],PMAT[1]->M_V[1].V[15]);
    
    fprintf(fp_mat1_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[2].V[0],PMAT[1]->M_V[2].V[1],PMAT[1]->M_V[2].V[2],PMAT[1]->M_V[2].V[3],PMAT[1]->M_V[2].V[4],PMAT[1]->M_V[2].V[5],PMAT[1]->M_V[2].V[6],PMAT[1]->M_V[2].V[7],PMAT[1]->M_V[2].V[8],PMAT[1]->M_V[2].V[9],PMAT[1]->M_V[2].V[10],PMAT[1]->M_V[2].V[11],PMAT[1]->M_V[2].V[12],PMAT[1]->M_V[2].V[13],PMAT[1]->M_V[2].V[14],PMAT[1]->M_V[2].V[15]);
    
    fprintf(fp_mat1_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[3].V[0],PMAT[1]->M_V[3].V[1],PMAT[1]->M_V[3].V[2],PMAT[1]->M_V[3].V[3],PMAT[1]->M_V[3].V[4],PMAT[1]->M_V[3].V[5],PMAT[1]->M_V[3].V[6],PMAT[1]->M_V[3].V[7],PMAT[1]->M_V[3].V[8],PMAT[1]->M_V[3].V[9],PMAT[1]->M_V[3].V[10],PMAT[1]->M_V[3].V[11],PMAT[1]->M_V[3].V[12],PMAT[1]->M_V[3].V[13],PMAT[1]->M_V[3].V[14],PMAT[1]->M_V[3].V[15]);    
    
    fprintf(fp_mat1_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[4].V[0],PMAT[1]->M_V[4].V[1],PMAT[1]->M_V[4].V[2],PMAT[1]->M_V[4].V[3],PMAT[1]->M_V[4].V[4],PMAT[1]->M_V[4].V[5],PMAT[1]->M_V[4].V[6],PMAT[1]->M_V[4].V[7],PMAT[1]->M_V[4].V[8],PMAT[1]->M_V[4].V[9],PMAT[1]->M_V[4].V[10],PMAT[1]->M_V[4].V[11],PMAT[1]->M_V[4].V[12],PMAT[1]->M_V[4].V[13],PMAT[1]->M_V[4].V[14],PMAT[1]->M_V[4].V[15]);
    
    fprintf(fp_mat1_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[5].V[0],PMAT[1]->M_V[5].V[1],PMAT[1]->M_V[5].V[2],PMAT[1]->M_V[5].V[3],PMAT[1]->M_V[5].V[4],PMAT[1]->M_V[5].V[5],PMAT[1]->M_V[5].V[6],PMAT[1]->M_V[5].V[7],PMAT[1]->M_V[5].V[8],PMAT[1]->M_V[5].V[9],PMAT[1]->M_V[5].V[10],PMAT[1]->M_V[5].V[11],PMAT[1]->M_V[5].V[12],PMAT[1]->M_V[5].V[13],PMAT[1]->M_V[5].V[14],PMAT[1]->M_V[5].V[15]);
    
    fprintf(fp_mat1_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[6].V[0],PMAT[1]->M_V[6].V[1],PMAT[1]->M_V[6].V[2],PMAT[1]->M_V[6].V[3],PMAT[1]->M_V[6].V[4],PMAT[1]->M_V[6].V[5],PMAT[1]->M_V[6].V[6],PMAT[1]->M_V[6].V[7],PMAT[1]->M_V[6].V[8],PMAT[1]->M_V[6].V[9],PMAT[1]->M_V[6].V[10],PMAT[1]->M_V[6].V[11],PMAT[1]->M_V[6].V[12],PMAT[1]->M_V[6].V[13],PMAT[1]->M_V[6].V[14],PMAT[1]->M_V[6].V[15]);
    
    fprintf(fp_mat1_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[7].V[0],PMAT[1]->M_V[7].V[1],PMAT[1]->M_V[7].V[2],PMAT[1]->M_V[7].V[3],PMAT[1]->M_V[7].V[4],PMAT[1]->M_V[7].V[5],PMAT[1]->M_V[7].V[6],PMAT[1]->M_V[7].V[7],PMAT[1]->M_V[7].V[8],PMAT[1]->M_V[7].V[9],PMAT[1]->M_V[7].V[10],PMAT[1]->M_V[7].V[11],PMAT[1]->M_V[7].V[12],PMAT[1]->M_V[7].V[13],PMAT[1]->M_V[7].V[14],PMAT[1]->M_V[0].V[15]);
    
    fprintf(fp_mat1_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[8].V[0],PMAT[1]->M_V[8].V[1],PMAT[1]->M_V[8].V[2],PMAT[1]->M_V[8].V[3],PMAT[1]->M_V[8].V[4],PMAT[1]->M_V[8].V[5],PMAT[1]->M_V[8].V[6],PMAT[1]->M_V[8].V[7],PMAT[1]->M_V[8].V[8],PMAT[1]->M_V[8].V[9],PMAT[1]->M_V[8].V[10],PMAT[1]->M_V[8].V[11],PMAT[1]->M_V[8].V[12],PMAT[1]->M_V[8].V[13],PMAT[1]->M_V[8].V[14],PMAT[1]->M_V[8].V[15]);
    
    fprintf(fp_mat1_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[9].V[0],PMAT[1]->M_V[9].V[1],PMAT[1]->M_V[9].V[2],PMAT[1]->M_V[9].V[3],PMAT[1]->M_V[9].V[4],PMAT[1]->M_V[9].V[5],PMAT[1]->M_V[9].V[6],PMAT[1]->M_V[9].V[7],PMAT[1]->M_V[9].V[8],PMAT[1]->M_V[9].V[9],PMAT[1]->M_V[9].V[10],PMAT[1]->M_V[9].V[11],PMAT[1]->M_V[9].V[12],PMAT[1]->M_V[9].V[13],PMAT[1]->M_V[9].V[14],PMAT[1]->M_V[9].V[15]);
    
    fprintf(fp_mat1_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[10].V[0],PMAT[1]->M_V[10].V[1],PMAT[1]->M_V[10].V[2],PMAT[1]->M_V[10].V[3],PMAT[1]->M_V[10].V[4],PMAT[1]->M_V[10].V[5],PMAT[1]->M_V[10].V[6],PMAT[1]->M_V[10].V[7],PMAT[1]->M_V[10].V[8],PMAT[1]->M_V[10].V[9],PMAT[1]->M_V[10].V[10],PMAT[1]->M_V[10].V[11],PMAT[1]->M_V[10].V[12],PMAT[1]->M_V[10].V[13],PMAT[1]->M_V[10].V[14],PMAT[1]->M_V[10].V[15]);
    
    fprintf(fp_mat1_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[11].V[0],PMAT[1]->M_V[11].V[1],PMAT[1]->M_V[11].V[2],PMAT[1]->M_V[11].V[3],PMAT[1]->M_V[11].V[4],PMAT[1]->M_V[11].V[5],PMAT[1]->M_V[11].V[6],PMAT[1]->M_V[11].V[7],PMAT[1]->M_V[11].V[8],PMAT[1]->M_V[11].V[9],PMAT[1]->M_V[11].V[10],PMAT[1]->M_V[11].V[11],PMAT[1]->M_V[11].V[12],PMAT[1]->M_V[11].V[13],PMAT[1]->M_V[11].V[14],PMAT[1]->M_V[11].V[15]);
    
    fprintf(fp_mat1_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[12].V[0],PMAT[1]->M_V[12].V[1],PMAT[1]->M_V[12].V[2],PMAT[1]->M_V[12].V[3],PMAT[1]->M_V[12].V[4],PMAT[1]->M_V[12].V[5],PMAT[1]->M_V[12].V[6],PMAT[1]->M_V[12].V[7],PMAT[1]->M_V[12].V[8],PMAT[1]->M_V[12].V[9],PMAT[1]->M_V[12].V[10],PMAT[1]->M_V[12].V[11],PMAT[1]->M_V[12].V[12],PMAT[1]->M_V[12].V[13],PMAT[1]->M_V[12].V[14],PMAT[1]->M_V[12].V[15]);
    
    fprintf(fp_mat1_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[13].V[0],PMAT[1]->M_V[13].V[1],PMAT[1]->M_V[13].V[2],PMAT[1]->M_V[13].V[3],PMAT[1]->M_V[13].V[4],PMAT[1]->M_V[13].V[5],PMAT[1]->M_V[13].V[6],PMAT[1]->M_V[13].V[7],PMAT[1]->M_V[13].V[8],PMAT[1]->M_V[13].V[9],PMAT[1]->M_V[13].V[10],PMAT[1]->M_V[13].V[11],PMAT[1]->M_V[13].V[12],PMAT[1]->M_V[13].V[13],PMAT[1]->M_V[13].V[14],PMAT[1]->M_V[13].V[15]);
    
    fprintf(fp_mat1_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[14].V[0],PMAT[1]->M_V[14].V[1],PMAT[1]->M_V[14].V[2],PMAT[1]->M_V[14].V[3],PMAT[1]->M_V[14].V[4],PMAT[1]->M_V[14].V[5],PMAT[1]->M_V[14].V[6],PMAT[1]->M_V[14].V[7],PMAT[1]->M_V[14].V[8],PMAT[1]->M_V[14].V[9],PMAT[1]->M_V[14].V[10],PMAT[1]->M_V[14].V[11],PMAT[1]->M_V[14].V[12],PMAT[1]->M_V[14].V[13],PMAT[1]->M_V[14].V[14],PMAT[1]->M_V[14].V[15]);

	fprintf(fp_mat1_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[1]->M_V[15].V[0],PMAT[1]->M_V[15].V[1],PMAT[1]->M_V[15].V[2],PMAT[1]->M_V[15].V[3],PMAT[1]->M_V[15].V[4],PMAT[1]->M_V[15].V[5],PMAT[1]->M_V[15].V[6],PMAT[1]->M_V[15].V[7],PMAT[1]->M_V[15].V[8],PMAT[1]->M_V[15].V[9],PMAT[1]->M_V[15].V[10],PMAT[1]->M_V[15].V[11],PMAT[1]->M_V[15].V[12],PMAT[1]->M_V[15].V[13],PMAT[1]->M_V[15].V[14],PMAT[1]->M_V[15].V[15]);

    
    
    fprintf(fp_mat2_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[0].V[0],PMAT[2]->M_V[0].V[1],PMAT[2]->M_V[0].V[2],PMAT[2]->M_V[0].V[3],PMAT[2]->M_V[0].V[4],PMAT[2]->M_V[0].V[5],PMAT[2]->M_V[0].V[6],PMAT[2]->M_V[0].V[7],PMAT[2]->M_V[0].V[8],PMAT[2]->M_V[0].V[9],PMAT[2]->M_V[0].V[10],PMAT[2]->M_V[0].V[11],PMAT[2]->M_V[0].V[12],PMAT[2]->M_V[0].V[13],PMAT[2]->M_V[0].V[14],PMAT[2]->M_V[0].V[15]);
    
    fprintf(fp_mat2_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[1].V[0],PMAT[2]->M_V[1].V[1],PMAT[2]->M_V[1].V[2],PMAT[2]->M_V[1].V[3],PMAT[2]->M_V[1].V[4],PMAT[2]->M_V[1].V[5],PMAT[2]->M_V[1].V[6],PMAT[2]->M_V[1].V[7],PMAT[2]->M_V[1].V[8],PMAT[2]->M_V[1].V[9],PMAT[2]->M_V[1].V[10],PMAT[2]->M_V[1].V[11],PMAT[2]->M_V[1].V[12],PMAT[2]->M_V[1].V[13],PMAT[2]->M_V[1].V[14],PMAT[2]->M_V[1].V[15]);
    
    fprintf(fp_mat2_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[2].V[0],PMAT[2]->M_V[2].V[1],PMAT[2]->M_V[2].V[2],PMAT[2]->M_V[2].V[3],PMAT[2]->M_V[2].V[4],PMAT[2]->M_V[2].V[5],PMAT[2]->M_V[2].V[6],PMAT[2]->M_V[2].V[7],PMAT[2]->M_V[2].V[8],PMAT[2]->M_V[2].V[9],PMAT[2]->M_V[2].V[10],PMAT[2]->M_V[2].V[11],PMAT[2]->M_V[2].V[12],PMAT[2]->M_V[2].V[13],PMAT[2]->M_V[2].V[14],PMAT[2]->M_V[2].V[15]);
    
    fprintf(fp_mat2_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[3].V[0],PMAT[2]->M_V[3].V[1],PMAT[2]->M_V[3].V[2],PMAT[2]->M_V[3].V[3],PMAT[2]->M_V[3].V[4],PMAT[2]->M_V[3].V[5],PMAT[2]->M_V[3].V[6],PMAT[2]->M_V[3].V[7],PMAT[2]->M_V[3].V[8],PMAT[2]->M_V[3].V[9],PMAT[2]->M_V[3].V[10],PMAT[2]->M_V[3].V[11],PMAT[2]->M_V[3].V[12],PMAT[2]->M_V[3].V[13],PMAT[2]->M_V[3].V[14],PMAT[2]->M_V[3].V[15]);    
    
    fprintf(fp_mat2_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[4].V[0],PMAT[2]->M_V[4].V[1],PMAT[2]->M_V[4].V[2],PMAT[2]->M_V[4].V[3],PMAT[2]->M_V[4].V[4],PMAT[2]->M_V[4].V[5],PMAT[2]->M_V[4].V[6],PMAT[2]->M_V[4].V[7],PMAT[2]->M_V[4].V[8],PMAT[2]->M_V[4].V[9],PMAT[2]->M_V[4].V[10],PMAT[2]->M_V[4].V[11],PMAT[2]->M_V[4].V[12],PMAT[2]->M_V[4].V[13],PMAT[2]->M_V[4].V[14],PMAT[2]->M_V[4].V[15]);
    
    fprintf(fp_mat2_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[5].V[0],PMAT[2]->M_V[5].V[1],PMAT[2]->M_V[5].V[2],PMAT[2]->M_V[5].V[3],PMAT[2]->M_V[5].V[4],PMAT[2]->M_V[5].V[5],PMAT[2]->M_V[5].V[6],PMAT[2]->M_V[5].V[7],PMAT[2]->M_V[5].V[8],PMAT[2]->M_V[5].V[9],PMAT[2]->M_V[5].V[10],PMAT[2]->M_V[5].V[11],PMAT[2]->M_V[5].V[12],PMAT[2]->M_V[5].V[13],PMAT[2]->M_V[5].V[14],PMAT[2]->M_V[5].V[15]);
    
    fprintf(fp_mat2_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[6].V[0],PMAT[2]->M_V[6].V[1],PMAT[2]->M_V[6].V[2],PMAT[2]->M_V[6].V[3],PMAT[2]->M_V[6].V[4],PMAT[2]->M_V[6].V[5],PMAT[2]->M_V[6].V[6],PMAT[2]->M_V[6].V[7],PMAT[2]->M_V[6].V[8],PMAT[2]->M_V[6].V[9],PMAT[2]->M_V[6].V[10],PMAT[2]->M_V[6].V[11],PMAT[2]->M_V[6].V[12],PMAT[2]->M_V[6].V[13],PMAT[2]->M_V[6].V[14],PMAT[2]->M_V[6].V[15]);
    
    fprintf(fp_mat2_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[7].V[0],PMAT[2]->M_V[7].V[1],PMAT[2]->M_V[7].V[2],PMAT[2]->M_V[7].V[3],PMAT[2]->M_V[7].V[4],PMAT[2]->M_V[7].V[5],PMAT[2]->M_V[7].V[6],PMAT[2]->M_V[7].V[7],PMAT[2]->M_V[7].V[8],PMAT[2]->M_V[7].V[9],PMAT[2]->M_V[7].V[10],PMAT[2]->M_V[7].V[11],PMAT[2]->M_V[7].V[12],PMAT[2]->M_V[7].V[13],PMAT[2]->M_V[7].V[14],PMAT[2]->M_V[0].V[15]);
    
    fprintf(fp_mat2_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[8].V[0],PMAT[2]->M_V[8].V[1],PMAT[2]->M_V[8].V[2],PMAT[2]->M_V[8].V[3],PMAT[2]->M_V[8].V[4],PMAT[2]->M_V[8].V[5],PMAT[2]->M_V[8].V[6],PMAT[2]->M_V[8].V[7],PMAT[2]->M_V[8].V[8],PMAT[2]->M_V[8].V[9],PMAT[2]->M_V[8].V[10],PMAT[2]->M_V[8].V[11],PMAT[2]->M_V[8].V[12],PMAT[2]->M_V[8].V[13],PMAT[2]->M_V[8].V[14],PMAT[2]->M_V[8].V[15]);
    
    fprintf(fp_mat2_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[9].V[0],PMAT[2]->M_V[9].V[1],PMAT[2]->M_V[9].V[2],PMAT[2]->M_V[9].V[3],PMAT[2]->M_V[9].V[4],PMAT[2]->M_V[9].V[5],PMAT[2]->M_V[9].V[6],PMAT[2]->M_V[9].V[7],PMAT[2]->M_V[9].V[8],PMAT[2]->M_V[9].V[9],PMAT[2]->M_V[9].V[10],PMAT[2]->M_V[9].V[11],PMAT[2]->M_V[9].V[12],PMAT[2]->M_V[9].V[13],PMAT[2]->M_V[9].V[14],PMAT[2]->M_V[9].V[15]);
    
    fprintf(fp_mat2_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[10].V[0],PMAT[2]->M_V[10].V[1],PMAT[2]->M_V[10].V[2],PMAT[2]->M_V[10].V[3],PMAT[2]->M_V[10].V[4],PMAT[2]->M_V[10].V[5],PMAT[2]->M_V[10].V[6],PMAT[2]->M_V[10].V[7],PMAT[2]->M_V[10].V[8],PMAT[2]->M_V[10].V[9],PMAT[2]->M_V[10].V[10],PMAT[2]->M_V[10].V[11],PMAT[2]->M_V[10].V[12],PMAT[2]->M_V[10].V[13],PMAT[2]->M_V[10].V[14],PMAT[2]->M_V[10].V[15]);
    
    fprintf(fp_mat2_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[11].V[0],PMAT[2]->M_V[11].V[1],PMAT[2]->M_V[11].V[2],PMAT[2]->M_V[11].V[3],PMAT[2]->M_V[11].V[4],PMAT[2]->M_V[11].V[5],PMAT[2]->M_V[11].V[6],PMAT[2]->M_V[11].V[7],PMAT[2]->M_V[11].V[8],PMAT[2]->M_V[11].V[9],PMAT[2]->M_V[11].V[10],PMAT[2]->M_V[11].V[11],PMAT[2]->M_V[11].V[12],PMAT[2]->M_V[11].V[13],PMAT[2]->M_V[11].V[14],PMAT[2]->M_V[11].V[15]);
    
    fprintf(fp_mat2_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[12].V[0],PMAT[2]->M_V[12].V[1],PMAT[2]->M_V[12].V[2],PMAT[2]->M_V[12].V[3],PMAT[2]->M_V[12].V[4],PMAT[2]->M_V[12].V[5],PMAT[2]->M_V[12].V[6],PMAT[2]->M_V[12].V[7],PMAT[2]->M_V[12].V[8],PMAT[2]->M_V[12].V[9],PMAT[2]->M_V[12].V[10],PMAT[2]->M_V[12].V[11],PMAT[2]->M_V[12].V[12],PMAT[2]->M_V[12].V[13],PMAT[2]->M_V[12].V[14],PMAT[2]->M_V[12].V[15]);
    
    fprintf(fp_mat2_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[13].V[0],PMAT[2]->M_V[13].V[1],PMAT[2]->M_V[13].V[2],PMAT[2]->M_V[13].V[3],PMAT[2]->M_V[13].V[4],PMAT[2]->M_V[13].V[5],PMAT[2]->M_V[13].V[6],PMAT[2]->M_V[13].V[7],PMAT[2]->M_V[13].V[8],PMAT[2]->M_V[13].V[9],PMAT[2]->M_V[13].V[10],PMAT[2]->M_V[13].V[11],PMAT[2]->M_V[13].V[12],PMAT[2]->M_V[13].V[13],PMAT[2]->M_V[13].V[14],PMAT[2]->M_V[13].V[15]);
    
    fprintf(fp_mat2_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[14].V[0],PMAT[2]->M_V[14].V[1],PMAT[2]->M_V[14].V[2],PMAT[2]->M_V[14].V[3],PMAT[2]->M_V[14].V[4],PMAT[2]->M_V[14].V[5],PMAT[2]->M_V[14].V[6],PMAT[2]->M_V[14].V[7],PMAT[2]->M_V[14].V[8],PMAT[2]->M_V[14].V[9],PMAT[2]->M_V[14].V[10],PMAT[2]->M_V[14].V[11],PMAT[2]->M_V[14].V[12],PMAT[2]->M_V[14].V[13],PMAT[2]->M_V[14].V[14],PMAT[2]->M_V[14].V[15]);
    
    fprintf(fp_mat2_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[2]->M_V[15].V[0],PMAT[2]->M_V[15].V[1],PMAT[2]->M_V[15].V[2],PMAT[2]->M_V[15].V[3],PMAT[2]->M_V[15].V[4],PMAT[2]->M_V[15].V[5],PMAT[2]->M_V[15].V[6],PMAT[2]->M_V[15].V[7],PMAT[2]->M_V[15].V[8],PMAT[2]->M_V[15].V[9],PMAT[2]->M_V[15].V[10],PMAT[2]->M_V[15].V[11],PMAT[2]->M_V[15].V[12],PMAT[2]->M_V[15].V[13],PMAT[2]->M_V[15].V[14],PMAT[2]->M_V[15].V[15]);
    
    
    
    fprintf(fp_mat3_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[0].V[0],PMAT[3]->M_V[0].V[1],PMAT[3]->M_V[0].V[2],PMAT[3]->M_V[0].V[3],PMAT[3]->M_V[0].V[4],PMAT[3]->M_V[0].V[5],PMAT[3]->M_V[0].V[6],PMAT[3]->M_V[0].V[7],PMAT[3]->M_V[0].V[8],PMAT[3]->M_V[0].V[9],PMAT[3]->M_V[0].V[10],PMAT[3]->M_V[0].V[11],PMAT[3]->M_V[0].V[12],PMAT[3]->M_V[0].V[13],PMAT[3]->M_V[0].V[14],PMAT[3]->M_V[0].V[15]);
    
    fprintf(fp_mat3_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[1].V[0],PMAT[3]->M_V[1].V[1],PMAT[3]->M_V[1].V[2],PMAT[3]->M_V[1].V[3],PMAT[3]->M_V[1].V[4],PMAT[3]->M_V[1].V[5],PMAT[3]->M_V[1].V[6],PMAT[3]->M_V[1].V[7],PMAT[3]->M_V[1].V[8],PMAT[3]->M_V[1].V[9],PMAT[3]->M_V[1].V[10],PMAT[3]->M_V[1].V[11],PMAT[3]->M_V[1].V[12],PMAT[3]->M_V[1].V[13],PMAT[3]->M_V[1].V[14],PMAT[3]->M_V[1].V[15]);
    
    fprintf(fp_mat3_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[2].V[0],PMAT[3]->M_V[2].V[1],PMAT[3]->M_V[2].V[2],PMAT[3]->M_V[2].V[3],PMAT[3]->M_V[2].V[4],PMAT[3]->M_V[2].V[5],PMAT[3]->M_V[2].V[6],PMAT[3]->M_V[2].V[7],PMAT[3]->M_V[2].V[8],PMAT[3]->M_V[2].V[9],PMAT[3]->M_V[2].V[10],PMAT[3]->M_V[2].V[11],PMAT[3]->M_V[2].V[12],PMAT[3]->M_V[2].V[13],PMAT[3]->M_V[2].V[14],PMAT[3]->M_V[2].V[15]);
    
    fprintf(fp_mat3_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[3].V[0],PMAT[3]->M_V[3].V[1],PMAT[3]->M_V[3].V[2],PMAT[3]->M_V[3].V[3],PMAT[3]->M_V[3].V[4],PMAT[3]->M_V[3].V[5],PMAT[3]->M_V[3].V[6],PMAT[3]->M_V[3].V[7],PMAT[3]->M_V[3].V[8],PMAT[3]->M_V[3].V[9],PMAT[3]->M_V[3].V[10],PMAT[3]->M_V[3].V[11],PMAT[3]->M_V[3].V[12],PMAT[3]->M_V[3].V[13],PMAT[3]->M_V[3].V[14],PMAT[3]->M_V[3].V[15]);    
    
    fprintf(fp_mat3_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[4].V[0],PMAT[3]->M_V[4].V[1],PMAT[3]->M_V[4].V[2],PMAT[3]->M_V[4].V[3],PMAT[3]->M_V[4].V[4],PMAT[3]->M_V[4].V[5],PMAT[3]->M_V[4].V[6],PMAT[3]->M_V[4].V[7],PMAT[3]->M_V[4].V[8],PMAT[3]->M_V[4].V[9],PMAT[3]->M_V[4].V[10],PMAT[3]->M_V[4].V[11],PMAT[3]->M_V[4].V[12],PMAT[3]->M_V[4].V[13],PMAT[3]->M_V[4].V[14],PMAT[3]->M_V[4].V[15]);
    
    fprintf(fp_mat3_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[5].V[0],PMAT[3]->M_V[5].V[1],PMAT[3]->M_V[5].V[2],PMAT[3]->M_V[5].V[3],PMAT[3]->M_V[5].V[4],PMAT[3]->M_V[5].V[5],PMAT[3]->M_V[5].V[6],PMAT[3]->M_V[5].V[7],PMAT[3]->M_V[5].V[8],PMAT[3]->M_V[5].V[9],PMAT[3]->M_V[5].V[10],PMAT[3]->M_V[5].V[11],PMAT[3]->M_V[5].V[12],PMAT[3]->M_V[5].V[13],PMAT[3]->M_V[5].V[14],PMAT[3]->M_V[5].V[15]);
    
    fprintf(fp_mat3_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[6].V[0],PMAT[3]->M_V[6].V[1],PMAT[3]->M_V[6].V[2],PMAT[3]->M_V[6].V[3],PMAT[3]->M_V[6].V[4],PMAT[3]->M_V[6].V[5],PMAT[3]->M_V[6].V[6],PMAT[3]->M_V[6].V[7],PMAT[3]->M_V[6].V[8],PMAT[3]->M_V[6].V[9],PMAT[3]->M_V[6].V[10],PMAT[3]->M_V[6].V[11],PMAT[3]->M_V[6].V[12],PMAT[3]->M_V[6].V[13],PMAT[3]->M_V[6].V[14],PMAT[3]->M_V[6].V[15]);
    
    fprintf(fp_mat3_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[7].V[0],PMAT[3]->M_V[7].V[1],PMAT[3]->M_V[7].V[2],PMAT[3]->M_V[7].V[3],PMAT[3]->M_V[7].V[4],PMAT[3]->M_V[7].V[5],PMAT[3]->M_V[7].V[6],PMAT[3]->M_V[7].V[7],PMAT[3]->M_V[7].V[8],PMAT[3]->M_V[7].V[9],PMAT[3]->M_V[7].V[10],PMAT[3]->M_V[7].V[11],PMAT[3]->M_V[7].V[12],PMAT[3]->M_V[7].V[13],PMAT[3]->M_V[7].V[14],PMAT[3]->M_V[0].V[15]);
    
    fprintf(fp_mat3_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[8].V[0],PMAT[3]->M_V[8].V[1],PMAT[3]->M_V[8].V[2],PMAT[3]->M_V[8].V[3],PMAT[3]->M_V[8].V[4],PMAT[3]->M_V[8].V[5],PMAT[3]->M_V[8].V[6],PMAT[3]->M_V[8].V[7],PMAT[3]->M_V[8].V[8],PMAT[3]->M_V[8].V[9],PMAT[3]->M_V[8].V[10],PMAT[3]->M_V[8].V[11],PMAT[3]->M_V[8].V[12],PMAT[3]->M_V[8].V[13],PMAT[3]->M_V[8].V[14],PMAT[3]->M_V[8].V[15]);
    
    fprintf(fp_mat3_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[9].V[0],PMAT[3]->M_V[9].V[1],PMAT[3]->M_V[9].V[2],PMAT[3]->M_V[9].V[3],PMAT[3]->M_V[9].V[4],PMAT[3]->M_V[9].V[5],PMAT[3]->M_V[9].V[6],PMAT[3]->M_V[9].V[7],PMAT[3]->M_V[9].V[8],PMAT[3]->M_V[9].V[9],PMAT[3]->M_V[9].V[10],PMAT[3]->M_V[9].V[11],PMAT[3]->M_V[9].V[12],PMAT[3]->M_V[9].V[13],PMAT[3]->M_V[9].V[14],PMAT[3]->M_V[9].V[15]);
    
    fprintf(fp_mat3_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[10].V[0],PMAT[3]->M_V[10].V[1],PMAT[3]->M_V[10].V[2],PMAT[3]->M_V[10].V[3],PMAT[3]->M_V[10].V[4],PMAT[3]->M_V[10].V[5],PMAT[3]->M_V[10].V[6],PMAT[3]->M_V[10].V[7],PMAT[3]->M_V[10].V[8],PMAT[3]->M_V[10].V[9],PMAT[3]->M_V[10].V[10],PMAT[3]->M_V[10].V[11],PMAT[3]->M_V[10].V[12],PMAT[3]->M_V[10].V[13],PMAT[3]->M_V[10].V[14],PMAT[3]->M_V[10].V[15]);
    
    fprintf(fp_mat3_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[11].V[0],PMAT[3]->M_V[11].V[1],PMAT[3]->M_V[11].V[2],PMAT[3]->M_V[11].V[3],PMAT[3]->M_V[11].V[4],PMAT[3]->M_V[11].V[5],PMAT[3]->M_V[11].V[6],PMAT[3]->M_V[11].V[7],PMAT[3]->M_V[11].V[8],PMAT[3]->M_V[11].V[9],PMAT[3]->M_V[11].V[10],PMAT[3]->M_V[11].V[11],PMAT[3]->M_V[11].V[12],PMAT[3]->M_V[11].V[13],PMAT[3]->M_V[11].V[14],PMAT[3]->M_V[11].V[15]);
    
    fprintf(fp_mat3_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[12].V[0],PMAT[3]->M_V[12].V[1],PMAT[3]->M_V[12].V[2],PMAT[3]->M_V[12].V[3],PMAT[3]->M_V[12].V[4],PMAT[3]->M_V[12].V[5],PMAT[3]->M_V[12].V[6],PMAT[3]->M_V[12].V[7],PMAT[3]->M_V[12].V[8],PMAT[3]->M_V[12].V[9],PMAT[3]->M_V[12].V[10],PMAT[3]->M_V[12].V[11],PMAT[3]->M_V[12].V[12],PMAT[3]->M_V[12].V[13],PMAT[3]->M_V[12].V[14],PMAT[3]->M_V[12].V[15]);
    
    fprintf(fp_mat3_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[13].V[0],PMAT[3]->M_V[13].V[1],PMAT[3]->M_V[13].V[2],PMAT[3]->M_V[13].V[3],PMAT[3]->M_V[13].V[4],PMAT[3]->M_V[13].V[5],PMAT[3]->M_V[13].V[6],PMAT[3]->M_V[13].V[7],PMAT[3]->M_V[13].V[8],PMAT[3]->M_V[13].V[9],PMAT[3]->M_V[13].V[10],PMAT[3]->M_V[13].V[11],PMAT[3]->M_V[13].V[12],PMAT[3]->M_V[13].V[13],PMAT[3]->M_V[13].V[14],PMAT[3]->M_V[13].V[15]);
    
    fprintf(fp_mat3_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[14].V[0],PMAT[3]->M_V[14].V[1],PMAT[3]->M_V[14].V[2],PMAT[3]->M_V[14].V[3],PMAT[3]->M_V[14].V[4],PMAT[3]->M_V[14].V[5],PMAT[3]->M_V[14].V[6],PMAT[3]->M_V[14].V[7],PMAT[3]->M_V[14].V[8],PMAT[3]->M_V[14].V[9],PMAT[3]->M_V[14].V[10],PMAT[3]->M_V[14].V[11],PMAT[3]->M_V[14].V[12],PMAT[3]->M_V[14].V[13],PMAT[3]->M_V[14].V[14],PMAT[3]->M_V[14].V[15]);
    
    fprintf(fp_mat3_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[3]->M_V[15].V[0],PMAT[3]->M_V[15].V[1],PMAT[3]->M_V[15].V[2],PMAT[3]->M_V[15].V[3],PMAT[3]->M_V[15].V[4],PMAT[3]->M_V[15].V[5],PMAT[3]->M_V[15].V[6],PMAT[3]->M_V[15].V[7],PMAT[3]->M_V[15].V[8],PMAT[3]->M_V[15].V[9],PMAT[3]->M_V[15].V[10],PMAT[3]->M_V[15].V[11],PMAT[3]->M_V[15].V[12],PMAT[3]->M_V[15].V[13],PMAT[3]->M_V[15].V[14],PMAT[3]->M_V[15].V[15]);
    
    
    fprintf(fp_mat4_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[0].V[0],PMAT[4]->M_V[0].V[1],PMAT[4]->M_V[0].V[2],PMAT[4]->M_V[0].V[3],PMAT[4]->M_V[0].V[4],PMAT[4]->M_V[0].V[5],PMAT[4]->M_V[0].V[6],PMAT[4]->M_V[0].V[7],PMAT[4]->M_V[0].V[8],PMAT[4]->M_V[0].V[9],PMAT[4]->M_V[0].V[10],PMAT[4]->M_V[0].V[11],PMAT[4]->M_V[0].V[12],PMAT[4]->M_V[0].V[13],PMAT[4]->M_V[0].V[14],PMAT[4]->M_V[0].V[15]);
    
    fprintf(fp_mat4_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[1].V[0],PMAT[4]->M_V[1].V[1],PMAT[4]->M_V[1].V[2],PMAT[4]->M_V[1].V[3],PMAT[4]->M_V[1].V[4],PMAT[4]->M_V[1].V[5],PMAT[4]->M_V[1].V[6],PMAT[4]->M_V[1].V[7],PMAT[4]->M_V[1].V[8],PMAT[4]->M_V[1].V[9],PMAT[4]->M_V[1].V[10],PMAT[4]->M_V[1].V[11],PMAT[4]->M_V[1].V[12],PMAT[4]->M_V[1].V[13],PMAT[4]->M_V[1].V[14],PMAT[4]->M_V[1].V[15]);
    
    fprintf(fp_mat4_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[2].V[0],PMAT[4]->M_V[2].V[1],PMAT[4]->M_V[2].V[2],PMAT[4]->M_V[2].V[3],PMAT[4]->M_V[2].V[4],PMAT[4]->M_V[2].V[5],PMAT[4]->M_V[2].V[6],PMAT[4]->M_V[2].V[7],PMAT[4]->M_V[2].V[8],PMAT[4]->M_V[2].V[9],PMAT[4]->M_V[2].V[10],PMAT[4]->M_V[2].V[11],PMAT[4]->M_V[2].V[12],PMAT[4]->M_V[2].V[13],PMAT[4]->M_V[2].V[14],PMAT[4]->M_V[2].V[15]);
    
    fprintf(fp_mat4_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[3].V[0],PMAT[4]->M_V[3].V[1],PMAT[4]->M_V[3].V[2],PMAT[4]->M_V[3].V[3],PMAT[4]->M_V[3].V[4],PMAT[4]->M_V[3].V[5],PMAT[4]->M_V[3].V[6],PMAT[4]->M_V[3].V[7],PMAT[4]->M_V[3].V[8],PMAT[4]->M_V[3].V[9],PMAT[4]->M_V[3].V[10],PMAT[4]->M_V[3].V[11],PMAT[4]->M_V[3].V[12],PMAT[4]->M_V[3].V[13],PMAT[4]->M_V[3].V[14],PMAT[4]->M_V[3].V[15]);    
    
    fprintf(fp_mat4_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[4].V[0],PMAT[4]->M_V[4].V[1],PMAT[4]->M_V[4].V[2],PMAT[4]->M_V[4].V[3],PMAT[4]->M_V[4].V[4],PMAT[4]->M_V[4].V[5],PMAT[4]->M_V[4].V[6],PMAT[4]->M_V[4].V[7],PMAT[4]->M_V[4].V[8],PMAT[4]->M_V[4].V[9],PMAT[4]->M_V[4].V[10],PMAT[4]->M_V[4].V[11],PMAT[4]->M_V[4].V[12],PMAT[4]->M_V[4].V[13],PMAT[4]->M_V[4].V[14],PMAT[4]->M_V[4].V[15]);
    
    fprintf(fp_mat4_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[5].V[0],PMAT[4]->M_V[5].V[1],PMAT[4]->M_V[5].V[2],PMAT[4]->M_V[5].V[3],PMAT[4]->M_V[5].V[4],PMAT[4]->M_V[5].V[5],PMAT[4]->M_V[5].V[6],PMAT[4]->M_V[5].V[7],PMAT[4]->M_V[5].V[8],PMAT[4]->M_V[5].V[9],PMAT[4]->M_V[5].V[10],PMAT[4]->M_V[5].V[11],PMAT[4]->M_V[5].V[12],PMAT[4]->M_V[5].V[13],PMAT[4]->M_V[5].V[14],PMAT[4]->M_V[5].V[15]);
    
    fprintf(fp_mat4_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[6].V[0],PMAT[4]->M_V[6].V[1],PMAT[4]->M_V[6].V[2],PMAT[4]->M_V[6].V[3],PMAT[4]->M_V[6].V[4],PMAT[4]->M_V[6].V[5],PMAT[4]->M_V[6].V[6],PMAT[4]->M_V[6].V[7],PMAT[4]->M_V[6].V[8],PMAT[4]->M_V[6].V[9],PMAT[4]->M_V[6].V[10],PMAT[4]->M_V[6].V[11],PMAT[4]->M_V[6].V[12],PMAT[4]->M_V[6].V[13],PMAT[4]->M_V[6].V[14],PMAT[4]->M_V[6].V[15]);
    
    fprintf(fp_mat4_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[7].V[0],PMAT[4]->M_V[7].V[1],PMAT[4]->M_V[7].V[2],PMAT[4]->M_V[7].V[3],PMAT[4]->M_V[7].V[4],PMAT[4]->M_V[7].V[5],PMAT[4]->M_V[7].V[6],PMAT[4]->M_V[7].V[7],PMAT[4]->M_V[7].V[8],PMAT[4]->M_V[7].V[9],PMAT[4]->M_V[7].V[10],PMAT[4]->M_V[7].V[11],PMAT[4]->M_V[7].V[12],PMAT[4]->M_V[7].V[13],PMAT[4]->M_V[7].V[14],PMAT[4]->M_V[0].V[15]);
    
    fprintf(fp_mat4_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[8].V[0],PMAT[4]->M_V[8].V[1],PMAT[4]->M_V[8].V[2],PMAT[4]->M_V[8].V[3],PMAT[4]->M_V[8].V[4],PMAT[4]->M_V[8].V[5],PMAT[4]->M_V[8].V[6],PMAT[4]->M_V[8].V[7],PMAT[4]->M_V[8].V[8],PMAT[4]->M_V[8].V[9],PMAT[4]->M_V[8].V[10],PMAT[4]->M_V[8].V[11],PMAT[4]->M_V[8].V[12],PMAT[4]->M_V[8].V[13],PMAT[4]->M_V[8].V[14],PMAT[4]->M_V[8].V[15]);
    
    fprintf(fp_mat4_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[9].V[0],PMAT[4]->M_V[9].V[1],PMAT[4]->M_V[9].V[2],PMAT[4]->M_V[9].V[3],PMAT[4]->M_V[9].V[4],PMAT[4]->M_V[9].V[5],PMAT[4]->M_V[9].V[6],PMAT[4]->M_V[9].V[7],PMAT[4]->M_V[9].V[8],PMAT[4]->M_V[9].V[9],PMAT[4]->M_V[9].V[10],PMAT[4]->M_V[9].V[11],PMAT[4]->M_V[9].V[12],PMAT[4]->M_V[9].V[13],PMAT[4]->M_V[9].V[14],PMAT[4]->M_V[9].V[15]);
    
    fprintf(fp_mat4_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[10].V[0],PMAT[4]->M_V[10].V[1],PMAT[4]->M_V[10].V[2],PMAT[4]->M_V[10].V[3],PMAT[4]->M_V[10].V[4],PMAT[4]->M_V[10].V[5],PMAT[4]->M_V[10].V[6],PMAT[4]->M_V[10].V[7],PMAT[4]->M_V[10].V[8],PMAT[4]->M_V[10].V[9],PMAT[4]->M_V[10].V[10],PMAT[4]->M_V[10].V[11],PMAT[4]->M_V[10].V[12],PMAT[4]->M_V[10].V[13],PMAT[4]->M_V[10].V[14],PMAT[4]->M_V[10].V[15]);
    
    fprintf(fp_mat4_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[11].V[0],PMAT[4]->M_V[11].V[1],PMAT[4]->M_V[11].V[2],PMAT[4]->M_V[11].V[3],PMAT[4]->M_V[11].V[4],PMAT[4]->M_V[11].V[5],PMAT[4]->M_V[11].V[6],PMAT[4]->M_V[11].V[7],PMAT[4]->M_V[11].V[8],PMAT[4]->M_V[11].V[9],PMAT[4]->M_V[11].V[10],PMAT[4]->M_V[11].V[11],PMAT[4]->M_V[11].V[12],PMAT[4]->M_V[11].V[13],PMAT[4]->M_V[11].V[14],PMAT[4]->M_V[11].V[15]);
    
    fprintf(fp_mat4_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[12].V[0],PMAT[4]->M_V[12].V[1],PMAT[4]->M_V[12].V[2],PMAT[4]->M_V[12].V[3],PMAT[4]->M_V[12].V[4],PMAT[4]->M_V[12].V[5],PMAT[4]->M_V[12].V[6],PMAT[4]->M_V[12].V[7],PMAT[4]->M_V[12].V[8],PMAT[4]->M_V[12].V[9],PMAT[4]->M_V[12].V[10],PMAT[4]->M_V[12].V[11],PMAT[4]->M_V[12].V[12],PMAT[4]->M_V[12].V[13],PMAT[4]->M_V[12].V[14],PMAT[4]->M_V[12].V[15]);
    
    fprintf(fp_mat4_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[13].V[0],PMAT[4]->M_V[13].V[1],PMAT[4]->M_V[13].V[2],PMAT[4]->M_V[13].V[3],PMAT[4]->M_V[13].V[4],PMAT[4]->M_V[13].V[5],PMAT[4]->M_V[13].V[6],PMAT[4]->M_V[13].V[7],PMAT[4]->M_V[13].V[8],PMAT[4]->M_V[13].V[9],PMAT[4]->M_V[13].V[10],PMAT[4]->M_V[13].V[11],PMAT[4]->M_V[13].V[12],PMAT[4]->M_V[13].V[13],PMAT[4]->M_V[13].V[14],PMAT[4]->M_V[13].V[15]);
    
    fprintf(fp_mat4_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[14].V[0],PMAT[4]->M_V[14].V[1],PMAT[4]->M_V[14].V[2],PMAT[4]->M_V[14].V[3],PMAT[4]->M_V[14].V[4],PMAT[4]->M_V[14].V[5],PMAT[4]->M_V[14].V[6],PMAT[4]->M_V[14].V[7],PMAT[4]->M_V[14].V[8],PMAT[4]->M_V[14].V[9],PMAT[4]->M_V[14].V[10],PMAT[4]->M_V[14].V[11],PMAT[4]->M_V[14].V[12],PMAT[4]->M_V[14].V[13],PMAT[4]->M_V[14].V[14],PMAT[4]->M_V[14].V[15]);
    
    fprintf(fp_mat4_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[4]->M_V[15].V[0],PMAT[4]->M_V[15].V[1],PMAT[4]->M_V[15].V[2],PMAT[4]->M_V[15].V[3],PMAT[4]->M_V[15].V[4],PMAT[4]->M_V[15].V[5],PMAT[4]->M_V[15].V[6],PMAT[4]->M_V[15].V[7],PMAT[4]->M_V[15].V[8],PMAT[4]->M_V[15].V[9],PMAT[4]->M_V[15].V[10],PMAT[4]->M_V[15].V[11],PMAT[4]->M_V[15].V[12],PMAT[4]->M_V[15].V[13],PMAT[4]->M_V[15].V[14],PMAT[4]->M_V[15].V[15]);
    
    
    fprintf(fp_mat5_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[0].V[0],PMAT[5]->M_V[0].V[1],PMAT[5]->M_V[0].V[2],PMAT[5]->M_V[0].V[3],PMAT[5]->M_V[0].V[4],PMAT[5]->M_V[0].V[5],PMAT[5]->M_V[0].V[6],PMAT[5]->M_V[0].V[7],PMAT[5]->M_V[0].V[8],PMAT[5]->M_V[0].V[9],PMAT[5]->M_V[0].V[10],PMAT[5]->M_V[0].V[11],PMAT[5]->M_V[0].V[12],PMAT[5]->M_V[0].V[13],PMAT[5]->M_V[0].V[14],PMAT[5]->M_V[0].V[15]);
    
    fprintf(fp_mat5_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[1].V[0],PMAT[5]->M_V[1].V[1],PMAT[5]->M_V[1].V[2],PMAT[5]->M_V[1].V[3],PMAT[5]->M_V[1].V[4],PMAT[5]->M_V[1].V[5],PMAT[5]->M_V[1].V[6],PMAT[5]->M_V[1].V[7],PMAT[5]->M_V[1].V[8],PMAT[5]->M_V[1].V[9],PMAT[5]->M_V[1].V[10],PMAT[5]->M_V[1].V[11],PMAT[5]->M_V[1].V[12],PMAT[5]->M_V[1].V[13],PMAT[5]->M_V[1].V[14],PMAT[5]->M_V[1].V[15]);
    
    fprintf(fp_mat5_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[2].V[0],PMAT[5]->M_V[2].V[1],PMAT[5]->M_V[2].V[2],PMAT[5]->M_V[2].V[3],PMAT[5]->M_V[2].V[4],PMAT[5]->M_V[2].V[5],PMAT[5]->M_V[2].V[6],PMAT[5]->M_V[2].V[7],PMAT[5]->M_V[2].V[8],PMAT[5]->M_V[2].V[9],PMAT[5]->M_V[2].V[10],PMAT[5]->M_V[2].V[11],PMAT[5]->M_V[2].V[12],PMAT[5]->M_V[2].V[13],PMAT[5]->M_V[2].V[14],PMAT[5]->M_V[2].V[15]);
    
    fprintf(fp_mat5_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[3].V[0],PMAT[5]->M_V[3].V[1],PMAT[5]->M_V[3].V[2],PMAT[5]->M_V[3].V[3],PMAT[5]->M_V[3].V[4],PMAT[5]->M_V[3].V[5],PMAT[5]->M_V[3].V[6],PMAT[5]->M_V[3].V[7],PMAT[5]->M_V[3].V[8],PMAT[5]->M_V[3].V[9],PMAT[5]->M_V[3].V[10],PMAT[5]->M_V[3].V[11],PMAT[5]->M_V[3].V[12],PMAT[5]->M_V[3].V[13],PMAT[5]->M_V[3].V[14],PMAT[5]->M_V[3].V[15]);    
    
    fprintf(fp_mat5_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[4].V[0],PMAT[5]->M_V[4].V[1],PMAT[5]->M_V[4].V[2],PMAT[5]->M_V[4].V[3],PMAT[5]->M_V[4].V[4],PMAT[5]->M_V[4].V[5],PMAT[5]->M_V[4].V[6],PMAT[5]->M_V[4].V[7],PMAT[5]->M_V[4].V[8],PMAT[5]->M_V[4].V[9],PMAT[5]->M_V[4].V[10],PMAT[5]->M_V[4].V[11],PMAT[5]->M_V[4].V[12],PMAT[5]->M_V[4].V[13],PMAT[5]->M_V[4].V[14],PMAT[5]->M_V[4].V[15]);
    
    fprintf(fp_mat5_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[5].V[0],PMAT[5]->M_V[5].V[1],PMAT[5]->M_V[5].V[2],PMAT[5]->M_V[5].V[3],PMAT[5]->M_V[5].V[4],PMAT[5]->M_V[5].V[5],PMAT[5]->M_V[5].V[6],PMAT[5]->M_V[5].V[7],PMAT[5]->M_V[5].V[8],PMAT[5]->M_V[5].V[9],PMAT[5]->M_V[5].V[10],PMAT[5]->M_V[5].V[11],PMAT[5]->M_V[5].V[12],PMAT[5]->M_V[5].V[13],PMAT[5]->M_V[5].V[14],PMAT[5]->M_V[5].V[15]);
    
    fprintf(fp_mat5_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[6].V[0],PMAT[5]->M_V[6].V[1],PMAT[5]->M_V[6].V[2],PMAT[5]->M_V[6].V[3],PMAT[5]->M_V[6].V[4],PMAT[5]->M_V[6].V[5],PMAT[5]->M_V[6].V[6],PMAT[5]->M_V[6].V[7],PMAT[5]->M_V[6].V[8],PMAT[5]->M_V[6].V[9],PMAT[5]->M_V[6].V[10],PMAT[5]->M_V[6].V[11],PMAT[5]->M_V[6].V[12],PMAT[5]->M_V[6].V[13],PMAT[5]->M_V[6].V[14],PMAT[5]->M_V[6].V[15]);
    
    fprintf(fp_mat5_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[7].V[0],PMAT[5]->M_V[7].V[1],PMAT[5]->M_V[7].V[2],PMAT[5]->M_V[7].V[3],PMAT[5]->M_V[7].V[4],PMAT[5]->M_V[7].V[5],PMAT[5]->M_V[7].V[6],PMAT[5]->M_V[7].V[7],PMAT[5]->M_V[7].V[8],PMAT[5]->M_V[7].V[9],PMAT[5]->M_V[7].V[10],PMAT[5]->M_V[7].V[11],PMAT[5]->M_V[7].V[12],PMAT[5]->M_V[7].V[13],PMAT[5]->M_V[7].V[14],PMAT[5]->M_V[0].V[15]);
    
    fprintf(fp_mat5_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[8].V[0],PMAT[5]->M_V[8].V[1],PMAT[5]->M_V[8].V[2],PMAT[5]->M_V[8].V[3],PMAT[5]->M_V[8].V[4],PMAT[5]->M_V[8].V[5],PMAT[5]->M_V[8].V[6],PMAT[5]->M_V[8].V[7],PMAT[5]->M_V[8].V[8],PMAT[5]->M_V[8].V[9],PMAT[5]->M_V[8].V[10],PMAT[5]->M_V[8].V[11],PMAT[5]->M_V[8].V[12],PMAT[5]->M_V[8].V[13],PMAT[5]->M_V[8].V[14],PMAT[5]->M_V[8].V[15]);
    
    fprintf(fp_mat5_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[9].V[0],PMAT[5]->M_V[9].V[1],PMAT[5]->M_V[9].V[2],PMAT[5]->M_V[9].V[3],PMAT[5]->M_V[9].V[4],PMAT[5]->M_V[9].V[5],PMAT[5]->M_V[9].V[6],PMAT[5]->M_V[9].V[7],PMAT[5]->M_V[9].V[8],PMAT[5]->M_V[9].V[9],PMAT[5]->M_V[9].V[10],PMAT[5]->M_V[9].V[11],PMAT[5]->M_V[9].V[12],PMAT[5]->M_V[9].V[13],PMAT[5]->M_V[9].V[14],PMAT[5]->M_V[9].V[15]);
    
    fprintf(fp_mat5_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[10].V[0],PMAT[5]->M_V[10].V[1],PMAT[5]->M_V[10].V[2],PMAT[5]->M_V[10].V[3],PMAT[5]->M_V[10].V[4],PMAT[5]->M_V[10].V[5],PMAT[5]->M_V[10].V[6],PMAT[5]->M_V[10].V[7],PMAT[5]->M_V[10].V[8],PMAT[5]->M_V[10].V[9],PMAT[5]->M_V[10].V[10],PMAT[5]->M_V[10].V[11],PMAT[5]->M_V[10].V[12],PMAT[5]->M_V[10].V[13],PMAT[5]->M_V[10].V[14],PMAT[5]->M_V[10].V[15]);
    
    fprintf(fp_mat5_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[11].V[0],PMAT[5]->M_V[11].V[1],PMAT[5]->M_V[11].V[2],PMAT[5]->M_V[11].V[3],PMAT[5]->M_V[11].V[4],PMAT[5]->M_V[11].V[5],PMAT[5]->M_V[11].V[6],PMAT[5]->M_V[11].V[7],PMAT[5]->M_V[11].V[8],PMAT[5]->M_V[11].V[9],PMAT[5]->M_V[11].V[10],PMAT[5]->M_V[11].V[11],PMAT[5]->M_V[11].V[12],PMAT[5]->M_V[11].V[13],PMAT[5]->M_V[11].V[14],PMAT[5]->M_V[11].V[15]);
    
    fprintf(fp_mat5_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[12].V[0],PMAT[5]->M_V[12].V[1],PMAT[5]->M_V[12].V[2],PMAT[5]->M_V[12].V[3],PMAT[5]->M_V[12].V[4],PMAT[5]->M_V[12].V[5],PMAT[5]->M_V[12].V[6],PMAT[5]->M_V[12].V[7],PMAT[5]->M_V[12].V[8],PMAT[5]->M_V[12].V[9],PMAT[5]->M_V[12].V[10],PMAT[5]->M_V[12].V[11],PMAT[5]->M_V[12].V[12],PMAT[5]->M_V[12].V[13],PMAT[5]->M_V[12].V[14],PMAT[5]->M_V[12].V[15]);
    
    fprintf(fp_mat5_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[13].V[0],PMAT[5]->M_V[13].V[1],PMAT[5]->M_V[13].V[2],PMAT[5]->M_V[13].V[3],PMAT[5]->M_V[13].V[4],PMAT[5]->M_V[13].V[5],PMAT[5]->M_V[13].V[6],PMAT[5]->M_V[13].V[7],PMAT[5]->M_V[13].V[8],PMAT[5]->M_V[13].V[9],PMAT[5]->M_V[13].V[10],PMAT[5]->M_V[13].V[11],PMAT[5]->M_V[13].V[12],PMAT[5]->M_V[13].V[13],PMAT[5]->M_V[13].V[14],PMAT[5]->M_V[13].V[15]);
    
    fprintf(fp_mat5_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[14].V[0],PMAT[5]->M_V[14].V[1],PMAT[5]->M_V[14].V[2],PMAT[5]->M_V[14].V[3],PMAT[5]->M_V[14].V[4],PMAT[5]->M_V[14].V[5],PMAT[5]->M_V[14].V[6],PMAT[5]->M_V[14].V[7],PMAT[5]->M_V[14].V[8],PMAT[5]->M_V[14].V[9],PMAT[5]->M_V[14].V[10],PMAT[5]->M_V[14].V[11],PMAT[5]->M_V[14].V[12],PMAT[5]->M_V[14].V[13],PMAT[5]->M_V[14].V[14],PMAT[5]->M_V[14].V[15]);
    
    fprintf(fp_mat5_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[5]->M_V[15].V[0],PMAT[5]->M_V[15].V[1],PMAT[5]->M_V[15].V[2],PMAT[5]->M_V[15].V[3],PMAT[5]->M_V[15].V[4],PMAT[5]->M_V[15].V[5],PMAT[5]->M_V[15].V[6],PMAT[5]->M_V[15].V[7],PMAT[5]->M_V[15].V[8],PMAT[5]->M_V[15].V[9],PMAT[5]->M_V[15].V[10],PMAT[5]->M_V[15].V[11],PMAT[5]->M_V[15].V[12],PMAT[5]->M_V[15].V[13],PMAT[5]->M_V[15].V[14],PMAT[5]->M_V[15].V[15]);
    
    
    fprintf(fp_mat6_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[0].V[0],PMAT[6]->M_V[0].V[1],PMAT[6]->M_V[0].V[2],PMAT[6]->M_V[0].V[3],PMAT[6]->M_V[0].V[4],PMAT[6]->M_V[0].V[5],PMAT[6]->M_V[0].V[6],PMAT[6]->M_V[0].V[7],PMAT[6]->M_V[0].V[8],PMAT[6]->M_V[0].V[9],PMAT[6]->M_V[0].V[10],PMAT[6]->M_V[0].V[11],PMAT[6]->M_V[0].V[12],PMAT[6]->M_V[0].V[13],PMAT[6]->M_V[0].V[14],PMAT[6]->M_V[0].V[15]);
    
    fprintf(fp_mat6_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[1].V[0],PMAT[6]->M_V[1].V[1],PMAT[6]->M_V[1].V[2],PMAT[6]->M_V[1].V[3],PMAT[6]->M_V[1].V[4],PMAT[6]->M_V[1].V[5],PMAT[6]->M_V[1].V[6],PMAT[6]->M_V[1].V[7],PMAT[6]->M_V[1].V[8],PMAT[6]->M_V[1].V[9],PMAT[6]->M_V[1].V[10],PMAT[6]->M_V[1].V[11],PMAT[6]->M_V[1].V[12],PMAT[6]->M_V[1].V[13],PMAT[6]->M_V[1].V[14],PMAT[6]->M_V[1].V[15]);
    
    fprintf(fp_mat6_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[2].V[0],PMAT[6]->M_V[2].V[1],PMAT[6]->M_V[2].V[2],PMAT[6]->M_V[2].V[3],PMAT[6]->M_V[2].V[4],PMAT[6]->M_V[2].V[5],PMAT[6]->M_V[2].V[6],PMAT[6]->M_V[2].V[7],PMAT[6]->M_V[2].V[8],PMAT[6]->M_V[2].V[9],PMAT[6]->M_V[2].V[10],PMAT[6]->M_V[2].V[11],PMAT[6]->M_V[2].V[12],PMAT[6]->M_V[2].V[13],PMAT[6]->M_V[2].V[14],PMAT[6]->M_V[2].V[15]);
    
    fprintf(fp_mat6_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[3].V[0],PMAT[6]->M_V[3].V[1],PMAT[6]->M_V[3].V[2],PMAT[6]->M_V[3].V[3],PMAT[6]->M_V[3].V[4],PMAT[6]->M_V[3].V[5],PMAT[6]->M_V[3].V[6],PMAT[6]->M_V[3].V[7],PMAT[6]->M_V[3].V[8],PMAT[6]->M_V[3].V[9],PMAT[6]->M_V[3].V[10],PMAT[6]->M_V[3].V[11],PMAT[6]->M_V[3].V[12],PMAT[6]->M_V[3].V[13],PMAT[6]->M_V[3].V[14],PMAT[6]->M_V[3].V[15]);    
    
    fprintf(fp_mat6_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[4].V[0],PMAT[6]->M_V[4].V[1],PMAT[6]->M_V[4].V[2],PMAT[6]->M_V[4].V[3],PMAT[6]->M_V[4].V[4],PMAT[6]->M_V[4].V[5],PMAT[6]->M_V[4].V[6],PMAT[6]->M_V[4].V[7],PMAT[6]->M_V[4].V[8],PMAT[6]->M_V[4].V[9],PMAT[6]->M_V[4].V[10],PMAT[6]->M_V[4].V[11],PMAT[6]->M_V[4].V[12],PMAT[6]->M_V[4].V[13],PMAT[6]->M_V[4].V[14],PMAT[6]->M_V[4].V[15]);
    
    fprintf(fp_mat6_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[5].V[0],PMAT[6]->M_V[5].V[1],PMAT[6]->M_V[5].V[2],PMAT[6]->M_V[5].V[3],PMAT[6]->M_V[5].V[4],PMAT[6]->M_V[5].V[5],PMAT[6]->M_V[5].V[6],PMAT[6]->M_V[5].V[7],PMAT[6]->M_V[5].V[8],PMAT[6]->M_V[5].V[9],PMAT[6]->M_V[5].V[10],PMAT[6]->M_V[5].V[11],PMAT[6]->M_V[5].V[12],PMAT[6]->M_V[5].V[13],PMAT[6]->M_V[5].V[14],PMAT[6]->M_V[5].V[15]);
    
    fprintf(fp_mat6_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[6].V[0],PMAT[6]->M_V[6].V[1],PMAT[6]->M_V[6].V[2],PMAT[6]->M_V[6].V[3],PMAT[6]->M_V[6].V[4],PMAT[6]->M_V[6].V[5],PMAT[6]->M_V[6].V[6],PMAT[6]->M_V[6].V[7],PMAT[6]->M_V[6].V[8],PMAT[6]->M_V[6].V[9],PMAT[6]->M_V[6].V[10],PMAT[6]->M_V[6].V[11],PMAT[6]->M_V[6].V[12],PMAT[6]->M_V[6].V[13],PMAT[6]->M_V[6].V[14],PMAT[6]->M_V[6].V[15]);
    
    fprintf(fp_mat6_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[7].V[0],PMAT[6]->M_V[7].V[1],PMAT[6]->M_V[7].V[2],PMAT[6]->M_V[7].V[3],PMAT[6]->M_V[7].V[4],PMAT[6]->M_V[7].V[5],PMAT[6]->M_V[7].V[6],PMAT[6]->M_V[7].V[7],PMAT[6]->M_V[7].V[8],PMAT[6]->M_V[7].V[9],PMAT[6]->M_V[7].V[10],PMAT[6]->M_V[7].V[11],PMAT[6]->M_V[7].V[12],PMAT[6]->M_V[7].V[13],PMAT[6]->M_V[7].V[14],PMAT[6]->M_V[0].V[15]);
    
    fprintf(fp_mat6_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[8].V[0],PMAT[6]->M_V[8].V[1],PMAT[6]->M_V[8].V[2],PMAT[6]->M_V[8].V[3],PMAT[6]->M_V[8].V[4],PMAT[6]->M_V[8].V[5],PMAT[6]->M_V[8].V[6],PMAT[6]->M_V[8].V[7],PMAT[6]->M_V[8].V[8],PMAT[6]->M_V[8].V[9],PMAT[6]->M_V[8].V[10],PMAT[6]->M_V[8].V[11],PMAT[6]->M_V[8].V[12],PMAT[6]->M_V[8].V[13],PMAT[6]->M_V[8].V[14],PMAT[6]->M_V[8].V[15]);
    
    fprintf(fp_mat6_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[9].V[0],PMAT[6]->M_V[9].V[1],PMAT[6]->M_V[9].V[2],PMAT[6]->M_V[9].V[3],PMAT[6]->M_V[9].V[4],PMAT[6]->M_V[9].V[5],PMAT[6]->M_V[9].V[6],PMAT[6]->M_V[9].V[7],PMAT[6]->M_V[9].V[8],PMAT[6]->M_V[9].V[9],PMAT[6]->M_V[9].V[10],PMAT[6]->M_V[9].V[11],PMAT[6]->M_V[9].V[12],PMAT[6]->M_V[9].V[13],PMAT[6]->M_V[9].V[14],PMAT[6]->M_V[9].V[15]);
    
    fprintf(fp_mat6_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[10].V[0],PMAT[6]->M_V[10].V[1],PMAT[6]->M_V[10].V[2],PMAT[6]->M_V[10].V[3],PMAT[6]->M_V[10].V[4],PMAT[6]->M_V[10].V[5],PMAT[6]->M_V[10].V[6],PMAT[6]->M_V[10].V[7],PMAT[6]->M_V[10].V[8],PMAT[6]->M_V[10].V[9],PMAT[6]->M_V[10].V[10],PMAT[6]->M_V[10].V[11],PMAT[6]->M_V[10].V[12],PMAT[6]->M_V[10].V[13],PMAT[6]->M_V[10].V[14],PMAT[6]->M_V[10].V[15]);
    
    fprintf(fp_mat6_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[11].V[0],PMAT[6]->M_V[11].V[1],PMAT[6]->M_V[11].V[2],PMAT[6]->M_V[11].V[3],PMAT[6]->M_V[11].V[4],PMAT[6]->M_V[11].V[5],PMAT[6]->M_V[11].V[6],PMAT[6]->M_V[11].V[7],PMAT[6]->M_V[11].V[8],PMAT[6]->M_V[11].V[9],PMAT[6]->M_V[11].V[10],PMAT[6]->M_V[11].V[11],PMAT[6]->M_V[11].V[12],PMAT[6]->M_V[11].V[13],PMAT[6]->M_V[11].V[14],PMAT[6]->M_V[11].V[15]);
    
    fprintf(fp_mat6_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[12].V[0],PMAT[6]->M_V[12].V[1],PMAT[6]->M_V[12].V[2],PMAT[6]->M_V[12].V[3],PMAT[6]->M_V[12].V[4],PMAT[6]->M_V[12].V[5],PMAT[6]->M_V[12].V[6],PMAT[6]->M_V[12].V[7],PMAT[6]->M_V[12].V[8],PMAT[6]->M_V[12].V[9],PMAT[6]->M_V[12].V[10],PMAT[6]->M_V[12].V[11],PMAT[6]->M_V[12].V[12],PMAT[6]->M_V[12].V[13],PMAT[6]->M_V[12].V[14],PMAT[6]->M_V[12].V[15]);
    
    fprintf(fp_mat6_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[13].V[0],PMAT[6]->M_V[13].V[1],PMAT[6]->M_V[13].V[2],PMAT[6]->M_V[13].V[3],PMAT[6]->M_V[13].V[4],PMAT[6]->M_V[13].V[5],PMAT[6]->M_V[13].V[6],PMAT[6]->M_V[13].V[7],PMAT[6]->M_V[13].V[8],PMAT[6]->M_V[13].V[9],PMAT[6]->M_V[13].V[10],PMAT[6]->M_V[13].V[11],PMAT[6]->M_V[13].V[12],PMAT[6]->M_V[13].V[13],PMAT[6]->M_V[13].V[14],PMAT[6]->M_V[13].V[15]);
    
    fprintf(fp_mat6_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[14].V[0],PMAT[6]->M_V[14].V[1],PMAT[6]->M_V[14].V[2],PMAT[6]->M_V[14].V[3],PMAT[6]->M_V[14].V[4],PMAT[6]->M_V[14].V[5],PMAT[6]->M_V[14].V[6],PMAT[6]->M_V[14].V[7],PMAT[6]->M_V[14].V[8],PMAT[6]->M_V[14].V[9],PMAT[6]->M_V[14].V[10],PMAT[6]->M_V[14].V[11],PMAT[6]->M_V[14].V[12],PMAT[6]->M_V[14].V[13],PMAT[6]->M_V[14].V[14],PMAT[6]->M_V[14].V[15]);
    
    fprintf(fp_mat6_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[6]->M_V[15].V[0],PMAT[6]->M_V[15].V[1],PMAT[6]->M_V[15].V[2],PMAT[6]->M_V[15].V[3],PMAT[6]->M_V[15].V[4],PMAT[6]->M_V[15].V[5],PMAT[6]->M_V[15].V[6],PMAT[6]->M_V[15].V[7],PMAT[6]->M_V[15].V[8],PMAT[6]->M_V[15].V[9],PMAT[6]->M_V[15].V[10],PMAT[6]->M_V[15].V[11],PMAT[6]->M_V[15].V[12],PMAT[6]->M_V[15].V[13],PMAT[6]->M_V[15].V[14],PMAT[6]->M_V[15].V[15]);
    
    
    fprintf(fp_mat7_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[0].V[0],PMAT[7]->M_V[0].V[1],PMAT[7]->M_V[0].V[2],PMAT[7]->M_V[0].V[3],PMAT[7]->M_V[0].V[4],PMAT[7]->M_V[0].V[5],PMAT[7]->M_V[0].V[6],PMAT[7]->M_V[0].V[7],PMAT[7]->M_V[0].V[8],PMAT[7]->M_V[0].V[9],PMAT[7]->M_V[0].V[10],PMAT[7]->M_V[0].V[11],PMAT[7]->M_V[0].V[12],PMAT[7]->M_V[0].V[13],PMAT[7]->M_V[0].V[14],PMAT[7]->M_V[0].V[15]);
    
    fprintf(fp_mat7_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[1].V[0],PMAT[7]->M_V[1].V[1],PMAT[7]->M_V[1].V[2],PMAT[7]->M_V[1].V[3],PMAT[7]->M_V[1].V[4],PMAT[7]->M_V[1].V[5],PMAT[7]->M_V[1].V[6],PMAT[7]->M_V[1].V[7],PMAT[7]->M_V[1].V[8],PMAT[7]->M_V[1].V[9],PMAT[7]->M_V[1].V[10],PMAT[7]->M_V[1].V[11],PMAT[7]->M_V[1].V[12],PMAT[7]->M_V[1].V[13],PMAT[7]->M_V[1].V[14],PMAT[7]->M_V[1].V[15]);
    
    fprintf(fp_mat7_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[2].V[0],PMAT[7]->M_V[2].V[1],PMAT[7]->M_V[2].V[2],PMAT[7]->M_V[2].V[3],PMAT[7]->M_V[2].V[4],PMAT[7]->M_V[2].V[5],PMAT[7]->M_V[2].V[6],PMAT[7]->M_V[2].V[7],PMAT[7]->M_V[2].V[8],PMAT[7]->M_V[2].V[9],PMAT[7]->M_V[2].V[10],PMAT[7]->M_V[2].V[11],PMAT[7]->M_V[2].V[12],PMAT[7]->M_V[2].V[13],PMAT[7]->M_V[2].V[14],PMAT[7]->M_V[2].V[15]);
    
    fprintf(fp_mat7_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[3].V[0],PMAT[7]->M_V[3].V[1],PMAT[7]->M_V[3].V[2],PMAT[7]->M_V[3].V[3],PMAT[7]->M_V[3].V[4],PMAT[7]->M_V[3].V[5],PMAT[7]->M_V[3].V[6],PMAT[7]->M_V[3].V[7],PMAT[7]->M_V[3].V[8],PMAT[7]->M_V[3].V[9],PMAT[7]->M_V[3].V[10],PMAT[7]->M_V[3].V[11],PMAT[7]->M_V[3].V[12],PMAT[7]->M_V[3].V[13],PMAT[7]->M_V[3].V[14],PMAT[7]->M_V[3].V[15]);    
    
    fprintf(fp_mat7_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[4].V[0],PMAT[7]->M_V[4].V[1],PMAT[7]->M_V[4].V[2],PMAT[7]->M_V[4].V[3],PMAT[7]->M_V[4].V[4],PMAT[7]->M_V[4].V[5],PMAT[7]->M_V[4].V[6],PMAT[7]->M_V[4].V[7],PMAT[7]->M_V[4].V[8],PMAT[7]->M_V[4].V[9],PMAT[7]->M_V[4].V[10],PMAT[7]->M_V[4].V[11],PMAT[7]->M_V[4].V[12],PMAT[7]->M_V[4].V[13],PMAT[7]->M_V[4].V[14],PMAT[7]->M_V[4].V[15]);
    
    fprintf(fp_mat7_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[5].V[0],PMAT[7]->M_V[5].V[1],PMAT[7]->M_V[5].V[2],PMAT[7]->M_V[5].V[3],PMAT[7]->M_V[5].V[4],PMAT[7]->M_V[5].V[5],PMAT[7]->M_V[5].V[6],PMAT[7]->M_V[5].V[7],PMAT[7]->M_V[5].V[8],PMAT[7]->M_V[5].V[9],PMAT[7]->M_V[5].V[10],PMAT[7]->M_V[5].V[11],PMAT[7]->M_V[5].V[12],PMAT[7]->M_V[5].V[13],PMAT[7]->M_V[5].V[14],PMAT[7]->M_V[5].V[15]);
    
    fprintf(fp_mat7_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[6].V[0],PMAT[7]->M_V[6].V[1],PMAT[7]->M_V[6].V[2],PMAT[7]->M_V[6].V[3],PMAT[7]->M_V[6].V[4],PMAT[7]->M_V[6].V[5],PMAT[7]->M_V[6].V[6],PMAT[7]->M_V[6].V[7],PMAT[7]->M_V[6].V[8],PMAT[7]->M_V[6].V[9],PMAT[7]->M_V[6].V[10],PMAT[7]->M_V[6].V[11],PMAT[7]->M_V[6].V[12],PMAT[7]->M_V[6].V[13],PMAT[7]->M_V[6].V[14],PMAT[7]->M_V[6].V[15]);
    
    fprintf(fp_mat7_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[7].V[0],PMAT[7]->M_V[7].V[1],PMAT[7]->M_V[7].V[2],PMAT[7]->M_V[7].V[3],PMAT[7]->M_V[7].V[4],PMAT[7]->M_V[7].V[5],PMAT[7]->M_V[7].V[6],PMAT[7]->M_V[7].V[7],PMAT[7]->M_V[7].V[8],PMAT[7]->M_V[7].V[9],PMAT[7]->M_V[7].V[10],PMAT[7]->M_V[7].V[11],PMAT[7]->M_V[7].V[12],PMAT[7]->M_V[7].V[13],PMAT[7]->M_V[7].V[14],PMAT[7]->M_V[0].V[15]);
    
    fprintf(fp_mat7_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[8].V[0],PMAT[7]->M_V[8].V[1],PMAT[7]->M_V[8].V[2],PMAT[7]->M_V[8].V[3],PMAT[7]->M_V[8].V[4],PMAT[7]->M_V[8].V[5],PMAT[7]->M_V[8].V[6],PMAT[7]->M_V[8].V[7],PMAT[7]->M_V[8].V[8],PMAT[7]->M_V[8].V[9],PMAT[7]->M_V[8].V[10],PMAT[7]->M_V[8].V[11],PMAT[7]->M_V[8].V[12],PMAT[7]->M_V[8].V[13],PMAT[7]->M_V[8].V[14],PMAT[7]->M_V[8].V[15]);
    
    fprintf(fp_mat7_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[9].V[0],PMAT[7]->M_V[9].V[1],PMAT[7]->M_V[9].V[2],PMAT[7]->M_V[9].V[3],PMAT[7]->M_V[9].V[4],PMAT[7]->M_V[9].V[5],PMAT[7]->M_V[9].V[6],PMAT[7]->M_V[9].V[7],PMAT[7]->M_V[9].V[8],PMAT[7]->M_V[9].V[9],PMAT[7]->M_V[9].V[10],PMAT[7]->M_V[9].V[11],PMAT[7]->M_V[9].V[12],PMAT[7]->M_V[9].V[13],PMAT[7]->M_V[9].V[14],PMAT[7]->M_V[9].V[15]);
    
    fprintf(fp_mat7_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[10].V[0],PMAT[7]->M_V[10].V[1],PMAT[7]->M_V[10].V[2],PMAT[7]->M_V[10].V[3],PMAT[7]->M_V[10].V[4],PMAT[7]->M_V[10].V[5],PMAT[7]->M_V[10].V[6],PMAT[7]->M_V[10].V[7],PMAT[7]->M_V[10].V[8],PMAT[7]->M_V[10].V[9],PMAT[7]->M_V[10].V[10],PMAT[7]->M_V[10].V[11],PMAT[7]->M_V[10].V[12],PMAT[7]->M_V[10].V[13],PMAT[7]->M_V[10].V[14],PMAT[7]->M_V[10].V[15]);
    
    fprintf(fp_mat7_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[11].V[0],PMAT[7]->M_V[11].V[1],PMAT[7]->M_V[11].V[2],PMAT[7]->M_V[11].V[3],PMAT[7]->M_V[11].V[4],PMAT[7]->M_V[11].V[5],PMAT[7]->M_V[11].V[6],PMAT[7]->M_V[11].V[7],PMAT[7]->M_V[11].V[8],PMAT[7]->M_V[11].V[9],PMAT[7]->M_V[11].V[10],PMAT[7]->M_V[11].V[11],PMAT[7]->M_V[11].V[12],PMAT[7]->M_V[11].V[13],PMAT[7]->M_V[11].V[14],PMAT[7]->M_V[11].V[15]);
    
    fprintf(fp_mat7_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[12].V[0],PMAT[7]->M_V[12].V[1],PMAT[7]->M_V[12].V[2],PMAT[7]->M_V[12].V[3],PMAT[7]->M_V[12].V[4],PMAT[7]->M_V[12].V[5],PMAT[7]->M_V[12].V[6],PMAT[7]->M_V[12].V[7],PMAT[7]->M_V[12].V[8],PMAT[7]->M_V[12].V[9],PMAT[7]->M_V[12].V[10],PMAT[7]->M_V[12].V[11],PMAT[7]->M_V[12].V[12],PMAT[7]->M_V[12].V[13],PMAT[7]->M_V[12].V[14],PMAT[7]->M_V[12].V[15]);
    
    fprintf(fp_mat7_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[13].V[0],PMAT[7]->M_V[13].V[1],PMAT[7]->M_V[13].V[2],PMAT[7]->M_V[13].V[3],PMAT[7]->M_V[13].V[4],PMAT[7]->M_V[13].V[5],PMAT[7]->M_V[13].V[6],PMAT[7]->M_V[13].V[7],PMAT[7]->M_V[13].V[8],PMAT[7]->M_V[13].V[9],PMAT[7]->M_V[13].V[10],PMAT[7]->M_V[13].V[11],PMAT[7]->M_V[13].V[12],PMAT[7]->M_V[13].V[13],PMAT[7]->M_V[13].V[14],PMAT[7]->M_V[13].V[15]);
    
    fprintf(fp_mat7_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[14].V[0],PMAT[7]->M_V[14].V[1],PMAT[7]->M_V[14].V[2],PMAT[7]->M_V[14].V[3],PMAT[7]->M_V[14].V[4],PMAT[7]->M_V[14].V[5],PMAT[7]->M_V[14].V[6],PMAT[7]->M_V[14].V[7],PMAT[7]->M_V[14].V[8],PMAT[7]->M_V[14].V[9],PMAT[7]->M_V[14].V[10],PMAT[7]->M_V[14].V[11],PMAT[7]->M_V[14].V[12],PMAT[7]->M_V[14].V[13],PMAT[7]->M_V[14].V[14],PMAT[7]->M_V[14].V[15]);
    
    fprintf(fp_mat7_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",PMAT[7]->M_V[15].V[0],PMAT[7]->M_V[15].V[1],PMAT[7]->M_V[15].V[2],PMAT[7]->M_V[15].V[3],PMAT[7]->M_V[15].V[4],PMAT[7]->M_V[15].V[5],PMAT[7]->M_V[15].V[6],PMAT[7]->M_V[15].V[7],PMAT[7]->M_V[15].V[8],PMAT[7]->M_V[15].V[9],PMAT[7]->M_V[15].V[10],PMAT[7]->M_V[15].V[11],PMAT[7]->M_V[15].V[12],PMAT[7]->M_V[15].V[13],PMAT[7]->M_V[15].V[14],PMAT[7]->M_V[15].V[15]);
    
    
   /* fprintf(fp_mat8_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[0].V[0],MAT[8]->M_V[0].V[1],MAT[8]->M_V[0].V[2],MAT[8]->M_V[0].V[3],MAT[8]->M_V[0].V[4],MAT[8]->M_V[0].V[5],MAT[8]->M_V[0].V[6],MAT[8]->M_V[0].V[7],MAT[8]->M_V[0].V[8],MAT[8]->M_V[0].V[9],MAT[8]->M_V[0].V[10],MAT[8]->M_V[0].V[11],MAT[8]->M_V[0].V[12],MAT[8]->M_V[0].V[13],MAT[8]->M_V[0].V[14],MAT[8]->M_V[0].V[15]);
    
    fprintf(fp_mat8_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[1].V[0],MAT[8]->M_V[1].V[1],MAT[8]->M_V[1].V[2],MAT[8]->M_V[1].V[3],MAT[8]->M_V[1].V[4],MAT[8]->M_V[1].V[5],MAT[8]->M_V[1].V[6],MAT[8]->M_V[1].V[7],MAT[8]->M_V[1].V[8],MAT[8]->M_V[1].V[9],MAT[8]->M_V[1].V[10],MAT[8]->M_V[1].V[11],MAT[8]->M_V[1].V[12],MAT[8]->M_V[1].V[13],MAT[8]->M_V[1].V[14],MAT[8]->M_V[1].V[15]);
    
    fprintf(fp_mat8_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[2].V[0],MAT[8]->M_V[2].V[1],MAT[8]->M_V[2].V[2],MAT[8]->M_V[2].V[3],MAT[8]->M_V[2].V[4],MAT[8]->M_V[2].V[5],MAT[8]->M_V[2].V[6],MAT[8]->M_V[2].V[7],MAT[8]->M_V[2].V[8],MAT[8]->M_V[2].V[9],MAT[8]->M_V[2].V[10],MAT[8]->M_V[2].V[11],MAT[8]->M_V[2].V[12],MAT[8]->M_V[2].V[13],MAT[8]->M_V[2].V[14],MAT[8]->M_V[2].V[15]);
    
    fprintf(fp_mat8_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[3].V[0],MAT[8]->M_V[3].V[1],MAT[8]->M_V[3].V[2],MAT[8]->M_V[3].V[3],MAT[8]->M_V[3].V[4],MAT[8]->M_V[3].V[5],MAT[8]->M_V[3].V[6],MAT[8]->M_V[3].V[7],MAT[8]->M_V[3].V[8],MAT[8]->M_V[3].V[9],MAT[8]->M_V[3].V[10],MAT[8]->M_V[3].V[11],MAT[8]->M_V[3].V[12],MAT[8]->M_V[3].V[13],MAT[8]->M_V[3].V[14],MAT[8]->M_V[3].V[15]);    
    
    fprintf(fp_mat8_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[4].V[0],MAT[8]->M_V[4].V[1],MAT[8]->M_V[4].V[2],MAT[8]->M_V[4].V[3],MAT[8]->M_V[4].V[4],MAT[8]->M_V[4].V[5],MAT[8]->M_V[4].V[6],MAT[8]->M_V[4].V[7],MAT[8]->M_V[4].V[8],MAT[8]->M_V[4].V[9],MAT[8]->M_V[4].V[10],MAT[8]->M_V[4].V[11],MAT[8]->M_V[4].V[12],MAT[8]->M_V[4].V[13],MAT[8]->M_V[4].V[14],MAT[8]->M_V[4].V[15]);
    
    fprintf(fp_mat8_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[5].V[0],MAT[8]->M_V[5].V[1],MAT[8]->M_V[5].V[2],MAT[8]->M_V[5].V[3],MAT[8]->M_V[5].V[4],MAT[8]->M_V[5].V[5],MAT[8]->M_V[5].V[6],MAT[8]->M_V[5].V[7],MAT[8]->M_V[5].V[8],MAT[8]->M_V[5].V[9],MAT[8]->M_V[5].V[10],MAT[8]->M_V[5].V[11],MAT[8]->M_V[5].V[12],MAT[8]->M_V[5].V[13],MAT[8]->M_V[5].V[14],MAT[8]->M_V[5].V[15]);
    
    fprintf(fp_mat8_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[6].V[0],MAT[8]->M_V[6].V[1],MAT[8]->M_V[6].V[2],MAT[8]->M_V[6].V[3],MAT[8]->M_V[6].V[4],MAT[8]->M_V[6].V[5],MAT[8]->M_V[6].V[6],MAT[8]->M_V[6].V[7],MAT[8]->M_V[6].V[8],MAT[8]->M_V[6].V[9],MAT[8]->M_V[6].V[10],MAT[8]->M_V[6].V[11],MAT[8]->M_V[6].V[12],MAT[8]->M_V[6].V[13],MAT[8]->M_V[6].V[14],MAT[8]->M_V[6].V[15]);
    
    fprintf(fp_mat8_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[7].V[0],MAT[8]->M_V[7].V[1],MAT[8]->M_V[7].V[2],MAT[8]->M_V[7].V[3],MAT[8]->M_V[7].V[4],MAT[8]->M_V[7].V[5],MAT[8]->M_V[7].V[6],MAT[8]->M_V[7].V[7],MAT[8]->M_V[7].V[8],MAT[8]->M_V[7].V[9],MAT[8]->M_V[7].V[10],MAT[8]->M_V[7].V[11],MAT[8]->M_V[7].V[12],MAT[8]->M_V[7].V[13],MAT[8]->M_V[7].V[14],MAT[8]->M_V[0].V[15]);
    
    fprintf(fp_mat8_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[8].V[0],MAT[8]->M_V[8].V[1],MAT[8]->M_V[8].V[2],MAT[8]->M_V[8].V[3],MAT[8]->M_V[8].V[4],MAT[8]->M_V[8].V[5],MAT[8]->M_V[8].V[6],MAT[8]->M_V[8].V[7],MAT[8]->M_V[8].V[8],MAT[8]->M_V[8].V[9],MAT[8]->M_V[8].V[10],MAT[8]->M_V[8].V[11],MAT[8]->M_V[8].V[12],MAT[8]->M_V[8].V[13],MAT[8]->M_V[8].V[14],MAT[8]->M_V[8].V[15]);
    
    fprintf(fp_mat8_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[9].V[0],MAT[8]->M_V[9].V[1],MAT[8]->M_V[9].V[2],MAT[8]->M_V[9].V[3],MAT[8]->M_V[9].V[4],MAT[8]->M_V[9].V[5],MAT[8]->M_V[9].V[6],MAT[8]->M_V[9].V[7],MAT[8]->M_V[9].V[8],MAT[8]->M_V[9].V[9],MAT[8]->M_V[9].V[10],MAT[8]->M_V[9].V[11],MAT[8]->M_V[9].V[12],MAT[8]->M_V[9].V[13],MAT[8]->M_V[9].V[14],MAT[8]->M_V[9].V[15]);
    
    fprintf(fp_mat8_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[10].V[0],MAT[8]->M_V[10].V[1],MAT[8]->M_V[10].V[2],MAT[8]->M_V[10].V[3],MAT[8]->M_V[10].V[4],MAT[8]->M_V[10].V[5],MAT[8]->M_V[10].V[6],MAT[8]->M_V[10].V[7],MAT[8]->M_V[10].V[8],MAT[8]->M_V[10].V[9],MAT[8]->M_V[10].V[10],MAT[8]->M_V[10].V[11],MAT[8]->M_V[10].V[12],MAT[8]->M_V[10].V[13],MAT[8]->M_V[10].V[14],MAT[8]->M_V[10].V[15]);
    
    fprintf(fp_mat8_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[11].V[0],MAT[8]->M_V[11].V[1],MAT[8]->M_V[12].V[2],MAT[8]->M_V[11].V[3],MAT[8]->M_V[11].V[4],MAT[8]->M_V[11].V[5],MAT[8]->M_V[11].V[6],MAT[8]->M_V[11].V[7],MAT[8]->M_V[11].V[8],MAT[8]->M_V[11].V[9],MAT[8]->M_V[11].V[10],MAT[8]->M_V[11].V[11],MAT[8]->M_V[11].V[12],MAT[8]->M_V[11].V[13],MAT[8]->M_V[11].V[14],MAT[8]->M_V[11].V[15]);
    
    fprintf(fp_mat8_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[12].V[0],MAT[8]->M_V[12].V[1],MAT[8]->M_V[13].V[2],MAT[8]->M_V[12].V[3],MAT[8]->M_V[12].V[4],MAT[8]->M_V[12].V[5],MAT[8]->M_V[12].V[6],MAT[8]->M_V[12].V[7],MAT[8]->M_V[12].V[8],MAT[8]->M_V[12].V[9],MAT[8]->M_V[12].V[10],MAT[8]->M_V[12].V[11],MAT[8]->M_V[12].V[12],MAT[8]->M_V[12].V[13],MAT[8]->M_V[12].V[14],MAT[8]->M_V[12].V[15]);
    
    fprintf(fp_mat8_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[13].V[0],MAT[8]->M_V[13].V[1],MAT[8]->M_V[14].V[2],MAT[8]->M_V[13].V[3],MAT[8]->M_V[13].V[4],MAT[8]->M_V[13].V[5],MAT[8]->M_V[13].V[6],MAT[8]->M_V[13].V[7],MAT[8]->M_V[13].V[8],MAT[8]->M_V[13].V[9],MAT[8]->M_V[13].V[10],MAT[8]->M_V[13].V[11],MAT[8]->M_V[13].V[12],MAT[8]->M_V[13].V[13],MAT[8]->M_V[13].V[14],MAT[8]->M_V[13].V[15]);
    
    fprintf(fp_mat8_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[8]->M_V[14].V[0],MAT[8]->M_V[14].V[1],MAT[8]->M_V[15].V[2],MAT[8]->M_V[14].V[3],MAT[8]->M_V[14].V[4],MAT[8]->M_V[14].V[5],MAT[8]->M_V[14].V[6],MAT[8]->M_V[14].V[7],MAT[8]->M_V[14].V[8],MAT[8]->M_V[14].V[9],MAT[8]->M_V[14].V[10],MAT[8]->M_V[14].V[11],MAT[8]->M_V[14].V[12],MAT[8]->M_V[14].V[13],MAT[8]->M_V[14].V[14],MAT[8]->M_V[14].V[15]);
    */
    
    
   /* fprintf(fp_mat9_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[0].V[0],MAT[9]->M_V[0].V[1],MAT[9]->M_V[0].V[2],MAT[9]->M_V[0].V[3],MAT[9]->M_V[0].V[4],MAT[9]->M_V[0].V[5],MAT[9]->M_V[0].V[6],MAT[9]->M_V[0].V[7],MAT[9]->M_V[0].V[8],MAT[9]->M_V[0].V[9],MAT[9]->M_V[0].V[10],MAT[9]->M_V[0].V[11],MAT[9]->M_V[0].V[12],MAT[9]->M_V[0].V[13],MAT[9]->M_V[0].V[14],MAT[9]->M_V[0].V[15]);
    
    fprintf(fp_mat9_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[1].V[0],MAT[9]->M_V[1].V[1],MAT[9]->M_V[1].V[2],MAT[9]->M_V[1].V[3],MAT[9]->M_V[1].V[4],MAT[9]->M_V[1].V[5],MAT[9]->M_V[1].V[6],MAT[9]->M_V[1].V[7],MAT[9]->M_V[1].V[8],MAT[9]->M_V[1].V[9],MAT[9]->M_V[1].V[10],MAT[9]->M_V[1].V[11],MAT[9]->M_V[1].V[12],MAT[9]->M_V[1].V[13],MAT[9]->M_V[1].V[14],MAT[9]->M_V[1].V[15]);
    
    fprintf(fp_mat9_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[2].V[0],MAT[9]->M_V[2].V[1],MAT[9]->M_V[2].V[2],MAT[9]->M_V[2].V[3],MAT[9]->M_V[2].V[4],MAT[9]->M_V[2].V[5],MAT[9]->M_V[2].V[6],MAT[9]->M_V[2].V[7],MAT[9]->M_V[2].V[8],MAT[9]->M_V[2].V[9],MAT[9]->M_V[2].V[10],MAT[9]->M_V[2].V[11],MAT[9]->M_V[2].V[12],MAT[9]->M_V[2].V[13],MAT[9]->M_V[2].V[14],MAT[9]->M_V[2].V[15]);
    
    fprintf(fp_mat9_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[3].V[0],MAT[9]->M_V[3].V[1],MAT[9]->M_V[3].V[2],MAT[9]->M_V[3].V[3],MAT[9]->M_V[3].V[4],MAT[9]->M_V[3].V[5],MAT[9]->M_V[3].V[6],MAT[9]->M_V[3].V[7],MAT[9]->M_V[3].V[8],MAT[9]->M_V[3].V[9],MAT[9]->M_V[3].V[10],MAT[9]->M_V[3].V[11],MAT[9]->M_V[3].V[12],MAT[9]->M_V[3].V[13],MAT[9]->M_V[3].V[14],MAT[9]->M_V[3].V[15]);    
    
    fprintf(fp_mat9_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[4].V[0],MAT[9]->M_V[4].V[1],MAT[9]->M_V[4].V[2],MAT[9]->M_V[4].V[3],MAT[9]->M_V[4].V[4],MAT[9]->M_V[4].V[5],MAT[9]->M_V[4].V[6],MAT[9]->M_V[4].V[7],MAT[9]->M_V[4].V[8],MAT[9]->M_V[4].V[9],MAT[9]->M_V[4].V[10],MAT[9]->M_V[4].V[11],MAT[9]->M_V[4].V[12],MAT[9]->M_V[4].V[13],MAT[9]->M_V[4].V[14],MAT[9]->M_V[4].V[15]);
    
    fprintf(fp_mat9_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[5].V[0],MAT[9]->M_V[5].V[1],MAT[9]->M_V[5].V[2],MAT[9]->M_V[5].V[3],MAT[9]->M_V[5].V[4],MAT[9]->M_V[5].V[5],MAT[9]->M_V[5].V[6],MAT[9]->M_V[5].V[7],MAT[9]->M_V[5].V[8],MAT[9]->M_V[5].V[9],MAT[9]->M_V[5].V[10],MAT[9]->M_V[5].V[11],MAT[9]->M_V[5].V[12],MAT[9]->M_V[5].V[13],MAT[9]->M_V[5].V[14],MAT[9]->M_V[5].V[15]);
    
    fprintf(fp_mat9_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[6].V[0],MAT[9]->M_V[6].V[1],MAT[9]->M_V[6].V[2],MAT[9]->M_V[6].V[3],MAT[9]->M_V[6].V[4],MAT[9]->M_V[6].V[5],MAT[9]->M_V[6].V[6],MAT[9]->M_V[6].V[7],MAT[9]->M_V[6].V[8],MAT[9]->M_V[6].V[9],MAT[9]->M_V[6].V[10],MAT[9]->M_V[6].V[11],MAT[9]->M_V[6].V[12],MAT[9]->M_V[6].V[13],MAT[9]->M_V[6].V[14],MAT[9]->M_V[6].V[15]);
    
    fprintf(fp_mat9_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[7].V[0],MAT[9]->M_V[7].V[1],MAT[9]->M_V[7].V[2],MAT[9]->M_V[7].V[3],MAT[9]->M_V[7].V[4],MAT[9]->M_V[7].V[5],MAT[9]->M_V[7].V[6],MAT[9]->M_V[7].V[7],MAT[9]->M_V[7].V[8],MAT[9]->M_V[7].V[9],MAT[9]->M_V[7].V[10],MAT[9]->M_V[7].V[11],MAT[9]->M_V[7].V[12],MAT[9]->M_V[7].V[13],MAT[9]->M_V[7].V[14],MAT[9]->M_V[0].V[15]);
    
    fprintf(fp_mat9_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[8].V[0],MAT[9]->M_V[8].V[1],MAT[9]->M_V[8].V[2],MAT[9]->M_V[8].V[3],MAT[9]->M_V[8].V[4],MAT[9]->M_V[8].V[5],MAT[9]->M_V[8].V[6],MAT[9]->M_V[8].V[7],MAT[9]->M_V[8].V[8],MAT[9]->M_V[8].V[9],MAT[9]->M_V[8].V[10],MAT[9]->M_V[8].V[11],MAT[9]->M_V[8].V[12],MAT[9]->M_V[8].V[13],MAT[9]->M_V[8].V[14],MAT[9]->M_V[8].V[15]);
    
    fprintf(fp_mat9_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[9].V[0],MAT[9]->M_V[9].V[1],MAT[9]->M_V[9].V[2],MAT[9]->M_V[9].V[3],MAT[9]->M_V[9].V[4],MAT[9]->M_V[9].V[5],MAT[9]->M_V[9].V[6],MAT[9]->M_V[9].V[7],MAT[9]->M_V[9].V[8],MAT[9]->M_V[9].V[9],MAT[9]->M_V[9].V[10],MAT[9]->M_V[9].V[11],MAT[9]->M_V[9].V[12],MAT[9]->M_V[9].V[13],MAT[9]->M_V[9].V[14],MAT[9]->M_V[9].V[15]);
    
    fprintf(fp_mat9_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[10].V[0],MAT[9]->M_V[10].V[1],MAT[9]->M_V[10].V[2],MAT[9]->M_V[10].V[3],MAT[9]->M_V[10].V[4],MAT[9]->M_V[10].V[5],MAT[9]->M_V[10].V[6],MAT[9]->M_V[10].V[7],MAT[9]->M_V[10].V[8],MAT[9]->M_V[10].V[9],MAT[9]->M_V[10].V[10],MAT[9]->M_V[10].V[11],MAT[9]->M_V[10].V[12],MAT[9]->M_V[10].V[13],MAT[9]->M_V[10].V[14],MAT[9]->M_V[10].V[15]);
    
    fprintf(fp_mat9_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[11].V[0],MAT[9]->M_V[11].V[1],MAT[9]->M_V[12].V[2],MAT[9]->M_V[11].V[3],MAT[9]->M_V[11].V[4],MAT[9]->M_V[11].V[5],MAT[9]->M_V[11].V[6],MAT[9]->M_V[11].V[7],MAT[9]->M_V[11].V[8],MAT[9]->M_V[11].V[9],MAT[9]->M_V[11].V[10],MAT[9]->M_V[11].V[11],MAT[9]->M_V[11].V[12],MAT[9]->M_V[11].V[13],MAT[9]->M_V[11].V[14],MAT[9]->M_V[11].V[15]);
    
    fprintf(fp_mat9_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[12].V[0],MAT[9]->M_V[12].V[1],MAT[9]->M_V[13].V[2],MAT[9]->M_V[12].V[3],MAT[9]->M_V[12].V[4],MAT[9]->M_V[12].V[5],MAT[9]->M_V[12].V[6],MAT[9]->M_V[12].V[7],MAT[9]->M_V[12].V[8],MAT[9]->M_V[12].V[9],MAT[9]->M_V[12].V[10],MAT[9]->M_V[12].V[11],MAT[9]->M_V[12].V[12],MAT[9]->M_V[12].V[13],MAT[9]->M_V[12].V[14],MAT[9]->M_V[12].V[15]);
    
    fprintf(fp_mat9_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[13].V[0],MAT[9]->M_V[13].V[1],MAT[9]->M_V[14].V[2],MAT[9]->M_V[13].V[3],MAT[9]->M_V[13].V[4],MAT[9]->M_V[13].V[5],MAT[9]->M_V[13].V[6],MAT[9]->M_V[13].V[7],MAT[9]->M_V[13].V[8],MAT[9]->M_V[13].V[9],MAT[9]->M_V[13].V[10],MAT[9]->M_V[13].V[11],MAT[9]->M_V[13].V[12],MAT[9]->M_V[13].V[13],MAT[9]->M_V[13].V[14],MAT[9]->M_V[13].V[15]);
    
    fprintf(fp_mat9_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[14].V[0],MAT[9]->M_V[14].V[1],MAT[9]->M_V[15].V[2],MAT[9]->M_V[14].V[3],MAT[9]->M_V[14].V[4],MAT[9]->M_V[14].V[5],MAT[9]->M_V[14].V[6],MAT[9]->M_V[14].V[7],MAT[9]->M_V[14].V[8],MAT[9]->M_V[14].V[9],MAT[9]->M_V[14].V[10],MAT[9]->M_V[14].V[11],MAT[9]->M_V[14].V[12],MAT[9]->M_V[14].V[13],MAT[9]->M_V[14].V[14],MAT[9]->M_V[14].V[15]);
    
    fprintf(fp_mat9_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[9]->M_V[15].V[0],MAT[9]->M_V[15].V[1],MAT[9]->M_V[16].V[2],MAT[9]->M_V[15].V[3],MAT[9]->M_V[15].V[4],MAT[9]->M_V[15].V[5],MAT[9]->M_V[15].V[6],MAT[9]->M_V[15].V[7],MAT[9]->M_V[15].V[8],MAT[9]->M_V[15].V[9],MAT[9]->M_V[15].V[10],MAT[9]->M_V[15].V[11],MAT[9]->M_V[15].V[12],MAT[9]->M_V[15].V[13],MAT[9]->M_V[15].V[14],MAT[9]->M_V[15].V[15]);
    
    
    fprintf(fp_mat10_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[0].V[0],MAT[10]->M_V[0].V[1],MAT[10]->M_V[0].V[2],MAT[10]->M_V[0].V[3],MAT[10]->M_V[0].V[4],MAT[10]->M_V[0].V[5],MAT[10]->M_V[0].V[6],MAT[10]->M_V[0].V[7],MAT[10]->M_V[0].V[8],MAT[10]->M_V[0].V[9],MAT[10]->M_V[0].V[10],MAT[10]->M_V[0].V[11],MAT[10]->M_V[0].V[12],MAT[10]->M_V[0].V[13],MAT[10]->M_V[0].V[14],MAT[10]->M_V[0].V[15]);
    
    fprintf(fp_mat10_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[1].V[0],MAT[10]->M_V[1].V[1],MAT[10]->M_V[1].V[2],MAT[10]->M_V[1].V[3],MAT[10]->M_V[1].V[4],MAT[10]->M_V[1].V[5],MAT[10]->M_V[1].V[6],MAT[10]->M_V[1].V[7],MAT[10]->M_V[1].V[8],MAT[10]->M_V[1].V[9],MAT[10]->M_V[1].V[10],MAT[10]->M_V[1].V[11],MAT[10]->M_V[1].V[12],MAT[10]->M_V[1].V[13],MAT[10]->M_V[1].V[14],MAT[10]->M_V[1].V[15]);
    
    fprintf(fp_mat10_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[2].V[0],MAT[10]->M_V[2].V[1],MAT[10]->M_V[2].V[2],MAT[10]->M_V[2].V[3],MAT[10]->M_V[2].V[4],MAT[10]->M_V[2].V[5],MAT[10]->M_V[2].V[6],MAT[10]->M_V[2].V[7],MAT[10]->M_V[2].V[8],MAT[10]->M_V[2].V[9],MAT[10]->M_V[2].V[10],MAT[10]->M_V[2].V[11],MAT[10]->M_V[2].V[12],MAT[10]->M_V[2].V[13],MAT[10]->M_V[2].V[14],MAT[10]->M_V[2].V[15]);
    
    fprintf(fp_mat10_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[3].V[0],MAT[10]->M_V[3].V[1],MAT[10]->M_V[3].V[2],MAT[10]->M_V[3].V[3],MAT[10]->M_V[3].V[4],MAT[10]->M_V[3].V[5],MAT[10]->M_V[3].V[6],MAT[10]->M_V[3].V[7],MAT[10]->M_V[3].V[8],MAT[10]->M_V[3].V[9],MAT[10]->M_V[3].V[10],MAT[10]->M_V[3].V[11],MAT[10]->M_V[3].V[12],MAT[10]->M_V[3].V[13],MAT[10]->M_V[3].V[14],MAT[10]->M_V[3].V[15]);    
    
    fprintf(fp_mat10_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[4].V[0],MAT[10]->M_V[4].V[1],MAT[10]->M_V[4].V[2],MAT[10]->M_V[4].V[3],MAT[10]->M_V[4].V[4],MAT[10]->M_V[4].V[5],MAT[10]->M_V[4].V[6],MAT[10]->M_V[4].V[7],MAT[10]->M_V[4].V[8],MAT[10]->M_V[4].V[9],MAT[10]->M_V[4].V[10],MAT[10]->M_V[4].V[11],MAT[10]->M_V[4].V[12],MAT[10]->M_V[4].V[13],MAT[10]->M_V[4].V[14],MAT[10]->M_V[4].V[15]);
    
    fprintf(fp_mat10_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[5].V[0],MAT[10]->M_V[5].V[1],MAT[10]->M_V[5].V[2],MAT[10]->M_V[5].V[3],MAT[10]->M_V[5].V[4],MAT[10]->M_V[5].V[5],MAT[10]->M_V[5].V[6],MAT[10]->M_V[5].V[7],MAT[10]->M_V[5].V[8],MAT[10]->M_V[5].V[9],MAT[10]->M_V[5].V[10],MAT[10]->M_V[5].V[11],MAT[10]->M_V[5].V[12],MAT[10]->M_V[5].V[13],MAT[10]->M_V[5].V[14],MAT[10]->M_V[5].V[15]);
    
    fprintf(fp_mat10_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[6].V[0],MAT[10]->M_V[6].V[1],MAT[10]->M_V[6].V[2],MAT[10]->M_V[6].V[3],MAT[10]->M_V[6].V[4],MAT[10]->M_V[6].V[5],MAT[10]->M_V[6].V[6],MAT[10]->M_V[6].V[7],MAT[10]->M_V[6].V[8],MAT[10]->M_V[6].V[9],MAT[10]->M_V[6].V[10],MAT[10]->M_V[6].V[11],MAT[10]->M_V[6].V[12],MAT[10]->M_V[6].V[13],MAT[10]->M_V[6].V[14],MAT[10]->M_V[6].V[15]);
    
    fprintf(fp_mat10_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[7].V[0],MAT[10]->M_V[7].V[1],MAT[10]->M_V[7].V[2],MAT[10]->M_V[7].V[3],MAT[10]->M_V[7].V[4],MAT[10]->M_V[7].V[5],MAT[10]->M_V[7].V[6],MAT[10]->M_V[7].V[7],MAT[10]->M_V[7].V[8],MAT[10]->M_V[7].V[9],MAT[10]->M_V[7].V[10],MAT[10]->M_V[7].V[11],MAT[10]->M_V[7].V[12],MAT[10]->M_V[7].V[13],MAT[10]->M_V[7].V[14],MAT[10]->M_V[0].V[15]);
    
    fprintf(fp_mat10_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[8].V[0],MAT[10]->M_V[8].V[1],MAT[10]->M_V[8].V[2],MAT[10]->M_V[8].V[3],MAT[10]->M_V[8].V[4],MAT[10]->M_V[8].V[5],MAT[10]->M_V[8].V[6],MAT[10]->M_V[8].V[7],MAT[10]->M_V[8].V[8],MAT[10]->M_V[8].V[9],MAT[10]->M_V[8].V[10],MAT[10]->M_V[8].V[11],MAT[10]->M_V[8].V[12],MAT[10]->M_V[8].V[13],MAT[10]->M_V[8].V[14],MAT[10]->M_V[8].V[15]);
    
    fprintf(fp_mat10_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[9].V[0],MAT[10]->M_V[9].V[1],MAT[10]->M_V[9].V[2],MAT[10]->M_V[9].V[3],MAT[10]->M_V[9].V[4],MAT[10]->M_V[9].V[5],MAT[10]->M_V[9].V[6],MAT[10]->M_V[9].V[7],MAT[10]->M_V[9].V[8],MAT[10]->M_V[9].V[9],MAT[10]->M_V[9].V[10],MAT[10]->M_V[9].V[11],MAT[10]->M_V[9].V[12],MAT[10]->M_V[9].V[13],MAT[10]->M_V[9].V[14],MAT[10]->M_V[9].V[15]);
    
    fprintf(fp_mat10_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[10].V[0],MAT[10]->M_V[10].V[1],MAT[10]->M_V[10].V[2],MAT[10]->M_V[10].V[3],MAT[10]->M_V[10].V[4],MAT[10]->M_V[10].V[5],MAT[10]->M_V[10].V[6],MAT[10]->M_V[10].V[7],MAT[10]->M_V[10].V[8],MAT[10]->M_V[10].V[9],MAT[10]->M_V[10].V[10],MAT[10]->M_V[10].V[11],MAT[10]->M_V[10].V[12],MAT[10]->M_V[10].V[13],MAT[10]->M_V[10].V[14],MAT[10]->M_V[10].V[15]);
    
    fprintf(fp_mat10_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[11].V[0],MAT[10]->M_V[11].V[1],MAT[10]->M_V[12].V[2],MAT[10]->M_V[11].V[3],MAT[10]->M_V[11].V[4],MAT[10]->M_V[11].V[5],MAT[10]->M_V[11].V[6],MAT[10]->M_V[11].V[7],MAT[10]->M_V[11].V[8],MAT[10]->M_V[11].V[9],MAT[10]->M_V[11].V[10],MAT[10]->M_V[11].V[11],MAT[10]->M_V[11].V[12],MAT[10]->M_V[11].V[13],MAT[10]->M_V[11].V[14],MAT[10]->M_V[11].V[15]);
    
    fprintf(fp_mat10_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[12].V[0],MAT[10]->M_V[12].V[1],MAT[10]->M_V[13].V[2],MAT[10]->M_V[12].V[3],MAT[10]->M_V[12].V[4],MAT[10]->M_V[12].V[5],MAT[10]->M_V[12].V[6],MAT[10]->M_V[12].V[7],MAT[10]->M_V[12].V[8],MAT[10]->M_V[12].V[9],MAT[10]->M_V[12].V[10],MAT[10]->M_V[12].V[11],MAT[10]->M_V[12].V[12],MAT[10]->M_V[12].V[13],MAT[10]->M_V[12].V[14],MAT[10]->M_V[12].V[15]);
    
    fprintf(fp_mat10_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[13].V[0],MAT[10]->M_V[13].V[1],MAT[10]->M_V[14].V[2],MAT[10]->M_V[13].V[3],MAT[10]->M_V[13].V[4],MAT[10]->M_V[13].V[5],MAT[10]->M_V[13].V[6],MAT[10]->M_V[13].V[7],MAT[10]->M_V[13].V[8],MAT[10]->M_V[13].V[9],MAT[10]->M_V[13].V[10],MAT[10]->M_V[13].V[11],MAT[10]->M_V[13].V[12],MAT[10]->M_V[13].V[13],MAT[10]->M_V[13].V[14],MAT[10]->M_V[13].V[15]);
    
    fprintf(fp_mat10_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[14].V[0],MAT[10]->M_V[14].V[1],MAT[10]->M_V[15].V[2],MAT[10]->M_V[14].V[3],MAT[10]->M_V[14].V[4],MAT[10]->M_V[14].V[5],MAT[10]->M_V[14].V[6],MAT[10]->M_V[14].V[7],MAT[10]->M_V[14].V[8],MAT[10]->M_V[14].V[9],MAT[10]->M_V[14].V[10],MAT[10]->M_V[14].V[11],MAT[10]->M_V[14].V[12],MAT[10]->M_V[14].V[13],MAT[10]->M_V[14].V[14],MAT[10]->M_V[14].V[15]);
    
    fprintf(fp_mat10_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[10]->M_V[15].V[0],MAT[10]->M_V[15].V[1],MAT[10]->M_V[16].V[2],MAT[10]->M_V[15].V[3],MAT[10]->M_V[15].V[4],MAT[10]->M_V[15].V[5],MAT[10]->M_V[15].V[6],MAT[10]->M_V[15].V[7],MAT[10]->M_V[15].V[8],MAT[10]->M_V[15].V[9],MAT[10]->M_V[15].V[10],MAT[10]->M_V[15].V[11],MAT[10]->M_V[15].V[12],MAT[10]->M_V[15].V[13],MAT[10]->M_V[15].V[14],MAT[10]->M_V[15].V[15]);
    
    
    fprintf(fp_mat11_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[0].V[0],MAT[11]->M_V[0].V[1],MAT[11]->M_V[0].V[2],MAT[11]->M_V[0].V[3],MAT[11]->M_V[0].V[4],MAT[11]->M_V[0].V[5],MAT[11]->M_V[0].V[6],MAT[11]->M_V[0].V[7],MAT[11]->M_V[0].V[8],MAT[11]->M_V[0].V[9],MAT[11]->M_V[0].V[10],MAT[11]->M_V[0].V[11],MAT[11]->M_V[0].V[12],MAT[11]->M_V[0].V[13],MAT[11]->M_V[0].V[14],MAT[11]->M_V[0].V[15]);
    
    fprintf(fp_mat11_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[1].V[0],MAT[11]->M_V[1].V[1],MAT[11]->M_V[1].V[2],MAT[11]->M_V[1].V[3],MAT[11]->M_V[1].V[4],MAT[11]->M_V[1].V[5],MAT[11]->M_V[1].V[6],MAT[11]->M_V[1].V[7],MAT[11]->M_V[1].V[8],MAT[11]->M_V[1].V[9],MAT[11]->M_V[1].V[10],MAT[11]->M_V[1].V[11],MAT[11]->M_V[1].V[12],MAT[11]->M_V[1].V[13],MAT[11]->M_V[1].V[14],MAT[11]->M_V[1].V[15]);
    
    fprintf(fp_mat11_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[2].V[0],MAT[11]->M_V[2].V[1],MAT[11]->M_V[2].V[2],MAT[11]->M_V[2].V[3],MAT[11]->M_V[2].V[4],MAT[11]->M_V[2].V[5],MAT[11]->M_V[2].V[6],MAT[11]->M_V[2].V[7],MAT[11]->M_V[2].V[8],MAT[11]->M_V[2].V[9],MAT[11]->M_V[2].V[10],MAT[11]->M_V[2].V[11],MAT[11]->M_V[2].V[12],MAT[11]->M_V[2].V[13],MAT[11]->M_V[2].V[14],MAT[11]->M_V[2].V[15]);
    
    fprintf(fp_mat11_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[3].V[0],MAT[11]->M_V[3].V[1],MAT[11]->M_V[3].V[2],MAT[11]->M_V[3].V[3],MAT[11]->M_V[3].V[4],MAT[11]->M_V[3].V[5],MAT[11]->M_V[3].V[6],MAT[11]->M_V[3].V[7],MAT[11]->M_V[3].V[8],MAT[11]->M_V[3].V[9],MAT[11]->M_V[3].V[10],MAT[11]->M_V[3].V[11],MAT[11]->M_V[3].V[12],MAT[11]->M_V[3].V[13],MAT[11]->M_V[3].V[14],MAT[11]->M_V[3].V[15]);    
    
    fprintf(fp_mat11_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[4].V[0],MAT[11]->M_V[4].V[1],MAT[11]->M_V[4].V[2],MAT[11]->M_V[4].V[3],MAT[11]->M_V[4].V[4],MAT[11]->M_V[4].V[5],MAT[11]->M_V[4].V[6],MAT[11]->M_V[4].V[7],MAT[11]->M_V[4].V[8],MAT[11]->M_V[4].V[9],MAT[11]->M_V[4].V[10],MAT[11]->M_V[4].V[11],MAT[11]->M_V[4].V[12],MAT[11]->M_V[4].V[13],MAT[11]->M_V[4].V[14],MAT[11]->M_V[4].V[15]);
    
    fprintf(fp_mat11_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[5].V[0],MAT[11]->M_V[5].V[1],MAT[11]->M_V[5].V[2],MAT[11]->M_V[5].V[3],MAT[11]->M_V[5].V[4],MAT[11]->M_V[5].V[5],MAT[11]->M_V[5].V[6],MAT[11]->M_V[5].V[7],MAT[11]->M_V[5].V[8],MAT[11]->M_V[5].V[9],MAT[11]->M_V[5].V[10],MAT[11]->M_V[5].V[11],MAT[11]->M_V[5].V[12],MAT[11]->M_V[5].V[13],MAT[11]->M_V[5].V[14],MAT[11]->M_V[5].V[15]);
    
    fprintf(fp_mat11_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[6].V[0],MAT[11]->M_V[6].V[1],MAT[11]->M_V[6].V[2],MAT[11]->M_V[6].V[3],MAT[11]->M_V[6].V[4],MAT[11]->M_V[6].V[5],MAT[11]->M_V[6].V[6],MAT[11]->M_V[6].V[7],MAT[11]->M_V[6].V[8],MAT[11]->M_V[6].V[9],MAT[11]->M_V[6].V[10],MAT[11]->M_V[6].V[11],MAT[11]->M_V[6].V[12],MAT[11]->M_V[6].V[13],MAT[11]->M_V[6].V[14],MAT[11]->M_V[6].V[15]);
    
    fprintf(fp_mat11_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[7].V[0],MAT[11]->M_V[7].V[1],MAT[11]->M_V[7].V[2],MAT[11]->M_V[7].V[3],MAT[11]->M_V[7].V[4],MAT[11]->M_V[7].V[5],MAT[11]->M_V[7].V[6],MAT[11]->M_V[7].V[7],MAT[11]->M_V[7].V[8],MAT[11]->M_V[7].V[9],MAT[11]->M_V[7].V[10],MAT[11]->M_V[7].V[11],MAT[11]->M_V[7].V[12],MAT[11]->M_V[7].V[13],MAT[11]->M_V[7].V[14],MAT[11]->M_V[0].V[15]);
    
    fprintf(fp_mat11_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[8].V[0],MAT[11]->M_V[8].V[1],MAT[11]->M_V[8].V[2],MAT[11]->M_V[8].V[3],MAT[11]->M_V[8].V[4],MAT[11]->M_V[8].V[5],MAT[11]->M_V[8].V[6],MAT[11]->M_V[8].V[7],MAT[11]->M_V[8].V[8],MAT[11]->M_V[8].V[9],MAT[11]->M_V[8].V[10],MAT[11]->M_V[8].V[11],MAT[11]->M_V[8].V[12],MAT[11]->M_V[8].V[13],MAT[11]->M_V[8].V[14],MAT[11]->M_V[8].V[15]);
    
    fprintf(fp_mat11_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[9].V[0],MAT[11]->M_V[9].V[1],MAT[11]->M_V[9].V[2],MAT[11]->M_V[9].V[3],MAT[11]->M_V[9].V[4],MAT[11]->M_V[9].V[5],MAT[11]->M_V[9].V[6],MAT[11]->M_V[9].V[7],MAT[11]->M_V[9].V[8],MAT[11]->M_V[9].V[9],MAT[11]->M_V[9].V[10],MAT[11]->M_V[9].V[11],MAT[11]->M_V[9].V[12],MAT[11]->M_V[9].V[13],MAT[11]->M_V[9].V[14],MAT[11]->M_V[9].V[15]);
    
    fprintf(fp_mat11_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[10].V[0],MAT[11]->M_V[10].V[1],MAT[11]->M_V[10].V[2],MAT[11]->M_V[10].V[3],MAT[11]->M_V[10].V[4],MAT[11]->M_V[10].V[5],MAT[11]->M_V[10].V[6],MAT[11]->M_V[10].V[7],MAT[11]->M_V[10].V[8],MAT[11]->M_V[10].V[9],MAT[11]->M_V[10].V[10],MAT[11]->M_V[10].V[11],MAT[11]->M_V[10].V[12],MAT[11]->M_V[10].V[13],MAT[11]->M_V[10].V[14],MAT[11]->M_V[10].V[15]);
    
    fprintf(fp_mat11_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[11].V[0],MAT[11]->M_V[11].V[1],MAT[11]->M_V[12].V[2],MAT[11]->M_V[11].V[3],MAT[11]->M_V[11].V[4],MAT[11]->M_V[11].V[5],MAT[11]->M_V[11].V[6],MAT[11]->M_V[11].V[7],MAT[11]->M_V[11].V[8],MAT[11]->M_V[11].V[9],MAT[11]->M_V[11].V[10],MAT[11]->M_V[11].V[11],MAT[11]->M_V[11].V[12],MAT[11]->M_V[11].V[13],MAT[11]->M_V[11].V[14],MAT[11]->M_V[11].V[15]);
    
    fprintf(fp_mat11_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[12].V[0],MAT[11]->M_V[12].V[1],MAT[11]->M_V[13].V[2],MAT[11]->M_V[12].V[3],MAT[11]->M_V[12].V[4],MAT[11]->M_V[12].V[5],MAT[11]->M_V[12].V[6],MAT[11]->M_V[12].V[7],MAT[11]->M_V[12].V[8],MAT[11]->M_V[12].V[9],MAT[11]->M_V[12].V[10],MAT[11]->M_V[12].V[11],MAT[11]->M_V[12].V[12],MAT[11]->M_V[12].V[13],MAT[11]->M_V[12].V[14],MAT[11]->M_V[12].V[15]);
    
    fprintf(fp_mat11_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[13].V[0],MAT[11]->M_V[13].V[1],MAT[11]->M_V[14].V[2],MAT[11]->M_V[13].V[3],MAT[11]->M_V[13].V[4],MAT[11]->M_V[13].V[5],MAT[11]->M_V[13].V[6],MAT[11]->M_V[13].V[7],MAT[11]->M_V[13].V[8],MAT[11]->M_V[13].V[9],MAT[11]->M_V[13].V[10],MAT[11]->M_V[13].V[11],MAT[11]->M_V[13].V[12],MAT[11]->M_V[13].V[13],MAT[11]->M_V[13].V[14],MAT[11]->M_V[13].V[15]);
    
    fprintf(fp_mat11_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[14].V[0],MAT[11]->M_V[14].V[1],MAT[11]->M_V[15].V[2],MAT[11]->M_V[14].V[3],MAT[11]->M_V[14].V[4],MAT[11]->M_V[14].V[5],MAT[11]->M_V[14].V[6],MAT[11]->M_V[14].V[7],MAT[11]->M_V[14].V[8],MAT[11]->M_V[14].V[9],MAT[11]->M_V[14].V[10],MAT[11]->M_V[14].V[11],MAT[11]->M_V[14].V[12],MAT[11]->M_V[14].V[13],MAT[11]->M_V[14].V[14],MAT[11]->M_V[14].V[15]);
    
    fprintf(fp_mat11_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[11]->M_V[15].V[0],MAT[11]->M_V[15].V[1],MAT[11]->M_V[16].V[2],MAT[11]->M_V[15].V[3],MAT[11]->M_V[15].V[4],MAT[11]->M_V[15].V[5],MAT[11]->M_V[15].V[6],MAT[11]->M_V[15].V[7],MAT[11]->M_V[15].V[8],MAT[11]->M_V[15].V[9],MAT[11]->M_V[15].V[10],MAT[11]->M_V[15].V[11],MAT[11]->M_V[15].V[12],MAT[11]->M_V[15].V[13],MAT[11]->M_V[15].V[14],MAT[11]->M_V[15].V[15]);
    
    
    fprintf(fp_mat12_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[0].V[0],MAT[12]->M_V[0].V[1],MAT[12]->M_V[0].V[2],MAT[12]->M_V[0].V[3],MAT[12]->M_V[0].V[4],MAT[12]->M_V[0].V[5],MAT[12]->M_V[0].V[6],MAT[12]->M_V[0].V[7],MAT[12]->M_V[0].V[8],MAT[12]->M_V[0].V[9],MAT[12]->M_V[0].V[10],MAT[12]->M_V[0].V[11],MAT[12]->M_V[0].V[12],MAT[12]->M_V[0].V[13],MAT[12]->M_V[0].V[14],MAT[12]->M_V[0].V[15]);
    
    fprintf(fp_mat12_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[1].V[0],MAT[12]->M_V[1].V[1],MAT[12]->M_V[1].V[2],MAT[12]->M_V[1].V[3],MAT[12]->M_V[1].V[4],MAT[12]->M_V[1].V[5],MAT[12]->M_V[1].V[6],MAT[12]->M_V[1].V[7],MAT[12]->M_V[1].V[8],MAT[12]->M_V[1].V[9],MAT[12]->M_V[1].V[10],MAT[12]->M_V[1].V[11],MAT[12]->M_V[1].V[12],MAT[12]->M_V[1].V[13],MAT[12]->M_V[1].V[14],MAT[12]->M_V[1].V[15]);
    
    fprintf(fp_mat12_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[2].V[0],MAT[12]->M_V[2].V[1],MAT[12]->M_V[2].V[2],MAT[12]->M_V[2].V[3],MAT[12]->M_V[2].V[4],MAT[12]->M_V[2].V[5],MAT[12]->M_V[2].V[6],MAT[12]->M_V[2].V[7],MAT[12]->M_V[2].V[8],MAT[12]->M_V[2].V[9],MAT[12]->M_V[2].V[10],MAT[12]->M_V[2].V[11],MAT[12]->M_V[2].V[12],MAT[12]->M_V[2].V[13],MAT[12]->M_V[2].V[14],MAT[12]->M_V[2].V[15]);
    
    fprintf(fp_mat12_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[3].V[0],MAT[12]->M_V[3].V[1],MAT[12]->M_V[3].V[2],MAT[12]->M_V[3].V[3],MAT[12]->M_V[3].V[4],MAT[12]->M_V[3].V[5],MAT[12]->M_V[3].V[6],MAT[12]->M_V[3].V[7],MAT[12]->M_V[3].V[8],MAT[12]->M_V[3].V[9],MAT[12]->M_V[3].V[10],MAT[12]->M_V[3].V[11],MAT[12]->M_V[3].V[12],MAT[12]->M_V[3].V[13],MAT[12]->M_V[3].V[14],MAT[12]->M_V[3].V[15]);    
    
    fprintf(fp_mat12_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[4].V[0],MAT[12]->M_V[4].V[1],MAT[12]->M_V[4].V[2],MAT[12]->M_V[4].V[3],MAT[12]->M_V[4].V[4],MAT[12]->M_V[4].V[5],MAT[12]->M_V[4].V[6],MAT[12]->M_V[4].V[7],MAT[12]->M_V[4].V[8],MAT[12]->M_V[4].V[9],MAT[12]->M_V[4].V[10],MAT[12]->M_V[4].V[11],MAT[12]->M_V[4].V[12],MAT[12]->M_V[4].V[13],MAT[12]->M_V[4].V[14],MAT[12]->M_V[4].V[15]);
    
    fprintf(fp_mat12_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[5].V[0],MAT[12]->M_V[5].V[1],MAT[12]->M_V[5].V[2],MAT[12]->M_V[5].V[3],MAT[12]->M_V[5].V[4],MAT[12]->M_V[5].V[5],MAT[12]->M_V[5].V[6],MAT[12]->M_V[5].V[7],MAT[12]->M_V[5].V[8],MAT[12]->M_V[5].V[9],MAT[12]->M_V[5].V[10],MAT[12]->M_V[5].V[11],MAT[12]->M_V[5].V[12],MAT[12]->M_V[5].V[13],MAT[12]->M_V[5].V[14],MAT[12]->M_V[5].V[15]);
    
    fprintf(fp_mat12_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[6].V[0],MAT[12]->M_V[6].V[1],MAT[12]->M_V[6].V[2],MAT[12]->M_V[6].V[3],MAT[12]->M_V[6].V[4],MAT[12]->M_V[6].V[5],MAT[12]->M_V[6].V[6],MAT[12]->M_V[6].V[7],MAT[12]->M_V[6].V[8],MAT[12]->M_V[6].V[9],MAT[12]->M_V[6].V[10],MAT[12]->M_V[6].V[11],MAT[12]->M_V[6].V[12],MAT[12]->M_V[6].V[13],MAT[12]->M_V[6].V[14],MAT[12]->M_V[6].V[15]);
    
    fprintf(fp_mat12_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[7].V[0],MAT[12]->M_V[7].V[1],MAT[12]->M_V[7].V[2],MAT[12]->M_V[7].V[3],MAT[12]->M_V[7].V[4],MAT[12]->M_V[7].V[5],MAT[12]->M_V[7].V[6],MAT[12]->M_V[7].V[7],MAT[12]->M_V[7].V[8],MAT[12]->M_V[7].V[9],MAT[12]->M_V[7].V[10],MAT[12]->M_V[7].V[11],MAT[12]->M_V[7].V[12],MAT[12]->M_V[7].V[13],MAT[12]->M_V[7].V[14],MAT[12]->M_V[0].V[15]);
    
    fprintf(fp_mat12_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[8].V[0],MAT[12]->M_V[8].V[1],MAT[12]->M_V[8].V[2],MAT[12]->M_V[8].V[3],MAT[12]->M_V[8].V[4],MAT[12]->M_V[8].V[5],MAT[12]->M_V[8].V[6],MAT[12]->M_V[8].V[7],MAT[12]->M_V[8].V[8],MAT[12]->M_V[8].V[9],MAT[12]->M_V[8].V[10],MAT[12]->M_V[8].V[11],MAT[12]->M_V[8].V[12],MAT[12]->M_V[8].V[13],MAT[12]->M_V[8].V[14],MAT[12]->M_V[8].V[15]);
    
    fprintf(fp_mat12_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[9].V[0],MAT[12]->M_V[9].V[1],MAT[12]->M_V[9].V[2],MAT[12]->M_V[9].V[3],MAT[12]->M_V[9].V[4],MAT[12]->M_V[9].V[5],MAT[12]->M_V[9].V[6],MAT[12]->M_V[9].V[7],MAT[12]->M_V[9].V[8],MAT[12]->M_V[9].V[9],MAT[12]->M_V[9].V[10],MAT[12]->M_V[9].V[11],MAT[12]->M_V[9].V[12],MAT[12]->M_V[9].V[13],MAT[12]->M_V[9].V[14],MAT[12]->M_V[9].V[15]);
    
    fprintf(fp_mat12_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[10].V[0],MAT[12]->M_V[10].V[1],MAT[12]->M_V[10].V[2],MAT[12]->M_V[10].V[3],MAT[12]->M_V[10].V[4],MAT[12]->M_V[10].V[5],MAT[12]->M_V[10].V[6],MAT[12]->M_V[10].V[7],MAT[12]->M_V[10].V[8],MAT[12]->M_V[10].V[9],MAT[12]->M_V[10].V[10],MAT[12]->M_V[10].V[11],MAT[12]->M_V[10].V[12],MAT[12]->M_V[10].V[13],MAT[12]->M_V[10].V[14],MAT[12]->M_V[10].V[15]);
    
    fprintf(fp_mat12_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[11].V[0],MAT[12]->M_V[11].V[1],MAT[12]->M_V[12].V[2],MAT[12]->M_V[11].V[3],MAT[12]->M_V[11].V[4],MAT[12]->M_V[11].V[5],MAT[12]->M_V[11].V[6],MAT[12]->M_V[11].V[7],MAT[12]->M_V[11].V[8],MAT[12]->M_V[11].V[9],MAT[12]->M_V[11].V[10],MAT[12]->M_V[11].V[11],MAT[12]->M_V[11].V[12],MAT[12]->M_V[11].V[13],MAT[12]->M_V[11].V[14],MAT[12]->M_V[11].V[15]);
    
    fprintf(fp_mat12_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[12].V[0],MAT[12]->M_V[12].V[1],MAT[12]->M_V[13].V[2],MAT[12]->M_V[12].V[3],MAT[12]->M_V[12].V[4],MAT[12]->M_V[12].V[5],MAT[12]->M_V[12].V[6],MAT[12]->M_V[12].V[7],MAT[12]->M_V[12].V[8],MAT[12]->M_V[12].V[9],MAT[12]->M_V[12].V[10],MAT[12]->M_V[12].V[11],MAT[12]->M_V[12].V[12],MAT[12]->M_V[12].V[13],MAT[12]->M_V[12].V[14],MAT[12]->M_V[12].V[15]);
    
    fprintf(fp_mat12_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[13].V[0],MAT[12]->M_V[13].V[1],MAT[12]->M_V[14].V[2],MAT[12]->M_V[13].V[3],MAT[12]->M_V[13].V[4],MAT[12]->M_V[13].V[5],MAT[12]->M_V[13].V[6],MAT[12]->M_V[13].V[7],MAT[12]->M_V[13].V[8],MAT[12]->M_V[13].V[9],MAT[12]->M_V[13].V[10],MAT[12]->M_V[13].V[11],MAT[12]->M_V[13].V[12],MAT[12]->M_V[13].V[13],MAT[12]->M_V[13].V[14],MAT[12]->M_V[13].V[15]);
    
    fprintf(fp_mat12_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[14].V[0],MAT[12]->M_V[14].V[1],MAT[12]->M_V[15].V[2],MAT[12]->M_V[14].V[3],MAT[12]->M_V[14].V[4],MAT[12]->M_V[14].V[5],MAT[12]->M_V[14].V[6],MAT[12]->M_V[14].V[7],MAT[12]->M_V[14].V[8],MAT[12]->M_V[14].V[9],MAT[12]->M_V[14].V[10],MAT[12]->M_V[14].V[11],MAT[12]->M_V[14].V[12],MAT[12]->M_V[14].V[13],MAT[12]->M_V[14].V[14],MAT[12]->M_V[14].V[15]);
    
    fprintf(fp_mat12_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[12]->M_V[15].V[0],MAT[12]->M_V[15].V[1],MAT[12]->M_V[16].V[2],MAT[12]->M_V[15].V[3],MAT[12]->M_V[15].V[4],MAT[12]->M_V[15].V[5],MAT[12]->M_V[15].V[6],MAT[12]->M_V[15].V[7],MAT[12]->M_V[15].V[8],MAT[12]->M_V[15].V[9],MAT[12]->M_V[15].V[10],MAT[12]->M_V[15].V[11],MAT[12]->M_V[15].V[12],MAT[12]->M_V[15].V[13],MAT[12]->M_V[15].V[14],MAT[12]->M_V[15].V[15]);
    
    
    fprintf(fp_mat13_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[0].V[0],MAT[13]->M_V[0].V[1],MAT[13]->M_V[0].V[2],MAT[13]->M_V[0].V[3],MAT[13]->M_V[0].V[4],MAT[13]->M_V[0].V[5],MAT[13]->M_V[0].V[6],MAT[13]->M_V[0].V[7],MAT[13]->M_V[0].V[8],MAT[13]->M_V[0].V[9],MAT[13]->M_V[0].V[10],MAT[13]->M_V[0].V[11],MAT[13]->M_V[0].V[12],MAT[13]->M_V[0].V[13],MAT[13]->M_V[0].V[14],MAT[13]->M_V[0].V[15]);
    
    fprintf(fp_mat13_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[1].V[0],MAT[13]->M_V[1].V[1],MAT[13]->M_V[1].V[2],MAT[13]->M_V[1].V[3],MAT[13]->M_V[1].V[4],MAT[13]->M_V[1].V[5],MAT[13]->M_V[1].V[6],MAT[13]->M_V[1].V[7],MAT[13]->M_V[1].V[8],MAT[13]->M_V[1].V[9],MAT[13]->M_V[1].V[10],MAT[13]->M_V[1].V[11],MAT[13]->M_V[1].V[12],MAT[13]->M_V[1].V[13],MAT[13]->M_V[1].V[14],MAT[13]->M_V[1].V[15]);
    
    fprintf(fp_mat13_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[2].V[0],MAT[13]->M_V[2].V[1],MAT[13]->M_V[2].V[2],MAT[13]->M_V[2].V[3],MAT[13]->M_V[2].V[4],MAT[13]->M_V[2].V[5],MAT[13]->M_V[2].V[6],MAT[13]->M_V[2].V[7],MAT[13]->M_V[2].V[8],MAT[13]->M_V[2].V[9],MAT[13]->M_V[2].V[10],MAT[13]->M_V[2].V[11],MAT[13]->M_V[2].V[12],MAT[13]->M_V[2].V[13],MAT[13]->M_V[2].V[14],MAT[13]->M_V[2].V[15]);
    
    fprintf(fp_mat13_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[3].V[0],MAT[13]->M_V[3].V[1],MAT[13]->M_V[3].V[2],MAT[13]->M_V[3].V[3],MAT[13]->M_V[3].V[4],MAT[13]->M_V[3].V[5],MAT[13]->M_V[3].V[6],MAT[13]->M_V[3].V[7],MAT[13]->M_V[3].V[8],MAT[13]->M_V[3].V[9],MAT[13]->M_V[3].V[10],MAT[13]->M_V[3].V[11],MAT[13]->M_V[3].V[12],MAT[13]->M_V[3].V[13],MAT[13]->M_V[3].V[14],MAT[13]->M_V[3].V[15]);    
    
    fprintf(fp_mat13_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[4].V[0],MAT[13]->M_V[4].V[1],MAT[13]->M_V[4].V[2],MAT[13]->M_V[4].V[3],MAT[13]->M_V[4].V[4],MAT[13]->M_V[4].V[5],MAT[13]->M_V[4].V[6],MAT[13]->M_V[4].V[7],MAT[13]->M_V[4].V[8],MAT[13]->M_V[4].V[9],MAT[13]->M_V[4].V[10],MAT[13]->M_V[4].V[11],MAT[13]->M_V[4].V[12],MAT[13]->M_V[4].V[13],MAT[13]->M_V[4].V[14],MAT[13]->M_V[4].V[15]);
    
    fprintf(fp_mat13_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[5].V[0],MAT[13]->M_V[5].V[1],MAT[13]->M_V[5].V[2],MAT[13]->M_V[5].V[3],MAT[13]->M_V[5].V[4],MAT[13]->M_V[5].V[5],MAT[13]->M_V[5].V[6],MAT[13]->M_V[5].V[7],MAT[13]->M_V[5].V[8],MAT[13]->M_V[5].V[9],MAT[13]->M_V[5].V[10],MAT[13]->M_V[5].V[11],MAT[13]->M_V[5].V[12],MAT[13]->M_V[5].V[13],MAT[13]->M_V[5].V[14],MAT[13]->M_V[5].V[15]);
    
    fprintf(fp_mat13_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[6].V[0],MAT[13]->M_V[6].V[1],MAT[13]->M_V[6].V[2],MAT[13]->M_V[6].V[3],MAT[13]->M_V[6].V[4],MAT[13]->M_V[6].V[5],MAT[13]->M_V[6].V[6],MAT[13]->M_V[6].V[7],MAT[13]->M_V[6].V[8],MAT[13]->M_V[6].V[9],MAT[13]->M_V[6].V[10],MAT[13]->M_V[6].V[11],MAT[13]->M_V[6].V[12],MAT[13]->M_V[6].V[13],MAT[13]->M_V[6].V[14],MAT[13]->M_V[6].V[15]);
    
    fprintf(fp_mat13_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[7].V[0],MAT[13]->M_V[7].V[1],MAT[13]->M_V[7].V[2],MAT[13]->M_V[7].V[3],MAT[13]->M_V[7].V[4],MAT[13]->M_V[7].V[5],MAT[13]->M_V[7].V[6],MAT[13]->M_V[7].V[7],MAT[13]->M_V[7].V[8],MAT[13]->M_V[7].V[9],MAT[13]->M_V[7].V[10],MAT[13]->M_V[7].V[11],MAT[13]->M_V[7].V[12],MAT[13]->M_V[7].V[13],MAT[13]->M_V[7].V[14],MAT[13]->M_V[0].V[15]);
    
    fprintf(fp_mat13_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[8].V[0],MAT[13]->M_V[8].V[1],MAT[13]->M_V[8].V[2],MAT[13]->M_V[8].V[3],MAT[13]->M_V[8].V[4],MAT[13]->M_V[8].V[5],MAT[13]->M_V[8].V[6],MAT[13]->M_V[8].V[7],MAT[13]->M_V[8].V[8],MAT[13]->M_V[8].V[9],MAT[13]->M_V[8].V[10],MAT[13]->M_V[8].V[11],MAT[13]->M_V[8].V[12],MAT[13]->M_V[8].V[13],MAT[13]->M_V[8].V[14],MAT[13]->M_V[8].V[15]);
    
    fprintf(fp_mat13_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[9].V[0],MAT[13]->M_V[9].V[1],MAT[13]->M_V[9].V[2],MAT[13]->M_V[9].V[3],MAT[13]->M_V[9].V[4],MAT[13]->M_V[9].V[5],MAT[13]->M_V[9].V[6],MAT[13]->M_V[9].V[7],MAT[13]->M_V[9].V[8],MAT[13]->M_V[9].V[9],MAT[13]->M_V[9].V[10],MAT[13]->M_V[9].V[11],MAT[13]->M_V[9].V[12],MAT[13]->M_V[9].V[13],MAT[13]->M_V[9].V[14],MAT[13]->M_V[9].V[15]);
    
    fprintf(fp_mat13_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[10].V[0],MAT[13]->M_V[10].V[1],MAT[13]->M_V[10].V[2],MAT[13]->M_V[10].V[3],MAT[13]->M_V[10].V[4],MAT[13]->M_V[10].V[5],MAT[13]->M_V[10].V[6],MAT[13]->M_V[10].V[7],MAT[13]->M_V[10].V[8],MAT[13]->M_V[10].V[9],MAT[13]->M_V[10].V[10],MAT[13]->M_V[10].V[11],MAT[13]->M_V[10].V[12],MAT[13]->M_V[10].V[13],MAT[13]->M_V[10].V[14],MAT[13]->M_V[10].V[15]);
    
    fprintf(fp_mat13_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[11].V[0],MAT[13]->M_V[11].V[1],MAT[13]->M_V[12].V[2],MAT[13]->M_V[11].V[3],MAT[13]->M_V[11].V[4],MAT[13]->M_V[11].V[5],MAT[13]->M_V[11].V[6],MAT[13]->M_V[11].V[7],MAT[13]->M_V[11].V[8],MAT[13]->M_V[11].V[9],MAT[13]->M_V[11].V[10],MAT[13]->M_V[11].V[11],MAT[13]->M_V[11].V[12],MAT[13]->M_V[11].V[13],MAT[13]->M_V[11].V[14],MAT[13]->M_V[11].V[15]);
    
    fprintf(fp_mat13_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[12].V[0],MAT[13]->M_V[12].V[1],MAT[13]->M_V[13].V[2],MAT[13]->M_V[12].V[3],MAT[13]->M_V[12].V[4],MAT[13]->M_V[12].V[5],MAT[13]->M_V[12].V[6],MAT[13]->M_V[12].V[7],MAT[13]->M_V[12].V[8],MAT[13]->M_V[12].V[9],MAT[13]->M_V[12].V[10],MAT[13]->M_V[12].V[11],MAT[13]->M_V[12].V[12],MAT[13]->M_V[12].V[13],MAT[13]->M_V[12].V[14],MAT[13]->M_V[12].V[15]);
    
    fprintf(fp_mat13_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[13].V[0],MAT[13]->M_V[13].V[1],MAT[13]->M_V[14].V[2],MAT[13]->M_V[13].V[3],MAT[13]->M_V[13].V[4],MAT[13]->M_V[13].V[5],MAT[13]->M_V[13].V[6],MAT[13]->M_V[13].V[7],MAT[13]->M_V[13].V[8],MAT[13]->M_V[13].V[9],MAT[13]->M_V[13].V[10],MAT[13]->M_V[13].V[11],MAT[13]->M_V[13].V[12],MAT[13]->M_V[13].V[13],MAT[13]->M_V[13].V[14],MAT[13]->M_V[13].V[15]);
    
    fprintf(fp_mat13_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[14].V[0],MAT[13]->M_V[14].V[1],MAT[13]->M_V[15].V[2],MAT[13]->M_V[14].V[3],MAT[13]->M_V[14].V[4],MAT[13]->M_V[14].V[5],MAT[13]->M_V[14].V[6],MAT[13]->M_V[14].V[7],MAT[13]->M_V[14].V[8],MAT[13]->M_V[14].V[9],MAT[13]->M_V[14].V[10],MAT[13]->M_V[14].V[11],MAT[13]->M_V[14].V[12],MAT[13]->M_V[14].V[13],MAT[13]->M_V[14].V[14],MAT[13]->M_V[14].V[15]);
    
    fprintf(fp_mat13_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[13]->M_V[15].V[0],MAT[13]->M_V[15].V[1],MAT[13]->M_V[16].V[2],MAT[13]->M_V[15].V[3],MAT[13]->M_V[15].V[4],MAT[13]->M_V[15].V[5],MAT[13]->M_V[15].V[6],MAT[13]->M_V[15].V[7],MAT[13]->M_V[15].V[8],MAT[13]->M_V[15].V[9],MAT[13]->M_V[15].V[10],MAT[13]->M_V[15].V[11],MAT[13]->M_V[15].V[12],MAT[13]->M_V[15].V[13],MAT[13]->M_V[15].V[14],MAT[13]->M_V[15].V[15]);
    
    
    fprintf(fp_mat14_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[0].V[0],MAT[14]->M_V[0].V[1],MAT[14]->M_V[0].V[2],MAT[14]->M_V[0].V[3],MAT[14]->M_V[0].V[4],MAT[14]->M_V[0].V[5],MAT[14]->M_V[0].V[6],MAT[14]->M_V[0].V[7],MAT[14]->M_V[0].V[8],MAT[14]->M_V[0].V[9],MAT[14]->M_V[0].V[10],MAT[14]->M_V[0].V[11],MAT[14]->M_V[0].V[12],MAT[14]->M_V[0].V[13],MAT[14]->M_V[0].V[14],MAT[14]->M_V[0].V[15]);
    
    fprintf(fp_mat14_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[1].V[0],MAT[14]->M_V[1].V[1],MAT[14]->M_V[1].V[2],MAT[14]->M_V[1].V[3],MAT[14]->M_V[1].V[4],MAT[14]->M_V[1].V[5],MAT[14]->M_V[1].V[6],MAT[14]->M_V[1].V[7],MAT[14]->M_V[1].V[8],MAT[14]->M_V[1].V[9],MAT[14]->M_V[1].V[10],MAT[14]->M_V[1].V[11],MAT[14]->M_V[1].V[12],MAT[14]->M_V[1].V[13],MAT[14]->M_V[1].V[14],MAT[14]->M_V[1].V[15]);
    
    fprintf(fp_mat14_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[2].V[0],MAT[14]->M_V[2].V[1],MAT[14]->M_V[2].V[2],MAT[14]->M_V[2].V[3],MAT[14]->M_V[2].V[4],MAT[14]->M_V[2].V[5],MAT[14]->M_V[2].V[6],MAT[14]->M_V[2].V[7],MAT[14]->M_V[2].V[8],MAT[14]->M_V[2].V[9],MAT[14]->M_V[2].V[10],MAT[14]->M_V[2].V[11],MAT[14]->M_V[2].V[12],MAT[14]->M_V[2].V[13],MAT[14]->M_V[2].V[14],MAT[14]->M_V[2].V[15]);
    
    fprintf(fp_mat14_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[3].V[0],MAT[14]->M_V[3].V[1],MAT[14]->M_V[3].V[2],MAT[14]->M_V[3].V[3],MAT[14]->M_V[3].V[4],MAT[14]->M_V[3].V[5],MAT[14]->M_V[3].V[6],MAT[14]->M_V[3].V[7],MAT[14]->M_V[3].V[8],MAT[14]->M_V[3].V[9],MAT[14]->M_V[3].V[10],MAT[14]->M_V[3].V[11],MAT[14]->M_V[3].V[12],MAT[14]->M_V[3].V[13],MAT[14]->M_V[3].V[14],MAT[14]->M_V[3].V[15]);    
    
    fprintf(fp_mat14_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[4].V[0],MAT[14]->M_V[4].V[1],MAT[14]->M_V[4].V[2],MAT[14]->M_V[4].V[3],MAT[14]->M_V[4].V[4],MAT[14]->M_V[4].V[5],MAT[14]->M_V[4].V[6],MAT[14]->M_V[4].V[7],MAT[14]->M_V[4].V[8],MAT[14]->M_V[4].V[9],MAT[14]->M_V[4].V[10],MAT[14]->M_V[4].V[11],MAT[14]->M_V[4].V[12],MAT[14]->M_V[4].V[13],MAT[14]->M_V[4].V[14],MAT[14]->M_V[4].V[15]);
    
    fprintf(fp_mat14_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[5].V[0],MAT[14]->M_V[5].V[1],MAT[14]->M_V[5].V[2],MAT[14]->M_V[5].V[3],MAT[14]->M_V[5].V[4],MAT[14]->M_V[5].V[5],MAT[14]->M_V[5].V[6],MAT[14]->M_V[5].V[7],MAT[14]->M_V[5].V[8],MAT[14]->M_V[5].V[9],MAT[14]->M_V[5].V[10],MAT[14]->M_V[5].V[11],MAT[14]->M_V[5].V[12],MAT[14]->M_V[5].V[13],MAT[14]->M_V[5].V[14],MAT[14]->M_V[5].V[15]);
    
    fprintf(fp_mat14_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[6].V[0],MAT[14]->M_V[6].V[1],MAT[14]->M_V[6].V[2],MAT[14]->M_V[6].V[3],MAT[14]->M_V[6].V[4],MAT[14]->M_V[6].V[5],MAT[14]->M_V[6].V[6],MAT[14]->M_V[6].V[7],MAT[14]->M_V[6].V[8],MAT[14]->M_V[6].V[9],MAT[14]->M_V[6].V[10],MAT[14]->M_V[6].V[11],MAT[14]->M_V[6].V[12],MAT[14]->M_V[6].V[13],MAT[14]->M_V[6].V[14],MAT[14]->M_V[6].V[15]);
    
    fprintf(fp_mat14_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[7].V[0],MAT[14]->M_V[7].V[1],MAT[14]->M_V[7].V[2],MAT[14]->M_V[7].V[3],MAT[14]->M_V[7].V[4],MAT[14]->M_V[7].V[5],MAT[14]->M_V[7].V[6],MAT[14]->M_V[7].V[7],MAT[14]->M_V[7].V[8],MAT[14]->M_V[7].V[9],MAT[14]->M_V[7].V[10],MAT[14]->M_V[7].V[11],MAT[14]->M_V[7].V[12],MAT[14]->M_V[7].V[13],MAT[14]->M_V[7].V[14],MAT[14]->M_V[0].V[15]);
    
    fprintf(fp_mat14_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[8].V[0],MAT[14]->M_V[8].V[1],MAT[14]->M_V[8].V[2],MAT[14]->M_V[8].V[3],MAT[14]->M_V[8].V[4],MAT[14]->M_V[8].V[5],MAT[14]->M_V[8].V[6],MAT[14]->M_V[8].V[7],MAT[14]->M_V[8].V[8],MAT[14]->M_V[8].V[9],MAT[14]->M_V[8].V[10],MAT[14]->M_V[8].V[11],MAT[14]->M_V[8].V[12],MAT[14]->M_V[8].V[13],MAT[14]->M_V[8].V[14],MAT[14]->M_V[8].V[15]);
    
    fprintf(fp_mat14_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[9].V[0],MAT[14]->M_V[9].V[1],MAT[14]->M_V[9].V[2],MAT[14]->M_V[9].V[3],MAT[14]->M_V[9].V[4],MAT[14]->M_V[9].V[5],MAT[14]->M_V[9].V[6],MAT[14]->M_V[9].V[7],MAT[14]->M_V[9].V[8],MAT[14]->M_V[9].V[9],MAT[14]->M_V[9].V[10],MAT[14]->M_V[9].V[11],MAT[14]->M_V[9].V[12],MAT[14]->M_V[9].V[13],MAT[14]->M_V[9].V[14],MAT[14]->M_V[9].V[15]);
    
    fprintf(fp_mat14_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[10].V[0],MAT[14]->M_V[10].V[1],MAT[14]->M_V[10].V[2],MAT[14]->M_V[10].V[3],MAT[14]->M_V[10].V[4],MAT[14]->M_V[10].V[5],MAT[14]->M_V[10].V[6],MAT[14]->M_V[10].V[7],MAT[14]->M_V[10].V[8],MAT[14]->M_V[10].V[9],MAT[14]->M_V[10].V[10],MAT[14]->M_V[10].V[11],MAT[14]->M_V[10].V[12],MAT[14]->M_V[10].V[13],MAT[14]->M_V[10].V[14],MAT[14]->M_V[10].V[15]);
    
    fprintf(fp_mat14_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[11].V[0],MAT[14]->M_V[11].V[1],MAT[14]->M_V[12].V[2],MAT[14]->M_V[11].V[3],MAT[14]->M_V[11].V[4],MAT[14]->M_V[11].V[5],MAT[14]->M_V[11].V[6],MAT[14]->M_V[11].V[7],MAT[14]->M_V[11].V[8],MAT[14]->M_V[11].V[9],MAT[14]->M_V[11].V[10],MAT[14]->M_V[11].V[11],MAT[14]->M_V[11].V[12],MAT[14]->M_V[11].V[13],MAT[14]->M_V[11].V[14],MAT[14]->M_V[11].V[15]);
    
    fprintf(fp_mat14_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[12].V[0],MAT[14]->M_V[12].V[1],MAT[14]->M_V[13].V[2],MAT[14]->M_V[12].V[3],MAT[14]->M_V[12].V[4],MAT[14]->M_V[12].V[5],MAT[14]->M_V[12].V[6],MAT[14]->M_V[12].V[7],MAT[14]->M_V[12].V[8],MAT[14]->M_V[12].V[9],MAT[14]->M_V[12].V[10],MAT[14]->M_V[12].V[11],MAT[14]->M_V[12].V[12],MAT[14]->M_V[12].V[13],MAT[14]->M_V[12].V[14],MAT[14]->M_V[12].V[15]);
    
    fprintf(fp_mat14_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[13].V[0],MAT[14]->M_V[13].V[1],MAT[14]->M_V[14].V[2],MAT[14]->M_V[13].V[3],MAT[14]->M_V[13].V[4],MAT[14]->M_V[13].V[5],MAT[14]->M_V[13].V[6],MAT[14]->M_V[13].V[7],MAT[14]->M_V[13].V[8],MAT[14]->M_V[13].V[9],MAT[14]->M_V[13].V[10],MAT[14]->M_V[13].V[11],MAT[14]->M_V[13].V[12],MAT[14]->M_V[13].V[13],MAT[14]->M_V[13].V[14],MAT[14]->M_V[13].V[15]);
    
    fprintf(fp_mat14_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[14].V[0],MAT[14]->M_V[14].V[1],MAT[14]->M_V[15].V[2],MAT[14]->M_V[14].V[3],MAT[14]->M_V[14].V[4],MAT[14]->M_V[14].V[5],MAT[14]->M_V[14].V[6],MAT[14]->M_V[14].V[7],MAT[14]->M_V[14].V[8],MAT[14]->M_V[14].V[9],MAT[14]->M_V[14].V[10],MAT[14]->M_V[14].V[11],MAT[14]->M_V[14].V[12],MAT[14]->M_V[14].V[13],MAT[14]->M_V[14].V[14],MAT[14]->M_V[14].V[15]);
    
    fprintf(fp_mat14_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[14]->M_V[15].V[0],MAT[14]->M_V[15].V[1],MAT[14]->M_V[16].V[2],MAT[14]->M_V[15].V[3],MAT[14]->M_V[15].V[4],MAT[14]->M_V[15].V[5],MAT[14]->M_V[15].V[6],MAT[14]->M_V[15].V[7],MAT[14]->M_V[15].V[8],MAT[14]->M_V[15].V[9],MAT[14]->M_V[15].V[10],MAT[14]->M_V[15].V[11],MAT[14]->M_V[15].V[12],MAT[14]->M_V[15].V[13],MAT[14]->M_V[15].V[14],MAT[14]->M_V[15].V[15]);
    
    
    fprintf(fp_mat15_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[0].V[0],MAT[15]->M_V[0].V[1],MAT[15]->M_V[0].V[2],MAT[15]->M_V[0].V[3],MAT[15]->M_V[0].V[4],MAT[15]->M_V[0].V[5],MAT[15]->M_V[0].V[6],MAT[15]->M_V[0].V[7],MAT[15]->M_V[0].V[8],MAT[15]->M_V[0].V[9],MAT[15]->M_V[0].V[10],MAT[15]->M_V[0].V[11],MAT[15]->M_V[0].V[12],MAT[15]->M_V[0].V[13],MAT[15]->M_V[0].V[14],MAT[15]->M_V[0].V[15]);
    
    fprintf(fp_mat15_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[1].V[0],MAT[15]->M_V[1].V[1],MAT[15]->M_V[1].V[2],MAT[15]->M_V[1].V[3],MAT[15]->M_V[1].V[4],MAT[15]->M_V[1].V[5],MAT[15]->M_V[1].V[6],MAT[15]->M_V[1].V[7],MAT[15]->M_V[1].V[8],MAT[15]->M_V[1].V[9],MAT[15]->M_V[1].V[10],MAT[15]->M_V[1].V[11],MAT[15]->M_V[1].V[12],MAT[15]->M_V[1].V[13],MAT[15]->M_V[1].V[14],MAT[15]->M_V[1].V[15]);
    
    fprintf(fp_mat15_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[2].V[0],MAT[15]->M_V[2].V[1],MAT[15]->M_V[2].V[2],MAT[15]->M_V[2].V[3],MAT[15]->M_V[2].V[4],MAT[15]->M_V[2].V[5],MAT[15]->M_V[2].V[6],MAT[15]->M_V[2].V[7],MAT[15]->M_V[2].V[8],MAT[15]->M_V[2].V[9],MAT[15]->M_V[2].V[10],MAT[15]->M_V[2].V[11],MAT[15]->M_V[2].V[12],MAT[15]->M_V[2].V[13],MAT[15]->M_V[2].V[14],MAT[15]->M_V[2].V[15]);
    
    fprintf(fp_mat15_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[3].V[0],MAT[15]->M_V[3].V[1],MAT[15]->M_V[3].V[2],MAT[15]->M_V[3].V[3],MAT[15]->M_V[3].V[4],MAT[15]->M_V[3].V[5],MAT[15]->M_V[3].V[6],MAT[15]->M_V[3].V[7],MAT[15]->M_V[3].V[8],MAT[15]->M_V[3].V[9],MAT[15]->M_V[3].V[10],MAT[15]->M_V[3].V[11],MAT[15]->M_V[3].V[12],MAT[15]->M_V[3].V[13],MAT[15]->M_V[3].V[14],MAT[15]->M_V[3].V[15]);    
    
    fprintf(fp_mat15_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[4].V[0],MAT[15]->M_V[4].V[1],MAT[15]->M_V[4].V[2],MAT[15]->M_V[4].V[3],MAT[15]->M_V[4].V[4],MAT[15]->M_V[4].V[5],MAT[15]->M_V[4].V[6],MAT[15]->M_V[4].V[7],MAT[15]->M_V[4].V[8],MAT[15]->M_V[4].V[9],MAT[15]->M_V[4].V[10],MAT[15]->M_V[4].V[11],MAT[15]->M_V[4].V[12],MAT[15]->M_V[4].V[13],MAT[15]->M_V[4].V[14],MAT[15]->M_V[4].V[15]);
    
    fprintf(fp_mat15_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[5].V[0],MAT[15]->M_V[5].V[1],MAT[15]->M_V[5].V[2],MAT[15]->M_V[5].V[3],MAT[15]->M_V[5].V[4],MAT[15]->M_V[5].V[5],MAT[15]->M_V[5].V[6],MAT[15]->M_V[5].V[7],MAT[15]->M_V[5].V[8],MAT[15]->M_V[5].V[9],MAT[15]->M_V[5].V[10],MAT[15]->M_V[5].V[11],MAT[15]->M_V[5].V[12],MAT[15]->M_V[5].V[13],MAT[15]->M_V[5].V[14],MAT[15]->M_V[5].V[15]);
    
    fprintf(fp_mat15_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[6].V[0],MAT[15]->M_V[6].V[1],MAT[15]->M_V[6].V[2],MAT[15]->M_V[6].V[3],MAT[15]->M_V[6].V[4],MAT[15]->M_V[6].V[5],MAT[15]->M_V[6].V[6],MAT[15]->M_V[6].V[7],MAT[15]->M_V[6].V[8],MAT[15]->M_V[6].V[9],MAT[15]->M_V[6].V[10],MAT[15]->M_V[6].V[11],MAT[15]->M_V[6].V[12],MAT[15]->M_V[6].V[13],MAT[15]->M_V[6].V[14],MAT[15]->M_V[6].V[15]);
    
    fprintf(fp_mat15_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[7].V[0],MAT[15]->M_V[7].V[1],MAT[15]->M_V[7].V[2],MAT[15]->M_V[7].V[3],MAT[15]->M_V[7].V[4],MAT[15]->M_V[7].V[5],MAT[15]->M_V[7].V[6],MAT[15]->M_V[7].V[7],MAT[15]->M_V[7].V[8],MAT[15]->M_V[7].V[9],MAT[15]->M_V[7].V[10],MAT[15]->M_V[7].V[11],MAT[15]->M_V[7].V[12],MAT[15]->M_V[7].V[13],MAT[15]->M_V[7].V[14],MAT[15]->M_V[0].V[15]);
    
    fprintf(fp_mat15_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[8].V[0],MAT[15]->M_V[8].V[1],MAT[15]->M_V[8].V[2],MAT[15]->M_V[8].V[3],MAT[15]->M_V[8].V[4],MAT[15]->M_V[8].V[5],MAT[15]->M_V[8].V[6],MAT[15]->M_V[8].V[7],MAT[15]->M_V[8].V[8],MAT[15]->M_V[8].V[9],MAT[15]->M_V[8].V[10],MAT[15]->M_V[8].V[11],MAT[15]->M_V[8].V[12],MAT[15]->M_V[8].V[13],MAT[15]->M_V[8].V[14],MAT[15]->M_V[8].V[15]);
    
    fprintf(fp_mat15_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[9].V[0],MAT[15]->M_V[9].V[1],MAT[15]->M_V[9].V[2],MAT[15]->M_V[9].V[3],MAT[15]->M_V[9].V[4],MAT[15]->M_V[9].V[5],MAT[15]->M_V[9].V[6],MAT[15]->M_V[9].V[7],MAT[15]->M_V[9].V[8],MAT[15]->M_V[9].V[9],MAT[15]->M_V[9].V[10],MAT[15]->M_V[9].V[11],MAT[15]->M_V[9].V[12],MAT[15]->M_V[9].V[13],MAT[15]->M_V[9].V[14],MAT[15]->M_V[9].V[15]);
    
    fprintf(fp_mat15_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[10].V[0],MAT[15]->M_V[10].V[1],MAT[15]->M_V[10].V[2],MAT[15]->M_V[10].V[3],MAT[15]->M_V[10].V[4],MAT[15]->M_V[10].V[5],MAT[15]->M_V[10].V[6],MAT[15]->M_V[10].V[7],MAT[15]->M_V[10].V[8],MAT[15]->M_V[10].V[9],MAT[15]->M_V[10].V[10],MAT[15]->M_V[10].V[11],MAT[15]->M_V[10].V[12],MAT[15]->M_V[10].V[13],MAT[15]->M_V[10].V[14],MAT[15]->M_V[10].V[15]);
    
    fprintf(fp_mat15_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[11].V[0],MAT[15]->M_V[11].V[1],MAT[15]->M_V[12].V[2],MAT[15]->M_V[11].V[3],MAT[15]->M_V[11].V[4],MAT[15]->M_V[11].V[5],MAT[15]->M_V[11].V[6],MAT[15]->M_V[11].V[7],MAT[15]->M_V[11].V[8],MAT[15]->M_V[11].V[9],MAT[15]->M_V[11].V[10],MAT[15]->M_V[11].V[11],MAT[15]->M_V[11].V[12],MAT[15]->M_V[11].V[13],MAT[15]->M_V[11].V[14],MAT[15]->M_V[11].V[15]);
    
    fprintf(fp_mat15_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[12].V[0],MAT[15]->M_V[12].V[1],MAT[15]->M_V[13].V[2],MAT[15]->M_V[12].V[3],MAT[15]->M_V[12].V[4],MAT[15]->M_V[12].V[5],MAT[15]->M_V[12].V[6],MAT[15]->M_V[12].V[7],MAT[15]->M_V[12].V[8],MAT[15]->M_V[12].V[9],MAT[15]->M_V[12].V[10],MAT[15]->M_V[12].V[11],MAT[15]->M_V[12].V[12],MAT[15]->M_V[12].V[13],MAT[15]->M_V[12].V[14],MAT[15]->M_V[12].V[15]);
    
    fprintf(fp_mat15_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[13].V[0],MAT[15]->M_V[13].V[1],MAT[15]->M_V[14].V[2],MAT[15]->M_V[13].V[3],MAT[15]->M_V[13].V[4],MAT[15]->M_V[13].V[5],MAT[15]->M_V[13].V[6],MAT[15]->M_V[13].V[7],MAT[15]->M_V[13].V[8],MAT[15]->M_V[13].V[9],MAT[15]->M_V[13].V[10],MAT[15]->M_V[13].V[11],MAT[15]->M_V[13].V[12],MAT[15]->M_V[13].V[13],MAT[15]->M_V[13].V[14],MAT[15]->M_V[13].V[15]);
    
    fprintf(fp_mat15_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[14].V[0],MAT[15]->M_V[14].V[1],MAT[15]->M_V[15].V[2],MAT[15]->M_V[14].V[3],MAT[15]->M_V[14].V[4],MAT[15]->M_V[14].V[5],MAT[15]->M_V[14].V[6],MAT[15]->M_V[14].V[7],MAT[15]->M_V[14].V[8],MAT[15]->M_V[14].V[9],MAT[15]->M_V[14].V[10],MAT[15]->M_V[14].V[11],MAT[15]->M_V[14].V[12],MAT[15]->M_V[14].V[13],MAT[15]->M_V[14].V[14],MAT[15]->M_V[14].V[15]);
    
    fprintf(fp_mat15_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",MAT[15]->M_V[15].V[0],MAT[15]->M_V[15].V[1],MAT[15]->M_V[16].V[2],MAT[15]->M_V[15].V[3],MAT[15]->M_V[15].V[4],MAT[15]->M_V[15].V[5],MAT[15]->M_V[15].V[6],MAT[15]->M_V[15].V[7],MAT[15]->M_V[15].V[8],MAT[15]->M_V[15].V[9],MAT[15]->M_V[15].V[10],MAT[15]->M_V[15].V[11],MAT[15]->M_V[15].V[12],MAT[15]->M_V[15].V[13],MAT[15]->M_V[15].V[14],MAT[15]->M_V[15].V[15]);*/

}

void zeroize_print_mat(int num_mat_zore)
{
	int count_num_print_mat;
	for(count_num_print_mat=0;count_num_print_mat<num_mat_zore;count_num_print_mat++)
	{
		fprintf(fp_mat0_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat0_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);


		fprintf(fp_mat1_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat1_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);



		fprintf(fp_mat2_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat2_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);



		fprintf(fp_mat3_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat3_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);


		fprintf(fp_mat4_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat4_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);


		fprintf(fp_mat5_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat5_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);


		fprintf(fp_mat6_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat6_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);


		fprintf(fp_mat7_0,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_1,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_2,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_3,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_4,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_5,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_6,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_7,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_8,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_9,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_10,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_11,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_12,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_13,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_14,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

		fprintf(fp_mat7_15,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);

	}
}
