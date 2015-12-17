// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_H_
#define OMG_RTC_EXECUTION_CONTEXT_H_

#include "life_cycle_state.h"
#include "execution_kind.h"
#include "execution_context_profile.h"

#include "return_code_t.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ExecutionContext
{
	public:
	virtual ~ExecutionContext() {}

	virtual ExecutionContextProfile *profile() = 0;

	virtual bool IsRunning() = 0;

	virtual ReturnCode_t Start() = 0;
	virtual ReturnCode_t Stop() = 0;

	virtual double rate() = 0;
	virtual ReturnCode_t rate(double rate) = 0;

	virtual ReturnCode_t AddComponent(const UniqueIdentifier& component_id) = 0;
	virtual ReturnCode_t RemoveComponent(const UniqueIdentifier& component_id) = 0;
	virtual ReturnCode_t ActivateComponent(const UniqueIdentifier& component_id) = 0;
	virtual ReturnCode_t DeactivateComponent(const UniqueIdentifier& component_id) = 0;
	virtual ReturnCode_t ResetComponent(const UniqueIdentifier& component_id) = 0;

	virtual LifeCycleState component_state(const UniqueIdentifier& component_id) = 0;

	virtual ExecutionKind kind() = 0;
};
}
}

#endif

