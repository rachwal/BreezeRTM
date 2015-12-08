// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_OBJECT_MULTI_MODE_COMPONENT_ACTION_H_
#define OMG_RTC_OBJECT_MULTI_MODE_COMPONENT_ACTION_H_

#include "../../types/omg_rtc/return_code_t.h"
#include "../../execution_context/omg_rtc/execution_context_handle_t.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class MultiModeComponentAction
{
	public:
	virtual ~MultiModeComponentAction() {}

	virtual ReturnCode_t on_mode_changed(ExecutionContextHandle_t exec_context) = 0;
};
}
}

#endif

