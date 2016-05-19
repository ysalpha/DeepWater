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

#ifndef _LOCAL_BUFFER_MODELING_H
#define _LOCAL_BUFFER_MODELING_H

#define VALID 0 //lock is valid
#define INVALID 1 //lock is invalid

#include "dataTypeModeling.h"
#include "configuration.h"

struct MEM_B_B
{
	bool RD_S;
	bool WR_S;
	bool WRD_S;
	bool WWR_S;
	PS_ENT_TYPE MEM_D;
};

struct MEM_B_S
{
	struct MEM_B_B *MEM_B;
};

struct MEM_B
{
	bool isRead;
	bool isWrite;
	struct MEM_B_S *MM_B;
};

extern struct MEM_B *buff0,*buff1,*buff2;
extern struct MEM_B *pbuff0,*pbuff1,*pbuff2;

#define jud_buffer_read(num_ofbuff) (buff##num_ofbuff->isRead==1)?0:1
#define jud_buffer_write(num_ofbuff) (buff##num_ofbuff->isWrite==1)?0:1
#define set_buffer_read(num_ofbuff) buff##num_ofbuff->isRead=1
#define clr_buffer_read(num_ofbuff) buff##num_ofbuff->isRead=0
#define set_buffer_write(num_ofbuff) buff##num_ofbuff->isWrite=1
#define clr_buffer_write(num_ofbuff) buff##num_ofbuff->isWrite=0

#define jud_mb_data_read(num_ofbuff,row,col) ((buff##num_ofbuff->MM_B[row].MEM_B[col].WR_S==VALID)||(buff##num_ofbuff->MM_B[row].MEM_B[col].WWR_S==VALID))?0:1
#define jud_mb_data_write(num_ofbuff,row,col) ((buff##num_ofbuff->MM_B[row].MEM_B[col].RD_S==VALID)||(buff##num_ofbuff->MM_B[row].MEM_B[col].WRD_S==VALID)||(buff##num_ofbuff->MM_B[row].MEM_B[col].WR_S==VALID)||(buff##num_ofbuff->MM_B[row].MEM_B[col].WWR_S==VALID))?0:1
#define set_mb_data_rd(num_ofbuff,row,col) buff##num_ofbuff->MM_B[row].MEM_B[col].RD_S=VALID
#define set_mb_data_wr(num_ofbuff,row,col) buff##num_ofbuff->MM_B[row].MEM_B[col].WR_S=VALID
#define set_mb_data_wrd(num_ofbuff,row,col) buff##num_ofbuff->MM_B[row].MEM_B[col].WRD_S=VALID
#define set_mb_data_wwr(num_ofbuff,row,col) buff##num_ofbuff->MM_B[row].MEM_B[col].WWR_S=VALID
#define clr_mb_data_rd(num_ofbuff,row,col) buff##num_ofbuff->MM_B[row].MEM_B[col].RD_S=INVALID
#define clr_mb_data_wrd(num_ofbuff,row,col) buff##num_ofbuff->MM_B[row].MEM_B[col].WRD_S=INVALID
#define clr_mb_data_wr(num_ofbuff,row,col) buff##num_ofbuff->MM_B[row].MEM_B[col].WR_S=INVALID
#define clr_mb_data_wwr(num_ofbuff,row,col) buff##num_ofbuff->MM_B[row].MEM_B[col].WWR_S=INVALID

#define jud_mb_dread(num_ofbuff,mem_b_address,mem_b_bank) ((buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WR_S==VALID)||(buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WWR_S==VALID))?0:1
#define jud_mb_dwrite(num_ofbuff,mem_b_address,mem_b_bank) ((buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].RD_S==VALID)||(buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WRD_S==VALID)||(buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WR_S==VALID)||(buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WWR_S==VALID))?0:1
#define set_mb_drd(num_ofbuff,mem_b_address,mem_b_bank) buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].RD_S=VALID
#define set_mb_dwr(num_ofbuff,mem_b_address,mem_b_bank) buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WR_S=VALID
#define set_mb_dwrd(num_ofbuff,mem_b_address,mem_b_bank) buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WRD_S=VALID
#define set_mb_dwwr(num_ofbuff,mem_b_address,mem_b_bank) buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WWR_S=VALID
#define clr_mb_drd(num_ofbuff,mem_b_address,mem_b_bank) buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].RD_S=INVALID
#define clr_mb_dwr(num_ofbuff,mem_b_address,mem_b_bank) buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WR_S=INVALID
#define clr_mb_dwrd(num_ofbuff,mem_b_address,mem_b_bank) buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WRD_S=INVALID
#define clr_mb_dwwr(num_ofbuff,mem_b_address,mem_b_bank) buff##num_ofbuff->MM_B[mem_b_address].MEM_B[mem_b_bank].WWR_S=INVALID

#define get_mbdata(buffprt,buff_entry_id,buff_bank_id) (buffprt->MM_B[buff_entry_id].MEM_B[buff_bank_id].MEM_D)
#define back_mbdata(buffprt,buff_entry_id,buff_banl_id,data) buffprt->MM_B[buff_entry_id].MEM_B[buff_banl_id].MEM_D=data

extern bool jud_mb_entryread(int num_ofbuff,long mem_b_address);
extern bool jud_mb_entrywrite(int num_ofbuff,long mem_b_address);
extern bool set_mb_entryrd(int num_ofbuff,long mem_b_address);
extern bool set_mb_entrywrd(int num_ofbuff,long mem_b_address);
extern bool set_mb_entrywr(int num_ofbuff,long mem_b_address);
extern bool set_mb_entrywwr(int num_ofbuff,long mem_b_address);
extern bool clr_mb_entryrd(int num_ofbuff,long mem_b_address);
extern bool clr_mb_entrywrd(int num_ofbuff,long mem_b_address);
extern bool clr_mb_entrywr(int num_ofbuff,long mem_b_address);
extern bool clr_mb_entrywwr(int num_ofbuff,long mem_b_address);

extern bool Init_buff();

#endif /* _LOCAL_BUFFER_MODELING_H */
