// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_COMPONENT_ACTION_H_
#define OMG_RTC_COMPONENT_ACTION_H_

#include "return_code_t.h"
#include "execution_context_handle_t.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ComponentAction
{
	public:
	virtual ~ComponentAction() {}

	virtual ReturnCode_t OnInitialize() = 0;
	virtual ReturnCode_t OnFinalize() = 0;
	virtual ReturnCode_t OnStartup(ExecutionContextHandle_t handle) = 0;
	virtual ReturnCode_t OnShutdown(ExecutionContextHandle_t handle) = 0;
	virtual ReturnCode_t OnActivated(ExecutionContextHandle_t handle) = 0;
	virtual ReturnCode_t OnDeactivated(ExecutionContextHandle_t handle) = 0;
	virtual ReturnCode_t OnAborting(ExecutionContextHandle_t handle) = 0;
	virtual ReturnCode_t OnError(ExecutionContextHandle_t handle) = 0;
	virtual ReturnCode_t OnReset(ExecutionContextHandle_t handle) = 0;
};
}
}

#endif

