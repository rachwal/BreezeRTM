// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>
#include <tests/execution_context_service_stub.h>
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

	TEST_METHOD(ShouldInitializeRTObject)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);

		//WHEN
		auto return_code = rt_object->initialize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(return_code));

		delete rt_object;
		delete execution_context_service;
		delete port_service;
	}

	TEST_METHOD(ShouldReturnErrorCodeTryToInitializeRTObjectWithoutExecutionContextService)
	{
		//GIVEN
		auto rt_object = new stubs::RTObjectStub(nullptr, nullptr);

		//WHEN
		auto return_code = rt_object->initialize();

		//THEN
		Assert::AreEqual(1, static_cast<int>(return_code));

		delete rt_object;
	}


	TEST_METHOD(ShouldNotInitializeRTObjectMoreThanOnce)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);

		//WHEN
		auto first_return_code = rt_object->initialize();
		auto second_return_code = rt_object->initialize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete rt_object;
		delete execution_context_service;
		delete port_service;
	}


	TEST_METHOD(ShouldFinalizeRTObject)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);

		auto first_return_code = rt_object->initialize();

		//WHEN
		auto second_return_code = rt_object->finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(0, static_cast<int>(second_return_code));

		delete rt_object;
		delete execution_context_service;
		delete port_service;
	}

	TEST_METHOD(ShouldNotFinalizeRTObjectWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);
		auto first_return_code = rt_object->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();
		external_execution_context_service->add_component(rt_object);

		//WHEN
		auto second_return_code = rt_object->finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete rt_object;
		delete execution_context_service;
		delete port_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldNotFinalizeRTObjectWhichIsNotInitialized)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);

		//WHEN
		auto return_code = rt_object->finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(return_code));

		delete rt_object;
		delete execution_context_service;
		delete port_service;
	}

	TEST_METHOD(ShouldBeAliveWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);
		rt_object->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();
		external_execution_context_service->add_component(rt_object);

		//WHEN
		auto is_alive = rt_object->is_alive(external_execution_context_service);

		//THEN
		Assert::IsTrue(is_alive);

		delete rt_object;
		delete execution_context_service;
		delete port_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldNotBeAliveWhenNotParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);
		rt_object->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto is_alive = rt_object->is_alive(external_execution_context_service);

		//THEN
		Assert::IsFalse(is_alive);

		delete rt_object;
		delete execution_context_service;
		delete port_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldAttachContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto handle = rt_object->attach_context(external_execution_context_service);

		//THEN
		Assert::AreEqual(1L, handle);

		delete rt_object;
		delete execution_context_service;
		delete port_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldNotAttachTheSameContextMoreThanOnce)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);
		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto first_handle = rt_object->attach_context(external_execution_context_service);
		auto second_handle = rt_object->attach_context(external_execution_context_service);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(1L, second_handle);

		delete rt_object;
		delete execution_context_service;
		delete port_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldAttachTwoDifferentContexts)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);

		auto first_execution_context_service = new stubs::ExecutionContextServiceStub();
		auto second_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto first_handle = rt_object->attach_context(first_execution_context_service);
		auto second_handle = rt_object->attach_context(second_execution_context_service);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);

		delete rt_object;
		delete execution_context_service;
		delete port_service;

		delete first_execution_context_service;
		delete second_execution_context_service;
	}

	TEST_METHOD(ShouldDetachContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto rt_object = new stubs::RTObjectStub(execution_context_service, port_service);

		auto first_execution_context_service = new stubs::ExecutionContextServiceStub();
		auto second_execution_context_service = new stubs::ExecutionContextServiceStub();
		auto third_execution_context_service = new stubs::ExecutionContextServiceStub();
		auto fourth_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto first_handle = rt_object->attach_context(first_execution_context_service);
		auto second_handle = rt_object->attach_context(second_execution_context_service);
		rt_object->detach_context(first_handle);

		auto third_handle = rt_object->attach_context(third_execution_context_service);
		auto fourth_handle = rt_object->attach_context(fourth_execution_context_service);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);
		Assert::AreEqual(1L, third_handle);
		Assert::AreEqual(3L, fourth_handle);

		delete rt_object;
		delete execution_context_service;
		delete port_service;

		delete first_execution_context_service;
		delete second_execution_context_service;
		delete third_execution_context_service;
		delete fourth_execution_context_service;
	}

	TEST_METHOD(ShouldNotFinalizeRTObjectIfNotInitializedBefore)
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

