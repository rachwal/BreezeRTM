// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "execution_context_stub.h"

namespace breeze_rtm
{
namespace stubs
{
ExecutionContextStub::ExecutionContextStub(const omg_rtc::LightweightRTObjectService* lightweight_rt_object_service): ExecutionContext(lightweight_rt_object_service)
{
	profile_->kind = omg_rtc::ExecutionKind::PERIODIC;
}

omg_rtc::ExecutionContextProfile *ExecutionContextStub::profile()
{
	return profile_;
}
}
}

