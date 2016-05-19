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
 * pu
 *
 * Instruction operation modeling
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "pu.h"
#include "fixcomp.h"
#include "print_error.h"
#include "mctrl.h"
#include "localBufferModeling.h"
#include "common.h"
#include "bandwith_monitor.h"
#include "data_reuse.h"
#include "operation_type.h"

bool load(INS_OPD op,long length,int buff_id,long buff_addr,int clk)
{
	int i;
	if(op.type_flag == 0)
	{
		for(i=0;i<length;i++)
		{
			if(buff_id==0)
			{
				buffer0_out_bandwith+=SHORT_SIZE;
				if(get_mbdata(buff0,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i) != 0)
				{
					op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i] = 1;
					BV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
				else
				{
					op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i] = 0;
					BV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
			}
			else if(buff_id==1)
			{
				buffer1_out_bandwith+=SHORT_SIZE;
				if(get_mbdata(buff1,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i) != 0)
				{
					op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i] = 1;
					BV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
				else
				{
					op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i] = 0;
					BV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
			}
			else if(buff_id==2)
			{
				buffer2_out_bandwith+=SHORT_SIZE;
				if(get_mbdata(buff2,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i) != 0)
				{
					op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i] = 1;
					BV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
				else
				{
					op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i] = 0;
					BV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
			}
			else
			{
				printf("load use inexistence buffer! \n");
			}
		}
		for(i=length;i<RG_SIZE;i++)
		{
			op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i] = 0;
			BV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}
	else if(op.type_flag == 1)
	{
		if (allF || perfD)
		{
			creat_node_rs_num(&RV_dreuse[op.opd.type_RV.rg_num]);
			st_dr.rv_clk[op.opd.type_RV.rg_num] = clk;
		}

		for(i=0;i<length;i++)
		{
			if(buff_id==0)
			{
				op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i] = get_mbdata(buff0,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i);
			    RV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				buffer0_out_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==1)
			{
				op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i] = get_mbdata(buff1,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i);
				RV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				buffer1_out_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==2)
			{
				op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i] = get_mbdata(buff2,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i);
				RV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				buffer2_out_bandwith+=SHORT_SIZE;
			}
			else
			{
				printf("load use inexistence buffer! \n");
			}
		}
		for(i=length;i<RG_SIZE;i++)
		{
			op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i] = 0;
			RV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}
	else
	{
		for(i=0;i<length;i++)
		{
			if(buff_id==0)
			{
				op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i] = get_mbdata(buff0,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i);
				RDV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				buffer0_out_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==1)
			{
				op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i] = get_mbdata(buff1,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i);
				RDV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				buffer1_out_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==2)
			{
				op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i] = get_mbdata(buff2,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i);
				RDV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				buffer2_out_bandwith+=SHORT_SIZE;
			}
			else
			{
				printf("load use inexistence buffer! \n");
			}
		}
		for(i=length;i<RG_SIZE;i++)
		{
			op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i] = 0;
			RDV_in_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}
}		
		
bool launch(G_M* M,int row,int col,int buff_id,long buff_addr,int mat_num,int clk)
{
	int i,j;
	int row_b,col_b;
	row_b = buff_addr%MEM_BUFF_ENTRY_SIZE;col_b = buff_addr/MEM_BUFF_ENTRY_SIZE;
	if (allF || perfD)
	{
		creat_node_rs_num(&MAT_dreuse[mat_num]);
		st_dr.mat_clk[mat_num] = clk;
	}
	
	for(i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			if(buff_id==0)
			{
				M->M_V[i].V[j] = get_mbdata(buff0,row_b,col_b+j);
				MAT_in_bandwith[mat_num]+=SHORT_SIZE;
				buffer0_out_bandwith+=SHORT_SIZE;

			}
			else if(buff_id==1)
			{
    			M->M_V[i].V[j] = get_mbdata(buff1,row_b,col_b+j);
				MAT_in_bandwith[mat_num]+=SHORT_SIZE;
				buffer1_out_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==2)
			{
		    	M->M_V[i].V[j] = get_mbdata(buff2,row_b,col_b+j);
				MAT_in_bandwith[mat_num]+=SHORT_SIZE;
				buffer2_out_bandwith+=SHORT_SIZE;
			}
			else
			{
				print_error_ex("launch use inexistence buffer! \n"); 
			}
		}
		if(col<V_SIZE)
		{
			for(j=col;j<V_SIZE;j++)
			{
				M->M_V[i].V[j] = 0;
				MAT_in_bandwith[mat_num]+=SHORT_SIZE;
			}
		}
		col_b=col_b+V_SIZE;
	}
	if(row<V_SIZE)
	{
		for(i=row;i<V_NUM;i++)
		{
			for(j=0;j<V_SIZE;j++)
			{
				M->M_V[i].V[j] = 0;
				MAT_in_bandwith[mat_num]+=SHORT_SIZE;
			}
		}
	}
	return 1;
}		
		
