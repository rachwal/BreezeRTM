// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_OBJECT_MODE_CAPABLE_H_
#define OMG_RTC_OBJECT_MODE_CAPABLE_H_

#include "mode.h"

#include "../../execution_context/omg_rtc/execution_context.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ModeCapable
{
	public:
	virtual ~ModeCapable() {}

	virtual Mode *get_default_mode() = 0;
	virtual Mode *get_current_mode() = 0;
	virtual Mode *get_current_mode_in_context(ExecutionContext* exec_context) = 0;
	virtual Mode *get_pending_mode() = 0;
	virtual Mode *get_pending_mode_in_context(ExecutionContext* exec_context) = 0;

	virtual ReturnCode_t set_mode(Mode* new_mode, bool immediate) = 0;
};
}
}

#endif

