// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_EXECUTION_CONTEXT_SERVICE_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_EXECUTION_CONTEXT_SERVICE_STUB_H_

#include <breeze_rtm/execution_context_service.h>

namespace breeze_rtm
{
namespace stubs
{
class ExecutionContextServiceStub : public execution_context::ExecutionContextService
{
	public:
	ExecutionContextServiceStub();

	omg_rtc::ExecutionContextProfile *get_profile() override;;
};
}
}

#endif

