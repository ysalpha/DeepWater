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
 * configuration
 *
 * Configuration of the entire project
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "configuration.h"

#ifndef _MSC_VER

inline
char* strtok_s(char* s, const char* delm, char** context)
{
        return strtok_r(s, delm, context);
}
inline
int fopen_s(FILE** fp,const char* filename,const char* mode)
{
       *fp = fopen(filename,mode);
       if(fp == NULL)
           return 1;
       return 0;
}
typedef int errno_t;
#endif

/* option configuration */
bool stdebug_fl=OP_NVALID;  //mark single-step operation
bool report_fl=DEBUG_REPORT; //0 shows to not print the state of execution
bool print_br_data=DEFAULT_PBRD; // 0 shows to not print the register 、 mat and buffer data
bool stdebug_ck=DEFAULT_DEBUG; //0 shows to debug
bool print_rv_mat_data=0; // 0 show to not print
bool development_model=1; //1 show to in development mode

long delay_times=255;
bool allow_delay=0;
long delay_insAddr=1;
bool isDelay=0;

/* pipeline kernel */

/* mark is decode delay cycle */
bool isDecodeDelay=0;
/* temporary storage delay decode cycle numbers */
long decodeDelayCycle=0;
/* mark whether to convert data to binary */
bool isToRTL=0;

/* memory increase size */
long MM_add_start,MM_add_end;

/* [regs] */
/* #register entry size */
int RG_SIZE=16;
/* #RV register number */
int RG_NUM=16;
/* #BV register number */
int BV_NUM=4;
/* #RDV register number */
int RDV_NUM=4;
/* #EXTV register number */
int EXTV_NUM=8;
/* #MAT structure entry size */
int V_SIZE=16;
/* #MAT structure number */
int V_NUM=16;
/* #NAT structure layer number */
int M_LAYER=8;


/* [memory]
#initial memory size */
int INIT_MEM_SIZE=8192;

/* [ins] */
char SLOAD[20]="load";
int LOAD_CYCLE=3;
int loadWordConsumed=2;

char SSTORE[20]="store";
int STORE_CYCLE=2;
int storeWordConsumed=2;

char SLAUNCH[20]="launch";
int LAUNCH_CYCLE=3;
int launchWordConsumed=2;

char SWB[20]="wb";
int WB_CYCLE=2;
int wbWordConsumed=2;

char SMOV[20]="mov";
int MOV_CYCLE=2;
int movWordConsumed=1;

char SEXTMOV[20]="extmov";
int EXTMOV_CYCLE=2;
int extmovWordConsumed=1;

char SDMALR[20]="dmalr";
int DMALR_CYCLE=256;
int dmalrWordConsumed=3;

char SDMALC[20]="dmalc";
int DMALC_CYCLE=256;
int dmalcWordConsumed=3;

char SDMASR[20]="dmasr";
int DMASR_CYCLE=256;
int dmasrWordConsumed=3;

char SDMASC[20]="dmasc";
int DMASC_CYCLE=256;
int dmascWordConsumed=3;

char SPRODVM[20]="prodvm";
int PRODVM_CYCLE=5;
int prodvmWordConsumed=1;

char SPRODVMP[20]="prodvmp";
int PRODVMP_CYCLE=5;
int prodvmpWordConsumed=1;

char SPRODMV[20]="prodmv";
int PRODMV_CYCLE=5;
int prodmvWordConsumed=1;

char SPRODMVP[20]="prodmvp";
int PRODMVP_CYCLE=5;
int prodmvpWordConsumed=1;

char SPRODVV[20]="prodvv";
int PRODVV_CYCLE=5;
int prodvvWordConsumed=1;

char SPRODVVP[20]="prodvvp";
int PRODVVP_CYCLE=5;
int prodvvpWordConsumed=1;

char SPRODVVD[20]="prodvvd";
int PRODVVD_CYCLE=5;
int prodvvdWordConsumed=1;

char SADDV[20]="addv";
int ADDV_CYCLE=5;
int addvWordConsumed=1;

char SSUBV[20]="subv";
int SUBV_CYCLE=5;
int subvWordConsumed=1;

char SSUBM[20]="subm";
int SUBM_CYCLE=5;
int submWordConsumed=1;

char SSUM[20]="sum";
int SUM_CYCLE=5;
int SUM_CYCLE_FUNC=1;
int sumWordConsumed=1;

char SMAX[20]="max";
int MAX_CYCLE=5;
int MAX_CYCLE_FUNC=1;
int maxWordConsumed=1;

