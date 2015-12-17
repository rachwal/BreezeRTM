// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "port_profile.h"

namespace breeze_rtm
{
namespace omg_rtc
{
PortProfile::PortProfile(std::string name): name_(name)
{
	connector_id_list_ = new std::list<UniqueIdentifier>();
}

PortProfile::~PortProfile()
{
	delete connector_id_list_;
}

std::string PortProfile::name() const
{
	return name_;
}

void PortProfile::name(const std::string& name)
{
	name_ = name;
}

std::list<UniqueIdentifier> *PortProfile::connector_id_list() const
{
	return new std::list<UniqueIdentifier>(*connector_id_list_);
}

void PortProfile::AddConnectorProfileId(const UniqueIdentifier& profile_id) const
{
	connector_id_list_->push_back(profile_id);
}

void PortProfile::RemoveConnectorProfileId(const UniqueIdentifier& profile_id) const
{
	connector_id_list_->remove(profile_id);
}
}
}

