// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_PROFILE_H_
#define OMG_RTC_EXECUTION_CONTEXT_PROFILE_H_

#include "execution_kind.h"
#include "unique_identifier.h"

namespace breeze_rtm
{
namespace omg_rtc
{
struct ExecutionContextProfile
{
	UniqueIdentifier id;
	ExecutionKind kind;
	double rate;
};
}
}

#endif

