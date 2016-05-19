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

#ifndef _PRONT_BANDWITH_H
#define _PRONT_BANDWITH_H

#define SIAPLING_FREQUENCY 100

#define ALL_RV_IN_BANDWITH "bandwith\\rv_bw\\allRVInBandwith.txt"
#define ALL_RV_OUT_BANDWITH "bandwith\\rv_bw\\allRVOutBandwith.txt"

#define RV_IN_BANDWITH0 "bandwith\\rv_bw\\RV0InBandwith.txt"
#define RV_IN_BANDWITH1 "bandwith\\rv_bw\\RV1InBandwith.txt"
#define RV_IN_BANDWITH2 "bandwith\\rv_bw\\RV2InBandwith.txt"
#define RV_IN_BANDWITH3 "bandwith\\rv_bw\\RV3InBandwith.txt"
#define RV_IN_BANDWITH4 "bandwith\\rv_bw\\RV4InBandwith.txt"
#define RV_IN_BANDWITH5 "bandwith\\rv_bw\\RV5InBandwith.txt"
#define RV_IN_BANDWITH6 "bandwith\\rv_bw\\RV6InBandwith.txt"
#define RV_IN_BANDWITH7 "bandwith\\rv_bw\\RV7InBandwith.txt"
#define RV_IN_BANDWITH8 "bandwith\\rv_bw\\RV8InBandwith.txt"
#define RV_IN_BANDWITH9 "bandwith\\rv_bw\\RV9InBandwith.txt"
#define RV_IN_BANDWITH10 "bandwith\\rv_bw\\RV10InBandwith.txt"
#define RV_IN_BANDWITH11 "bandwith\\rv_bw\\RV11InBandwith.txt"
#define RV_IN_BANDWITH12 "bandwith\\rv_bw\\RV12InBandwith.txt"
#define RV_IN_BANDWITH13 "bandwith\\rv_bw\\RV13InBandwith.txt"
#define RV_IN_BANDWITH14 "bandwith\\rv_bw\\RV14InBandwith.txt"
#define RV_IN_BANDWITH15 "bandwith\\rv_bw\\RV15InBandwith.txt"

#define RV_OUT_BANDWITH0 "bandwith\\rv_bw\\RV0OutBandwith.txt"
#define RV_OUT_BANDWITH1 "bandwith\\rv_bw\\RV1OutBandwith.txt"
#define RV_OUT_BANDWITH2 "bandwith\\rv_bw\\RV2OutBandwith.txt"
#define RV_OUT_BANDWITH3 "bandwith\\rv_bw\\RV3OutBandwith.txt"
#define RV_OUT_BANDWITH4 "bandwith\\rv_bw\\RV4OutBandwith.txt"
#define RV_OUT_BANDWITH5 "bandwith\\rv_bw\\RV5OutBandwith.txt"
#define RV_OUT_BANDWITH6 "bandwith\\rv_bw\\RV6OutBandwith.txt"
#define RV_OUT_BANDWITH7 "bandwith\\rv_bw\\RV7OutBandwith.txt"
#define RV_OUT_BANDWITH8 "bandwith\\rv_bw\\RV8OutBandwith.txt"
#define RV_OUT_BANDWITH9 "bandwith\\rv_bw\\RV9OutBandwith.txt"
#define RV_OUT_BANDWITH10 "bandwith\\rv_bw\\RV10OutBandwith.txt"
#define RV_OUT_BANDWITH11 "bandwith\\rv_bw\\RV11OutBandwith.txt"
#define RV_OUT_BANDWITH12 "bandwith\\rv_bw\\RV12OutBandwith.txt"
#define RV_OUT_BANDWITH13 "bandwith\\rv_bw\\RV13OutBandwith.txt"
#define RV_OUT_BANDWITH14 "bandwith\\rv_bw\\RV14OutBandwith.txt"
#define RV_OUT_BANDWITH15 "bandwith\\rv_bw\\RV15OutBandwith.txt"


#define ALL_BV_IN_BANDWITH "bandwith\\bv_bw\\allBVInBandwith.txt"
#define ALL_BV_OUT_BANDWITH "bandwith\\bv_bw\\allBVOutBandwith.txt"

