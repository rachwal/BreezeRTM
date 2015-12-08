// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

namespace openrtmsandbox
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(SandboxTests)
{
	public:
	SandboxTests() { }

	~SandboxTests() { }

	TEST_METHOD(Sandbox_ShouldFail)
	{
		//GIVEN

		//WHEN

		//THEN
		Assert::Fail();
	}
};
}

