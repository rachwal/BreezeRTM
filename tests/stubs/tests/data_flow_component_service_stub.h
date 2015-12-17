// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_DATA_FLOW_COMPONENT_SERVICE_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_DATA_FLOW_COMPONENT_SERVICE_STUB_H_

#include <omg_rtc/data_flow_component_service.h>
#include <omg_rtc/lightweight_rt_object_service.h>
#include <omg_rtc/execution_context_service.h>
#include <omg_rtc/port_service.h>

namespace breeze_rtm
{
namespace stubs
{
class DataFlowComponentServiceStub : public omg_rtc::DataFlowComponentService
{
	public:
	DataFlowComponentServiceStub();
	~DataFlowComponentServiceStub();

	omg_rtc::DataFlowComponent *Create(const omg_rtc::UniqueIdentifier& lightweight_rt_object_id) const override;
	omg_rtc::DataFlowComponent *Create(const omg_rtc::UniqueIdentifier& lightweight_rt_object_id, omg_rtc::Logger* logger) const override;
	omg_rtc::DataFlowComponent *Retrieve(const omg_rtc::UniqueIdentifier& id) const override;

	void AttachLightweightRTObjectService(omg_rtc::LightweightRTObjectService* lightweight_rt_object_service);
	void AttachExecutionContextService(omg_rtc::ExecutionContextService* execution_context_service);
	void AttachPortService(omg_rtc::PortService* port_service);

	private:
	std::map<omg_rtc::UniqueIdentifier, omg_rtc::DataFlowComponent*>* data_flow_component_map_;

	omg_rtc::LightweightRTObjectService* lightweight_rt_object_service_;
	omg_rtc::PortService* port_service_;
	omg_rtc::ExecutionContextService* execution_context_service_;
};
}
}

#endif

