// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "data_flow_component_service_stub.h"
#include "data_flow_component_stub.h"
#include "data_flow_logging_component_stub.h"

namespace breeze_rtm
{
namespace stubs
{
DataFlowComponentServiceStub::DataFlowComponentServiceStub() : lightweight_rt_object_service_(nullptr), port_service_(nullptr), execution_context_service_(nullptr)
{
	data_flow_component_map_ = new std::map<omg_rtc::UniqueIdentifier, omg_rtc::DataFlowComponent*>();
}

DataFlowComponentServiceStub::~DataFlowComponentServiceStub()
{
	auto begin = data_flow_component_map_->begin();
	auto end = data_flow_component_map_->end();
	data_flow_component_map_->erase(begin, end);
	delete data_flow_component_map_;
}

omg_rtc::DataFlowComponent *DataFlowComponentServiceStub::Create(const omg_rtc::UniqueIdentifier& data_flow_component_id) const
{
	auto data_flow_component = new DataFlowComponentStub(execution_context_service_, port_service_);
	data_flow_component_map_->operator[](data_flow_component_id) = data_flow_component;
	lightweight_rt_object_service_->Register(data_flow_component_id, this);

	return Retrieve(data_flow_component_id);
}

omg_rtc::DataFlowComponent *DataFlowComponentServiceStub::Create(const omg_rtc::UniqueIdentifier& data_flow_component_id, omg_rtc::Logger* logger) const
{
	auto data_flow_component = new DataFlowLoggingComponentStub(execution_context_service_, port_service_, logger);
	data_flow_component_map_->operator[](data_flow_component_id) = data_flow_component;
	lightweight_rt_object_service_->Register(data_flow_component_id, this);

	return Retrieve(data_flow_component_id);
}

omg_rtc::DataFlowComponent *DataFlowComponentServiceStub::Retrieve(const omg_rtc::UniqueIdentifier& id) const
{
	return data_flow_component_map_->operator[](id);
}

void DataFlowComponentServiceStub::AttachLightweightRTObjectService(omg_rtc::LightweightRTObjectService* lightweight_rt_object_service)
{
	lightweight_rt_object_service_ = lightweight_rt_object_service;
}

void DataFlowComponentServiceStub::AttachExecutionContextService(omg_rtc::ExecutionContextService* execution_context_service)
{
	execution_context_service_ = execution_context_service;
}

void DataFlowComponentServiceStub::AttachPortService(omg_rtc::PortService* port_service)
{
	port_service_ = port_service;
}
}
}

