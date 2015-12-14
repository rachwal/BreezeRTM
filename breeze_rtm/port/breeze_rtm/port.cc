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
	profile_ = new omg_rtc::PortProfile("default");
}

Port::~Port()
{
	delete profile_;
}

omg_rtc::ReturnCode_t Port::connect(omg_rtc::ConnectorProfile* profile)
{
	if (is_connected(profile->id()))
	{
		return omg_rtc::RTC_OK;
	}

	profile_->add_connector_profile(profile);

	notify_connect(profile);

	auto ports = profile->ports();
	for (auto port = ports->begin(); port != ports->end(); ++port)
	{
		if (!(*port)->is_connected(profile->id()))
		{
			(*port)->connect(profile);
		}
	}

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::disconnect(const omg_rtc::UniqueIdentifier& connector_id)
{
	auto profile = get_connector_profile(connector_id);
	if (!profile)
	{
		return omg_rtc::RTC_OK;
	}

	auto ports = profile->ports();

	profile_->remove_connector_profile(connector_id);

	notify_disconnect(connector_id);

	for (auto port = ports->begin(); port != ports->end(); ++port)
	{
		if ((*port)->is_connected(profile->id()))
		{
			(*port)->disconnect(connector_id);
		}
	}

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::notify_connect(omg_rtc::ConnectorProfile* profile)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::notify_disconnect(const omg_rtc::UniqueIdentifier& connector_id)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t Port::disconnect_all()
{
	return omg_rtc::RTC_OK;
}

bool Port::is_connected(const omg_rtc::UniqueIdentifier& connector_id)
{
	if (get_connector_profile(connector_id))
	{
		return true;
	}
	return false;
}

omg_rtc::PortProfile *Port::get_port_profile()
{
	return profile_;
}

std::list<omg_rtc::ConnectorProfile*> *Port::get_connector_profiles()
{
	return nullptr;
}

omg_rtc::ConnectorProfile *Port::get_connector_profile(const omg_rtc::UniqueIdentifier& connector_id)
{
	auto profiles = profile_->connector_profiles();

	for (auto profile = profiles->begin(); profile != profiles->end(); ++profile)
	{
		if (profile->first == connector_id)
		{
			return profile->second;
		}
	}
	return nullptr;
}
}
}

