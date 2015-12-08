// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_PORT_PORT_INTERFACE_PROFILE_LIST_H_
#define OMG_RTC_PORT_PORT_INTERFACE_PROFILE_LIST_H_

#include "port_interface_profile.h"

#include "../../common/omg_rtc/list_interface.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class PortInterfaceProfileList :public ListInterface<PortInterfaceProfile> { };
}
}

#endif

