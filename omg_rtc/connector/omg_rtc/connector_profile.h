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
	ConnectorProfile(std::string name, UniqueIdentifier id) : name_(name), id_(id)
	{
		ports_ = new std::list<PortInterface*>();
	}

	~ConnectorProfile()
	{
		delete ports_;
	}

	std::string name() const
	{
		return name_;
	}

	UniqueIdentifier id() const
	{
		return id_;
	}

	std::list<PortInterface*> *ports() const
	{
		return ports_;
	}

	void AddPort(PortInterface* port) const
	{
		ports_->push_back(port);
	};

	void RemovePort(PortInterface* port) const
	{
		ports_->remove(port);
	};

	private:
	std::string name_;
	UniqueIdentifier id_;
	std::list<PortInterface*>* ports_;
};
}
}

#endif

