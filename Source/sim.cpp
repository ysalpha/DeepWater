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
 * sim
 *
 * DWsim simulator logical structure
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sim.h"
#include "configuration.h"
#include "convb.h"
#include "mctrl.h"
#include "localBufferModeling.h"
#include "ps_inst.h"
#include "printR.h"
#include "print_mat.h"
#include "print_bandwith.h"
#include "pulse_error.h"
#include "printINAddr.h"
#include "pl_kernel.h"
#include "print.h"
#include "data_reuse.h"
#include "fileVariant.h"
#include "print_ins_to_binary.h"
#include "bandwith_monitor.h"
#include "operation_type.h"
#include "reportall.h"
#include "wintolinux.h"

void sim()
{
	char sf[] = "**********************************************************************************************************************************\n";
	char end0[] = "\n***********************************************************************************************************************************\n   ----------------------------------------------------------Sim has done-------------------------------------------------------\n";
	char end1[] = "   ------------------------------------------------------  cycle number is : ";
	char end2[] = "  ---------------------------------------------   \n";
	char end3[] = "   ---------------------------------------------  ";
	char end4[] = "  -------------------------------------------   \n";
	char end5[] = "********** *************************************************************************************************************************\n";
	configurePS();    /* configure the project , all of the parameter */
	char sd;
	long clk=0;
	Initrgs();    /* initialize regs etc. */
	Init_mm();    /* initialize memory */
	Initpl();    /* initialize pl signal */
	init_pl_scratchpad();    /* initialize pl scratchpad */
	Init_buff();    /* initialize local buffer */
	long ins_n = init_inst();    /* initialize program load to memorary */
	if (allF || !qGetD)    /* fastly generate memory data */
	{
		//if (development_model || print_rv_mat_data)
		if (dugD)
		{
			/* initialize file pointer of printing regs */
			open_file_register();
			/* initialize file pointer of printing mat */
			open_file_mat();
			/* initialize file pointer of printing indirect addressing */
    		openprintAddr();
			/* initialize file pointer of error message */
    		open_err_file();
			/* initialize debug information file pointer */
    		init_dbP_file();
		}
		if (allF || rtlD)
		{
			/* initialize file pointer of saving binary */
    		init_hd_file();
		}
		if (allF || perfD)
		{
			/* initialize data reuse correlation */
			Init_Data_Reuse();
	    	/* initialize file pointer of printing bandwith */
	        open_file_bw();
		}
	}
	init_bw_sd();    /* initialize print band-with data structure */

	clock_t begin_sim,end_sim;
	begin_sim = clock();
go:
	while(true)
	{
		clk++;
		if (dugD)
		{
			myprint_report("\n--CYCLE ", clk, ":\n", NULL, sf, NULL);
		}
		printf("\nsysclk %d\n",clk);
		pl_fetch();
		pl_load();
		pl_launch();
		pl_wb();
		pl_store();
		pl_mov();
		pl_extmov();
		pl_dmalr();
		pl_dmalc();
		pl_dmasr();
		pl_dmasc();
		pl_prodvm();
		pl_prodvmp();
		pl_prodmv();
		pl_prodmvp();
		pl_prodvv();
		pl_prodvvp();
		pl_prodvvd();
		pl_addv();
		pl_addm();
		pl_subv();
		pl_subm();
		pl_max();
		pl_scale();
		pl_diff();
		pl_randgen();
		pl_probcmp();
		pl_bias();
		pl_act();
		pl_decode(&decode_i1);
		if (judend())
		{
			break;
		}
		pl_syn(clk);
		if (allF || !qGetD)
		{
			//if (development_model || print_rv_mat_data)
			/* print debug information data */
			if (dugD)
			{
				print_all_register(clk); //打印每一个时钟周期RV寄存器的值
				print_all_mat(); //打印每一个时钟周期MAT的值
			//}
			
			//if (print_br_data)
			//{
			//	myprint_BV_rp();
			//	myprint_RV_rp();
			//	myprint_RDV_rp();
			//	myprint_EXTV_rp();
			//	myprint_MAT_rp();
			//	myprint_BUFFER_rp();
			}
			/* print performance data ; bandwith information */
			if (allF || perfD)
			{
				if ((clk + 1) % SIAPLING_FREQUENCY == 0)
	    		{
    				print_procedure_bw();
    			}
			}
			
		}
		
		if (stdebug_fl==OP_VALID)
		{
			if (stdebug_ck==0)
			{
next:		
				scanf("%c",&sd);
				if((sd=='t')||(sd=='T'))
					goto go;
				else if((sd=='c')||(sd=='C'))
				{
					stdebug_fl=OP_NVALID;
					goto go;
				}
				else
					goto next;
			}
			else
				stdebug_ck=1;
		}
	}
	end_sim = clock();
	double cost_time = (double)(end_sim - begin_sim);
	if (allF || !qGetD)
	{
		//if (development_model || print_rv_mat_data)
		if (dugD)
		{
			zeroize_print_all_register(3);
			close_file_register(); // 关闭打印RV寄存器的文件指针
			zeroize_print_mat(3);
			close_file_mat(); //关闭打印MAT的文件指针
			close_err_file();//关闭打印程序错误信息的文件指针
		}
		if (allF || rtlD)
		{
			fclose(fp_saveRTLB); //关闭保存指令二进制的文件指针
			fclose(fp_Ri);  //关闭保存调整顺序指令的文件指针
		}
		if (allF || perfD)
		{
			print_all_data_rs();//打印data reuse 的相关数据
			close_file_bw(); //关闭打印抽样周期带宽的文件指针
		}
	}
	
	store_mm(con_mem_tmp,MM_add_start,INIT_MEM_SIZE);
	//rename("buf.mem",con_mem_tmp);
	if (allF || !qGetD)
	{
		if (dugD)
		{
			myprint_BV_rp();
			myprint_RV_rp();
			myprint_RDV_rp();
			myprint_EXTV_rp();
			myprint_MAT_rp();
			myprint_BUFFER_rp();
		}
		if (allF || rtlD)
		{
			print_insBinary_to_four(save_b);
		}
		if (allF || perfD)
		{
			print_bandwith(); //输出带宽
    		print_optype();
		}
		if (dugD)
		{
		    myprint_report0(end0, NULL, end1, clk - 1, end2, NULL);
		    fprintf(freport, "load_num is : %ld\n", load_num);
		    fprintf(freport, "load_wait_time is :%ld\n", load_wait_time);
		    fprintf(freport, "load_wait_time_func is :%ld\n", load_fwait_time);
		    fprintf(freport, "load_exe_time is :%ld\n", load_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "launch_num is :%ld\n", launch_num);
		    fprintf(freport, "launch_wait_time is :%ld\n", launch_wait_time);
		    fprintf(freport, "launch_wait_time_func is :%ld\n", launch_fwait_time);
		    fprintf(freport, "launch_exe_time is :%ld\n", launch_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "wb_num is :%ld\n", wb_num);
		    fprintf(freport, "wb_wait_time is :%ld\n", wb_wait_time);
		    fprintf(freport, "wb_wait_time_func is :%ld\n", wb_fwait_time);
		    fprintf(freport, "wb_exe_time is :%ld\n", wb_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "store_num is :%ld\n", store_num);
		    fprintf(freport, "store_wait_time is :%ld\n", store_wait_time);
		    fprintf(freport, "store_wait_time_func is :%ld\n", store_fwait_time);
		    fprintf(freport, "store_exe_time is :%ld\n", store_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "mov_num is :%ld\n", mov_num);
		    fprintf(freport, "mov_wait_time is :%ld\n", mov_wait_time);
		    fprintf(freport, "mov_wait_time_func is :%ld\n", mov_fwait_time);
		    fprintf(freport, "mov_exe_time is :%ld\n", mov_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "extmov_num is :%ld\n", extmov_num);
		    fprintf(freport, "extmov_wait_time is :%ld\n", extmov_wait_time);
		    fprintf(freport, "extmov_wait_time_func is :%ld\n", extmov_fwait_time);
		    fprintf(freport, "extmov_exe_time is :%ld\n", extmov_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "dmalr_num is :%ld\n", dmalr_num);
		    fprintf(freport, "dmalr_wait_time is :%ld\n", dmalr_wait_time);
		    fprintf(freport, "dmalr_wait_time_func is :%ld\n", dmalr_fwait_time);
		    fprintf(freport, "dmalr_exe_time is :%ld\n", dmalr_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "dmalc_num is :%ld\n", dmalc_num);
		    fprintf(freport, "dmalc_wait_time is :%ld\n", dmalc_wait_time);
		    fprintf(freport, "dmalc_wait_time_func is :%ld\n", dmalc_fwait_time);
		    fprintf(freport, "dmalc_exe_time is :%ld\n", dmalc_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "dmasr_num is :%ld\n", dmasr_num);
		    fprintf(freport, "dmasr_wait_time is :%ld\n", dmasr_wait_time);
		    fprintf(freport, "dmasr_wait_time_func is :%ld\n", dmasr_fwait_time);
		    fprintf(freport, "dmasr_exe_time is :%ld\n", dmasr_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "dmasc_num is :%ld\n", dmasc_num);
		    fprintf(freport, "dmasc_wait_time is :%ld\n", dmasc_wait_time);
		    fprintf(freport, "dmasc_wait_time_func is :%ld\n", dmasc_fwait_time);
		    fprintf(freport, "dmasc_exe_time is :%ld\n", dmasc_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "prodvm_num is :%ld\n", prodvm_num);
		    fprintf(freport, "prodvm_wait_time is :%ld\n", prodvm_wait_time);
		    fprintf(freport, "prodvm_wait_time_func is :%ld\n", prodvm_fwait_time);
		    fprintf(freport, "prodvm_exe_time is :%ld\n", prodvm_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "prodvmp_num is :%ld\n", prodvmp_num);
		    fprintf(freport, "prodvmp_wait_time is :%ld\n", prodvmp_wait_time);
		    fprintf(freport, "prodvmp_wait_time_func is :%ld\n", prodvmp_fwait_time);
		    fprintf(freport, "prodvmp_exe_time is :%ld\n", prodvmp_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "prodmv_num is :%ld\n", prodmv_num);
		    fprintf(freport, "prodmv_wait_time is :%ld\n", prodmv_wait_time);
		    fprintf(freport, "prodmv_wait_time_func is :%ld\n", prodmv_fwait_time);
		    fprintf(freport, "prodmvp_exe_time is :%ld\n", prodmv_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "prodmvp_num is :%ld\n", prodmvp_num);
		    fprintf(freport, "prodmvp_wait_time is :%ld\n", prodmvp_wait_time);
		    fprintf(freport, "prodmvp_wait_time_func is :%ld\n", prodmvp_fwait_time);
		    fprintf(freport, "prodmvp_exe_time is :%ld\n", prodmvp_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "prodvv_num is :%ld\n", prodvv_num);
		    fprintf(freport, "prodvv_wait_time is :%ld\n", prodvv_wait_time);
		    fprintf(freport, "prodvv_wait_time_func is :%ld\n", prodvv_fwait_time);
		    fprintf(freport, "prodvv_exe_time is :%ld\n", prodvv_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "prodvvp_num is :%ld\n", prodvvp_num);
		    fprintf(freport, "prodvvp_wait_time is :%ld\n", prodvvp_wait_time);
		    fprintf(freport, "prodvvp_wait_time_func is :%ld\n", prodvvp_fwait_time);
		    fprintf(freport, "prodvvp_exe_time is :%ld\n", prodvvp_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "prodvvd_num is :%ld\n", prodvvd_num);
		    fprintf(freport, "prodvvd_wait_time is :%ld\n", prodvvd_wait_time);
		    fprintf(freport, "prodvvd_wait_time_func is :%ld\n", prodvvd_fwait_time);
		    fprintf(freport, "prodvvd_exe_time is :%ld\n", prodvvd_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "addv_num is :%ld\n", addv_num);
		    fprintf(freport, "addv_wait_time is :%ld\n", addv_wait_time);
		    fprintf(freport, "addv_wait_time_func is :%ld\n", addv_fwait_time);
		    fprintf(freport, "addv_exe_time is :%ld\n", addv_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "addm_num is :%ld\n", addm_num);
		    fprintf(freport, "addm_wait_time is :%ld\n", addm_wait_time);
		    fprintf(freport, "addm_wait_time_func is :%ld\n", addm_fwait_time);
		    fprintf(freport, "addm_exe_time is :%ld\n", addm_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "subv_num is :%ld\n", subv_num);
		    fprintf(freport, "subv_wait_time is :%ld\n", subv_wait_time);
		    fprintf(freport, "subv_wait_time_func is :%ld\n", subv_fwait_time);
		    fprintf(freport, "subv_exe_time is :%ld\n", subv_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "subm_num is :%ld\n", subm_num);
		    fprintf(freport, "subm_wait_time is :%ld\n", subm_wait_time);
		    fprintf(freport, "subm_wait_time_func is :%ld\n", subm_fwait_time);
		    fprintf(freport, "subm_exe_time is :%ld\n", subm_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "max_num is :%ld\n", max_num);
		    fprintf(freport, "max_wait_time is :%ld\n", max_wait_time);
		    fprintf(freport, "max_wait_time_func is :%ld\n", max_fwait_time);
		    fprintf(freport, "max_exe_time is :%ld\n", max_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "diff_num is :%ld\n", diff_num);
		    fprintf(freport, "diff_wait_time is :%ld\n", diff_wait_time);
		    fprintf(freport, "diff_wait_time_func is :%ld\n", diff_fwait_time);
		    fprintf(freport, "diff_exe_time is :%ld\n", diff_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "scale_num is :%ld\n", scale_num);
		    fprintf(freport, "scale_wait_time is :%ld\n", scale_wait_time);
		    fprintf(freport, "scale_wait_time_func is :%ld\n", scale_fwait_time);
		    fprintf(freport, "scale_exe_time is :%ld\n", scale_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "randgen_num is :%ld\n", randgen_num);
		    fprintf(freport, "randgen_wait_time is :%ld\n", randgen_wait_time);
		    fprintf(freport, "randgen_wait_time_func is :%ld\n", randgen_fwait_time);
		    fprintf(freport, "randgen_exe_time is :%ld\n", randgen_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "probcmp_num is :%ld\n", probcmp_num);
		    fprintf(freport, "probcmp_wait_time is :%ld\n", probcmp_wait_time);
		    fprintf(freport, "probcmp_wait_time_func is :%ld\n", probcmp_fwait_time);
		    fprintf(freport, "probcmp_exe_time is :%ld\n", probcmp_execute_time);
		    fprintf(freport, "\n");
		    fprintf(freport, "bias_num is :%ld\n", bias_num);
		    fprintf(freport, "bias_wait_time is :%ld\n", bias_wait_time);
		    fprintf(freport, "bias_wait_time_func is :%ld\n", bias_fwait_time);
		    fprintf(freport, "bias_exe_time is :%ld\n", bias_execute_time);
		    
		    myprint_report0(end5, NULL, "", NULL, "", NULL);
		    
		    fprintf(freport, "\n\nexecution all time is : %lf seconds.\n\n", cost_time / CLK_TCK);
		    fprintf(freport, "\n\n CLK_TCK is : %ld.\n\n", CLK_TCK);
		    fclose(freport);
		    
		    closeprintAddr();
		    
		    //print_repor(clk, cost_time / CLK_TCK, ins_n, d_ins_n);
		}
		if (allF || perfD)
		{
			free_all_data_reuse();//释放data reuse的相关数据结构
		}
	}
	print_repor(clk, cost_time / CLK_TCK, ins_n, d_ins_n);

	printf("\n************ **********************************************************************************************************\n");
	printf(" ------------------------------------------------Sim has done-------------------------------------------------------\n");
	printf(" --------------------------------------------cycle number is---%6d-----------------------------------------------\n", clk - 1);
	printf(" --------------------------------------------time(s) is---%6f-----------------------------------------------\n", cost_time / CLK_TCK);
	//FILE *freport_test = fopen("test_report.txt","w+");
	//fprintf(freport_test, "\n\nexecution all time is : %lf seconds.\n\n", cost_time / CLK_TCK);
	//fclose(freport_test);
	printf("**********************************************************************************************************************\n");
}