bool store(INS_OPD op,long length,int buff_id,long buff_addr,int clk)
{
	int i;
	if(op.type_flag == 0)
	{
		for(i=0;i<length;i++)
		{
			if(buff_id==0)
			{
				back_mbdata(buff0,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i]);
				BV_out_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				buffer0_in_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==1)
			{
    			back_mbdata(buff1,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i]);
				BV_out_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				buffer1_in_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==2)
			{
		    	back_mbdata(buff2,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,op.opd.type_BV.pBV->R_V[op.opd.type_BV.rg_num].V[i]);
				BV_out_bandwith[op.opd.type_BV.rg_num]+=SHORT_SIZE;
				buffer2_in_bandwith+=SHORT_SIZE;
			}
			else
			{
				printf("store use inexistence buffer! \n");
			}
		}
		if(length<RG_SIZE)
		{
			for(;i<RG_SIZE;i++)
			{
		    	if(buff_id==0)
				{
		    		back_mbdata(buff0,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,0);
					buffer0_in_bandwith+=SHORT_SIZE;
				}
	    		else if(buff_id==1)
				{
        			back_mbdata(buff1,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,0);
					buffer1_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==2)
				{
	    	    	back_mbdata(buff2,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,0);
					buffer2_in_bandwith+=SHORT_SIZE;
				}
		    	else
				{
		    		printf("store use inexistence buffer! \n");
				}
			}
		}
		return 1;
	}
	else if(op.type_flag == 1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op.opd.type_RV.rg_num], clk - st_dr.rv_clk[op.opd.type_RV.rg_num]);
			st_dr.rv_clk[op.opd.type_RV.rg_num] = clk;
		}
		
		for(i=0;i<length;i++)
		{
			if(buff_id==0)
			{
				back_mbdata(buff0,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]);
			    buffer0_in_bandwith+=SHORT_SIZE;
				RV_out_bandwith[op.opd.type_RV.rg_num]+=SHORT_SIZE;
			}
			else if(buff_id==1)
			{
    			back_mbdata(buff1,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]);
				buffer1_in_bandwith+=SHORT_SIZE;
				RV_out_bandwith[op.opd.type_RV.rg_num]+=SHORT_SIZE;
			}
			else if(buff_id==2)
			{
		    	back_mbdata(buff2,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]);
				buffer2_in_bandwith+=SHORT_SIZE;
				RV_out_bandwith[op.opd.type_RV.rg_num]+=SHORT_SIZE;
			}
			else
			{
				printf("store use inexistence buffer! \n");
			}
		}
		if(length<RG_SIZE)
		{
			for(;i<RG_SIZE;i++)
			{
				if(buff_id==0)
				{
		    		back_mbdata(buff0,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,0);
					buffer0_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==1)
				{
    		    	back_mbdata(buff1,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,0);
					buffer1_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==2)
				{
		        	back_mbdata(buff2,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,0);
					buffer2_in_bandwith+=SHORT_SIZE;
				}
	    		else
				{
		    		printf("store use inexistence buffer! \n");
				}
			}
		}
		return 1;
	}
	else
	{
		for(i=0;i<length;i++)
		{
			if(buff_id==0)
			{
				back_mbdata(buff0,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]);
				buffer0_in_bandwith+=SHORT_SIZE;
				RDV_out_bandwith[op.opd.type_RV.rg_num]+=SHORT_SIZE;
			}
			else if(buff_id==1)
			{
    			back_mbdata(buff1,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]);
				buffer1_in_bandwith+=SHORT_SIZE;
				RDV_out_bandwith[op.opd.type_RV.rg_num]+=SHORT_SIZE;
			}
			else if(buff_id==2)
			{
		    	back_mbdata(buff2,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]);
				buffer2_in_bandwith+=SHORT_SIZE;
				RDV_out_bandwith[op.opd.type_RV.rg_num]+=SHORT_SIZE;
			}
			else
			{
				printf("store use inexistence buffer! \n");
			}
		}
		if(length<RG_SIZE)
		{
			for(;i<RG_SIZE;i++)
			{
				if(buff_id==0)
				{
					back_mbdata(buff0,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,0);
					buffer0_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==1)
				{
        			back_mbdata(buff1,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,0);
					buffer1_in_bandwith+=SHORT_SIZE;
				}
	    		else if(buff_id==2)
				{
	    	    	back_mbdata(buff2,buff_addr%MEM_BUFF_ENTRY_SIZE,buff_addr/MEM_BUFF_ENTRY_SIZE+i,0);
					buffer2_in_bandwith+=SHORT_SIZE;
				}
	    		else
				{
	    			printf("store use inexistence buffer! \n");
				}
			}
		}
		return 1;
	}
}		
		
bool wb(G_M* M,int row,int col,int buff_id,long buff_addr,int mat_num,int clk)
{
	int i,j;
	int row_b,col_b;
	if (allF || perfD)
	{
		add_node_rs_clk(&MAT_dreuse[mat_num], clk - st_dr.mat_clk[mat_num]);
		st_dr.mat_clk[mat_num] = clk;
	}
	
	row_b = buff_addr%MEM_BUFF_ENTRY_SIZE;col_b = buff_addr/MEM_BUFF_ENTRY_SIZE;
	for(i=0;i<row;i++)
	{
		for (j=0;j<col;j++)
		{
			if(buff_id==0)
			{
				back_mbdata(buff0,row_b,col_b+i*RG_SIZE+j,M->M_V[i].V[j]);
				buffer0_in_bandwith+=SHORT_SIZE;
				MAT_out_bandwith[mat_num]+=SHORT_SIZE;
			}
			else if(buff_id==1)
			{
    			back_mbdata(buff1,row_b,col_b+i*RG_SIZE+j,M->M_V[i].V[j]);
				buffer1_in_bandwith+=SHORT_SIZE;
				MAT_out_bandwith[mat_num]+=SHORT_SIZE;
			}
			else if(buff_id==2)
			{
		    	back_mbdata(buff2,row_b,col_b+i*RG_SIZE+j,M->M_V[i].V[j]);
				buffer2_in_bandwith+=SHORT_SIZE;
				MAT_out_bandwith[mat_num]+=SHORT_SIZE;
			}
			else
			{
				printf("wb use inexistence buffer! \n"); 
			}
		}
		if(col<V_SIZE)
			for(j=col;j<V_SIZE;j++)
			{
				if(buff_id==0)
				{
			    	back_mbdata(buff0,row_b,col_b+i*RG_SIZE+j,0);
					buffer0_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==1)
				{
    		    	back_mbdata(buff1,row_b,col_b+i*RG_SIZE+j,0);
					buffer1_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==2)
				{
		        	back_mbdata(buff2,row_b,col_b+i*RG_SIZE+j,0);
					buffer2_in_bandwith+=SHORT_SIZE;
				}
	    		else
				{
		    		printf("wb use inexistence buffer! \n"); 
				}
			}
	}
	if(row<V_SIZE)
	{
		for(i=row;i<V_NUM;i++)
			for(j=0;j<V_SIZE;j++)
			{
				if(buff_id==0)
				{
			    	back_mbdata(buff0,row_b,col_b+i*RG_SIZE+j,0);
					buffer0_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==1)
				{
    		    	back_mbdata(buff1,row_b,col_b+i*RG_SIZE+j,0);
					buffer1_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==2)
				{
		        	back_mbdata(buff2,row_b,col_b+i*RG_SIZE+j,0);
					buffer2_in_bandwith+=SHORT_SIZE;
				}
	    		else
				{
		    		printf("wb use inexistence buffer! \n"); 
				}
			}
	}
	return 1;
}

