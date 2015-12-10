// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_PROFILE_H_
#define OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_PROFILE_H_

#include "execution_kind.h"

#include <list>

namespace breeze_rtm
{
namespace omg_rtc
{
class RTObject;

class ExecutionContextProfile
{
	public:
	ExecutionKind kind;
	double rate;
	RTObject* owner;
	std::list<RTObject*>* participants;
};
}
}

#endif

