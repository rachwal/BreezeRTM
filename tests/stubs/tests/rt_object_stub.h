// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_RT_OBJECT_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_RT_OBJECT_STUB_H_

#include <breeze_rtm/rt_object.h>

namespace breeze_rtm
{
namespace stubs
{
class RTObjectStub :public rt_object::RTObject
{
	public:
	RTObjectStub(omg_rtc::ExecutionContext* execution_context, omg_rtc::Port* port);
};
}
}

#endif

