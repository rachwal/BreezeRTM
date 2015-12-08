// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_PROFILE_H_
#define OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_PROFILE_H_

#include "execution_kind.h"

#include "../../object/omg_rtc/rt_object.h"
#include "../../common/omg_rtc/list_interface.h"
#include "../../types/omg_rtc/nv_list.h"

namespace breeze_rtm
{
namespace omg_rtc
{
struct ExecutionContextProfile
{
	ExecutionKind kind;
	double rate;
	RTObject* owner;
	ListInterface<RTObject>* participants;
	NVList properties;
};
}
}

#endif

