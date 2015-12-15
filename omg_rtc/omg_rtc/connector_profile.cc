// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "connector_profile.h"

namespace breeze_rtm
{
namespace omg_rtc
{
ConnectorProfile::ConnectorProfile()
{
	port_id_list_ = new std::list<UniqueIdentifier>();
}

ConnectorProfile::~ConnectorProfile()
{
	delete port_id_list_;
}

std::string ConnectorProfile::name() const
{
	return name_;
}

void ConnectorProfile::name(const std::string& name)
{
	name_ = name;
}

UniqueIdentifier ConnectorProfile::id() const
{
	return id_;
}

void ConnectorProfile::id(const UniqueIdentifier& id)
{
	id_ = id;
}

void ConnectorProfile::AddPortId(const UniqueIdentifier& port_id) const
{
	port_id_list_->push_back(port_id);
}

void ConnectorProfile::RemovePortId(const UniqueIdentifier& port_id) const
{
	port_id_list_->remove(port_id);
}

std::list<UniqueIdentifier> *ConnectorProfile::GetPortIds() const
{
	return new std::list<UniqueIdentifier>(*port_id_list_);
}
}
}

