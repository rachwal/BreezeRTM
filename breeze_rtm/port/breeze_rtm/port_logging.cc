// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "port_logging.h"

#include <sstream>

namespace breeze_rtm
{
namespace port
{
PortLogging::PortLogging(const omg_rtc::UniqueIdentifier id, const omg_rtc::PortService* port_service, const omg_rtc::ConnectorProfileService* connector_profile_service, omg_rtc::Logger* logger)
	: Port(id, port_service, connector_profile_service), logger_(logger) {}

omg_rtc::ReturnCode_t PortLogging::Connect(const omg_rtc::UniqueIdentifier& connector_id)
{
	std::stringstream stream;
	stream << "Connect" << "(" << connector_id << ")";
	logger_->Trace(profile_->name(), stream.str());
	return Port::Connect(connector_id);
}

omg_rtc::ReturnCode_t PortLogging::Disconnect(const omg_rtc::UniqueIdentifier& connector_id)
{
	std::stringstream stream;
	stream << "Disconnect" << "(" << connector_id << ")";
	logger_->Trace(profile_->name(), stream.str());
	return Port::Disconnect(connector_id);
}

omg_rtc::ReturnCode_t PortLogging::NotifyConnect(const omg_rtc::UniqueIdentifier& connector_id)
{
	std::stringstream stream;
	stream << "NotifyConnect" << "(" << connector_id << ")";
	logger_->Trace(profile_->name(), stream.str());
	return Port::NotifyConnect(connector_id);
}

omg_rtc::ReturnCode_t PortLogging::NotifyDisconnect(const omg_rtc::UniqueIdentifier& connector_id)
{
	std::stringstream stream;
	stream << "NotifyDisconnect" << "(" << connector_id << ")";
	logger_->Trace(profile_->name(), stream.str());
	return Port::NotifyDisconnect(connector_id);
}

omg_rtc::ReturnCode_t PortLogging::DisconnectAll()
{
	std::stringstream stream;
	stream << "DisconnectAll()";
	logger_->Trace(profile_->name(), stream.str());
	return Port::DisconnectAll();
}
}
}

