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

#ifndef _REGS_MODELING_H
#define _REGS_MODELING_H

#include "dataTypeModeling.h"
#include "configuration.h"

struct RG
{
	bool RD_S;//read flag
	bool WR_S;//write flag
	bool WRD_S;//wait to read flag
	bool WWR_S;//wait to write flag
	PS_PTR_TYPE V;//the real data vector
};

struct G_RG //real register group
{
	int readnum;
	int writenum;
	RG* R_V;
};

extern G_RG *RV,*RDV,*EXTV;
extern G_RG *PRV,*PRDV,*PEXTV;

extern RG Rbuffer,Cbuffer;
extern RG PRbuffer,PCbuffer;

struct RB
{
	bool RD_S;//read flag
	bool WR_S;//write flag
	bool WRD_S;//wait to read flag
	bool WWR_S;//wait to write flag
	bool *V;//the int data vector
};

struct G_RB //bool register group
{
	//int readnum;
	//int writenum;
	RB *R_V;
};

extern G_RB *BV;
extern G_RB *PBV;

#define VALID 0 //lock is valid
#define INVALID 1 //lock is invalid

#define VALID 0 //lock is valid
#define INVALID 1 //lock is invalid

/*register read control; Group g, Register n, and the i(th) element*/
#define R_read(g,n,i) g##V->R_V[n].V[i] 

/*register write control; Group G, Register n, and the i(th) element, d the data is writen*/
#define R_write(g,n,i,d) g##V->R_V[n].V[i]=d

/*judge group G n(th) register can be write or not, 0 not, 1 yes*/
#define jud_write(g,n) ((g##V->R_V[n].RD_S==VALID)||(g##V->R_V[n].WR_S==VALID)||(g##V->R_V[n].WRD_S==VALID)||(g##V->R_V[n].WWR_S==VALID)) ? 0 : 1 //(g##V->writenum<R_WR_PORT)&1

/*judge group G n(th) register can be read or not, 0 not, 1 yes*/
#define jud_read(g,n) ((g##V->R_V[n].WR_S==VALID)||(g##V->R_V[n].WWR_S==VALID)) ? 0 : 1 // (g##V->readnum<R_RD_PORT)&1 //a litter problem

/*set write flag for Group G n(th) vector*/
#define set_wr(g,n) g##V->R_V[n].WR_S=VALID; //g##V->writenum++;

/*set read flag for Group G n(th) vector*/
#define set_rd(g,n) g##V->R_V[n].RD_S=VALID; //g##V->readnum++;

/*set wait to read flag for Group G n(th) vector*/
#define set_wrd(g,n) g##V->R_V[n].WRD_S=VALID;

/*set wait to write flag for Group G n(th) vector*/
#define set_wwr(g,n) g##V->R_V[n].WWR_S=VALID;

/*clear write flag for Group G n(th) vector*/
#define clr_wr(g,n) g##V->R_V[n].WR_S=INVALID; //g##V->writenum--;

/*clear read flag for Group G n(th) vector*/
#define clr_rd(g,n) g##V->R_V[n].RD_S=INVALID; //g##V->readnum--;

/*clear wait to read flag for Group G n(th) vector*/
#define clr_wrd(g,n) g##V->R_V[n].WRD_S=INVALID;

/*clear wait to write flag for Group G n(th) vector*/
#define clr_wwr(g,n) g##V->R_V[n].WWR_S=INVALID;

struct MG
{
	bool RD_S;//read flag
	bool WR_S;//write flag
	bool WRD_S;//wait to read flag
	bool WWR_S;//wait to write flag
	PS_ENT_TYPE *V;
};

struct G_M
{
	MG *M_V;
};

extern G_M **MAT;
extern G_M **PMAT;

struct G_MB
{
	bool RD_S;
	bool WR_S;
	bool WRD_S;
	bool WWR_S;
	PS_PTR_TYPE *V;
};

extern G_MB Mbuffer;
extern G_MB PMbuffer;

/* definition of Rbuffer, Cbuffer, Mbuffer state flag operations */
#define jud_B_read(buffer_type) (((buffer_type##buffer.WR_S==VALID)||(buffer_type##buffer.WWR_S==VALID))?0:1)
#define jud_B_write(buffer_type) (((buffer_type##buffer.WR_S==VALID)||(buffer_type##buffer.WWR_S==VALID)||(buffer_type##buffer.RD_S==VALID)||(buffer_type##buffer.WRD_S==VALID))?0:1)

#define set_B_rd(buffer_type) buffer_type##buffer.RD_S=VALID
#define set_B_wr(buffer_type) buffer_type##buffer.WR_S=VALID
#define set_B_wrd(buffer_type) buffer_type##buffer.WRD_S=VALID
#define set_B_wwr(buffer_type) buffer_type##buffer.WWR_S=VALID

