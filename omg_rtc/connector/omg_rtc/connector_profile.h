// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_CONNECTOR_CONNECTOR_PROFILE_H_
#define OMG_RTC_CONNECTOR_CONNECTOR_PROFILE_H_

#include <string>
#include <list>

#include "../../types/omg_rtc/unique_identifier.h"
#include "../../port/omg_rtc/port_interface.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ConnectorProfile
{
	public:
	ConnectorProfile()
	{
		ports = new std::list<PortInterface*>();
	}

	~ConnectorProfile()
	{
		delete ports;
	}

	std::string name;
	UniqueIdentifier id;
	std::list<PortInterface*>* ports;
};
}
}

#endif

