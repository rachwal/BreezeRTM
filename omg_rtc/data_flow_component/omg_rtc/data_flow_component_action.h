// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_DATA_FLOW_COMPONENT_RTC_DATA_FLOW_COMPONENT_ACTION_H_
#define OMG_DATA_FLOW_COMPONENT_RTC_DATA_FLOW_COMPONENT_ACTION_H_

#include "../../types/omg_rtc/return_code_t.h"
#include "../../execution_context/omg_rtc/execution_context_handle_t.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class DataFlowComponentAction
{
	public:
	virtual ~DataFlowComponentAction() {}

	private:
	virtual ReturnCode_t on_execute(ExecutionContextHandle_t exec_context) = 0;
	virtual ReturnCode_t on_state_update(ExecutionContextHandle_t exec_context) = 0;
	virtual ReturnCode_t on_rate_changed(ExecutionContextHandle_t exec_context) = 0;
};
}
}

#endif