#define clr_B_rd(buffer_type) buffer_type##buffer.RD_S=INVALID
#define clr_B_wr(buffer_type) buffer_type##buffer.WR_S=INVALID
#define clr_B_wrd(buffer_type) buffer_type##buffer.WRD_S=INVALID
#define clr_B_wwr(buffer_type) buffer_type##buffer.WWR_S=INVALID

/* define  operations of read/write Rbuffer, Cbuffer, Mbuffer */
#define read_RC_B(buffer_type,buffer_index) buffer_type##buffer.V[buffer_index]
#define write_RC_B(buffer_type,buffer_index,data) buffer_type##buffer.V[buffer_index]=data

#define read_M_B(buffer_row,buffer_col) Mbuffer.V[buffer_row][buffer_col]
#define write_M_B(buffer_row,buffer_col,data) Mbuffer.V[buffer_row][buffer_col]=data

/*MAT row read control; Layer L, row r, and the i(th) element*/
#define M_read(l,r,i) MAT[l]->M_V[r].V[i] 

/*MAT row write control; Layer L, row r, and the i(th) element, d the data is writen*/
#define M_write(l,r,i,d) MAT[l]->M_V[r].V[i]=d

/*judge layer L r(th) row can be write or not, 0 not, 1 yes*/
#define jud_MR_write(l,r) ((MAT[l]->M_V[r].RD_S==VALID)||(MAT[l]->M_V[r].WR_S==VALID)||(MAT[l]->M_V[r].WRD_S==VALID)||(MAT[l]->M_V[r].WWR_S==VALID)) ? 0 : 1

/*judge layer L r(th) row can be read or not, 0 not, 1 yes*/ 
#define jud_MR_read(l,r) ((MAT[l]->M_V[r].WR_S==VALID)||(MAT[l]->M_V[r].WWR_S==VALID)) ? 0 : 1

#define jud_M_write(l) (jud_MR_write(l,0)&&jud_MR_write(l,1)&&jud_MR_write(l,2)&&jud_MR_write(l,3)&&jud_MR_write(l,4)\
	&&jud_MR_write(l,5)&&jud_MR_write(l,6)&&jud_MR_write(l,7)&&jud_MR_write(l,8)&&jud_MR_write(l,9)\
	&&jud_MR_write(l,10)&&jud_MR_write(l,11)&&jud_MR_write(l,12)&&jud_MR_write(l,13)&&jud_MR_write(l,14)\
	&&jud_MR_write(l,15)) ? 1 : 0

#define jud_M_read(l) (jud_MR_read(l,0)&&jud_MR_read(l,1)&&jud_MR_read(l,2)&&jud_MR_read(l,3)&&jud_MR_read(l,4)&&jud_MR_read(l,5)\
	&&jud_MR_read(l,6)&&jud_MR_read(l,7)&&jud_MR_read(l,8)&&jud_MR_read(l,9)&&jud_MR_read(l,10)&&jud_MR_read(l,11)\
	&&jud_MR_read(l,12)&&jud_MR_read(l,13)&&jud_MR_read(l,14)&&jud_MR_read(l,15)) ? 1 : 0

/*set write flag for Layer L r(th) row*/
#define set_MR_wr(l,r) MAT[l]->M_V[r].WR_S=VALID; 

#define set_M_wr(l) set_MR_wr(l,0);set_MR_wr(l,1);set_MR_wr(l,2);set_MR_wr(l,3);set_MR_wr(l,4);set_MR_wr(l,5);\
	set_MR_wr(l,6);set_MR_wr(l,7);set_MR_wr(l,8);set_MR_wr(l,9);set_MR_wr(l,10);set_MR_wr(l,11);\
	set_MR_wr(l,12);set_MR_wr(l,13);set_MR_wr(l,14);set_MR_wr(l,15)

/*set read flag for Layer L r(th) row*/
#define set_MR_rd(l,r) MAT[l]->M_V[r].RD_S=VALID;

#define set_M_rd(l) set_MR_rd(l,0);set_MR_rd(l,1);set_MR_rd(l,2);set_MR_rd(l,3);set_MR_rd(l,4);set_MR_rd(l,5);\
	set_MR_rd(l,6);set_MR_rd(l,7);set_MR_rd(l,8);set_MR_rd(l,9);set_MR_rd(l,10);set_MR_rd(l,11);\
	set_MR_rd(l,12);set_MR_rd(l,13);set_MR_rd(l,14);set_MR_rd(l,15)

