// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_PORT_LOGGING_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_PORT_LOGGING_STUB_H_

#include <breeze_rtm/port_logging.h>

namespace breeze_rtm
{
namespace stubs
{
class PortLoggingStub : public port::PortLogging
{
	public:
	PortLoggingStub(const omg_rtc::UniqueIdentifier id, const omg_rtc::PortService* port_service, omg_rtc::ConnectorProfileService* connector_profile_service, omg_rtc::Logger* logger);

	void name(const std::string name) const;
};
}
}

#endif

