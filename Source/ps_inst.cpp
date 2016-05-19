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
 * ps inst
 *
 * Read instruction from file and fixed instruction format , and modeling
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ps_inst.h"
#include "op_common.h"
#include "fileVariant.h"
#include "print_error.h"
#include "ps_pipeline.h"
#include "dataTypeModeling.h"
#include "wintolinux.h"

long scanline()
{
	FILE *f0,*f1;
	char line[100]="";
	char bufline[100]="";
	long lines = 0;    /* instruction line number */
	long i,char_n;    /*empty char number*/
	bool flag;    /*empty line flag*/

	open_file(&f0,pmname,"r",
		"can not open program file in ps_inst.cpp scanline().\n");
	open_file(&f1,tempm,"w",
		"can not create tempm.mem in ps_inst.cpp scanline().\n");

nextline:

	while(fgets(line, 100, f0)!=NULL) 
	{
		flag=1;    /* Initial the empty line flag empty value */
		char_n=0;

		for(i=0;i<strlen(line);i++)
		{
			if((0xff&line[i])>0x20)
			{
				flag=0    /* there is non-empty char in this line */;
				break;
			}
			else
			{
				char_n++;
			}
		}
		if(flag==0)
		{
			if(line[char_n]=='/')    /* judge this non-empty line is a note line or not */
			{
				if(line[char_n+1]=='/')
				{
					goto nextline;
				}
				else
				{
					printf("line %d error\n",line+1);
					exit(0);
				}
			}
			else
			{
				if(line[char_n]==EOF)    /* judge this is a end line or not */
				{
					goto endline;
				}
				else
				{
					lines++;
				}
			}
			for(i=0;i<(strlen(line)-char_n);i++)
			{
				if (line[char_n+i]=='/')
				{
					if(line[char_n+i+1]=='/')
					{
						bufline[i]='\n';
						bufline[i+1]='\0';
						goto note;
					}
					else
					{

						printf("line %d error\n",lines);
						printf("%c\n",line[char_n+i+1]);
						exit(0);
					}
				}
				else
				{
					if(line[char_n+i]==EOF)
					{
						bufline[i]='\n';
						bufline[i+1]='\0';
						goto endline;
					}
					bufline[i]=line[char_n+i];
				}

			}
			bufline[i]='\0';

note:
			fprintf(f1,bufline);
		}
	}
endline:
	fclose(f0);
	fclose(f1);
	return lines;
}

bool match_BV_R(char* p,int ins_n,int op_n)
{
	if(strcmp(p,SBV1)==0)
	{
		ins[ins_n].op[op_n].opd.type_BV.pBV=BV;
		ins[ins_n].op[op_n].opd.type_BV.rg_num=0;
		ins[ins_n].op[op_n].type_flag = 0;
		return 1;
	}
	else if(strcmp(p,SBV2)==0)
	{
		ins[ins_n].op[op_n].opd.type_BV.pBV=BV;
		ins[ins_n].op[op_n].opd.type_BV.rg_num=1;
		ins[ins_n].op[op_n].type_flag = 0;
		return 1;
	}
	else if(strcmp(p,SBV3)==0)
	{
		ins[ins_n].op[op_n].opd.type_BV.pBV=BV;
		ins[ins_n].op[op_n].opd.type_BV.rg_num=2;
		ins[ins_n].op[op_n].type_flag = 0;
		return 1;
	}
	else if(strcmp(p,SBV4)==0)
	{
		ins[ins_n].op[op_n].opd.type_BV.pBV=BV;
		ins[ins_n].op[op_n].opd.type_BV.rg_num=3;
		ins[ins_n].op[op_n].type_flag = 0;
		return 1;
	}
	return 0;
}

bool match_RV_R(char* p,int ins_n,int op_n)
{
	if(strcmp(p,SRV1)==0)
	{               
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=0;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV2)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=1;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV3)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=2;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV4)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=3;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV5)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=4;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV6)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=5;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV7)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=6;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV8)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=7;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV9)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=8;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV10)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=9;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV11)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=10;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV12)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=11;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV13)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=12;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV14)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=13;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV15)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=14;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	else if(strcmp(p,SRV16)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=15;
		ins[ins_n].op[op_n].type_flag = 1;
		return 1;
	}
	return 0;
}