/*set wait to read flag for Layer L r(th) row*/
#define set_MR_wrd(l,r) MAT[l]->M_V[r].WRD_S=VALID;

#define set_M_wrd(l) set_MR_wrd(l,0);set_MR_wrd(l,1);set_MR_wrd(l,2);set_MR_wrd(l,3);set_MR_wrd(l,4);set_MR_wrd(l,5);\
	set_MR_wrd(l,6);set_MR_wrd(l,7);set_MR_wrd(l,8);set_MR_wrd(l,9);set_MR_wrd(l,10);set_MR_wrd(l,11);\
	set_MR_wrd(l,12);set_MR_wrd(l,13);set_MR_wrd(l,14);set_MR_wrd(l,15)

/*set wait to write flag for Layer L r(th) row*/
#define set_MR_wwr(l,r) MAT[l]->M_V[r].WWR_S=VALID;

#define set_M_wwr(l) set_MR_wwr(l,0);set_MR_wwr(l,1);set_MR_wwr(l,2);set_MR_wwr(l,3);set_MR_wwr(l,4);set_MR_wwr(l,5);\
	set_MR_wwr(l,6);set_MR_wwr(l,7);set_MR_wwr(l,8);set_MR_wwr(l,9);set_MR_wwr(l,10);set_MR_wwr(l,11);\
	set_MR_wwr(l,12);set_MR_wwr(l,13);set_MR_wwr(l,14);set_MR_wwr(l,15)

/*clear write flag for Layer L  r(th) row*/
#define clr_MR_wr(l,r) MAT[l]->M_V[r].WR_S=INVALID;

#define clr_M_wr(l) clr_MR_wr(l,0);clr_MR_wr(l,1);clr_MR_wr(l,2);clr_MR_wr(l,3);clr_MR_wr(l,4);clr_MR_wr(l,5);\
	clr_MR_wr(l,6);clr_MR_wr(l,7);clr_MR_wr(l,8);clr_MR_wr(l,9);clr_MR_wr(l,10);clr_MR_wr(l,11);\
	clr_MR_wr(l,12);clr_MR_wr(l,13);clr_MR_wr(l,14);clr_MR_wr(l,15)

/*clear read flag for Layer L r(th) row*/
#define clr_MR_rd(l,r) MAT[l]->M_V[r].RD_S=INVALID;

#define clr_M_rd(l) clr_MR_rd(l,0);clr_MR_rd(l,1);clr_MR_rd(l,2);clr_MR_rd(l,3);clr_MR_rd(l,4);clr_MR_rd(l,5);\
	clr_MR_rd(l,6);clr_MR_rd(l,7);clr_MR_rd(l,8);clr_MR_rd(l,9);clr_MR_rd(l,10);clr_MR_rd(l,11);\
	clr_MR_rd(l,12);clr_MR_rd(l,13);clr_MR_rd(l,14);clr_MR_rd(l,15)

/*clear wait to read flag for Layer L r(th) row*/
#define clr_MR_wrd(l,r) MAT[l]->M_V[r].WRD_S=INVALID;

#define clr_M_wrd(l) clr_MR_wrd(l,0);clr_MR_wrd(l,1);clr_MR_wrd(l,2);clr_MR_wrd(l,3);clr_MR_wrd(l,4);clr_MR_wrd(l,5);\
	clr_MR_wrd(l,6);clr_MR_wrd(l,7);clr_MR_wrd(l,8);clr_MR_wrd(l,9);clr_MR_wrd(l,10);clr_MR_wrd(l,11);\
	clr_MR_wrd(l,12);clr_MR_wrd(l,13);clr_MR_wrd(l,14);clr_MR_wrd(l,15)

/*clear wait to write flag for Layer L r(th) row*/
#define clr_MR_wwr(l,r) MAT[l]->M_V[r].WWR_S=INVALID;

#define clr_M_wwr(l) clr_MR_wwr(l,0);clr_MR_wwr(l,1);clr_MR_wwr(l,2);clr_MR_wwr(l,3);clr_MR_wwr(l,4);clr_MR_wwr(l,5);\
	clr_MR_wwr(l,6);clr_MR_wwr(l,7);clr_MR_wwr(l,8);clr_MR_wwr(l,9);clr_MR_wwr(l,10);clr_MR_wwr(l,11);\
	clr_MR_wwr(l,12);clr_MR_wwr(l,13);clr_MR_wwr(l,14);clr_MR_wwr(l,15)


/*initialize the group RV register*/
extern void init_RV();
extern void init_EXTV();
extern void init_RDV();
extern void init_BV();
extern void init_MAT();
extern void init_BUFF();

#endif /* _REGS_MODELING_H */
