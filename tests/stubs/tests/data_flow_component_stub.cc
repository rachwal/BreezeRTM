// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "data_flow_component_stub.h"

namespace breeze_rtm
{
namespace stubs
{
DataFlowComponentStub::DataFlowComponentStub(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service) : DataFlowComponent(execution_context_service, port_service)
{
	profile_.instance_name = "test";
}
}
}