char SSCALE[20]="scale";
int SCALE_CYCLE=5;
int SCALE_CYCLE_FUNC=1;
int scaleWordConsumed=1;

char SADDM[20]="addm";
int ADDM_CYCLE=5;
int ADDM_CYCLE_FUNC=1;
int addmWordConsumed=1;

char SDIFF[20]="diff";
int DIFF_CYCLE=5;
int DIFF_CYCLE_FUNC=1;
int diffWordConsumed=1;

char SRANDGEN[20]="randgen";
int RANDGEN_CYCLE=2;
int randgenWordConsumed=1;

char SPROBCMP[20]="probcmp";
int PROBCMP_CYCLE=5;
int PROBCMP_CYCLE_FUNC=1;
int probcmpWordConsumed=1;

char SBIAS[20]="bias";
int BIAS_CYCLE=5;
int BIAS_CYCLE_FUNC=1;
int biasWordConsumed=1;

char SACT[20]="act";
int ACT_CYCLE=5;
int ACT_CYCLE_FUNC=1;
int actWordConsumed=1;

char SLOOP[20]="loop";
int loopWordConsumed=1;

char SENDLOOP[20]="endloop";
int endloopWordConsumed=1;

/* [pipeline] */
int fetch_num=10;
int RTL_A_WORD=5;

/*[localBuffer]*/
int MEM_BUFF_ENTRY_SIZE=1024;
int MEM_BUFF_BANK_SIZE=256;

/* [pulsesim mode] */
short ps_mode = 1;
short qGetD = 0;
short rtlD = 0;
short perfD = 0;
short allF = 0;
short dugD = 0;

enum confLabel{confRegsV=1,confMemoryV,confInsV,confPipelineV,confLocalBufferV,confPSMode};

void normString(char *confNS)
{
	int s_len,tempL,bs_count = 0,i;
	s_len = strlen(confNS);
	if(confNS[s_len-1] == 10 || confNS[s_len-1] == 32) /* remove the newline character and blank space */
	{
		confNS[s_len-1] = '\0';
	}
	s_len = strlen(confNS);
	tempL = s_len-1;
	while(confNS[tempL] == 32) /* remove blank space in the end of string */
	{
		confNS[tempL--] = '\0';
	}
	s_len = strlen(confNS);
	tempL = 0;
	while(confNS[tempL] == 32) /* count the number of blank space in the start of string */
	{
		++bs_count;
		++tempL;
	}
	/* move the string to cover the blank space */
	for(i=0;i<s_len-bs_count;i++)
	{
		confNS[i] = confNS[i+bs_count];
	}
	for(;i<s_len;i++)
	{
		confNS[i] = '\0';
	}
}

int getConfLabel(char *confStr)
{
	if(strstr(confStr,"regs") != NULL)
	{
		return confRegsV;
	}
	else if(strstr(confStr,"memory") != NULL)
	{
		return confMemoryV;
	}
	else if(strstr(confStr,"ins") != NULL)
	{
		return confInsV;
	}
	else if(strstr(confStr,"pipeline") != NULL)
	{
		return confPipelineV;
	}
	else if(strstr(confStr,"localBuffer") != NULL)
	{
		return confLocalBufferV;
	}
	else if (strstr(confStr, "psMode") != NULL)
	{
		return confPSMode;
	}
	else
	{
		printf("no excepted string ! ---- %s \n",confStr);
		return 0;
	}
}

void confRegs(FILE **fp_conf)
{
	while(!feof(*fp_conf))
	{
		char buf[500];
		fgets(buf,500,*fp_conf);
		normString(buf);
		if(!strcmp(buf,"") || (buf[0]=='#') || (buf[0] == 10))
		{
			continue;
		}
		else if(strstr(buf,"=") != NULL)
		{
			char *p,*p_strtok;
			p = strtok_s(buf,"=",&p_strtok);
			if(strcmp(p,"RG_SIZE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					RG_SIZE = atoi(p);
				}
			}
			else if(strcmp(p,"RG_NUM") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					RG_NUM = atoi(p);
		    	}
			}
			else if(strcmp(p,"BV_NUM") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					BV_NUM = atoi(p);
				}
			}
			else if(strcmp(p,"RDV_NUM") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					RDV_NUM = atoi(p);
				}
			}
			else if(strcmp(p,"EXTV_NUM") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					EXTV_NUM = atoi(p);
				}
			}
			else if(strcmp(p,"V_SIZE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					V_SIZE = atoi(p);
				}
			}
			else if(strcmp(p,"V_NUM") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					V_NUM = atoi(p);
				}
			}
			else if(strcmp(p,"M_LAYER") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					M_LAYER = atoi(p);
				}
			}
			else
			{
				printf("no excepted string ! -- %s\n",p);
			}
		}
		else
		{
			matchConfLabel(fp_conf,1,buf);
		}
	}
}