bool mov(INS_OPD op1,INS_OPD op2,int clk)
{
	int i;
	if(op1.type_flag==0 && op2.type_flag==0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i]=op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[i];
			BV_in_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==0)
	{
		if (allF || perfD)
		{
			creat_node_rs_num(&RV_dreuse[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[i];
			RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
			creat_node_rs_num(&RV_dreuse[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
			RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==2)
	{
		if (allF || perfD)
		{
			creat_node_rs_num(&RV_dreuse[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
			RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			RDV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==2 && op2.type_flag==0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[i];
			RDV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==2 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
		
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
			RDV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==2 && op2.type_flag==2)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
			RDV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			RDV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else
	{
		print_error_ex("mov ָ\C1\EE\B2\D9\D7\F7\CA\FD\C0\E0\D0Ͳ\BBƥ\C5\E4!");
		return 0;
	}
}

bool extmov(INS_OPD op1,INS_OPD op2,int clk)
{
	int i;
	if(op1.type_flag==0 && op2.type_flag==0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i]=op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[i];
			BV_in_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==0)
	{
		if (allF || perfD)
		{
			creat_node_rs_num(&RV_dreuse[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[i];
			RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
			creat_node_rs_num(&RV_dreuse[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
			RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==2)
	{
		if (allF || perfD)
		{
			creat_node_rs_num(&RV_dreuse[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
			RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			RDV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==2 && op2.type_flag==0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[i];
			RDV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==2 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
		
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
			RDV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else if(op1.type_flag==2 && op2.type_flag==2)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
			RDV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
			RDV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
		return 1;
	}else
	{
		print_error_ex("mov ָ\C1\EE\B2\D9\D7\F7\CA\FD\C0\E0\D0Ͳ\BBƥ\C5\E4!");
		return 0;
	}
}

bool dmalr(INS_OPD op,int clk)
{
	long mem_addr1,mem_addrt,mem_addr2,buff_addr;
	int length,repetition,stride,buff_id;
	length = op.opd.type_DMA.length;
	repetition = op.opd.type_DMA.repetition;
	stride = op.opd.type_DMA.stride;
	buff_id = op.opd.type_DMA.buff_id;
	buff_addr = op.opd.type_DMA.buff_addr;
	mem_addrt = op.opd.type_DMA.mem_addr;
	int j,count; short data;
	int row,col;
	row = buff_addr%MEM_BUFF_ENTRY_SIZE;
	col = buff_addr/MEM_BUFF_ENTRY_SIZE;
	for(count=0;count<repetition;count++)
	{
		mem_addr1 = mem_addrt+count*stride;
		mem_addr2 = mem_addr1+length-1;
		for(j=0;j<length;j++)
		{
			data = read_mm(mem_addr1+j);
			mem_out_bandwith+=SHORT_SIZE;
			if(buff_id==0)
			{
				back_mbdata(buff0,row,col+count*V_SIZE+j,data);
				buffer0_in_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==1)
			{
    			back_mbdata(buff1,row,col+count*V_SIZE+j,data);
				buffer1_in_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==2)
			{
		    	back_mbdata(buff2,row,col+count*V_SIZE+j,data);
				buffer2_in_bandwith+=SHORT_SIZE;
			}
			else
			{
				printf("dmalr use inexistence buffer! \n"); 
			}
		}
		if(length<V_SIZE)
		{
			for(;j<V_SIZE;j++)
			{
				if(buff_id==0)
				{
			    	back_mbdata(buff0,row,col+count*V_SIZE+j,0);
					buffer0_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==1)
				{
    	    		back_mbdata(buff1,row,col+count*V_SIZE+j,0);
					buffer1_in_bandwith+=SHORT_SIZE;
				}
		    	else if(buff_id==2)
				{
		        	back_mbdata(buff2,row,col+count*V_SIZE+j,0);
					buffer2_in_bandwith+=SHORT_SIZE;
				}
		    	else
				{
		    		printf("dmalr use inexistence buffer! \n"); 
				}
			}
		}
	}
	return 1;
}

bool dmalc(INS_OPD op,int clk)
{
	long mem_addrt,mem_addr1,buff_addr;
	int length,repetition,stride,buff_id;
	int row,col;
	length = op.opd.type_DMA.length;
	repetition = op.opd.type_DMA.repetition;
	stride = op.opd.type_DMA.stride;
	buff_id = op.opd.type_DMA.buff_id;
	buff_addr = op.opd.type_DMA.buff_addr;
	mem_addrt = op.opd.type_DMA.mem_addr;
	int i,count; short data;
	struct MEM_B * buff_p;
	buff_p = get_buffp(buff_id);
	row = buff_addr%MEM_BUFF_ENTRY_SIZE;
	col = buff_addr/MEM_BUFF_ENTRY_SIZE;
	for(count=0;count<repetition;count++)
	{
		mem_addr1 = mem_addrt+count*stride;
		for(i=0;i<length;i++)
		{
			data = read_mm(mem_addr1+i);
			mem_out_bandwith+=SHORT_SIZE;
			back_mbdata(buff_p,row+i,col,data);
			if(buff_id==0)
			{
				buffer0_in_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==1)
			{
				buffer1_in_bandwith+=SHORT_SIZE;
			}
			else if(buff_id==2)
			{
				buffer2_in_bandwith+=SHORT_SIZE;
			}
			else
			{
			}
		}
		if(length<V_SIZE)
		{
			for(;i<V_SIZE;i++)
			{
				back_mbdata(buff_p,row+i,col,0);
				if(buff_id==0)
	 		    {
			    	buffer0_in_bandwith+=SHORT_SIZE;
			    }
			    else if(buff_id==1)
			    {
			    	buffer1_in_bandwith+=SHORT_SIZE;
			    }
			    else if(buff_id==2)
			    {
			    	buffer2_in_bandwith+=SHORT_SIZE;
			    }
			    else
			    {
			    }
			}
		}
		row = V_SIZE+row;
	}
	return 1;
}

bool dmasr(INS_OPD op,int clk)
{
	long mem_addrt,mem_addr1,buff_addr;
	int length,repetition,stride,buff_id;
	int row,col;
	length = op.opd.type_DMA.length;
	repetition = op.opd.type_DMA.repetition;
	stride = op.opd.type_DMA.stride;
	buff_id = op.opd.type_DMA.buff_id;
	buff_addr = op.opd.type_DMA.buff_addr;
	mem_addrt = op.opd.type_DMA.mem_addr;
	int i,count; short data;
	struct MEM_B * buff_p;
	buff_p = get_buffp(buff_id);
	row = buff_addr;
	for(count=0;count<repetition;count++)
	{
		mem_addr1 = mem_addrt+count*stride;
		col = count*V_SIZE;
		for(i=0;i<length;i++)
		{
			data = get_mbdata(buff_p,row,col+i);
			if(buff_id==0)
	 	    {
		    	buffer0_out_bandwith+=SHORT_SIZE;
		    }
		    else if(buff_id==1)
		    {
		    	buffer1_out_bandwith+=SHORT_SIZE;
		    }
		    else if(buff_id==2)
		    {
		    	buffer2_out_bandwith+=SHORT_SIZE;
		    }
		    else
		    {
		    }
			mem_in_bandwith+=SHORT_SIZE;
			write_mm(mem_addr1+i,data);
		}
	}

	return 1;
}

bool dmasc(INS_OPD op,int clk)
{
	long mem_addrt,mem_addr1,buff_addr;
	int length,repetition,stride,buff_id;
	int row,col;
	length = op.opd.type_DMA.length;
	repetition = op.opd.type_DMA.repetition;
	stride = op.opd.type_DMA.stride;
	buff_id = op.opd.type_DMA.buff_id;
	buff_addr = op.opd.type_DMA.buff_addr;
	mem_addrt = op.opd.type_DMA.mem_addr;
	int i,count; short data;
	struct MEM_B * buff_p;
	buff_p = get_buffp(buff_id);
	row = buff_addr%MEM_BUFF_ENTRY_SIZE;
	col = buff_addr/MEM_BUFF_ENTRY_SIZE;
	for(count=0;count<repetition;count++)
	{
		mem_addr1 = mem_addrt+count*stride;
		for(i=0;i<length;i++)
		{
			data = get_mbdata(buff_p,row+i,col);
			if(buff_id==0)
	 	    {
		    	buffer0_out_bandwith+=SHORT_SIZE;
		    }
		    else if(buff_id==1)
		    {
		    	buffer1_out_bandwith+=SHORT_SIZE;
		    }
		    else if(buff_id==2)
		    {
		    	buffer2_out_bandwith+=SHORT_SIZE;
		    }
		    else
		    {
		    }
			write_mm(mem_addr1+i,data);
			mem_in_bandwith+=SHORT_SIZE;
		}
		row = V_SIZE+row;
	}
	return 1;
}

bool prodvm(INS_OPD op1, INS_OPD op2, G_M* M,INS_OPD op4,int mat_num,int clk,int ins_line)
{
	int i,j;

	VM_num_mul++;

	add_node_rs_clk(&MAT_dreuse[mat_num],clk-st_dr.mat_clk[mat_num]);
	st_dr.mat_clk[mat_num]=clk;
	if(op4.opd.accumul == 1)
	{
		VV_num_add++;
		if (allF || perfD)
		{
			add_node_rs_clk(&Rbuffer_dreuse, clk - st_dr.rbuffer_clk);
			st_dr.rbuffer_clk = clk;
		}
	}
	if(op2.type_flag == 0)
   	{
   		for(i=0;i<RG_SIZE;i++)
   		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=0;
			if(op4.opd.accumul == 0)
			{
				for(j=0;j<RG_SIZE;j++)
				{
		    	  op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],fixmul(op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[j],M->M_V[j].V[i],ins_line),ins_line);
				  if(j==0)
				  {
					  RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				  }
				  else
				  {
					  RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					  RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				  }
				  BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
				  MAT_out_bandwith[mat_num]+=SHORT_SIZE;
				}
			}
			else
			{
				for(j=0;j<RG_SIZE;j++)
				{
		    	  op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],fixmul(op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[j],M->M_V[j].V[i],ins_line),ins_line);
				  if(j==0)
				  {
					  RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				  }
				  else
				  {
					  RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					  RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				  }
				  BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
				  MAT_out_bandwith[mat_num]+=SHORT_SIZE;
				}
				op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i] = fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],Rbuffer.V[i],ins_line);
				RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				Rbuffer_out_bandwith+=SHORT_SIZE;
			}
    	}
    }else if(op2.type_flag == 1)
    {
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
    	for(i=0;i<RG_SIZE;i++)
     	{
	    	op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=0;
			if(op4.opd.accumul == 0)
			{
				for(j=0;j<RG_SIZE;j++)
				{
		        	op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],fixmul(op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[j],M->M_V[j].V[i],ins_line),ins_line);
					if(j==0)
					{
						RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					}
					else
					{
						RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
						RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					}
					RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
					MAT_out_bandwith[mat_num]+=SHORT_SIZE;
				}
			}
			else
			{
				for(j=0;j<RG_SIZE;j++)
				{
					op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],fixmul(op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[j],M->M_V[j].V[i],ins_line),ins_line);
					if(j==0)
					{
						RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					}
					else
					{
						RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
						RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					}
					RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
					MAT_out_bandwith[mat_num]+=SHORT_SIZE;
				}
				op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i] = fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],Rbuffer.V[i],ins_line);
				RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				Rbuffer_out_bandwith+=SHORT_SIZE;
			}
	     }
   	}else
   	{
	   	print_error_ex("prodvm ָ\C1\EE\B5\C4Դ\B2\D9\D7\F7\CA\FD\B2\D9\D7\F7\CA\FD\C0\E0\D0Ͳ\BBƥ\C5\E4!");
		return 0;
	}
	if (allF || perfD)
	{
		creat_node_rs_num(&RV_dreuse[op1.opd.type_RV.rg_num]);
		st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
	}
	return 1;
}

