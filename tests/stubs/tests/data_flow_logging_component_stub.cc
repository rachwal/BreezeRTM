// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "data_flow_logging_component_stub.h"

namespace breeze_rtm
{
namespace stubs
{
DataFlowLoggingComponentStub::DataFlowLoggingComponentStub(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service, omg_rtc::Logger* logger) : DataFlowLoggingComponent(execution_context_service, port_service, logger)
{
	profile_.instance_name = "DataFlowLoggingComponentStub";
}
}
}