bool match_RDV_R(char* p,int ins_n,int op_n)
{
	if(strcmp(p,SRDV1)==0)
	{               
		ins[ins_n].op[op_n].opd.type_RV.pRV=RDV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=0;
		ins[ins_n].op[op_n].type_flag = 2;
		return 1;
	}
	else if(strcmp(p,SRDV2)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RDV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=1;
		ins[ins_n].op[op_n].type_flag = 2;
		return 1;
	}
	else if(strcmp(p,SRDV3)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RDV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=2;
		ins[ins_n].op[op_n].type_flag = 2;
		return 1;
	}
	else if(strcmp(p,SRDV4)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=RDV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=3;
		ins[ins_n].op[op_n].type_flag = 2;
		return 1;
	}
	return 0;
}

bool match_EXTV_R(char*p,int ins_n,int op_n)
{
	if(strcmp(p,SEXTV1)==0)
	{               
		ins[ins_n].op[op_n].opd.type_RV.pRV=EXTV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=0;
		ins[ins_n].op[op_n].type_flag = 7;
		return 1;
	}
	else if(strcmp(p,SEXTV2)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=EXTV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=1;
		ins[ins_n].op[op_n].type_flag = 7;
		return 1;
	}
	else if(strcmp(p,SEXTV3)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=EXTV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=2;
		ins[ins_n].op[op_n].type_flag = 7;
		return 1;
	}
	else if(strcmp(p,SEXTV4)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=EXTV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=3;
		ins[ins_n].op[op_n].type_flag = 7;
		return 1;
	}
	else if(strcmp(p,SEXTV5)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=EXTV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=4;
		ins[ins_n].op[op_n].type_flag = 7;
		return 1;
	}
	else if(strcmp(p,SEXTV6)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=EXTV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=5;
		ins[ins_n].op[op_n].type_flag = 7;
		return 1;
	}
	else if(strcmp(p,SEXTV7)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=EXTV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=6;
		ins[ins_n].op[op_n].type_flag = 7;
		return 1;
	}
	else if(strcmp(p,SEXTV8)==0)
	{
		ins[ins_n].op[op_n].opd.type_RV.pRV=EXTV;
		ins[ins_n].op[op_n].opd.type_RV.rg_num=7;
		ins[ins_n].op[op_n].type_flag = 7;
		return 1;
	}
	return 0;
}

