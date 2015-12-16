// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_MODE_CAPABLE_H_
#define OMG_RTC_MODE_CAPABLE_H_

#include "mode.h"
#include "execution_context.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ModeCapable
{
	public:
	virtual ~ModeCapable() {}

	virtual Mode *GetDefaultMode() = 0;
	virtual Mode *GetCurrentMode() = 0;
	virtual Mode *GetCurrentModeInContext(ExecutionContext* exec_context) = 0;
	virtual Mode *GetPendingMode() = 0;
	virtual Mode *GetPendingModeInContext(ExecutionContext* exec_context) = 0;

	virtual ReturnCode_t SetMode(Mode* new_mode, bool immediate) = 0;
};
}
}

#endif

