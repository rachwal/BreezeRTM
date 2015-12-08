// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_H_
#define OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_H_

#include "life_cycle_state.h"
#include "execution_kind.h"

#include "../../types/omg_rtc/return_code_t.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class LightweightRTObject;

class ExecutionContext
{
	public:
	virtual ~ExecutionContext() {}

	virtual bool is_running() = 0;
	virtual ReturnCode_t start() = 0;
	virtual ReturnCode_t stop() = 0;
	virtual double get_rate() = 0;
	virtual ReturnCode_t set_rate(double rate) = 0;

	virtual ReturnCode_t add_component(LightweightRTObject* comp) = 0;
	virtual ReturnCode_t remove_component(LightweightRTObject* comp) = 0;
	virtual ReturnCode_t activate_component(LightweightRTObject* comp) = 0;
	virtual ReturnCode_t deactivate_component(LightweightRTObject* comp) = 0;
	virtual ReturnCode_t reset_component(LightweightRTObject* comp) = 0;
	virtual LifeCycleState get_component_state(LightweightRTObject* comp) = 0;

	virtual ExecutionKind get_kind() = 0;
};
}
}

#endif