bool prodvmp(INS_OPD op1,G_M* M,INS_OPD op3,int mat_num,int clk,int ins_line)
{
	int i,j;
	VM_num_mul++;

	if(op3.opd.accumul == 1)
	{
		VV_num_add++;

		add_node_rs_clk(&Rbuffer_dreuse,clk-st_dr.rbuffer_clk);
		st_dr.rbuffer_clk=clk;
	}
	if (allF || perfD)
	{
		creat_node_rs_num(&Rbuffer_dreuse);
		st_dr.rbuffer_clk = clk;
		add_node_rs_clk(&MAT_dreuse[mat_num], clk - st_dr.mat_clk[mat_num]);
		st_dr.mat_clk[mat_num] = clk;
	}

	if(op1.type_flag==0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			if(op3.opd.accumul == 0)
			{
				Rbuffer.V[i] = 0;
			}
			for(j=0;j<RG_SIZE;j++)
			{
				Rbuffer.V[i]=fixadd(Rbuffer.V[i],fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[j],M->M_V[j].V[i],ins_line),ins_line);
				if((op3.opd.accumul == 1)&&(j==0))
				{
					Rbuffer_in_bandwith+=SHORT_SIZE;
					Rbuffer_out_bandwith+=SHORT_SIZE;
				}
				else if((op3.opd.accumul == 0)&&(j==0))
				{
					Rbuffer_in_bandwith+=SHORT_SIZE;
				}
				else
				{
					Rbuffer_in_bandwith+=SHORT_SIZE;
					Rbuffer_out_bandwith+=SHORT_SIZE;
				}
				BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
				MAT_out_bandwith[mat_num]+=SHORT_SIZE;
			}
		}
	}
	else if(op1.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			if(op3.opd.accumul == 0)
			{
				Rbuffer.V[i] = 0;
			}
			for(j=0;j<RG_SIZE;j++)
			{
				Rbuffer.V[i]=fixadd(Rbuffer.V[i],fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[j],M->M_V[j].V[i],ins_line),ins_line);
				if((op3.opd.accumul == 1)&&(j==0))
				{
					Rbuffer_in_bandwith+=SHORT_SIZE;
					Rbuffer_out_bandwith+=SHORT_SIZE;
				}
				else if((op3.opd.accumul == 0)&&(j==0))
				{
					Rbuffer_in_bandwith+=SHORT_SIZE;
				}
				else
				{
					Rbuffer_in_bandwith+=SHORT_SIZE;
					Rbuffer_out_bandwith+=SHORT_SIZE;
				}
				RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				MAT_out_bandwith[mat_num]+=SHORT_SIZE;
			}
		}
	}
	else
	{
		print_error_ex("prodvmp ָ\C1\EE\B5\C4Դ\B2\D9\D7\F7\CA\FD\B2\D9\D7\F7\CA\FD\C0\E0\D0Ͳ\BBƥ\C5\E4!");
    	return 0;
	}
	return 1;
}
		
