#include "port_logging_stub.h"

namespace breeze_rtm
{
namespace stubs
{
PortLoggingStub::PortLoggingStub(std::string name, omg_rtc::Logger* logger) : PortLogging(logger)
{
	profile_->name(name);
}
}
}

