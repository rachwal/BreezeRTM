// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "data_flow_component.h"

namespace breeze_rtm
{
namespace data_flow_component
{
omg_rtc::ReturnCode_t DataFlowComponent::on_execute(omg_rtc::ExecutionContextHandle_t exec_context)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t DataFlowComponent::on_state_update(omg_rtc::ExecutionContextHandle_t exec_context)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t DataFlowComponent::on_rate_changed(omg_rtc::ExecutionContextHandle_t exec_context)
{
	return omg_rtc::RTC_OK;
}
}
}

