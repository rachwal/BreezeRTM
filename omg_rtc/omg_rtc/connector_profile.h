// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_CONNECTOR_PROFILE_H_
#define OMG_RTC_CONNECTOR_PROFILE_H_

#include <string>
#include <list>

#include "unique_identifier.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class ConnectorProfile
{
	public:
	ConnectorProfile();

	~ConnectorProfile();

	std::string name() const;
	void name(const std::string& name);

	UniqueIdentifier id() const;
	void id(const UniqueIdentifier& id);

	std::list<UniqueIdentifier> *GetPortIds() const;
	void AddPortId(const UniqueIdentifier& port_id) const;
	void RemovePortId(const UniqueIdentifier& port_id) const;

	private:
	std::string name_;
	UniqueIdentifier id_;
	std::list<UniqueIdentifier>* port_id_list_;
};
}
}

#endif

