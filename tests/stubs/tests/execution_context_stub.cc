// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "execution_context_stub.h"

namespace breeze_rtm
{
namespace stubs
{
ExecutionContextStub::ExecutionContextStub()
{
	profile_.kind = omg_rtc::ExecutionKind::PERIODIC;
	profile_.owner = nullptr;
}

omg_rtc::ExecutionContextProfile *ExecutionContextStub::get_profile()
{
	return &profile_;
}
}
}

