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
 * pipeline kernel
 *
 * pipeline simulate kernel module
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pl_kernel.h"
#include "print.h"
#include "list.h"
#include "options.h"
#include "convb.h"
#include "printINAddr.h"
#include "localBufferModeling.h"
#include "list.h"
#include "stackOP.h"
#include "ps_pipeline.h"
#include "ps_inst.h"
#include "print_error.h"
#include "pu.h"

 /* count dynamic instruction */
long d_ins_n = 0;

/* control the fetch unit ,0 show not fetch */
bool endfetch = 1;
/* 0 show to abandoned take in instruction */
bool endfetchdecode = 1;

/* record the number of ending loop */
int endloopnum=0;

/* Used to determine whether cycle data on mobile takes up to the next cycle, The default do not take up */
bool load_free_i1=1,store_free_i1=1,launch_free_i1=1,wb_free_i1=1,mov_free_i1=1,extvmov_free_i1=1;

/* instructions address inserted into the first array*/
void insert_headlist(long ins,bool ins_f)
{
	int i;
	for(i=fetch_num-1;i>0;i--)
	{
		buff_f_ins[i].buff_fetch_num=buff_f_ins[i-1].buff_fetch_num;
	}
	buff_f_ins[0].buff_fetch_num=ins;
}

/* Implement array element back one ,and clear array[0] */
bool array_back_n(ploprand* arry,int length)
{
	int i=0;
    for(i=0;i<length-1;i++)
	{
		arry[length-1-i]=arry[length-1-i-1];
	}
	arry[0].ex_ins=0;
	arry[0].is_exist_ins=0;
	memset(arry[0].op,0,sizeof(arry[0].op));
	return 1;
}

/* judge array is empty before index */
bool judge_array_empty(ploprand* arry,int index)
{
	int i;
	for(i=0;i<index;i++)
	{
		if(arry[i].is_exist_ins)
		{
			return 0;
		}
	}
	return 1;
}

/* look loop decoded success queue spare index */
int insert_loop_array(ploprand *loopI)
{
	int i_c = 0;
	for(;i_c<9;i_c++)
	{
		if(loopI[i_c].is_exist_ins == 1)
		{
			continue;
		}
		else
		{
			break;
		}
	}
	return i_c;
}

bool pl_fetch()
{
	if((plst.fetch_if1==STG_READY)&&(plst.decode_if0==STG_NRDY)&&(plst.fetch_st==STG_FREE)&&endfetch)
	{
		endfetchdecode = 1;
		int i=0;
		fetch_of_num_i0=0;
		//If a clock cycle is refers to the instruction of failure, to take that back to back in refers to the buffer//
		if(fetch_success == 0)
		{
			fetch_success=1;
			for(;i<fetch_f_num;i++)
			{
				decode_i0[i].opcode = ins[fetch_buff[i]].opcode;
				decode_i0[i].decode_ins = fetch_buff[i];
				decode_i0[i].op[0] = ins[fetch_buff[i]].op[0];
				decode_i0[i].op[1] = ins[fetch_buff[i]].op[1];
				decode_i0[i].op[2] = ins[fetch_buff[i]].op[2];
				decode_i0[i].op[3] = ins[fetch_buff[i]].op[3];
				/* Used to record refers to the number, used to solve the instruction file without enough instructions to fill the window */
				fetch_of_num_i0++;
			}
			memset(fetch_buff,0,sizeof(fetch_buff));/* reset the fetch failure buffer */
			fetch_f_num=0;
		}
	if(i<fetch_num)/* fetch queue is spare */
	{
		for(;i<fetch_num;i++)
		{
			if(fetch_n<ins_num)
			{
				decode_i0[i].opcode = ins[fetch_n].opcode;
     			decode_i0[i].decode_ins = fetch_n;
	    		decode_i0[i].op[0] = ins[fetch_n].op[0];
		    	decode_i0[i].op[1] = ins[fetch_n].op[1];
	    		decode_i0[i].op[2] = ins[fetch_n].op[2];
				decode_i0[i].op[3] = ins[fetch_n].op[3];
		    	fetch_n++;
				fetch_of_num_i0++;
			}
		}
	}
	plst.fetch_cycle=FETCH_CYCLE;
	plst.fetch_st=STG_BUSY;
	}
    return 1;
}

bool pl_load()
{
   if((plst.load_if1==STG_READY))
   {
       plst.load_cycle=LOAD_CYCLE;
       plst.load_st=STG_BUSY;
       //load_i1.op[0].op_r->state=RST_BUSY;

    }
    return 1;
}

bool pl_launch()
{
   if((plst.launch_if1==STG_READY))
   {
	   plst.launch_cycle=LAUNCH_CYCLE;
       plst.launch_st=STG_BUSY;
        //launch_i1.op[0].op_r->state=RST_BUSY;

    }
    return 1;
}

bool pl_wb()
{
	if((plst.wb_if1==STG_READY))
	{
		plst.wb_cycle=WB_CYCLE-1;
		plst.wb_st=STG_BUSY;
	}
	return 1;
}

bool pl_store()
{
   if((plst.store_if1==STG_READY))
   {
	   plst.store_cycle=STORE_CYCLE;
       plst.store_st=STG_BUSY;//store_i1.op[1].op_r->state=RST_BUSY;
    }
    return 1;
}

bool pl_mov()
{
	if((plst.mov_if1==STG_READY))
	{
		plst.mov_cycle=MOV_CYCLE;
		plst.mov_st=STG_BUSY;
	}
	return 1;
}

bool pl_extmov()
{
	if((plst.extmov_if1==STG_READY))
	{
		plst.extmov_cycle=EXTMOV_CYCLE;
		plst.extmov_st=STG_BUSY;
	}
	return 1;
}

bool pl_dmalr()
{
	if((plst.dmalr_if1==STG_READY)&&(plst.dmalr_st==STG_FREE))
	{
		plst.dmalr_cycle=DMALR_CYCLE;  //dmalr_i1.op[0].opd.type_DMA.length*dmalr_i1.op[0].opd.type_DMA.repetition-1;
		plst.dmalr_st=STG_BUSY;
	}
	return 1;
}

bool pl_dmalc()
{
	if((plst.dmalc_if1==STG_READY)&&(plst.dmalc_st==STG_FREE))
	{
		plst.dmalc_cycle=DMALC_CYCLE;  //dmalc_i1.op[0].opd.type_DMA.length*dmalc_i1.op[0].opd.type_DMA.repetition-1;
		plst.dmalc_st=STG_BUSY;
	}
	return 1;
}

bool pl_dmasr()
{
	if((plst.dmasr_if1==STG_READY)&&(plst.dmasr_st==STG_FREE))
	{
		plst.dmasr_cycle=DMASR_CYCLE;  //dmasr_i1.op[0].opd.type_DMA.length*dmasr_i1.op[0].opd.type_DMA.repetition-1;
		plst.dmasr_st=STG_BUSY;
	}
	return 1;
}

bool pl_dmasc()
{
	if((plst.dmasc_if1==STG_READY)&&(plst.dmasc_st==STG_FREE))
	{
		plst.dmasc_cycle=DMASC_CYCLE;  //dmasc_i1.op[0].opd.type_DMA.length*dmasc_i1.op[0].opd.type_DMA.repetition-1;
		plst.dmasc_st=STG_BUSY;
	}
	return 1;
}

bool pl_prodvm()
{
   if((plst.prodvm_if1==STG_READY))
   {
   	   plst.prodvm_cycle=PRODVM_CYCLE;
       plst.prodvm_st=STG_BUSY;  //prodvm_i1.op[0].op_r->state=RST_BUSY;    prodvm_i1.op[1].op_r->state=RST_BUSY;   prodvm_i1.op[2].op_r->state=RST_BUSY;

    }
    return 1;
}

bool pl_prodvmp()
{
	if((plst.prodvmp_if1==STG_READY))
   {
	   plst.prodvmp_cycle=PRODVMP_CYCLE;
       plst.prodvmp_st=STG_BUSY;  //prodvm_i1.op[0].op_r->state=RST_BUSY;    prodvm_i1.op[1].op_r->state=RST_BUSY;   prodvm_i1.op[2].op_r->state=RST_BUSY;

    }
	return 1;
}

bool pl_prodmv()
{
   if((plst.prodmv_if1==STG_READY))
   {
	   
	    plst.prodmv_cycle=PRODMV_CYCLE;
        plst.prodmv_st=STG_BUSY;  //prodmv_i1.op[0].op_r->state=RST_BUSY;
 //       prodmv_i1.op[1].op_r->state=RST_BUSY;
 //       prodmv_i1.op[2].op_r->state=RST_BUSY;

    }
    return 1;
}

bool pl_prodmvp()
{
	 if((plst.prodmvp_if1==STG_READY))
   {
		plst.prodmvp_cycle=PRODMVP_CYCLE;
        plst.prodmvp_st=STG_BUSY;  
    }
	return 1;
}

bool pl_prodvv()
{
   if((plst.prodvv_if1==STG_READY))
   {
    	plst.prodvv_cycle=PRODVV_CYCLE;
        plst.prodvv_st=STG_BUSY; // prodvv_i1.op[0].op_r->state=RST_BUSY; prodvv_i1.op[1].op_r->state=RST_BUSY; prodvv_i1.op[2].op_r->state=RST_BUSY;

    }
    return 1;
}

bool pl_prodvvp()
{
	if((plst.prodvvp_if1==STG_READY))
   {
        plst.prodvvp_cycle=PRODVVP_CYCLE;
        plst.prodvvp_st=STG_BUSY;

    }
	return 1;
}

bool pl_prodvvd()
{
   if((plst.prodvvd_if1==STG_READY))
   {
        plst.prodvvd_cycle=PRODVVD_CYCLE;
        plst.prodvvd_st=STG_BUSY;
    }
    return 1;
}

bool pl_addv()
{
   if((plst.addv_if1==STG_READY))
   {
        plst.addv_cycle=ADDV_CYCLE;
        plst.addv_st=STG_BUSY;
    }
    return 1;
}

bool pl_addm()
{
	if((plst.addm_if1==STG_READY))
   {
 	    plst.addm_cycle=ADDM_CYCLE;
        plst.addm_st=STG_BUSY;
    }
	return 1;
}

bool pl_subv()
{
	if((plst.subv_if1==STG_READY))
	{
		plst.subv_cycle=SUBV_CYCLE;
		plst.subv_st=STG_BUSY;
	}
	return 1;
}

bool pl_subm()
{
	if((plst.subm_if1==STG_READY))
	{
		plst.subm_cycle=SUBM_CYCLE;
		plst.subm_st=STG_BUSY;
	}
	return 1;
}

bool pl_sum()
{
	if((plst.sum_if1==STG_READY))
	{
		plst.sum_cycle=SUM_CYCLE;
		plst.sum_st=STG_BUSY;
	}
	return 1;
}

bool pl_max()
{
	if((plst.max_if1==STG_READY))
	{
		plst.max_cycle=MAX_CYCLE;
		plst.max_st=STG_BUSY;
	}
	return 1;
}

bool pl_scale()
{
	if((plst.scale_if1==STG_READY))
	{
		plst.scale_cycle=SCALE_CYCLE;
		plst.scale_st=STG_BUSY;
	}
	return 1;
}

bool pl_diff()
{
	if((plst.diff_if1==STG_READY))
	{
		plst.diff_cycle=DIFF_CYCLE;
		plst.diff_st=STG_BUSY;
	}
	return 1;
}

bool pl_randgen()
{
	if((plst.randgen_if1==STG_READY)&&(plst.randgen_st==STG_FREE))
	{
		plst.randgen_cycle=RANDGEN_CYCLE;
		plst.randgen_st=STG_BUSY;
	}
	return 1;
}

bool pl_probcmp()
{
	if((plst.probcmp_if1==STG_READY))
	{
		plst.probcmp_cycle=PROBCMP_CYCLE;
		plst.probcmp_st=STG_BUSY;
	}
	return 1;
}

bool pl_bias()
{
	if((plst.bias_if1==STG_READY))
	{
		plst.bias_cycle=BIAS_CYCLE;
		plst.bias_st=STG_BUSY;
	}
	return 1;
}

bool pl_act()
{
	if((plst.act_if1 == STG_READY))
	{
		plst.act_cycle=ACT_CYCLE;
		plst.act_st=STG_BUSY;
	}
	return 1;
}

