// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "port_logging.h"
#include <sstream>

namespace breeze_rtm
{
namespace port
{
PortLogging::PortLogging(omg_rtc::Logger* logger) : Port(), logger_(logger) {}

omg_rtc::PortProfile *PortLogging::get_port_profile()
{
	return Port::get_port_profile();
}

std::list<omg_rtc::ConnectorProfile*> *PortLogging::get_connector_profiles()
{
	return Port::get_connector_profiles();
}

omg_rtc::ConnectorProfile *PortLogging::get_connector_profile(const omg_rtc::UniqueIdentifier& connector_id)
{
	return Port::get_connector_profile(connector_id);
}

omg_rtc::ReturnCode_t PortLogging::connect(omg_rtc::ConnectorProfile* connector_profile)
{
	std::stringstream stream;
	stream << "connect" << "(" << connector_profile->id() << ")";
	logger_->Trace(profile_->name(), stream.str());
	return Port::connect(connector_profile);
}

omg_rtc::ReturnCode_t PortLogging::disconnect(const omg_rtc::UniqueIdentifier& connector_id)
{
	std::stringstream stream;
	stream << "disconnect" << "(" << connector_id << ")";
	logger_->Trace(profile_->name(), stream.str());
	return Port::disconnect(connector_id);
}

omg_rtc::ReturnCode_t PortLogging::notify_connect(omg_rtc::ConnectorProfile* connector_profile)
{
	std::stringstream stream;
	stream << "notify_connect" << "(" << connector_profile->id() << ")";
	logger_->Trace(profile_->name(), stream.str());
	return Port::notify_connect(connector_profile);
}

omg_rtc::ReturnCode_t PortLogging::notify_disconnect(const omg_rtc::UniqueIdentifier& connector_id)
{
	std::stringstream stream;
	stream << "notify_disconnect" << "(" << connector_id << ")";
	logger_->Trace(profile_->name(), stream.str());
	return Port::notify_disconnect(connector_id);
}

omg_rtc::ReturnCode_t PortLogging::disconnect_all()
{
	std::stringstream stream;
	stream << "disconnect_all()";
	logger_->Trace(profile_->name(), stream.str());
	return Port::disconnect_all();
}
}
}

