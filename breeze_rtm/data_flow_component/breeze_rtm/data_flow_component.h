// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OPENRTM_DATA_FLOW_COMPONENT_BASE_H_
#define OPENRTM_DATA_FLOW_COMPONENT_BASE_H_

#include <breeze_rtm/rt_object.h>

#include <omg_rtc/data_flow_component_action.h>

namespace breeze_rtm
{
namespace data_flow_component
{
class DataFlowComponent : public rt_object::RTObject, public omg_rtc::DataFlowComponentAction
{
	public:
	virtual omg_rtc::ReturnCode_t on_execute(omg_rtc::ExecutionContextHandle_t exec_context) override;
	virtual omg_rtc::ReturnCode_t on_state_update(omg_rtc::ExecutionContextHandle_t exec_context) override;
	virtual omg_rtc::ReturnCode_t on_rate_changed(omg_rtc::ExecutionContextHandle_t exec_context) override;

	protected:
	DataFlowComponent(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service)
		: RTObject(execution_context_service, port_service) {}
};
}
}

#endif

