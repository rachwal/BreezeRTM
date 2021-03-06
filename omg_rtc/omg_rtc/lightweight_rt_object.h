// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_LIGHTWEIGHT_RT_OBJECT_H_
#define OMG_RTC_LIGHTWEIGHT_RT_OBJECT_H_

#include "component_action.h"
#include "execution_context.h"
#include "unique_identifier.h"

#include <map>
#include <list>

namespace breeze_rtm
{
namespace omg_rtc
{
class LightweightRTObject : public ComponentAction
{
	public:
	virtual ~LightweightRTObject() {}

	virtual ReturnCode_t Initialize(const UniqueIdentifier& execution_context_id) = 0;
	virtual ReturnCode_t Finalize() = 0;
	virtual bool IsAlive(const UniqueIdentifier& execution_context_id) = 0;
	virtual ReturnCode_t Exit() = 0;
	virtual ExecutionContextHandle_t AttachContext(const UniqueIdentifier& execution_context_id) = 0;
	virtual ReturnCode_t DetachContext(ExecutionContextHandle_t handle) = 0;
	virtual ExecutionContext *GetContext(ExecutionContextHandle_t handle) = 0;
	virtual std::list<UniqueIdentifier> *GetOwnedContexts() = 0;
	virtual std::map<ExecutionContextHandle_t, UniqueIdentifier> *GetParticipatingContexts() = 0;
	virtual ExecutionContextHandle_t GetContextHandle(const UniqueIdentifier& execution_context_id) = 0;
};
}
}

#endif

