// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_DATA_FLOW_LOGGING_COMPONENT_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_DATA_FLOW_LOGGING_COMPONENT_STUB_H_

#include <breeze_rtm/data_flow_logging_component.h>

namespace breeze_rtm
{
namespace stubs
{
class DataFlowLoggingComponentStub :public data_flow_component::DataFlowLoggingComponent
{
	public:
	explicit DataFlowLoggingComponentStub(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service, omg_rtc::Logger* logger);
};
}
}

#endif

