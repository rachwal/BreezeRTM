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
	virtual omg_rtc::PortProfile *get_port_profile() override;
	virtual std::list<omg_rtc::ConnectorProfile*> *get_connector_profiles() override;
	virtual omg_rtc::ConnectorProfile *get_connector_profile(const omg_rtc::UniqueIdentifier& connector_id) override;
	virtual omg_rtc::ReturnCode_t connect(omg_rtc::ConnectorProfile* connector_profile) override;
	virtual omg_rtc::ReturnCode_t disconnect(const omg_rtc::UniqueIdentifier& connector_id) override;
	virtual omg_rtc::ReturnCode_t notify_connect(omg_rtc::ConnectorProfile* connector_profile) override;
	virtual omg_rtc::ReturnCode_t notify_disconnect(const omg_rtc::UniqueIdentifier& connector_id) override;
	virtual omg_rtc::ReturnCode_t disconnect_all() override;

	protected:
	explicit PortLogging(omg_rtc::Logger* logger);

	omg_rtc::Logger* logger_;
};
}
}

#endif