bool prodmv(INS_OPD op1, INS_OPD op2, G_M* M,INS_OPD op4,int mat_num,int clk,int ins_line)
{
	int i,j;
	MV_num_mul++;

	if(op4.opd.accumul == 1)
	{
		MM_num_add++;
		if (allF || perfD)
		{
			add_node_rs_clk(&Cbuffer_dreuse, clk - st_dr.cbuffer_clk);
			st_dr.cbuffer_clk = clk;
		}
	}
	if (allF || perfD)
	{
		add_node_rs_clk(&MAT_dreuse[mat_num], clk - st_dr.mat_clk[mat_num]);
		st_dr.mat_clk[mat_num] = clk;
	}
	if(op2.type_flag == 0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=0;
			for(j=0;j<RG_SIZE;j++)
			{
				op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],fixmul(op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[j],M->M_V[i].V[j],ins_line),ins_line);
				if(j==0)
				{
					RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				}
				else
				{
					RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				}
				BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
				MAT_out_bandwith[mat_num]+=SHORT_SIZE;
			}
			if(op4.opd.accumul == 1)
			{
				op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],Cbuffer.V[i],ins_line);
				RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				Cbuffer_out_bandwith+=SHORT_SIZE;
			}
		}
	}else if(op2.type_flag == 1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=0;
			for(j=0;j<RG_SIZE;j++)
			{
				op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],fixmul(op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[j],M->M_V[i].V[j],ins_line),ins_line);
				if(j==0)
				{
					RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				}
				else
				{
					RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				}
				RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
				MAT_out_bandwith[mat_num]+=SHORT_SIZE;
			}
			if(op4.opd.accumul == 1)
			{
				op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],Cbuffer.V[i],ins_line);
				RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				Cbuffer_out_bandwith+=SHORT_SIZE;
			}
		}
	}else
	{
		print_error_ex("prodvm ָ\C1\EE\B5\C4Դ\B2\D9\D7\F7\CA\FD\B2\D9\D7\F7\CA\FD\C0\E0\D0Ͳ\BBƥ\C5\E4!");
		return 0;
	}
	if (allF || perfD)
	{
		creat_node_rs_num(&RV_dreuse[op1.opd.type_RV.rg_num]);
		st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
	}
	return 1;
}		

bool prodmvp(INS_OPD op1,G_M* M,INS_OPD op3,int mat_num,int clk,int ins_line)
{
	int i,j;
	MV_num_mul++;

	if(op3.opd.accumul == 1)
	{
		MM_num_add++;

		if (allF || perfD)
		{
			add_node_rs_clk(&Cbuffer_dreuse, clk - st_dr.cbuffer_clk);
			st_dr.cbuffer_clk = clk;
		}
	}
	if (allF || perfD)
	{
		creat_node_rs_num(&Cbuffer_dreuse);
		st_dr.cbuffer_clk = clk;
		add_node_rs_clk(&MAT_dreuse[mat_num], clk - st_dr.mat_clk[mat_num]);
		st_dr.mat_clk[mat_num] = clk;
	}
	
	if(op1.type_flag==0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			if(op3.opd.accumul == 0)
			{
				Cbuffer.V[i] = 0;
			}
			for(j=0;j<RG_SIZE;j++)
			{
				Cbuffer.V[i]=fixadd(Cbuffer.V[i],fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[j],M->M_V[i].V[j],ins_line),ins_line);
				if(j==0)
				{
					Cbuffer_in_bandwith+=SHORT_SIZE;
				}
				else
				{
					Cbuffer_in_bandwith+=SHORT_SIZE;
					Cbuffer_out_bandwith+=SHORT_SIZE;
				}
				BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
				MAT_out_bandwith[mat_num]+=SHORT_SIZE;
			}
		}
	}
	else if(op1.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			if(op3.opd.accumul == 0)
			{
				Cbuffer.V[i] = 0;
			}
			for(j=0;j<RG_SIZE;j++)
			{
				Cbuffer.V[i]=fixadd(Cbuffer.V[i],fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[j],M->M_V[i].V[j],ins_line),ins_line);
				if(j==0)
				{
					Cbuffer_in_bandwith+=SHORT_SIZE;
				}
				else
				{
					Cbuffer_in_bandwith+=SHORT_SIZE;
					Cbuffer_out_bandwith+=SHORT_SIZE;
				}
				RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				MAT_out_bandwith[mat_num]+=SHORT_SIZE;
			}
		}
	}
	else
	{
		print_error_ex("prodvmp ָ\C1\EE\B5\C4Դ\B2\D9\D7\F7\CA\FD\B2\D9\D7\F7\CA\FD\C0\E0\D0Ͳ\BBƥ\C5\E4!");
    	return 0;
	}
	return 1;
}

