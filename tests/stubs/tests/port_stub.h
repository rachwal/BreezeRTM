// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_PORT_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_PORT_STUB_H_

#include <breeze_rtm/port.h>

namespace breeze_rtm
{
namespace stubs
{
class PortStub: public port::Port
{
	public:
	PortStub(const omg_rtc::UniqueIdentifier id, const omg_rtc::PortService* port_service, const omg_rtc::ConnectorProfileService* connector_profile_service);
};
}
}

#endif

