// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_DATA_FLOW_COMPONENT_DATA_FLOW_LOGGING_COMPONENT_H_
#define BREEZE_RTM_DATA_FLOW_COMPONENT_DATA_FLOW_LOGGING_COMPONENT_H_

#include "data_flow_component.h"

namespace breeze_rtm
{
namespace data_flow_component
{
class DataFlowLoggingComponent : public DataFlowComponent
{
	public:
	virtual omg_rtc::ReturnCode_t OnExecute(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnStateUpdate(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnRateChanged(omg_rtc::ExecutionContextHandle_t handle) override;

	protected:
	DataFlowLoggingComponent(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service, omg_rtc::Logger* logger);

	private:
	omg_rtc::Logger* logger_;
};
}
}

#endif