void confMEM(FILE **fp_conf)
{
	while(!feof(*fp_conf))
	{
		char buf[500];
		fgets(buf,500,*fp_conf);
		normString(buf);
		if(!strcmp(buf,"") || (buf[0]=='#') || (buf[0] == 10))
		{
			continue;
		}
		else if(strstr(buf,"=") != NULL)
		{
			char *p,*p_strtok;
			p = strtok_s(buf,"=",&p_strtok);
			if(strcmp(p,"INIT_MEM_SIZE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					INIT_MEM_SIZE = atoi(p);
				}
			}
			else
			{
				printf("no excepted string ! -- %s\n",p);
			}
		}
		else
		{
			matchConfLabel(fp_conf,1,buf);
		}
	}
}

void confPL(FILE **fp_conf)
{
	while(!feof(*fp_conf))
	{
		char buf[500];
		fgets(buf,500,*fp_conf);
		normString(buf);
		if(!strcmp(buf,"") || (buf[0]=='#') || (buf[0] == 10))
		{
			continue;
		}
		else if(strstr(buf,"=") != NULL)
		{
			char *p,*p_strtok;
			p = strtok_s(buf,"=",&p_strtok);
			if(strcmp(p,"fetch_num") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					fetch_num = atoi(p);
				}
			}
			else if(strcmp(p,"RTL_A_WORD") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					RTL_A_WORD = atoi(p);
				}
			}
			else
			{
				printf("no excepted string ! -- %s\n",p);
			}
		}
		else
		{
			matchConfLabel(fp_conf,1,buf);
		}
	}
}

void confLBUF(FILE **fp_conf)
{
	while(!feof(*fp_conf))
	{
		char buf[500];
		fgets(buf,500,*fp_conf);
		normString(buf);
		if(!strcmp(buf,"") || (buf[0]=='#') || (buf[0] == 10))
		{
			continue;
		}
		else if(strstr(buf,"=") != NULL)
		{
			char *p,*p_strtok;
			p = strtok_s(buf,"=",&p_strtok);
			if(strcmp(p,"MEM_BUFF_ENTRY_SIZE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					MEM_BUFF_ENTRY_SIZE = atoi(p);
				}
			}
			else if(strcmp(p,"MEM_BUFF_BANK_SIZE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					MEM_BUFF_BANK_SIZE = atoi(p);
				}
			}
			else
			{
				printf("no excepted string ! -- %s\n",p);
			}
		}
		else
		{
			matchConfLabel(fp_conf,1,buf);
		}
	}
}

