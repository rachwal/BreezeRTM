// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_PORT_PORT_LOGGING_H_
#define BREEZE_RTM_PORT_PORT_LOGGING_H_

#include "port.h"

#include <omg_rtc/logger.h>

namespace breeze_rtm
{
namespace port
{
class PortLogging : public Port
{
	public:
	virtual omg_rtc::ReturnCode_t Connect(omg_rtc::ConnectorProfile* connector_profile) override;
	virtual omg_rtc::ReturnCode_t Disconnect(const omg_rtc::UniqueIdentifier& connector_id) override;
	virtual omg_rtc::ReturnCode_t NotifyConnect(omg_rtc::ConnectorProfile* connector_profile) override;
	virtual omg_rtc::ReturnCode_t NotifyDisconnect(const omg_rtc::UniqueIdentifier& connector_id) override;
	virtual omg_rtc::ReturnCode_t DisconnectAll() override;

	protected:
	explicit PortLogging(const omg_rtc::UniqueIdentifier id, const omg_rtc::PortService* port_service, omg_rtc::ConnectorProfileService* connector_profile_service, omg_rtc::Logger* logger);

	omg_rtc::Logger* logger_;
};
}
}

#endif

