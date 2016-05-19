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

#ifndef _PL_KERNEL_H
#define _PL_KERNEL_H

#include "ps_pipeline.h"
#include "configuration.h"

extern long d_ins_n;

extern void insert_headlist(long ins,bool ins_f);

extern long Init_pm();

extern bool pl_fetch();

extern bool pl_load();

extern bool pl_launch();

extern bool pl_wb();

extern bool pl_store();

extern bool pl_mov();

extern bool pl_extmov();

extern bool pl_dmalr();

extern bool pl_dmalc();

extern bool pl_dmasr();

extern bool pl_dmasc();

extern bool pl_prodvm();

extern bool pl_prodvmp();

extern bool pl_prodmv();

extern bool pl_prodmvp();

extern bool pl_prodvv();

extern bool pl_prodvvp();

extern bool pl_prodvvd();

extern bool pl_addv();

extern bool pl_addm();

extern bool pl_subv();

extern bool pl_subm();

extern bool pl_sum();

extern bool pl_max();

extern bool pl_scale();

extern bool pl_diff();

extern bool pl_randgen();

extern bool pl_probcmp();

extern bool pl_bias();

extern bool pl_act();

extern bool pl_decode(decodeoprand** inssp);

extern bool pl_syn(int);

#endif /* _PL_KERNEL_H */
