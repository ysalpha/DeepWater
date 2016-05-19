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

#ifndef _STACK_OP_H
#define _STACK_OP_H

/* set loop max embedded layers */
#define LP_LAYER 8

typedef struct LOOP_STRUCT
{
	struct LOOP_STRUCT *lpnext;
	bool isOver;//1 show loop end
	int iterLP;
	long addr1;
	long strd1;
	long addr2;
	long strd2;
	long addr3;
	long strd3;
	long lpaddr;
	long endlpaddr;
}nodeLP;

/* loop state registers,adopt stack structure to manage peer-loop */
extern nodeLP stateLP[LP_LAYER];

/* add loop information to stack selected by loop-id */
extern void addSateLP(int lpId,int iterLP,long addr1,long strd1,long addr2,long strd2,long addr3,long strd3,long lpaddr);
/* delete loop information from stack selected by loop-id */
extern void delStateLP(int lpID);
/* modify loop state information of loop execution over */
extern void modOverLP(int lpId,bool isOver);
/* modify loop state information of loop-end address */
extern void modEndLP(int lpId,long endlpaddr);
/* judge loop end by loop-id */
extern bool loopEndById(int lpId);
/* update loop iter numbers */
extern bool subIterLP(int lpID);
/* try to set loop-end address */
extern bool setEndlpAddr(int lpID,long addr);
/* address in loop-info operation */
extern void endlpaddrst(int lpID);
extern bool lpdecode(long addr);//To determine whether a command in the current loop cycle
/* obtain the address in loop-info */
extern long getADDR(int lpID,int addr1);
extern bool endcurloop();//Whether the current loop is over
extern bool endclpjaddr(long insaddr);//Determine the end of the current loop, and instruction address is greater than the end of the loop

typedef struct
{
	int lpid;
	long endlpaddr;/* loop-end address */
}curlp;

/* record the loop id and related informations with executing */
extern curlp curlpRV;

#endif /* _STACK_OP_H */
