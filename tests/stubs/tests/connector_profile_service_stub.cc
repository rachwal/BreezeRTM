#include "connector_profile_service_stub.h"

namespace breeze_rtm
{
namespace stubs
{
ConnectorProfileServiceStub::ConnectorProfileServiceStub()
{
	profiles_ = new std::map<omg_rtc::UniqueIdentifier, omg_rtc::ConnectorProfile*>();
}

ConnectorProfileServiceStub::~ConnectorProfileServiceStub()
{
	auto begin = profiles_->begin();
	auto end = profiles_->end();
	profiles_->erase(begin, end);
	delete profiles_;
}

omg_rtc::ConnectorProfile *ConnectorProfileServiceStub::Create(const std::string name, const omg_rtc::UniqueIdentifier& id) const
{
	auto new_profile = new omg_rtc::ConnectorProfile();
	new_profile->name(name);
	new_profile->id(id);

	profiles_->operator[](id) = new_profile;

	return Retrieve(id);
}

omg_rtc::ConnectorProfile *ConnectorProfileServiceStub::Retrieve(const omg_rtc::UniqueIdentifier& id) const
{
	return profiles_->operator[](id);
}

void ConnectorProfileServiceStub::Update(const omg_rtc::UniqueIdentifier& id, const omg_rtc::ConnectorProfile& port) const {}

void ConnectorProfileServiceStub::Destroy(const omg_rtc::UniqueIdentifier& id) const
{
	profiles_->erase(id);
}
}
}