void confINS(FILE **fp_conf)
{
	while(!feof(*fp_conf))
	{
		char buf[500];
		fgets(buf,500,*fp_conf);
		normString(buf);
		if(!strcmp(buf,"") || (buf[0]=='#') || (buf[0] == 10))
		{
			continue;
		}
		else if(strstr(buf,"=") != NULL)
		{
			char *p,*p_strtok;
			p = strtok_s(buf,"=",&p_strtok);
			normString(p);
			if(strcmp(p,"SLOAD") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SLOAD,p);
				}
			}
			else if(strcmp(p,"LOAD_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					LOAD_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"loadWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					loadWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SSTORE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SSTORE,p);
				}
			}
			else if(strcmp(p,"STORE_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					STORE_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"storeWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					storeWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SLAUNCH") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SLAUNCH,p);
				}
			}
			else if(strcmp(p,"LAUNCH_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					LAUNCH_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"launchWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					launchWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SWB") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SWB,p);
				}
			}
			else if(strcmp(p,"WB_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					WB_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"wbWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					wbWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SMOV") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SMOV,p);
				}
			}
			else if(strcmp(p,"MOV_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					MOV_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"movWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					movWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SEXTMOV") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SEXTMOV,p);
				}
			}
			else if(strcmp(p,"EXTMOV_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					EXTMOV_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"extmovWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					extmovWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SDMALR") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SDMALR,p);
				}
			}
			else if(strcmp(p,"DMALR_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					DMALR_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"dmalrWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					dmalrWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SDMALC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SDMALC,p);
				}
			}
			else if(strcmp(p,"DMALC_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					DMALC_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"dmalcWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					dmalcWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SDMASR") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SDMASR,p);
				}
			}
			else if(strcmp(p,"DMASR_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					DMASR_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"dmasrWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					dmasrWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SDMASC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SDMASC,p);
				}
			}
			else if(strcmp(p,"DMASC_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					DMASC_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"dmascWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					dmascWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SPRODVM") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SPRODVM,p);
				}
			}
			else if(strcmp(p,"PRODVM_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					PRODVM_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"prodvmWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					prodvmWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SPRODVMP") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SPRODVMP,p);
				}
			}
			else if(strcmp(p,"PRODVMP_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					PRODVMP_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"prodvmpWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					prodvmpWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SPRODMV") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SPRODMV,p);
				}
			}
			else if(strcmp(p,"prodmvWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					prodmvWordConsumed = atoi(p);
				}
			}
			else if(strcmp(p,"PRODMV_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					PRODMV_CYCLE = atoi(p);
				}
			}

			else if(strcmp(p,"SPRODMVP") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SPRODMVP,p);
				}
			}
			else if(strcmp(p,"PRODMVP_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					PRODMVP_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"prodmvpWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					prodmvpWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SPRODVV") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SPRODVV,p);
				}
			}
			else if(strcmp(p,"PRODVV_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					PRODVV_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"prodvvWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					prodvvWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SPRODVVP") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SPRODVVP,p);
				}
			}
			else if(strcmp(p,"PRODVVP_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					PRODVVP_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"prodvvpWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					prodvvpWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SPRODVVD") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SPRODVVD,p);
				}
			}
			else if(strcmp(p,"PRODVVD_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					PRODVVD_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"prodvvdWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					prodvvdWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SADDV") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SADDV,p);
				}
			}
			else if(strcmp(p,"ADDV_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					ADDV_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"addvWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					addvWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SSUBV") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SSUBV,p);
				}
			}
			else if(strcmp(p,"SUBV_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					SUBV_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"subvWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					subvWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SSUBM") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SSUBM,p);
				}
			}
			else if(strcmp(p,"SUBM_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					SUBM_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"submWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					submWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SSUM") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SSUM,p);
				}
			}
			else if(strcmp(p,"SUM_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					SUM_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"SUM_CYCLE_FUNC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					SUM_CYCLE_FUNC = atoi(p);
				}
			}
			else if(strcmp(p,"sumWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					sumWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SMAX") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SMAX,p);
				}
			}
			else if(strcmp(p,"MAX_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					MAX_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"MAX_CYCLE_FUNC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					MAX_CYCLE_FUNC = atoi(p);
				}
			}
			else if(strcmp(p,"maxWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					maxWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SSCALE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SSCALE,p);
				}
			}
			else if(strcmp(p,"SCALE_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					SCALE_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"SCALE_CYCLE_FUNC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					SCALE_CYCLE_FUNC = atoi(p);
				}
			}
			else if(strcmp(p,"scaleWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					scaleWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SADDM") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SADDM,p);
				}
			}
			else if(strcmp(p,"ADDM_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					ADDM_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"ADDM_CYCLE_FUNC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					ADDM_CYCLE_FUNC = atoi(p);
				}
			}
			else if(strcmp(p,"addmWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					addmWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SDIFF") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SDIFF,p);
				}
			}
			else if(strcmp(p,"DIFF_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					DIFF_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"DIFF_CYCLE_FUNC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					DIFF_CYCLE_FUNC = atoi(p);
				}
			}
			else if(strcmp(p,"diffWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					diffWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SRANDGEN") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SRANDGEN,p);
				}
			}
			else if(strcmp(p,"RANDGEN_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					RANDGEN_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"randgenWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					randgenWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SPROBCMP") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SPROBCMP,p);
				}
			}
			else if(strcmp(p,"PROBCMP_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					PROBCMP_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"PROBCMP_CYCLE_FUNC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					PROBCMP_CYCLE_FUNC = atoi(p);
				}
			}
			else if(strcmp(p,"probcmpWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					probcmpWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SBIAS") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SBIAS,p);
				}
			}
			else if(strcmp(p,"BIAS_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					BIAS_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"BIAS_CYCLE_FUNC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					BIAS_CYCLE_FUNC = atoi(p);
				}
			}
			else if(strcmp(p,"biasWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					biasWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SACT") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SACT,p);
				}
			}
			else if(strcmp(p,"ACT_CYCLE") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					ACT_CYCLE = atoi(p);
				}
			}
			else if(strcmp(p,"ACT_CYCLE_FUNC") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					ACT_CYCLE_FUNC = atoi(p);
				}
			}
			else if(strcmp(p,"actWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					actWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SLOOP") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SLOOP,p);
				}
			}
			else if(strcmp(p,"loopWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					loopWordConsumed = atoi(p);
				}
			}

			else if(strcmp(p,"SENDLOOP") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					normString(p);
					strcpy(SENDLOOP,p);
				}
			}
			else if(strcmp(p,"endloopWordConsumed") == 0)
			{
				if((p = strtok_s(NULL,"=",&p_strtok)) != NULL)
				{
					endloopWordConsumed = atoi(p);
				}
			}

			else
			{
				printf("no excepted string ! -- %s\n",p);
			}
		}
		else
		{
			matchConfINS(fp_conf);
		}
	}
}

