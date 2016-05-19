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

#ifndef _PS_INST_H
#define _PS_INST_H

/* preprocessing the inst.txt , return number of inst */
extern long scanline();


/* get register group id */
#define num_ofrg(ins_n,op_n,rg_type) ins_n.op[op_n].opd.type_##rg_type##V.rg_num

/* save operands data */
#define mem_addr_opd(ins_n,op_n,count) ins[ins_n].op[op_n].type_flag = 5;\
	ins[ins_n].op[op_n].opd.mem_addr = count
#define imme_opd(ins_n,op_n,i_data) ins[ins_n].op[op_n].type_flag = 4;\
	ins[ins_n].op[op_n].opd.type_FD = i_data
#define mat_opd(ins_n,op_n,layer,row,col) ins[ins_n].op[op_n].type_flag = 3;\
	ins[ins_n].op[op_n].opd.type_MAT.pMAT = MAT[layer];\
	ins[ins_n].op[op_n].opd.type_MAT.mat_num = layer;\
	ins[ins_n].op[op_n].opd.type_MAT.row = row;\
	ins[ins_n].op[op_n].opd.type_MAT.col = col
#define mat_opd2(ins_n,op_n,layer) ins[ins_n].op[op_n].type_flag = 3;\
	ins[ins_n].op[op_n].opd.type_MAT.pMAT = MAT[layer];\
	ins[ins_n].op[op_n].opd.type_MAT.mat_num = layer
#define buff_opd(ins_n,op_n,buff_id,buff_addr) ins[ins_n].op[op_n].opd.type_BUFF.buff_id=buff_id;\
	ins[ins_n].op[op_n].opd.type_BUFF.mem_b_addr=buff_addr;ins[ins_n].op[op_n].type_flag = 7
#define dma_opd(ins_n,op_n,mem_addr,length,stride,repetition,buff_id,buff_addr) ins[ins_n].op[op_n].type_flag = 6;\
	ins[ins_n].op[op_n].opd.type_DMA.mem_addr = mem_addr;ins[ins_n].op[op_n].opd.type_DMA.length = length;\
	ins[ins_n].op[op_n].opd.type_DMA.stride = stride;ins[ins_n].op[op_n].opd.type_DMA.repetition = repetition;\
	ins[ins_n].op[op_n].opd.type_DMA.buff_id = buff_id;ins[ins_n].op[op_n].opd.type_DMA.buff_addr = buff_addr

#define indirct_flag(ins_n,op_n,boolflag) ins[ins_n].op[op_n].opd.indirctFlag = boolflag
#define indirct_opd(ins_n,op_n,bufferid,loopid,addrid,offset) ins[ins_n].op[op_n].opd.type_INDD.loopId = loopid;\
	ins[ins_n].op[op_n].opd.type_INDD.addrId = addrid;ins[ins_n].op[op_n].opd.type_INDD.offset = offset;\
	ins[ins_n].op[op_n].opd.type_INDD.bufferId = bufferid
#define loopid_opd(ins_n,op_n,loopid,loopiter) ins[ins_n].op[op_n].opd.type_LPID.loopId = loopid;\
	ins[ins_n].op[op_n].opd.type_LPID.iterTimes = loopiter
#define loopad_opd(ins_n,op_n,stride,addr) ins[ins_n].op[op_n].opd.type_LPAD.stride = stride;\
	ins[ins_n].op[op_n].opd.type_LPAD.addr = addr

/* instructions modeling , return number of inst */
extern long init_inst();

#endif /* _PS_INST_H */
