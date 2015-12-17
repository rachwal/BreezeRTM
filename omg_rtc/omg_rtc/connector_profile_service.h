// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_CONNECTOR_PROFILE_SERVICE_H_
#define OMG_RTC_CONNECTOR_PROFILE_SERVICE_H_

#include "connector_profile.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ConnectorProfileService
{
	public:
	virtual ~ConnectorProfileService() {}

	virtual ConnectorProfile *Create(const std::string name, const UniqueIdentifier& id) const = 0;
	virtual ConnectorProfile *Retrieve(const UniqueIdentifier& id) const = 0;
};
}
}

#endif

