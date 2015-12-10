// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_PORT_PORT_H_
#define BREEZE_RTM_PORT_PORT_H_

#include <omg_rtc/port.h>

#include <map>

namespace breeze_rtm
{
namespace port
{
class Port : public omg_rtc::Port
{
	public:
	virtual ~Port();

	virtual omg_rtc::PortProfile *get_port_profile() override;

	virtual std::list<omg_rtc::ConnectorProfile> *get_connector_profiles() override;
	virtual omg_rtc::ConnectorProfile *get_connector_profile(const omg_rtc::UniqueIdentifier connector_id) override;

	virtual omg_rtc::ReturnCode_t connect(omg_rtc::ConnectorProfile& connector_profile) override;
	virtual omg_rtc::ReturnCode_t disconnect(const omg_rtc::UniqueIdentifier connector_id) override;
	virtual omg_rtc::ReturnCode_t notify_connect(omg_rtc::ConnectorProfile& connector_profile) override;
	virtual omg_rtc::ReturnCode_t notify_disconnect(const omg_rtc::UniqueIdentifier connector_id) override;
	virtual omg_rtc::ReturnCode_t disconnect_all() override;

	protected:
	Port();

	private:
	std::map<omg_rtc::UniqueIdentifier, omg_rtc::ConnectorProfile>* connection_channels_;
	omg_rtc::PortProfile profile_;
};
}
}

#endif

