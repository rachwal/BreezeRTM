// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_COMPONENT_COMPONENT_PROFILE_H_
#define OMG_RTC_COMPONENT_COMPONENT_PROFILE_H_

#include <string>

#include "../../connector/omg_rtc/connector_profile.h"
#include "../../object/omg_rtc/rt_object.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ComponentProfile
{
	public:
	ComponentProfile() : parent(nullptr)
	{
		port_profiles_ = new std::list<ConnectorProfile>();
	}

	std::string instance_name() const
	{
		return instance_name_;
	};

	void instance_name(std::string value)
	{
		instance_name_ = value;
	};

	std::string type_name() const
	{
		return type_name_;
	};

	void type_name(std::string value)
	{
		type_name_ = value;
	};

	std::string description() const
	{
		return description_;
	};

	void description(std::string value)
	{
		description_ = value;
	};

	std::string version() const
	{
		return version_;
	};

	void version(std::string value)
	{
		version_ = value;
	};

	std::string vendor() const
	{
		return version_;
	};

	void vendor(std::string value)
	{
		version_ = value;
	};

	std::string category() const
	{
		return category_;
	};

	void category(std::string value)
	{
		category_ = value;
	};

	std::list<ConnectorProfile> *port_profiles() const
	{
		return port_profiles_;
	}

	private:
	std::string instance_name_;
	std::string type_name_;
	std::string description_;
	std::string version_;
	std::string vendor_;
	std::string category_;

	std::list<ConnectorProfile>* port_profiles_;
	RTObject* parent;
};
}
}

#endif