#define BV_IN_BANDWITH0 "bandwith\\bv_bw\\BV0InBandwith.txt"
#define BV_IN_BANDWITH1 "bandwith\\bv_bw\\BV1InBandwith.txt"
#define BV_IN_BANDWITH2 "bandwith\\bv_bw\\BV2InBandwith.txt"
#define BV_IN_BANDWITH3 "bandwith\\bv_bw\\BV3InBandwith.txt"

#define BV_OUT_BANDWITH0 "bandwith\\bv_bw\\BV0OutBandwith.txt"
#define BV_OUT_BANDWITH1 "bandwith\\bv_bw\\BV1OutBandwith.txt"
#define BV_OUT_BANDWITH2 "bandwith\\bv_bw\\BV2OutBandwith.txt"
#define BV_OUT_BANDWITH3 "bandwith\\bv_bw\\BV3OutBandwith.txt"

#define ALL_RDV_IN_BANDWITH "bandwith\\rdv_bw\\allRDVInBandwith.txt"
#define ALL_RDV_OUT_BANDWITH "bandwith\\rdv_bw\\allRDVOutBandwith.txt"

#define RDV_IN_BANDWITH0 "bandwith\\rdv_bw\\RDV0InBandwith.txt"
#define RDV_IN_BANDWITH1 "bandwith\\rdv_bw\\RDV1InBandwith.txt"
#define RDV_IN_BANDWITH2 "bandwith\\rdv_bw\\RDV2InBandwith.txt"
#define RDV_IN_BANDWITH3 "bandwith\\rdv_bw\\RDV3InBandwith.txt"

#define RDV_OUT_BANDWITH0 "bandwith\\rdv_bw\\RDV0OutBandwith.txt"
#define RDV_OUT_BANDWITH1 "bandwith\\rdv_bw\\RDV1OutBandwith.txt"
#define RDV_OUT_BANDWITH2 "bandwith\\rdv_bw\\RDV2OutBandwith.txt"
#define RDV_OUT_BANDWITH3 "bandwith\\rdv_bw\\RDV3OutBandwith.txt"

#define ALL_EXTV_IN_BANDWITH "bandwith\\extv_bw\\allEXTVInBandwith.txt"
#define ALL_EXTV_OUT_BANDWITH "bandwith\\extv_bw\\allEXTVOutBandwith.txt"

#define EXTV_IN_BANDWITH0 "bandwith\\extv_bw\\EXTV0InBandwith.txt"
#define EXTV_IN_BANDWITH1 "bandwith\\extv_bw\\EXTV1InBandwith.txt"
#define EXTV_IN_BANDWITH2 "bandwith\\extv_bw\\EXTV2InBandwith.txt"
#define EXTV_IN_BANDWITH3 "bandwith\\extv_bw\\EXTV3InBandwith.txt"
#define EXTV_IN_BANDWITH4 "bandwith\\extv_bw\\EXTV4InBandwith.txt"
#define EXTV_IN_BANDWITH5 "bandwith\\extv_bw\\EXTV5InBandwith.txt"
#define EXTV_IN_BANDWITH6 "bandwith\\extv_bw\\EXTV6InBandwith.txt"
#define EXTV_IN_BANDWITH7 "bandwith\\extv_bw\\EXTV7InBandwith.txt"

#define EXTV_OUT_BANDWITH0 "bandwith\\extv_bw\\EXTV0OutBandwith.txt"
#define EXTV_OUT_BANDWITH1 "bandwith\\extv_bw\\EXTV1OutBandwith.txt"
#define EXTV_OUT_BANDWITH2 "bandwith\\extv_bw\\EXTV2OutBandwith.txt"
#define EXTV_OUT_BANDWITH3 "bandwith\\extv_bw\\EXTV3OutBandwith.txt"
#define EXTV_OUT_BANDWITH4 "bandwith\\extv_bw\\EXTV4OutBandwith.txt"
#define EXTV_OUT_BANDWITH5 "bandwith\\extv_bw\\EXTV5OutBandwith.txt"
#define EXTV_OUT_BANDWITH6 "bandwith\\extv_bw\\EXTV6OutBandwith.txt"
#define EXTV_OUT_BANDWITH7 "bandwith\\extv_bw\\EXTV7OutBandwith.txt"

