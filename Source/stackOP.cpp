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
 * stack op
 *
 * define common stack structure
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stackOP.h"


nodeLP stateLP[LP_LAYER];
curlp curlpRV;

void addSateLP(int lpId,int iterLP,long addr1,long strd1,long addr2,long strd2,long addr3,long strd3,long lpaddr)
{
	nodeLP *newp = (nodeLP*)malloc(sizeof(nodeLP));
	newp->isOver = 0;
	newp->iterLP = iterLP;
	newp->addr1 = addr1;
	newp->strd1 = strd1;
	newp->addr2 = addr2;
	newp->strd2 = strd2;
	newp->addr3 = addr3;
	newp->strd3 = strd3;
	newp->lpaddr = lpaddr;
	newp->endlpaddr = 0;
	newp->lpnext = stateLP[lpId].lpnext;
	stateLP[lpId].lpnext = newp;
}

void delStateLP(int lpID)
{
	if(stateLP[lpID].lpnext != NULL)
	{
		nodeLP *curpn = stateLP[lpID].lpnext->lpnext;
		nodeLP *curp = stateLP[lpID].lpnext;
		stateLP[lpID].lpnext = curpn;
		free(curp);
	}
}

void modOverLP(int lpId,bool isOver)
{
	stateLP[lpId].lpnext->isOver = isOver;
}

void modEndLP(int lpId,long endlpaddr)
{
	stateLP[lpId].lpnext->endlpaddr = endlpaddr;
}

bool loopEndById(int lpId)
{
	if(stateLP[lpId].lpnext == NULL)
	{
		return 1;
	}
	if(stateLP[lpId].lpnext->isOver == 1)
	{
		return 1;
	}
	return 0;
}

bool subIterLP(int lpID)
{
	if(--(stateLP[lpID].lpnext->iterLP) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool setEndlpAddr(int lpID,long addr)
{
	if((stateLP[lpID].lpnext->endlpaddr == 0)||(stateLP[lpID].lpnext->endlpaddr == addr))
	{
		modEndLP(lpID,addr);
		return 1;
	}
	else
	{
		return 0;
	}
}

void endlpaddrst(int lpID)
{
	stateLP[lpID].lpnext->addr1 += stateLP[lpID].lpnext->strd1;
	stateLP[lpID].lpnext->addr2 += stateLP[lpID].lpnext->strd2;
	stateLP[lpID].lpnext->addr3 += stateLP[lpID].lpnext->strd3;
}

bool lpdecode(long addr)
{
	if(stateLP[curlpRV.lpid].lpnext == NULL)
	{
		return 1;
	}
	if((stateLP[curlpRV.lpid].lpnext->endlpaddr == 0)||(addr <= stateLP[curlpRV.lpid].lpnext->endlpaddr))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

long getADDR(int lpID,int addr1)
{
	if(addr1 == 0)
	{
		return stateLP[lpID].lpnext->addr1;
	}
	else if(addr1 == 1)
	{
		return stateLP[lpID].lpnext->addr2;
	}
	else if(addr1 == 2)
	{
		return stateLP[lpID].lpnext->addr3;
	}
	else
	{
		return 0;
	}
}

bool endcurloop()
{
	return loopEndById(curlpRV.lpid);
}

bool endclpjaddr(long insaddr)
{
	if(endcurloop())
	{
		if(insaddr>stateLP[curlpRV.lpid].lpnext->endlpaddr)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
