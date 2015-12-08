// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_CONNECTOR_CONNECTOR_PROFILE_H_
#define OMG_RTC_CONNECTOR_CONNECTOR_PROFILE_H_

#include <string>

#include "../../common/omg_rtc/service_interface.h"
#include "../../types/omg_rtc/unique_identifier.h"
#include "../../types/omg_rtc/nv_list.h"

namespace breeze_rtm
{
namespace omg_rtc
{
struct ConnectorProfile
{
	std::string name;
	UniqueIdentifier connector_id;
	ListInterface<ServiceInterface<ConnectorProfile>>* ports;
	NVList properties;
};
}
}

#endif

