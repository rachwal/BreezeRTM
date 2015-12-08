// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_FACTORY_H_
#define OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_FACTORY_H_

#include "execution_context_service.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ExecutionContextFactory
{
	public:
	virtual ~ExecutionContextFactory() {}

	virtual ExecutionContextService *Create() = 0;
};
}
}

#endif