void confPSModeF(FILE **fp_conf)
{
	while (!feof(*fp_conf))
	{
		char buf[500];
		fgets(buf, 500, *fp_conf);
		normString(buf);
		if (!strcmp(buf, "") || (buf[0] == '#') || (buf[0] == 10))
		{
			continue;
		}
		else if (strstr(buf, "=") != NULL)
		{
			char *p, *p_strtok;
			p = strtok_s(buf, "=", &p_strtok);
			if (strcmp(p, "ps_mode") == 0)
			{
				if ((p = strtok_s(NULL, "=", &p_strtok)) != NULL)
				{
					ps_mode = atoi(p);
					if (ps_mode == 1)
					{
						qGetD = 1;
					}
					else if (ps_mode == 2)
					{
						rtlD = 1;
					}
					else if (ps_mode == 3)
					{
						perfD = 1;
					}
					else if (ps_mode == 4)
					{
						allF = 1;
					}
					else if (ps_mode == 5)
					{
						dugD = 1;
					}
					else
					{
						printf("error value !\n");
					}
				}
			}
			else
			{
				printf("no excepted string ! -- %s\n", p);
			}
		}
		else
		{
			matchConfLabel(fp_conf, 1, buf);
		}
	}
}

void matchConfLabel(FILE **fp_conf,int repStr,char* prestr)
{
	while(!feof(*fp_conf) || repStr)
	{
		char buf[500];
		if(!repStr)
		{
			fgets(buf,500,*fp_conf);
			normString(buf);
		}
		else
		{
			strcpy(buf,prestr);
		}
		repStr = 0;
		if(!strcmp(buf,"") || (buf[0]=='#') || (buf[0] == 10))
		{
			continue;
		}
		else
		{
			switch (getConfLabel(buf))
			{
			case confRegsV:
				{
					confRegs(fp_conf);
					break;
				}
			case confMemoryV:
				{
					confMEM(fp_conf);
					break;
				}
			case confPipelineV:
				{
					confPL(fp_conf);
					break;
				}
			case confLocalBufferV:
				{
					confLBUF(fp_conf);
					break;
				}
			case confPSMode:
			{
				confPSModeF(fp_conf);
				break;
			}
			default:
				{
					printf("no excepted string ! ---- %s \n",buf);
					break;
				}
			}
		}
	}
}

void matchConfINS(FILE **fp_conf)
{
	while(!feof(*fp_conf))
	{
		char buf[500];
	
		fgets(buf,500,*fp_conf);
		normString(buf);
		if(!strcmp(buf,"") || (buf[0]=='#') || (buf[0] == 10))
		{
			continue;
		}
		else
		{
			if(strstr(buf,"ins") != NULL)
			{
				confINS(fp_conf);
			}
			else
			{
				printf("no excepted string ! ---- %s \n",buf);
				printf("Excepted string ! ---- [ins] \n");
				break;
			}
		}
	}
}

int configurePS()
{
	FILE *file_conf,*file_conf2;
	errno_t err;
	
	if((err=fopen_s(&file_conf2,"ps.conf","r")) != 0)
	{
		printf("can not creat ps.conf file .-----%s\n",strerror(err));
		exit(0);
	}
	matchConfLabel(&file_conf2,0,"");
	fclose(file_conf2);
	if((err=fopen_s(&file_conf,"ins.conf","r")) != 0)
	{
		printf("can not creat ins.conf file .-----%s\n",strerror(err));
		exit(0);
	}
	matchConfINS(&file_conf);
	fclose(file_conf);
	return 0;
}
