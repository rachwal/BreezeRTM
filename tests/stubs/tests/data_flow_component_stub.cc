// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "data_flow_component_stub.h"

namespace breeze_rtm
{
namespace stubs
{
DataFlowComponentStub::DataFlowComponentStub(omg_rtc::ExecutionContext* execution_context, omg_rtc::Port* port) : DataFlowComponent(execution_context, port)
{
	profile_.instance_name("DataFlowComponentStub");
}
}
}

