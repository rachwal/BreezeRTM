// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OPENRTM_DATA_FLOW_LOGGING_COMPONENT_BASE_H_
#define OPENRTM_DATA_FLOW_LOGGING_COMPONENT_BASE_H_

#include "data_flow_component.h"

#include <breeze_rtm/rt_logging_object.h>

namespace breeze_rtm
{
namespace data_flow_component
{
class DataFlowLoggingComponent : public rt_object::RTLoggingObject, public omg_rtc::DataFlowComponentAction
{
	public:
	omg_rtc::ReturnCode_t on_execute(omg_rtc::ExecutionContextHandle_t handle) override;
	omg_rtc::ReturnCode_t on_state_update(omg_rtc::ExecutionContextHandle_t handle) override;
	omg_rtc::ReturnCode_t on_rate_changed(omg_rtc::ExecutionContextHandle_t handle) override;

	protected:
	DataFlowLoggingComponent(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service, omg_rtc::Logger* logger);
};
}
}

#endif

