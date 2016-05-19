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

#ifndef _PRINT_R_H
#define _PRINT_R_H

#define FILE_RV0 "rv\\rv0.txt"
#define FILE_RV1 "rv\\rv1.txt"
#define FILE_RV2 "rv\\rv2.txt"
#define FILE_RV3 "rv\\rv3.txt"
#define FILE_RV4 "rv\\rv4.txt"
#define FILE_RV5 "rv\\rv5.txt"
#define FILE_RV6 "rv\\rv6.txt"
#define FILE_RV7 "rv\\rv7.txt"
#define FILE_RV8 "rv\\rv8.txt"
#define FILE_RV9 "rv\\rv9.txt"
#define FILE_RV10 "rv\\rv10.txt"
#define FILE_RV11 "rv\\rv11.txt"
#define FILE_RV12 "rv\\rv12.txt"
#define FILE_RV13 "rv\\rv13.txt"
#define FILE_RV14 "rv\\rv14.txt"
#define FILE_RV15 "rv\\rv15.txt"

#define FILE_RBUFFER "buff\\rbuffer.txt"
#define FILE_CBUFFER "buff\\cbuffer.txt"

#define MBUFFER0 "buff\\mbuffer0.txt"
#define MBUFFER1 "buff\\mbuffer1.txt"
#define MBUFFER2 "buff\\mbuffer2.txt"
#define MBUFFER3 "buff\\mbuffer3.txt"
#define MBUFFER4 "buff\\mbuffer4.txt"
#define MBUFFER5 "buff\\mbuffer5.txt"
#define MBUFFER6 "buff\\mbuffer6.txt"
#define MBUFFER7 "buff\\mbuffer7.txt"
#define MBUFFER8 "buff\\mbuffer8.txt"
#define MBUFFER9 "buff\\mbuffer9.txt"
#define MBUFFER10 "buff\\mbuffer10.txt"
#define MBUFFER11 "buff\\mbuffer11.txt"
#define MBUFFER12 "buff\\mbuffer12.txt"
#define MBUFFER13 "buff\\mbuffer13.txt"
#define MBUFFER14 "buff\\mbuffer14.txt"
#define MBUFFER15 "buff\\mbuffer15.txt"

extern void print_RV0(int);
extern void print_RV1(int);
extern void print_RV2(int);
extern void print_RV3(int);
extern void print_RV4(int);
extern void print_RV5(int);
extern void print_RV6(int);
extern void print_RV7(int);
extern void print_RV8(int);
extern void print_RV9(int);
extern void print_RV10(int);
extern void print_RV11(int);
extern void print_RV12(int);
extern void print_RV13(int);
extern void print_RV14(int);
extern void print_RV15(int);
extern void print_RBUFFER(int);
extern void print_CBUFFER(int);

extern void print_MBUFFER0();
extern void print_MBUFFER1();
extern void print_MBUFFER2();
extern void print_MBUFFER3();
extern void print_MBUFFER4();
extern void print_MBUFFER5();
extern void print_MBUFFER6();
extern void print_MBUFFER7();
extern void print_MBUFFER8();
extern void print_MBUFFER9();
extern void print_MBUFFER10();
extern void print_MBUFFER11();
extern void print_MBUFFER12();
extern void print_MBUFFER13();
extern void print_MBUFFER14();
extern void print_MBUFFER15();

extern void open_file_register();
extern void close_file_register();

extern void print_all_register(int clk);
extern void zeroize_print_all_register(int);

#endif /* _PRINT_R_H */
