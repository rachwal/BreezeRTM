// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_LIST_H_
#define OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_LIST_H_

#include "execution_context.h"

#include "../../common/omg_rtc/list_interface.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ExecutionContextList :public ListInterface<ExecutionContext> { };
}
}

#endif

