// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_RT_LOGGING_OBJECT_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_RT_LOGGING_OBJECT_STUB_H_

#include <breeze_rtm/rt_logging_object.h>

namespace breeze_rtm
{
namespace stubs
{
class RTLoggingObjectStub :public rt_object::RTLoggingObject
{
	public:
	RTLoggingObjectStub(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service, omg_rtc::Logger* logger);
};
}
}

#endif

