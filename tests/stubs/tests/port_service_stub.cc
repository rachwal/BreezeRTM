#include "port_service_stub.h"
#include "port_stub.h"
#include "port_logging_stub.h"

namespace breeze_rtm
{
namespace stubs
{
PortServiceStub::PortServiceStub(omg_rtc::ConnectorProfileService* connector_profile_service) : connector_profile_service_(connector_profile_service)
{
	ports_ = new std::map<omg_rtc::UniqueIdentifier, omg_rtc::Port*>();
}

PortServiceStub::~PortServiceStub()
{
	auto begin = ports_->begin();
	auto end = ports_->end();
	ports_->erase(begin, end);
	delete ports_;
}

omg_rtc::Port *PortServiceStub::Create(const omg_rtc::UniqueIdentifier& id) const
{
	auto new_port = new PortStub(id, this, connector_profile_service_);
	ports_->operator[](id) = new_port;

	return Retrieve(id);
}

omg_rtc::Port *PortServiceStub::Create(const std::string& name, const omg_rtc::UniqueIdentifier& id, omg_rtc::Logger* logger) const
{
	auto new_port = new PortLoggingStub(id, this, connector_profile_service_, logger);
	new_port->name(name);

	ports_->operator[](id) = new_port;

	return Retrieve(id);
}

omg_rtc::Port *PortServiceStub::Retrieve(const omg_rtc::UniqueIdentifier& id) const
{
	return ports_->operator[](id);
}

void PortServiceStub::Update(const omg_rtc::UniqueIdentifier& id, const omg_rtc::Port& port) const { }

void PortServiceStub::Destroy(const omg_rtc::UniqueIdentifier& id) const
{
	ports_->erase(id);
}
}
}