bool pl_decode(decodeoprand** inssp)
{
	decodeoprand* inss = *inssp;
	if(isDecodeDelay==0)  //Implementation in delay period is not decode, direct output four bytes of the binary code, skip the decoding stage
	{
		if(plst.decode_if1==STG_READY)
	    {
			bool load_free_i0=1,store_free_i0=1,launch_free_i0=1,wb_free_i0=1,mov_free_i0=1,extvmov_free_i0=1;
			/* Explain instructions in a decoding cycle only allows one to perform */
			bool loadOnly=load_free_i1,storeOnly=store_free_i1,launchOnly=launch_free_i1,wbOnly=wb_free_i1,movOnly=mov_free_i1,extmovOnly=extvmov_free_i1;
		    /* 1 show to have decoded failure instructons */
			decode_end=0;
		    int i,j=0;
			/* count the number of decoded success instruction */
		    decode_v_num=0;
			/* mark operands whether ready */
		    bool op1_f,op2_f,op3_f,op4_f;

			/* mark endloop can decode ,1 show yes */
			bool endlpdeocde = 1;

			/* Used to distinguish endloop the previous instruction is outside or inside of 
			the cycle in the current loop, the default is inside */
			bool endlptobuffer = 1;
		  
			memset(buff_f_ins,0,sizeof(buff_f_ins));
	        for(i=0;i<decode_of_num_i1;i++)
		    {
				//If decoding instruction to specify insertion delay period and the pipeline time delay is allowed
		    	if((inss[i].decode_ins == delay_insAddr)&&allow_delay)
		    	{
		    		isDelay=1; //Used for synchronization is to set up delay cycle number
		    		break;
		    	}
		    	op1_f=0,op2_f=0,op3_f=0,op4_f=0;
		        switch(inss[i].opcode)
		    	{
				case LOOP_OPCODE:
					{
						int lpId;
						lpId = inss[i].op[0].opd.type_LPID.loopId;
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}

						if((plst.decode_st==STG_FREE)&&(loopEndById(lpId)))
						{
							delStateLP(lpId);
							//rtlMaxWord=rtlMaxWord+loopWordConsumed;
							int lp_i0_num = insert_loop_array(loop_i0);
							loop_i0[lp_i0_num].is_exist_ins = 1;
							loop_i0[lp_i0_num].ex_ins = inss[i].decode_ins;
							++decode_v_num,inss[i].decode_v = 1;
							plst.loop_if0 = STG_READY;

							int iterLP;
							long addr1,strd1,addr2,strd2,addr3,strd3,lpaddr;
							iterLP = inss[i].op[0].opd.type_LPID.iterTimes;
							if(lpId != 0)
							{
								addr1 = inss[i].op[1].opd.type_LPAD.addr + stateLP[lpId-1].lpnext->addr1;
								strd1 = inss[i].op[1].opd.type_LPAD.stride;
								addr2 = inss[i].op[2].opd.type_LPAD.addr + stateLP[lpId-1].lpnext->addr2;
								strd2 = inss[i].op[2].opd.type_LPAD.stride;
								addr3 = inss[i].op[3].opd.type_LPAD.addr + stateLP[lpId-1].lpnext->addr3;
								strd3 = inss[i].op[3].opd.type_LPAD.stride;
							}
							else
							{
								addr1 = inss[i].op[1].opd.type_LPAD.addr;
								strd1 = inss[i].op[1].opd.type_LPAD.stride;
								addr2 = inss[i].op[2].opd.type_LPAD.addr;
								strd2 = inss[i].op[2].opd.type_LPAD.stride;
								addr3 = inss[i].op[3].opd.type_LPAD.addr;
								strd3 = inss[i].op[3].opd.type_LPAD.stride;
							}
							lpaddr = inss[i].decode_ins;

							addSateLP(lpId,iterLP,addr1,strd1,addr2,strd2,addr3,strd3,lpaddr);

							curlpRV.endlpaddr = 0;
							curlpRV.lpid = lpId;
						}
						else
						{
							//buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
							++decode_v_num;
						}
						break;
					} 
				case ENDLOOP_OPCODE:
					{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
						int lpId = inss[i].op[0].opd.endloopid;
						long endlpaddr = inss[i].decode_ins;
						//setEndlpAddr(lpId,endlpaddr);
						if((plst.decode_st==STG_FREE)&&endlpdeocde&&setEndlpAddr(lpId,endlpaddr))
						{
							
							int lp_i0_num = insert_loop_array(endloop_i0);
							endloop_i0[lp_i0_num].is_exist_ins = 1;
							endloop_i0[lp_i0_num].ex_ins = inss[i].decode_ins;
							++decode_v_num,inss[i].decode_v = 1;
							
							plst.endloop_if0 = STG_READY;

							curlpRV.endlpaddr = endlpaddr;
							curlpRV.lpid = lpId;

							if(subIterLP(lpId))
							{
								modOverLP(lpId,1);
								endloopnum++;
								fetch_n = inss[i].decode_ins + 1;
								plst.fetch_if0=STG_READY;
								endfetch=1;
							}
							else
							{
								endlpaddrst(lpId);
								fetch_n = stateLP[lpId].lpnext->lpaddr + 1;
								plst.fetch_if0=STG_READY;
								endfetch=1;
							}
							
						}
						else
						{
							if((endlpdeocde == 0)&&endlptobuffer&&setEndlpAddr(lpId,endlpaddr))
							{
								curlpRV.endlpaddr = endlpaddr;
								curlpRV.lpid = lpId;
								setEndlpAddr(lpId,endlpaddr);
								buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
								endfetch=0;
								endfetchdecode=0;
							}
							else
							{
								++decode_v_num;
							}
						}
						break;
					}
		    	case LOAD_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
						int bufferId;
						long inndaddr;
						if(inss[i].op[3].opd.indirctFlag)
						{
							bufferId = inss[i].op[2].opd.type_INDD.bufferId;
							int loopId = inss[i].op[2].opd.type_INDD.loopId;
							int addrId = inss[i].op[2].opd.type_INDD.addrId;
							int offset = inss[i].op[2].opd.type_INDD.offset;
							inndaddr = offset + getADDR(loopId,addrId);
							inss[i].op[2].opd.type_BUFF.buff_id = bufferId;
							inss[i].op[2].opd.type_BUFF.mem_b_addr = inndaddr;
						}
		    			if(inss[i].op[0].type_flag==0)
		    			{
		    				if((jud_write(B,num_ofrg(inss[i],0,B))))
		    				{
		    					set_wr(B,num_ofrg(inss[i],0,B));
		    					set_wwr(B,num_ofrg(inss[i],0,B));
		    					op1_f=1;
		    				}
		    				else
							{
		    					set_wwr(B,num_ofrg(inss[i],0,B));
							}
		    				int k=0,length=inss[i].op[1].opd.length;
		    				int buff_id=inss[i].op[2].opd.type_BUFF.buff_id;
		    				long buff_addr=inss[i].op[2].opd.type_BUFF.mem_b_addr;
		    				int row,col;row=buff_addr%MEM_BUFF_ENTRY_SIZE;col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    				if(buff_id==0)
		    				{
		    					if((jud_buffer_read(0)))
		    					{
									for(k=0;k<length;k++)
									{
										if(jud_mb_data_read(0,row,col+k))
										{
											set_mb_data_wrd(0,row,col+k);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(0,row,col+k);
										}
									}
		    					}
								else
								{
									op2_f=1;
									for(k=0;k<length;k++)
									{
										set_mb_data_wrd(0,row,col+k);
									}
								}
		    				}
		    				else if(buff_id==1)
		    				{
		    					if((jud_buffer_read(1)))
		    					{
		    						for(k=0;k<length;k++)
									{
										if(jud_mb_data_read(1,row,col+k))
										{
											set_mb_data_wrd(1,row,col+k);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(1,row,col+k);
										}
									}
		    					}
								else
								{
									op2_f=1;
									for(k=0;k<length;k++)
									{
										set_mb_data_wrd(1,row,col+k);
									}
								}
		    				}
		    				else if(buff_id==2)
		    				{
		    					if((jud_buffer_read(2)))
		    					{
		    						for(k=0;k<length;k++)
									{
										if(jud_mb_data_read(2,row,col+k))
										{
											set_mb_data_wrd(2,row,col+k);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(2,row,col+k);
										}
									}
		    					}
								else
								{
									op2_f=1;
									for(k=0;k<length;k++)
									{
										set_mb_data_wrd(2,row,col+k);
									}
								}
		    				}
		    				else
		    				{
		    					print_error_ex("use not exist buffer in load instruction.");
		    				}
							if(op2_f)
							{
								op2_f=0;
							}
							else
							{
								op2_f=1;
							}
		    			    if((plst.load_if0==STG_NRDY)&&loadOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    			    {
								if(!qGetD)
								{
									printAddr(buff_addr);
								}
								loadOnly=0;
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+loadWordConsumed;
								if(rtlMaxWord>4)
								{
									load_free_i0=0;
								}
		    			    	load_i0.ex_ins=inss[i].decode_ins;
								load_i0.is_exist_ins=1;
		    			    	load_i0.op[0]=inss[i].op[0];
		    			    	load_i0.op[1]=inss[i].op[1];
		    					load_i0.op[2]=inss[i].op[2];
								load_i0.op[3]=inss[i].op[3];
		    			    	plst.load_if0=STG_READY;
		    					if(buff_id==0)
		    					{
		    						set_buffer_read(0);
									for(k=0;k<length;k++)
									{
										set_mb_data_rd(0,row,col+k);
									}
		    					}
		    					else if(buff_id==1)
		    					{
		    						set_buffer_read(0);
									for(k=0;k<length;k++)
									{
										set_mb_data_rd(1,row,col+k);
									}
		    					}
		    					else
		    					{
		    						set_buffer_read(0);
									for(k=0;k<length;k++)
									{
										set_mb_data_rd(2,row,col+k);
									}
		    					}
		       					++decode_v_num,inss[i].decode_v=1;
		    			    }
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
								{
		    						clr_wr(B,num_ofrg(inss[i],0,B));
								}
		    					if(!loadOnly&&op1_f)
		    					{	
		    	    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	    				load_fwait_time++;				
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	    				load_wait_time++;	
		    					}
		    				}
		    		   	}
		    			else if(inss[i].op[0].type_flag==1)
		    			{
		    				if((jud_write(R,num_ofrg(inss[i],0,R))))
		    		  		{
		    					set_wr(R,num_ofrg(inss[i],0,R));
		    					set_wwr(R,num_ofrg(inss[i],0,R));
		    					op1_f=1;
		    		  		}
		    				else
							{
		    					set_wwr(R,num_ofrg(inss[i],0,R));
							}
		    				int k=0,length=inss[i].op[1].opd.length;
		    				int buff_id=inss[i].op[2].opd.type_BUFF.buff_id;
		    				long buff_addr=inss[i].op[2].opd.type_BUFF.mem_b_addr;
					
		    				int row,col;row=buff_addr%MEM_BUFF_ENTRY_SIZE;col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    				if(buff_id==0)
		    				{
		    					if((jud_buffer_read(0)))
		    					{
									for(k=0;k<length;k++)
									{
										if(jud_mb_data_read(0,row,col+k))
										{
											set_mb_data_wrd(0,row,col+k);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(0,row,col+k);
										}
									}
		    					}
								else
								{
									op2_f=1;
									for(k=0;k<length;k++)
									{
										set_mb_data_wrd(0,row,col+k);
									}
								}
		    				}
		    				else if(buff_id==1)
		    				{
		    					if((jud_buffer_read(1)))
		    					{
		    						for(k=0;k<length;k++)
									{
										if(jud_mb_data_read(1,row,col+k))
										{
											set_mb_data_wrd(1,row,col+k);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(1,row,col+k);
										}
									}
		    					}
								else
								{
									op2_f=1;
									for(k=0;k<length;k++)
									{
										set_mb_data_wrd(1,row,col+k);
									}
								}
		    				}
		    				else if(buff_id==2)
		    				{
		    					if((jud_buffer_read(2)))
		    					{
		    						for(k=0;k<length;k++)
									{
										if(jud_mb_data_read(2,row,col+k))
										{
											set_mb_data_wrd(2,row,col+k);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(2,row,col+k);
										}
									}
		    					}
								else
								{
									op2_f=1;
									for(k=0;k<length;k++)
									{
										set_mb_data_wrd(2,row,col+k);
									}
								}
		    				}
		    				else
		    				{
		    					print_error_ex("use not exist buffer in load instruction.");
		    				}
							if(op2_f)
							{
								op2_f=0;
							}
							else
							{
								op2_f=1;
							}
		    			    if((plst.load_if0==STG_NRDY)&&loadOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    				{
								if(allF || !qGetD)
								{
									printAddr(buff_addr);
								}
								loadOnly=0;
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+loadWordConsumed;
								if(rtlMaxWord>4)
								{
									load_free_i0=0;
								}
		    			    	load_i0.ex_ins=inss[i].decode_ins;
								load_i0.is_exist_ins=1;
		    			    	load_i0.op[0]=inss[i].op[0];
		    			    	load_i0.op[1]=inss[i].op[1];
		    					load_i0.op[2]=inss[i].op[2];
								load_i0.op[3]=inss[i].op[3];
		    			    	plst.load_if0=STG_READY;
		    					++decode_v_num;
		    					inss[i].decode_v=1;
		    					if(buff_id==0)
		    					{
		    						set_buffer_read(0);
									for(k=0;k<length;k++)
									{
										set_mb_data_rd(0,row,col+k);
									}
		    					}
		    					else if(buff_id==1)
		    					{
		    						set_buffer_read(0);
									for(k=0;k<length;k++)
									{
										set_mb_data_rd(1,row,col+k);
									}
		    					}
		    					else
		    					{
		    						set_buffer_read(0);
									for(k=0;k<length;k++)
									{
										set_mb_data_rd(2,row,col+k);
									}
		    					}
		    			    }
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
								{
		    						clr_wr(R,num_ofrg(inss[i],0,R));
								}
		    					if(!loadOnly&&op1_f)
		    					{
                                    buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					    load_fwait_time++;								
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    			    		load_wait_time++;
		    					}
		    					break;
		    				}
		    			}
		    			else
		    			{
		    			  if(jud_write(RD,num_ofrg(inss[i],0,R)))
		    		  		{
								endlptobuffer = 0;
		    					set_wwr(RD,num_ofrg(inss[i],0,R));
		    					set_wr(RD,num_ofrg(inss[i],0,R));
		    					op1_f=0;
		    		  		}
		    				else
							{
		    					set_wwr(RD,num_ofrg(inss[i],0,R));
						    }
		    			   int k=0,length=inss[i].op[1].opd.length;
		    				int buff_id=inss[i].op[2].opd.type_BUFF.buff_id;
		    				long buff_addr=inss[i].op[2].opd.type_BUFF.mem_b_addr;
							
		    				int row,col;row=buff_addr%MEM_BUFF_ENTRY_SIZE;col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    				if(buff_id==0)
		    				{
		    					if((jud_buffer_read(0)))
		    					{
									for(k=0;k<length;k++)
									{
										if(jud_mb_data_read(0,row,col+k))
										{
											set_mb_data_wrd(0,row,col+k);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(0,row,col+k);
										}
									}
		    					}
								else
								{
									op2_f=1;
									for(k=0;k<length;k++)
									{
										set_mb_data_wrd(0,row,col+k);
									}
								}
		    				}
		    				else if(buff_id==1)
		    				{
		    					if((jud_buffer_read(1)))
		    					{
		    						for(k=0;k<length;k++)
									{
										if(jud_mb_data_read(1,row,col+k))
										{
											set_mb_data_wrd(1,row,col+k);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(1,row,col+k);
										}
									}
		    					}
								else
								{
									op2_f=1;
									for(k=0;k<length;k++)
									{
										set_mb_data_wrd(1,row,col+k);
									}
								}
		    				}
		    				else if(buff_id==2)
		    				{
		    					if((jud_buffer_read(2)))
		    					{
		    						for(k=0;k<length;k++)
									{
										if(jud_mb_data_read(2,row,col+k))
										{
											set_mb_data_wrd(2,row,col+k);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(2,row,col+k);
										}
									}
		    					}
								else
								{
									op2_f=1;
									for(k=0;k<length;k++)
									{
										set_mb_data_wrd(2,row,col+k);
									}
								}
		    				}
		    				else
		    				{
		    					print_error_ex("use not exist buffer in load instruction.");
		    				}
							if(op2_f)
							{
								op2_f=0;
							}
							else
							{
								op2_f=1;
							}
		    			    if((plst.load_if0==STG_NRDY)&&loadOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    			    {
								if(allF || !qGetD)
								{
									printAddr(buff_addr);
								}
								loadOnly=0;
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+loadWordConsumed;
								if(rtlMaxWord>4)
								{
									load_free_i0=0;
								}
		    			    	load_i0.ex_ins=inss[i].decode_ins;
								load_i0.is_exist_ins=1;
		    			    	load_i0.op[0]=inss[i].op[0];
		    			    	load_i0.op[1]=inss[i].op[1];
		    					load_i0.op[2]=inss[i].op[2];
								load_i0.op[3]=inss[i].op[3];
		    			    	plst.load_if0=STG_READY;
		        				if(buff_id==0)
		    					{
		    						set_buffer_read(0);
									for(k=0;k<length;k++)
									{
										set_mb_data_rd(0,row,col+k);
									}
		    					}
		    					else if(buff_id==1)
		    					{
		    						set_buffer_read(0);
									for(k=0;k<length;k++)
									{
										set_mb_data_rd(1,row,col+k);
									}
		    					}
		    					else
		    					{
		    						set_buffer_read(0);
									for(k=0;k<length;k++)
									{
										set_mb_data_rd(2,row,col+k);
									}
		    					}
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    			    }
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
								{
		    						clr_wr(RD,num_ofrg(inss[i],0,R));
								}
								if(!loadOnly&&op1_f)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					    load_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    						load_wait_time++;
		    					}
		    				}
		    			}
		    			break;
		    	   }
		    	case LAUNCH_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
					
						int bufferId;
						long inndaddr;
						if(inss[i].op[2].opd.indirctFlag)
						{
							bufferId = inss[i].op[1].opd.type_INDD.bufferId;
							int loopId = inss[i].op[1].opd.type_INDD.loopId;
							int addrId = inss[i].op[1].opd.type_INDD.addrId;
							int offset = inss[i].op[1].opd.type_INDD.offset;
							inndaddr = offset + getADDR(loopId,addrId);
							inss[i].op[1].opd.type_BUFF.buff_id = bufferId;
							inss[i].op[1].opd.type_BUFF.mem_b_addr = inndaddr;
						}
		    			int mat_num;
		    			mat_num=inss[i].op[0].opd.type_MAT.mat_num;
		    			if((jud_M_write(mat_num)))
		    			{
		    				op1_f=1;
		    				set_M_wwr(mat_num);
		    				set_M_wr(mat_num);
		    			}
		    			else
		    			{
		    				set_M_wwr(mat_num);
		    			}
						int k,l;
		    			int buff_id=inss[i].op[1].opd.type_BUFF.buff_id;
						int row=inss[i].op[0].opd.type_MAT.row,col=0;
		    			long buff_addr=inss[i].op[1].opd.type_BUFF.mem_b_addr;
						
						int row_b=buff_addr%MEM_BUFF_ENTRY_SIZE;
	            		col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    	    	if(buff_id==0)
		    			{
		    				if((jud_buffer_read(0)))
		    				{
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										if(jud_mb_data_read(0,row_b,col+l))
										{
											set_mb_data_wrd(0,row_b,col+l);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(0,row_b,col+l);
										}
									}
									col=col+V_SIZE;
								}
		    				}
							else
							{
								op2_f=1;
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_wrd(0,row_b,col+l);
									}
									col=col+V_SIZE;
								}
							}
		    			}
		    			else if(buff_id==1)
		    			{
		    				if((jud_buffer_read(1)))
		    				{
		    					for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										if(jud_mb_data_read(1,row_b,col+l))
										{
											set_mb_data_wrd(1,row_b,col+l);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(1,row_b,col+l);
										}
									}
									col=col+V_SIZE;
								}
		    				}
							else
							{
								op2_f=1;
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_wrd(1,row_b,col+l);
									}
									col=col+V_SIZE;
								}
							}
		    			}
		    			else if(buff_id==2)
		    			{
		    				if((jud_buffer_read(2)))
		    				{
		    					for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										if(jud_mb_data_read(2,row_b,col+l))
										{
											set_mb_data_wrd(2,row_b,col+l);
										}
										else
										{
											op2_f=1;
											set_mb_data_wrd(2,row_b,col+l);
										}
									}
									col=col+V_SIZE;
								}
		    				}
							else
							{
								op2_f=1;
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_wrd(2,row_b,col+l);
									}
									col=col+V_SIZE;
								}
							}
		    			}
		    			else
		    			{
		    				print_error_ex("use not exist buffer. in launch");
		    			}
						if(op2_f)
						{
							op2_f=0;
						}
						else
						{
							op2_f=1;
						}
		    			if((plst.launch_if0==STG_NRDY)&&launchOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    			{
							if(allF || !qGetD)
							{
								printAddr(buff_addr);
							}
							launchOnly=0;
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+launchWordConsumed;
							if(rtlMaxWord>4)
							{
								launch_free_i0=0;
							}
		    				++decode_v_num,inss[i].decode_v=1;
		    				launch_i0.ex_ins=inss[i].decode_ins;
							launch_i0.is_exist_ins=1;
		    				launch_i0.op[0]=inss[i].op[0];
		    				launch_i0.op[1]=inss[i].op[1];
							launch_i0.op[2]=inss[i].op[2];
							launch_i0.op[3]=inss[i].op[3];
		    				plst.launch_if0=STG_READY;
							col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    				if(buff_id==0)
		    				{
		    			    	set_buffer_read(0);
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_rd(0,row_b,col+l);
									}
									col=col+V_SIZE;
								}
		    				}
		    				else if(buff_id==1)
		    				{
		    					set_buffer_read(1);
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_rd(1,row_b,col+l);
									}
									col=col+V_SIZE;
								}
		    				}
		    				else
		    				{
		    					set_buffer_read(2);
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_rd(2,row_b,col+l);
									}
									col=col+V_SIZE;
								}
		    				}
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
		    				{
		    					clr_M_wr(mat_num);
		    				}
		    				if(!launchOnly&&op1_f&&op2_f)
		    				{
		    					launch_fwait_time++;
		    					buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				}
		    				else
		    				{
		    					launch_wait_time++;
		    					buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				}
		    			}
		    			break;
		    		}
		    	case WB_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}

						int bufferId;
						long inndaddr;
						
						if(inss[i].op[2].opd.indirctFlag)
						{
							bufferId = inss[i].op[1].opd.type_INDD.bufferId;
							int loopId = inss[i].op[1].opd.type_INDD.loopId;
							int addrId = inss[i].op[1].opd.type_INDD.addrId;
							int offset = inss[i].op[1].opd.type_INDD.offset;
							inndaddr = offset + getADDR(loopId,addrId);
							inss[i].op[1].opd.type_BUFF.buff_id = bufferId;
							inss[i].op[1].opd.type_BUFF.mem_b_addr = inndaddr;
						}
		    			int mat_num=inss[i].op[0].opd.type_MAT.mat_num;
		    			set_M_wrd(mat_num);
		    			if((jud_M_read(mat_num)))
		    			{
		    				set_M_rd(mat_num);
		    				op1_f=1;
		    			}
		    			int k,l;
		    			int buff_id=inss[i].op[1].opd.type_BUFF.buff_id;
						int row=inss[i].op[0].opd.type_MAT.row,col=0;
		    			long buff_addr=inss[i].op[1].opd.type_BUFF.mem_b_addr;
						
						int row_b=buff_addr%MEM_BUFF_ENTRY_SIZE;
	            		col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    	    	if(buff_id==0)
		    			{
		    				if((jud_buffer_write(0)))
		    				{
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										if(jud_mb_data_write(0,row_b,col+l))
										{
											set_mb_data_wwr(0,row_b,col+l);
										}
										else
										{
											op2_f=1;
											set_mb_data_wwr(0,row_b,col+l);
										}
									}
									col=V_SIZE+col;
								}
		    				}
							else
							{
								op2_f=1;
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_wwr(0,row_b,col+l);
									}
									col=V_SIZE+col;
								}
							}
		    			}
		    			else if(buff_id==1)
		    			{
		    				if((jud_buffer_write(1)))
		    				{
		    					for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										if(jud_mb_data_write(1,row_b,col+l))
										{
											set_mb_data_wwr(1,row_b,col+l);
										}
										else
										{
											op2_f=1;
											set_mb_data_wwr(1,row_b,col+l);
										}
									}
									col=V_SIZE+col;
								}
		    				}
							else
							{
								op2_f=1;
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_wwr(1,row_b,col+l);
									}
									col=V_SIZE+col;
								}
							}
		    			}
		    			else if(buff_id==2)
		    			{
		    				if((jud_buffer_write(2)))
		    				{
		    					for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										if(jud_mb_data_write(2,row_b,col+l))
										{
											set_mb_data_wwr(2,row_b,col+l);
										}
										else
										{
											op2_f=1;
											set_mb_data_wwr(2,row_b,col+l);
										}
									}
									col=V_SIZE+col;
								}
		    				}
							else
							{
								op2_f=1;
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_wwr(2,row_b,col+l);
									}
									col=V_SIZE+col;
								}
							}
		    			}
		    			else
		    			{
		    				print_error_ex("use not exist buffer. in launch");
		    			}
						if(op2_f)
						{
							op2_f=0;
						}
						else
						{
							op2_f=1;
						}
		    			if((plst.wb_if0==STG_NRDY)&&wbOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    			{
							if(allF || !qGetD)
							{
								printAddr(buff_addr);
							}
							wbOnly=0;
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
							rtlMaxWord=rtlMaxWord+wbWordConsumed;
							if(rtlMaxWord>4)
							{
								wb_free_i0=0;
							}
		    				inss[i].decode_v=1;
		    				++decode_v_num,inss[i].decode_v=1;
		    				wb_i0.ex_ins=inss[i].decode_ins;
							wb_i0.is_exist_ins=1;
		    				wb_i0.op[0]=inss[i].op[0];
		    				wb_i0.op[1]=inss[i].op[1];
							wb_i0.op[2]=inss[i].op[2];
							wb_i0.op[3]=inss[i].op[3];
		    				plst.wb_if0=STG_READY;
							col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    				if(buff_id==0)
		    				{
		    			    	set_buffer_write(0);
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_wr(0,row_b,col+l);
									}
									col=V_SIZE+col;
								}
		    				}
		    				else if(buff_id==1)
		    				{
		    					set_buffer_write(1);
								for(k=0;k<row;k++)
								{
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_wr(1,row_b,col+l);
									}
									col=V_SIZE+col;
								}
		    				}
		    				else
		    				{
		    					set_buffer_write(2);
								for(k=0;k<row;k++)
								{
									col=k*V_SIZE;
									for(l=0;l<V_SIZE;l++)
									{
										set_mb_data_wr(2,row_b,col+l);
									}
								}
		    				}
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
		    				{
		    					clr_M_rd(mat_num);
		    				}
		    			//	if(op2_f)
		    				//{
		    				//	clr_mbwr(buff_id,buff_addr);
		    				//}
		    				if(!launchOnly&&op1_f&&op2_f)
		    				{
		    					wb_fwait_time++;
		    					buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				}
		    				else
		    				{
		    					wb_wait_time++;
		    					buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				}
		    			}
		    			break;
		    		}
		    	case STORE_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
						
						int bufferId;
						long inndaddr;
						if(inss[i].op[3].opd.indirctFlag)
						{
							bufferId = inss[i].op[2].opd.type_INDD.bufferId;
							int loopId = inss[i].op[2].opd.type_INDD.loopId;
							int addrId = inss[i].op[2].opd.type_INDD.addrId;
							int offset = inss[i].op[2].opd.type_INDD.offset;
							inndaddr = offset + getADDR(loopId,addrId);
							inss[i].op[2].opd.type_BUFF.buff_id = bufferId;
							inss[i].op[2].opd.type_BUFF.mem_b_addr = inndaddr;
						}
		    			int k=0,length=inss[i].op[1].opd.length;
		    			int buff_id=inss[i].op[2].opd.type_BUFF.buff_id;
		    			long buff_addr=inss[i].op[2].opd.type_BUFF.mem_b_addr;
						
		    			int row,col;row=buff_addr%MEM_BUFF_ENTRY_SIZE;col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    			if(buff_id==0)
		    			{
		    				if((jud_buffer_write(0)))
		    				{
								for(k=0;k<length;k++)
								{
									if(jud_mb_data_write(0,row,col+k))
									{
										set_mb_data_wwr(0,row,col+k);
									}
									else
									{
										set_mb_data_wwr(0,row,col+k);
										op1_f=1;
									}
								}
		    				}
							else
							{
								op1_f=1;
								for(k=0;k<length;k++)
								{
									set_mb_data_wwr(0,row,col+k);
								}
							}
		    			}
		    			else if(buff_id==1)
		    			{
		    				if((jud_buffer_write(1)))
		    				{
								for(k=0;k<length;k++)
								{
									if(jud_mb_data_write(1,row,col+k))
									{
										set_mb_data_wwr(1,row,col+k);
									}
									else
									{
										set_mb_data_wwr(1,row,col+k);
										op1_f=1;
									}
								}
		    				}
							else
							{
								op1_f=1;
								for(k=0;k<length;k++)
								{
									set_mb_data_wwr(1,row,col+k);
								}
							}
		    			}
		    			else if(buff_id==2)
		    			{
		    				if((jud_buffer_write(2)))
		    				{
								for(k=0;k<length;k++)
								{
									if(jud_mb_data_write(2,row,col+k))
									{
										set_mb_data_wwr(2,row,col+k);
									}
									else
									{
										set_mb_data_wwr(2,row,col+k);
										op1_f=1;
									}
								}
							}
							else
							{
								op1_f=1;
								for(k=0;k<length;k++)
								{
									set_mb_data_wwr(2,row,col+k);
								}
							}
		    			}
		    			else
		    			{
		    				print_error_ex("use not exist buffer. in wb");
		    			}
						if(op1_f)
						{
							op1_f=0;
						}
						else
						{
							op1_f=1;
						}
		    			if(inss[i].op[0].type_flag==0)
		    			{
		    				set_wrd(B,num_ofrg(inss[i],0,B));
		    				if((jud_read(B,num_ofrg(inss[i],0,B))))
		    				{
		    					op2_f=1;
		    				}
		    				if((plst.store_if0==STG_NRDY)&&storeOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    				{
								if(allF || !qGetD)
								{
									printAddr(buff_addr);
								}
								storeOnly=0;
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+storeWordConsumed;
								if(rtlMaxWord>4)
								{
									store_free_i0=0;
								}
		    					store_i0.ex_ins=inss[i].decode_ins;
								store_i0.is_exist_ins=1;
		    					store_i0.op[0]=inss[i].op[0];
		    					store_i0.op[1]=inss[i].op[1];
		    					store_i0.op[2]=inss[i].op[2];
								store_i0.op[3]=inss[i].op[3];
		    					plst.store_if0=STG_READY;
		    					set_rd(B,num_ofrg(inss[i],0,B));
		    			 		if(buff_id==0)
		    		        	{
		    		        		set_buffer_write(0);
									for(k=0;k<length;k++)
						    		{
										set_mb_data_wr(0,row,col+k);
									}
								}
		    		        	else if(buff_id==1)
		    		         	{
		    		        		set_buffer_write(1);
									for(k=0;k<length;k++)
						    		{
										set_mb_data_wr(1,row,col+k);
									}
		    		         	}
		    		        	else if(buff_id==2)
		    		        	{
		    		        		set_buffer_write(2);
									for(k=0;k<length;k++)
						    		{
										set_mb_data_wr(2,row,col+k);
									}
		    	    	    	}
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(!storeOnly&&op1_f&&op2_f)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    						store_fwait_time++;
		    					}
		    					else
		    					{
		    						store_wait_time++;
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					}
		    				}
		    			}
		    			else if(inss[i].op[0].type_flag==1)
		    			{
		    				set_wrd(R,num_ofrg(inss[i],0,R));
		    				if((jud_read(R,num_ofrg(inss[i],0,R))))
		    				{
		    					op2_f=1;
		    				}
		    				if((plst.store_if0==STG_NRDY)&&storeOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    				{
								if(allF || !qGetD)
								{
									printAddr(buff_addr);
								}
								storeOnly=0;
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+storeWordConsumed;
								if(rtlMaxWord>4)
								{
									store_free_i0=0;
								}
		    					store_i0.ex_ins=inss[i].decode_ins;
								store_i0.is_exist_ins=1;
		    					store_i0.op[0]=inss[i].op[0];
		    					store_i0.op[1]=inss[i].op[1];
		    					store_i0.op[2]=inss[i].op[2];
								store_i0.op[3]=inss[i].op[3];
		    					plst.store_if0=STG_READY;
		    					set_rd(R,num_ofrg(inss[i],0,R));
		    					if(buff_id==0)
		    		        	{
		    		        		set_buffer_write(0);
									for(k=0;k<length;k++)
						    		{
										set_mb_data_wr(0,row,col+k);
									}
								}
		    		        	else if(buff_id==1)
		    		         	{
		    		        		set_buffer_write(1);
									for(k=0;k<length;k++)
						    		{
										set_mb_data_wr(1,row,col+k);
									}
		    		         	}
		    		        	else if(buff_id==2)
		    		        	{
		    		        		set_buffer_write(2);
									for(k=0;k<length;k++)
						    		{
										set_mb_data_wr(2,row,col+k);
									}
		    	    	    	}
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(!storeOnly&&op1_f&&op2_f)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					    store_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					    store_wait_time++;
		    					}
		    					break;
		    				}
		    			}
		    			else
		    			{
		    				set_wrd(RD,num_ofrg(inss[i],0,R));
		    				if((jud_read(RD,num_ofrg(inss[i],0,R))))
		    				{
		    					op2_f=1;
		    				}
		    				if((plst.store_if0==STG_NRDY)&&storeOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    				{
								if(allF || !qGetD)
								{
									printAddr(buff_addr);
								}
								storeOnly=0;
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+storeWordConsumed;
								if(rtlMaxWord>4)
								{
									store_free_i0=0;
								}
		    					store_i0.ex_ins=inss[i].decode_ins;
								store_i0.is_exist_ins=1;
		    					store_i0.op[0]=inss[i].op[0];
		    					store_i0.op[1]=inss[i].op[1];
		    					store_i0.op[2]=inss[i].op[2];
								store_i0.op[3]=inss[i].op[3];
		    					plst.store_if0=STG_READY;
		    					set_rd(RD,num_ofrg(inss[i],0,R));
		    					if(buff_id==0)
		    		        	{
		    		        		set_buffer_write(0);
									for(k=0;k<length;k++)
						    		{
										set_mb_data_wr(0,row,col+k);
									}
								}
		    		        	else if(buff_id==1)
		    		         	{
		    		        		set_buffer_write(1);
									for(k=0;k<length;k++)
						    		{
										set_mb_data_wr(1,row,col+k);
									}
		    		         	}
		    		        	else if(buff_id==2)
		    		        	{
		    		        		set_buffer_write(2);
									for(k=0;k<length;k++)
						    		{
										set_mb_data_wr(2,row,col+k);
									}
		    	    	    	}
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(!storeOnly&&op1_f&&op2_f)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					    store_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					    store_wait_time++;
		    					}
		    				}
		    			}
		    			break;
		    		}
		    	case MOV_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if(inss[i].op[0].type_flag==0)
		    			{
		    				if((jud_write(B,num_ofrg(inss[i],0,B))))
		    				{
		    					set_wwr(B,num_ofrg(inss[i],0,B));
		    					op1_f=1;
		    				}
		    				else
							{
		    					set_wwr(B,num_ofrg(inss[i],0,B));
							}
		    				if(inss[i].op[1].type_flag==0)
		    				{
		    					if(num_ofrg(inss[i],1,B)!=num_ofrg(inss[i],0,B))
		    					{
		    						set_wrd(B,num_ofrg(inss[i],1,B));
		    						if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				    	{
		    			    			op2_f=1;
		    			    		}
		    					}
		    					else
								{
		    						op2_f=op1_f;
		    					}
		    					if((plst.mov_if0==STG_NRDY)&&movOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									movOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+movWordConsumed;
									if(rtlMaxWord>4)
									{
										mov_free_i0=0;
									}
		    						mov_i0.ex_ins=inss[i].decode_ins;
									mov_i0.is_exist_ins=1;
		    						mov_i0.op[0]=inss[i].op[0];
		    						mov_i0.op[1]=inss[i].op[1];
									mov_i0.op[2]=inss[i].op[2];
									mov_i0.op[3]=inss[i].op[3];
		    						plst.mov_if0=STG_READY;
		    						set_wr(B,num_ofrg(inss[i],0,B));
		    						set_rd(B,num_ofrg(inss[i],1,B));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!movOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag==1)
		    				{
		    					if((jud_read(R,num_ofrg(inss[i],1,R))))
		    					{
		    						op2_f=1;
		    						set_wrd(R,num_ofrg(inss[i],1,R));
		    					}
		    					else
								{
		    						set_wrd(R,num_ofrg(inss[i],1,R));
								}
		    					if((plst.mov_if0==STG_NRDY)&&movOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									movOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+movWordConsumed;
									if(rtlMaxWord>4)
									{
										mov_free_i0=0;
									}
		    						mov_i0.ex_ins=inss[i].decode_ins;
									mov_i0.is_exist_ins=1;
		    						mov_i0.op[0]=inss[i].op[0];
		    						mov_i0.op[1]=inss[i].op[1];
									mov_i0.op[2]=inss[i].op[2];
									mov_i0.op[3]=inss[i].op[3];
		    						plst.mov_if0=STG_READY;
		    						set_wr(B,num_ofrg(inss[i],0,B));
		    						set_rd(R,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!movOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_wait_time++;
		    						}
		    					}
		    				}
		    				else
		    				{
		    					if((jud_read(RD,num_ofrg(inss[i],1,R))))
		    					{
		    						set_wrd(RD,num_ofrg(inss[i],1,R));
		    						op2_f=1;
		    					}
		    					if((plst.mov_if0==STG_NRDY)&&movOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									movOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+movWordConsumed;
									if(rtlMaxWord>4)
									{
										mov_free_i0=0;
									}
		    						mov_i0.ex_ins=inss[i].decode_ins;
									mov_i0.is_exist_ins=1;
		    						mov_i0.op[0]=inss[i].op[0];
		    						mov_i0.op[1]=inss[i].op[1];
									mov_i0.op[2]=inss[i].op[2];
									mov_i0.op[3]=inss[i].op[3];
		    						plst.mov_if0=STG_READY;
		    						set_wr(B,num_ofrg(inss[i],0,B));
		    						set_rd(RD,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!movOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_wait_time++;
		    						}
		    					}
		    				}
		    			}
		    			else if(inss[i].op[0].type_flag==1)
		    			{
		    				if((jud_write(R,num_ofrg(inss[i],0,R))))
		    				{
		    					op1_f=1;
		    					set_wwr(R,num_ofrg(inss[i],0,R));
		    				}
		    				else
							{
		    					set_wwr(R,num_ofrg(inss[i],0,R));
							}
		    				if(inss[i].op[1].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],1,B));
		    					if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				    {
		    				    	op2_f=1;
		    		    		}
		    					if((plst.mov_if0==STG_NRDY)&&movOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									movOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+movWordConsumed;
									if(rtlMaxWord>4)
									{
										mov_free_i0=0;
									}
		    						mov_i0.ex_ins=inss[i].decode_ins;
									mov_i0.is_exist_ins=1;
		    						mov_i0.op[0]=inss[i].op[0];
		    						mov_i0.op[1]=inss[i].op[1];
									mov_i0.op[2]=inss[i].op[2];
									mov_i0.op[3]=inss[i].op[3];
		    						plst.mov_if0=STG_READY;
		    						set_wr(R,num_ofrg(inss[i],0,R));
		    						set_rd(B,num_ofrg(inss[i],1,B));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!movOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag==1)
		    				{
		    					int tmp=num_ofrg(inss[i],1,R);
		    					int tnmp=jud_read(R,tmp);
		    					if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    					{
		    						set_wrd(R,num_ofrg(inss[i],1,R));
		    						if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		    	    	{
		    		     		    	op2_f=1;
		    		        		}
		    					}
		    					else
								{
		    						op2_f=op1_f;
								}
		    					if((plst.mov_if0==STG_NRDY)&&movOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									movOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+movWordConsumed;
									if(rtlMaxWord>4)
									{
										mov_free_i0=0;
									}
		    						mov_i0.ex_ins=inss[i].decode_ins;
									mov_i0.is_exist_ins=1;
		    						mov_i0.op[0]=inss[i].op[0];
		    						mov_i0.op[1]=inss[i].op[1];
									mov_i0.op[2]=inss[i].op[2];
									mov_i0.op[3]=inss[i].op[3];
		    						plst.mov_if0=STG_READY;
		    						set_wr(R,num_ofrg(inss[i],0,R));
		    						set_rd(R,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!movOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_wait_time++;
		    						}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(RD,num_ofrg(inss[i],1,R));
		    					if((jud_read(RD,num_ofrg(inss[i],1,R))))
		    			    	{
		    				    	op2_f=1;
		    		    		}
		    					if((plst.mov_if0==STG_NRDY)&&movOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									movOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+movWordConsumed;
									if(rtlMaxWord>4)
									{
										mov_free_i0=0;
									}
		    						mov_i0.ex_ins=inss[i].decode_ins;
									mov_i0.is_exist_ins=1;
		    						mov_i0.op[0]=inss[i].op[0];
		    						mov_i0.op[1]=inss[i].op[1];
									mov_i0.op[2]=inss[i].op[2];
									mov_i0.op[3]=inss[i].op[3];
		    						plst.mov_if0=STG_READY;
		    						set_wr(R,num_ofrg(inss[i],0,R));
		    						set_rd(RD,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!movOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_wait_time++;
		    						}
		    					}
		    				}
		    			}
		    			else
		    			{
		    				if((jud_write(RD,num_ofrg(inss[i],0,R))))
		    				{
		    					op1_f=1;
		    					set_wwr(RD,num_ofrg(inss[i],0,R));
		    				}
		    				else
							{
		    					set_wwr(RD,num_ofrg(inss[i],0,R));
							}
		    				if(inss[i].op[1].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],1,B));
		    					if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				    {
		    			    		op2_f=1;
		    	    			}
		    					if((plst.mov_if0==STG_NRDY)&&movOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									movOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+movWordConsumed;
									if(rtlMaxWord>4)
									{
										mov_free_i0=0;
									}
		    						mov_i0.ex_ins=inss[i].decode_ins;
									mov_i0.is_exist_ins=1;
		    						mov_i0.op[0]=inss[i].op[0];
		    						mov_i0.op[1]=inss[i].op[1];
									mov_i0.op[2]=inss[i].op[2];
									mov_i0.op[3]=inss[i].op[3];
		    						plst.mov_if0=STG_READY;
		    						set_wr(RD,num_ofrg(inss[i],0,R));
		    						set_rd(B,num_ofrg(inss[i],1,B));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!movOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag==1)
		    				{
		    					set_wrd(R,num_ofrg(inss[i],1,R));
		    					if((jud_read(R,num_ofrg(inss[i],1,R))))
		    				    {
		    			    		op2_f=1;
		    	    			}
		    					if((plst.mov_if0==STG_NRDY)&&movOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									movOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+movWordConsumed;
									if(rtlMaxWord>4)
									{
										mov_free_i0=0;
									}
		    						mov_i0.ex_ins=inss[i].decode_ins;
									mov_i0.is_exist_ins=1;
		    						mov_i0.op[0]=inss[i].op[0];
		    						mov_i0.op[1]=inss[i].op[1];
									mov_i0.op[2]=inss[i].op[2];
									mov_i0.op[3]=inss[i].op[3];
		    						plst.mov_if0=STG_READY;
		    						set_wr(RD,num_ofrg(inss[i],0,R));
		    						set_rd(R,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!movOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_wait_time++;
		    						}
		    					}
		    				}
		    				else
		    				{
		    					if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    					{
		    						set_wrd(RD,num_ofrg(inss[i],1,R));
		    						if((jud_read(RD,num_ofrg(inss[i],1,R))))
		    		    		    {
		    		    	    		op1_f=1;
		    	        			}
		    					}
		    					else
								{
		    						op2_f=op1_f;
								}
		    					if((plst.mov_if0==STG_NRDY)&&movOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									movOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+movWordConsumed;
									if(rtlMaxWord>4)
									{
										mov_free_i0=0;
									}
		    						mov_i0.ex_ins=inss[i].decode_ins;
									mov_i0.is_exist_ins=1;
		    						mov_i0.op[0]=inss[i].op[0];
		    						mov_i0.op[1]=inss[i].op[1];
									mov_i0.op[2]=inss[i].op[2];
									mov_i0.op[3]=inss[i].op[3];
		    						plst.mov_if0=STG_READY;
		    						set_wr(RD,num_ofrg(inss[i],0,R));
		    						set_rd(RD,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!movOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        mov_wait_time++;
		    						}
		    					}
		    				}
		    			}
		    			break;
		    		}
		    	case EXTMOV_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if(inss[i].op[0].type_flag==0)
		    			{
		    				if((jud_write(B,num_ofrg(inss[i],0,B))))
		    				{
		    					op1_f=1;
		    					set_wwr(B,num_ofrg(inss[i],0,B));
		    				}
		    				else
							{
		    					set_wwr(B,num_ofrg(inss[i],0,B));
							}
		    				if(inss[i].op[1].type_flag==0)
		    				{
		    					if(num_ofrg(inss[i],1,B)!=num_ofrg(inss[i],0,B))
		    					{
		    						set_wrd(B,num_ofrg(inss[i],1,B));
		    						if((jud_read(B,num_ofrg(inss[i],1,B))))
		    			    		{
		    		    				op2_f=1;
		    		    			}
		    					}
		    					else
								{
		    						op2_f=op1_f;
								}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(B,num_ofrg(inss[i],0,B));
		    						set_rd(B,num_ofrg(inss[i],1,B));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag==1)
		    				{
		    					set_wrd(R,num_ofrg(inss[i],1,R));
		    					if((jud_read(R,num_ofrg(inss[i],1,R))))
		    					{
		    						op2_f=1;
		    					}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(B,num_ofrg(inss[i],0,B));
		    						set_rd(R,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag == 2)
		    				{
		    					set_wrd(RD,num_ofrg(inss[i],1,R));
		    					if((jud_read(RD,num_ofrg(inss[i],1,R))))
		    					{
		    						op2_f=1;
		    					}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(B,num_ofrg(inss[i],0,B));
		    						set_rd(RD,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(EXT,num_ofrg(inss[i],1,R));
		    					if((jud_read(EXT,num_ofrg(inss[i],1,R))))
		    					{
		    						op2_f=1;
		    					}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(B,num_ofrg(inss[i],0,B));
		    						set_rd(EXT,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    			}
		    			else if(inss[i].op[0].type_flag==1)
		    			{
		    				int tmp=num_ofrg(inss[i],0,R);
		    				bool l1=RV->R_V[tmp].RD_S;
		    				bool l2=RV->R_V[tmp].WRD_S;
		    				bool l3=RV->R_V[tmp].WR_S;
		    				bool l4=RV->R_V[tmp].WWR_S;
		    				int tm=RV->writenum;
		    				if((jud_write(R,num_ofrg(inss[i],0,R))))
		    				{
		    					set_wwr(R,num_ofrg(inss[i],0,R));
		    					op1_f=1;
		    				}
		    				else
							{
		    					set_wwr(R,num_ofrg(inss[i],0,R));
							}
		    				if(inss[i].op[1].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],1,B));
		    					if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				    {
		    				    	op2_f=1;
		    		    		}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(R,num_ofrg(inss[i],0,R));
		    						set_rd(B,num_ofrg(inss[i],1,B));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag==1)
		    				{
		    					if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    					{
		    						set_wrd(R,num_ofrg(inss[i],1,R));
		    						if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		     	    	{
		    		    		    	op2_f=1;
		    		        		}
		    					}
		    					else
								{
		    						op2_f=op1_f;
								}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(R,num_ofrg(inss[i],0,R));
		    						set_rd(R,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag==2)
		    				{
		    					set_wrd(RD,num_ofrg(inss[i],1,R));
		    					if((jud_read(RD,num_ofrg(inss[i],1,R))))
		    			    	{
		    				    	op2_f=1;
		    		    		}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(R,num_ofrg(inss[i],0,R));
		    						set_rd(RD,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(EXT,num_ofrg(inss[i],1,R));
		    					if((jud_read(EXT,num_ofrg(inss[i],1,R))))
		    					{
		    						op2_f=1;
		    					}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(B,num_ofrg(inss[i],0,B));
		    						set_rd(EXT,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    			}
		    			else if(inss[i].op[0].type_flag==2)
		    			{
		    				if((jud_write(RD,num_ofrg(inss[i],0,R))))
		    				{
		    					set_wwr(RD,num_ofrg(inss[i],0,R));
		    					op1_f=1;
		    				}
		    				else
							{
		    					set_wwr(RD,num_ofrg(inss[i],0,R));
							}
		    				if(inss[i].op[1].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],1,B));
		    					if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				    {
		    			    		op2_f=1;
		    	    			}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(RD,num_ofrg(inss[i],0,R));
		    						set_rd(B,num_ofrg(inss[i],1,B));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag==1)
		    				{
		    					set_wrd(R,num_ofrg(inss[i],1,R));
		    					if((jud_read(R,num_ofrg(inss[i],1,R))))
		    				    {
		    			    		op2_f=1;
		    	    			}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(RD,num_ofrg(inss[i],0,R));
		    						set_rd(R,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag==2)
		    				{
		    					if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    					{
		    						set_wrd(RD,num_ofrg(inss[i],1,R));
		    						if((jud_read(RD,num_ofrg(inss[i],1,R))))
		    			    	    {
		    			        		op2_f=1;
		    	    			    }
		    					}
		    					else
								{
		    						op2_f=op1_f;
								}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(RD,num_ofrg(inss[i],0,R));
		    						set_rd(RD,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(EXT,num_ofrg(inss[i],1,R));
		    					if((jud_read(EXT,num_ofrg(inss[i],1,R))))
		    					{
		    						op2_f=1;
		    					}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(B,num_ofrg(inss[i],0,B));
		    						set_rd(EXT,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    			}
		    			else
		    			{
		    				if((jud_write(EXT,num_ofrg(inss[i],0,R))))
		    				{
		    					set_wwr(EXT,num_ofrg(inss[i],0,R));
		    					op1_f=1;
		    				}
		    				else
							{
		    					set_wwr(EXT,num_ofrg(inss[i],0,R));
							}
		    				if(inss[i].op[1].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],1,B));
		    					if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				    {
		    			    		op2_f=1;
		    	    			}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(EXT,num_ofrg(inss[i],0,R));
		    						set_rd(B,num_ofrg(inss[i],1,B));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag == 1)
		    				{
		    					set_wrd(R,num_ofrg(inss[i],1,R));
		    					if((jud_read(R,num_ofrg(inss[i],1,R))))
		    				    {
		    			    		op2_f=1;
		    	    			}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(EXT,num_ofrg(inss[i],0,R));
		    						set_rd(R,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else if(inss[i].op[1].type_flag == 2)
		    				{
		    					set_wrd(RD,num_ofrg(inss[i],1,R));
		    					if((jud_read(RD,num_ofrg(inss[i],1,R))))
		    				    {
		    			    		op2_f=1;
		    	    			}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(EXT,num_ofrg(inss[i],0,R));
		    						set_rd(RD,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    				else
		    				{
		    					if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    					{
		    						set_wrd(EXT,num_ofrg(inss[i],1,R));
		    				    	if((jud_read(EXT,num_ofrg(inss[i],1,R))))
		    				        {
		    			        		op2_f=1;
		    	    	    		}
		    					}
		    					else
								{
		    						op2_f=op1_f;
								}
		    					if((plst.extmov_if0==STG_NRDY)&&extmovOnly&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&(rtlMaxWord<RTL_A_WORD))
		    	     			{
									extmovOnly=0;
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+extmovWordConsumed;
									if(rtlMaxWord>4)
									{
										extvmov_free_i0=0;
									}
		    						extmov_i0.ex_ins=inss[i].decode_ins;
									extmov_i0.is_exist_ins=1;
		    						extmov_i0.op[0]=inss[i].op[0];
		    						extmov_i0.op[1]=inss[i].op[1];
									extmov_i0.op[2]=inss[i].op[2];
									extmov_i0.op[3]=inss[i].op[3];
		    						plst.extmov_if0=STG_READY;
		    						set_wr(EXT,num_ofrg(inss[i],0,R));
		    						set_rd(EXT,num_ofrg(inss[i],1,R));
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(!extmovOnly&&op1_f&&op2_f)
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_fwait_time++;
		    						}
		    						else
		    						{
		    							buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    					        extmov_wait_time++;
		    						}
		    					}
		    				}
		    			}
		    			break;
		    		}
		    	case DMALR_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
						long buff_addr;
                     	int repetition,buff_id;
                    	repetition = inss[i].op[0].opd.type_DMA.repetition;
	                    //stride = op.opd.type_DMA.stride;
                    	buff_id = inss[i].op[0].opd.type_DMA.buff_id;
                    	buff_addr = inss[i].op[0].opd.type_DMA.buff_addr;
                    	//mem_addrt = op.opd.type_DMA.mem_addr;
                    	int k,count;
						int row,col=0;
		    			buff_id=inss[i].op[0].opd.type_DMA.buff_id;
						row=buff_addr%MEM_BUFF_ENTRY_SIZE;
	            		col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    			if(buff_id==0)
		    			{
		    				if((jud_buffer_write(0)))
		    	    		{
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										if(jud_mb_data_write(0,row,col+k))
										{
											set_mb_data_wwr(0,row,col+k);
										}
										else
										{
											op1_f=1;
											set_mb_data_wwr(0,row,col+k);
										}
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
							else
		    				{
		    					op1_f=1;
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wwr(0,row,col+k);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
		    			}
		    			else if(buff_id==1)
		    			{
		    				if((jud_buffer_write(1)))
		    	    		{
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										if(jud_mb_data_write(1,row,col+k))
										{
											set_mb_data_wwr(1,row,col+k);
										}
										else
										{
											op1_f=1;
											set_mb_data_wwr(1,row,col+k);
										}
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
							else
		    				{
		    					op1_f=1;
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wwr(1,row,col+k);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
		    			}
		    			else if(buff_id==2)
		    			{
		    				if((jud_buffer_write(2)))
		    	    		{
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										if(jud_mb_data_write(2,row,col+k))
										{
											set_mb_data_wwr(2,row,col+k);
										}
										else
										{
											op1_f=1;
											set_mb_data_wwr(2,row,col+k);
										}
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
							else
		    				{
		    					op1_f=1;
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wwr(2,row,col+k);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
		    			}
		    			else
		    			{
		    				print_error_ex("using not exist buffer in dmalr .");
		    			}
		    			if(op1_f)
						{
		    				op1_f=0;
						}
		    			else
						{
		    				op1_f=1;
						}
	        			if((plst.dmalr_if0==STG_NRDY)&&(plst.dmalr_st==STG_FREE)&&(plst.decode_st==STG_FREE)&&op1_f&&(rtlMaxWord<RTL_A_WORD)&&onlyDma)
		    		    {
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				onlyDma=0;
		    				rtlMaxWord=rtlMaxWord+dmalrWordConsumed;
		    		    	dmalr_i0.ex_ins=inss[i].decode_ins;
		    		    	dmalr_i0.op[0]=inss[i].op[0];
		    		    	plst.dmalr_if0=STG_READY;
							col=buff_addr/MEM_BUFF_ENTRY_SIZE;
		    				if(buff_id==0)
		    			   	{
								set_buffer_write(0);
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wr(0,row,col+k);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    			   	}
		    		    	else if(buff_id==1)
		    		   		{
		    		    		set_buffer_write(1);
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wr(1,row,col+k);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    		    	}
		    		    	else if(buff_id==2)
		    		    	{
		    			    	set_buffer_write(2);
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wr(2,row,col+k);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    		    	}
		    			   	else
		    			   	{
		    			    	print_error_ex("using not exist buffer in dmalr .");
		    			   	}
		       			    ++decode_v_num,inss[i].decode_v=1;
		    		    }
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(!onlyDma&&op1_f)
		    				{	
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	   				dmalr_fwait_time++;				
		    				}
		    				else
		    				{
		    					buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	   				dmalr_wait_time++;	
		    				}
		    			}
		    			break;
		    		}
		    	case DMALC_OPCODE:
		        	{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			int buff_id;
		    			buff_id=inss[i].op[0].opd.type_DMA.buff_id;
						long buff_addr;
                     	int repetition;
                    	repetition = inss[i].op[0].opd.type_DMA.repetition;
                    	buff_id = inss[i].op[0].opd.type_DMA.buff_id;
                    	buff_addr = inss[i].op[0].opd.type_DMA.buff_addr;
                    	int k,count;
						int row=0,col=0;
						row = buff_addr%MEM_BUFF_ENTRY_SIZE;col = buff_addr/MEM_BUFF_ENTRY_SIZE;
		    			if(buff_id==0)
		    			{
		    				if((jud_buffer_write(0)))
		    				{
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										if(jud_mb_data_write(0,row+k,col))
										{
											set_mb_data_wwr(0,row+k,col);
										}
										else
										{
											op1_f=1;
											set_mb_data_wwr(0,row+k,col);
										}
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
							}
							else
		    				{
		    					op1_f=1;
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wwr(0,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    				}
		    			}
		    			else if(buff_id==1)
		    			{
		    				if((jud_buffer_write(1)))
		    				{
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										if(jud_mb_data_write(1,row+k,col))
										{
											set_mb_data_wwr(1,row+k,col);
										}
										else
										{
											op1_f=1;
											set_mb_data_wwr(1,row+k,col);
										}
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
							}
							else
		    				{
		    					op1_f=1;
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wwr(1,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    				}
		    			}
		    			else if(buff_id==2)
		    			{
		    				if((jud_buffer_write(2)))
		    				{
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										if(jud_mb_data_write(2,row+k,col))
										{
											set_mb_data_wwr(2,row+k,col);
										}
										else
										{
											op1_f=1;
											set_mb_data_wwr(2,row+k,col);
										}
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
							}
							else
		    				{
		    					op1_f=1;
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wwr(2,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    				}
		    			}
		    			else
		    			{
		    				print_error_ex("using not exist buffer in dmalc .");
		    			}
		    			if(op1_f)
						{
		    				op1_f=0;
						}
		    			else
						{
		    				op1_f=1;
						}
	        			if((plst.dmalc_if0==STG_NRDY)&&(plst.dmalc_st==STG_FREE)&&(plst.decode_st==STG_FREE)&&op1_f&&(rtlMaxWord<RTL_A_WORD)&&onlyDma)
		    		    {
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				onlyDma=0;
		    				rtlMaxWord=rtlMaxWord+dmalcWordConsumed;
		    		    	dmalc_i0.ex_ins=inss[i].decode_ins;
		    		    	dmalc_i0.op[0]=inss[i].op[0];
		    		    	plst.dmalc_if0=STG_READY;
							row = buff_addr%MEM_BUFF_ENTRY_SIZE;col = buff_addr/MEM_BUFF_ENTRY_SIZE;
		    				if(buff_id==0)
		    			   	{
		    			    	set_buffer_write(0);
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wr(0,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    			   	}
		    			   	else if(buff_id==1)
		    		    	{
		    			   		set_buffer_write(1);
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wr(1,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    			   	}
		    			   	else if(buff_id==2)
		    			   	{
		    			    	set_buffer_write(2);
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wr(2,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    			   	}
		    			   	else
		    			   	{
		    			    	print_error_ex("using not exist buffer in dmalr .");
		    			   	}
		       				++decode_v_num,inss[i].decode_v=1;
		    		    }
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(!onlyDma&&op1_f)
		    				{	
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	   				dmalc_fwait_time++;				
		    				}
		    				else
		    				{
		    					buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	   				dmalc_wait_time++;	
		    				}
		    			}
		    			break;
		        	}
		    	case DMASR_OPCODE:
		        	{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			int k,l;
		    			int repetition;
						int buff_id;
		    			int row,col=0;
						long buff_addr=inss[i].op[0].opd.type_DMA.buff_addr;
		    			repetition=inss[i].op[0].opd.type_DMA.repetition;
		    			buff_id=inss[i].op[0].opd.type_DMA.buff_id;
						row = buff_addr%MEM_BUFF_ENTRY_SIZE;col = buff_addr/MEM_BUFF_ENTRY_SIZE;
		    			if(buff_id==0)
		    			{
		    				if((jud_buffer_read(0)))
		    				{
								for(k=0;k<repetition;k++)
								{
									for(l=0;l<MEM_BUFF_BOLCK_SIZE;l++)
									{
										if(jud_mb_data_read(0,row,col+l))
										{
											set_mb_data_wrd(0,row,col+l);
										}
										else
										{
											set_mb_data_wrd(0,row,col+l);
											op1_f=1;
										}
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
		    				else
		    				{
		    					op1_f=1;
								for(k=0;k<repetition;k++)
								{
									for(l=0;l<MEM_BUFF_BOLCK_SIZE;l++)
									{
										set_mb_data_wrd(0,row,col+l);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
		    			}
		    			else if(buff_id==1)
		    			{
		    				if((jud_buffer_read(1)))
		    				{
								for(k=0;k<repetition;k++)
								{
									for(l=0;l<MEM_BUFF_BOLCK_SIZE;l++)
									{
										if(jud_mb_data_read(1,row,col+l))
										{
											set_mb_data_wrd(1,row,col+l);
										}
										else
										{
											set_mb_data_wrd(1,row,col+l);
											op1_f=1;
										}
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
		    				else
		    				{
		    					op1_f=1;
								for(k=0;k<repetition;k++)
								{
									for(l=0;l<MEM_BUFF_BOLCK_SIZE;l++)
									{
										set_mb_data_wrd(1,row,col+l);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
		    			}
		    			else if(buff_id==2)
		    			{
		    				if((jud_buffer_read(2)))
		    				{
								for(k=0;k<repetition;k++)
								{
									for(l=0;l<MEM_BUFF_BOLCK_SIZE;l++)
									{
										if(jud_mb_data_read(2,row,col+l))
										{
											set_mb_data_wrd(2,row,col+l);
										}
										else
										{
											set_mb_data_wrd(2,row,col+l);
											op1_f=1;
										}
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
		    				else
		    				{
		    					op1_f=1;
								for(k=0;k<repetition;k++)
								{
									for(l=0;l<MEM_BUFF_BOLCK_SIZE;l++)
									{
										set_mb_data_wrd(2,row,col+l);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    				}
		    			}
		    			else
		    			{
		    				print_error_ex("using not exist buffer in dmasr .");
		    			}
		    			if(op1_f)
						{
		    				op1_f=0;
						}
		    			else
						{
		    				op1_f=1;
						}
	        			if((plst.dmasr_if0==STG_NRDY)&&(plst.dmasr_st==STG_FREE)&&(plst.decode_st==STG_FREE)&&op1_f&&(rtlMaxWord<RTL_A_WORD)&&onlyDma)
		    		    {
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				onlyDma=0;
		    				rtlMaxWord=rtlMaxWord+dmasrWordConsumed;
		    		    	dmasr_i0.ex_ins=inss[i].decode_ins;
		    		    	dmasr_i0.op[0]=inss[i].op[0];
		    		    	plst.dmasr_if0=STG_READY;
		        			//for(k=0;k<repetition;k++)
		    		    	//{
		        			//	for(l=0;l<length;l++)
		    	    		//	{
		    	    		//		set_mwr(mem_addr1);
		    		    	//	}
		    		    	//}
							row = buff_addr%MEM_BUFF_ENTRY_SIZE;col = buff_addr/MEM_BUFF_ENTRY_SIZE;
		    				if(buff_id==0)
		    			   	{
		    			   		set_buffer_read(0);
								for(k=0;k<repetition;k++)
								{
									for(l=0;l<MEM_BUFF_BOLCK_SIZE;l++)
									{
										set_mb_data_rd(0,row,col+l);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    			   	}
		    			   	else if(buff_id==1)
		    		    	{
		    			   		set_buffer_read(1);
								for(k=0;k<repetition;k++)
								{
									for(l=0;l<MEM_BUFF_BOLCK_SIZE;l++)
									{
										set_mb_data_rd(1,row,col+l);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    			   	}
		    			   	else if(buff_id==2)
		    			   	{
		    				   	set_buffer_read(2);
								for(k=0;k<repetition;k++)
								{
									for(l=0;l<MEM_BUFF_BOLCK_SIZE;l++)
									{
										set_mb_data_rd(2,row,col+l);
									}
									col=MEM_BUFF_BOLCK_SIZE+col;
								}
		    			   	}
		    			   	else
		    			   	{
		    			    	print_error_ex("using not exist buffer in dmasr .");
		    			   	}
		       				++decode_v_num,inss[i].decode_v=1;
		    		    }
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(!onlyDma&&op1_f)
		    				{	
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	   				dmasr_fwait_time++;				
		    				}
		    				else
		    				{
		    					buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	   				dmasr_wait_time++;	
		    				}
		    			}
		    			break;
		    		}
		    	case DMASC_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			int buff_id;
		    			buff_id=inss[i].op[0].opd.type_DMA.buff_id;
						long buff_addr;
                     	int repetition;
                    	repetition = inss[i].op[0].opd.type_DMA.repetition;
                    	buff_id = inss[i].op[0].opd.type_DMA.buff_id;
                    	buff_addr = inss[i].op[0].opd.type_DMA.buff_addr;
                    	int k,count;
						int row=0,col=0;
						row = buff_addr%MEM_BUFF_ENTRY_SIZE;col = buff_addr/MEM_BUFF_ENTRY_SIZE;
		    			if(buff_id==0)
		    			{
		    				if((jud_buffer_read(0)))
		    				{
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										if(jud_mb_data_read(0,row+k,col))
										{
											set_mb_data_wrd(0,row+k,col);
										}
										else
										{
											op1_f=1;
											set_mb_data_wrd(0,row+k,col);
										}
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
							}
							else
		    				{
		    					op1_f=1;
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wrd(0,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    				}
		    			}
		    			else if(buff_id==1)
		    			{
		    				if((jud_buffer_read(1)))
		    				{
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										if(jud_mb_data_read(1,row+k,col))
										{
											set_mb_data_wrd(1,row+k,col);
										}
										else
										{
											op1_f=1;
											set_mb_data_wrd(1,row+k,col);
										}
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
							}
							else
		    				{
		    					op1_f=1;
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wrd(1,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    				}
		    			}
		    			else if(buff_id==2)
		    			{
		    				if((jud_buffer_read(2)))
		    				{
		    					for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										if(jud_mb_data_read(2,row+k,col))
										{
											set_mb_data_wrd(2,row+k,col);
										}
										else
										{
											op1_f=1;
											set_mb_data_wrd(2,row+k,col);
										}
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
							}
							else
		    				{
		    					op1_f=1;
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_wrd(2,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    				}
		    			}
		    			else
		    			{
		    				print_error_ex("using not exist buffer in dmasc .");
		    			}
		    			if(op1_f)
						{
		    				op1_f=0;
						}
		    			else
						{
		    				op1_f=1;
						}
	        			if((plst.dmasc_if0==STG_NRDY)&&(plst.dmasc_st==STG_FREE)&&(plst.decode_st==STG_FREE)&&op1_f&&(rtlMaxWord<RTL_A_WORD)&&onlyDma)
		    		    {
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				onlyDma=0;
		    				rtlMaxWord=rtlMaxWord+dmascWordConsumed;
		    		    	dmasc_i0.ex_ins=inss[i].decode_ins;
		    		    	dmasc_i0.op[0]=inss[i].op[0];
		    		    	plst.dmasc_if0=STG_READY;
		    		   		row = buff_addr%MEM_BUFF_ENTRY_SIZE;col = buff_addr/MEM_BUFF_ENTRY_SIZE;
		    				if(buff_id==0)
		    			   	{
		    			    	set_buffer_read(0);
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_rd(0,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    			   	}
		    			   	else if(buff_id==1)
		    		    	{
		    			   		set_buffer_read(1);
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_rd(1,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    			   	}
		    			   	else if(buff_id==2)
		    			   	{
		    			    	set_buffer_read(2);
								for(count=0;count<repetition;count++)
								{
									for(k=0;k<MEM_BUFF_BOLCK_SIZE;k++)
									{
										set_mb_data_rd(2,row+k,col);
									}
									row=MEM_BUFF_BOLCK_SIZE+row;
								}
		    			   	}
		    			   	else
		    			   	{
		    			    	print_error_ex("using not exist buffer in dmasc .");
		    			   	}
		       				++decode_v_num,inss[i].decode_v=1;
		    		    }
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(!onlyDma&&op1_f)
		    				{	
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	   				dmasc_fwait_time++;				
		    				}
		    				else
		    				{
		    					buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	   				dmasc_wait_time++;	
		    				}
		    			}
		    			break;
		        	}
		    	case PRODVM_OPCODE:
		    	   {
					   if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
					   {
						   endlptobuffer = 0;
						   endlpdeocde = 0;
						   ++decode_v_num;
						   plst.fetch_if0=STG_NRDY;
						   break;
					   }
		        		if((jud_write(R,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    				set_wr(R,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
						}
		    			if(inss[i].op[1].type_flag==0)
		    			{
		    				set_wrd(B,num_ofrg(inss[i],1,B));
		    				if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				{
		    					set_rd(B,num_ofrg(inss[i],1,B));
		    					op2_f=1;
		    				}
		    				set_M_wrd(inss[i].op[2].opd.type_MAT.mat_num);
		    				if((jud_M_read(inss[i].op[2].opd.type_MAT.mat_num)))
		    				{
		    					set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					op3_f=1;
		    				}
		    				if(inss[i].op[3].opd.accumul)
		    				{
		    					set_B_wrd(R);
		    					if((jud_B_read(R)))
		    					{
		    						op4_f=1;
		    						set_B_rd(R);
		    					}
		    				}
		    				else
		    				{
		    					op4_f=1;
		    				}
		    				if((plst.prodvm_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&op4_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    				{
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+prodvmWordConsumed;
		    					prodvm_i0.ex_ins=inss[i].decode_ins;
								prodvm_i0.is_exist_ins=1;
		    					prodvm_i0.op[0]=inss[i].op[0];
		    					prodvm_i0.op[1]=inss[i].op[1];
		    					prodvm_i0.op[2]=inss[i].op[2];
		    					prodvm_i0.op[3]=inss[i].op[3];
		    					plst.prodvm_if0=STG_READY;
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    					isFreeNeuroUnit=noNeurCalcUnit;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
		    					{
		    						clr_wr(B,num_ofrg(inss[i],0,R));
		    					}
		    					if(op2_f)
		    					{
		    						clr_rd(B,num_ofrg(inss[i],1,B));
		    					}
		    					if(op3_f)
		    					{
		    						clr_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					}
		    					if(op4_f&&inss[i].op[3].opd.accumul)
		    					{
		    						clr_B_rd(R);
		    					}
		    					if(op1_f&&op2_f&&op3_f&&op4_f&&!isFreeNeuroUnit)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodvm_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodvm_wait_time++;
		    					}
		    				}
		    			}
		    			else
		    			{
		    				set_wrd(R,num_ofrg(inss[i],1,R));
		    				if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    				{
		    					if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		    		{
		    		    			set_rd(R,num_ofrg(inss[i],1,R));
		    		    			op2_f=1;
		    		    		}
		    				}
		    				else
		    				{
		    					if(op1_f)
		    					{
		    						set_rd(R,num_ofrg(inss[i],1,R));
		    					}
		    					op2_f=op1_f;
		    				}
		    				set_M_wrd(inss[i].op[2].opd.type_MAT.mat_num);
		    				if((jud_M_read(inss[i].op[2].opd.type_MAT.mat_num)))
		    				{
		    					set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					op3_f=1;
		    				}
		    				if(inss[i].op[3].opd.accumul)
		    				{
		    					set_B_wrd(R);
		    					if((jud_B_read(R)))
		    					{
		    						op4_f=1;
		    						set_B_rd(R);
		    					}
		    				}
		    				else
		    				{
		    					op4_f=1;
		    				}
		    				if((plst.prodvm_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&op4_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    				{
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+prodvmWordConsumed;
		    					prodvm_i0.ex_ins=inss[i].decode_ins;
								prodvm_i0.is_exist_ins=1;
		    					prodvm_i0.op[0]=inss[i].op[0];
		    					prodvm_i0.op[1]=inss[i].op[1];
		    					prodvm_i0.op[2]=inss[i].op[2];
		    					prodvm_i0.op[3]=inss[i].op[3];
		    					plst.prodvm_if0=STG_READY;
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    					isFreeNeuroUnit=noNeurCalcUnit;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
		    					{
		    						clr_wr(R,num_ofrg(inss[i],0,R));
		    					}
		    					if(op2_f)
		    					{
		    						clr_rd(R,num_ofrg(inss[i],1,R));
		    					}
		    					if(op3_f)
		    					{
		    						clr_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					}
		    					if(op4_f&&inss[i].op[3].opd.accumul)
		    					{
		    						clr_B_rd(R);
		    					}
		    					if(op1_f&&op2_f&&op3_f&&op4_f&&!isFreeNeuroUnit)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodvm_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodvm_wait_time++;
		    					}
		    				}
		    			}
		    			break;
		    		}
		    	case PRODVMP_OPCODE:
		    	    {
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if(inss[i].op[0].type_flag==0)
		    			{
		    				set_wrd(B,num_ofrg(inss[i],0,B));
		    				if((jud_read(B,num_ofrg(inss[i],0,B))))
		    				{
		    					set_rd(B,num_ofrg(inss[i],0,B));
		    					op1_f=1;
		    				}
		    				set_M_wrd(inss[i].op[1].opd.type_MAT.mat_num);
		    				if((jud_M_read(inss[i].op[1].opd.type_MAT.mat_num)))
		    				{
		    					set_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    					op2_f=1;
		    				}
		    				if((jud_B_write(R)))
		    				{
		    					op3_f=1;
		    					set_B_wwr(R);
		    					set_B_wr(R);
		    				}
		    				else
							{
		    					set_B_wwr(R);
							}
		    				if((plst.prodvmp_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    				{
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+prodvmpWordConsumed;
		    					prodvmp_i0.ex_ins=inss[i].decode_ins;
								prodvmp_i0.is_exist_ins=1;
		    					prodvmp_i0.op[0]=inss[i].op[0];
		    					prodvmp_i0.op[1]=inss[i].op[1];
		    					prodvmp_i0.op[2]=inss[i].op[2];
								prodvmp_i0.op[3]=inss[i].op[3];
		    					plst.prodvmp_if0=STG_READY;
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    					isFreeNeuroUnit=noNeurCalcUnit;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
		    					{
		    						clr_wr(B,num_ofrg(inss[i],0,R));
		    					}
		    					if(op2_f)
		    					{
		    						clr_rd(B,num_ofrg(inss[i],1,B));
		    					}
		    					if(op3_f)
		    					{
		    						clr_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					}
		    					if(op3_f)
		    					{
		    						clr_B_wr(R);
		    					}
		    					if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodvmp_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodvmp_wait_time++;
		    					}
		    				}
		    			}
		    			else
		    			{
		    				set_wrd(R,num_ofrg(inss[i],0,R));
		    				int tmp=jud_read(R,num_ofrg(inss[i],0,R));
		    				if((jud_read(R,num_ofrg(inss[i],0,R))))
		    				{
		    					set_rd(R,num_ofrg(inss[i],0,R));
		    					op1_f=1;
		    				}
		    				set_M_wrd(inss[i].op[1].opd.type_MAT.mat_num);
		    				if((jud_M_read(inss[i].op[1].opd.type_MAT.mat_num)))
		    				{
		    					set_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    					op2_f=1;
		    				}
		    				if((jud_B_write(R)))
		    				{
		    					op3_f=1;
		    					set_B_wr(R);
		    					set_B_wwr(R);
		    				}
		    				else
		    					set_B_wwr(R);
		    				if((plst.prodvmp_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    				{
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+prodvmpWordConsumed;
		    					prodvmp_i0.ex_ins=inss[i].decode_ins;
								prodvmp_i0.is_exist_ins=1;
		    					prodvmp_i0.op[0]=inss[i].op[0];
		    					prodvmp_i0.op[1]=inss[i].op[1];
		    					prodvmp_i0.op[2]=inss[i].op[2];
								prodvmp_i0.op[3]=inss[i].op[3];
		    					plst.prodvmp_if0=STG_READY;
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    					isFreeNeuroUnit=noNeurCalcUnit;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
		    					{
		    						clr_rd(R,num_ofrg(inss[i],0,R));
		    					}
		    					if(op2_f)
		    					{
		    						clr_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    					}
		    					if(op3_f)
		    					{
		    						clr_B_wr(R);
		    					}
		    					if(op1_f&&op2_f&&op3_f&&isFreeNeuroUnit)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodvmp_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodvmp_wait_time++;
		    					}
		    				}
		    			}
		    			break;
	        		}
		    	case PRODMV_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if((jud_write(R,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wr(R,num_ofrg(inss[i],0,R));
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
						}
		    			if(inss[i].op[1].type_flag==0)
		    			{
		    				set_wrd(B,num_ofrg(inss[i],1,B));
		    				if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				{
		    					set_rd(B,num_ofrg(inss[i],1,B));
		    					op2_f=1;
		    				}
		    				set_M_wrd(inss[i].op[2].opd.type_MAT.mat_num);
		    				if((jud_M_read(inss[i].op[2].opd.type_MAT.mat_num)))
		    				{
		    					set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					op3_f=1;
		    				}
		    				if(inss[i].op[3].opd.accumul)
		    				{
		    					set_B_wrd(C);
		    					if((jud_B_read(C)))
		    					{
		    						op4_f=1;
		    						set_B_rd(C);
		    					}
		    				}
		    				else
		    				{
		    					op4_f=1;
		    				}
		    				if((plst.prodmv_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&op4_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    				{
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+prodmvWordConsumed;
		    					prodmv_i0.ex_ins=inss[i].decode_ins;
								prodmv_i0.is_exist_ins=1;
		    					prodmv_i0.op[0]=inss[i].op[0];
		    					prodmv_i0.op[1]=inss[i].op[1];
		    					prodmv_i0.op[2]=inss[i].op[2];
		    					prodmv_i0.op[3]=inss[i].op[3];
		    					plst.prodmv_if0=STG_READY;
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    					isFreeNeuroUnit=noNeurCalcUnit;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
		    					{
		    						clr_wr(R,num_ofrg(inss[i],0,R));
		    					}
		    					if(op2_f)
		    					{
		    						clr_rd(B,num_ofrg(inss[i],1,B));
		    					}
		    					if(op3_f)
		    					{
		    						clr_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					}
		    					if(op4_f&&inss[i].op[3].opd.accumul)
		    					{
		    						clr_B_rd(C);
		    					}
		    					if(op1_f&&op2_f&&op3_f&&op4_f&&!isFreeNeuroUnit)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodmv_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				       prodmv_wait_time++;
		    					}
		    				}
		    			}
		    			else
		    			{
		    				set_wrd(R,num_ofrg(inss[i],1,R));
		    				if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    				{
		    					if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		    		{
		    		    			set_rd(R,num_ofrg(inss[i],1,R));
		    			    		op2_f=1;
		    		    		}
		    				}
		    				else
		    				{
		    					if(op1_f)
		    					{
		    						set_rd(R,num_ofrg(inss[i],1,R));
		    					}
		    					op2_f=op1_f;
		    				}
		    				set_M_wrd(inss[i].op[2].opd.type_MAT.mat_num);
							bool prodmv_boolMAT=jud_M_read(inss[i].op[2].opd.type_MAT.mat_num);
		    				if((jud_M_read(inss[i].op[2].opd.type_MAT.mat_num)))
		    				{
		    					set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					op3_f=1;
		    				}
		    				if(inss[i].op[3].opd.accumul)
		    				{
		    					set_B_wrd(C);
		    					if((jud_B_read(C)))
		    					{
		    						op4_f=1;
		    						set_B_rd(C);
		    					}
		    				}
		    				else
		    				{
		    					op4_f=1;
		    				}
		    				if((plst.prodmv_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&op4_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    				{
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+prodmvWordConsumed;
		    		     		prodmv_i0.ex_ins=inss[i].decode_ins;
								prodmv_i0.is_exist_ins=1;
		    					prodmv_i0.op[0]=inss[i].op[0];
		    					prodmv_i0.op[1]=inss[i].op[1];
		    					prodmv_i0.op[2]=inss[i].op[2];
		    					prodmv_i0.op[3]=inss[i].op[3];
		    					plst.prodmv_if0=STG_READY;
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    					isFreeNeuroUnit=noNeurCalcUnit;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
		    					{
		    						clr_wr(R,num_ofrg(inss[i],0,R));
		    					}
		    					if(op2_f)
		    					{
		    						clr_rd(R,num_ofrg(inss[i],1,R));
		    					}
		    				    if(op3_f)
		    					{
		    						clr_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					}
		    					if(op4_f&&inss[i].op[3].opd.accumul)
		    					{
		    						clr_B_rd(C);
		    					}
		    					if(op1_f&&op2_f&&op3_f&&op4_f&&!isFreeNeuroUnit)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodmv_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodmv_wait_time++;
		    					}
		    				}
		    			}
		    			break;
		    		}
		    	case PRODMVP_OPCODE:
		       	    {
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if(inss[i].op[0].type_flag==0)
		    			{
		    				set_wrd(B,num_ofrg(inss[i],0,B));
		    				if((jud_read(B,num_ofrg(inss[i],0,B))))
		    				{
		    					set_rd(B,num_ofrg(inss[i],0,B));
		    					op1_f=1;
		    				}
		    				set_M_wrd(inss[i].op[1].opd.type_MAT.mat_num);
		    				if((jud_M_read(inss[i].op[1].opd.type_MAT.mat_num)))
		    				{
		    					set_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    					op2_f=1;
		    				}
		    				if((jud_B_write(C)))
		    				{
		    					op3_f=1;
		    					set_B_wr(C);
		    					set_B_wwr(C);
		    				}
		    				else
							{
		    					set_B_wwr(C);
							}
		    				if((plst.prodmvp_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    				{
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+prodmvpWordConsumed;
		    					prodmvp_i0.ex_ins=inss[i].decode_ins;
								prodmvp_i0.is_exist_ins=1;
		    					prodmvp_i0.op[0]=inss[i].op[0];
		    					prodmvp_i0.op[1]=inss[i].op[1];
		    					prodmvp_i0.op[2]=inss[i].op[2];
								prodmvp_i0.op[3]=inss[i].op[3];
		    					plst.prodmvp_if0=STG_READY;
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    					isFreeNeuroUnit=noNeurCalcUnit;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
		    					{
		    						clr_rd(B,num_ofrg(inss[i],0,B));
		    					}
		    					if(op2_f)
		    					{
		    						clr_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    					}
		    					if(op3_f)
		    					{
		    						clr_B_wr(C);
		    					}
		    					if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodmvp_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				       prodmvp_wait_time++;
		    					}
		    				}
		    			}
		    			else
		    			{
		    				set_wrd(R,num_ofrg(inss[i],0,R));
		    				if((jud_read(R,num_ofrg(inss[i],0,R))))
		    				{
		    					set_rd(R,num_ofrg(inss[i],0,R));
		    					op1_f=1;
		    				}
		    				set_M_wrd(inss[i].op[1].opd.type_MAT.mat_num);
		    				if((jud_M_read(inss[i].op[1].opd.type_MAT.mat_num)))
		    				{
		    					set_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    					op2_f=1;
		    				}
		    				if((jud_B_write(C)))
		    				{
		    					op3_f=1;
		    					set_B_wr(C);
		    					set_B_wwr(C);
		    				}
		    				else
							{
		    					set_B_wwr(C);
							}
		    				if((plst.prodmvp_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    				{
		    					//convert_ins_to_b(inss[i],fp_saveRTLB);
		    					rtlMaxWord=rtlMaxWord+prodmvpWordConsumed;
		    		     		prodmvp_i0.ex_ins=inss[i].decode_ins;
								prodmvp_i0.is_exist_ins=1;
		    					prodmvp_i0.op[0]=inss[i].op[0];
		    					prodmvp_i0.op[1]=inss[i].op[1];
		    					prodmvp_i0.op[2]=inss[i].op[2];
								prodmvp_i0.op[3]=inss[i].op[3];
		    					plst.prodmvp_if0=STG_READY;
		    					++decode_v_num,inss[i].decode_v=1;
		    					inss[i].decode_v=1;
		    					isFreeNeuroUnit=noNeurCalcUnit;
		    				}
		    				else
		    				{
								if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
								{
									endlpdeocde = 0;
								}
		    					if(op1_f)
		    					{
		    						clr_rd(R,num_ofrg(inss[i],0,R));
		    					}
		    					if(op2_f)
		    					{
		    						clr_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    					}
		    				    if(op3_f)
		    					{
		    						clr_B_wr(C);
		    					}
		    					if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodmvp_fwait_time++;
		    					}
		    					else
		    					{
		    						buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				        prodmvp_wait_time++;
		    					}
		    				}
		    			}
		    			break;
		    		}
		    	case PRODVV_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if((jud_M_write(inss[i].op[0].opd.type_MAT.mat_num)))
		    			{
		    				set_M_wr(inss[i].op[0].opd.type_MAT.mat_num);
		    				set_M_wwr(inss[i].op[0].opd.type_MAT.mat_num);
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_M_wwr(inss[i].op[0].opd.type_MAT.mat_num);
						}
		    			if(inss[i].op[1].type_flag==0)
		    			{
		    				set_wrd(B,num_ofrg(inss[i],1,B));
		    				if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				{
		    					set_rd(B,num_ofrg(inss[i],1,B));
		    					op2_f=1;
		    				}
		    				if(inss[i].op[2].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],2,B));
		    					if(num_ofrg(inss[i],2,B)!=num_ofrg(inss[i],1,B))
		    					{
		    						bool j=jud_read(B,num_ofrg(inss[i],2,B));
		    						if((jud_read(B,num_ofrg(inss[i],2,B))))
		    			    	    {
		    				        	set_rd(B,num_ofrg(inss[i],2,B));
		    				        	op3_f=1;
		    				     	}
		    					}
		    					else
		    					{
		    						if(op2_f)
		    						{
		    							set_rd(B,num_ofrg(inss[i],2,B));
		    						}
		    						op3_f=op2_f;
		    					}
		    					if(inss[i].op[3].opd.accumul)
		    		    		{
		    		    			set_B_wrd(M);
		    		    			if((jud_B_read(M)))
		    		    			{
		    		    				op4_f=1;
		    		    				set_B_rd(M);
		    		    			}
		    		    		}
		    		    		else
		    		    		{
		    		    			op4_f=1;
		    		    		}
		    					if((plst.prodvv_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&op4_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvWordConsumed;
		    						prodvv_i0.ex_ins=inss[i].decode_ins;
									prodvv_i0.is_exist_ins=1;
		    						prodvv_i0.op[0]=inss[i].op[0];
		    						prodvv_i0.op[1]=inss[i].op[1];
		    						prodvv_i0.op[2]=inss[i].op[2];
		    						prodvv_i0.op[3]=inss[i].op[3];
		    						plst.prodvv_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
		    						{
		    							clr_M_wr(inss[i].op[0].opd.type_MAT.mat_num);
		    						}
		    						if(op2_f)
		    						{
		    							clr_rd(B,num_ofrg(inss[i],1,B));
		    						}
		    						if(op3_f)
		    						{
		    							clr_rd(B,num_ofrg(inss[i],2,B));
		    						}
		    						if(op4_f&&inss[i].op[3].opd.accumul)
		    		     			{
		    		    				clr_B_rd(M);
		    		    			}
		    		    			if(op1_f&&op2_f&&op3_f&&op4_f&&!isFreeNeuroUnit)
		    			  		    {
		    		    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 		   	        prodvv_fwait_time++;
		    		    			}
		    		    			else
		    		    			{
		    				   			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				   	        prodvv_wait_time++;
		    				   		}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(R,num_ofrg(inss[i],2,R));
		    					if((jud_read(R,num_ofrg(inss[i],2,R))))
		    				    {
		    				   		set_rd(R,num_ofrg(inss[i],2,R));
		    				   		op3_f=1;
		    				   	}
		    					if(inss[i].op[3].opd.accumul)
		    		    		{
		    		    			set_B_wrd(M);
		    		    			if((jud_B_read(M)))
		    		    			{
		    		    				op4_f=1;
		    		    				set_B_rd(M);
		    		    			}
		    		    		}
		    		    		else
		    		    		{
		    		    			op4_f=1;
		    		    		}
		    					if((plst.prodvv_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&op4_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvWordConsumed;
		    						prodvv_i0.ex_ins=inss[i].decode_ins;
									prodvv_i0.is_exist_ins=1;
		    						prodvv_i0.op[0]=inss[i].op[0];
		    						prodvv_i0.op[1]=inss[i].op[1];
		    						prodvv_i0.op[2]=inss[i].op[2];
		    						prodvv_i0.op[3]=inss[i].op[3];
		    						plst.prodvv_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
		    						{
		    							clr_M_wr(inss[i].op[0].opd.type_MAT.mat_num);
		    						}
		    						if(op2_f)
		    						{
		    							clr_rd(B,num_ofrg(inss[i],1,B));
		    						}
		    						if(op3_f)
		    						{
		    							clr_rd(R,num_ofrg(inss[i],2,R));
		    						}
		    						if(op4_f&&inss[i].op[3].opd.accumul)
		    		     			{
		    		    				clr_B_rd(M);
		    		    			}
		    		    			if(op1_f&&op2_f&&op3_f&&op4_f&&!isFreeNeuroUnit)
		    			  		    {
		    		    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 		   	        prodvv_fwait_time++;
		    		    			}
		    		    			else
		    		    			{
		    			    			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				   	        prodvv_wait_time++;
		    				   		}
		    					}
		    				}
		    			}
		    			else
		    			{
		    				set_wrd(R,num_ofrg(inss[i],1,R));
		    				if((jud_read(R,num_ofrg(inss[i],1,R))))
		    				{
		    					set_rd(R,num_ofrg(inss[i],1,R));
		    					op2_f=1;
		    				}
		    				if(inss[i].op[2].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],2,B));
		    					if((jud_read(B,num_ofrg(inss[i],2,B))))
		    				    {
		    				    	set_rd(B,num_ofrg(inss[i],2,B));
		    				    	op3_f=1;
		    				   	}
		    					if(inss[i].op[3].opd.accumul)
		    		    		{
		    		    			set_B_wrd(M);
		    		    			if((jud_B_read(M)))
		    		    			{
		    		    				op4_f=1;
		    		    				set_B_rd(M);
		    		    			}
		    		    		}
		    		    		else
		    		    		{
		    		    			op4_f=1;
		    		    		}
		    					if((plst.prodvv_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&op4_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvWordConsumed;
		    						prodvv_i0.ex_ins=inss[i].decode_ins;
									prodvv_i0.is_exist_ins=1;
		    						prodvv_i0.op[0]=inss[i].op[0];
		    						prodvv_i0.op[1]=inss[i].op[1];
		    						prodvv_i0.op[2]=inss[i].op[2];
		    						prodvv_i0.op[3]=inss[i].op[3];
		    						plst.prodvv_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
		    						{
		    							clr_M_wr(inss[i].op[0].opd.type_MAT.mat_num);
		    						}
		    						if(op2_f)
		    						{
		    							clr_rd(R,num_ofrg(inss[i],1,R));
		    						}
		    						if(op3_f)
		    						{
		    							clr_rd(B,num_ofrg(inss[i],2,B));
		    						}
		    						if(op4_f&&inss[i].op[3].opd.accumul)
		    		     			{
		    		    				clr_B_rd(M);
		    		    			}
		    		    			if(op1_f&&op2_f&&op3_f&&op4_f&&!isFreeNeuroUnit)
		    			  		    {
		    		    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 		            prodvv_fwait_time++;
		    		    			}
		    		    			else
		    		    			{
		    				   			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				   	        prodvv_wait_time++;
		    				   		}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(R,num_ofrg(inss[i],2,R));
		    					if(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],1,R))
		    					{
		    						int num_prodvv=num_ofrg(inss[i],2,R);
		    						num_prodvv=inss[i].op[2].opd.type_RV.pRV->readnum;
		    						bool bool_prodvv=inss[i].op[2].opd.type_RV.pRV->R_V[1].RD_S;
		    						bool_prodvv=inss[i].op[2].opd.type_RV.pRV->R_V[1].WRD_S;
		    						bool_prodvv=inss[i].op[2].opd.type_RV.pRV->R_V[1].WR_S;
		    						bool_prodvv=inss[i].op[2].opd.type_RV.pRV->R_V[1].WWR_S;
		    						if((jud_read(R,num_ofrg(inss[i],2,R))))
		    			    	    {
		    			        		set_rd(R,num_ofrg(inss[i],2,R));
		    			        		op3_f=1;
		    			        	}
		    					}
		    					else
		    					{
		    						if(op2_f)
		    							set_rd(R,num_ofrg(inss[i],2,R));
		    						op3_f=op2_f;
		    					}
		    					if(inss[i].op[3].opd.accumul)
		    		    		{
		    		    			set_B_wrd(M);
		    		    			if((jud_B_read(M)))
		    		    			{
		    		    				op4_f=1;
		    		    				set_B_rd(M);
		    		    			}
		    		    		}
		    		    		else
		    		    		{
		    		    			op4_f=1;
		    		    		}
		    					if((plst.prodvv_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&op4_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvWordConsumed;
		    						prodvv_i0.ex_ins=inss[i].decode_ins;
									prodvv_i0.is_exist_ins=1;
		    						prodvv_i0.op[0]=inss[i].op[0];
		    						prodvv_i0.op[1]=inss[i].op[1];
		    						prodvv_i0.op[2]=inss[i].op[2];
		    						prodvv_i0.op[3]=inss[i].op[3];
		    						plst.prodvv_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
		    						{
		    							clr_M_wr(inss[i].op[0].opd.type_MAT.mat_num);
		    						}
		    						if(op2_f)
		    						{
		    							clr_rd(R,num_ofrg(inss[i],1,R));
		    						}
		    						if(op3_f)
		    						{
		    							clr_rd(R,num_ofrg(inss[i],2,R));
		    						}
		    						if(op4_f&&inss[i].op[3].opd.accumul)
		    		     			{
		    		    				clr_B_rd(M);
		    		    			}
		    		    			if(op1_f&&op2_f&&op3_f&&op4_f&&!isFreeNeuroUnit)
		    			  		    {
		    		    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 		   	        prodvv_fwait_time++;
		    		    			}
		    		    			else
		    		    			{
		    				   			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    			    	        prodvv_wait_time++;
		    				   		}
		    					}
		    				}
		    			}
		    			break;
		    		}
		    	case PRODVVP_OPCODE:
		    	    {
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if(inss[i].op[0].type_flag==0)
		    			{
		    				set_wrd(B,num_ofrg(inss[i],0,B));
		    				if((jud_read(B,num_ofrg(inss[i],0,B))))
		    				{
		    					set_rd(B,num_ofrg(inss[i],0,B));
		    					op1_f=1;
		    				}
		    				if(inss[i].op[1].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],1,B));
		    					if(num_ofrg(inss[i],1,B)!=num_ofrg(inss[i],0,B))
		    					{
		    						if((jud_read(B,num_ofrg(inss[i],1,B))))
		    			    	    {
		    				        	set_rd(B,num_ofrg(inss[i],1,B));
		    				        	op2_f=1;
		    				     	}
		    					}
		    					else
		    					{
		    						if(op1_f)
		    						{
		    							set_rd(B,num_ofrg(inss[i],1,B));
		    						}
		    						op2_f=op1_f;
		    					}
		    		    		if((jud_B_write(M)))
		    		    		{
		    		    			op3_f=1;
		    		    			set_B_wr(M);
		    						set_B_wwr(M);
		    		    		}
		    					else
								{
		    						set_B_wwr(M);
								}
		    					if((plst.prodvvp_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvpWordConsumed;
		    						prodvvp_i0.ex_ins=inss[i].decode_ins;
									prodvvp_i0.is_exist_ins=1;
		    						prodvvp_i0.op[0]=inss[i].op[0];
		    						prodvvp_i0.op[1]=inss[i].op[1];
		    						prodvvp_i0.op[2]=inss[i].op[2];
		    						prodvvp_i0.op[3]=inss[i].op[3];
		    						plst.prodvvp_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
		    						{
		    							clr_rd(B,num_ofrg(inss[i],0,B));
		    						}
		    						if(op2_f)
		    						{
		    							clr_rd(B,num_ofrg(inss[i],1,B));
		    						}
		    						if(op3_f)
		    		     			{
		    		    				clr_B_wr(M);
		    		    			}
		    		    			if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    			  		    {
		    		    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 		   	        prodvvp_fwait_time++;
		    		    			}
		    		    			else
		    		    			{
		    				   			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				   	        prodvvp_wait_time++;
		    				   		}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(R,num_ofrg(inss[i],1,R));
		    					if((jud_read(R,num_ofrg(inss[i],1,R))))
		    				    {
		    				   		set_rd(R,num_ofrg(inss[i],1,R));
		    				   		op2_f=1;
		    				   	}
		    		    		if((jud_B_write(M)))
		    		    		{
		    		    			op3_f=1;
		    		    			set_B_wr(M);
		    						set_B_wwr(M);
		    		    		}
		    					else
								{
		    						set_B_wwr(M);
								}
		    					if((plst.prodvvp_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvpWordConsumed;
		    						prodvvp_i0.ex_ins=inss[i].decode_ins;
									prodvvp_i0.is_exist_ins=1;
		    						prodvvp_i0.op[0]=inss[i].op[0];
		    						prodvvp_i0.op[1]=inss[i].op[1];
		    						prodvvp_i0.op[2]=inss[i].op[2];
									prodvvp_i0.op[3]=inss[i].op[3];
		    						plst.prodvvp_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
		    						{
		    							clr_rd(B,num_ofrg(inss[i],0,B));
		    						}
		    						if(op2_f)
		    						{
		    							clr_rd(R,num_ofrg(inss[i],1,R));
		    						}
		    						if(op3_f)
		    		     			{
		    		    				clr_B_wr(M);
		    		    			}
		    		    			if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    			  		    {
		    		    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 		   	        prodvvp_fwait_time++;
		    		    			}
		    		    			else
		    		    			{
		    			    			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				   	        prodvvp_wait_time++;
		    				   		}
		    					}
		    				}
		    			}
		    			else
		    			{
		    				set_wrd(R,num_ofrg(inss[i],0,R));
		    				if((jud_read(R,num_ofrg(inss[i],0,R))))
		    				{
		    					set_rd(R,num_ofrg(inss[i],0,R));
		    					op1_f=1;
		    				}
		    				if(inss[i].op[1].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],1,B));
		    					if((jud_read(B,num_ofrg(inss[i],1,B))))
		    				    {
		    				    	set_rd(B,num_ofrg(inss[i],1,B));
		    				    	op2_f=1;
		    				   	}
		    		    		if((jud_B_write(M)))
		    		    		{
		    		    			op3_f=1;
		    		    			set_B_wr(M);
		    						set_B_wwr(M);
		    		    		}
		    					else
								{
		    						set_B_wwr(M);
								}
		    					if((plst.prodvvp_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvpWordConsumed;
		    						prodvvp_i0.ex_ins=inss[i].decode_ins;
									prodvvp_i0.is_exist_ins=1;
		    						prodvvp_i0.op[0]=inss[i].op[0];
		    						prodvvp_i0.op[1]=inss[i].op[1];
		    						prodvvp_i0.op[2]=inss[i].op[2];
									prodvvp_i0.op[3]=inss[i].op[3];
		    						plst.prodvvp_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
		    						{
		    							clr_rd(R,num_ofrg(inss[i],0,R));
		    						}
		    						if(op2_f)
		    						{
		    							clr_rd(B,num_ofrg(inss[i],1,B));
		    						}
		    						if(op3_f)
		    		     			{
		    		    				clr_B_wr(M);
		    		    			}
		    		    			if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    			  		    {
		    		    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 		            prodvvp_fwait_time++;
		    		    			}
		    		    			else
		    		    			{
		    				   			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    				   	        prodvvp_wait_time++;
		    				   		}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(R,num_ofrg(inss[i],1,R));
		    					if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    					{
		    						if((jud_read(R,num_ofrg(inss[i],1,R))))
		    			    	    {
		    			        		set_rd(R,num_ofrg(inss[i],1,R));
		    			        		op2_f=1;
		    			        	}
		    					}
		    					else
		    					{
		    						if(op1_f)
		    							set_rd(R,num_ofrg(inss[i],1,R));
		    						op2_f=op1_f;
		    					}
		    		    		if((jud_B_write(M)))
		    		    		{
		    		    			op3_f=1;
		    		    			set_B_wr(M);
		    						set_B_wwr(M);
		    		    		}
		    					else
		    						set_B_wwr(M);
		    					if((plst.prodvvp_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvpWordConsumed;
		    						prodvvp_i0.ex_ins=inss[i].decode_ins;
									prodvvp_i0.is_exist_ins=1;
		    						prodvvp_i0.op[0]=inss[i].op[0];
		    						prodvvp_i0.op[1]=inss[i].op[1];
		    						prodvvp_i0.op[2]=inss[i].op[2];
									prodvvp_i0.op[3]=inss[i].op[3];
		    						plst.prodvvp_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
		    						{
		    							clr_rd(R,num_ofrg(inss[i],0,R));
		    						}
		    						if(op2_f)
		    						{
		    							clr_rd(R,num_ofrg(inss[i],1,R));
		    						}
		    						if(op3_f)
		    		     			{
		    		    				clr_B_wr(M);
		    		    			}
		    		    			if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    			  		    {
		    		    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 		   	        prodvvp_fwait_time++;
		    		    			}
		    		    			else
		    		    			{
		    				   			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    			    	        prodvvp_wait_time++;
		    				   		}
		    					}
		    				}
		    			}
		    			break;
	         		}
		    	case PRODVVD_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if(inss[i].op[0].type_flag==0)
		    			{
		    				if((jud_write(B,num_ofrg(inss[i],0,B))))
		    				{
		    					set_wwr(B,num_ofrg(inss[i],0,B));
		    					set_wr(B,num_ofrg(inss[i],0,B));
		    					op1_f=1;
		    				}
		    				else
		    					set_wwr(B,num_ofrg(inss[i],0,B));
		    				set_wrd(R,num_ofrg(inss[i],1,R));
		    				if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		    	{
		    		     		set_rd(R,num_ofrg(inss[i],1,R));
		    		    		op2_f=1;
		    		   		}
		    				if(inss[i].op[2].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],2,B));
		    					if(num_ofrg(inss[i],2,B)!=num_ofrg(inss[i],0,B))
		    			    	{
		    						if((jud_read(B,num_ofrg(inss[i],2,B))))
		    				    	{
		    				    		set_rd(B,num_ofrg(inss[i],2,B));
		    				    		op3_f=1;
		    				    	}
		    					}
		    					else
		    					{
		    						if(op1_f)
		    						{
		    							set_rd(B,num_ofrg(inss[i],2,B));
		    						}
		    						op3_f=op1_f;
		    					}
		    					if((plst.prodvvd_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvdWordConsumed;
		    						prodvvd_i0.ex_ins=inss[i].decode_ins;
									prodvvd_i0.is_exist_ins=1;
		    						prodvvd_i0.op[0]=inss[i].op[0];
		    						prodvvd_i0.op[1]=inss[i].op[1];
		    						prodvvd_i0.op[2]=inss[i].op[2];
									prodvvd_i0.op[3]=inss[i].op[3];
		    						plst.prodvvd_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
		    						{
		    							clr_wr(B,num_ofrg(inss[i],0,B));
		    						}
		    						if(op2_f)
		    						{
		    							clr_rd(R,num_ofrg(inss[i],1,R));
		    						}
		    						if(op3_f)
		    						{
		    							clr_rd(B,num_ofrg(inss[i],2,B));
		    						}
		    		    			if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    	  	    		    {
		    		    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		        	        prodvvd_fwait_time++;
		    		    			}
		    			    		else
		    	 	    			{
		    		        			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		        	        prodvvd_wait_time++;
		    		        		}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(R,num_ofrg(inss[i],2,R));
		    					if(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],1,R))
		    					{
		    						if((jud_read(R,num_ofrg(inss[i],2,R))))
		    		 				{
		    		    				set_rd(R,num_ofrg(inss[i],2,R));
		    		    				op3_f=1;
		    		    			}
		    					}
		    					else
		    					{
		    						if(op2_f)
		    						{
		    							set_rd(R,num_ofrg(inss[i],2,R));
		    						}
		    						op3_f=op2_f;
		    					}
		    					if((plst.prodvvd_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvdWordConsumed;
		    						prodvvd_i0.ex_ins=inss[i].decode_ins;
									prodvvd_i0.is_exist_ins=1;
		    						prodvvd_i0.op[0]=inss[i].op[0];
		    						prodvvd_i0.op[1]=inss[i].op[1];
		    						prodvvd_i0.op[2]=inss[i].op[2];
		    						plst.prodvvd_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
									{
		    							clr_wr(B,num_ofrg(inss[i],0,B));
									}
		    						if(op2_f)
									{
		    							clr_rd(R,num_ofrg(inss[i],1,R));
									}
		    						if(op3_f)
									{
		    							clr_rd(R,num_ofrg(inss[i],2,R));
									}
		    						if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    			   		    {
		    		       				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 	       	        prodvvd_fwait_time++;
		    		       			}
		    		        		else
		    		      			{
		    			     			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    			    	        prodvvd_wait_time++;
		    			    		}
		    					}
		    				}
		    			}
		    			else
		    			{
		    				int tmp=num_ofrg(inss[i],0,R);
		    	    		bool t1=RV->R_V[tmp].RD_S;
		    	    		bool t2=RV->R_V[tmp].WRD_S;
		    	    		bool t3=RV->R_V[tmp].WR_S;
		    		    	bool t4=RV->R_V[tmp].WWR_S;
		    	    		bool t5=jud_write(R,tmp);
		    				if((jud_write(R,num_ofrg(inss[i],0,R))))
		    				{
		    					set_wwr(R,num_ofrg(inss[i],0,R));
		    					set_wr(R,num_ofrg(inss[i],0,R));
		    					op1_f=1;
		    				}
		    				else
		    					set_wwr(R,num_ofrg(inss[i],0,R));
		    				set_wrd(R,num_ofrg(inss[i],1,R));
		    				if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    				{
		    					if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		    		{
		    		    			set_rd(R,num_ofrg(inss[i],1,R));
		    		    			op2_f=1;
		    		    		}
		    				}
		    				else
		    				{
		    					if(op1_f)
								{
		    						set_rd(R,num_ofrg(inss[i],1,R));
								}
		    					op2_f=op1_f;
		    				}
		    				if(inss[i].op[2].type_flag==0)
		    				{
		    					set_wrd(B,num_ofrg(inss[i],2,B));
		    					if((jud_read(B,num_ofrg(inss[i],2,B))))
		    					{
		    						set_rd(B,num_ofrg(inss[i],2,B));
		    						op3_f=1;
		    					}
		    					if((plst.prodvvd_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvdWordConsumed;
		    						prodvvd_i0.ex_ins=inss[i].decode_ins;
									prodvvd_i0.is_exist_ins=1;
		    						prodvvd_i0.op[0]=inss[i].op[0];
		    						prodvvd_i0.op[1]=inss[i].op[1];
		    						prodvvd_i0.op[2]=inss[i].op[2];
									prodvvd_i0.op[3]=inss[i].op[3];
		    						plst.prodvvd_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
									{
		    							clr_wr(R,num_ofrg(inss[i],0,R));
									}
		    						if(op2_f)
									{
		    							clr_rd(R,num_ofrg(inss[i],1,R));
									}
		    						if(op3_f)
									{
		    							clr_rd(B,num_ofrg(inss[i],2,B));
									}
		    						if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    	  	    		    {
		    	  	    				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		        	        prodvvd_fwait_time++;
		    	 	    			}
		    	 		    		else
		    		       			{
		    			       			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    			       	        prodvvd_wait_time++;
		    			       		}
		    					}
		    				}
		    				else
		    				{
		    					set_wrd(R,num_ofrg(inss[i],2,R));
		    					if((num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],0,R))&&(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],1,R)))
		    					{
		    						if((jud_read(R,num_ofrg(inss[i],2,R))))
		    		    			{
		    			    			set_rd(R,num_ofrg(inss[i],2,R));
		    			    			op3_f=1;
		    			    		}
		    					}
		    					else
		    					{
		    						if((num_ofrg(inss[i],2,R)==num_ofrg(inss[i],0,R))&&(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],1,R)))
		    						{
		    							if(op1_f)
										{
		    								set_rd(R,num_ofrg(inss[i],2,R));
										}
		    							op3_f=op1_f;
		    						}
		    						if((num_ofrg(inss[i],2,R)==num_ofrg(inss[i],1,R))&&(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],0,R)))
		    						{
		    							if(op2_f)
										{
		    								set_rd(R,num_ofrg(inss[i],2,R));
										}
		    							op3_f=op2_f;
		    						}
		    						else
		    						{
		    							if(op1_f)
		    								set_rd(R,num_ofrg(inss[i],2,R));
		    							op3_f=op1_f;
		    						}
		    					}
		    					if((plst.prodvvd_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    					{
		    						//convert_ins_to_b(inss[i],fp_saveRTLB);
		    						rtlMaxWord=rtlMaxWord+prodvvdWordConsumed;
		    						prodvvd_i0.ex_ins=inss[i].decode_ins;
									prodvvd_i0.is_exist_ins=1;
		    						prodvvd_i0.op[0]=inss[i].op[0];
		    						prodvvd_i0.op[1]=inss[i].op[1];
		    						prodvvd_i0.op[2]=inss[i].op[2];
									prodvvd_i0.op[3]=inss[i].op[3];
		    						plst.prodvvd_if0=STG_READY;
		    						++decode_v_num,inss[i].decode_v=1;
		    						inss[i].decode_v=1;
		    						isFreeNeuroUnit=noNeurCalcUnit;
		    					}
		    					else
		    					{
									if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
									{
										endlpdeocde = 0;
									}
		    						if(op1_f)
									{
		    							clr_wr(R,num_ofrg(inss[i],0,R));
									}
		    						if(op2_f)
									{
		    							clr_rd(R,num_ofrg(inss[i],1,R));
									}
		    						if(op3_f)
									{
		    							clr_rd(R,num_ofrg(inss[i],2,R));
									}
		    						if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    			   		    {
		    		       				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		         	        prodvvd_fwait_time++;
		    		       			}
		    		   	    		else
		    		       			{
		    		        			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		        	        prodvvd_wait_time++;
		    		        		}
		    					}
		    				}
		    			}
		    			break;
		    		}
		    	case ADDV_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if((jud_write(R,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wr(R,num_ofrg(inss[i],0,R));
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
						}
		    			set_wrd(R,num_ofrg(inss[i],1,R));
		    			if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    			{
		    				if((jud_read(R,num_ofrg(inss[i],1,R))))
		    	    		{
		    		    		set_rd(R,num_ofrg(inss[i],1,R));
		    		     		op2_f=1;
		    		    	}
		    			}
		    			else
		    			{
		    				if(op1_f)
							{
		    					set_rd(R,num_ofrg(inss[i],1,R));
							}
		    				op2_f=op1_f;
		    			}
		    			set_wrd(R,num_ofrg(inss[i],2,R));
		    			if((num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],0,R))&&(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],1,R)))
		    			{
		    				if(jud_read(R,num_ofrg(inss[i],2,R)))
		    	    		{
		    	    			set_rd(R,num_ofrg(inss[i],2,R));
		    		    		op3_f=1;
		    	    		}
		    			}
		    			else
		    			{
		    				if((num_ofrg(inss[i],2,R)==num_ofrg(inss[i],0,R))&&(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],1,R)))
		    				{
		    					if(op1_f)
								{
		    						set_rd(R,num_ofrg(inss[i],2,R));
								}
		    					op3_f=op1_f;
		    				}
		    				if((num_ofrg(inss[i],2,R)==num_ofrg(inss[i],1,R))&&(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],0,R)))
		    				{
		    					if(op2_f)
								{
		    						set_rd(R,num_ofrg(inss[i],2,R));
								}
		    					op3_f=op2_f;
		    				}
		    				else
		    				{
		    					if(op1_f)
								{
		    						set_rd(R,num_ofrg(inss[i],2,R));
								}
		    					op3_f=op2_f;
		    				}
		    			}
		    			if((plst.addv_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+addvWordConsumed;
		    				addv_i0.ex_ins=inss[i].decode_ins;
							addv_i0.is_exist_ins=1;
		    				addv_i0.op[0]=inss[i].op[0];
		    				addv_i0.op[1]=inss[i].op[1];
		    				addv_i0.op[2]=inss[i].op[2];
							addv_i0.op[3]=inss[i].op[3];
		    				plst.addv_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
		    				{
		    					clr_wr(R,num_ofrg(inss[i],0,R));
		    				}
		    				if(op2_f)
		    				{
		    					clr_rd(R,num_ofrg(inss[i],1,R));
		    				}
		    				if(op3_f)
		    				{
		    					clr_rd(R,num_ofrg(inss[i],2,R));
		    				}
		    				if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		     	   		    {
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        addv_fwait_time++;
		    	   			}
		    	    		else
		    	   			{
		    	    			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	      	        addv_wait_time++;
		    	      		}
		    			}
		    			break;
		    		}
		    	case ADDM_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
                        if((jud_M_write(inss[i].op[0].opd.type_MAT.mat_num)))
		        	    {
		    				set_M_wwr(inss[i].op[0].opd.type_MAT.mat_num);
		                    set_M_wr(inss[i].op[0].opd.type_MAT.mat_num);
		        	   		op1_f=1;
		        	   	}
		    			else
						{
		    				set_M_wwr(inss[i].op[0].opd.type_MAT.mat_num);
						}
		    			set_M_wrd(inss[i].op[1].opd.type_MAT.mat_num);
		    			if(inss[i].op[1].opd.type_MAT.mat_num!=inss[i].op[0].opd.type_MAT.mat_num)
		    			{
		    				if((jud_M_read(inss[i].op[1].opd.type_MAT.mat_num)))
		    	           {
		    	                set_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    	         		op2_f=1;
		    	        	}
		    			}
		    	    	else
		    			{
		    				if(op1_f)
							{
		    					set_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
							}
		    				op2_f=op1_f;
		    			}
		    			set_M_wrd(inss[i].op[2].opd.type_MAT.mat_num);
		    			if((inss[i].op[2].opd.type_MAT.mat_num!=inss[i].op[0].opd.type_MAT.mat_num)&&(inss[i].op[2].opd.type_MAT.mat_num!=inss[i].op[1].opd.type_MAT.mat_num))
		    			{
		    				if((jud_M_read(inss[i].op[2].opd.type_MAT.mat_num)))
		    	            {
		    	                set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    	        		op3_f=1;
		    	        	}
		    			}
		    	    	else
		    			{
		    				if((inss[i].op[2].opd.type_MAT.mat_num==inss[i].op[0].opd.type_MAT.mat_num)&&(inss[i].op[2].opd.type_MAT.mat_num!=inss[i].op[1].opd.type_MAT.mat_num))
		    				{
		    					if(op1_f)
		    					{
		    						set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					}
		    					op3_f=op1_f;
		    				}
		    				if((inss[i].op[2].opd.type_MAT.mat_num==inss[i].op[1].opd.type_MAT.mat_num)&&(inss[i].op[2].opd.type_MAT.mat_num!=inss[i].op[0].opd.type_MAT.mat_num))
		    				{
		    					if(op2_f)
		    						set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					op3_f=op1_f;
		    				}
		    				if((inss[i].op[2].opd.type_MAT.mat_num==inss[i].op[0].opd.type_MAT.mat_num)&&(inss[i].op[2].opd.type_MAT.mat_num==inss[i].op[1].opd.type_MAT.mat_num))
		    				{
		    					if(op1_f)
		    						set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					op3_f=op1_f;
		    				}
		    			}
		    		   	if((plst.addm_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    		   	{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+addmWordConsumed;
		    		   		addm_i0.ex_ins=inss[i].decode_ins;
							addm_i0.is_exist_ins=1;
		    		    	addm_i0.op[0]=inss[i].op[0];
		    		   		addm_i0.op[1]=inss[i].op[1];
		    		   		addm_i0.op[2]=inss[i].op[2];
							addm_i0.op[3]=inss[i].op[3];
		    		   		plst.addm_if0=STG_READY;
		    	    		++decode_v_num,inss[i].decode_v=1;
		    		   		inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    		   	}
		    	    	else
		    	    	{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
							{
		    					clr_M_wr(inss[i].op[0].opd.type_MAT.mat_num);
							}
							if(op2_f)
							{
		    					clr_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
							}
		    				if(op3_f)
							{
		    					clr_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
							}
		    	    		if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    	     	    {
		    	      			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        addm_fwait_time++;
		    	 	    	}
		    	     		else
		    	      		{
		    	    			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		   	        addm_wait_time++;
		    		   		}
		    	    	}
	            		break;
		         	}
		    	case SUBV_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if((jud_write(R,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    				set_wr(R,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    			set_wrd(R,num_ofrg(inss[i],1,R));
		    			if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    			{
		    				if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		    	{
		    		    		set_rd(R,num_ofrg(inss[i],1,R));
		    	    			op2_f=1;
		    	    		}
		    			}
		    			else
		    			{
		    				if(op1_f)
							{
		    					set_rd(R,num_ofrg(inss[i],1,R));
							}
		    				op2_f=op1_f;
		    			}
		    			set_wrd(R,num_ofrg(inss[i],2,R));
		    			if((num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],0,R))&&(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],1,R)))
		    			{
		    				if((jud_read(R,num_ofrg(inss[i],2,R))))
		    	    		{
		    		    		set_rd(R,num_ofrg(inss[i],2,R));
		    		    		op3_f=1;
		    	    		}
		    			}
		    			else
		    		    {
		    				if((num_ofrg(inss[i],2,R)==num_ofrg(inss[i],0,R))&&(num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],1,R)))
		    				{
		    					if(op1_f)
		    						set_rd(R,num_ofrg(inss[i],2,R));
		    					op3_f=op1_f;
		    				}
		    			    if((num_ofrg(inss[i],2,R)!=num_ofrg(inss[i],0,R))&&(num_ofrg(inss[i],2,R)==num_ofrg(inss[i],1,R)))
		    				{
		    					if(op2_f)
		    						set_rd(R,num_ofrg(inss[i],2,R));
		    					op3_f=op2_f;
		    				}
		    				else
		    				{
		    					if(op1_f)
								{
		    						set_rd(R,num_ofrg(inss[i],2,R));
								}
		    					op3_f=op1_f;
		    				}
		    			}
		    			if((plst.subv_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+subvWordConsumed;
		    				subv_i0.ex_ins=inss[i].decode_ins;
							subv_i0.is_exist_ins=1;
		    				subv_i0.op[0]=inss[i].op[0];
		    				subv_i0.op[1]=inss[i].op[1];
		    				subv_i0.op[2]=inss[i].op[2];
							subv_i0.op[3]=inss[i].op[3];
		    				plst.subv_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
							{
		    					clr_wr(R,num_ofrg(inss[i],0,R));
							}
		    				if(op2_f)
							{
		    					clr_rd(R,num_ofrg(inss[i],1,R));
							}
		    				if(op3_f)
							{
		    					clr_rd(R,num_ofrg(inss[i],2,R));
							}
		    				if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		      	   		    {
		     	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        subv_fwait_time++;
		    	   			}
		    	    		else
		    	   			{
		    	       			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        subv_wait_time++;
		    	       		}
		    			}
		    			break;
		    		}
		    	case SUBM_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if((jud_M_write(inss[i].op[0].opd.type_MAT.mat_num)))
		    		    {
		    				set_M_wwr(inss[i].op[0].opd.type_MAT.mat_num);
		    	            set_M_wr(inss[i].op[0].opd.type_MAT.mat_num);
		    		  		op1_f=1;
		    		   	}
		    			else
						{
		    				set_M_wwr(inss[i].op[0].opd.type_MAT.mat_num);
						}
		    			set_M_wrd(inss[i].op[1].opd.type_MAT.mat_num);
		    			if(inss[i].op[1].opd.type_MAT.mat_num!=inss[i].op[0].opd.type_MAT.mat_num)
		    			{
		    				if((jud_M_read(inss[i].op[1].opd.type_MAT.mat_num)))
		    		        {
		    	                set_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    	        		op2_f=1;
		    	        	}
		    			}
		    			else
		    			{
		    				if(op1_f)
							{
		    					set_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
							}
		    				op2_f=op1_f;
		    			}
		    		    set_M_wrd(inss[i].op[2].opd.type_MAT.mat_num);
		    			if((inss[i].op[2].opd.type_MAT.mat_num!=inss[i].op[0].opd.type_MAT.mat_num)&&(inss[i].op[2].opd.type_MAT.mat_num!=inss[i].op[1].opd.type_MAT.mat_num))
		    			{
		    				if((jud_M_read(inss[i].op[2].opd.type_MAT.mat_num)))
		    	            {
		    	                set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    	        		op3_f=1;
		    	        	}
		    			}
		    	    	else
		    			{
		    				if((inss[i].op[2].opd.type_MAT.mat_num==inss[i].op[0].opd.type_MAT.mat_num)&&(inss[i].op[2].opd.type_MAT.mat_num!=inss[i].op[1].opd.type_MAT.mat_num))
		    				{
		    					if(op1_f)
		    					{
		    						set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					}
		    					op3_f=op1_f;
		    				}
		    				if((inss[i].op[2].opd.type_MAT.mat_num==inss[i].op[1].opd.type_MAT.mat_num)&&(inss[i].op[2].opd.type_MAT.mat_num!=inss[i].op[0].opd.type_MAT.mat_num))
		    				{
		    					if(op2_f)
		    						set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					op3_f=op1_f;
		    				}
		    				if((inss[i].op[2].opd.type_MAT.mat_num==inss[i].op[0].opd.type_MAT.mat_num)&&(inss[i].op[2].opd.type_MAT.mat_num==inss[i].op[1].opd.type_MAT.mat_num))
		    				{
		    					if(op1_f)
		    						set_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
		    					op3_f=op1_f;
		    				}
		    			}
		    			if((plst.subm_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+submWordConsumed;
		    				subm_i0.ex_ins=inss[i].decode_ins;
							subm_i0.is_exist_ins=1;
		    				subm_i0.op[0]=inss[i].op[0];
		    				subm_i0.op[1]=inss[i].op[1];
		    				subm_i0.op[2]=inss[i].op[2];
							subm_i0.op[3]=inss[i].op[3];
		    				plst.subm_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
							{
		    					clr_M_wr(inss[i].op[0].opd.type_MAT.mat_num);
							}
		    				if(op2_f)
							{
		    					clr_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
							}
		    				if(op3_f)
							{
		    					clr_M_rd(inss[i].op[2].opd.type_MAT.mat_num);
							}
		    				if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    	   		    {
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        subm_fwait_time++;
		    		   		}
		    		   		else
		    		   		{
		    		   			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		   	        subm_wait_time++;
		    		   		}
		    			}
		    			break;
		    		}
		    	case SUM_OPCODE:
	   	    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if((jud_write(R,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    				set_wr(R,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
						}
		    			 set_M_wrd(inss[i].op[1].opd.type_MAT.mat_num);
		    			if((jud_M_read(inss[i].op[1].opd.type_MAT.mat_num)))
		    		    {
		    	            set_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
		    	    		op2_f=1;
		    	    	}
		    			if((plst.sum_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+sumWordConsumed;
		    				sum_i0.ex_ins=inss[i].decode_ins;
							sum_i0.is_exist_ins=1;
		    				sum_i0.op[0]=inss[i].op[0];
		    				sum_i0.op[1]=inss[i].op[1];
							sum_i0.op[2]=inss[i].op[2];
							sum_i0.op[3]=inss[i].op[3];
		    				plst.sum_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
							{
		    					clr_wr(R,num_ofrg(inss[i],0,R));
							}
		    				if(op2_f)
							{
		    					clr_M_rd(inss[i].op[1].opd.type_MAT.mat_num);
							}
		    				if(op1_f&&op2_f&&!isFreeNeuroUnit)
		      	   		    {
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        sum_fwait_time++;
		    	   			}
		    	    		else
		    	   			{
		    	       			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        sum_wait_time++;
		    	       		}
		    			}
		    			break;
		    		}
		    	case MAX_OPCODE:
		        	{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if((jud_write(R,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    				set_wr(R,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    			if((num_ofrg(inss[i],1,R))!=(num_ofrg(inss[i],0,R)))
		    			{
		    				set_wrd(R,num_ofrg(inss[i],1,R));
		    				if((jud_read(R,num_ofrg(inss[i],1,R))))
		    				{
		    					set_rd(R,num_ofrg(inss[i],1,R));
		    					op2_f=1;
		    				}
		    			}
		    			else
		    			{
		    				set_rd(R,num_ofrg(inss[i],1,R));
		    				op2_f=op1_f;
		    			}
		    			if((num_ofrg(inss[i],2,R))!=(num_ofrg(inss[i],0,R)))
		    			{
		    				if((num_ofrg(inss[i],1,R))!=(num_ofrg(inss[i],2,R)))
		    				{
		    					set_wrd(R,num_ofrg(inss[i],2,R));
		    		    		if((jud_read(R,num_ofrg(inss[i],2,R))))
		    		    		{
		    		    			set_rd(R,num_ofrg(inss[i],2,R));
		    		    			op3_f=1;
		    		    		}
		    				}
		    				else
		    				{
		    					op3_f=op2_f;
		    				}
		    			}
		    			else
		    			{
		    				set_rd(R,num_ofrg(inss[i],2,R));
		    				op2_f=op1_f;
		    			}
		    			if((plst.max_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+maxWordConsumed;
		    				max_i0.ex_ins=inss[i].decode_ins;
							max_i0.is_exist_ins=1;
		    				max_i0.op[0]=inss[i].op[0];
		    				max_i0.op[1]=inss[i].op[1];
		    				max_i0.op[2]=inss[i].op[2];
							max_i0.op[3]=inss[i].op[3];
		    				plst.max_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
							{
		    					clr_wr(R,num_ofrg(inss[i],0,R));
							}
		    				if(op2_f)
							{
		    					clr_rd(R,num_ofrg(inss[i],1,R));
							}
		    				if(op3_f)
							{
		    					clr_rd(R,num_ofrg(inss[i],2,R));
							}
		    				if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		      	   		    {
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        max_fwait_time++;
		    	   			}
		    	    		else
		    	   			{
		    	       			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        max_wait_time++;
		    	       		}
		    			}
		    			break;
		        	}
		    	case SCALE_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if((jud_write(R,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    				set_wr(R,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
						}
		    			set_wrd(R,num_ofrg(inss[i],1,R));
		    			if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    			{
		    				if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		    	{
		    		    		set_rd(R,num_ofrg(inss[i],1,R));
		    		    		op2_f=1;
		    		    	}
		    			}
		    			else
		    			{
		    				if(op1_f)
							{
		    					set_rd(R,num_ofrg(inss[i],1,R));
							}
		    				op2_f=op1_f;
		    			}
		    			if((plst.scale_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+scaleWordConsumed;
		    				scale_i0.ex_ins=inss[i].decode_ins;
							scale_i0.is_exist_ins=1;
		    				scale_i0.op[0]=inss[i].op[0];
		    				scale_i0.op[1]=inss[i].op[1];
		    				scale_i0.op[2]=inss[i].op[2];
							scale_i0.op[3]=inss[i].op[3];
		    				plst.scale_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
							{
		    					clr_wr(R,num_ofrg(inss[i],0,R));
							}
		    				if(op2_f)
							{
		    					clr_rd(R,num_ofrg(inss[i],1,R));
							}
		    				if(op1_f&&op2_f&&!isFreeNeuroUnit)
		      	   		    {
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        scale_fwait_time++;
		    	   			}
		    	    		else
		    	   			{
		    	       			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        scale_wait_time++;
		    	       		}
		    			}
		    			break;
		    		}
		    	case DIFF_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
						if((jud_write(R,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    				set_wr(R,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
						}
		    			set_wrd(R,num_ofrg(inss[i],1,R));
		    			if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    			{
		    				if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		    	{
		    		    		set_rd(R,num_ofrg(inss[i],1,R));
		    		    		op2_f=1;
		    		    	}
		    			}
		    			else
		    			{
		    				if(op1_f)
							{
		    					set_rd(R,num_ofrg(inss[i],1,R));
							}
		    				op2_f=op1_f;
		    			}
		    			if((plst.diff_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+diffWordConsumed;
		    				diff_i0.ex_ins=inss[i].decode_ins;
							diff_i0.is_exist_ins=1;
		    				diff_i0.op[0]=inss[i].op[0];
		    				diff_i0.op[1]=inss[i].op[1];
							diff_i0.op[2]=inss[i].op[2];
							diff_i0.op[3]=inss[i].op[3];
		    				plst.diff_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    			}
		    			else
	        			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
							{
		    					clr_wr(R,num_ofrg(inss[i],0,R));
							}
		    				if(op2_f)
							{
		    					clr_rd(R,num_ofrg(inss[i],1,R));
							}
		    				if(op1_f&&op2_f&&!isFreeNeuroUnit)
		    	   		    {
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	     	        diff_fwait_time++;
		    	 			}
		    	    		else
		    	   			{
		    	     			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	     	        diff_wait_time++;
		    	      		}
		    		   	}
		    		    break;
		    		}
		    	case BIAS_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			if((jud_write(R,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
		    				set_wr(R,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_wwr(R,num_ofrg(inss[i],0,R));
						}
		    			set_wrd(R,num_ofrg(inss[i],1,R));
		    			if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
		    			{
		    				if((jud_read(R,num_ofrg(inss[i],1,R))))
		    		    	{
		    		    		set_rd(R,num_ofrg(inss[i],1,R));
		    		    		op2_f=1;
		    		    	}
		    			}
		    			else
		    			{
		    				if(op1_f)
							{
		    					set_rd(R,num_ofrg(inss[i],1,R));
							}
		    				op2_f=op1_f;
		    			}
		    			if((plst.bias_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+biasWordConsumed;
		    				bias_i0.ex_ins=inss[i].decode_ins;
							bias_i0.is_exist_ins=1;
		    				bias_i0.op[0]=inss[i].op[0];
		    				bias_i0.op[1]=inss[i].op[1];
							bias_i0.op[2]=inss[i].op[2];
							bias_i0.op[3]=inss[i].op[3];
		    				plst.bias_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
							{
		    					clr_wr(R,num_ofrg(inss[i],0,R));
							}
		    				if(op2_f)
							{
		    					clr_rd(R,num_ofrg(inss[i],1,R));
							}
		    				if(op1_f&&op2_f&&!isFreeNeuroUnit)
		    	  		    {
		    					buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	    	        bias_fwait_time++;
		    		   		}
		    		   		else
		    		   		{
		    		 			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    			        bias_wait_time++;
		    		  		}
		    			}
		    			break;
		    		}
		    	case RANDGEN_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			int tmp=num_ofrg(inss[i],0,R);
		    			if((jud_write(RD,num_ofrg(inss[i],0,R))))
		    			{
		    				set_wwr(RD,num_ofrg(inss[i],0,R));
		    				set_wr(RD,num_ofrg(inss[i],0,R));
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_wwr(RD,num_ofrg(inss[i],0,R));
						}
		    			if((plst.randgen_if0==STG_NRDY)&&(plst.randgen_st==STG_FREE)&&(plst.decode_st==STG_FREE)&&op1_f&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+randgenWordConsumed;
		    				randgen_i0.ex_ins=inss[i].decode_ins;
		    				randgen_i0.op[0]=inss[i].op[0];
		    				plst.randgen_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    			}
		    			else
		    			{	
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
                            if(op1_f)
		    				{
		    					clr_wr(RD,num_ofrg(inss[i],0,R));
		    				}							
		    				if(op1_f)
		    			    {
		    		    		buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    		 	        randgen_fwait_time++;
		    	  			}
		    		   		else
		    				{
		    		 			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    			        randgen_wait_time++;
		    	    		}
		    			}
		    			break;
		    		}
		    	case PROBCMP_OPCODE:
		    		{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
		    			int tmp=num_ofrg(inss[i],0,B);
		    			bool t1=BV->R_V[tmp].RD_S;
		    			bool t2=BV->R_V[tmp].WRD_S;
		    			bool t3=BV->R_V[tmp].WR_S;
		    			bool t4=BV->R_V[tmp].WWR_S;
		    			bool t5=jud_write(B,tmp);
		    			if((jud_write(B,num_ofrg(inss[i],0,B))))
		    			{
		    				set_wwr(B,num_ofrg(inss[i],0,B));
		    				set_wr(B,num_ofrg(inss[i],0,B));
		    				op1_f=1;
		    			}
		    			else
						{
		    				set_wwr(B,num_ofrg(inss[i],0,B));
						}
		    			set_wrd(R,num_ofrg(inss[i],1,R));
		    			if((jud_read(R,num_ofrg(inss[i],1,R))))
		    			{
		    				set_rd(R,num_ofrg(inss[i],1,R));
		    				op2_f=1;
		    			}
		    			set_wrd(RD,num_ofrg(inss[i],2,R));
		    			if((jud_read(RD,num_ofrg(inss[i],2,R))))
		    			{
		    				set_rd(RD,num_ofrg(inss[i],2,R));
		    				op3_f=1;
		    			}
		    			if((plst.probcmp_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&op3_f&&isFreeNeuroUnit&&(rtlMaxWord<RTL_A_WORD))
		    			{
		    				//convert_ins_to_b(inss[i],fp_saveRTLB);
		    				rtlMaxWord=rtlMaxWord+probcmpWordConsumed;
		    				probcmp_i0.ex_ins=inss[i].decode_ins;
							probcmp_i0.is_exist_ins=1;
		    				probcmp_i0.op[0]=inss[i].op[0];
		    				probcmp_i0.op[1]=inss[i].op[1];
		    				probcmp_i0.op[2]=inss[i].op[2];
							probcmp_i0.op[3]=inss[i].op[3];
		    				plst.probcmp_if0=STG_READY;
		    				++decode_v_num,inss[i].decode_v=1;
		    				inss[i].decode_v=1;
		    				isFreeNeuroUnit=noNeurCalcUnit;
		    			}
		    			else
		    			{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
		    				if(op1_f)
		    		        	clr_wr(B,num_ofrg(inss[i],0,B));
		    		        if(op2_f)
		    					clr_rd(R,num_ofrg(inss[i],1,R));
		    				if(op3_f)
		    					clr_rd(RD,num_ofrg(inss[i],2,R));
		    				if(op1_f&&op2_f&&op3_f&&!isFreeNeuroUnit)
		    	 		    {
		    	   				buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	       	        probcmp_fwait_time++;
		    	   			}
		    		   		else
		    	 			{
		    	     			buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    	     	        probcmp_wait_time++;
		    	     		}
		    			}
		    			break;
		    		}
				case ACT_OPCODE:
					{
						if((lpdecode(inss[i].decode_ins) == 0)&&(!endcurloop()))
						{
							endlptobuffer = 0;
							endlpdeocde = 0;
							++decode_v_num;
							plst.fetch_if0=STG_NRDY;
							break;
						}
						if((jud_write(R,num_ofrg(inss[i],0,R))))
						{
							set_wwr(R,num_ofrg(inss[i],0,R));
							set_wr(R,num_ofrg(inss[i],0,R));
							op1_f=1;
						}
						else
						{
							set_wwr(R,num_ofrg(inss[i],0,R));
						}
						set_wrd(R,num_ofrg(inss[i],1,R));
						if(num_ofrg(inss[i],1,R)!=num_ofrg(inss[i],0,R))
						{
							if((jud_read(R,num_ofrg(inss[i],1,R))))
							{
								set_rd(R,num_ofrg(inss[i],1,R));
								op2_f=1;
							}
						}
						else
						{
							if(op1_f)
							{
								set_rd(R,num_ofrg(inss[i],1,R));
							}
							op2_f=op1_f;
						}
						if((plst.act_if0==STG_NRDY)&&(plst.decode_st==STG_FREE)&&op1_f&&op2_f&&isFreeMathFunc&&(rtlMaxWord<RTL_A_WORD))
						{
							//convert_ins_to_b(inss[i],fp_saveRTLB);
							rtlMaxWord=rtlMaxWord+actWordConsumed;
							act_i0.ex_ins=inss[i].decode_ins;
							act_i0.is_exist_ins=1;
							act_i0.op[0]=inss[i].op[0];
							act_i0.op[1]=inss[i].op[1];
							act_i0.op[2]=inss[i].op[2];
							act_i0.op[3]=inss[i].op[3];
							plst.act_if0=STG_READY;
							++decode_v_num,inss[i].decode_v=1;
							inss[i].decode_v=1;
							isFreeNeuroUnit=noNeurCalcUnit;
						}
						else
						{
							if(lpdecode(inss[i].decode_ins)||endclpjaddr(inss[i].decode_ins))
							{
								endlpdeocde = 0;
							}
							if(op1_f)
							{
								clr_wr(R,num_ofrg(inss[i],0,R));
							}
							if(op2_f)
							{
								clr_rd(R,num_ofrg(inss[i],1,R));
							}
							if(op1_f&&op2_f&&!isFreeMathFunc)
							{
								buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
						    	act_fwait_time++;
							}
							else
							{
								buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
								act_wait_time++;
							}
						}
						break;
					}
		        }
	        }
			
		    for(;i<decode_of_num_i1;i++)
		    {
		    	buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
		    }
		    /*if(rtlMaxWord<RTL_A_WORD)
		    {
		    	int k=0;
		    	for(;k<RTL_A_WORD-rtlMaxWord;k++)
		    	{
		    		zeroize_ADDR(32,fp_saveRTLB);
		    		linefeed_ADDR(fp_saveRTLB);
		    	}
		    	rtlMaxWord=0;
		    }
		    else
		    {
		    	rtlMaxWord=rtlMaxWord-RTL_A_WORD;
		    }
		    if(myRTLDebug)
		    {
		    	linefeed_ADDR(fp_saveRTLB);
		    }*/
		    plst.decode_st=STG_BUSY;
		    plst.decode_cycle=DECODE_CYCLE;
			d_ins_n += decode_v_num;
		    if(decode_v_num != decode_of_num_i1)
			{
		    	decode_end=1;
			}
		    decode_f_num=decode_of_num_i1-decode_v_num;
			load_free_i1=load_free_i0;
			launch_free_i1=launch_free_i0;
			wb_free_i1=wb_free_i0;
			store_free_i1=store_free_i0;
			mov_free_i1=mov_free_i0;
			mov_free_i1=mov_free_i0;
	    }
	}
	else
	{
		if(plst.decode_if1==STG_READY)
		{
			int i=0,j=0;
			decode_v_num=0;
	    	for(;i<decode_of_num_i1;i++)
	    	{
	    		buff_f_ins[j++].buff_fetch_num=inss[i].decode_ins;
	    	}
			isDelay=0;
	    	plst.decode_st=STG_BUSY;
	    	plst.decode_cycle=DECODE_CYCLE;
			decode_end=1;
			decode_f_num=decode_of_num_i1;
			if(allF || !qGetD)
			{
				zeroize_ADDR(32,fp_saveRTLB);
                linefeed_ADDR(fp_saveRTLB);
                zeroize_ADDR(32,fp_saveRTLB);
                linefeed_ADDR(fp_saveRTLB);
                zeroize_ADDR(32,fp_saveRTLB);
                linefeed_ADDR(fp_saveRTLB);
                zeroize_ADDR(32,fp_saveRTLB);
                linefeed_ADDR(fp_saveRTLB);
			}
			rtlMaxWord=RTL_A_WORD;
			//if(myRTLDebug)
		    //{
		    //	linefeed_ADDR(fp_saveRTLB);
		   // }
			decodeDelayCycle=decodeDelayCycle-1;
			if(decodeDelayCycle==0)
			{
				allow_delay=0;
				isDecodeDelay=isDelay;
			}
		}
	}
	return 1;
}

bool pl_syn(int clk)
{
	if(isDelay)
	{
		isDecodeDelay=isDelay;
		decodeDelayCycle=delay_times;
	}
    if(plst.fetch_st==STG_BUSY)
    {
		int i;
		fetch_of_num_i1=fetch_of_num_i0;
		// judge is the quick running mode
		if (dugD)
		{
			//if (report_fl == 1)
			//{
				for (i = 0;i<fetch_of_num_i1;i++)
				{
					myprint_report("     FETCH :instruction ", decode_i0[i].decode_ins + 1, ": ", NULL, ins[decode_i0[i].decode_ins].instr, NULL);
					printf("     FETCH :instruction %d : %s\n", decode_i0[i].decode_ins + 1, ins[decode_i0[i].decode_ins].instr);
				}
			//}
			//if (report_fl == 1)
			//{
				fprintf(freport, "\n");
			//}
		}
        plst.fetch_cycle=plst.fetch_cycle-1;
        if(plst.fetch_cycle==0)
        {
            plst.fetch_st=STG_FREE;
            plst.decode_if0=STG_READY;
            plst.fetch_if1=STG_NRDY;
        }
    }
    if(((plst.fetch_if1==STG_NRDY)&&(fetch_n<ins_num))||(decode_end&&(plst.fetch_if1==STG_NRDY)))
    {
        //fetch_n++;
        plst.fetch_if0=STG_READY;
    }
    
	if (allF || rtlD)
	{
		/* \D3\C3\D3\DA\C5жϱ\BE\D6\DC\C6\DA\CAǷ\F1\D0\E8Ҫ\CA\E4\B3\F6ָ\C1\EE\B5Ķ\FE\BD\F8\D6ƴ\FA\C2\EB*/
		if (isToRTL == 1)
		{
			isToRTL = 0;
			int count_ins_b = 0;//\D3\C3\C0\B4\B1\E9\C0\FA\D4ݴ\E6\D0\E8Ҫת\BB\BBΪ\B6\FE\BD\F8\D6Ƶ\C4ָ\C1\EE\B5\C4\CA\FD\D7\E9
			for (;count_ins_b<10;count_ins_b++)
			{
				if (convTB[count_ins_b].is_exist_ins)
				{
					convert_ins_to_b(convTB[count_ins_b], fp_saveRTLB);
				}
			}
			memset(convTB, 0, sizeof(convTB));
		}
	}

	if(plst.decode_st==STG_BUSY)
	{
		int k;
		if (!qGetD)
		{
			if (decode_v_num)
			{
				int convTB_count = 0;
				for (k = 0;k<decode_of_num_i1;k++)
				{
					if ((decode_i1[k].decode_v))
					{
						if (dugD)
						{
							myprint_report("     DECODE :instruction ", decode_i1[k].decode_ins + 1, ": ", NULL, ins[decode_i1[k].decode_ins].instr, NULL);
							printf("     DECODE :instruction %d : %s\n", decode_i1[k].decode_ins + 1, ins[decode_i1[k].decode_ins].instr);
						}
						if (allF || rtlD)
						{
							convTB[convTB_count].is_exist_ins = 1;
		    				convTB[convTB_count].ex_ins = decode_i1[k].decode_ins;
		    				convTB[convTB_count].op[0] = decode_i1[k].op[0];
		    				convTB[convTB_count].op[1] = decode_i1[k].op[1];
		    				convTB[convTB_count].op[2] = decode_i1[k].op[2];
		    				convTB[convTB_count].op[3] = decode_i1[k].op[3];
		    				convTB_count++;
		    				isToRTL = 1;
						}
					}
				}
				//if (report_fl == 1)
				if (dugD)
				{
					fprintf(freport, "\n");
				}
			}
			if (dugD)
			{ 
				if (decode_f_num && (isDecodeDelay == 0))
	    		{
	    			for (k = 0;k<decode_f_num;k++)
	    			{
		    			if (buff_f_ins[k].buff_fetch_num != 0)
		    			{
		    				myprint_report("     DECODE FAILURE:instruction ", buff_f_ins[k].buff_fetch_num + 1, ": ", NULL, ins[buff_f_ins[k].buff_fetch_num].instr, NULL);
		    				printf("     DECODE FAILURE:instruction %d : %s\n", buff_f_ins[k].buff_fetch_num + 1, ins[buff_f_ins[k].buff_fetch_num].instr);
		    			}
		    		}
		    		//if (dugD)
		    		//{
					fprintf(freport, "\n");
				}
			}
		}
		
		plst.decode_cycle=plst.decode_cycle-1;
		if(plst.decode_cycle==0)
		{
			plst.exe_st0=STG_BUSY;
			plst.decode_st=STG_FREE;
			plst.decode_if1=STG_NRDY;
		}
		for(k=0;k<RG_NUM;k++)
		{
			clr_wwr(R,k);
			clr_wrd(R,k);
		}
		for(k=0;k<BV_NUM;k++)
		{
			clr_wwr(B,k);
			clr_wrd(B,k);
		}
		for(k=0;k<RDV_NUM;k++)
		{
			clr_wwr(RD,k);
			clr_wrd(RD,k);
		}
		for(k=0;k<M_LAYER;k++)
		{
			clr_M_wrd(k);
		    clr_M_wwr(k);
		}
		
		int m=0;
		for(k=0;k<MEM_BUFF_ENTRY_SIZE;k++)
		{
			for(m=0;m<MEM_BUFF_BANK_SIZE;m++)
			{
				clr_mb_data_wrd(0,k,m);
				clr_mb_data_wrd(1,k,m);
				clr_mb_data_wrd(2,k,m);
				clr_mb_data_wwr(0,k,m);
				clr_mb_data_wwr(1,k,m);
				clr_mb_data_wwr(2,k,m);
			}
		}


		clr_buffer_read(0);
		clr_buffer_write(0);
		clr_buffer_read(1);
		clr_buffer_write(1);
		clr_buffer_read(2);
		clr_buffer_write(2);
		
		clr_B_wrd(R);
		clr_B_wwr(R);
		clr_B_wrd(C);
		clr_B_wwr(C);
		clr_B_wrd(M);
		clr_B_wwr(M);

		clr_B_rd(R);
		clr_B_wr(R);
		clr_B_rd(C);
		clr_B_wr(C);
		clr_B_rd(M);
		clr_B_wr(M);
		// clear neuron arithmetic unit occupation
		isFreeNeuroUnit=plNeuroCalcUnitNum;
	}

	if(plst.loop_st == STG_BUSY)
	{
		int i_lst = 0,j_lst;
		if(endloopnum != 0)
		{
			for(i_lst=0;i_lst<endloopnum;i_lst++)
			{
				for(j_lst=0;j_lst<9;j_lst++)
				{
					if(loop_i1[j_lst].is_exist_ins)
					{
						continue;
					}
					else
					{
						break;
					}
				}
				loop_i1[j_lst-1].is_exist_ins = 0;
			}
			endloopnum=0;
		}
		
		int loop_C =0;
		for(i_lst=0;i_lst<LP_LAYER+1;i_lst++)
		{
			if(loop_i1[i_lst].is_exist_ins)
			{
				loop_C++;
				if (dugD)
				{
					myprint_report("     LOOP :instruction ", loop_i1[i_lst].ex_ins + 1, ": ", NULL, ins[loop_i1[i_lst].ex_ins].instr, NULL);
					printf("     LOOP :instruction %d : %s\n", loop_i1[i_lst].ex_ins + 1, ins[loop_i1[i_lst].ex_ins].instr);
				}
			}
		}
		if(loop_C == 0)
		{
			plst.loop_st = STG_FREE;
		}
	}

	if(plst.endloop_st == STG_BUSY)
	{
		int i_lst = 0;
		for(i_lst=0;i_lst<LP_LAYER+1;i_lst++)
		{
			if(endloop_i1[i_lst].is_exist_ins)
			{
				endloop_i1[i_lst].is_exist_ins = 0;
				if (dugD)
				{
					myprint_report("     ENDLOOP :instruction ", endloop_i1[i_lst].ex_ins + 1, ": ", NULL, ins[endloop_i1[i_lst].ex_ins].instr, NULL);
					printf("     ENDLOOP :instruction %d : %s\n", endloop_i1[i_lst].ex_ins + 1, ins[endloop_i1[i_lst].ex_ins].instr);
				}
			}
		}
		plst.endloop_st = STG_FREE;
		plst.endloop_if0 = STG_NRDY;
	}

    if(plst.load_st==STG_BUSY)
    {
		if(load_i1[0].is_exist_ins)
		{
			load(load_i1[0].op[0],load_i1[0].op[1].opd.length,load_i1[0].op[2].opd.type_BUFF.buff_id,load_i1[0].op[2].opd.type_BUFF.mem_b_addr,clk);

			int buff_id=load_i1[0].op[2].opd.type_BUFF.buff_id;
			int row,col;
			long length=load_i1[0].op[1].opd.length;
			long buff_addr=load_i1[0].op[2].opd.type_BUFF.mem_b_addr;
			row=buff_addr%MEM_BUFF_ENTRY_SIZE;
			col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			int i;
			if(buff_id==0)
			{
				clr_buffer_read(0);
				for(i=0;i<length;i++)
				{
					clr_mb_data_rd(0,row,col+i);
				}
			}
			else if(buff_id==1)
			{
				clr_buffer_read(1);
				for(i=0;i<length;i++)
				{
					clr_mb_data_rd(1,row,col+i);
				}
			}
			else if(buff_id==2)
			{
				clr_buffer_read(2);
				for(i=0;i<length;i++)
				{
					clr_mb_data_rd(2,row,col+i);
				}
			}
			else
			{

			}
		}
		if (dugD)
		{
			int i = 0;
			if (report_fl == 1)
			{
				for (;i<LOAD_CYCLE + 1;i++)
				{
					if (load_i1[LOAD_CYCLE - i].is_exist_ins)
					{
						myprint_report("     LOAD :instruction ", load_i1[LOAD_CYCLE - i].ex_ins + 1, ": ", NULL, ins[load_i1[LOAD_CYCLE - i].ex_ins].instr, NULL);
						printf("     LOAD :instruction %d : %s\n", load_i1[LOAD_CYCLE - i].ex_ins + 1, ins[load_i1[LOAD_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(load_i1,LOAD_CYCLE+1);
		plst.load_if1=STG_NRDY;
        load_execute_time++;
        //plst.load_cycle=plst.load_cycle-1;
		if(load_i1[LOAD_CYCLE].is_exist_ins)
        {
			//load(load_i1[LOAD_CYCLE].op[0],load_i1[LOAD_CYCLE].op[1].opd.length,load_i1[LOAD_CYCLE].op[2].opd.type_BUFF.buff_id,load_i1[LOAD_CYCLE].op[2].opd.type_BUFF.mem_b_addr,clk);

			load_i1[LOAD_CYCLE].is_exist_ins=0;
            if(judge_array_empty(load_i1,LOAD_CYCLE))
			{
				plst.load_st=STG_FREE;
			}
            //load_i1.op[0].op_r->state=RST_FREE;
			if(load_i1[LOAD_CYCLE].op[0].type_flag==0)
			{
				clr_wr(B,num_ofrg(load_i1[LOAD_CYCLE],0,B));
				clr_wwr(B,num_ofrg(load_i1[LOAD_CYCLE],0,B));
				clr_wrd(B,num_ofrg(load_i1[LOAD_CYCLE],0,B));
				memcpy(&PBV->R_V[num_ofrg(load_i1[LOAD_CYCLE],0,B)],&BV->R_V[num_ofrg(load_i1[LOAD_CYCLE],0,B)],sizeof(struct RB));
			}
			else if(load_i1[LOAD_CYCLE].op[0].type_flag==1)
			{
				clr_wr(R,num_ofrg(load_i1[LOAD_CYCLE],0,R));
				clr_wwr(R,num_ofrg(load_i1[LOAD_CYCLE],0,R));
				clr_wrd(R,num_ofrg(load_i1[LOAD_CYCLE],0,R));
				memcpy(&PRV->R_V[num_ofrg(load_i1[LOAD_CYCLE],0,R)],&RV->R_V[num_ofrg(load_i1[LOAD_CYCLE],0,R)],sizeof(struct RG));
			}
			else
			{
				clr_wr(RD,num_ofrg(load_i1[LOAD_CYCLE],0,R));
				clr_wwr(RD,num_ofrg(load_i1[LOAD_CYCLE],0,R));
				clr_wrd(RD,num_ofrg(load_i1[LOAD_CYCLE],0,R));
				memcpy(&PRDV->R_V[num_ofrg(load_i1[LOAD_CYCLE],0,R)],&RDV->R_V[num_ofrg(load_i1[LOAD_CYCLE],0,R)],sizeof(struct RG));
			}
			
			/*int buff_id=load_i1[LOAD_CYCLE].op[2].opd.type_BUFF.buff_id;
			int row,col;
			long length=load_i1[LOAD_CYCLE].op[1].opd.length;
			long buff_addr=load_i1[LOAD_CYCLE].op[2].opd.type_BUFF.mem_b_addr;
			row=buff_addr%MEM_BUFF_ENTRY_SIZE;
			col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			if(buff_id==0)
			{
				memcpy(pbuffer0,buffer0,sizeof(struct MEM_B));
				//clr_buffer_read(0);
				//for(i=0;i<length;i++)
				//{
				//	clr_mb_data_rd(0,row,col+i);
				//}
			}
			else if(buff_id==1)
			{
				//memcpy(pbuffer1,buffer1,sizeof(struct MEM_B));
				//clr_buffer_read(1);
				//for(i=0;i<length;i++)
				//{
				//	clr_mb_data_rd(1,row,col+i);
				//}
			}
			else if(buff_id==2)
			{
				//memcpy(pbuffer2,buffer2,sizeof(struct MEM_B));
				//clr_buffer_read(2);
				//for(i=0;i<length;i++)
				//{
				//	clr_mb_data_rd(2,row,col+i);
				//}
			}
			else
			{
				
			}*/
        }
    }

    if(plst.launch_st==STG_BUSY)
    {
        int i;
		if(launch_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(launch_i1[0],fp_saveRTLB);
			launch(launch_i1[0].op[0].opd.type_MAT.pMAT,launch_i1[0].op[0].opd.type_MAT.row,launch_i1[0].op[0].opd.type_MAT.col,launch_i1[0].op[1].opd.type_BUFF.buff_id,launch_i1[0].op[1].opd.type_BUFF.mem_b_addr,launch_i1[0].op[0].opd.type_MAT.mat_num,clk);

			int buff_id=launch_i1[0].op[1].opd.type_BUFF.buff_id;
			int row=launch_i1[0].op[0].opd.type_MAT.row;
			long buff_addr=launch_i1[0].op[1].opd.type_BUFF.mem_b_addr;
			int row_b=buff_addr%MEM_BUFF_ENTRY_SIZE;
			int col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			int m,k;
			if(buff_id==0)
			{
				clr_buffer_read(0);
				for(k=0;k<row;k++)
				{
					for(m=0;m<V_SIZE;m++)
					{
						clr_mb_data_rd(0,row_b,col+m);
					}
					col=col+V_SIZE;
				}
			}
			else if(buff_id==1)
			{
				clr_buffer_read(1);
				for(k=0;k<row;k++)
				{
					for(m=0;m<V_SIZE;m++)
					{
						clr_mb_data_rd(1,row_b,col+m);
					}
					col=col+V_SIZE;
				}
			}
			else if(buff_id==2)
			{
				clr_buffer_read(2);
				for(k=0;k<row;k++)
				{
					for(m=0;m<V_SIZE;m++)
					{
						clr_mb_data_rd(2,row_b,col+m);
					}
					col=col+V_SIZE;
				}
			}
			else
			{

			}
		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				for (i = 0;i<LAUNCH_CYCLE + 1;i++)
				{
					if (launch_i1[LAUNCH_CYCLE - i].is_exist_ins)
					{
						myprint_report("     LAUNCH :instruction ", launch_i1[LAUNCH_CYCLE - i].ex_ins + 1, ": ", NULL, ins[launch_i1[LAUNCH_CYCLE - i].ex_ins].instr, NULL);
						printf("     LAUNCH :instruction %d : %s\n", launch_i1[LAUNCH_CYCLE - i].ex_ins + 1, ins[launch_i1[LAUNCH_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(launch_i1,LAUNCH_CYCLE+1);
		plst.launch_if1=STG_NRDY;
        launch_execute_time++;
        //plst.launch_cycle=plst.launch_cycle-1;
		if(launch_i1[LAUNCH_CYCLE].is_exist_ins)
        {
			//launch(launch_i1[LAUNCH_CYCLE].op[0].opd.type_MAT.pMAT,launch_i1[LAUNCH_CYCLE].op[0].opd.type_MAT.row,launch_i1[LAUNCH_CYCLE].op[0].opd.type_MAT.col,launch_i1[LAUNCH_CYCLE].op[1].opd.type_BUFF.buff_id,launch_i1[LAUNCH_CYCLE].op[1].opd.type_BUFF.mem_b_addr,launch_i1[LAUNCH_CYCLE].op[0].opd.type_MAT.mat_num,clk);

			launch_i1[LAUNCH_CYCLE].is_exist_ins=0;
			if(judge_array_empty(launch_i1,LAUNCH_CYCLE))
			{
				plst.launch_st=STG_FREE;
			}
			int layer;
			layer=launch_i1[LAUNCH_CYCLE].op[0].opd.type_MAT.mat_num;
			clr_M_wr(layer);
			memcpy(PMAT[layer],MAT[layer],sizeof(struct G_M));
			/*int buff_id=launch_i1[LAUNCH_CYCLE].op[1].opd.type_BUFF.buff_id;
			int row=launch_i1[LAUNCH_CYCLE].op[0].opd.type_MAT.row;
			long buff_addr=launch_i1[LAUNCH_CYCLE].op[1].opd.type_BUFF.mem_b_addr;
			int row_b=buff_addr%MEM_BUFF_ENTRY_SIZE;
	        int col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			int m,k;
			if(buff_id==0)
			{
				clr_buffer_read(0);
				for(k=0;k<row;k++)
				{
					for(m=0;m<V_SIZE;m++)
					{
						clr_mb_data_rd(0,row_b,col+m);
					}
					col=col+V_SIZE;
				}
			}
			else if(buff_id==1)
			{
				clr_buffer_read(1);
				for(k=0;k<row;k++)
				{
					for(m=0;m<V_SIZE;m++)
					{
						clr_mb_data_rd(1,row_b,col+m);
					}
					col=col+V_SIZE;
				}
			}
			else if(buff_id==2)
			{
				clr_buffer_read(2);
				for(k=0;k<row;k++)
				{
					for(m=0;m<V_SIZE;m++)
					{
						clr_mb_data_rd(2,row_b,col+m);
					}
					col=col+V_SIZE;
				}
			}
			else
			{
				
			}*/
        }
    }

	if(plst.wb_st==STG_BUSY)
    {
		if(wb_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(wb_i1[0],fp_saveRTLB);
			wb(wb_i1[0].op[0].opd.type_MAT.pMAT,wb_i1[0].op[0].opd.type_MAT.row,wb_i1[0].op[0].opd.type_MAT.col,wb_i1[0].op[1].opd.type_BUFF.buff_id,wb_i1[0].op[1].opd.type_BUFF.mem_b_addr,wb_i1[0].op[0].opd.type_MAT.mat_num,clk);

			int layer;
			layer=wb_i1[0].op[0].opd.type_MAT.mat_num;
			clr_M_rd(layer);
		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<WB_CYCLE + 1;i++)
				{
					if (wb_i1[WB_CYCLE - i].is_exist_ins)
					{
						myprint_report("     WB :instruction ", wb_i1[WB_CYCLE - i].ex_ins + 1, ": ", NULL, ins[wb_i1[WB_CYCLE - i].ex_ins].instr, NULL);
						printf("     WB :instruction %d : %s\n", wb_i1[WB_CYCLE - i].ex_ins + 1, ins[wb_i1[WB_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(wb_i1,WB_CYCLE+1);
		plst.wb_if1=STG_NRDY;
        wb_execute_time++;
        //plst.wb_cycle=plst.wb_cycle-1;
		if(wb_i1[WB_CYCLE].is_exist_ins)
        {
			//wb(wb_i1[WB_CYCLE].op[0].opd.type_MAT.pMAT,wb_i1[WB_CYCLE].op[0].opd.type_MAT.row,wb_i1[WB_CYCLE].op[0].opd.type_MAT.col,wb_i1[WB_CYCLE].op[1].opd.type_BUFF.buff_id,wb_i1[WB_CYCLE].op[1].opd.type_BUFF.mem_b_addr,wb_i1[WB_CYCLE].op[0].opd.type_MAT.mat_num,clk);

			wb_i1[WB_CYCLE].is_exist_ins=0;
			if(judge_array_empty(wb_i1,WB_CYCLE))
			{
				plst.wb_st=STG_FREE;
			}
			//int layer;
			//layer=wb_i1[WB_CYCLE].op[0].opd.type_MAT.mat_num;
			//clr_M_rd(layer);
			int buff_id=wb_i1[WB_CYCLE].op[1].opd.type_BUFF.buff_id;
			int row=wb_i1[WB_CYCLE].op[0].opd.type_MAT.row;
			long buff_addr=wb_i1[WB_CYCLE].op[1].opd.type_BUFF.mem_b_addr;
			int row_b=buff_addr%MEM_BUFF_ENTRY_SIZE;
	        int col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			int m,k;
			if(buff_id==0)
			{
				clr_buffer_write(0);
				for(k=0;k<row;k++)
				{
					for(m=0;m<V_SIZE;m++)
					{
						clr_mb_data_wr(0,row_b,col+m);
					}
					col=col+V_SIZE;
				}
				memcpy(pbuff0,buff0,sizeof(struct MEM_B));
			}
			else if(buff_id==1)
			{
				clr_buffer_write(1);
				for(k=0;k<row;k++)
				{
					for(m=0;m<V_SIZE;m++)
					{
						clr_mb_data_wr(1,row_b,col+m);
					}
					col=col+V_SIZE;
				}
				memcpy(pbuff1,buff1,sizeof(struct MEM_B));
			}
			else if(buff_id==2)
			{
				clr_buffer_write(2);
				for(k=0;k<row;k++)
				{
					for(m=0;m<V_SIZE;m++)
					{
						clr_mb_data_wr(2,row_b,col+m);
					}
					col=col+V_SIZE;
				}
				memcpy(pbuff2,buff2,sizeof(struct MEM_B));
			}
			else
			{
				
			}
        }
    }

    if(plst.store_st==STG_BUSY)
    {
		if(store_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(store_i1[0],fp_saveRTLB);
			store(store_i1[0].op[0], store_i1[0].op[1].opd.length, store_i1[0].op[2].opd.type_BUFF.buff_id,store_i1[0].op[2].opd.type_BUFF.mem_b_addr,clk);

			if(store_i1[0].op[0].type_flag==0)
			{
				clr_rd(B,num_ofrg(store_i1[0],0,B));
				clr_wwr(B,num_ofrg(store_i1[0],0,B));
				clr_wrd(B,num_ofrg(store_i1[0],0,B));
			}
			else if(store_i1[0].op[0].type_flag==1)
			{
				clr_rd(R,num_ofrg(store_i1[0],0,R));
				clr_wwr(R,num_ofrg(store_i1[0],0,R));
				clr_wrd(R,num_ofrg(store_i1[0],0,R));
			}
			else
			{
				clr_rd(RD,num_ofrg(store_i1[0],0,R));
				clr_wwr(RD,num_ofrg(store_i1[0],0,R));
				clr_wrd(RD,num_ofrg(store_i1[0],0,R));
			}
		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<STORE_CYCLE + 1;i++)
				{
					if (store_i1[STORE_CYCLE - i].is_exist_ins)
					{
						myprint_report("     STORE :instruction ", store_i1[STORE_CYCLE - i].ex_ins + 1, ": ", NULL, ins[store_i1[STORE_CYCLE - i].ex_ins].instr, NULL);
						printf("     STORE :instruction %d : %s\n", store_i1[STORE_CYCLE - i].ex_ins + 1, ins[store_i1[STORE_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(store_i1,STORE_CYCLE+1);
        plst.store_if1=STG_NRDY;
        store_execute_time++;
        //plst.store_cycle=plst.store_cycle-1;
		if(store_i1[STORE_CYCLE].is_exist_ins)
        {
			//store(store_i1[STORE_CYCLE].op[0], store_i1[STORE_CYCLE].op[1].opd.length, store_i1[STORE_CYCLE].op[2].opd.type_BUFF.buff_id,store_i1[STORE_CYCLE].op[2].opd.type_BUFF.mem_b_addr,clk);

			store_i1[STORE_CYCLE].is_exist_ins=0;
			if(judge_array_empty(store_i1,STORE_CYCLE))
			{
				plst.store_st=STG_FREE;
			}
			/*if(store_i1[STORE_CYCLE].op[0].type_flag==0)
			{
			clr_rd(B,num_ofrg(store_i1[STORE_CYCLE],0,B));
			clr_wwr(B,num_ofrg(store_i1[STORE_CYCLE],0,B));
			clr_wrd(B,num_ofrg(store_i1[STORE_CYCLE],0,B));
			}
			else if(store_i1[STORE_CYCLE].op[0].type_flag==1)
			{
			clr_rd(R,num_ofrg(store_i1[STORE_CYCLE],0,R));
			clr_wwr(R,num_ofrg(store_i1[STORE_CYCLE],0,R));
			clr_wrd(R,num_ofrg(store_i1[STORE_CYCLE],0,R));
			}
			else
			{
			clr_rd(RD,num_ofrg(store_i1[STORE_CYCLE],0,R));
			clr_wwr(RD,num_ofrg(store_i1[STORE_CYCLE],0,R));
			clr_wrd(RD,num_ofrg(store_i1[STORE_CYCLE],0,R));
			}*/
			
			int buff_id=store_i1[STORE_CYCLE].op[2].opd.type_BUFF.buff_id;
			int row,col;
			long length=store_i1[STORE_CYCLE].op[1].opd.length;
			long buff_addr=store_i1[STORE_CYCLE].op[2].opd.type_BUFF.mem_b_addr;
			row=buff_addr%MEM_BUFF_ENTRY_SIZE;
			col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			int k=0;
			if(buff_id==0)
			{
				clr_buffer_write(0);
				for(k=0;k<length;k++)
				{
					clr_mb_data_wr(0,row,col+k);
				}
				memcpy(pbuff0,buff0,sizeof(struct MEM_B));
			}
			else if(buff_id==1)
			{
				clr_buffer_write(1);
				for(k=0;k<length;k++)
				{
					clr_mb_data_wr(1,row,col+k);
				}
				memcpy(pbuff1,buff1,sizeof(struct MEM_B));
			}
			else if(buff_id==2)
			{
				clr_buffer_write(2);
				for(k=0;k<length;k++)
				{
					clr_mb_data_wr(2,row,col+k);
				}
				memcpy(pbuff2,buff2,sizeof(struct MEM_B));
			}
			else
			{
				
			}
        }
    }

	if(plst.mov_st==STG_BUSY)
	{
		if(mov_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(mov_i1[0],fp_saveRTLB);
			mov(mov_i1[0].op[0],mov_i1[0].op[1],clk);

			if(mov_i1[0].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(mov_i1[0],1,B));
				clr_wwr(B,num_ofrg(mov_i1[0],1,B));
				clr_wrd(B,num_ofrg(mov_i1[0],1,B));
			}
			else if(mov_i1[0].op[1].type_flag==1)
			{
				clr_rd(R,num_ofrg(mov_i1[0],1,R));
				clr_wwr(R,num_ofrg(mov_i1[0],1,R));
				clr_wrd(R,num_ofrg(mov_i1[0],1,R));
			}
			else
			{
				clr_rd(RD,num_ofrg(mov_i1[0],1,R));
				clr_wwr(RD,num_ofrg(mov_i1[0],1,R));
				clr_wrd(RD,num_ofrg(mov_i1[0],1,R));
			}
		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<MOV_CYCLE + 1;i++)
				{
					if (mov_i1[MOV_CYCLE - i].is_exist_ins)
					{
						myprint_report("     MOV :instruction ", mov_i1[MOV_CYCLE - i].ex_ins + 1, ": ", NULL, ins[mov_i1[MOV_CYCLE - i].ex_ins].instr, NULL);
						printf("     MOV :instruction %d : %s\n", mov_i1[MOV_CYCLE - i].ex_ins + 1, ins[mov_i1[MOV_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(mov_i1,MOV_CYCLE+1);
		plst.mov_if1=STG_NRDY;
    	mov_execute_time++;
		//plst.mov_cycle=plst.mov_cycle-1;
		if(mov_i1[MOV_CYCLE].is_exist_ins)
		{
			//mov(mov_i1[MOV_CYCLE].op[0],mov_i1[MOV_CYCLE].op[1],clk);

			mov_i1[MOV_CYCLE].is_exist_ins=0;
			if(judge_array_empty(mov_i1,MOV_CYCLE))
			{
				plst.mov_st=STG_FREE;
			}
			if(mov_i1[MOV_CYCLE].op[0].type_flag==0)
			{
				clr_wr(B,num_ofrg(mov_i1[MOV_CYCLE],0,B));
				clr_wwr(B,num_ofrg(mov_i1[MOV_CYCLE],0,B));
				clr_wrd(B,num_ofrg(mov_i1[MOV_CYCLE],0,B));
				memcpy(&PBV->R_V[num_ofrg(mov_i1[MOV_CYCLE],0,B)],&BV->R_V[num_ofrg(mov_i1[MOV_CYCLE],0,B)],sizeof(struct RB));
			}
			else if(mov_i1[MOV_CYCLE].op[0].type_flag==1)
			{
				clr_wr(R,num_ofrg(mov_i1[MOV_CYCLE],0,R));
				clr_wwr(R,num_ofrg(mov_i1[MOV_CYCLE],0,R));
				clr_wrd(R,num_ofrg(mov_i1[MOV_CYCLE],0,R));
				memcpy(&PRV->R_V[num_ofrg(mov_i1[MOV_CYCLE],0,R)],&RV->R_V[num_ofrg(mov_i1[MOV_CYCLE],0,R)],sizeof(struct RG));
			}
			else
			{
				clr_wr(RD,num_ofrg(mov_i1[MOV_CYCLE],0,R));
				clr_wwr(RD,num_ofrg(mov_i1[MOV_CYCLE],0,R));
				clr_wrd(RD,num_ofrg(mov_i1[MOV_CYCLE],0,R));
				memcpy(&PRDV->R_V[num_ofrg(mov_i1[MOV_CYCLE],0,R)],&RDV->R_V[num_ofrg(mov_i1[MOV_CYCLE],0,R)],sizeof(struct RG));
			}
			 /*if(mov_i1[MOV_CYCLE].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(mov_i1[MOV_CYCLE],1,B));
				clr_wwr(B,num_ofrg(mov_i1[MOV_CYCLE],1,B));
				clr_wrd(B,num_ofrg(mov_i1[MOV_CYCLE],1,B));
			}
			else if(mov_i1[MOV_CYCLE].op[1].type_flag==1)
			{
				clr_rd(R,num_ofrg(mov_i1[MOV_CYCLE],1,R));
				clr_wwr(R,num_ofrg(mov_i1[MOV_CYCLE],1,R));
				clr_wrd(R,num_ofrg(mov_i1[MOV_CYCLE],1,R));
			}
			else
			{
				clr_rd(RD,num_ofrg(mov_i1[MOV_CYCLE],1,R));
				clr_wwr(RD,num_ofrg(mov_i1[MOV_CYCLE],1,R));
				clr_wrd(RD,num_ofrg(mov_i1[MOV_CYCLE],1,R));
			}*/
		}
	}

	if(plst.extmov_st==STG_BUSY)
	{
		if(extmov_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(extmov_i1[0],fp_saveRTLB);
			extmov(extmov_i1[0].op[0],extmov_i1[0].op[1],clk);

			if(extmov_i1[0].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(extmov_i1[0],1,B));
				clr_wwr(B,num_ofrg(extmov_i1[0],1,B));
				clr_wrd(B,num_ofrg(extmov_i1[0],1,B));
			}
			else if(extmov_i1[0].op[1].type_flag==1)
			{
				clr_rd(R,num_ofrg(extmov_i1[0],1,R));
				clr_wwr(R,num_ofrg(extmov_i1[0],1,R));
				clr_wrd(R,num_ofrg(extmov_i1[0],1,R));
			}
			else if(extmov_i1[0].op[1].type_flag==2)
			{
				clr_rd(RD,num_ofrg(extmov_i1[0],1,R));
				clr_wwr(RD,num_ofrg(extmov_i1[0],1,R));
				clr_wrd(RD,num_ofrg(extmov_i1[0],1,R));
			}
			else
			{
				clr_rd(EXT,num_ofrg(extmov_i1[0],1,R));
				clr_wwr(EXT,num_ofrg(extmov_i1[0],1,R));
				clr_wrd(EXT,num_ofrg(extmov_i1[0],1,R));
			}
		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<EXTMOV_CYCLE + 1;i++)
				{
					if (extmov_i1[EXTMOV_CYCLE - i].is_exist_ins)
					{
						myprint_report("     EXTMOV :instruction ", extmov_i1[EXTMOV_CYCLE - i].ex_ins + 1, ": ", NULL, ins[extmov_i1[EXTMOV_CYCLE - i].ex_ins].instr, NULL);
						printf("     EXTMOV :instruction %d : %s\n", extmov_i1[EXTMOV_CYCLE - i].ex_ins + 1, ins[extmov_i1[EXTMOV_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(extmov_i1,EXTMOV_CYCLE+1);
		plst.extmov_if1=STG_NRDY;
	    extmov_execute_time++;
	    //plst.extmov_cycle=plst.extmov_cycle-1;
		if(extmov_i1[EXTMOV_CYCLE].is_exist_ins)
	    {
			//extmov(extmov_i1[EXTMOV_CYCLE].op[0],extmov_i1[EXTMOV_CYCLE].op[1],clk);

			extmov_i1[EXTMOV_CYCLE].is_exist_ins=0;
			if(judge_array_empty(extmov_i1,EXTMOV_CYCLE))
			{
				plst.extmov_st=STG_FREE;
			}
	    	if(extmov_i1[EXTMOV_CYCLE].op[0].type_flag==0)
	    	{
	    		clr_wr(B,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,B));
	    		clr_wwr(B,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,B));
	    		clr_wrd(B,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,B));
				memcpy(&PBV->R_V[num_ofrg(extmov_i1[EXTMOV_CYCLE],0,B)],&BV->R_V[num_ofrg(extmov_i1[EXTMOV_CYCLE],0,B)],sizeof(struct RB));
	    	}
	    	else if(extmov_i1[EXTMOV_CYCLE].op[0].type_flag==1)
	    	{
	    		clr_wr(R,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R));
	    		clr_wwr(R,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R));
	    		clr_wrd(R,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R));
				memcpy(&PRV->R_V[num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R)],&RV->R_V[num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R)],sizeof(struct RG));
	    	}
	    	else if(extmov_i1[EXTMOV_CYCLE].op[0].type_flag==2)
	    	{
	    		clr_wr(RD,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R));
	    		clr_wwr(RD,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R));
	    		clr_wrd(RD,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R));
				memcpy(&PRDV->R_V[num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R)],&RDV->R_V[num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R)],sizeof(struct RG));
	    	}
	    	else
	    	{
	    		clr_wr(EXT,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R));
	    		clr_wwr(EXT,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R));
	    		clr_wrd(EXT,num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R));
				memcpy(&PEXTV->R_V[num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R)],&EXTV->R_V[num_ofrg(extmov_i1[EXTMOV_CYCLE],0,R)],sizeof(struct RG));
	    	}
	    	/* if(extmov_i1[EXTMOV_CYCLE].op[1].type_flag==0)
	    	{
	    		clr_rd(B,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,B));
	    		clr_wwr(B,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,B));
	    		clr_wrd(B,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,B));
	    	}
	    	else if(extmov_i1[EXTMOV_CYCLE].op[1].type_flag==1)
	    	{
	    		clr_rd(R,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,R));
	    		clr_wwr(R,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,R));
	    		clr_wrd(R,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,R));
	    	}
	    	else if(extmov_i1[EXTMOV_CYCLE].op[1].type_flag==2)
	    	{
	    		clr_rd(RD,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,R));
	    		clr_wwr(RD,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,R));
	    		clr_wrd(RD,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,R));
	    	}
	    	else
	    	{
	    		clr_rd(EXT,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,R));
	    		clr_wwr(EXT,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,R));
	    		clr_wrd(EXT,num_ofrg(extmov_i1[EXTMOV_CYCLE],1,R));
	    	}*/
		}
	}

	if(plst.dmalr_st==STG_BUSY)
	{
		//if(plst.dmalr_cycle==DMALR_CYCLE)
		//{
		//	convert_ins_to_b(dmalr_i1,fp_saveRTLB);
		//}
		if (dugD)
		{
			if (report_fl == 1)
			{
				myprint_report("     DMALR :instruction ", dmalr_i1.ex_ins + 1, ": ", NULL, ins[dmalr_i1.ex_ins].instr, NULL);
				printf("     DMALR :instruction %d : %s\n", dmalr_i1.ex_ins + 1, ins[dmalr_i1.ex_ins].instr);
			}
		}
		dmalr_execute_time++;
		plst.dmalr_cycle=plst.dmalr_cycle-1;
		if(plst.dmalr_cycle==0)
		{

			onlyDma=1;
			dmalr(dmalr_i1.op[0],clk);
			plst.dmalr_st=STG_FREE;
			plst.dmalr_if1=STG_NRDY;
			 
			int buff_id;
			
			buff_id=dmalr_i1.op[0].opd.type_DMA.buff_id;
			long buff_addr=dmalr_i1.op[0].opd.type_DMA.buff_addr;
			int repetition=dmalr_i1.op[0].opd.type_DMA.repetition;
			int row=buff_addr%MEM_BUFF_ENTRY_SIZE;
    		int col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			int count,j;
			if(buff_id==0)
			{
				clr_buffer_write(0);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_wr(0,row,col+j);
					}
					col=MEM_BUFF_BOLCK_SIZE+col;
				}
				memcpy(pbuff0,buff0,sizeof(struct MEM_B));
			}
			else if(buff_id==1)
			{
				clr_buffer_write(1);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_wr(1,row,col+j);
					}
					col=MEM_BUFF_BOLCK_SIZE+col;
				}
				memcpy(pbuff1,buff1,sizeof(struct MEM_B));
			}
			else if(buff_id==2)
			{
				clr_buffer_write(2);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_wr(2,row,col+j);
					}
					col=MEM_BUFF_BOLCK_SIZE+col;
				}
				memcpy(pbuff2,buff2,sizeof(struct MEM_B));
    		}
			else
			{
				print_error_ex("using not exist buffer in dmalr .");
			}
		}
	}
	
    if(plst.dmalc_st==STG_BUSY)
	{
		//if(plst.dmalc_cycle==DMALC_CYCLE)
		//{
		//	convert_ins_to_b(dmalc_i1,fp_saveRTLB);
		//}
		if (dugD)
		{
			if (report_fl == 1)
			{
				myprint_report("     DMALC :instruction ", dmalc_i1.ex_ins + 1, ": ", NULL, ins[dmalc_i1.ex_ins].instr, NULL);
				printf("     DMALC :instruction %d : %s\n", dmalc_i1.ex_ins + 1, ins[dmalc_i1.ex_ins].instr);
			}
		}
		dmalc_execute_time++;
		plst.dmalc_cycle=plst.dmalc_cycle-1;
		if(plst.dmalc_cycle==0)
		{
			dmalc(dmalc_i1.op[0],clk);


			onlyDma=1;
			plst.dmalc_st=STG_FREE;
			plst.dmalc_if1=STG_NRDY;
			//int k,l,m;
			//int length,stride,repetition,buff_id;
			int buff_id;
			//int row,col;
			//long mem_addr,buff_addr,mem_addr1;
			//length=dmalc_i1.op[0].opd.type_DMA.length;
			//stride=dmalc_i1.op[0].opd.type_DMA.stride;
			//repetition=dmalc_i1.op[0].opd.type_DMA.repetition;
			buff_id=dmalc_i1.op[0].opd.type_DMA.buff_id;
			long buff_addr=dmalc_i1.op[0].opd.type_DMA.buff_addr;
			int repetition=dmalc_i1.op[0].opd.type_DMA.repetition;
			int row=buff_addr%MEM_BUFF_ENTRY_SIZE;
    		int col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			int count,j;
			if(buff_id==0)
			{
				clr_buffer_write(0);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_wr(0,row+j,col);
					}
					row=MEM_BUFF_BOLCK_SIZE+row;
				}
				memcpy(pbuff0,buff0,sizeof(struct MEM_B));
			}
			else if(buff_id==1)
			{
				clr_buffer_write(1);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_wr(1,row+j,col);
					}
					row=MEM_BUFF_BOLCK_SIZE+row;
				}
				memcpy(pbuff1,buff1,sizeof(struct MEM_B));
			}
			else if(buff_id==2)
			{
				clr_buffer_write(2);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_wr(2,row+j,col);
					}
					row=MEM_BUFF_BOLCK_SIZE+row;
				}
				memcpy(pbuff1,buff1,sizeof(struct MEM_B));
    		}
			else
			{
				print_error_ex("using not exist buffer in dmalc .");
			}
		}
	}
	
	if(plst.dmasr_st==STG_BUSY)
	{
		//if(plst.dmasr_cycle==DMASR_CYCLE)
		//{
		//	convert_ins_to_b(dmasr_i1,fp_saveRTLB);
		//}
		if (dugD)
		{
			if (report_fl == 1)
			{
				myprint_report("     DMASR :instruction ", dmasr_i1.ex_ins + 1, ": ", NULL, ins[dmasr_i1.ex_ins].instr, NULL);
				printf("     DMASR :instruction %d : %s\n", dmasr_i1.ex_ins + 1, ins[dmasr_i1.ex_ins].instr);
			}
		}
		dmasr_execute_time++;
		plst.dmasr_cycle=plst.dmasr_cycle-1;
		if(plst.dmasr_cycle==0)
		{
			dmasr(dmasr_i1.op[0],clk);


			onlyDma=1;
			plst.dmasr_st=STG_FREE;
			plst.dmasr_if1=STG_NRDY;
			 
			int buff_id;
			buff_id=dmasr_i1.op[0].opd.type_DMA.buff_id;
			long buff_addr=dmasr_i1.op[0].opd.type_DMA.buff_addr;
			int repetition=dmasr_i1.op[0].opd.type_DMA.repetition;
			int row=buff_addr%MEM_BUFF_ENTRY_SIZE;
    		int col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			int count,j;
			if(buff_id==0)
			{
				clr_buffer_read(0);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_rd(0,row,col+j);
					}
					col=MEM_BUFF_BOLCK_SIZE+col;
				}
			}
			else if(buff_id==1)
			{
				clr_buffer_read(1);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_rd(1,row,col+j);
					}
					col=MEM_BUFF_BOLCK_SIZE+col;
				}
			}
			else if(buff_id==2)
			{
				clr_buffer_read(2);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_rd(2,row,col+j);
					}
					col=MEM_BUFF_BOLCK_SIZE+col;
				}
    		}
			else
			{
				print_error_ex("using not exist buffer in dmasr .");
			}
		}
	}
	
	if(plst.dmasc_st==STG_BUSY)
	{
		//if(plst.dmasc_cycle==DMASC_CYCLE)
		//{
		//	convert_ins_to_b(dmasc_i1,fp_saveRTLB);
		//}
		if (dugD)
		{
			if (report_fl == 1)
			{
				myprint_report("     DMASC :instruction ", dmasc_i1.ex_ins + 1, ": ", NULL, ins[dmasc_i1.ex_ins].instr, NULL);
				printf("     DMASC :instruction %d : %s\n", dmasc_i1.ex_ins + 1, ins[dmasc_i1.ex_ins].instr);
			}
		}
		dmasc_execute_time++;
		plst.dmasc_cycle=plst.dmasc_cycle-1;
		if(plst.dmasc_cycle==0)
		{
			dmasc(dmasc_i1.op[0],clk);


			onlyDma=1;
			plst.dmasc_st=STG_FREE;
			plst.dmasc_if1=STG_NRDY;
			
			int buff_id;
			buff_id=dmasc_i1.op[0].opd.type_DMA.buff_id;
			long buff_addr=dmasc_i1.op[0].opd.type_DMA.buff_addr;
			int repetition=dmasc_i1.op[0].opd.type_DMA.repetition;
			int row=buff_addr%MEM_BUFF_ENTRY_SIZE;
    		int col=buff_addr/MEM_BUFF_ENTRY_SIZE;
			int count,j;
			if(buff_id==0)
			{
				clr_buffer_read(0);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_rd(0,row+j,col);
					}
					row=MEM_BUFF_BOLCK_SIZE+row;
				}
			}
			else if(buff_id==1)
			{
				clr_buffer_read(1);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_rd(1,row+j,col);
					}
					row=MEM_BUFF_BOLCK_SIZE+row;
				}
			}
			else if(buff_id==2)
			{
				clr_buffer_read(2);
				for(count=0;count<repetition;count++)
				{
					for(j=0;j<MEM_BUFF_BOLCK_SIZE;j++)
					{
						clr_mb_data_rd(2,row+j,col);
					}
					row=MEM_BUFF_BOLCK_SIZE+row;
				}
    		}
			else
			{
				print_error_ex("using not exist buffer in dmasc .");
			}
		}
	}
	
	if(plst.prodvm_st==STG_BUSY)
    {
		if(prodvm_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(prodvm_i1[0],fp_saveRTLB);
			prodvm(prodvm_i1[0].op[0], prodvm_i1[0].op[1], prodvm_i1[0].op[2].opd.type_MAT.pMAT,prodvm_i1[0].op[3],prodvm_i1[0].op[2].opd.type_MAT.mat_num,clk,prodvm_i1[0].ex_ins);

			if(prodvm_i1[0].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvm_i1[0],1,B));
				clr_wwr(B,num_ofrg(prodvm_i1[0],1,B));
				clr_wrd(B,num_ofrg(prodvm_i1[0],1,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvm_i1[0],1,R));
				clr_wwr(R,num_ofrg(prodvm_i1[0],1,R));
				clr_wrd(R,num_ofrg(prodvm_i1[0],1,R));
			}

			clr_M_rd(prodvm_i1[0].op[2].opd.type_MAT.mat_num);
			clr_M_wrd(prodvm_i1[0].op[2].opd.type_MAT.mat_num);
			clr_M_wwr(prodvm_i1[0].op[2].opd.type_MAT.mat_num);
		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<PRODVM_CYCLE + 1;i++)
				{
					if (prodvm_i1[PRODVM_CYCLE - i].is_exist_ins)
					{
						myprint_report("     PRODVM :instruction ", prodvm_i1[PRODVM_CYCLE - i].ex_ins + 1, ": ", NULL, ins[prodvm_i1[PRODVM_CYCLE - i].ex_ins].instr, NULL);
						printf("     PRODVM :instruction %d : %s\n", prodvm_i1[PRODVM_CYCLE - i].ex_ins + 1, ins[prodvm_i1[PRODVM_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(prodvm_i1,PRODVM_CYCLE+1);
		plst.prodvm_if1=STG_NRDY;
        prodvm_execute_time++;
        //plst.prodvm_cycle=plst.prodvm_cycle-1;
		//plst.prodvm_cycle_func=plst.prodvm_cycle_func-1;
		if(prodvm_i1[PRODVM_CYCLE].is_exist_ins)
        {
			/*prodvm(prodvm_i1[PRODVM_CYCLE].op[0], prodvm_i1[0].op[1], prodvm_i1[PRODVM_CYCLE].op[2].opd.type_MAT.pMAT,prodvm_i1[0].op[3],prodvm_i1[PRODVM_CYCLE].op[2].opd.type_MAT.mat_num,clk);
*/
			prodvm_i1[PRODVM_CYCLE].is_exist_ins=0;
			if(judge_array_empty(prodvm_i1,PRODVM_CYCLE))
			{
				plst.prodvm_st=STG_FREE;
			}
            clr_wr(R,num_ofrg(prodvm_i1[PRODVM_CYCLE],0,R));
			clr_wwr(R,num_ofrg(prodvm_i1[PRODVM_CYCLE],0,R));
			clr_wrd(R,num_ofrg(prodvm_i1[PRODVM_CYCLE],0,R));
			memcpy(&PRV->R_V[num_ofrg(prodvm_i1[PRODVM_CYCLE],0,R)],&RV->R_V[num_ofrg(prodvm_i1[PRODVM_CYCLE],0,R)],sizeof(struct RG));

			/*if(prodvm_i1[PRODVM_CYCLE].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvm_i1[PRODVM_CYCLE],1,B));
				clr_wwr(B,num_ofrg(prodvm_i1[PRODVM_CYCLE],1,B));
				clr_wrd(B,num_ofrg(prodvm_i1[PRODVM_CYCLE],1,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvm_i1[PRODVM_CYCLE],1,R));
				clr_wwr(R,num_ofrg(prodvm_i1[PRODVM_CYCLE],1,R));
				clr_wrd(R,num_ofrg(prodvm_i1[PRODVM_CYCLE],1,R));
			}

			clr_M_rd(prodvm_i1[PRODVM_CYCLE].op[2].opd.type_MAT.mat_num);
			clr_M_wrd(prodvm_i1[PRODVM_CYCLE].op[2].opd.type_MAT.mat_num);
			clr_M_wwr(prodvm_i1[PRODVM_CYCLE].op[2].opd.type_MAT.mat_num);*/
			
        }
		if(prodvm_i1[1].is_exist_ins)
		{
			if(prodvm_i1[1].op[3].opd.accumul)
			{
				clr_B_rd(R);
			}
		}
    }
	
	if(plst.prodvmp_st==STG_BUSY)
    {
		if(prodvmp_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(prodvmp_i1[0],fp_saveRTLB);
			prodvmp(prodvmp_i1[0].op[0],prodvmp_i1[0].op[1].opd.type_MAT.pMAT,prodvmp_i1[0].op[2],prodvmp_i1[0].op[1].opd.type_MAT.mat_num,clk,prodvmp_i1[0].ex_ins);

			if(prodvmp_i1[0].op[0].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvmp_i1[0],0,B));
				clr_wwr(B,num_ofrg(prodvmp_i1[0],0,B));
				clr_wrd(B,num_ofrg(prodvmp_i1[0],0,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvmp_i1[0],0,R));
				clr_wwr(R,num_ofrg(prodvmp_i1[0],0,R));
				clr_wrd(R,num_ofrg(prodvmp_i1[0],0,R));
			}

			clr_M_rd(prodvmp_i1[0].op[1].opd.type_MAT.mat_num);
			clr_M_wrd(prodvmp_i1[0].op[1].opd.type_MAT.mat_num);
			clr_M_wwr(prodvmp_i1[0].op[1].opd.type_MAT.mat_num);
		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<PRODVMP_CYCLE + 1;i++)
				{
					if (prodvmp_i1[PRODVMP_CYCLE - i].is_exist_ins)
					{
						myprint_report("     PRODVMP :instruction ", prodvmp_i1[PRODVMP_CYCLE - i].ex_ins + 1, ": ", NULL, ins[prodvmp_i1[PRODVMP_CYCLE - i].ex_ins].instr, NULL);
						printf("     PRODVMP :instruction %d : %s\n", prodvmp_i1[PRODVMP_CYCLE - i].ex_ins + 1, ins[prodvmp_i1[PRODVMP_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(prodvmp_i1,PRODVMP_CYCLE+1);
		plst.prodvmp_if1=STG_NRDY;
        prodvmp_execute_time++;
        //plst.prodvmp_cycle=plst.prodvmp_cycle-1;
		//plst.prodvmp_cycle_func=plst.prodvmp_cycle_func-1;
		if(prodvmp_i1[PRODVMP_CYCLE].is_exist_ins)
        {
			//prodvmp(prodvmp_i1[PRODVMP_CYCLE].op[0],prodvmp_i1[PRODVMP_CYCLE].op[1].opd.type_MAT.pMAT,prodvmp_i1[PRODVMP_CYCLE].op[2],prodvmp_i1[PRODVMP_CYCLE].op[1].opd.type_MAT.mat_num,clk);

			prodvmp_i1[PRODVMP_CYCLE].is_exist_ins=0;
			if(judge_array_empty(prodvmp_i1,PRODVMP_CYCLE))
			{
				plst.prodvmp_st=STG_FREE;
			}
			/*if(prodvmp_i1[PRODVMP_CYCLE].op[0].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvmp_i1[PRODVMP_CYCLE],0,B));
				clr_wwr(B,num_ofrg(prodvmp_i1[PRODVMP_CYCLE],0,B));
				clr_wrd(B,num_ofrg(prodvmp_i1[PRODVMP_CYCLE],0,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvmp_i1[PRODVMP_CYCLE],0,R));
				clr_wwr(R,num_ofrg(prodvmp_i1[PRODVMP_CYCLE],0,R));
				clr_wrd(R,num_ofrg(prodvmp_i1[PRODVMP_CYCLE],0,R));
			}

			clr_M_rd(prodvmp_i1[PRODVMP_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wrd(prodvmp_i1[PRODVMP_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wwr(prodvmp_i1[PRODVMP_CYCLE].op[1].opd.type_MAT.mat_num);*/
			
        }
		if(prodvmp_i1[1].is_exist_ins)
		{
			clr_B_wr(R);
			memcpy(&PRbuffer,&Rbuffer,sizeof(struct RG));
		}
    }

    if(plst.prodmv_st==STG_BUSY)
    {
		if(prodmv_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(prodmv_i1[0],fp_saveRTLB);
			prodmv(prodmv_i1[0].op[0], prodmv_i1[0].op[1], prodmv_i1[0].op[2].opd.type_MAT.pMAT,prodmv_i1[0].op[3],prodmv_i1[0].op[2].opd.type_MAT.mat_num,clk,prodmv_i1[0].ex_ins);

			if(prodmv_i1[0].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodmv_i1[0],1,B));
				clr_wwr(B,num_ofrg(prodmv_i1[0],1,B));
				clr_wrd(B,num_ofrg(prodmv_i1[0],1,B));
			}
			else
			{
				int prodmv_num=num_ofrg(prodmv_i1[0],1,R);
				prodmv_num=prodmv_i1[0].op[1].opd.type_RV.pRV->readnum;
				prodmv_num=prodmv_i1[0].op[1].opd.type_RV.pRV->R_V[1].RD_S;
				prodmv_num=prodmv_i1[0].op[1].opd.type_RV.pRV->R_V[1].WRD_S;
				prodmv_num=prodmv_i1[0].op[1].opd.type_RV.pRV->R_V[1].WR_S;
				prodmv_num=prodmv_i1[0].op[1].opd.type_RV.pRV->R_V[1].WWR_S;
				clr_rd(R,num_ofrg(prodmv_i1[0],1,R));
				clr_wwr(R,num_ofrg(prodmv_i1[0],1,R));
				clr_wrd(R,num_ofrg(prodmv_i1[0],1,R));
			}

			clr_M_rd(prodmv_i1[0].op[2].opd.type_MAT.mat_num);
			clr_M_wrd(prodmv_i1[0].op[2].opd.type_MAT.mat_num);
			clr_M_wwr(prodmv_i1[0].op[2].opd.type_MAT.mat_num);
		}
		
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<PRODMV_CYCLE + 1;i++)
				{
					if (prodmv_i1[PRODMV_CYCLE - i].is_exist_ins)
					{
						myprint_report("     PRODMV :instruction ", prodmv_i1[PRODMV_CYCLE - i].ex_ins + 1, ": ", NULL, ins[prodmv_i1[PRODMV_CYCLE - i].ex_ins].instr, NULL);
						printf("     PRODMV :instruction %d : %s\n", prodmv_i1[PRODMV_CYCLE - i].ex_ins + 1, ins[prodmv_i1[PRODMV_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(prodmv_i1,PRODMV_CYCLE+1);
		plst.prodmv_if1=STG_NRDY;
        prodmv_execute_time++;
        //plst.prodmv_cycle=plst.prodmv_cycle-1;
		//plst.prodmv_cycle_func=plst.prodmv_cycle_func-1;
		if(prodmv_i1[PRODMV_CYCLE].is_exist_ins)
        {
			//prodmv(prodmv_i1[PRODMV_CYCLE].op[0], prodmv_i1[PRODMV_CYCLE].op[1], prodmv_i1[PRODMV_CYCLE].op[2].opd.type_MAT.pMAT,prodmv_i1[PRODMV_CYCLE].op[3],prodmv_i1[PRODMV_CYCLE].op[2].opd.type_MAT.mat_num,clk);

			prodmv_i1[PRODMV_CYCLE].is_exist_ins=0;
			if(judge_array_empty(prodmv_i1,PRODMV_CYCLE))
			{
				plst.prodmv_st=STG_FREE;
			}
			int tem_prodmv=num_ofrg(prodmv_i1[PRODMV_CYCLE],0,R);
			clr_wr(R,num_ofrg(prodmv_i1[PRODMV_CYCLE],0,R));
			clr_wwr(R,num_ofrg(prodmv_i1[PRODMV_CYCLE],0,R));
			clr_wrd(R,num_ofrg(prodmv_i1[PRODMV_CYCLE],0,R));
			memcpy(&PRV->R_V[num_ofrg(prodmv_i1[PRODMV_CYCLE],0,R)],&RV->R_V[num_ofrg(prodmv_i1[PRODMV_CYCLE],0,R)],sizeof(struct RG));

			/*if(prodmv_i1[PRODMV_CYCLE].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodmv_i1[PRODMV_CYCLE],1,B));
				clr_wwr(B,num_ofrg(prodmv_i1[PRODMV_CYCLE],1,B));
				clr_wrd(B,num_ofrg(prodmv_i1[PRODMV_CYCLE],1,B));
			}
			else
			{
				int prodmv_num=num_ofrg(prodmv_i1[PRODMV_CYCLE],1,R);
				prodmv_num=prodmv_i1[PRODMV_CYCLE].op[1].opd.type_RV.pRV->readnum;
				prodmv_num=prodmv_i1[PRODMV_CYCLE].op[1].opd.type_RV.pRV->R_V[1].RD_S;
				prodmv_num=prodmv_i1[PRODMV_CYCLE].op[1].opd.type_RV.pRV->R_V[1].WRD_S;
				prodmv_num=prodmv_i1[PRODMV_CYCLE].op[1].opd.type_RV.pRV->R_V[1].WR_S;
				prodmv_num=prodmv_i1[PRODMV_CYCLE].op[1].opd.type_RV.pRV->R_V[1].WWR_S;
				clr_rd(R,num_ofrg(prodmv_i1[PRODMV_CYCLE],1,R));
				clr_wwr(R,num_ofrg(prodmv_i1[PRODMV_CYCLE],1,R));
				clr_wrd(R,num_ofrg(prodmv_i1[PRODMV_CYCLE],1,R));
			}

			clr_M_rd(prodmv_i1[PRODMV_CYCLE].op[2].opd.type_MAT.mat_num);
			clr_M_wrd(prodmv_i1[PRODMV_CYCLE].op[2].opd.type_MAT.mat_num);
			clr_M_wwr(prodmv_i1[PRODMV_CYCLE].op[2].opd.type_MAT.mat_num);*/
			
        }
		if(prodmv_i1[1].is_exist_ins)
		{
			if(prodmv_i1[1].op[3].opd.accumul)
			{
				clr_B_rd(C);
			}
		}
    }
	
	if(plst.prodmvp_st==STG_BUSY)
    {
		if(prodmvp_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(prodmvp_i1[0],fp_saveRTLB);
			prodmvp(prodmvp_i1[0].op[0],prodmvp_i1[0].op[1].opd.type_MAT.pMAT,prodmvp_i1[0].op[2],prodmvp_i1[0].op[1].opd.type_MAT.mat_num,clk,prodmvp_i1[0].ex_ins);

			if(prodmvp_i1[0].op[0].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodmvp_i1[0],0,B));
				clr_wwr(B,num_ofrg(prodmvp_i1[0],0,B));
				clr_wrd(B,num_ofrg(prodmvp_i1[0],0,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodmvp_i1[0],0,R));
				clr_wwr(R,num_ofrg(prodmvp_i1[0],0,R));
				clr_wrd(R,num_ofrg(prodmvp_i1[0],0,R));
			}

			clr_M_rd(prodmvp_i1[0].op[1].opd.type_MAT.mat_num);
			clr_M_wrd(prodmvp_i1[0].op[1].opd.type_MAT.mat_num);
			clr_M_wwr(prodmvp_i1[0].op[1].opd.type_MAT.mat_num);

		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<PRODMVP_CYCLE + 1;i++)
				{
					if (prodmvp_i1[PRODMVP_CYCLE - i].is_exist_ins)
					{
						myprint_report("     PRODMVP :instruction ", prodmvp_i1[PRODMVP_CYCLE - i].ex_ins + 1, ": ", NULL, ins[prodmvp_i1[PRODMVP_CYCLE - i].ex_ins].instr, NULL);
						printf("     PRODMVP :instruction %d : %s\n", prodmvp_i1[PRODMVP_CYCLE - i].ex_ins + 1, ins[prodmvp_i1[PRODMVP_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(prodmvp_i1,PRODMVP_CYCLE+1);
		plst.prodmvp_if1=STG_NRDY;
        prodmvp_execute_time++;
        //plst.prodmvp_cycle=plst.prodmvp_cycle-1;
		//plst.prodmvp_cycle_func=plst.prodmvp_cycle_func-1;
		if(prodmvp_i1[PRODMVP_CYCLE].is_exist_ins)
        {
			//prodmvp(prodmvp_i1[PRODMVP_CYCLE].op[0],prodmvp_i1[PRODMVP_CYCLE].op[1].opd.type_MAT.pMAT,prodmvp_i1[PRODMVP_CYCLE].op[2],prodmvp_i1[PRODMVP_CYCLE].op[1].opd.type_MAT.mat_num,clk);

			prodmvp_i1[PRODMVP_CYCLE].is_exist_ins=0;
			if(judge_array_empty(prodmvp_i1,PRODMVP_CYCLE))
			{
				plst.prodmvp_st=STG_FREE;
			}

			/*if(prodmvp_i1[PRODMVP_CYCLE].op[0].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodmvp_i1[PRODMVP_CYCLE],0,B));
				clr_wwr(B,num_ofrg(prodmvp_i1[PRODMVP_CYCLE],0,B));
				clr_wrd(B,num_ofrg(prodmvp_i1[PRODMVP_CYCLE],0,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodmvp_i1[PRODMVP_CYCLE],0,R));
				clr_wwr(R,num_ofrg(prodmvp_i1[PRODMVP_CYCLE],0,R));
				clr_wrd(R,num_ofrg(prodmvp_i1[PRODMVP_CYCLE],0,R));
			}

			clr_M_rd(prodmvp_i1[PRODMVP_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wrd(prodmvp_i1[PRODMVP_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wwr(prodmvp_i1[PRODMVP_CYCLE].op[1].opd.type_MAT.mat_num);
	*/
        }
		if(prodmvp_i1[1].is_exist_ins)
		{
			clr_B_wr(C);
			memcpy(&PCbuffer,&Cbuffer,sizeof(struct RG));
		}
    }

    if(plst.prodvv_st==STG_BUSY)
    {
		if(prodvv_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(prodvv_i1[0],fp_saveRTLB);
			prodvv(prodvv_i1[0].op[0].opd.type_MAT.pMAT,prodvv_i1[0].op[1], prodvv_i1[0].op[2],prodvv_i1[0].op[3],prodvv_i1[0].op[0].opd.type_MAT.mat_num,clk,prodvv_i1[0].ex_ins);

			if(prodvv_i1[0].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvv_i1[0],1,B));
				clr_wwr(B,num_ofrg(prodvv_i1[0],1,B));
				clr_wrd(B,num_ofrg(prodvv_i1[0],1,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvv_i1[0],1,R));
				clr_wwr(R,num_ofrg(prodvv_i1[0],1,R));
				clr_wrd(R,num_ofrg(prodvv_i1[0],1,R));
			}

			if(prodvv_i1[0].op[2].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvv_i1[0],2,B));
				clr_wwr(B,num_ofrg(prodvv_i1[0],2,B));
				clr_wrd(B,num_ofrg(prodvv_i1[0],2,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvv_i1[0],2,R));
				clr_wwr(R,num_ofrg(prodvv_i1[0],2,R));
				clr_wrd(R,num_ofrg(prodvv_i1[0],2,R));
			}
		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<PRODVV_CYCLE + 1;i++)
				{
					if (prodvv_i1[PRODVV_CYCLE - i].is_exist_ins)
					{
						myprint_report("     PRODVV :instruction ", prodvv_i1[PRODVV_CYCLE - i].ex_ins + 1, ": ", NULL, ins[prodvv_i1[PRODVV_CYCLE - i].ex_ins].instr, NULL);
						printf("     PRODVV :instruction %d : %s\n", prodvv_i1[PRODVV_CYCLE - i].ex_ins + 1, ins[prodvv_i1[PRODVV_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(prodvv_i1,PRODVV_CYCLE+1);
		plst.prodvv_if1=STG_NRDY;
        prodvv_execute_time++;
        //plst.prodvv_cycle=plst.prodvv_cycle-1;
		//plst.prodvv_cycle_func=plst.prodvv_cycle_func-1;
		if(prodvv_i1[PRODVV_CYCLE].is_exist_ins)
        {
			//prodvv(prodvv_i1[PRODVV_CYCLE].op[0].opd.type_MAT.pMAT,prodvv_i1[PRODVV_CYCLE].op[1], prodvv_i1[PRODVV_CYCLE].op[2],prodvv_i1[PRODVV_CYCLE].op[3],prodvv_i1[PRODVV_CYCLE].op[0].opd.type_MAT.mat_num,clk);

			prodvv_i1[PRODVV_CYCLE].is_exist_ins=0;
			if(judge_array_empty(prodvv_i1,PRODVV_CYCLE))
			{
				plst.prodvv_st=STG_FREE;
			}

			clr_M_wr(prodvv_i1[PRODVV_CYCLE].op[0].opd.type_MAT.mat_num);
			clr_M_wwr(prodvv_i1[PRODVV_CYCLE].op[0].opd.type_MAT.mat_num);
			clr_M_wrd(prodvv_i1[PRODVV_CYCLE].op[0].opd.type_MAT.mat_num);
			memcpy(PMAT[prodvv_i1[PRODVV_CYCLE].op[0].opd.type_MAT.mat_num],MAT[prodvv_i1[PRODVV_CYCLE].op[0].opd.type_MAT.mat_num],sizeof(struct G_M));

			/*if(prodvv_i1[PRODVV_CYCLE].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvv_i1[PRODVV_CYCLE],1,B));
				clr_wwr(B,num_ofrg(prodvv_i1[PRODVV_CYCLE],1,B));
				clr_wrd(B,num_ofrg(prodvv_i1[PRODVV_CYCLE],1,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvv_i1[PRODVV_CYCLE],1,R));
				clr_wwr(R,num_ofrg(prodvv_i1[PRODVV_CYCLE],1,R));
				clr_wrd(R,num_ofrg(prodvv_i1[PRODVV_CYCLE],1,R));
			}

			if(prodvv_i1[PRODVV_CYCLE].op[2].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvv_i1[PRODVV_CYCLE],2,B));
				clr_wwr(B,num_ofrg(prodvv_i1[PRODVV_CYCLE],2,B));
				clr_wrd(B,num_ofrg(prodvv_i1[PRODVV_CYCLE],2,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvv_i1[PRODVV_CYCLE],2,R));
				clr_wwr(R,num_ofrg(prodvv_i1[PRODVV_CYCLE],2,R));
				clr_wrd(R,num_ofrg(prodvv_i1[PRODVV_CYCLE],2,R));
			}*/
			
        }
		if(prodvv_i1[1].is_exist_ins)
		{
			if(prodvv_i1[1].op[3].opd.accumul)
			{
				clr_B_rd(M);
			}
		}
    }

    if(plst.prodvvp_st==STG_BUSY)
    {
		if(prodvvp_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(prodvvp_i1[0],fp_saveRTLB);
			prodvvp(prodvvp_i1[0].op[0], prodvvp_i1[0].op[1],prodvvp_i1[0].op[2],clk,prodvvp_i1[0].ex_ins);

			if(prodvvp_i1[0].op[0].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvvp_i1[0],0,B));
				clr_wwr(B,num_ofrg(prodvvp_i1[0],0,B));
				clr_wrd(B,num_ofrg(prodvvp_i1[0],0,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvvp_i1[0],0,R));
				clr_wwr(R,num_ofrg(prodvvp_i1[0],0,R));
				clr_wrd(R,num_ofrg(prodvvp_i1[0],0,R));
			}

			if(prodvvp_i1[0].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvvp_i1[0],1,B));
				clr_wwr(B,num_ofrg(prodvvp_i1[0],1,B));
				clr_wrd(B,num_ofrg(prodvvp_i1[0],1,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvvp_i1[0],1,R));
				clr_wwr(R,num_ofrg(prodvvp_i1[0],1,R));
				clr_wrd(R,num_ofrg(prodvvp_i1[0],1,R));
			}

		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<PRODVVP_CYCLE + 1;i++)
				{
					if (prodvvp_i1[PRODVVP_CYCLE - i].is_exist_ins)
					{
						myprint_report("     PRODVVP :instruction ", prodvvp_i1[PRODVVP_CYCLE - i].ex_ins + 1, ": ", NULL, ins[prodvvp_i1[PRODVVP_CYCLE - i].ex_ins].instr, NULL);
						printf("     PRODVVP :instruction %d : %s\n", prodvvp_i1[PRODVVP_CYCLE - i].ex_ins + 1, ins[prodvvp_i1[PRODVVP_CYCLE - i].ex_ins].instr);

					}
				}
			}
		}
		array_back_n(prodvvp_i1,PRODVVP_CYCLE+1);
		plst.prodvvp_if1=STG_NRDY;
        prodvvp_execute_time++;
        //plst.prodvvp_cycle=plst.prodvvp_cycle-1;
		//plst.prodvvp_cycle_func=plst.prodvvp_cycle_func-1;
		if(prodvvp_i1[PRODVVP_CYCLE].is_exist_ins)
        {
			//prodvvp(prodvvp_i1[PRODVVP_CYCLE].op[0], prodvvp_i1[PRODVVP_CYCLE].op[1],prodvvp_i1[PRODVVP_CYCLE].op[2],clk);

			prodvvp_i1[PRODVVP_CYCLE].is_exist_ins=0;
			if(judge_array_empty(prodvvp_i1,PRODVVP_CYCLE))
			{
				plst.prodvvp_st=STG_FREE;
			}
            
			/*if(prodvvp_i1[PRODVVP_CYCLE].op[0].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],0,B));
				clr_wwr(B,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],0,B));
				clr_wrd(B,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],0,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],0,R));
				clr_wwr(R,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],0,R));
				clr_wrd(R,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],0,R));
			}

			if(prodvvp_i1[PRODVVP_CYCLE].op[1].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],1,B));
				clr_wwr(B,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],1,B));
				clr_wrd(B,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],1,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],1,R));
				clr_wwr(R,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],1,R));
				clr_wrd(R,num_ofrg(prodvvp_i1[PRODVVP_CYCLE],1,R));
			}*/
			
        }
		if(prodvvp_i1[1].is_exist_ins)
		{
			clr_B_wr(M);
			memcpy(&PMbuffer,&Mbuffer,sizeof(struct G_MB));
		}
    }
	
	if(plst.prodvvd_st==STG_BUSY)
    {
		if(prodvvd_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(prodvvd_i1[0],fp_saveRTLB);
			prodvvd(prodvvd_i1[0].op[0], prodvvd_i1[0].op[1], prodvvd_i1[0].op[2],clk,prodvvd_i1[0].ex_ins);

			clr_rd(R,num_ofrg(prodvvd_i1[0],1,R));
			clr_wwr(R,num_ofrg(prodvvd_i1[0],1,R));
			clr_wrd(R,num_ofrg(prodvvd_i1[0],1,R));

			if(prodvvd_i1[0].op[2].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvvd_i1[0],2,B));
				clr_wwr(B,num_ofrg(prodvvd_i1[0],2,B));
				clr_wrd(B,num_ofrg(prodvvd_i1[0],2,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvvd_i1[0],2,R));
				clr_wwr(R,num_ofrg(prodvvd_i1[0],2,R));
				clr_wrd(R,num_ofrg(prodvvd_i1[0],2,R));
			}
		}
		if (dugD)
		{
			if (report_fl == 1)
			{
				int i;
				for (i = 0;i<PRODVVD_CYCLE + 1;i++)
				{
					if (prodvvd_i1[PRODVVD_CYCLE - i].is_exist_ins)
					{
						myprint_report("     PRODVVD :instruction ", prodvvd_i1[PRODVVD_CYCLE - i].ex_ins + 1, ": ", NULL, ins[prodvvd_i1[PRODVVD_CYCLE - i].ex_ins].instr, NULL);
						printf("     PRODVVD :instruction %d : %s\n", prodvvd_i1[PRODVVD_CYCLE - i].ex_ins + 1, ins[prodvvd_i1[PRODVVD_CYCLE - i].ex_ins].instr);
					}
				}
			}
		}
		array_back_n(prodvvd_i1,PRODVVD_CYCLE+1);
		plst.prodvvd_if1=STG_NRDY;
        prodvvd_execute_time++;
        //plst.prodvvd_cycle=plst.prodvvd_cycle-1;
		//plst.prodvvd_cycle_func=plst.prodvvd_cycle_func-1;
		if(prodvvd_i1[PRODVVD_CYCLE].is_exist_ins)
        {
			//prodvvd(prodvvd_i1[PRODVVD_CYCLE].op[0], prodvvd_i1[PRODVVD_CYCLE].op[1], prodvvd_i1[PRODVVD_CYCLE].op[2],clk);

			prodvvd_i1[PRODVVD_CYCLE].is_exist_ins=0;
			if(judge_array_empty(prodvvd_i1,PRODVVD_CYCLE))
			{
				plst.prodvvd_st=STG_FREE;
			}
			
			if(prodvvd_i1[PRODVVD_CYCLE].op[0].type_flag==0)
			{
				clr_wr(B,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,B));
				clr_wwr(B,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,B));
				clr_wrd(B,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,B));
				memcpy(&PBV->R_V[num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,B)],&BV->R_V[num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,B)],sizeof(struct RB));
			}
			else
			{
				clr_wr(R,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,R));
				clr_wwr(R,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,R));
				clr_wrd(R,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,R));
				memcpy(&PRV->R_V[num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,R)],&RV->R_V[num_ofrg(prodvvd_i1[PRODVVD_CYCLE],0,R)],sizeof(struct RG));
			}

			/*clr_rd(R,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],1,R));
			clr_wwr(R,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],1,R));
			clr_wrd(R,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],1,R));

			if(prodvvd_i1[PRODVVD_CYCLE].op[2].type_flag==0)
			{
				clr_rd(B,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],2,B));
				clr_wwr(B,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],2,B));
				clr_wrd(B,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],2,B));
			}
			else
			{
				clr_rd(R,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],2,R));
				clr_wwr(R,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],2,R));
				clr_wrd(R,num_ofrg(prodvvd_i1[PRODVVD_CYCLE],2,R));
			}*/
        }
    }

    if(plst.addv_st==STG_BUSY)
    {
		if(addv_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(addv_i1[0],fp_saveRTLB);
			addv(addv_i1[0].op[0], addv_i1[0].op[1], addv_i1[0].op[2],clk,addv_i1[0].ex_ins);

			clr_rd(R,num_ofrg(addv_i1[0],1,R));
			clr_wwr(R,num_ofrg(addv_i1[0],1,R));
			clr_wrd(R,num_ofrg(addv_i1[0],1,R));

			clr_rd(R,num_ofrg(addv_i1[0],2,R));
			clr_wwr(R,num_ofrg(addv_i1[0],2,R));
			clr_wrd(R,num_ofrg(addv_i1[0],2,R));
		}

		//if (!qGetD)
		//{
			//if (report_fl == 1)
		    if(dugD)
			{
				int i;
				for (i = 0;i<ADDV_CYCLE + 1;i++)
				{
					if (addv_i1[ADDV_CYCLE - i].is_exist_ins)
					{
						myprint_report("     ADDV :instruction ", addv_i1[ADDV_CYCLE - i].ex_ins + 1, ": ", NULL, ins[addv_i1[ADDV_CYCLE - i].ex_ins].instr, NULL);
						printf("     ADDV :instruction %d : %s\n", addv_i1[ADDV_CYCLE - i].ex_ins + 1, ins[addv_i1[ADDV_CYCLE - i].ex_ins].instr);
					}
				}
			//}
		}
		array_back_n(addv_i1,ADDV_CYCLE+1);
		plst.addv_if1=STG_NRDY;
        addv_execute_time++;
        //plst.addv_cycle=plst.addv_cycle-1;
		//plst.addv_cycle_func=plst.addv_cycle_func-1;
		if(addv_i1[ADDV_CYCLE].is_exist_ins)
        {
			//addv(addv_i1[ADDV_CYCLE].op[0], addv_i1[ADDV_CYCLE].op[1], addv_i1[ADDV_CYCLE].op[2],clk);

			addv_i1[ADDV_CYCLE].is_exist_ins=0;
			if(judge_array_empty(addv_i1,ADDV_CYCLE))
			{
				plst.addv_st=STG_FREE;
			}

			clr_wr(R,num_ofrg(addv_i1[ADDV_CYCLE],0,R));
			clr_wwr(R,num_ofrg(addv_i1[ADDV_CYCLE],0,R));
			clr_wrd(R,num_ofrg(addv_i1[ADDV_CYCLE],0,R));
			memcpy(&PRV->R_V[num_ofrg(addv_i1[ADDV_CYCLE],0,R)],&RV->R_V[num_ofrg(addv_i1[ADDV_CYCLE],0,R)],sizeof(struct RG));

			/*clr_rd(R,num_ofrg(addv_i1[ADDV_CYCLE],1,R));
			clr_wwr(R,num_ofrg(addv_i1[ADDV_CYCLE],1,R));
			clr_wrd(R,num_ofrg(addv_i1[ADDV_CYCLE],1,R));

			clr_rd(R,num_ofrg(addv_i1[ADDV_CYCLE],2,R));
			clr_wwr(R,num_ofrg(addv_i1[ADDV_CYCLE],2,R));
			clr_wrd(R,num_ofrg(addv_i1[ADDV_CYCLE],2,R));*/
        }
    }

	if(plst.addm_st==STG_BUSY)
    {
		if(addm_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(addm_i1[0],fp_saveRTLB);
			addm(addm_i1[0].op[0].opd.type_MAT.pMAT, addm_i1[0].op[1].opd.type_MAT.pMAT, addm_i1[0].op[2].opd.type_MAT.pMAT,addm_i1[0].op[0].opd.type_MAT.mat_num,addm_i1[0].op[1].opd.type_MAT.mat_num,addm_i1[0].op[2].opd.type_MAT.mat_num,clk,addm_i1[0].ex_ins);

			clr_M_rd(addm_i1[0].op[1].opd.type_MAT.mat_num);
			clr_M_wwr(addm_i1[0].op[1].opd.type_MAT.mat_num);
			clr_M_wrd(addm_i1[0].op[1].opd.type_MAT.mat_num);

			clr_M_rd(addm_i1[0].op[2].opd.type_MAT.mat_num);
			clr_M_wwr(addm_i1[0].op[2].opd.type_MAT.mat_num);
			clr_M_wrd(addm_i1[0].op[2].opd.type_MAT.mat_num);
		}
		//if (!qGetD)
		//{
			//if (report_fl == 1)
		    if(dugD)
			{
				int i;
				for (i = 0;i<ADDM_CYCLE + 1;i++)
				{
					if (addm_i1[ADDM_CYCLE - i].is_exist_ins)
					{
						myprint_report("     ADDM :instruction ", addm_i1[ADDM_CYCLE - i].ex_ins + 1, ": ", NULL, ins[addm_i1[ADDM_CYCLE - i].ex_ins].instr, NULL);
						printf("     ADDM :instruction %d : %s\n", addm_i1[ADDM_CYCLE - i].ex_ins + 1, ins[addm_i1[ADDM_CYCLE - i].ex_ins].instr);
					}
				}
			}
		//}
		array_back_n(addm_i1,ADDM_CYCLE+1);
		plst.addm_if1=STG_NRDY;
        addm_execute_time++;
        //plst.addm_cycle=plst.addm_cycle-1;
		//plst.addm_cycle_func=plst.addm_cycle_func-1;
		if(addm_i1[ADDM_CYCLE].is_exist_ins)
        {
			//addm(addm_i1[ADDM_CYCLE].op[0].opd.type_MAT.pMAT, addm_i1[ADDM_CYCLE].op[1].opd.type_MAT.pMAT, addm_i1[ADDM_CYCLE].op[2].opd.type_MAT.pMAT,addm_i1[ADDM_CYCLE].op[0].opd.type_MAT.mat_num,addm_i1[ADDM_CYCLE].op[1].opd.type_MAT.mat_num,addm_i1[ADDM_CYCLE].op[2].opd.type_MAT.mat_num,clk);

			addm_i1[ADDM_CYCLE].is_exist_ins=0;
			if(judge_array_empty(addm_i1,ADDM_CYCLE))
			{
				plst.addm_st=STG_FREE;
			}
			

			clr_M_wr(addm_i1[ADDM_CYCLE].op[0].opd.type_MAT.mat_num);
			clr_M_wwr(addm_i1[ADDM_CYCLE].op[0].opd.type_MAT.mat_num);
			clr_M_wrd(addm_i1[ADDM_CYCLE].op[0].opd.type_MAT.mat_num);
			memcpy(PMAT[addm_i1[ADDM_CYCLE].op[0].opd.type_MAT.mat_num],MAT[addm_i1[ADDM_CYCLE].op[0].opd.type_MAT.mat_num],sizeof(struct G_M));

			/*clr_M_rd(addm_i1[ADDM_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wwr(addm_i1[ADDM_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wrd(addm_i1[ADDM_CYCLE].op[1].opd.type_MAT.mat_num);

			clr_M_rd(addm_i1[ADDM_CYCLE].op[2].opd.type_MAT.mat_num);
			clr_M_wwr(addm_i1[ADDM_CYCLE].op[2].opd.type_MAT.mat_num);
			clr_M_wrd(addm_i1[ADDM_CYCLE].op[2].opd.type_MAT.mat_num);*/
        }
    }

	if(plst.subv_st==STG_BUSY)
    {
		if(subv_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(subv_i1[0],fp_saveRTLB);
			subv(subv_i1[0].op[0],subv_i1[0].op[1],subv_i1[0].op[2],clk,subv_i1[0].ex_ins);

			clr_rd(R,num_ofrg(subv_i1[0],1,R));
			clr_wwr(R,num_ofrg(subv_i1[0],1,R));
			clr_wrd(R,num_ofrg(subv_i1[0],1,R));

			clr_rd(R,num_ofrg(subv_i1[0],2,R));
			clr_wwr(R,num_ofrg(subv_i1[0],2,R));
			clr_wrd(R,num_ofrg(subv_i1[0],2,R));
		}
		//if (!qGetD)
		//{
			//if (report_fl == 1)
		    if (dugD)
			{
				int i;
				for (i = 0;i<SUBV_CYCLE + 1;i++)
				{
					if (subv_i1[SUBV_CYCLE - i].is_exist_ins)
					{
						myprint_report("     SUBV :instruction ", subv_i1[SUBV_CYCLE - i].ex_ins + 1, ": ", NULL, ins[subv_i1[SUBV_CYCLE - i].ex_ins].instr, NULL);
						printf("     SUBV :instruction %d : %s\n", subv_i1[SUBV_CYCLE - i].ex_ins + 1, ins[subv_i1[SUBV_CYCLE - i].ex_ins].instr);
					}
				}
			}
		//}
		
		array_back_n(subv_i1,SUBV_CYCLE+1);
		plst.subv_if1=STG_NRDY;
        subv_execute_time++;
        //plst.subv_cycle=plst.subv_cycle-1;
		//plst.subv_cycle_func=plst.subv_cycle_func-1;
		if(subv_i1[SUBV_CYCLE].is_exist_ins)
		{
			//subv(subv_i1[SUBV_CYCLE].op[0],subv_i1[SUBV_CYCLE].op[1],subv_i1[SUBV_CYCLE].op[2],clk);

			subv_i1[SUBV_CYCLE].is_exist_ins=0;
			if(judge_array_empty(subv_i1,SUBV_CYCLE))
			{
				plst.subv_st=STG_FREE;
			}

			clr_wr(R,num_ofrg(subv_i1[SUBV_CYCLE],0,R));
			clr_wwr(R,num_ofrg(subv_i1[SUBV_CYCLE],0,R));
			clr_wrd(R,num_ofrg(subv_i1[SUBV_CYCLE],0,R));
			memcpy(&PRV->R_V[num_ofrg(subv_i1[SUBV_CYCLE],0,R)],&RV->R_V[num_ofrg(subv_i1[SUBV_CYCLE],0,R)],sizeof(struct RG));

			/*clr_rd(R,num_ofrg(subv_i1[SUBV_CYCLE],1,R));
			clr_wwr(R,num_ofrg(subv_i1[SUBV_CYCLE],1,R));
			clr_wrd(R,num_ofrg(subv_i1[SUBV_CYCLE],1,R));

			clr_rd(R,num_ofrg(subv_i1[SUBV_CYCLE],2,R));
			clr_wwr(R,num_ofrg(subv_i1[SUBV_CYCLE],2,R));
			clr_wrd(R,num_ofrg(subv_i1[SUBV_CYCLE],2,R));*/
		}
	}

	if(plst.subm_st==STG_BUSY)
    {
		if(subm_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(subm_i1[0],fp_saveRTLB);
			subm(subm_i1[0].op[0].opd.type_MAT.pMAT,subm_i1[0].op[1].opd.type_MAT.pMAT,subm_i1[0].op[2].opd.type_MAT.pMAT,subm_i1[0].op[0].opd.type_MAT.mat_num,subm_i1[0].op[1].opd.type_MAT.mat_num,subm_i1[0].op[2].opd.type_MAT.mat_num,clk,subm_i1[0].ex_ins);

			clr_M_rd(subm_i1[0].op[1].opd.type_MAT.mat_num);
			clr_M_wwr(subm_i1[0].op[1].opd.type_MAT.mat_num);
			clr_M_wrd(subm_i1[0].op[1].opd.type_MAT.mat_num);

			clr_M_rd(subm_i1[0].op[2].opd.type_MAT.mat_num);
			clr_M_wwr(subm_i1[0].op[2].opd.type_MAT.mat_num);
			clr_M_wrd(subm_i1[0].op[2].opd.type_MAT.mat_num);
		}
		//if (!qGetD)
		//{
			//if (report_fl == 1)
		if (dugD)	
		{
			int i;
			for (i = 0;i<SUBM_CYCLE + 1;i++)
			{
				if (subm_i1[SUBM_CYCLE - i].is_exist_ins)
				{
					myprint_report("     SUBM :instruction ", subm_i1[SUBM_CYCLE - i].ex_ins + 1, ": ", NULL, ins[subm_i1[SUBM_CYCLE - i].ex_ins].instr, NULL);
					printf("     SUBM :instruction %d : %s\n", subm_i1[SUBM_CYCLE - i].ex_ins + 1, ins[subm_i1[SUBM_CYCLE - i].ex_ins].instr);
				}
			}
			//}
		}
		array_back_n(subm_i1,SUBM_CYCLE+1);
		plst.subm_if1=STG_NRDY;
        subm_execute_time++;
        //plst.subm_cycle=plst.subm_cycle-1;
		//plst.subm_cycle_func=plst.subm_cycle_func-1;
		if(subm_i1[SUBM_CYCLE].is_exist_ins)
        {
			//subm(subm_i1[SUBM_CYCLE].op[0].opd.type_MAT.pMAT,subm_i1[SUBM_CYCLE].op[1].opd.type_MAT.pMAT,subm_i1[SUBM_CYCLE].op[2].opd.type_MAT.pMAT,subm_i1[SUBM_CYCLE].op[0].opd.type_MAT.mat_num,subm_i1[SUBM_CYCLE].op[1].opd.type_MAT.mat_num,subm_i1[SUBM_CYCLE].op[2].opd.type_MAT.mat_num,clk);

			subm_i1[SUBM_CYCLE].is_exist_ins=0;
			if(judge_array_empty(subm_i1,SUBM_CYCLE))
			{
				plst.subm_st=STG_FREE;
			}

			clr_M_wr(subm_i1[SUBM_CYCLE].op[0].opd.type_MAT.mat_num);
			clr_M_wwr(subm_i1[SUBM_CYCLE].op[0].opd.type_MAT.mat_num);
			clr_M_wrd(subm_i1[SUBM_CYCLE].op[0].opd.type_MAT.mat_num);
			memcpy(PMAT[subm_i1[SUBM_CYCLE].op[0].opd.type_MAT.mat_num],MAT[subm_i1[SUBM_CYCLE].op[0].opd.type_MAT.mat_num],sizeof(struct G_M));


			/*clr_M_rd(subm_i1[SUBM_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wwr(subm_i1[SUBM_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wrd(subm_i1[SUBM_CYCLE].op[1].opd.type_MAT.mat_num);

			clr_M_rd(subm_i1[SUBM_CYCLE].op[2].opd.type_MAT.mat_num);
			clr_M_wwr(subm_i1[SUBM_CYCLE].op[2].opd.type_MAT.mat_num);
			clr_M_wrd(subm_i1[SUBM_CYCLE].op[2].opd.type_MAT.mat_num);*/
        }
    }

	if(plst.sum_st==STG_BUSY)
    {
		//if(sum_i1[0].is_exist_ins)
		//{
		//	convert_ins_to_b(sum_i1[0],fp_saveRTLB);
		//}
		if (dugD)
		{
			//if (report_fl == 1)
			//{
				int i;
				for (i = 0;i<SUM_CYCLE + 1;i++)
				{
					if (sum_i1[SUM_CYCLE - i].is_exist_ins)
					{
						myprint_report("     SUM :instruction ", sum_i1[SUM_CYCLE - i].ex_ins + 1, ": ", NULL, ins[sum_i1[SUM_CYCLE - i].ex_ins].instr, NULL);
						printf("     SUM :instruction %d : %s\n", sum_i1[SUM_CYCLE - i].ex_ins + 1, ins[sum_i1[SUM_CYCLE - i].ex_ins].instr);
					}
				}
			//}
		}
		array_back_n(sum_i1,SUM_CYCLE+1);
		plst.sum_if1=STG_NRDY;
        sum_execute_time++;
        //plst.sum_cycle=plst.sum_cycle-1;
		//plst.sum_cycle_func=plst.sum_cycle_func-1;
		if(sum_i1[SUM_CYCLE].is_exist_ins)
		{
			sum(sum_i1[SUM_CYCLE].op[0],sum_i1[SUM_CYCLE].op[1].opd.type_MAT.pMAT,clk);

			sum_i1[SUM_CYCLE].is_exist_ins=0;
			if(judge_array_empty(sum_i1,SUM_CYCLE))
			{
				plst.sum_st=STG_FREE;
			}
			
			clr_wr(R,num_ofrg(sum_i1[SUM_CYCLE],0,R));
			clr_wwr(R,num_ofrg(sum_i1[SUM_CYCLE],0,R));
			clr_wrd(R,num_ofrg(sum_i1[SUM_CYCLE],0,R));

			clr_M_rd(sum_i1[SUM_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wwr(sum_i1[SUM_CYCLE].op[1].opd.type_MAT.mat_num);
			clr_M_wrd(sum_i1[SUM_CYCLE].op[1].opd.type_MAT.mat_num);
		}
	}

	if(plst.max_st==STG_BUSY)
	{
		if(max_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(max_i1[0],fp_saveRTLB);
			max(max_i1[0].op[0],max_i1[0].op[1],max_i1[0].op[2],clk);

			clr_rd(R,num_ofrg(max_i1[0],1,R));
			clr_rd(R,num_ofrg(max_i1[0],2,R));
		}
		if (dugD)
		{
			//if (report_fl == 1)
			//{
				int i;
				for (i = 0;i<MAX_CYCLE + 1;i++)
				{
					if (max_i1[MAX_CYCLE - i].is_exist_ins)
					{
						myprint_report("     MAX :instruction ", max_i1[MAX_CYCLE - i].ex_ins + 1, ": ", NULL, ins[max_i1[MAX_CYCLE - i].ex_ins].instr, NULL);
						printf("     MAX :instruction %d : %s\n", max_i1[MAX_CYCLE - i].ex_ins + 1, ins[max_i1[MAX_CYCLE - i].ex_ins].instr);
					}
				}
		//	}
		}
		array_back_n(max_i1,MAX_CYCLE+1);
		plst.max_if1=STG_NRDY;
		max_execute_time++;
		//plst.max_cycle=plst.max_cycle-1;
		//plst.max_cycle_func=plst.max_cycle_func-1;
		if(max_i1[MAX_CYCLE].is_exist_ins)
		{
			//max(max_i1[MAX_CYCLE].op[0],max_i1[MAX_CYCLE].op[1],max_i1[MAX_CYCLE].op[2],clk);

			max_i1[MAX_CYCLE].is_exist_ins=0;
			if(judge_array_empty(max_i1,MAX_CYCLE))
			{
				plst.max_st=STG_FREE;
			}
			
			clr_wr(R,num_ofrg(max_i1[MAX_CYCLE],0,R));
			memcpy(&PRV->R_V[num_ofrg(max_i1[MAX_CYCLE],0,R)],&RV->R_V[num_ofrg(max_i1[MAX_CYCLE],0,R)],sizeof(struct RG));
			/*clr_rd(R,num_ofrg(max_i1[MAX_CYCLE],1,R));
			clr_rd(R,num_ofrg(max_i1[MAX_CYCLE],2,R));*/
		}
	}
	
	if(plst.scale_st==STG_BUSY)
    {
		if(scale_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(scale_i1[0],fp_saveRTLB);
			scale(scale_i1[0].op[0],scale_i1[0].op[1],scale_i1[0].op[2].opd.type_FD,clk,scale_i1[0].ex_ins);

			clr_rd(R,num_ofrg(scale_i1[0],1,R));
			clr_wwr(R,num_ofrg(scale_i1[0],1,R));
			clr_wrd(R,num_ofrg(scale_i1[0],1,R));
		}
		if (dugD)
		{
			//if (report_fl == 1)
			//{
				int i;
				for (i = 0;i<SCALE_CYCLE + 1;i++)
				{
					if (scale_i1[SCALE_CYCLE - i].is_exist_ins)
					{
						myprint_report("     SCALE :instruction ", scale_i1[SCALE_CYCLE - i].ex_ins + 1, ": ", NULL, ins[scale_i1[SCALE_CYCLE - i].ex_ins].instr, NULL);
						printf("     SCALE :instruction %d : %s\n", scale_i1[SCALE_CYCLE - i].ex_ins + 1, ins[scale_i1[SCALE_CYCLE - i].ex_ins].instr);
					}
				}
			//}
		}
		array_back_n(scale_i1,SCALE_CYCLE+1);
		plst.scale_if1=STG_NRDY;
        scale_execute_time++;
        //plst.scale_cycle=plst.scale_cycle-1;
		//plst.scale_cycle_func=plst.scale_cycle_func-1;
		if(scale_i1[SCALE_CYCLE].is_exist_ins)
		{
			//scale(scale_i1[SCALE_CYCLE].op[0],scale_i1[SCALE_CYCLE].op[1],scale_i1[SCALE_CYCLE].op[2].opd.type_FD,clk);

			scale_i1[SCALE_CYCLE].is_exist_ins=0;
			if(judge_array_empty(scale_i1,SCALE_CYCLE))
			{
				plst.scale_st=STG_FREE;
			}

			clr_wr(R,num_ofrg(scale_i1[SCALE_CYCLE],0,R));
			clr_wwr(R,num_ofrg(scale_i1[SCALE_CYCLE],0,R));
			clr_wrd(R,num_ofrg(scale_i1[SCALE_CYCLE],0,R));
			memcpy(&PRV->R_V[num_ofrg(scale_i1[SCALE_CYCLE],0,R)],&RV->R_V[num_ofrg(scale_i1[SCALE_CYCLE],0,R)],sizeof(struct RG));

			/*clr_rd(R,num_ofrg(scale_i1[SCALE_CYCLE],1,R));
			clr_wwr(R,num_ofrg(scale_i1[SCALE_CYCLE],1,R));
			clr_wrd(R,num_ofrg(scale_i1[SCALE_CYCLE],1,R));*/
		}
	}

	if(plst.diff_st==STG_BUSY)
    {
		if(diff_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(diff_i1[0],fp_saveRTLB);
			diff(diff_i1[0].op[0],diff_i1[0].op[1],clk,diff_i1[0].ex_ins);

			clr_rd(R,num_ofrg(diff_i1[0],1,R));
			clr_wwr(R,num_ofrg(diff_i1[0],1,R));
			clr_wrd(R,num_ofrg(diff_i1[0],1,R));
		}
		if (dugD)
		{
			//if (report_fl == 1)
			//{
				int i;
				for (i = 0;i<DIFF_CYCLE + 1;i++)
				{
					if (diff_i1[DIFF_CYCLE - i].is_exist_ins)
					{
						myprint_report("     DIFF :instruction ", diff_i1[DIFF_CYCLE - i].ex_ins + 1, ": ", NULL, ins[diff_i1[DIFF_CYCLE - i].ex_ins].instr, NULL);
						printf("     DIFF :instruction %d : %s\n", diff_i1[DIFF_CYCLE - i].ex_ins + 1, ins[diff_i1[DIFF_CYCLE - i].ex_ins].instr);
					}
				}
			//}
		}
		array_back_n(diff_i1,DIFF_CYCLE+1);
		plst.diff_if1=STG_NRDY;
        diff_execute_time++;
        //plst.diff_cycle=plst.diff_cycle-1;
		//plst.diff_cycle_func=plst.diff_cycle_func-1;
		if(diff_i1[DIFF_CYCLE].is_exist_ins)
		{
			//diff(diff_i1[DIFF_CYCLE].op[0],diff_i1[DIFF_CYCLE].op[1],clk);

			diff_i1[DIFF_CYCLE].is_exist_ins=0;
			if(judge_array_empty(diff_i1,DIFF_CYCLE))
			{
				plst.diff_st=STG_FREE;
			}

			clr_wr(R,num_ofrg(diff_i1[DIFF_CYCLE],0,R));
			clr_wwr(R,num_ofrg(diff_i1[DIFF_CYCLE],0,R));
			clr_wrd(R,num_ofrg(diff_i1[DIFF_CYCLE],0,R));
			memcpy(&PRV->R_V[num_ofrg(diff_i1[DIFF_CYCLE],0,R)],&RV->R_V[num_ofrg(diff_i1[DIFF_CYCLE],0,R)],sizeof(struct RG));

			/*clr_rd(R,num_ofrg(diff_i1[DIFF_CYCLE],1,R));
			clr_wwr(R,num_ofrg(diff_i1[DIFF_CYCLE],1,R));
			clr_wrd(R,num_ofrg(diff_i1[DIFF_CYCLE],1,R));*/
		}
	}

	if(plst.randgen_st==STG_BUSY)
    {
		//if(plst.randgen_cycle==RANDGEN_CYCLE)
		//{
		//	convert_ins_to_b(randgen_i1,fp_saveRTLB);
		//}
		if (dugD)
		{
			//if (report_fl == 1)
			//{
				myprint_report("     RANDGEN :instruction ", randgen_i1.ex_ins + 1, ": ", NULL, ins[randgen_i1.ex_ins].instr, NULL);
				printf("     RANDGEN :instruction %d : %s\n", randgen_i1.ex_ins + 1, ins[randgen_i1.ex_ins].instr);
			//}
		}
        randgen_execute_time++;
		plst.randgen_cycle=plst.randgen_cycle-1;
		if(plst.randgen_cycle==0)
		{
			randgen(randgen_i1.op[0],clk);

			plst.randgen_st=STG_FREE;
            plst.randgen_if1=STG_NRDY;

			clr_wr(RD,num_ofrg(randgen_i1,0,R));
			clr_wwr(RD,num_ofrg(randgen_i1,0,R));
			clr_wrd(RD,num_ofrg(randgen_i1,0,R));
		}
	}

	if(plst.probcmp_st==STG_BUSY)
    {
		if(probcmp_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(probcmp_i1[0],fp_saveRTLB);
			probcmp(probcmp_i1[0].op[0],probcmp_i1[0].op[1],probcmp_i1[0].op[2],clk);

			clr_rd(R,num_ofrg(probcmp_i1[0],1,R));
			clr_wwr(R,num_ofrg(probcmp_i1[0],1,R));
			clr_wrd(R,num_ofrg(probcmp_i1[0],1,R));

			clr_rd(RD,num_ofrg(probcmp_i1[0],2,R));
			clr_wwr(RD,num_ofrg(probcmp_i1[0],2,R));
			clr_wrd(RD,num_ofrg(probcmp_i1[0],2,R));
		}
		if (dugD)
		{
			//if (report_fl == 1)
			//{
				int i;
				for (i = 0;i<PROBCMP_CYCLE + 1;i++)
				{
					if (probcmp_i1[PROBCMP_CYCLE - i].is_exist_ins)
					{
						myprint_report("     PROBCMP :instruction ", probcmp_i1[PROBCMP_CYCLE - i].ex_ins + 1, ": ", NULL, ins[probcmp_i1[PROBCMP_CYCLE - i].ex_ins].instr, NULL);
						printf("     PROBCMP :instruction %d : %s\n", probcmp_i1[PROBCMP_CYCLE - i].ex_ins + 1, ins[probcmp_i1[PROBCMP_CYCLE - i].ex_ins].instr);
					}
				}
			//}
		}
		array_back_n(probcmp_i1,PROBCMP_CYCLE+1);
		plst.probcmp_if1=STG_NRDY;
        probcmp_execute_time++;
        //plst.probcmp_cycle=plst.probcmp_cycle-1;
		//plst.probcmp_cycle_func=plst.probcmp_cycle_func-1;
		if(probcmp_i1[PROBCMP_CYCLE].is_exist_ins)
		{
			//probcmp(probcmp_i1[PROBCMP_CYCLE].op[0],probcmp_i1[PROBCMP_CYCLE].op[1],probcmp_i1[PROBCMP_CYCLE].op[2],clk);

			probcmp_i1[PROBCMP_CYCLE].is_exist_ins=0;
			if(judge_array_empty(probcmp_i1,PROBCMP_CYCLE))
			{
				plst.probcmp_st=STG_FREE;
			}

			clr_wr(B,num_ofrg(probcmp_i1[PROBCMP_CYCLE],0,B));
			clr_wwr(B,num_ofrg(probcmp_i1[PROBCMP_CYCLE],0,B));
			clr_wrd(B,num_ofrg(probcmp_i1[PROBCMP_CYCLE],0,B));
			memcpy(&PBV->R_V[num_ofrg(probcmp_i1[PROBCMP_CYCLE],0,B)],&BV->R_V[num_ofrg(probcmp_i1[PROBCMP_CYCLE],0,B)],sizeof(struct RB));

			/*clr_rd(R,num_ofrg(probcmp_i1[PROBCMP_CYCLE],1,R));
			clr_wwr(R,num_ofrg(probcmp_i1[PROBCMP_CYCLE],1,R));
			clr_wrd(R,num_ofrg(probcmp_i1[PROBCMP_CYCLE],1,R));

			clr_rd(RD,num_ofrg(probcmp_i1[PROBCMP_CYCLE],2,R));
			clr_wwr(RD,num_ofrg(probcmp_i1[PROBCMP_CYCLE],2,R));
			clr_wrd(RD,num_ofrg(probcmp_i1[PROBCMP_CYCLE],2,R));*/
		}
	}

	if(plst.bias_st==STG_BUSY)
    {
		if(bias_i1[0].is_exist_ins)
		{
		//	convert_ins_to_b(bias_i1[0],fp_saveRTLB);
			bias(bias_i1[0].op[0],bias_i1[0].op[1],bias_i1[0].op[2].opd.type_FD,clk,bias_i1[0].ex_ins);

			clr_rd(R,num_ofrg(bias_i1[0],1,R));
			clr_wwr(R,num_ofrg(bias_i1[0],1,R));
			clr_wrd(R,num_ofrg(bias_i1[0],1,R));
		}
		if (dugD)
		{
			//if (report_fl == 1)
			//{
				int i;
				for (i = 0;i<BIAS_CYCLE + 1;i++)
				{
					if (bias_i1[BIAS_CYCLE - i].is_exist_ins)
					{
						myprint_report("     BIAS :instruction ", bias_i1[BIAS_CYCLE - i].ex_ins + 1, ": ", NULL, ins[bias_i1[BIAS_CYCLE - i].ex_ins].instr, NULL);
						printf("     BIAS :instruction %d : %s\n", bias_i1[BIAS_CYCLE - i].ex_ins + 1, ins[bias_i1[BIAS_CYCLE - i].ex_ins].instr);
					}
				}
			//}
		}
		array_back_n(bias_i1,BIAS_CYCLE+1);
		plst.bias_if1=STG_NRDY;
        bias_execute_time++;
        plst.bias_cycle=plst.bias_cycle-1;
		plst.bias_cycle_func=plst.bias_cycle_func-1;
		if(bias_i1[BIAS_CYCLE].is_exist_ins)
		{
			//bias(bias_i1[BIAS_CYCLE].op[0],bias_i1[BIAS_CYCLE].op[1],bias_i1[BIAS_CYCLE].op[2].opd.type_FD,clk);

			bias_i1[BIAS_CYCLE].is_exist_ins=0;
			if(judge_array_empty(bias_i1,BIAS_CYCLE))
			{
				plst.bias_st=STG_FREE;
			}

			clr_wr(R,num_ofrg(bias_i1[BIAS_CYCLE],0,R));
			clr_wwr(R,num_ofrg(bias_i1[BIAS_CYCLE],0,R));
			clr_wrd(R,num_ofrg(bias_i1[BIAS_CYCLE],0,R));
			memcpy(&PRV->R_V[num_ofrg(bias_i1[BIAS_CYCLE],0,R)],&RV->R_V[num_ofrg(bias_i1[BIAS_CYCLE],0,R)],sizeof(struct RG));

			/*clr_rd(R,num_ofrg(bias_i1[BIAS_CYCLE],1,R));
			clr_wwr(R,num_ofrg(bias_i1[BIAS_CYCLE],1,R));
			clr_wrd(R,num_ofrg(bias_i1[BIAS_CYCLE],1,R));*/
		}
	}

	if(plst.act_st==STG_BUSY)
    {
		if(act_i1[0].is_exist_ins)
		{
			//convert_ins_to_b(bias_i1[0],fp_saveRTLB);
			act(act_i1[0].op[0],act_i1[0].op[1],act_i1[0].op[2].opd.type_FD,clk,act_i1[0].ex_ins);

			clr_rd(R,num_ofrg(act_i1[0],1,R));
			clr_wwr(R,num_ofrg(act_i1[0],1,R));
			clr_wrd(R,num_ofrg(act_i1[0],1,R));
		}
		if (dugD)
		{
			//if (report_fl == 1)
			//{
				int i;
				for (i = 0;i<ACT_CYCLE + 1;i++)
				{
					if (act_i1[ACT_CYCLE - i].is_exist_ins)
					{
						myprint_report("     BIAS :instruction ", act_i1[ACT_CYCLE - i].ex_ins + 1, ": ", NULL, ins[act_i1[ACT_CYCLE - i].ex_ins].instr, NULL);
						printf("     BIAS :instruction %d : %s\n", act_i1[ACT_CYCLE - i].ex_ins + 1, ins[act_i1[ACT_CYCLE - i].ex_ins].instr);
					}
				}
			//}
		}
		array_back_n(act_i1,ACT_CYCLE+1);
		plst.act_if1=STG_NRDY;
		act_execute_time++;
		plst.act_cycle=plst.act_cycle-1;
		plst.act_cycle_func=plst.act_cycle_func-1;
		if(act_i1[ACT_CYCLE].is_exist_ins)
		{

			act_i1[ACT_CYCLE].is_exist_ins=0;
			if(judge_array_empty(act_i1,ACT_CYCLE))
			{
				plst.act_st=STG_FREE;
			}

			clr_wr(R,num_ofrg(act_i1[ACT_CYCLE],0,R));
			clr_wwr(R,num_ofrg(act_i1[ACT_CYCLE],0,R));
			clr_wrd(R,num_ofrg(act_i1[ACT_CYCLE],0,R));
			memcpy(&PRV->R_V[num_ofrg(act_i1[ACT_CYCLE],0,R)],&RV->R_V[num_ofrg(act_i1[ACT_CYCLE],0,R)],sizeof(struct RG));

			/*clr_rd(R,num_ofrg(bias_i1[BIAS_CYCLE],1,R));
			clr_wwr(R,num_ofrg(bias_i1[BIAS_CYCLE],1,R));
			clr_wrd(R,num_ofrg(bias_i1[BIAS_CYCLE],1,R));*/
		}
	}

	if(plst.exe_st1 == STG_BUSY)
	{
		if (allF || rtlD)
		{
			if (plst.rtlMaxWord_i1<RTL_A_WORD)
			{
				int k = 0;
				for (;k<RTL_A_WORD - plst.rtlMaxWord_i1;k++)
				{
					zeroize_ADDR(32, fp_saveRTLB);
					linefeed_ADDR(fp_saveRTLB);
				}
			}
		}
	}
	
    if(myRTLDebug)
    {
    	linefeed_ADDR(fp_saveRTLB);
    }
	
    if((plst.fetch_if0==STG_READY)&&(plst.fetch_if1==STG_NRDY))
    {
         plst.fetch_if0=STG_NRDY;
         plst.fetch_if1=STG_READY;
    }

	if((endfetch==0)&&(decode_f_num != 0))
	{
		int i=0;
		decode_of_num_i1=0;
		memset(decode_i1,0,sizeof(decode_i1));
		for(;i<decode_f_num;i++)
		{
			decode_i1[i].opcode = ins[buff_f_ins[i].buff_fetch_num].opcode;
			decode_i1[i].decode_ins = buff_f_ins[i].buff_fetch_num;
			decode_i1[i].op[0] = ins[buff_f_ins[i].buff_fetch_num].op[0];
			decode_i1[i].op[1] = ins[buff_f_ins[i].buff_fetch_num].op[1];
			decode_i1[i].op[2] = ins[buff_f_ins[i].buff_fetch_num].op[2];
			decode_i1[i].op[3] = ins[buff_f_ins[i].buff_fetch_num].op[3];
			decode_of_num_i1++;
		}
		decode_end=0;
		decode_f_num=0;
		plst.decode_if0=STG_NRDY;
		plst.decode_if1=STG_READY;
	}

    if((plst.decode_if0==STG_READY)&&(plst.decode_if1==STG_NRDY))
    {
		int i=0,k,j=0;
		decode_of_num_i1=0;
		zeroDecode_i1();
		if(decode_end==1)
		{
			decode_end=0;
			for(;i<decode_f_num;i++)
			{
				decode_i1[i].opcode = ins[buff_f_ins[i].buff_fetch_num].opcode;
				decode_i1[i].decode_ins = buff_f_ins[i].buff_fetch_num;
				decode_i1[i].op[0] = ins[buff_f_ins[i].buff_fetch_num].op[0];
				decode_i1[i].op[1] = ins[buff_f_ins[i].buff_fetch_num].op[1];
				decode_i1[i].op[2] = ins[buff_f_ins[i].buff_fetch_num].op[2];
				decode_i1[i].op[3] = ins[buff_f_ins[i].buff_fetch_num].op[3];
				decode_of_num_i1++;
			}
			decode_f_num=0;
			//memset(buff_f_ins,0,sizeof(buff_f_ins));
			zeroBuff_f_ins();
		}
		if(endfetchdecode)
		{
			for(k=0;k<fetch_of_num_i1;k++)
			{
				if(i<fetch_num)
				{
					decode_i1[i++]=decode_i0[k];
					++decode_of_num_i1;
				}
				else
				{
					fetch_buff[j++]=decode_i0[k].decode_ins;
					fetch_success=0;
					fetch_f_num++;
				}
			}
		}
		else
		{
			for(k=0;k<fetch_of_num_i1;k++)
			{
				fetch_buff[j++]=decode_i0[k].decode_ins;
				fetch_success=0;
				fetch_f_num++;
			}

		}
		plst.decode_if0=STG_NRDY;
		plst.decode_if1=STG_READY;
	}

	if((plst.exe_st0==STG_BUSY))
	{
		plst.exe_st1=STG_BUSY;
		plst.exe_st0=STG_FREE;
		plst.rtlMaxWord_i1=rtlMaxWord;
		if(rtlMaxWord<RTL_A_WORD)
		{
			rtlMaxWord=0;
		}
		else
		{
			rtlMaxWord=rtlMaxWord-RTL_A_WORD;
		}
	}

	if(plst.loop_if0==STG_READY)
	{
		int i = 0,j = 0;
		for(j=0;j<9;j++)
		{
			if(loop_i1[j].is_exist_ins)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		for(i=0;i<9-j;i++)
		{
			loop_i1[j+i] = loop_i0[i];
		}
		memset(loop_i0,0,sizeof(loop_i0));
		plst.loop_st = STG_BUSY;
		plst.loop_if0 = STG_NRDY;
	}

	if(plst.endloop_if0==STG_READY)
	{
		int i = 0;
		for(i=0;i<9;i++)
		{
			endloop_i1[i] = endloop_i0[i];
		}
		memset(endloop_i0,0,sizeof(endloop_i0));
		plst.endloop_st = STG_BUSY;
		plst.endloop_if0 = STG_NRDY;
	}
   
    if((plst.load_if0==STG_READY)&&(plst.load_if1==STG_NRDY))
    {
         load_i1[0]=load_i0;
         plst.load_if0=STG_NRDY;
         plst.load_if1=STG_READY;
    }

    if((plst.launch_if0==STG_READY)&&(plst.launch_if1==STG_NRDY))
    {
         launch_i1[0]=launch_i0;
         plst.launch_if0=STG_NRDY;
         plst.launch_if1=STG_READY;
    }

	 if((plst.wb_if0==STG_READY)&&(plst.wb_if1==STG_NRDY))
    {
         wb_i1[0]=wb_i0;
         plst.wb_if0=STG_NRDY;
         plst.wb_if1=STG_READY;
    }

    if((plst.store_if0==STG_READY)&&(plst.store_if1==STG_NRDY))
    {
         store_i1[0]=store_i0;
         plst.store_if0=STG_NRDY;
         plst.store_if1=STG_READY;
    }

	 if((plst.mov_if0==STG_READY)&&(plst.mov_if1==STG_NRDY))
    {
         mov_i1[0]=mov_i0;
         plst.mov_if0=STG_NRDY;
         plst.mov_if1=STG_READY;
    }

    if((plst.extmov_if0==STG_READY)&&(plst.extmov_if1==STG_NRDY))
     {
          extmov_i1[0]=extmov_i0;
          plst.extmov_if0=STG_NRDY;
          plst.extmov_if1=STG_READY;
     }
   
    if((plst.dmalr_if0==STG_READY)&&(plst.dmalr_if1==STG_NRDY))
     {
          dmalr_i1=dmalr_i0;
          plst.dmalr_if0=STG_NRDY;
          plst.dmalr_if1=STG_READY;
     }
   
    if((plst.dmalc_if0==STG_READY)&&(plst.dmalc_if1==STG_NRDY))
     {
          dmalc_i1=dmalc_i0;
          plst.dmalc_if0=STG_NRDY;
          plst.dmalc_if1=STG_READY;
     }
   
    if((plst.dmasr_if0==STG_READY)&&(plst.dmasr_if1==STG_NRDY))
     {
          dmasr_i1=dmasr_i0;
          plst.dmasr_if0=STG_NRDY;
          plst.dmasr_if1=STG_READY;
     }
   
    if((plst.dmasc_if0==STG_READY)&&(plst.dmasc_if1==STG_NRDY))
    {
         dmasc_i1=dmasc_i0;
         plst.dmasc_if0=STG_NRDY;
         plst.dmasc_if1=STG_READY;
    }

    if((plst.prodvm_if0==STG_READY)&&(plst.prodvm_if1==STG_NRDY))
    {
         prodvm_i1[0]=prodvm_i0;
         plst.prodvm_if0=STG_NRDY;
         plst.prodvm_if1=STG_READY;
    }

	if((plst.prodvmp_if0==STG_READY)&&(plst.prodvmp_if1==STG_NRDY))
    {
         prodvmp_i1[0]=prodvmp_i0;
         plst.prodvmp_if0=STG_NRDY;
         plst.prodvmp_if1=STG_READY;
    }

    if((plst.prodmv_if0==STG_READY)&&(plst.prodmv_if1==STG_NRDY))
    {
         prodmv_i1[0]=prodmv_i0;
         plst.prodmv_if0=STG_NRDY;
         plst.prodmv_if1=STG_READY;
    }

	 if((plst.prodmvp_if0==STG_READY)&&(plst.prodmvp_if1==STG_NRDY))
    {
         prodmvp_i1[0]=prodmvp_i0;
         plst.prodmvp_if0=STG_NRDY;
         plst.prodmvp_if1=STG_READY;
    }

    if((plst.prodvv_if0==STG_READY)&&(plst.prodvv_if1==STG_NRDY))
    {
         prodvv_i1[0]=prodvv_i0;
         plst.prodvv_if0=STG_NRDY;
         plst.prodvv_if1=STG_READY;
    }

	if((plst.prodvvp_if0==STG_READY)&&(plst.prodvvp_if1==STG_NRDY))
    {
         prodvvp_i1[0]=prodvvp_i0;
         plst.prodvvp_if0=STG_NRDY;
         plst.prodvvp_if1=STG_READY;
    }

    if((plst.prodvvd_if0==STG_READY)&&(plst.prodvvd_if1==STG_NRDY))
    {
         prodvvd_i1[0]=prodvvd_i0;
         plst.prodvvd_if0=STG_NRDY;
         plst.prodvvd_if1=STG_READY;
    }

    if((plst.addv_if0==STG_READY)&&(plst.addv_if1==STG_NRDY))
    {
         addv_i1[0]=addv_i0;
         plst.addv_if0=STG_NRDY;
         plst.addv_if1=STG_READY;
    }

	 if((plst.addm_if0==STG_READY)&&(plst.addm_if1==STG_NRDY))
    {
         addm_i1[0]=addm_i0;
         plst.addm_if0=STG_NRDY;
         plst.addm_if1=STG_READY;
    }

    if((plst.subv_if0==STG_READY)&&(plst.subv_if1==STG_NRDY))
    {
        subv_i1[0]=subv_i0;
        plst.subv_if0=STG_NRDY;
		plst.subv_if1=STG_READY;
    }

	if((plst.subm_if0==STG_READY)&&(plst.subm_if1==STG_NRDY))
    {
        subm_i1[0]=subm_i0;
        plst.subm_if0=STG_NRDY;
		plst.subm_if1=STG_READY;
    }

	if((plst.max_if0==STG_READY)&&(plst.max_if1==STG_NRDY))
    {
        max_i1[0]=max_i0;
        plst.max_if0=STG_NRDY;
		plst.max_if1=STG_READY;
    }

	if((plst.scale_if0==STG_READY)&&(plst.scale_if1==STG_NRDY))
    {
        scale_i1[0]=scale_i0;
        plst.scale_if0=STG_NRDY;
		plst.scale_if1=STG_READY;
    }

	if((plst.diff_if0==STG_READY)&&(plst.diff_if1==STG_NRDY))
    {
        diff_i1[0]=diff_i0;
        plst.diff_if0=STG_NRDY;
		plst.diff_if1=STG_READY;
    }

	if((plst.randgen_if0==STG_READY)&&(plst.randgen_if1==STG_NRDY))
    {
        randgen_i1=randgen_i0;
        plst.randgen_if0=STG_NRDY;
		plst.randgen_if1=STG_READY;
    }

	if((plst.probcmp_if0==STG_READY)&&(plst.probcmp_if1==STG_NRDY))
    {
        probcmp_i1[0]=probcmp_i0;
        plst.probcmp_if0=STG_NRDY;
		plst.probcmp_if1=STG_READY;
    }

	if((plst.bias_if0==STG_READY)&&(plst.bias_if1==STG_NRDY))
    {
        bias_i1[0]=bias_i0;
        plst.bias_if0=STG_NRDY;
		plst.bias_if1=STG_READY;
    }

	if((plst.act_if0==STG_READY)&&(plst.act_if1==STG_NRDY))
	{
		act_i1[0]=act_i0;
		plst.act_if0=STG_NRDY;
		plst.act_if1=STG_READY;
	}

    return 1;
}