long init_inst()
{
	/* output instruction format error */
	open_instError();
	int op_n,    /* record operands order */
		ins_n=0;    /* instructions index */
	char *d=" ";    /* split char[] */
	char *p,    /* string by splitting */
		*p_stoken;    /* string after strtok_s */
	char c[100];    /* temporary instruction */

	ins_num = scanline();
	printf("instruction number -- %d\n",ins_num);
	ins = (insStruction*)malloc(sizeof(insStruction)*ins_num);
	FILE *fp;
	sprintf(c,"%s %s.","can not open",tempm);
	open_file(&fp,tempm,"r",c);
	memset(c,0,sizeof(c));
	for(ins_n=0;ins_n<ins_num;ins_n++)
	{
		op_n = 0;
		fgets(c,100,fp);
		strcpy(ins[ins_n].instr,c);
		if(c!=NULL)
		{
			int tmp=strlen(c);
			if(c[strlen(c)-1]=='\n')
			{
				c[strlen(c)-1]='\0';
			}
			if(c[strlen(c)-1]==-1)
			{
				c[strlen(c)-1]='\0';
			}
			p=strtok_s(c,d,&p_stoken);
		}
		if(strcmp(p,SLOAD)==0)
       {
           if(strstr(p_stoken,"A") == NULL)
		   {
			   ins[ins_n].opcode=LOAD_OPCODE;
			   load_num++;
			   p = strtok_s(NULL,d,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in load is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0) && (match_RDV_R(p,ins_n,op_n) == 0))
			   {
				   print_instError("op_data of load error in line %d",ins_n+1);
			   }
			   ++op_n;
			   p = strtok_s(NULL,d,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in load is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   int length = atoi(p);
			   ins[ins_n].op[op_n].opd.length = length;
			   ++op_n;
			   p = strtok_s(NULL,d,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in load is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   int buff_id = atoi(p);
			   p = strtok_s(NULL,d,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in load is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   long buff_addr = atol(p);
			   buff_opd(ins_n,op_n,buff_id,buff_addr);
			   ++op_n;
			   indirct_flag(ins_n,op_n,0);
		   }
		   else
		   {
			   ins[ins_n].opcode=LOAD_OPCODE;
			   load_num++;
			   char seps[] = " A()";
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in load is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0) && (match_RDV_R(p,ins_n,op_n) == 0))
			   {
				   print_instError("op_data of load error in line %d.\n",ins_n+1);
			   }
			   ++op_n;
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in load is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   int length = atoi(p);
			   ins[ins_n].op[op_n].opd.length = length;
			   ++op_n;
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in load is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   int bufferid = atoi(p);
			   p = strtok_s(NULL,seps,&p_stoken);
			    if((p == NULL)||(strlen(p) != 2))
			   {
				   printf("p in load is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   char loopC[2];
			   loopC[0] = p[0];
			   loopC[1] = '\0';
			   int loopid = atoi(loopC);
			   loopC[0] = p[1];
			   loopC[1] = '\0';
			   int addrid = atoi(loopC);
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in load is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   int offset = atoi(p);
			   indirct_opd(ins_n,op_n,bufferid,loopid,addrid,offset);
			   ++op_n;
			   indirct_flag(ins_n,op_n,1);
		   }
       }
       else if(strcmp(p,SLAUNCH)==0)
       {
		   if(strstr(p_stoken,"A") == NULL)
		   {
			    ins[ins_n].opcode=LAUNCH_OPCODE;
				launch_num++;
				p = strtok_s(NULL,d,&p_stoken);
				if(p == NULL)
				{
					printf("p in launch is NULL in line %d.\n",ins_n+1);
					exit(0);
				}
				int layer_addr = atoi(p);
				p = strtok_s(NULL,d,&p_stoken);
				if(p == NULL)
				{
					printf("p in launch is NULL in line %d.\n",ins_n+1);
					exit(0);
				}
				int row = atoi(p);
				p = strtok_s(NULL,d,&p_stoken);
				if(p == NULL)
				{
					printf("p in launch is NULL in line %d.\n",ins_n+1);
					exit(0);
				}
				int col = atoi(p);
				mat_opd(ins_n,op_n,layer_addr,row,col);

				++op_n;
				p = strtok_s(NULL,d,&p_stoken);
				if(p == NULL)
				{
					printf("p in launch is NULL in line %d.\n",ins_n+1);
					exit(0);
				}
				int buff_id = atoi(p);
				p = strtok_s(NULL,d,&p_stoken);
				if(p == NULL)
				{
					printf("p in launch is NULL in line %d.\n",ins_n+1);
					exit(0);
				}
				long buff_addr = atol(p);
				buff_opd(ins_n,op_n,buff_id,buff_addr);
				++op_n;
				indirct_flag(ins_n,op_n,0);
		   }
		   else
		   {
			   ins[ins_n].opcode = LAUNCH_OPCODE;
			   launch_num++;
			   char seps[] = " A()";
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in launch is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   int layer_addr = atoi(p);
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in launch is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   int row = atoi(p);
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in launch is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   int col = atoi(p);
			   mat_opd(ins_n,op_n,layer_addr,row,col);
			   ++op_n;
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in launch is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   int bufferid = atoi(p);
			   p = strtok_s(NULL,seps,&p_stoken);
			   if((p == NULL)||(strlen(p) != 2))
			   {
				   printf("p in launch is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   char loopC[2];
			   loopC[0] = p[0];
			   loopC[1] = '\0';
			   int loopid = atoi(loopC);
			   loopC[0] = p[1];
			   loopC[1] = '\0';
			   int addrid = atoi(loopC);
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in launch is NULL in line %d\n",ins_n+1);
				   exit(0);
			   }
			   int offset = atoi(p);
			   indirct_opd(ins_n,op_n,bufferid,loopid,addrid,offset);
			   ++op_n;
			   indirct_flag(ins_n,op_n,1);

		   }
       }
	   else if(strcmp(p,SWB)==0)
       {
          if(strstr(p_stoken,"A") == NULL)
		  {
			  ins[ins_n].opcode=WB_OPCODE;
			  wb_num++;
			  p = strtok_s(NULL,d,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d.\n",ins_n+1);
				  exit(0);
			  }
			  int layer_addr = atoi(p);
			  p = strtok_s(NULL,d,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d.\n",ins_n+1);
				  exit(0);
			  }
			  int row = atoi(p);
			  p = strtok_s(NULL,d,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d.\n",ins_n+1);
				  exit(0);
			  }
			  int col = atoi(p);
			  mat_opd(ins_n,op_n,layer_addr,row,col);

			  ++op_n;
			  p = strtok_s(NULL,d,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d.\n",ins_n+1);
				  exit(0);
			  }
			  int buff_id = atoi(p);
			  p = strtok_s(NULL,d,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d\n",ins_n+1);
				  exit(0);
			  }
			  int buff_addr = atol(p);
			  buff_opd(ins_n,op_n,buff_id,buff_addr);
			  ++op_n;
			  indirct_flag(ins_n,op_n,0);
		  }
		  else
		  {
			  ins[ins_n].opcode = WB_OPCODE;
			  wb_num++;
			  char seps[] = " A()";
			  p = strtok_s(NULL,seps,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d\n",ins_n+1);
				  exit(0);
			  }
			  int layer_addr = atoi(p);
			  p = strtok_s(NULL,seps,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d\n",ins_n+1);
				  exit(0);
			  }
			  int row = atoi(p);
			  p = strtok_s(NULL,seps,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d\n",ins_n+1);
				  exit(0);
			  }
			  int col = atoi(p);
			  mat_opd(ins_n,op_n,layer_addr,row,col);

			  ++op_n;
			  p = strtok_s(NULL,seps,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d\n",ins_n+1);
				  exit(0);
			  }
			  int bufferid = atoi(p);
			  p = strtok_s(NULL,seps,&p_stoken);
			  if((p == NULL)||(strlen(p) != 2))
			  {
				  printf("p in wb is NULL in line %d.\n",ins_n+1);
				  exit(0);
			  }
			  char loopC[2];
			  loopC[0] = p[0];
			  loopC[1] = '\0';
			  int loopid = atoi(loopC);
			  loopC[0] = p[1];
			  loopC[1] = '\0';
			  int addrid = atoi(loopC);
			  p = strtok_s(NULL,seps,&p_stoken);
			  if(p == NULL)
			  {
				  printf("p in wb is NULL in line %d\n",ins_n+1);
				  exit(0);
			  }
			  int offset = atoi(p);
			  indirct_opd(ins_n,op_n,bufferid,loopid,addrid,offset);
			  ++op_n;
			  indirct_flag(ins_n,op_n,1);

		  }
       }
       else if(strcmp(p,SSTORE)==0)
       {
           if(strstr(p_stoken,"A") == NULL)
		   {
			   ins[ins_n].opcode=STORE_OPCODE;
			   store_num++;
			   p = strtok_s(NULL,d,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in store is NULL in line %d\n",ins_n+1);
				   exit(0);
			   }
			   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0) && (match_RDV_R(p,ins_n,op_n) == 0))
			   {
				   print_instError("op_data of store error in line %d.\n",ins_n+1);
			   }

			   ++op_n;
			   p = strtok_s(NULL,d,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in store is NULL in line %d\n",ins_n+1);
				   exit(0);
			   }
			   int length = atoi(p);
			   ins[ins_n].op[op_n].opd.length = length;

			   ++op_n;
			   p = strtok_s(NULL,d,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in store is NULL in line %d\n",ins_n+1);
				   exit(0);
			   }
			   int buff_id = atoi(p);
			   p = strtok_s(NULL,d,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in store is NULL in line %d\n",ins_n+1);
				   exit(0);
			   }
			   long buff_addr = atol(p);
			   buff_opd(ins_n,op_n,buff_id,buff_addr);
			   ++op_n;
			   indirct_flag(ins_n,op_n,0);
		   }
		   else
		   {
			   ins[ins_n].opcode = STORE_OPCODE;
			   store_num++;
			   char seps[] = " A()";
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in store is NULL in line %d\n",ins_n+1);
				   exit(0);
			   }
			   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0) && (match_RDV_R(p,ins_n,op_n) == 0))
			   {
				   print_instError("op_data of store error in line %d",ins_n+1);
				   //printf("op_data of store error in line %d\n",ins_n);
			   }

			   ++op_n;
			   p = strtok_s(NULL,d,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in store is NULL in line %d\n",ins_n+1);
				   exit(0);
			   }
			   int length = atoi(p);
			   ins[ins_n].op[op_n].opd.length = length;

			   ++op_n;
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in store is NULL in line %d\n",ins_n+1);
				   exit(0);
			   }
			   int bufferid = atoi(p);
			   p = strtok_s(NULL,seps,&p_stoken);
			   if((p == NULL)||(strlen(p) != 2))
			   {
				   printf("p in store is NULL in line %d.\n",ins_n+1);
				   exit(0);
			   }
			   char loopC[2];
			   loopC[0] = p[0];
			   loopC[1] = '\0';
			   int loopid = atoi(loopC);
			   loopC[0] = p[1];
			   loopC[1] = '\0';
			   int addrid = atoi(loopC);
			   p = strtok_s(NULL,seps,&p_stoken);
			   if(p == NULL)
			   {
				   printf("p in store is NULL in line %d\n",ins_n+1);
				   exit(0);
			   }
			   int offset = atoi(p);
			   indirct_opd(ins_n,op_n,bufferid,loopid,addrid,offset);
			   ++op_n;
			   indirct_flag(ins_n,op_n,1);
		   }
       }
	   else if(strcmp(p,SMOV)==0)
       {
           ins[ins_n].opcode=MOV_OPCODE;
           mov_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in mov is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0) && (match_RDV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of mov error in line %d",ins_n+1);
			   //printf(" op_data of mov error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in mov is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0) && (match_RDV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of mov error in line %d",ins_n+1);
			  // printf(" op_data of mov error in line %d\n",ins_n);
		   }
       }
	   else if(strcmp(p,SEXTMOV)==0)
       {
           ins[ins_n].opcode=EXTMOV_OPCODE;
           extmov_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in extmov is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0) && (match_RDV_R(p,ins_n,op_n) == 0)&& (match_EXTV_R(p,ins_n,op_n)))
		   {
			   print_instError(" op_data of extmov error in line %d",ins_n+1);
			   //printf(" op_data of extmov error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in extmov is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0) && (match_RDV_R(p,ins_n,op_n) == 0)&& (match_EXTV_R(p,ins_n,op_n)))
		   {
			   print_instError(" op_data of extmov error in line %d",ins_n+1);
			   //printf(" op_data of extmov error in line %d\n",ins_n);
		   }
       }
	   else if(strcmp(p,SDMALR)==0)
	   {
		   ins[ins_n].opcode = DMALR_OPCODE;
		   dmalr_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long mem_addr = atol(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int length = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int stride = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int repetition = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int buff_id = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long buff_addr = atol(p);
		   dma_opd(ins_n,op_n,mem_addr,length,stride,repetition,buff_id,buff_addr);
	   }
	   else if(strcmp(p,SDMALC)==0)
	   {
		   ins[ins_n].opcode = DMALC_OPCODE;
		   dmalc_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long mem_addr = atol(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int length = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int stride = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int repetition = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int buff_id = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmalc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long buff_addr = atol(p);
		   dma_opd(ins_n,op_n,mem_addr,length,stride,repetition,buff_id,buff_addr);
	   }
	   else if(strcmp(p,SDMASR)==0)
	   {
		   ins[ins_n].opcode = DMASR_OPCODE;
		   dmasr_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long mem_addr = atol(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int length = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int stride = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int repetition = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int buff_id = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasr is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long buff_addr = atol(p);
		   dma_opd(ins_n,op_n,mem_addr,length,stride,repetition,buff_id,buff_addr);
	   }
	   else if(strcmp(p,SDMASC)==0)
	   {
		   ins[ins_n].opcode = DMASC_OPCODE;
		   dmasc_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long mem_addr = atol(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int length = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int stride = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int repetition = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int buff_id = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in dmasc is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long buff_addr = atol(p);
		   dma_opd(ins_n,op_n,mem_addr,length,stride,repetition,buff_id,buff_addr);
	   }
       else if(strcmp(p,SPRODVM)==0)
       {
           ins[ins_n].opcode=PRODVM_OPCODE;
           prodvm_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of prodvm error in line %d",ins_n+1);
			   //printf(" op_data of prodvm error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodvm error in line %d",ins_n+1);
			   //printf(" op_data of prodvm error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int layer_addr = atoi(p);mat_opd2(ins_n,op_n,layer_addr);
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   bool accumul;
		   if(atoi(p)==1)
		   {
			   accumul = 1;
		   }
		   else if(atoi(p)==0)
		   {
			   accumul = 0;
		   }
		   else
		   {
			   printf( " op_data of prodvm error . accumul must 0 or 1. in line %d\n " ,ins_n+1);
			   exit(0);
		   }
		   ins[ins_n].op[op_n].opd.accumul = accumul;
       }
	   else if(strcmp(p,SPRODVMP)==0)
       {
           ins[ins_n].opcode=PRODVMP_OPCODE;
           prodvmp_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvmp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodvmp error in line %d",ins_n+1);
			   //printf(" op_data of prodvm error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvmp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int layer_addr = atoi(p);mat_opd2(ins_n,op_n,layer_addr);
		   ++op_n;
    	   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvmp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   bool accumul;
		   if(atoi(p)==1)
		   {
			   accumul = 1;
		   }
		   else if(atoi(p)==0)
		   {
			   accumul = 0;
		   }
		   else
		   {
			   printf( " op_data of prodvmp error . accumul must 0 or 1. in line %d\n " ,ins_n+1);
			   exit(0);
		   }
		   ins[ins_n].op[op_n].opd.accumul = accumul;
       }
       else if(strcmp(p,SPRODMV)==0)
       {
           ins[ins_n].opcode=PRODMV_OPCODE;
           prodmv_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodmv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of prodmv error in line %d",ins_n+1);
			   //printf(" op_data of prodmv error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodmv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodmv error in line %d",ins_n+1);
			  // printf(" op_data of prodmv error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodmv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int layer_addr = atoi(p);mat_opd2(ins_n,op_n,layer_addr);
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodmv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   bool accumul;
		  if(atoi(p)==1)
		  {
	    	   accumul = 1;
	      }
	     else if(atoi(p)==0)
	      {
	        accumul = 0;
	      }
	      else
	      {
	         printf( " op_data of prodmv error . accumul must 0 or 1. in line %d\n " ,ins_n+1);
	         exit(0);
	      }
		   ins[ins_n].op[op_n].opd.accumul = accumul;
       }
	   else if(strcmp(p,SPRODMVP)==0)
       {
           ins[ins_n].opcode=PRODMVP_OPCODE;
           prodmvp_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodmvp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodmvp error in line %d",ins_n+1);
			  // printf(" op_data of prodmv error in line %d\n",ins_n);
		   }
		   ++op_n;
		    p = strtok_s(NULL,d,&p_stoken);
			if(p == NULL)
			{
				printf("p in prodmvp is NULL in line %d\n",ins_n+1);
				exit(0);
			}
			int layer_addr = atoi(p);mat_opd2(ins_n,op_n,layer_addr);
			++op_n;
			p = strtok_s(NULL,d,&p_stoken);
			if(p == NULL)
			{
				printf("p in prodmvp is NULL in line %d\n",ins_n+1);
				exit(0);
			}
			bool accumul;
			if(atoi(p)==1)
		  {
	    	   accumul = 1;
	      }
	     else if(atoi(p)==0)
	      {
	        accumul = 0;
	      }
	      else
	      {
	         printf( " op_data of prodmvp error . accumul must 0 or 1. in line %d\n " ,ins_n+1);
	         exit(0);
	      }
			ins[ins_n].op[op_n].opd.accumul = accumul;
       }
       else if(strcmp(p,SPRODVV)==0)
       {
           ins[ins_n].opcode=PRODVV_OPCODE;
           prodvv_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int layer_addr = atoi(p);mat_opd2(ins_n,op_n,layer_addr);
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodvv error in line %d",ins_n+1);
			   //printf(" op_data of prodvv error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodvv error in line %d",ins_n+1);
			  // printf(" op_data of prodvv error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   bool accumul;
		  if(atoi(p)==1)
		  {
	    	   accumul = 1;
	      }
	     else if(atoi(p)==0)
	      {
	        accumul = 0;
	      }
	      else
	      {
	         printf( " op_data of prodvv error . accumul must 0 or 1. in line %d\n " ,ins_n+1);
	         exit(0);
	      }
		   ins[ins_n].op[op_n].opd.accumul = accumul;
       }
       else if(strcmp(p,SPRODVVP)==0)
       {
           ins[ins_n].opcode=PRODVVP_OPCODE;
           prodvvp_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvvp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodvvp error in line %d",ins_n+1);
			   //printf(" op_data of prodvv error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvvp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodvvp error in line %d",ins_n+1);
			  // printf(" op_data of prodvv error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvvp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   bool accumul;
		   if(atoi(p)==1)
		  {
	    	   accumul = 1;
	      }
	     else if(atoi(p)==0)
	      {
	        accumul = 0;
	      }
	      else
	      {
	         printf( " op_data of prodvvp error . accumul must 0 or 1. in line %d\n " ,ins_n+1);
	         exit(0);
	      }
		   ins[ins_n].op[op_n].opd.accumul = accumul;
       }
       else if(strcmp(p,SPRODVVD)==0)
       {
           ins[ins_n].opcode=PRODVVD_OPCODE;
           prodvvd_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvvd is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodvvd error in line %d",ins_n+1);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in prodvvd is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of prodvvd error in line %d",ins_n+1);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		    p = strtok_s(NULL,d,&p_stoken);
			if(p == NULL)
			{
				printf("p in prodvvd is NULL in line %d\n",ins_n+1);
				exit(0);
			}
		   if((match_BV_R(p,ins_n,op_n) == 0) && (match_RV_R(p,ins_n,op_n) == 0))
		   {
			   print_instError(" op_data of prodvvd error in line %d",ins_n+1);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
       }
       else if(strcmp(p,SADDV)==0)
       {
           ins[ins_n].opcode=ADDV_OPCODE;
           addv_num++;
		    p = strtok_s(NULL,d,&p_stoken);
			if(p == NULL)
			{
				printf("p in addv is NULL in line %d\n",ins_n+1);
				exit(0);
			}
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of addv error in line %d",ins_n+1);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in addv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of addv error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		    p = strtok_s(NULL,d,&p_stoken);
			if(p == NULL)
			{
				printf("p in addv is NULL in line %d\n",ins_n+1);
				exit(0);
			}
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of addv error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
       }
	   else if(strcmp(p,SADDM)==0)
       {
           ins[ins_n].opcode=ADDM_OPCODE;
           addm_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in addm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		  int layer_addr = atoi(p);
		   mat_opd2(ins_n,op_n,layer_addr);
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in addm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   layer_addr = atoi(p);
		   mat_opd2(ins_n,op_n,layer_addr);++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in addm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   layer_addr = atoi(p);
		   mat_opd2(ins_n,op_n,layer_addr);
       }
	   else if(strcmp(p,SSUBV)==0)
       {
           ins[ins_n].opcode=SUBV_OPCODE;
           subv_num++;
		    p = strtok_s(NULL,d,&p_stoken);
			if(p == NULL)
			{
				printf("p in subv is NULL in line %d\n",ins_n+1);
				exit(0);
			}
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of subv error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in subv is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of subv error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		    p = strtok_s(NULL,d,&p_stoken);
			if(p == NULL)
			{
				printf("p in subv is NULL in line %d\n",ins_n+1);
				exit(0);
			}
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of subv error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
       }
	   else if(strcmp(p,SSUBM)==0)
       {
           ins[ins_n].opcode=SUBM_OPCODE;
           subm_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in subm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int layer_addr = atoi(p);
		   mat_opd2(ins_n,op_n,layer_addr);
		   p = strtok_s(NULL,d,&p_stoken);++op_n;
		   if(p == NULL)
		   {
			   printf("p in subm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   layer_addr = atoi(p);
		   mat_opd2(ins_n,op_n,layer_addr);++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in subm is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   layer_addr = atoi(p);
		   mat_opd2(ins_n,op_n,layer_addr);
       }
	   else if(strcmp(p,SSUM)==0)
       {
           ins[ins_n].opcode=SUM_OPCODE;
           sum_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in sum is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of sum error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   p = strtok_s(NULL,d,&p_stoken);++op_n;
		   if(p == NULL)
		   {
			   printf("p in sum is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int layer_addr = atoi(p);
		   mat_opd2(ins_n,op_n,layer_addr);
       }
	   else if(strcmp(p,SMAX)==0)
	   {
		   ins[ins_n].opcode=MAX_OPCODE;
		   max_num++;
		   p=strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in max is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of max error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   p = strtok_s(NULL,d,&p_stoken);++op_n;
		   if(p == NULL)
		   {
			   printf("p in max is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of max error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in max is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   ++op_n;
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			    print_instError(" op_data of max error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
	   }
	   else if(strcmp(p,SSCALE)==0)
       {
           ins[ins_n].opcode=SCALE_OPCODE;
           scale_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in scale is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of scale error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in scale is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of scale error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in scale is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   PS_ENT_TYPE scale_factor = float2pstype(p);
		   imme_opd(ins_n,op_n,scale_factor);

       }
	   else if(strcmp(p,SDIFF)==0)
       {
           ins[ins_n].opcode=DIFF_OPCODE;
           diff_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in diff is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of diff error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in diff is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of diff error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
       }
	   else if(strcmp(p,SRANDGEN)==0)
       {
           ins[ins_n].opcode=RANDGEN_OPCODE;
           randgen_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in randgen is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RDV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of randgen error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
       }
	   else if(strcmp(p,SPROBCMP) == 0)
       {
           ins[ins_n].opcode=PROBCMP_OPCODE;
           probcmp_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in probcmp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_BV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError("op_data of probcmp error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in probcmp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError("op_data of probcmp error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in probcmp is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RDV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of probcmp error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
       }
	   else if(strcmp(p,SBIAS)==0)
       {
           ins[ins_n].opcode=BIAS_OPCODE;
           bias_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in bias is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of bias error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in bias is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of bias error in line %d",ins_n);
			   //printf(" op_data of prodvvd error in line %d\n",ins_n);
		   }
		   ++op_n;p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in bias is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   PS_ENT_TYPE bias = float2pstype(p);
		   imme_opd(ins_n,op_n,bias);
       }
	   else if(strcmp(p,SACT) == 0)
	   {
		   ins[ins_n].opcode=ACT_OPCODE;
		   act_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in act is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of act error in line %d",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in act is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   if(match_RV_R(p,ins_n,op_n) == 0)
		   {
			   print_instError(" op_data of act error in line %d",ins_n);
		   }
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in act is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   short act_type = atoi(p);
		   imme_opd(ins_n,op_n,act_type);
	   }
	   else if(strcmp(p,SLOOP) == 0)
	   {
		   ins[ins_n].opcode = LOOP_OPCODE;
		   loop_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in loop is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int loopid = atoi(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in act is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   int loopiter = atoi(p);
		   loopid_opd(ins_n,op_n,loopid,loopiter);
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in loop is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long addr = atol(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in loop is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   long stride = atol(p);
		   loopad_opd(ins_n,op_n,stride,addr);
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in loop is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   addr = atol(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in loop is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   stride = atol(p);
		   loopad_opd(ins_n,op_n,stride,addr);
		   ++op_n;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in loop is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   addr = atol(p);
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in loop is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   stride = atol(p);
		   loopad_opd(ins_n,op_n,stride,addr);
	   }
	   else if(strcmp(p,SENDLOOP) == 0)
	   {
		   ins[ins_n].opcode = ENDLOOP_OPCODE;
		   endloop_num++;
		   p = strtok_s(NULL,d,&p_stoken);
		   if(p == NULL)
		   {
			   printf("p in endloop is NULL in line %d\n",ins_n+1);
			   exit(0);
		   }
		   ins[ins_n].op[op_n].opd.endloopid = atoi(p);
	   }
       else
       {
           printf("load_pm error in %d\n",ins_n+1);
           exit(0);
       }
	}
    close_file(fp);
	close_instError();
    return ins_num;
}
