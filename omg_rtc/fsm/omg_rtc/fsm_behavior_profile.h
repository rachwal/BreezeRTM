// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_FSM_FSM_BEHAVIOR_PROFILE_H_
#define OMG_RTC_FSM_FSM_BEHAVIOR_PROFILE_H_

#include "fsm_component_action.h"

#include "../../types/omg_rtc/unique_identifier.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class FsmBehaviorProfile
{
	public:
	FsmComponentAction* comp;
	UniqueIdentifier id;
};
}
}

#endif

