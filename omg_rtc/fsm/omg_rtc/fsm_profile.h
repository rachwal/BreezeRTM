// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_FSM_FSM_PROFILE_H_
#define OMG_RTC_FSM_FSM_PROFILE_H_

#include "fsm_behavior_profile.h"

#include <list>

namespace breeze_rtm
{
namespace omg_rtc
{
class FsmProfile
{
	public:
	std::list<FsmBehaviorProfile>* behavior_profiles;
};
}
}

#endif

