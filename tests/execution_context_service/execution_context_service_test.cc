// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_service_stub.h>
#include <tests/data_flow_component_stub.h>

namespace breeze_rtm
{
namespace execution_context_service_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace breeze_rtm;

TEST_CLASS(ExecutionContextTest)
{
	public:
	ExecutionContextTest() { }

	~ExecutionContextTest() { }

	TEST_METHOD(ShouldAddComponent)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto add_component_return_code = external_execution_context_service->add_component(component);

		//THEN
		Assert::AreEqual(0, static_cast<int>(add_component_return_code));

		delete component;
		delete execution_context_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldNotAddTheSameComponentMoreThanOnce)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto first_add_component_return_code = external_execution_context_service->add_component(component);
		auto second_add_component_return_code = external_execution_context_service->add_component(component);

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_add_component_return_code));
		Assert::AreEqual(5, static_cast<int>(second_add_component_return_code));

		delete component;
		delete execution_context_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldRemoveComponent)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto first_add_component_return_code = external_execution_context_service->add_component(component);
		auto second_add_component_return_code = external_execution_context_service->remove_component(component);

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_add_component_return_code));
		Assert::AreEqual(0, static_cast<int>(second_add_component_return_code));

		delete component;
		delete execution_context_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldNotFinalizeComponentIfNotRemovedFromContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto add_component_return_code = external_execution_context_service->add_component(component);
		auto finalize_component_return_code = component->finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(add_component_return_code));
		Assert::AreEqual(5, static_cast<int>(finalize_component_return_code));

		delete component;
		delete execution_context_service;

		delete external_execution_context_service;
	}

	TEST_METHOD(ShouldFinalizeComponentIfRemovedFromContext)
	{
		//GIVEN
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();

		//WHEN
		auto add_component_return_code = external_execution_context_service->add_component(component);
		auto remove_component_return_code = external_execution_context_service->remove_component(component);
		auto finalize_component_return_code = component->finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(add_component_return_code));
		Assert::AreEqual(0, static_cast<int>(remove_component_return_code));
		Assert::AreEqual(0, static_cast<int>(finalize_component_return_code));

		delete component;
		delete execution_context_service;

		delete external_execution_context_service;
	}
};
}
}
