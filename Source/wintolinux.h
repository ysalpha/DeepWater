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

#ifndef _WIN_TO_LINUX_H
#define _WIN_TO_LINUX_H

#ifndef _MSC_VER
#include <sys/io.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
typedef int errno_t;
#define CLK_TCK CLOCKS_PER_SEC
inline
char* strtok_s(char* s,const char* delm,char** context)
{
      return strtok_r(s,delm,context);
}

extern errno_t gmtime_s(struct tm* tm_time,time_t *c_time);
extern errno_t fopen_s(FILE** fp,const char* filename,const char* mode);
extern char* itoa(int num, char* str, int base);
extern char* ltoa(long int num, char* str, int base);

#else
#include <io.h>
#endif
#endif    /* wintolinux.h */
