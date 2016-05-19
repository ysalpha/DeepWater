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

#ifndef _INS_OPCODE_H
#define _INS_OPCODE_H

/* define instructions operation code */
#define LOAD_OPCODE 0
#define STORE_OPCODE 3
#define LAUNCH_OPCODE 2
#define WB_OPCODE 6
#define MOV_OPCODE 4
#define EXTMOV_OPCODE 5
#define DMALR_OPCODE 30
#define DMALC_OPCODE 31
#define DMASR_OPCODE 32
#define DMASC_OPCODE 33
#define PRODVM_OPCODE 8
#define PRODVMP_OPCODE 13
#define PRODMV_OPCODE 9
#define PRODMVP_OPCODE 14
#define PRODVV_OPCODE 10
#define PRODVVP_OPCODE 15
#define PRODVVD_OPCODE 11
#define ADDV_OPCODE 12
#define SUBV_OPCODE 16
#define SUBM_OPCODE 17
#define SUM_OPCODE 18
#define MAX_OPCODE 19
#define SCALE_OPCODE 20
#define ADDM_OPCODE 22
#define DIFF_OPCODE 21
#define RANDGEN_OPCODE 23
#define PROBCMP_OPCODE 24
#define BIAS_OPCODE 25
#define ACT_OPCODE 26
#define LOOP_OPCODE 27
#define ENDLOOP_OPCODE 28


#endif
