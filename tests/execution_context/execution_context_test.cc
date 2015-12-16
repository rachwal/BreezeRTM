// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_stub.h>
#include <tests/data_flow_component_stub.h>
#include <tests/execution_context_service_stub.h>

namespace breeze_rtm
{
namespace execution_context_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace breeze_rtm;

TEST_CLASS(ExecutionContextTest)
{
	public:
	ExecutionContextTest() { }

	~ExecutionContextTest() { }

	TEST_METHOD(ExecutionContextShouldAddComponent)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		auto execution_context = execution_context_service->Create("component_ec");
		component->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto add_component_return_code = external_execution_context->AddComponent(component);

		//THEN
		Assert::AreEqual(0, static_cast<int>(add_component_return_code));

		delete component;
		delete execution_context_service;
	}

	TEST_METHOD(ExecutionContextShouldNotAddTheSameComponentMoreThanOnce)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		auto execution_context = execution_context_service->Create("component_ec");
		component->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto first_add_component_return_code = external_execution_context->AddComponent(component);
		auto second_add_component_return_code = external_execution_context->AddComponent(component);

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_add_component_return_code));
		Assert::AreEqual(5, static_cast<int>(second_add_component_return_code));

		delete component;
		delete execution_context_service;
	}

	TEST_METHOD(ExecutionContextShouldRemoveComponent)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		auto execution_context = execution_context_service->Create("component_ec");
		component->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto first_add_component_return_code = external_execution_context->AddComponent(component);
		auto second_add_component_return_code = external_execution_context->RemoveComponent(component);

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_add_component_return_code));
		Assert::AreEqual(0, static_cast<int>(second_add_component_return_code));

		delete component;
		delete execution_context_service;
	}

	TEST_METHOD(ExecutionContextShouldNotFinalizeComponentIfNotRemovedFromExecutionContext)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		auto execution_context = execution_context_service->Create("component_ec");
		component->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto add_component_return_code = external_execution_context->AddComponent(component);
		auto finalize_component_return_code = component->Finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(add_component_return_code));
		Assert::AreEqual(5, static_cast<int>(finalize_component_return_code));

		delete component;
		delete execution_context_service;
	}

	TEST_METHOD(ExecutionContextShouldFinalizeComponentIfRemovedFromExecutionContext)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto component = new stubs::DataFlowComponentStub(execution_context_service, nullptr);

		auto execution_context = execution_context_service->Create("component_ec");
		component->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto add_component_return_code = external_execution_context->AddComponent(component);
		auto remove_component_return_code = external_execution_context->RemoveComponent(component);
		auto finalize_component_return_code = component->Finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(add_component_return_code));
		Assert::AreEqual(0, static_cast<int>(remove_component_return_code));
		Assert::AreEqual(0, static_cast<int>(finalize_component_return_code));

		delete component;
		delete execution_context_service;
	}
};
}
}

