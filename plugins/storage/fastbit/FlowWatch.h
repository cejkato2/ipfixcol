/*
 * \file FlowWatch.h
 * \author Petr Kramolis <kramolis@cesnet.cz>
 * \brief class for flows and SQ numbers check
 *
 * Copyright (C) 2012 CESNET, z.s.p.o.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is, and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */
#ifndef FLOWWATCH_H_
#define FLOWWATCH_H_

#include <stdio.h>
#include <stdlib.h>

class FlowWatch {
	enum {SQ_MAX=4294967295,SQ_BOT_LIMIT=1431655765, SQ_TOP_LIMIT=2863311530 };
	uint firstSQ_;
	uint lastSQ_;
	uint recFlows_;
	uint lastFlows_; /**< Number of flows in the last packet */
	bool reseted;
public:
	void updateSQ(uint sq);
	void addFlows(uint recFlows);
	uint exportedFlows();
	uint receivedFlows();
	void reset();
	int write(std::string dir);
	FlowWatch();
	virtual ~FlowWatch();
};

#endif /* FLOWWATCH_H_ */