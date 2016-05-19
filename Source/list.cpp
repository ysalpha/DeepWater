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
 * list
 *
 * realize list data structure and define some common function
 */

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct NODE* init_node()
{
	struct NODE* pnode=NULL;
	pnode=(struct NODE*)malloc(sizeof(struct NODE));
	pnode->mem_addr=0;
	pnode->flag=0;
	pnode->next=NULL;
	return pnode;
}

void add_node(struct NODE* pNode,long mem_addr,bool flag)
{
	struct NODE* p1=NULL;
	struct NODE *p2=NULL;
	p1=(struct NODE*)malloc(sizeof(struct NODE));
	p1->mem_addr=mem_addr;
	p1->flag=flag;
	p1->next=NULL;
	p2=pNode;
	while(p2->next!=NULL)
	{
		p2=p2->next;
	}
	p2->next=p1;
}

void clr_nodes(struct NODE* pnode)
{
	struct NODE* p1=pnode,*p2=NULL;
	while(p1!=NULL)
	{
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	pnode=NULL;
}

bool find_flag(struct NODE* pnode,long mem_addr)
{
	struct NODE* p1=pnode;
	while(p1->next!=NULL)
	{
		if(p1->next->mem_addr==mem_addr)
		{
			return p1->next->flag;
		}
		p1=p1->next;
	}
	return 0;
}
