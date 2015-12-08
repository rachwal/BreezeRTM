// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_COMPONENT_COMPONENT_ACTION_H_
#define OMG_RTC_COMPONENT_COMPONENT_ACTION_H_

#include "../../types/omg_rtc/return_code_t.h"
#include "../../execution_context/omg_rtc/execution_context_handle_t.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ComponentAction
{
	public:
	virtual ~ComponentAction() {}

	virtual ReturnCode_t on_initialize() = 0;
	virtual ReturnCode_t on_finalize() = 0;
	virtual ReturnCode_t on_startup(ExecutionContextHandle_t exec_context) = 0;
	virtual ReturnCode_t on_shutdown(ExecutionContextHandle_t exec_context) = 0;
	virtual ReturnCode_t on_activated(ExecutionContextHandle_t exec_context) = 0;
	virtual ReturnCode_t on_deactivated(ExecutionContextHandle_t exec_context) = 0;
	virtual ReturnCode_t on_aborting(ExecutionContextHandle_t exec_context) = 0;
	virtual ReturnCode_t on_error(ExecutionContextHandle_t exec_context) = 0;
	virtual ReturnCode_t on_reset(ExecutionContextHandle_t exec_context) = 0;
};
}
}

#endif

