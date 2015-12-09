// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "rt_logging_object_stub.h"

namespace breeze_rtm
{
namespace stubs
{
RTLoggingObjectStub::RTLoggingObjectStub(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service, omg_rtc::Logger* logger) : RTLoggingObject(execution_context_service, port_service, logger)
{
	profile_.instance_name = "stub";
}
}
}

