// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_PORT_PORT_INTERFACE_PROFILE_H_
#define OMG_RTC_PORT_PORT_INTERFACE_PROFILE_H_

#include "port_interface_polarity.h"

#include <string>

namespace breeze_rtm
{
namespace omg_rtc
{
struct PortInterfaceProfile
{
	std::string instance_name;
	std::string type_name;
	PortInterfacePolarity polarity;
};
}
}

#endif

