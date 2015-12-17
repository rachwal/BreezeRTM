// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "execution_context_service_stub.h"
#include "execution_context_stub.h"
#include "lightweight_rt_object_service_stub.h"
#include "port_service_stub.h"
#include "connector_profile_service_stub.h"

namespace breeze_rtm
{
namespace stubs
{
ExecutionContextServiceStub::ExecutionContextServiceStub() : lightweight_rt_object_service_(nullptr)
{
	execution_context_map_ = new std::map<omg_rtc::UniqueIdentifier, omg_rtc::ExecutionContext*>();
}

ExecutionContextServiceStub::~ExecutionContextServiceStub()
{
	auto begin = execution_context_map_->begin();
	auto end = execution_context_map_->end();
	execution_context_map_->erase(begin, end);
	delete execution_context_map_;
}

ExecutionContextServiceStub *ExecutionContextServiceStub::CreateServiceStub()
{
	auto connector_profile_service = new ConnectorProfileServiceStub();
	auto port_service = new PortServiceStub();
	port_service->AttachConnectorProfileService(connector_profile_service);

	auto lightweight_rt_object_service = new LightweightRTObjectServiceStub();
	lightweight_rt_object_service->AttachPortService(port_service);

	auto execution_context_service = new ExecutionContextServiceStub();
	execution_context_service->AttachLightweightRTObjectService(lightweight_rt_object_service);
	lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);

	return execution_context_service;
}

omg_rtc::ExecutionContext *ExecutionContextServiceStub::Create(const omg_rtc::UniqueIdentifier& id) const
{
	auto new_execution_context = new ExecutionContextStub(this, lightweight_rt_object_service_);
	new_execution_context->profile()->id = id;
	execution_context_map_->operator[](id) = new_execution_context;

	return Retrieve(id);
}

omg_rtc::ExecutionContext *ExecutionContextServiceStub::Retrieve(const omg_rtc::UniqueIdentifier& id) const
{
	return execution_context_map_->operator[](id);
}

void ExecutionContextServiceStub::Update(const omg_rtc::UniqueIdentifier& id, const omg_rtc::ExecutionContext& execution_context) const {}

void ExecutionContextServiceStub::Destroy(const omg_rtc::UniqueIdentifier& id) const { }

void ExecutionContextServiceStub::AttachLightweightRTObjectService(omg_rtc::LightweightRTObjectService* lightweight_rt_object_service)
{
	lightweight_rt_object_service_ = lightweight_rt_object_service;
}
}
}