bool prodvv(G_M* M, INS_OPD op1, INS_OPD op2,INS_OPD op3,int mat_num,int clk,int ins_line)
{
	int i,j;
	VV_num_mul++;

	if (allF || perfD)
	{
		creat_node_rs_num(&MAT_dreuse[mat_num]);
		st_dr.mat_clk[mat_num] = clk;
	}
	if(op3.opd.accumul == 1)
	{
		MM_num_add++;

		if (allF || perfD)
		{
			add_node_rs_clk(&Mbuffer_dreuse, clk - st_dr.mbuffer_clk);
			st_dr.mbuffer_clk = clk;
		}
	}
	if(op1.type_flag==0 && op2.type_flag==0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			for(j=0;j<RG_SIZE;j++)
			{
				M->M_V[i].V[j]=fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i],op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[j],ins_line);
				MAT_in_bandwith[mat_num]+=SHORT_SIZE;
				BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
				BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
				if(op3.opd.accumul == 1)
				{
					M->M_V[i].V[j]=fixadd(M->M_V[i].V[j],Mbuffer.V[i][j],ins_line);
					MAT_in_bandwith[mat_num]+=SHORT_SIZE;
					MAT_out_bandwith[mat_num]+=SHORT_SIZE;
					Mbuffer_out_bandwith+=SHORT_SIZE;
				}
			}
		}
		return 1;
	}else if(op1.type_flag==0 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			for(j=0;j<RG_SIZE;j++)
			{
				M->M_V[i].V[j]=fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i],op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[j],ins_line);
				MAT_in_bandwith[mat_num]+=SHORT_SIZE;
				BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
				RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
				if(op3.opd.accumul==1)
				{
		    		M->M_V[i].V[j]=fixadd(M->M_V[i].V[j],Mbuffer.V[i][j],ins_line);
					MAT_in_bandwith[mat_num]+=SHORT_SIZE;
					MAT_out_bandwith[mat_num]+=SHORT_SIZE;
					Mbuffer_out_bandwith+=SHORT_SIZE;
				}
			}
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==0)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			for(j=0;j<RG_SIZE;j++)
			{
				M->M_V[i].V[j]=fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[j],ins_line);
				MAT_in_bandwith[mat_num]+=SHORT_SIZE;
				BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
				RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				if(op3.opd.accumul==1)
				{
					M->M_V[i].V[j]=fixadd(M->M_V[i].V[j],Mbuffer.V[i][j],ins_line);
					MAT_in_bandwith[mat_num]+=SHORT_SIZE;
					MAT_out_bandwith[mat_num]+=SHORT_SIZE;
					Mbuffer_out_bandwith+=SHORT_SIZE;
				}
			}
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			for(j=0;j<RG_SIZE;j++)
			{
				M->M_V[i].V[j]=fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[j],ins_line);
				MAT_in_bandwith[mat_num]+=SHORT_SIZE;
				RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
				RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
				if(op3.opd.accumul==1)
				{
					M->M_V[i].V[j]=fixadd(M->M_V[i].V[j],Mbuffer.V[i][j],ins_line);
					MAT_in_bandwith[mat_num]+=SHORT_SIZE;
					MAT_out_bandwith[mat_num]+=SHORT_SIZE;
					Mbuffer_out_bandwith+=SHORT_SIZE;
				}
			}
		}
		return 1;
	}else
	{
		print_error_ex("prodvv ָ\C1\EE\B2\D9\D7\F7\CA\FD\C0\E0\D0Ͳ\BBƥ\C5\E4!");
		return 0;
	}
}	

bool prodvvp(INS_OPD op1,INS_OPD op2,INS_OPD op3,int clk,int ins_line)
{
	int i,j;
	VV_num_mul++;

	if(op3.opd.accumul == 1)
	{
		MM_num_add++;

		if (allF || perfD)
		{
			add_node_rs_clk(&Mbuffer_dreuse, clk - st_dr.mbuffer_clk);
			st_dr.mbuffer_clk = clk;
		}
	}
	if (allF || perfD)
	{
		creat_node_rs_num(&Mbuffer_dreuse);
		st_dr.mbuffer_clk = clk;
	}
	if(op1.type_flag==0 && op2.type_flag==0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			for(j=0;j<RG_SIZE;j++)
			{
				if(op3.opd.accumul == 0)
				{
					Mbuffer.V[i][j]=fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i],op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[j],ins_line);
					Mbuffer_in_bandwith+=SHORT_SIZE;
					BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
					BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
				else
				{
					Mbuffer.V[i][j]=fixadd(Mbuffer.V[i][j],fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i],op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[j],ins_line),ins_line);
					Mbuffer_in_bandwith+=SHORT_SIZE;
					Mbuffer_out_bandwith+=SHORT_SIZE;
					BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
					BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
			}
		}
		return 1;
	}else if(op1.type_flag==0 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			for(j=0;j<RG_SIZE;j++)
			{
				if(op3.opd.accumul==0)
				{
					Mbuffer.V[i][j]=fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i],op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[j],ins_line);
					Mbuffer_in_bandwith+=SHORT_SIZE;
					BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
					RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
				}
				else
				{
					Mbuffer.V[i][j]=fixadd(Mbuffer.V[i][j],fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i],op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[j],ins_line),ins_line);
					Mbuffer_in_bandwith+=SHORT_SIZE;
					Mbuffer_out_bandwith+=SHORT_SIZE;
					BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
					RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
				}
			}
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==0)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			for(j=0;j<RG_SIZE;j++)
			{
				if(op3.opd.accumul==0)
				{
					Mbuffer.V[i][j]=fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[j],ins_line);
					Mbuffer_in_bandwith+=SHORT_SIZE;
					RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
				else
				{
					Mbuffer.V[i][j]=fixadd(Mbuffer.V[i][j],fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[j],ins_line),ins_line);
					Mbuffer_in_bandwith+=SHORT_SIZE;
					Mbuffer_out_bandwith+=SHORT_SIZE;
					RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
				}
			}
		}
		return 1;
	}else if(op1.type_flag==1 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			for(j=0;j<RG_SIZE;j++)
			{
				if(op3.opd.accumul==0)
				{
					Mbuffer.V[i][j]=fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[j],ins_line);
					Mbuffer_in_bandwith+=SHORT_SIZE;
					RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
				}
				else
				{
					Mbuffer.V[i][j]=fixadd(Mbuffer.V[i][j],fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[j],ins_line),ins_line);
					Mbuffer_in_bandwith+=SHORT_SIZE;
					Mbuffer_out_bandwith+=SHORT_SIZE;
					RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
					RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
			
				}
			}
		}
		return 1;
	}else
	{
		print_error_ex("prodvvp ָ\C1\EE\B2\D9\D7\F7\CA\FD\C0\E0\D0Ͳ\BBƥ\C5\E4!");
		return 0;
	}
	return 1;
}

