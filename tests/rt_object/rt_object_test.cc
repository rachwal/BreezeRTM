// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_stub.h>
#include <tests/execution_context_service_stub.h>
#include <tests/lightweight_rt_object_service_stub.h>

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
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);

		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context = execution_context_service->Create("ec");

		//WHEN
		auto return_code = rt_object->Initialize(execution_context);

		//THEN
		Assert::AreEqual(0, static_cast<int>(return_code));

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldReturnErrorCodeTryToInitializeWithNullExecutionContext)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		//WHEN
		auto return_code = rt_object->Initialize(nullptr);

		//THEN
		Assert::AreEqual(1, static_cast<int>(return_code));

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}


	TEST_METHOD(RTObjectShouldNotInitializeMoreThanOnce)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context = execution_context_service->Create("ec");

		//WHEN
		auto first_return_code = rt_object->Initialize(execution_context);
		auto second_return_code = rt_object->Initialize(execution_context);

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}


	TEST_METHOD(RTObjectShouldFinalize)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context = execution_context_service->Create("ec");

		//WHEN
		auto first_return_code = rt_object->Initialize(execution_context);
		auto second_return_code = rt_object->Finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(0, static_cast<int>(second_return_code));

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldNotFinalizeWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context = execution_context_service->Create("ec");
		auto first_return_code = rt_object->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");
		external_execution_context->AddComponent(rt_object);

		//WHEN
		auto second_return_code = rt_object->Finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldNotFinalizeWhenIsNotInitialized)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		//WHEN
		auto return_code = rt_object->Finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(return_code));

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldBeAliveWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context = execution_context_service->Create("ec");
		rt_object->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");
		external_execution_context->AddComponent(rt_object);

		//WHEN
		auto is_alive = rt_object->IsAlive(external_execution_context);

		//THEN
		Assert::IsTrue(is_alive);

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldNotBeAliveWhenNotParticipatingInExecutionContext)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context = execution_context_service->Create("ec");
		rt_object->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto is_alive = rt_object->IsAlive(external_execution_context);

		//THEN
		Assert::IsFalse(is_alive);

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldExit)
	{
		//GIVEN

		//WHEN

		//THEN
		Assert::Fail();
	}


	TEST_METHOD(RTObjectShouldAttachContext)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto handle = rt_object->AttachContext(external_execution_context);

		//THEN
		Assert::AreEqual(1L, handle);

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldNotAttachTheSameContextMoreThanOnce)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto external_execution_context = execution_context_service->Create("external_ec");

		//WHEN
		auto first_handle = rt_object->AttachContext(external_execution_context);
		auto second_handle = rt_object->AttachContext(external_execution_context);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(1L, second_handle);

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldAttachTwoDifferentContexts)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto first_execution_context = execution_context_service->Create("first_ec");
		auto second_execution_context = execution_context_service->Create("second_ec");

		//WHEN
		auto first_handle = rt_object->AttachContext(first_execution_context);
		auto second_handle = rt_object->AttachContext(second_execution_context);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldDetachContext)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto first_execution_context = execution_context_service->Create("first_ec");
		auto second_execution_context = execution_context_service->Create("second_ec");
		auto third_execution_context = execution_context_service->Create("third_ec");
		auto fourth_execution_context = execution_context_service->Create("fourth_ec");

		//WHEN
		auto first_handle = rt_object->AttachContext(first_execution_context);
		auto second_handle = rt_object->AttachContext(second_execution_context);
		rt_object->DetachContext(first_handle);

		auto third_handle = rt_object->AttachContext(third_execution_context);
		auto fourth_handle = rt_object->AttachContext(fourth_execution_context);

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);
		Assert::AreEqual(1L, third_handle);
		Assert::AreEqual(3L, fourth_handle);

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTObjectShouldNotFinalizeWhenNotInitializedBefore)
	{
		//GIVEN
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		//WHEN
		auto finalize_component_return_code = rt_object->Finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(finalize_component_return_code));

		delete rt_object;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}
};
}
}

