// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <breeze_rtm/data_flow_component.h>
#include <breeze_rtm/execution_context_service.h>

namespace breeze_rtm
{
namespace data_flow_component_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace breeze_rtm;

class DataFlowComponentStub :public data_flow_component::DataFlowComponent
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

	omg_rtc::ExecutionContextProfile *get_profile() override
	{
		return &profile_;
	};
};

TEST_CLASS(DataFlowComponentTest)
{
	public:
	DataFlowComponentTest() { }

	~DataFlowComponentTest() { }

	TEST_METHOD(ShouldInitializeComponent)
	{
		//GIVEN
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);

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
		auto data_flow_component = new DataFlowComponentStub(nullptr, nullptr);

		//WHEN
		auto return_code = data_flow_component->initialize();

		//THEN
		Assert::AreEqual(1, static_cast<int>(return_code));

		delete data_flow_component;
	}

	TEST_METHOD(ShouldNotInitializeComponentMoreThanOnce)
	{
		//GIVEN
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);
		auto first_return_code = data_flow_component->initialize();

		auto external_execution_context_service = new ExecutionContextServiceStub();
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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);
		data_flow_component->initialize();

		auto external_execution_context_service = new ExecutionContextServiceStub();
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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);
		data_flow_component->initialize();

		auto external_execution_context_service = new ExecutionContextServiceStub();

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);

		auto external_execution_context_service = new ExecutionContextServiceStub();

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);
		auto external_execution_context_service = new ExecutionContextServiceStub();

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);

		auto first_execution_context_service = new ExecutionContextServiceStub();
		auto second_execution_context_service = new ExecutionContextServiceStub();

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
		auto execution_context_service = new ExecutionContextServiceStub();
		auto data_flow_component = new DataFlowComponentStub(execution_context_service, nullptr);

		auto first_execution_context_service = new ExecutionContextServiceStub();
		auto second_execution_context_service = new ExecutionContextServiceStub();
		auto third_execution_context_service = new ExecutionContextServiceStub();
		auto fourth_execution_context_service = new ExecutionContextServiceStub();

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
		auto component = new DataFlowComponentStub(nullptr, nullptr);

		//WHEN
		auto finalize_component_return_code = component->finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(finalize_component_return_code));

		delete component;
	}
};
}
}

