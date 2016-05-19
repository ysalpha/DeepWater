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

#ifndef _PRINT_H
#define _PRINT_H

#include "ps_pipeline.h"

extern FILE* freport;

/* initialize debug information file pointer*/
extern void init_dbP_file();

extern bool myprintregB(RB rg);
extern bool myprintreg(RG rg);
extern bool myprint_BV();
extern bool myprint_RV();
extern bool myprint_RDV();
extern bool myprint_EXTV();
extern bool myprint_MAT();
extern bool myprint_BUFFER();
extern void myprint_fatal(char *s);
extern bool myprint_report(char *s0, long n0, char *s1, long n1, char *s2, long n2);
extern bool myprint_report0(char *s0, long n0, char *s1, long n1, char *s2, long n2);
extern void myprintreg_rb(RB rg);
extern void myprintreg_rp(RG rg);
extern bool myprint_BV_rp();
extern bool myprint_RV_rp();
extern bool myprint_RDV_rp();
extern bool myprint_EXTV_rp();
extern bool myprint_MAT_rp();
extern bool myprint_BUFFER_rp();

#endif /* _PRINT_H */
