// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_OBJECT_RT_OBJECT_INTERFACE_H_
#define OMG_RTC_OBJECT_RT_OBJECT_INTERFACE_H_

#include "../../common/omg_rtc/list_interface.h"
#include "../../common/omg_rtc/service_interface.h"
#include "../../connector/omg_rtc/connector_profile.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class RTObjectInterface
{
	public:
	virtual ~RTObjectInterface() {}

	virtual ListInterface<ServiceInterface<ConnectorProfile>> *get_ports() = 0;
};
}
}

#endif

