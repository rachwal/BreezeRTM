// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "rt_logging_object_stub.h"

namespace breeze_rtm
{
namespace stubs
{
RTLoggingObjectStub::RTLoggingObjectStub(omg_rtc::Logger* logger) : RTLoggingObject(logger)
{
	profile_.instance_name = "RTLoggingObjectStub";
}
}
}

