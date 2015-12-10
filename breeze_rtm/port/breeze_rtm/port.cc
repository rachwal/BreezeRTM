// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "port.h"

namespace breeze_rtm
{
namespace port
{
Port::Port()
{
	connection_channels_ = new std::map<omg_rtc::UniqueIdentifier, omg_rtc::ConnectorProfile>();
}

Port::~Port()
{
	delete connection_channels_;
}

omg_rtc::ReturnCode_t Port::connect(omg_rtc::ConnectorProfile& connector_profile)
{
	connection_channels_->operator[](connector_profile.id) = connector_profile;

	notify_connect(connector_profile);

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::disconnect(const omg_rtc::UniqueIdentifier connector_id)
{
	connection_channels_->erase(connector_id);

	notify_disconnect(connector_id);

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::notify_connect(omg_rtc::ConnectorProfile& profile)
{
	for (auto connector_profile = profile_.connector_profiles->begin(); connector_profile != profile_.connector_profiles->end(); ++connector_profile)
	{
		for (auto port = connector_profile->ports->begin(); port != connector_profile->ports->end(); ++port)
		{
			(*port)->notify_connect(profile);
		}
	}

	profile_.connector_profiles->push_back(profile);

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::notify_disconnect(const omg_rtc::UniqueIdentifier connector_id)
{
	for (auto connector_profile = profile_.connector_profiles->begin(); connector_profile != profile_.connector_profiles->end(); ++connector_profile)
	{
		if (connector_profile->id == connector_id)
		{
			profile_.connector_profiles->erase(connector_profile);
		}
		else
		{
			for (auto port = connector_profile->ports->begin(); port != connector_profile->ports->end(); ++port)
			{
				(*port)->notify_disconnect(connector_id);
			}
		}
	}

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::disconnect_all()
{
	return omg_rtc::RTC_OK;
}

omg_rtc::PortProfile *Port::get_port_profile()
{
	return &profile_;
}

std::list<omg_rtc::ConnectorProfile> *Port::get_connector_profiles()
{
	return profile_.connector_profiles;
}

omg_rtc::ConnectorProfile *Port::get_connector_profile(const omg_rtc::UniqueIdentifier connector_id)
{
	return &connection_channels_->operator[](connector_id);
}
}
}

