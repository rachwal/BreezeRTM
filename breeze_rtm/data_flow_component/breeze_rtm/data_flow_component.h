// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_DATA_FLOW_COMPONENT_DATA_FLOW_COMPONENT_H_
#define BREEZE_RTM_DATA_FLOW_COMPONENT_DATA_FLOW_COMPONENT_H_

#include <breeze_rtm/rt_object.h>

#include <omg_rtc/data_flow_component_action.h>

namespace breeze_rtm
{
namespace data_flow_component
{
class DataFlowComponent : public rt_object::RTObject, public omg_rtc::DataFlowComponentAction
{
	public:
	virtual omg_rtc::ReturnCode_t OnExecute(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnStateUpdate(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnRateChanged(omg_rtc::ExecutionContextHandle_t handle) override;

	protected:
	DataFlowComponent(omg_rtc::ExecutionContext* execution_context, omg_rtc::Port* port);
};
}
}

#endif

