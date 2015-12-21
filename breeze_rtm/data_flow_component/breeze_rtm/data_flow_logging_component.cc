// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "data_flow_logging_component.h"

#include <sstream>

namespace breeze_rtm
{
namespace data_flow_component
{
DataFlowLoggingComponent::DataFlowLoggingComponent(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service, omg_rtc::Logger* logger)
	: DataFlowComponent(execution_context_service, port_service), logger_(logger) {}

omg_rtc::ReturnCode_t DataFlowLoggingComponent::OnExecute(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnExecute" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t DataFlowLoggingComponent::OnStateUpdate(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnStateUpdate" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t DataFlowLoggingComponent::OnRateChanged(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnRateChanged" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return omg_rtc::RTC_OK;
}
}
}

