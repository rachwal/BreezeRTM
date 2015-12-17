// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_stub.h>
#include <tests/system_builder_stub.h>

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
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		//WHEN
		auto return_code = rt_object->Initialize("ec");

		//THEN
		Assert::AreEqual(0, static_cast<int>(return_code));

		delete system_builder;
	}

	TEST_METHOD(RTObjectShouldNotInitializeMoreThanOnce)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		//WHEN
		auto first_return_code = rt_object->Initialize("ec");
		auto second_return_code = rt_object->Initialize("ec");

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete system_builder;
	}


	TEST_METHOD(RTObjectShouldFinalize)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		//WHEN
		auto first_return_code = rt_object->Initialize("ec");
		auto second_return_code = rt_object->Finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(0, static_cast<int>(second_return_code));

		delete system_builder;
	}

	TEST_METHOD(RTObjectShouldNotFinalizeWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");
		auto first_return_code = rt_object->Initialize("ec");

		auto execution_context_service = system_builder->execution_context_service();
		auto external_execution_context = execution_context_service->Create("external_ec");
		external_execution_context->AddComponent("rto1");

		//WHEN
		auto second_return_code = rt_object->Finalize();

		//THEN
		Assert::AreEqual(0, static_cast<int>(first_return_code));
		Assert::AreEqual(5, static_cast<int>(second_return_code));

		delete system_builder;
	}

	TEST_METHOD(RTObjectShouldNotFinalizeWhenIsNotInitialized)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		//WHEN
		auto return_code = rt_object->Finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(return_code));

		delete system_builder;
	}

	TEST_METHOD(RTObjectShouldBeAliveWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		rt_object->Initialize("ec");

		auto execution_context_service = system_builder->execution_context_service();
		auto external_execution_context = execution_context_service->Create("external_ec");
		external_execution_context->AddComponent("rto1");

		//WHEN
		auto is_alive = rt_object->IsAlive("external_ec");

		//THEN
		Assert::IsTrue(is_alive);

		delete system_builder;
	}

	TEST_METHOD(RTObjectShouldNotBeAliveWhenNotParticipatingInExecutionContext)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		rt_object->Initialize("ec");

		auto execution_context_service = system_builder->execution_context_service();
		execution_context_service->Create("external_ec");

		//WHEN
		auto is_alive = rt_object->IsAlive("external_ec");

		//THEN
		Assert::IsFalse(is_alive);

		delete system_builder;
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
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context_service = system_builder->execution_context_service();
		execution_context_service->Create("external_ec");

		//WHEN
		auto handle = rt_object->AttachContext("external_ec");

		//THEN
		Assert::AreEqual(1L, handle);

		delete system_builder;
	}

	TEST_METHOD(RTObjectShouldNotAttachTheSameContextMoreThanOnce)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context_service = system_builder->execution_context_service();
		execution_context_service->Create("external_ec");

		//WHEN
		auto first_handle = rt_object->AttachContext("external_ec");
		auto second_handle = rt_object->AttachContext("external_ec");

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(1L, second_handle);

		delete system_builder;
	}

	TEST_METHOD(RTObjectShouldAttachTwoDifferentContexts)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context_service = system_builder->execution_context_service();
		execution_context_service->Create("first_ec");
		execution_context_service->Create("second_ec");

		//WHEN
		auto first_handle = rt_object->AttachContext("first_ec");
		auto second_handle = rt_object->AttachContext("second_ec");

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);

		delete system_builder;
	}

	TEST_METHOD(RTObjectShouldDetachContext)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		auto execution_context_service = system_builder->execution_context_service();
		execution_context_service->Create("first_ec");
		execution_context_service->Create("second_ec");
		execution_context_service->Create("third_ec");
		execution_context_service->Create("fourth_ec");

		//WHEN
		auto first_handle = rt_object->AttachContext("first_ec");
		auto second_handle = rt_object->AttachContext("second_ec");
		rt_object->DetachContext(first_handle);

		auto third_handle = rt_object->AttachContext("third_ec");
		auto fourth_handle = rt_object->AttachContext("fourth_ec");

		//THEN
		Assert::AreEqual(1L, first_handle);
		Assert::AreEqual(2L, second_handle);
		Assert::AreEqual(1L, third_handle);
		Assert::AreEqual(3L, fourth_handle);

		delete system_builder;
	}

	TEST_METHOD(RTObjectShouldNotFinalizeWhenNotInitializedBefore)
	{
		//GIVEN
		auto system_builder = new stubs::SystemBuilderStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1");

		//WHEN
		auto finalize_component_return_code = rt_object->Finalize();

		//THEN
		Assert::AreEqual(5, static_cast<int>(finalize_component_return_code));

		delete system_builder;
	}
};
}
}

