// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_PORT_PORT_PROFILE_H_
#define OMG_RTC_PORT_PORT_PROFILE_H_

#include "port_interface_profile.h"

#include <string>

#include "../../common/omg_rtc/list_interface.h"
#include "../../common/omg_rtc/service_interface.h"
#include "../../connector/omg_rtc/connector_profile.h"
#include "../../object/omg_rtc/rt_object_interface.h"

namespace breeze_rtm
{
namespace omg_rtc
{
struct PortProfile
{
	std::string name;

	ListInterface<PortInterfaceProfile>* interfaces;
	ServiceInterface<ConnectorProfile>* port_ref;
	ListInterface<ConnectorProfile>* connector_profiles;
	RTObjectInterface* owner;
	NVList properties;
};
}
}

#endif

