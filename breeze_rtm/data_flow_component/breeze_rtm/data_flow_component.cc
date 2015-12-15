// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "data_flow_component.h"

namespace breeze_rtm
{
namespace data_flow_component
{
DataFlowComponent::DataFlowComponent(omg_rtc::ExecutionContext* execution_context, omg_rtc::Port* port) : RTObject(execution_context, port) {}

omg_rtc::ReturnCode_t DataFlowComponent::OnExecute(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t DataFlowComponent::OnStateUpdate(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t DataFlowComponent::OnRateChanged(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}
}
}

