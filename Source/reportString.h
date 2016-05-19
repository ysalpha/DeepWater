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

#ifndef _REPORT_STRING_H
#define _REPORT_STRING_H

#define REPORT_HEAD_FORMAT_ONE "//////////////////////////////////////////////////\nCopyrigth info\n(Reserved headline)\n\nfileName:pulsesim.rpt\nDate:"
#define REPORT_HEAD_FORMAT_TWO "//////////////////////////////////////////////////\n"

#define REPORT_HEAD "\nSimulation overview\n\nTotal static instruction:"
#define REPORT_HEAD_SECODE "Execution cycle:"
#define REPORT_HEAD_SECODE_BY "Simulation time (second):"

#define REPORT_BLOCK_ONE "\nA.Statistic of states of instruction execution:\n"
#define REPORT_BLOCK_ONE_HEAD "\ninsName     insNum     waitCycle     waitFuncUnitCycle     exeCycle\n"
#define REPORT_BLOCK_ONE_DATA_FORMAT "%-20s\t%-20ld\t%-20ld\t%-20ld\t%-20ld\n"

#define REPORT_BLOCK_TWO "\n\nB.Statistic of operation:\n"
#define REPORT_BLOCK_TWO_HEAD        "\nopType            num\n"
#define REPORT_BLOCK_TWO_DATA_FORMAT "%-20s\t%-20ld\n"

#define REPORT_BLOCK_THREE "\n\nC.Statistic of bandwith:\n"
#define REPORT_BLOCK_THREE_HEAD       "\nmoduleName     inBW     outBW\n"
#define RPORT_BLOCK_THREE_DATA_FORMAT    "%-20s\t%-20ld\t%-20ld\n"

#define REPORT_BLOCK_FOUR "\n\nD.Statistic of data reuse(detail description in datareuse.dr):\n"
#define REPORT_BLOCK_ROUR_HEAD "\n\n"


#endif /* _REPORT_STRING_H */
