// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_CONNECTOR_PROFILE_SERVICE_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_CONNECTOR_PROFILE_SERVICE_STUB_H_

#include <omg_rtc/port_service.h>
#include <omg_rtc/connector_profile_service.h>

#include <map>

namespace breeze_rtm
{
namespace stubs
{
class ConnectorProfileServiceStub : public omg_rtc::ConnectorProfileService
{
	public:
	explicit ConnectorProfileServiceStub();
	~ConnectorProfileServiceStub();

	omg_rtc::ConnectorProfile *Create(const std::string name, const omg_rtc::UniqueIdentifier& id) const override;
	omg_rtc::ConnectorProfile *Retrieve(const omg_rtc::UniqueIdentifier& id) const override;

	private:
	std::map<omg_rtc::UniqueIdentifier, omg_rtc::ConnectorProfile*>* profiles_;
};
}
}

#endif