bool prodvvd(INS_OPD op3, INS_OPD op1, INS_OPD op2,int clk,int ins_line)
{
	int i;
	VV_num_mul++;

	if(op1.type_flag==0 && op2.type_flag==0)
	{
		for(i=0;i<RG_SIZE;i++)
		{
			op3.opd.type_RV.pRV->R_V[op3.opd.type_RV.rg_num].V[i]=fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i],op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[i],ins_line);
			RV_in_bandwith[op3.opd.type_RV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
		}
	}else if(op1.type_flag==0 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			op3.opd.type_RV.pRV->R_V[op3.opd.type_RV.rg_num].V[i]=fixmul(op1.opd.type_BV.pBV->R_V[op1.opd.type_BV.rg_num].V[i],op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i],ins_line);
			RV_in_bandwith[op3.opd.type_RV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op1.opd.type_BV.rg_num]+=SHORT_SIZE;
			RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
	}else if(op1.type_flag==1 && op2.type_flag==0)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			op3.opd.type_RV.pRV->R_V[op3.opd.type_RV.rg_num].V[i]=fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],op2.opd.type_BV.pBV->R_V[op2.opd.type_BV.rg_num].V[i],ins_line);
			RV_in_bandwith[op3.opd.type_RV.rg_num]+=SHORT_SIZE;
			BV_out_bandwith[op2.opd.type_BV.rg_num]+=SHORT_SIZE;
			RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
	}else if(op1.type_flag==1 && op2.type_flag==1)
	{
		if (allF || perfD)
		{
			add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
			st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
			add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
			st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		}
		for(i=0;i<RG_SIZE;i++)
		{
			op3.opd.type_RV.pRV->R_V[op3.opd.type_RV.rg_num].V[i]=fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i],ins_line);
			RV_in_bandwith[op3.opd.type_RV.rg_num]+=SHORT_SIZE;
			RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
			RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
		}
	}else
	{
		print_error_ex("prodvvd ָ\C1\EE\B2\D9\D7\F7\CA\FD\C0\E0\D0Ͳ\BBƥ\C5\E4!");
		return 0;
	}
	if (allF || perfD)
	{
		creat_node_rs_num(&RV_dreuse[op3.opd.type_RV.rg_num]);
		st_dr.rv_clk[op3.opd.type_RV.rg_num] = clk;
	}
	return 1;
	//for(i=0;i<16;i++)
	//		M[i]=fixmul(V1[i],V2[i]);
			//M[i]=V1[i]*V2[i];
	//return 1;
}		
		
bool addv(INS_OPD op3, INS_OPD op1, INS_OPD op2,int clk,int ins_line)
{
	int i;
	VV_num_add++;

	if (allF || perfD)
	{
		add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
		st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
		st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		creat_node_rs_num(&RV_dreuse[op3.opd.type_RV.rg_num]);
		st_dr.rv_clk[op3.opd.type_RV.rg_num] = clk;
	}
	for(i=0;i<RG_SIZE;i++)
	{
		op3.opd.type_RV.pRV->R_V[op3.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i],ins_line);
		RV_in_bandwith[op3.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
	}
	//for(i=0;i<16;i++)
		//V1[i]=fixadd(V2[i],V3[i]);
			//M[i]=V1[i]*V2[i];
	return 1;
}		

bool addm(G_M* M3,G_M* M1,G_M* M2,int mat_num1,int mat_num2,int mat_num3,int clk,int ins_line)
{
	int i,j;
	MM_num_add++;

	if (allF || perfD)
	{
		add_node_rs_clk(&MAT_dreuse[mat_num2], clk - st_dr.mat_clk[mat_num2]);
		st_dr.mat_clk[mat_num2] = clk;
		add_node_rs_clk(&MAT_dreuse[mat_num3], clk - st_dr.mat_clk[mat_num3]);
		st_dr.mat_clk[mat_num3] = clk;
		creat_node_rs_num(&MAT_dreuse[mat_num1]);
		st_dr.mat_clk[mat_num1] = clk;
	}
	for(i=0;i<V_NUM;i++)
	{
		for(j=0;j<V_SIZE;j++)
		{
			M3->M_V[i].V[j]=fixadd(M1->M_V[i].V[j],M2->M_V[i].V[j],ins_line);
			MAT_in_bandwith[mat_num1]+=SHORT_SIZE;
			MAT_in_bandwith[mat_num2]+=SHORT_SIZE;
			MAT_in_bandwith[mat_num3]+=SHORT_SIZE;
		}
	}
	return 1;
}

bool subv(INS_OPD op3,INS_OPD op1,INS_OPD op2,int clk,int ins_line)
{
	int i;
	VV_num_add++;

	if (allF || perfD)
	{
		add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
		st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
		st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		creat_node_rs_num(&RV_dreuse[op3.opd.type_RV.rg_num]);
		st_dr.rv_clk[op3.opd.type_RV.rg_num] = clk;
	}
	for(i=0;i<RG_SIZE;i++)
	{
		op3.opd.type_RV.pRV->R_V[op3.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],-op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i],ins_line);
		RV_in_bandwith[op3.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
	}
	//for(i=0;i<16;i++)
		//V1[i]=fixadd(V2[i],V3[i]);
			//M[i]=V1[i]*V2[i];
	return 1;
}

bool subm(G_M* M3,G_M* M1,G_M* M2,int mat_num1,int mat_num2,int mat_num3,int clk,int ins_line)
{
	int i,j;
	MM_num_add++;

	if (allF || perfD)
	{
		add_node_rs_clk(&MAT_dreuse[mat_num2], clk - st_dr.mat_clk[mat_num2]);
		st_dr.mat_clk[mat_num2] = clk;
		add_node_rs_clk(&MAT_dreuse[mat_num3], clk - st_dr.mat_clk[mat_num3]);
		st_dr.mat_clk[mat_num3] = clk;
		creat_node_rs_num(&MAT_dreuse[mat_num1]);
		st_dr.mat_clk[mat_num1] = clk;
	}
	for(i=0;i<V_NUM;i++)
	{
		for(j=0;j<V_SIZE;j++)
		{
			M3->M_V[i].V[j]=fixadd(M1->M_V[i].V[j],-M2->M_V[i].V[j],ins_line);
			MAT_in_bandwith[mat_num1]+=SHORT_SIZE;
			MAT_in_bandwith[mat_num2]+=SHORT_SIZE;
			MAT_in_bandwith[mat_num3]+=SHORT_SIZE;
		}
	}
	return 1;
}

