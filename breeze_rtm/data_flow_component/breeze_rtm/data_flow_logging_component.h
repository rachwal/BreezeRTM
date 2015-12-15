// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_DATA_FLOW_COMPONENT_DATA_FLOW_LOGGING_COMPONENT_H_
#define BREEZE_RTM_DATA_FLOW_COMPONENT_DATA_FLOW_LOGGING_COMPONENT_H_

#include "data_flow_component.h"

#include <breeze_rtm/rt_logging_object.h>

namespace breeze_rtm
{
namespace data_flow_component
{
class DataFlowLoggingComponent : public rt_object::RTLoggingObject, public omg_rtc::DataFlowComponentAction
{
	public:
	omg_rtc::ReturnCode_t OnExecute(omg_rtc::ExecutionContextHandle_t handle) override;
	omg_rtc::ReturnCode_t OnStateUpdate(omg_rtc::ExecutionContextHandle_t handle) override;
	omg_rtc::ReturnCode_t OnRateChanged(omg_rtc::ExecutionContextHandle_t handle) override;

	protected:
	DataFlowLoggingComponent(omg_rtc::ExecutionContext* execution_context, omg_rtc::Port* port, omg_rtc::Logger* logger);
};
}
}

#endif

