// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_PORT_PORT_H_
#define BREEZE_RTM_PORT_PORT_H_

#include <omg_rtc/port.h>
#include <omg_rtc/port_service.h>
#include <omg_rtc/connector_profile_service.h>

namespace breeze_rtm
{
namespace port
{
class Port : public omg_rtc::Port
{
	public:
	virtual ~Port();

	virtual omg_rtc::UniqueIdentifier id() const override;

	virtual omg_rtc::PortProfile *port_profile() override;

	virtual std::list<omg_rtc::UniqueIdentifier> *GetConnectorIdList() override;
	virtual omg_rtc::ConnectorProfile *GetConnectorProfile(const omg_rtc::UniqueIdentifier& connector_id) override;

	virtual omg_rtc::ReturnCode_t Connect(const omg_rtc::UniqueIdentifier& connector_id) override;
	virtual omg_rtc::ReturnCode_t Disconnect(const omg_rtc::UniqueIdentifier& connector_id) override;
	virtual omg_rtc::ReturnCode_t NotifyConnect(const omg_rtc::UniqueIdentifier& connector_id) override;
	virtual omg_rtc::ReturnCode_t NotifyDisconnect(const omg_rtc::UniqueIdentifier& connector_id) override;
	virtual omg_rtc::ReturnCode_t DisconnectAll() override;

	virtual bool IsConnected(const omg_rtc::UniqueIdentifier& connector_id) override;

	protected:
	Port(const omg_rtc::UniqueIdentifier port_id, const omg_rtc::PortService* port_service, const omg_rtc::ConnectorProfileService* connector_profile_service);

	omg_rtc::PortProfile* profile_;

	private:
	const omg_rtc::PortService* port_service_;
	const omg_rtc::ConnectorProfileService* connector_profile_service_;

	omg_rtc::UniqueIdentifier id_;
};
}
}

#endif

