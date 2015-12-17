// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_stub.h>
#include <tests/data_flow_component_stub.h>
#include <tests/data_flow_component_service_stub.h>
#include <tests/system_builder_stub.h>

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
		auto system_builder = new stubs::SystemBuilderStub();

		auto data_flow_component_service = system_builder->data_flow_component_service();
		auto component = data_flow_component_service->Create("comp1");
		component->Initialize("component_ec");

		auto execution_context_service = system_builder->execution_context_service();
		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto add_component_return_code = external_execution_context->AddComponent("comp1");

		//THEN
		Assert::AreEqual(0, static_cast<int>(add_component_return_code));

		delete system_builder;
	}

	TEST_METHOD(ExecutionContextShouldNotAddTheSameComponentMoreThanOnce)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto data_flow_component_service = system_builder->data_flow_component_service();
		auto component = data_flow_component_service->Create("comp1");
		component->Initialize("component_ec");

		auto execution_context_service = system_builder->execution_context_service();
		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto first_add_component_return_code = external_execution_context->AddComponent("comp1");
		auto second_add_component_return_code = external_execution_context->AddComponent("comp1");

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_add_component_return_code));
		Assert::AreEqual(5, static_cast<int>(second_add_component_return_code));

		delete system_builder;
	}

	TEST_METHOD(ExecutionContextShouldRemoveComponent)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto data_flow_component_service = system_builder->data_flow_component_service();
		auto component = data_flow_component_service->Create("comp1");
		component->Initialize("component_ec");

		auto execution_context_service = system_builder->execution_context_service();
		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto first_add_component_return_code = external_execution_context->AddComponent("comp1");
		auto second_add_component_return_code = external_execution_context->RemoveComponent("comp1");

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_add_component_return_code));
		Assert::AreEqual(0, static_cast<int>(second_add_component_return_code));

		delete system_builder;
	}

	TEST_METHOD(ExecutionContextShouldNotFinalizeComponentIfNotRemovedFromExecutionContext)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto data_flow_component_service = system_builder->data_flow_component_service();
		auto component = data_flow_component_service->Create("comp1");
		component->Initialize("component_ec");

		auto execution_context_service = system_builder->execution_context_service();
		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto add_component_return_code = external_execution_context->AddComponent("comp1");
		auto finalize_component_return_code = component->Finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(add_component_return_code));
		Assert::AreEqual(5, static_cast<int>(finalize_component_return_code));

		delete system_builder;
	}

	TEST_METHOD(ExecutionContextShouldFinalizeComponentIfRemovedFromExecutionContext)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto data_flow_component_service = system_builder->data_flow_component_service();
		auto component = data_flow_component_service->Create("comp1");
		component->Initialize("component_ec");

		auto execution_context_service = system_builder->execution_context_service();
		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto add_component_return_code = external_execution_context->AddComponent("comp1");
		auto remove_component_return_code = external_execution_context->RemoveComponent("comp1");
		auto finalize_component_return_code = component->Finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(add_component_return_code));
		Assert::AreEqual(0, static_cast<int>(remove_component_return_code));
		Assert::AreEqual(0, static_cast<int>(finalize_component_return_code));

		delete system_builder;
	}
};
}
}

