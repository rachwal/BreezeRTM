// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_PROFILE_H_
#define OMG_RTC_EXECUTION_CONTEXT_PROFILE_H_

#include "execution_kind.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class RTObject;

struct ExecutionContextProfile
{
	ExecutionKind kind;
	double rate;
};
}
}

#endif

