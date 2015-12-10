// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_SERVICE_H_
#define OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_SERVICE_H_

#include "execution_context.h"

#include "../../types/omg_rtc/unique_identifier.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ExecutionContextService
{
	public:
	virtual ~ExecutionContextService() {}

	virtual ExecutionContext *Create(UniqueIdentifier id) const = 0;
	virtual ExecutionContext *Retrieve(UniqueIdentifier id) const = 0;
	virtual void Update(UniqueIdentifier id, ExecutionContext* execution_context) const = 0;
	virtual void Destroy(UniqueIdentifier id) const = 0;
};
}
}

#endif

