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
#include "../../connector/omg_rtc/connector_profile.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class PortProfile
{
	public:
	explicit PortProfile(std::string name) : name_(name), interfaces(nullptr), port_ref(nullptr), owner(nullptr)
	{
		connector_profiles_ = new std::map<UniqueIdentifier, ConnectorProfile*>();
	}

	std::string name() const
	{
		return name_;
	}

	void name(const std::string& name)
	{
		name_ = name;
	}

	std::map<UniqueIdentifier, ConnectorProfile*> *connector_profiles() const
	{
		return connector_profiles_;
	}

	void add_connector_profile(ConnectorProfile* profile) const
	{
		connector_profiles_->operator[](profile->id()) = profile;
	}

	void remove_connector_profile(const UniqueIdentifier connector_id) const
	{
		connector_profiles_->erase(connector_id);
	}

	private:
	std::string name_;

	std::list<PortInterfaceProfile>* interfaces;
	PortInterface* port_ref;
	std::map<UniqueIdentifier, ConnectorProfile*>* connector_profiles_;
	RTObject* owner;
};
}
}

#endif

