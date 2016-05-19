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

#ifndef _DATA_TYPE_MODELING_H
#define _DATA_TYPE_MODELING_H

typedef  short PS_ENT_TYPE;
typedef  short *PS_PTR_TYPE;

/* convert string to PS_ENT_TYPE */
extern PS_ENT_TYPE str2pstype(char* str);

/* convert float to PS_ENT_TYPE */
extern PS_ENT_TYPE float2pstype(char* str);

/* convert float to PS_ENT_TYPE */
extern bool floatTopstype(
	char *filename0,    /* resource file name */
	char *filename1);    /* destination file name */

/* convert PS_ENT_TYPE to float */
extern bool pstypeTofloat(
	char *filename0,    /* resource file name */
	char *filename1);    /* destination file name */

#endif /* _DATA_TYPE_MODELING_H */
