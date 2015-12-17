// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "system_builder_stub.h"
#include "connector_profile_service_stub.h"
#include "port_service_stub.h"
#include "lightweight_rt_object_service_stub.h"
#include "execution_context_service_stub.h"
#include "data_flow_component_service_stub.h"

namespace breeze_rtm
{
namespace stubs
{
SystemBuilderStub::SystemBuilderStub()
{
	connector_profile_service_ = nullptr;
	port_service_ = nullptr;
	lightweight_rt_object_service_ = nullptr;
	execution_context_service_ = nullptr;
	data_flow_component_service_ = nullptr;
};

SystemBuilderStub::~SystemBuilderStub()
{
	delete connector_profile_service_;
	delete port_service_;
	delete lightweight_rt_object_service_;
	delete execution_context_service_;
	delete data_flow_component_service_;
}

omg_rtc::ConnectorProfileService *SystemBuilderStub::connector_profile_service()
{
	if (!connector_profile_service_)
	{
		this->Build();
	}
	return connector_profile_service_;
};

omg_rtc::PortService *SystemBuilderStub::port_service()
{
	if (!port_service_)
	{
		this->Build();
	}
	return port_service_;
};

omg_rtc::LightweightRTObjectService *SystemBuilderStub::lightweight_rt_object_service()
{
	if (!lightweight_rt_object_service_)
	{
		this->Build();
	}
	return lightweight_rt_object_service_;
};

omg_rtc::ExecutionContextService *SystemBuilderStub::execution_context_service()
{
	if (!execution_context_service_)
	{
		this->Build();
	}
	return execution_context_service_;
};

omg_rtc::DataFlowComponentService *SystemBuilderStub::data_flow_component_service()
{
	if (!data_flow_component_service_)
	{
		this->Build();
	}
	return data_flow_component_service_;
};

void SystemBuilderStub::Build()
{
	connector_profile_service_ = new ConnectorProfileServiceStub();

	auto port_service = new PortServiceStub();
	port_service->AttachConnectorProfileService(connector_profile_service_);
	port_service_ = port_service;

	auto lightweight_rt_object_service = new LightweightRTObjectServiceStub();
	lightweight_rt_object_service->AttachPortService(port_service);
	lightweight_rt_object_service_ = lightweight_rt_object_service;

	auto execution_context_service = new ExecutionContextServiceStub();
	execution_context_service->AttachLightweightRTObjectService(lightweight_rt_object_service);
	lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
	execution_context_service_ = execution_context_service;

	auto data_flow_component_service = new DataFlowComponentServiceStub();
	data_flow_component_service->AttachExecutionContextService(execution_context_service);
	data_flow_component_service->AttachLightweightRTObjectService(lightweight_rt_object_service);
	data_flow_component_service->AttachPortService(port_service);
	data_flow_component_service_ = data_flow_component_service;
};
}
}

