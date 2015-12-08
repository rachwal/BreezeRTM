// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_OBJECT_LIGHTWEIGHT_RT_OBJECT_H_
#define OMG_RTC_OBJECT_LIGHTWEIGHT_RT_OBJECT_H_

#include "../../component/omg_rtc/component_action.h"
#include "../../execution_context/omg_rtc/execution_context.h"

#include <map>
#include <list>

namespace breeze_rtm
{
namespace omg_rtc
{
class LightweightRTObject : public ComponentAction
{
	public:
	virtual ReturnCode_t initialize() = 0;
	virtual ReturnCode_t finalize() = 0;
	virtual bool is_alive(ExecutionContext* exec_context) = 0;
	virtual ReturnCode_t exit() = 0;
	virtual ExecutionContextHandle_t attach_context(ExecutionContext* exec_context) = 0;
	virtual ReturnCode_t detach_context(ExecutionContextHandle_t exec_handle) = 0;
	virtual ExecutionContext *get_context(ExecutionContextHandle_t exec_handle) = 0;
	virtual std::list<ExecutionContext*> *get_owned_contexts() = 0;
	virtual std::map<ExecutionContextHandle_t, ExecutionContext*> *get_participating_contexts() = 0;
	virtual ExecutionContextHandle_t get_context_handle(ExecutionContext& cxt) = 0;
};
}
}

#endif

