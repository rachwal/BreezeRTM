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

	TEST_METHOD(ShouldInitializeComponent)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		//WHEN
		auto return_code = data_flow_component->initialize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(return_code));

		delete data_flow_component;
		delete execution_context_service;
	}

	TEST_METHOD(ShouldReturnErrorCodeTryToInitializeComponentWithoutExecutionContextService)
	{
		//GIVEN
		auto data_flow_component = new stubs::DataFlowComponentStub(nullptr, nullptr);

		//WHEN
		auto return_code = data_flow_component->initialize();

		//THEN
		Assert::AreEqual(1, static_cast<int>(return_code));

		delete data_flow_component;
	}

	TEST_METHOD(ShouldNotInitializeComponentMoreThanOnce)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		//WHEN
		auto first_return_code = data_flow_component->initialize();
		auto second_return_code = data_flow_component->initialize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete data_flow_component;
		delete execution_context_service;
	}

	TEST_METHOD(ShouldFinalizeComponent)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		auto first_return_code = data_flow_component->initialize();

		//WHEN
		auto second_return_code = data_flow_component->finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(0, static_cast<int>(second_return_code));

		delete data_flow_component;
		delete execution_context_service;
	}

	TEST_METHOD(ShouldNotFinalizeComponentWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);
		auto first_return_code = data_flow_component->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();
		external_execution_context_service->add_component(data_flow_component);

		//WHEN
		auto second_return_code = data_flow_component->finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete data_flow_component;
		delete execution_context_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldNotFinalizeComponentWhichIsNotInitialized)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		//WHEN
		auto return_code = data_flow_component->finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(return_code));

		delete data_flow_component;
		delete execution_context_service;
	}

	TEST_METHOD(ShouldBeAliveWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);
		data_flow_component->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();
		external_execution_context_service->add_component(data_flow_component);

		//WHEN
		auto is_alive = data_flow_component->is_alive(external_execution_context_service);

		//THEN
		Assert::IsTrue(is_alive);

		delete data_flow_component;
		delete execution_context_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldNotBeAliveWhenNotParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);
		data_flow_component->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto is_alive = data_flow_component->is_alive(external_execution_context_service);

		//THEN
		Assert::IsFalse(is_alive);

		delete data_flow_component;
		delete execution_context_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldAttachContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto handle = data_flow_component->attach_context(external_execution_context_service);

		//THEN
		Assert::AreEqual(1L, handle);

		delete data_flow_component;
		delete execution_context_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldNotAttachTheSameContextMoreThanOnce)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);
		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto first_handle = data_flow_component->attach_context(external_execution_context_service);
		auto second_handle = data_flow_component->attach_context(external_execution_context_service);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(1L, second_handle);

		delete data_flow_component;
		delete execution_context_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldAttachTwoDifferentContexts)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		auto first_execution_context_service = new stubs::ExecutionContextServiceStub();
		auto second_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto first_handle = data_flow_component->attach_context(first_execution_context_service);
		auto second_handle = data_flow_component->attach_context(second_execution_context_service);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);

		delete data_flow_component;
		delete execution_context_service;

		delete first_execution_context_service;
		delete second_execution_context_service;
	}

	TEST_METHOD(ShouldDetachContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto data_flow_component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		auto first_execution_context_service = new stubs::ExecutionContextServiceStub();
		auto second_execution_context_service = new stubs::ExecutionContextServiceStub();
		auto third_execution_context_service = new stubs::ExecutionContextServiceStub();
		auto fourth_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto first_handle = data_flow_component->attach_context(first_execution_context_service);
		auto second_handle = data_flow_component->attach_context(second_execution_context_service);
		data_flow_component->detach_context(first_handle);

		auto third_handle = data_flow_component->attach_context(third_execution_context_service);
		auto fourth_handle = data_flow_component->attach_context(fourth_execution_context_service);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);
		Assert::AreEqual(1L, third_handle);
		Assert::AreEqual(3L, fourth_handle);

		delete data_flow_component;
		delete execution_context_service;

		delete first_execution_context_service;
		delete second_execution_context_service;
		delete third_execution_context_service;
		delete fourth_execution_context_service;
	}

	TEST_METHOD(ShouldNotFinalizeComponentIfNotInitializedBefore)
	{
		//GIVEN
		auto component = new stubs::DataFlowComponentStub(nullptr, nullptr);

		//WHEN
		auto finalize_component_return_code = component->finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(finalize_component_return_code));

		delete component;
	}
};
}
}

