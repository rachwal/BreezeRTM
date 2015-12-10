// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "rt_object_stub.h"

namespace breeze_rtm
{
namespace stubs
{
RTObjectStub::RTObjectStub(omg_rtc::ExecutionContext* execution_context, omg_rtc::Port* port) : RTObject(execution_context, port)
{
	profile_.instance_name = "RTObjectStub";
}
}
}

