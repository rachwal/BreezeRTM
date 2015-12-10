// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_DATA_FLOW_COMPONENT_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_DATA_FLOW_COMPONENT_STUB_H_

#include <breeze_rtm/data_flow_component.h>

namespace breeze_rtm
{
namespace stubs
{
class DataFlowComponentStub :public data_flow_component::DataFlowComponent
{
	public:
	DataFlowComponentStub(omg_rtc::ExecutionContext* execution_context, omg_rtc::Port* port);
};
}
}

#endif

