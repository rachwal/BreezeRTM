// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_EXECUTION_CONTEXT_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_EXECUTION_CONTEXT_STUB_H_

#include <breeze_rtm/execution_context.h>

namespace breeze_rtm
{
namespace stubs
{
class ExecutionContextStub : public execution_context::ExecutionContext
{
	public:
	ExecutionContextStub();

	omg_rtc::ExecutionContextProfile *get_profile() override;;
};
}
}

#endif
