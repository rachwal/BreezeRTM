// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "port.h"

namespace breeze_rtm
{
namespace port
{
Port::Port(const omg_rtc::UniqueIdentifier port_id, const omg_rtc::PortService* port_service, const omg_rtc::ConnectorProfileService* connector_profile_service) 
	: port_service_(port_service), connector_profile_service_(connector_profile_service), id_(port_id)
{
	profile_ = new omg_rtc::PortProfile(port_id);
}

Port::~Port()
{
	delete profile_;
}

omg_rtc::UniqueIdentifier Port::id() const
{
	return id_;
}

omg_rtc::ReturnCode_t Port::Connect(const omg_rtc::UniqueIdentifier& connector_id)
{
	auto profile = connector_profile_service_->Retrieve(connector_id);
	auto profile_id = profile->id();

	if (IsConnected(profile_id))
	{
		return omg_rtc::RTC_OK;
	}

	profile_->AddConnectorProfileId(profile_id);

	NotifyConnect(connector_id);

	auto port_id_list = profile->GetPortIds();
	for (auto port_id = port_id_list->begin(); port_id != port_id_list->end(); ++port_id)
	{
		auto port = port_service_->Retrieve(*port_id);
		if (!port->IsConnected(profile_id))
		{
			port->Connect(profile_id);
		}
	}
	delete port_id_list;

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::Disconnect(const omg_rtc::UniqueIdentifier& connector_id)
{
	if (!IsConnected(connector_id))
	{
		return omg_rtc::RTC_OK;
	}

	auto profile = GetConnectorProfile(connector_id);
	auto port_id_list = profile->GetPortIds();

	profile_->RemoveConnectorProfileId(connector_id);

	NotifyDisconnect(connector_id);

	for (auto port_id = port_id_list->begin(); port_id != port_id_list->end(); ++port_id)
	{
		auto port = port_service_->Retrieve(*port_id);
		if (port->IsConnected(profile->id()))
		{
			port->Disconnect(connector_id);
		}
	}
	delete port_id_list;

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::NotifyConnect(const omg_rtc::UniqueIdentifier&)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::NotifyDisconnect(const omg_rtc::UniqueIdentifier&)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::DisconnectAll()
{
	auto connector_id_list = profile_->connector_id_list();
	for (auto connector_id = connector_id_list->begin(); connector_id != connector_id_list->end(); ++connector_id)
	{
		Disconnect(*connector_id);
	}
	delete connector_id_list;

	return omg_rtc::RTC_OK;
}

bool Port::IsConnected(const omg_rtc::UniqueIdentifier& connector_id)
{
	auto connector_id_list = profile_->connector_id_list();
	for (auto id = connector_id_list->begin(); id != connector_id_list->end(); ++id)
	{
		if (*id == connector_id)
		{
			return true;
		}
	}
	delete connector_id_list;

	return false;
}

omg_rtc::PortProfile *Port::port_profile()
{
	return profile_;
}

std::list<omg_rtc::UniqueIdentifier> *Port::GetConnectorIdList()
{
	return profile_->connector_id_list();
}

omg_rtc::ConnectorProfile *Port::GetConnectorProfile(const omg_rtc::UniqueIdentifier& connector_id)
{
	return connector_profile_service_->Retrieve(connector_id);
}
}
}

