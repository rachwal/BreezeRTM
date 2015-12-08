// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <breeze_rtm/data_flow_component.h>
#include <breeze_rtm/execution_context_service.h>

#include <utils/strings.h>

namespace breeze_rtm
{
namespace execution_context_service_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace breeze_rtm;

class DataFlowComponentStub : public data_flow_component::DataFlowComponent
{
	public:
	DataFlowComponentStub(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service)
		: DataFlowComponent(execution_context_service, port_service)
	{
		profile_.instance_name = "test";
	}
};

class ExecutionContextServiceStub : public execution_context::ExecutionContextService
{
	public:
	ExecutionContextServiceStub()
	{
		profile_.kind = omg_rtc::ExecutionKind::PERIODIC;
		profile_.owner = nullptr;
	}
};

TEST_CLASS(ExecutionContextTest)
{
	public:
	ExecutionContextTest() { }

	~ExecutionContextTest() { }

	TEST_METHOD(ShouldAddComponent)
	{
		//GIVEN
		auto execution_context_service = new ExecutionContextServiceStub();
		auto component = new DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new ExecutionContextServiceStub();

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto component = new DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new ExecutionContextServiceStub();

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto component = new DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new ExecutionContextServiceStub();

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto component = new DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new ExecutionContextServiceStub();

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto component = new DataFlowComponentStub(execution_context_service, nullptr);
		component->initialize();

		auto external_execution_context_service = new ExecutionContextServiceStub();

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

