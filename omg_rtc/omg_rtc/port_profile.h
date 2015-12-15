// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_PORT_PROFILE_H_
#define OMG_RTC_PORT_PROFILE_H_

#include "port_interface.h"

#include <string>
#include <list>

namespace breeze_rtm
{
namespace omg_rtc
{
class PortProfile
{
	public:
	explicit PortProfile(std::string name);

	~PortProfile();

	std::string name() const;

	void name(const std::string& name);

	std::list<UniqueIdentifier> *connector_id_list() const;

	void AddConnectorProfileId(const UniqueIdentifier& profile_id) const;

	void RemoveConnectorProfileId(const UniqueIdentifier& profile_id) const;

	private:
	std::string name_;
	std::list<UniqueIdentifier>* connector_id_list_;
};
}
}

#endif

