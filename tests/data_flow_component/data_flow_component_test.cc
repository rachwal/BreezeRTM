// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_service_stub.h>
#include <tests/data_flow_component_stub.h>

namespace breeze_rtm
{
namespace data_flow_component_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace breeze_rtm;

TEST_CLASS(DataFlowComponentTest)
{
	public:
	DataFlowComponentTest() { }

	~DataFlowComponentTest() { }

	TEST_METHOD(DataFlowComponent_ShouldFail)
	{
		//GIVEN

		//WHEN

		//THEN
		Assert::Fail();
	}
};
}
}

