// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_SYSTEM_BUILDER_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_SYSTEM_BUILDER_STUB_H_

#include <omg_rtc/connector_profile_service.h>
#include <omg_rtc/port_service.h>
#include <omg_rtc/lightweight_rt_object_service.h>
#include <omg_rtc/execution_context_service.h>
#include <omg_rtc/data_flow_component_service.h>

namespace breeze_rtm
{
namespace stubs
{
class SystemBuilderStub
{
	public:
	SystemBuilderStub();
	~SystemBuilderStub();

	omg_rtc::ConnectorProfileService *connector_profile_service();
	omg_rtc::PortService *port_service();
	omg_rtc::LightweightRTObjectService *lightweight_rt_object_service();
	omg_rtc::ExecutionContextService *execution_context_service();
	omg_rtc::DataFlowComponentService *data_flow_component_service();

	private:
	void Build();

	omg_rtc::ConnectorProfileService* connector_profile_service_;
	omg_rtc::PortService* port_service_;
	omg_rtc::LightweightRTObjectService* lightweight_rt_object_service_;
	omg_rtc::ExecutionContextService* execution_context_service_;
	omg_rtc::DataFlowComponentService* data_flow_component_service_;
};
}
}

#endif

