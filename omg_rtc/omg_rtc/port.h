// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_PORT_H_
#define OMG_RTC_PORT_H_

#include "port_profile.h"

#include <list>

namespace breeze_rtm
{
namespace omg_rtc
{
class Port :public PortInterface
{
	public:
	virtual ~Port() {}

	virtual PortProfile *port_profile() = 0;
	virtual UniqueIdentifier id() const = 0;

	virtual std::list<UniqueIdentifier> *Port::GetConnectorProfiles() = 0;
	virtual ConnectorProfile *GetConnectorProfile(const UniqueIdentifier& connector_id) = 0;
};
}
}

#endif

