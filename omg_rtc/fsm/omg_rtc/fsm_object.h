// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_FSM_FSM_OBJECT_H_
#define OMG_RTC_FSM_FSM_OBJECT_H_

#include <string>

#include "../../types/omg_rtc/return_code_t.h"
#include "../../execution_context/omg_rtc/execution_context_handle_t.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class FsmObject
{
	public:
	virtual ~FsmObject() {}

	virtual ReturnCode_t send_stimulus(const std::string& message, ExecutionContextHandle_t exec_context) = 0;
};
}
}

#endif

