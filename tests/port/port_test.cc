// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

namespace breeze_rtm
{
namespace port_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace breeze_rtm;

TEST_CLASS(PortTest)
{
	public:
	PortTest() { }

	~PortTest() { }

	TEST_METHOD(Port_ShouldFail)
	{
		//GIVEN

		//WHEN

		//THEN
		Assert::Fail();
	}
};
}
}

