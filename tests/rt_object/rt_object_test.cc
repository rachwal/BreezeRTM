// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_stub.h>
#include <tests/rt_object_stub.h>

namespace breeze_rtm
{
namespace rt_object_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace breeze_rtm;

TEST_CLASS(RTObjectTest)
{
	public:
	RTObjectTest() { }

	~RTObjectTest() { }

	TEST_METHOD(RTObjectShouldInitialize)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);

		//WHEN
		auto return_code = rt_object->initialize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(return_code));

		delete rt_object;
		delete execution_context;
		delete port;
	}

	TEST_METHOD(RTObjectShouldReturnErrorCodeTryToInitializeWithoutExecutionContext)
	{
		//GIVEN
		auto rt_object = new stubs::RTObjectStub(nullptr, nullptr);

		//WHEN
		auto return_code = rt_object->initialize();

		//THEN
		Assert::AreEqual(1, static_cast<int>(return_code));

		delete rt_object;
	}


	TEST_METHOD(RTObjectShouldNotInitializeMoreThanOnce)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);

		//WHEN
		auto first_return_code = rt_object->initialize();
		auto second_return_code = rt_object->initialize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete rt_object;
		delete execution_context;
		delete port;
	}


	TEST_METHOD(RTObjectShouldFinalize)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);

		auto first_return_code = rt_object->initialize();

		//WHEN
		auto second_return_code = rt_object->finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(0, static_cast<int>(second_return_code));

		delete rt_object;
		delete execution_context;
		delete port;
	}

	TEST_METHOD(RTObjectShouldNotFinalizeWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);
		auto first_return_code = rt_object->initialize();

		auto external_execution_context = new stubs::ExecutionContextStub();
		external_execution_context->add_component(rt_object);

		//WHEN
		auto second_return_code = rt_object->finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete rt_object;
		delete execution_context;
		delete port;

		delete external_execution_context;
	}

	TEST_METHOD(RTObjectShouldNotFinalizeWhenIsNotInitialized)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);

		//WHEN
		auto return_code = rt_object->finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(return_code));

		delete rt_object;
		delete execution_context;
		delete port;
	}

	TEST_METHOD(RTObjectShouldBeAliveWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);
		rt_object->initialize();

		auto external_execution_context = new stubs::ExecutionContextStub();
		external_execution_context->add_component(rt_object);

		//WHEN
		auto is_alive = rt_object->is_alive(external_execution_context);

		//THEN
		Assert::IsTrue(is_alive);

		delete rt_object;
		delete execution_context;
		delete port;

		delete external_execution_context;
	}

	TEST_METHOD(RTObjectShouldNotBeAliveWhenNotParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);
		rt_object->initialize();

		auto external_execution_context = new stubs::ExecutionContextStub();

		//WHEN
		auto is_alive = rt_object->is_alive(external_execution_context);

		//THEN
		Assert::IsFalse(is_alive);

		delete rt_object;
		delete execution_context;
		delete port;

		delete external_execution_context;
	}

	TEST_METHOD(RTObjectShouldAttachContext)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);

		auto external_execution_context = new stubs::ExecutionContextStub();

		//WHEN
		auto handle = rt_object->attach_context(external_execution_context);

		//THEN
		Assert::AreEqual(1L, handle);

		delete rt_object;
		delete execution_context;
		delete port;

		delete external_execution_context;
	}

	TEST_METHOD(RTObjectShouldNotAttachTheSameContextMoreThanOnce)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);
		auto external_execution_context = new stubs::ExecutionContextStub();

		//WHEN
		auto first_handle = rt_object->attach_context(external_execution_context);
		auto second_handle = rt_object->attach_context(external_execution_context);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(1L, second_handle);

		delete rt_object;
		delete execution_context;
		delete port;

		delete external_execution_context;
	}

	TEST_METHOD(RTObjectShouldAttachTwoDifferentContexts)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);

		auto first_execution_context = new stubs::ExecutionContextStub();
		auto second_execution_context = new stubs::ExecutionContextStub();

		//WHEN
		auto first_handle = rt_object->attach_context(first_execution_context);
		auto second_handle = rt_object->attach_context(second_execution_context);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);

		delete rt_object;
		delete execution_context;
		delete port;

		delete first_execution_context;
		delete second_execution_context;
	}

	TEST_METHOD(RTObjectShouldDetachContext)
	{
		//GIVEN
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context, port);

		auto first_execution_context = new stubs::ExecutionContextStub();
		auto second_execution_context = new stubs::ExecutionContextStub();
		auto third_execution_context = new stubs::ExecutionContextStub();
		auto fourth_execution_context = new stubs::ExecutionContextStub();

		//WHEN
		auto first_handle = rt_object->attach_context(first_execution_context);
		auto second_handle = rt_object->attach_context(second_execution_context);
		rt_object->detach_context(first_handle);

		auto third_handle = rt_object->attach_context(third_execution_context);
		auto fourth_handle = rt_object->attach_context(fourth_execution_context);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);
		Assert::AreEqual(1L, third_handle);
		Assert::AreEqual(3L, fourth_handle);

		delete rt_object;
		delete execution_context;
		delete port;

		delete first_execution_context;
		delete second_execution_context;
		delete third_execution_context;
		delete fourth_execution_context;
	}

	TEST_METHOD(RTObjectShouldNotFinalizeWhenNotInitializedBefore)
	{
		//GIVEN
		auto rt_object = new stubs::RTObjectStub(nullptr, nullptr);

		//WHEN
		auto finalize_component_return_code = rt_object->finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(finalize_component_return_code));

		delete rt_object;
	}
};
}
}

