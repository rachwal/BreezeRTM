// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_PORT_SERVICE_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_PORT_SERVICE_STUB_H_

#include <omg_rtc/port_service.h>
#include <omg_rtc/connector_profile_service.h>
#include <omg_rtc/logger.h>

#include <map>

namespace breeze_rtm
{
namespace stubs
{
class PortServiceStub : public omg_rtc::PortService
{
	public:
	PortServiceStub();
	~PortServiceStub();

	omg_rtc::Port *Create(const omg_rtc::UniqueIdentifier& id) const override;
	omg_rtc::Port *Create(const std::string&, const omg_rtc::UniqueIdentifier& id, omg_rtc::Logger*) const override;
	omg_rtc::Port *Retrieve(const omg_rtc::UniqueIdentifier& id) const override;

	void AttachConnectorProfileService(omg_rtc::ConnectorProfileService* connector_profile_service);

	private:
	std::map<omg_rtc::UniqueIdentifier, omg_rtc::Port*>* ports_;
	omg_rtc::ConnectorProfileService* connector_profile_service_;
};
}
}

#endif

