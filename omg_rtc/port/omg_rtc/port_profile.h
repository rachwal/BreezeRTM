// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_PORT_PORT_PROFILE_H_
#define OMG_RTC_PORT_PORT_PROFILE_H_

#include "port_interface_profile.h"
#include "port_interface.h"

#include <string>
#include <list>

#include "../../object/omg_rtc/rt_object.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class PortProfile
{
	public:
	std::string name;

	std::list<PortInterfaceProfile>* interfaces;
	PortInterface* port_ref;
	std::list<ConnectorProfile>* connector_profiles;
	RTObject* owner;
};
}
}

#endif