#define ALL_MAT_IN_BANDWITH "bandwith\\mat_bw\\allMATInBandwith.txt"
#define ALL_MAT_OUT_BANDWITH "bandwith\\mat_bw\\allMATOutBandwith.txt"

#define MAT_IN_BANDWITH0 "bandwith\\mat_bw\\MAT0InBandwith.txt"
#define MAT_IN_BANDWITH1 "bandwith\\mat_bw\\MAT1InBandwith.txt"
#define MAT_IN_BANDWITH2 "bandwith\\mat_bw\\MAT2InBandwith.txt"
#define MAT_IN_BANDWITH3 "bandwith\\mat_bw\\MAT3InBandwith.txt"
#define MAT_IN_BANDWITH4 "bandwith\\mat_bw\\MAT4InBandwith.txt"
#define MAT_IN_BANDWITH5 "bandwith\\mat_bw\\MAT5InBandwith.txt"
#define MAT_IN_BANDWITH6 "bandwith\\mat_bw\\MAT6InBandwith.txt"
#define MAT_IN_BANDWITH7 "bandwith\\mat_bw\\MAT7InBandwith.txt"

#define MAT_OUT_BANDWITH0 "bandwith\\mat_bw\\MAT0OutBandwith.txt"
#define MAT_OUT_BANDWITH1 "bandwith\\mat_bw\\MAT1OutBandwith.txt"
#define MAT_OUT_BANDWITH2 "bandwith\\mat_bw\\MAT2OutBandwith.txt"
#define MAT_OUT_BANDWITH3 "bandwith\\mat_bw\\MAT3OutBandwith.txt"
#define MAT_OUT_BANDWITH4 "bandwith\\mat_bw\\MAT4OutBandwith.txt"
#define MAT_OUT_BANDWITH5 "bandwith\\mat_bw\\MAT5OutBandwith.txt"
#define MAT_OUT_BANDWITH6 "bandwith\\mat_bw\\MAT6OutBandwith.txt"
#define MAT_OUT_BANDWITH7 "bandwith\\mat_bw\\MAT7OutBandwith.txt"

#define RBUFFER_IN_BANDWITH "bandwith\\buffer_bw\\RbufferInBandwith.txt"
#define CBUFFER_IN_BANDWITH "bandwith\\buffer_bw\\CbufferInBandwith.txt"
#define MBUFFER_IN_BANDWITH "bandwith\\buffer_bw\\MbufferInBandwith.txt"
#define BUFFER0_IN_BANDWITH "bandwith\\buffer_bw\\buffer0InBandwith.txt"
#define BUFFER1_IN_BANDWITH "bandwith\\buffer_bw\\buffer1InBandwith.txt"
#define BUFFER2_IN_BANDWITH "bandwith\\buffer_bw\\buffer2InBandwith.txt"

#define RBUFFER_OUT_BANDWITH "bandwith\\buffer_bw\\RbufferOutBandwith.txt"
#define CBUFFER_OUT_BANDWITH "bandwith\\buffer_bw\\CbufferOutBandwith.txt"
#define MBUFFER_OUT_BANDWITH "bandwith\\buffer_bw\\MbufferOutBandwith.txt"
#define BUFFER0_OUT_BANDWITH "bandwith\\buffer_bw\\buffer0OutBandwith.txt"
#define BUFFER1_OUT_BANDWITH "bandwith\\buffer_bw\\buffer1OutBandwith.txt"
#define BUFFER2_OUT_BANDWITH "bandwith\\buffer_bw\\buffer2OutBandwith.txt"

#define ADD_OP_NUM "bandwith\\arithmetic_num\\addNum.txt"
#define MUL_OP_NUM "bandwith\\arithmetic_num\\mulNum.txt"

#define MEM_IN_BANDWITH_FILE "bandwith\\mem_bw\\memInBandwith.txt"
#define MEM_OUT_BANDWITH_FILE "bandwith\\mem_bw\\memOutBandwith.txt"

extern void open_file_bw();
extern void close_file_bw();
extern void print_procedure_bw();

#endif /* _PRINT_BANDWITH_H */
