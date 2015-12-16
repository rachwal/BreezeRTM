// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "port_service_stub.h"
#include "port_stub.h"
#include "port_logging_stub.h"
#include "connector_profile_service_stub.h"

namespace breeze_rtm
{
namespace stubs
{
PortServiceStub::PortServiceStub() : connector_profile_service_(nullptr)
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

PortServiceStub *PortServiceStub::CreateServiceStub()
{
	auto connector_profile_service = new ConnectorProfileServiceStub();
	auto port_service = new PortServiceStub();
	port_service->AttachConnectorProfileService(connector_profile_service);
	return port_service;
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

void PortServiceStub::AttachConnectorProfileService(omg_rtc::ConnectorProfileService* connector_profile_service)
{
	connector_profile_service_ = connector_profile_service;
}
}
}

