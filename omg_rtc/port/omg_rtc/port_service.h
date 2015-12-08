// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_PORT_PORT_SERVICE_H_
#define OMG_RTC_PORT_PORT_SERVICE_H_

#include "port_profile.h"

#include "../../common/omg_rtc/service_interface.h"
#include "../../connector/omg_rtc/connector_profile.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class PortService : public ServiceInterface<ConnectorProfile>
{
	public:
	virtual PortProfile *get_port_profile() = 0;
	virtual ListInterface<ConnectorProfile> *get_connector_profiles() = 0;
	virtual ConnectorProfile *get_connector_profile(const UniqueIdentifier connector_id) = 0;
};
}
}

#endif

