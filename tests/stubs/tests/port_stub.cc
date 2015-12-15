// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "port_stub.h"

namespace breeze_rtm
{
namespace stubs
{
PortStub::PortStub(const omg_rtc::UniqueIdentifier id, const omg_rtc::PortService* port_service, omg_rtc::ConnectorProfileService* connector_profile_service) : Port(id, port_service, connector_profile_service) {}
}
}

