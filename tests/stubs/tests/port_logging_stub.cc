#include "port_logging_stub.h"

namespace breeze_rtm
{
namespace stubs
{
PortLoggingStub::PortLoggingStub(const omg_rtc::UniqueIdentifier id, const omg_rtc::PortService* port_service, omg_rtc::ConnectorProfileService* connector_profile_service, omg_rtc::Logger* logger) : PortLogging(id, port_service, connector_profile_service, logger) { }

void PortLoggingStub::name(const std::string name) const
{
	profile_->name(name);
}
}
}

