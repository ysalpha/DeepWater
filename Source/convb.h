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

#ifndef _CONVB_H
#define _CONVB_H

#include <stdio.h>

#include "ps_pipeline.h"

/* myRTLDebug mark to print more messages to help coder debug the programmer.0 is show to not execute and the value is defaulted*/
#define myRTLDebug 0

/* Register addressing in hardware */
#define RV0_ADDR 0
#define RV1_ADDR 1
#define RV2_ADDR 2
#define RV3_ADDR 3
#define RV4_ADDR 4
#define RV5_ADDR 5
#define RV6_ADDR 6
#define RV7_ADDR 7
#define RV8_ADDR 8
#define RV9_ADDR 9
#define RV10_ADDR 10
#define RV11_ADDR 11
#define RV12_ADDR 12
#define RV13_ADDR 13
#define RV14_ADDR 14
#define RV15_ADDR 15

#define EXTV0_ADDR 16
#define EXTV1_ADDR 17
#define EXTV2_ADDR 18
#define EXTV3_ADDR 19
#define EXTV4_ADDR 20
#define EXTV5_ADDR 21
#define EXTV6_ADDR 22
#define EXTV7_ADDR 23

#define BV0_ADDR 24
#define BV1_ADDR 25
#define BV2_ADDR 26
#define BV3_ADDR 27

#define RDV0_ADDR 28
#define RDV1_ADDR 29
#define RDV2_ADDR 30
#define RDV3_ADDR 31

#define MAT0_ADDR 0
#define MAT1_ADDR 1
#define MAT2_ADDR 2
#define MAT3_ADDR 3
#define MAT4_ADDR 4
#define MAT5_ADDR 5
#define MAT6_ADDR 6
#define MAT7_ADDR 7

/* the binary ending of instructions in the RTL */
#define LOAD0_ADDR "1000000"
#define LOAD1_ADDR "1000001"
#define STORE0_ADDR "1000010"
#define STORE1_ADDR "1000011"
#define LAUNCH0_ADDR "1000100"
#define LAUNCH1_ADDR "1000101"
#define WB0_ADDR "1000110"
#define WB1_ADDR "1000111"
#define DMALR0_ADDR "1001000"
#define DMALR1_ADDR "1001001"
#define DMALR2_ADDR "1001010"
#define DMALC0_ADDR "1001011"
#define DMALC1_ADDR "1001100"
#define DMALC2_ADDR "1001101"
#define DMASR0_ADDR "1001110"
#define DMASR1_ADDR "1001111"
#define DMASR2_ADDR "1010000"
#define DMASC0_ADDR "1010001"
#define DMASC1_ADDR "1010010"
#define DMASC2_ADDR "1010011"
#define MOV_ADDR "1010100"
#define EXTMOV_ADDR "1010101"
#define PRODVM_ADDR "0100000"
#define PRODVMP_ADDR "0100001"
#define PRODMV_ADDR "0100010"
#define PRODMVP_ADDR "0100011"
#define PRODVV_ADDR "0100100"
#define PRODVVP_ADDR "0100101"
#define PRODVVD_ADDR "0100110"
#define DIFF_ADDR "0100111"
#define ADDV_ADDR "0101000"
#define ADDM_ADDR "0101001"
#define SUBV_ADDR "0101010"
#define SUBM_ADDR "0101011"
#define MAX_ADDR "0101100"
#define SCALE_ADDR "0101101"
#define BIAS_ADDR "0101110"
#define PROBCMP_ADDR "0101111"
#define EXP_ADDR "1100000"
#define LOG_ADDR "1100001"
#define RANDGEN_ADDR "1100010"
#define ACT_ADDR "1100011"

/* the file of saving the binary data*/
#define SAVE_B_FILE "rtlB.txt"

/* bits of parts of instruction*/
#define RG_A_L 7
#define BUFF_ID_A_L 2
#define LENGTH_A_L 4
#define BUFFER_ADDR_A_L 18
#define ALL_LENGTH_ADDR 32
#define INST_LENGTH_ADDR 7
#define MAT_A_L 7
#define ROW_COL_A_L 4
#define MEM_ADDR_A_L 32
#define MEN_ADDR_H_A_L 25
#define MEN_ADDR_L_A_L 7
#define STRIDE_A_L 15
#define REPETITION_A_L 4
#define SCALE_FACTOR_A_L 7
#define BIASE_A_L 7

extern char save_b[];//declare the 
extern FILE* fp_saveRTLB; // declare the file point saving the binary data 
extern FILE* fp_Ri;  //declare the file point saving out-order instructions 

/* declare the function convert the instruction to binary*/
extern bool convert_ins_to_b(ploprand,FILE*);

/* declare the function of matching the BV register file convert to binary */
extern void match_BV_ADDR(ploprand,int,FILE*);
extern void match_RV_ADDR(ploprand,int,FILE*);
extern void match_RDV_ADDR(ploprand,int,FILE*);
extern void match_EXTV_ADDR(ploprand,int,FILE*);
extern void match_BUFFER_ID_ADDR(int,FILE*);
extern void match_LENGTH_ADDR(int,FILE*,int);
extern void match_BUFFER_ADDR_ADDR(long,FILE*);
extern void match_LAYER_ADDR_ADDR(ploprand,int,FILE*);
extern void match_ROW_COL_ADDR(int,FILE*);
extern void match_MEM_ADDR_ADDR(long,FILE*,char*);
extern void match_STRIDE_ADDR(int,FILE*);
extern void match_REPETITION_ADDR(int,FILE*);
extern void match_SCALE_FACTOR_ADDR(int,FILE*);
extern void match_BIAS_ADDR(int,FILE*);

/* declare the function print a string to file*/
extern void put_str_ADDR(char*,FILE*);

/* declare the function print zero to file*/
extern void zeroize_ADDR(int,FILE*);

/* declare the function print a '\n' to file*/
extern void linefeed_ADDR(FILE*);

/* initialize file point */
extern void init_hd_file();
#endif /* _CONVB_H */
