// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_FSM_FSM_SERVICE_H_
#define OMG_RTC_FSM_FSM_SERVICE_H_

#include "fsm_profile.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class FsmService
{
	public:
	virtual ~FsmService() {}

	virtual FsmProfile *get_fsm_profile() = 0;
	virtual ReturnCode_t set_fsm_profile(const FsmProfile& fsm_profile) = 0;
};
}
}

#endif