bool scale(INS_OPD op2,INS_OPD op1,short scale_factor,int clk,int ins_line)
{
	int i;
	IV_num_mul++;

	if (allF || perfD)
	{
		add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
		st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		creat_node_rs_num(&RV_dreuse[op2.opd.type_RV.rg_num]);
		st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
	}
	for(i=0;i<RG_SIZE;i++)
	{
		op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i]=fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],scale_factor,ins_line);
		RV_in_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
	}
	return 1;
}

bool diff(INS_OPD op2,INS_OPD op1,int clk,int ins_line)
{
	int i;
	IV_num_add++;
	VV_num_mul++;

	if (allF || perfD)
	{
		add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
		st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		creat_node_rs_num(&RV_dreuse[op2.opd.type_RV.rg_num]);
		st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
	}
	for(i=0;i<RG_SIZE;i++)
	{
		op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i]=fixmul(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],fixadd(1024,-op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],ins_line),ins_line);
		RV_in_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
	}
	return 1;
}

bool randgen(INS_OPD op,int clk)
{
	int i;
	srand((int)time(NULL));
	for(i=0;i<RG_SIZE;i++)
	{
		op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]=32767-rand()%32768*2;
		RV_in_bandwith[op.opd.type_RV.rg_num]+=SHORT_SIZE;
	}
	return 1;
}

bool sum(INS_OPD op,G_M* M,int clk)
{
	int i,j;
	for(i=0;i<V_NUM;i++)
	{
		op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]=0;
		for(j=0;j<V_SIZE;j++)
			op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]=op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]+M->M_V[i].V[j];
	}
	return 1;
}

bool max(INS_OPD op1,INS_OPD op2,INS_OPD op3,int clk)
{
	int i;
	/*short max=SHRT_MIN;
	for(i=0;i<V_NUM;i++)
	{  
		for(j=0;j<V_SIZE-1;j++)
		{
			if(M->M_V[i].V[j]>max)
				max=M->M_V[i].V[j];
		}
		op.opd.type_RV.pRV->R_V[op.opd.type_RV.rg_num].V[i]=max;
	}*/ //for 1.3.6
	if (allF || perfD)
	{
		add_node_rs_clk(&RV_dreuse[op3.opd.type_RV.rg_num], clk - st_dr.rv_clk[op3.opd.type_RV.rg_num]);
		st_dr.rv_clk[op3.opd.type_RV.rg_num] = clk;
		add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
		st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		creat_node_rs_num(&RV_dreuse[op1.opd.type_RV.rg_num]);
		st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
	}
	for(i=0;i<RG_SIZE;i++)
	{
		int tmp=op2.opd.type_RV.rg_num;
		tmp=op3.opd.type_RV.rg_num;
		int tmp1 = op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
		tmp1=op3.opd.type_RV.pRV->R_V[op3.opd.type_RV.rg_num].V[i];
		RV_in_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op3.opd.type_RV.rg_num]+=SHORT_SIZE;
		if((op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i])>(op3.opd.type_RV.pRV->R_V[op3.opd.type_RV.rg_num].V[i]))
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i];
		}
		else
		{
			op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i]=op3.opd.type_RV.pRV->R_V[op3.opd.type_RV.rg_num].V[i];
		}
	}
	return 1;
}

bool probcmp(INS_OPD op3,INS_OPD op2,INS_OPD op1,int clk)
{
	int i;
	VV_num_add++;

	if (allF || perfD)
	{
		add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
		st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		add_node_rs_clk(&RV_dreuse[op2.opd.type_RV.rg_num], clk - st_dr.rv_clk[op2.opd.type_RV.rg_num]);
		st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
		creat_node_rs_num(&RV_dreuse[op3.opd.type_RV.rg_num]);
		st_dr.rv_clk[op3.opd.type_RV.rg_num] = clk;
	}
	for(i=0;i<RG_SIZE;i++)
	{
		RV_in_bandwith[op3.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
		if(op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i]>op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i])
		{
			op3.opd.type_BV.pBV->R_V[op3.opd.type_BV.rg_num].V[i]=1;
		}
		else
		{
			op3.opd.type_BV.pBV->R_V[op3.opd.type_BV.rg_num].V[i]=0;
		}
	}
	return 1;
}

bool bias(INS_OPD op2,INS_OPD op1,short bias,int clk,int ins_line)
{
	int i;
	IV_num_mul++;

	if (allF || perfD)
	{
		add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num], clk - st_dr.rv_clk[op1.opd.type_RV.rg_num]);
		st_dr.rv_clk[op1.opd.type_RV.rg_num] = clk;
		creat_node_rs_num(&RV_dreuse[op2.opd.type_RV.rg_num]);
		st_dr.rv_clk[op2.opd.type_RV.rg_num] = clk;
	}
	for(i=0;i<RG_SIZE;i++)
	{
		op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i]=fixadd(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],bias,ins_line);
		RV_in_bandwith[op2.opd.type_RV.rg_num]+=SHORT_SIZE;
		RV_out_bandwith[op1.opd.type_RV.rg_num]+=SHORT_SIZE;
	}
	return 1;
}

bool act(INS_OPD op2,INS_OPD op1,short act_type,int clk,int ins_line)
{
	int i;
	exp_num++;
	if (allF || perfD)
	{
		add_node_rs_clk(&RV_dreuse[op1.opd.type_RV.rg_num],clk-st_dr.rv_clk[op1.opd.type_RV.rg_num]);
    	st_dr.rv_clk[op1.opd.type_RV.rg_num]=clk;
    	creat_node_rs_num(&RV_dreuse[op2.opd.type_RV.rg_num]);
    	st_dr.rv_clk[op2.opd.type_RV.rg_num]=clk;
	}
	for(i=0;i<RG_SIZE;i++)
	{
		if(act_type == 0)
		{
			op2.opd.type_RV.pRV->R_V[op2.opd.type_RV.rg_num].V[i] = fixactexp(op1.opd.type_RV.pRV->R_V[op1.opd.type_RV.rg_num].V[i],ins_line);
			RV_in_bandwith[op2.opd.type_RV.rg_num] += SHORT_SIZE;
			RV_out_bandwith[op1.opd.type_RV.rg_num] += SHORT_SIZE;
		}
	}
	return 1;
}
