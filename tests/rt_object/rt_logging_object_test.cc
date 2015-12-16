// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_stub.h>
#include <tests/logger_stub.h>
#include <tests/execution_context_service_stub.h>
#include <tests/lightweight_rt_object_service_stub.h>

namespace breeze_rtm
{
namespace rt_object_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace breeze_rtm;

TEST_CLASS(RTLoggingObjectTest)
{
	public:
	RTLoggingObjectTest() { }

	~RTLoggingObjectTest() { }

	TEST_METHOD(RTLoggingObjectShouldInitialize)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_initialize()\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n");

		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto logger = new stubs::LoggerStub();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		auto execution_context = execution_context_service->Create("ec");

		//WHEN
		rt_object->Initialize(execution_context);

		//THEN
		auto logger_content = logger->content();
		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}


	TEST_METHOD(RTLoggingObjectShouldReturnErrorCodeTryToInitializeWithoutExecutionContext)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: initialize()\n");
		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto logger = new stubs::LoggerStub();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		//WHEN
		rt_object->Initialize(nullptr);

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}


	TEST_METHOD(RTLoggingObjectShouldNotInitializeMoreThanOnce)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_initialize()\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n") +
			std::string("TRACE: RTLoggingObjectStub: initialize()\n");

		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto logger = new stubs::LoggerStub();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		auto execution_context = execution_context_service->Create("ec");

		//WHEN
		rt_object->Initialize(execution_context);
		rt_object->Initialize(execution_context);

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}


	TEST_METHOD(RTLoggingObjectShouldFinalize)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_initialize()\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n") +
			std::string("TRACE: RTLoggingObjectStub: finalize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_finalize()\n");

		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto logger = new stubs::LoggerStub();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		auto execution_context = execution_context_service->Create("ec");

		rt_object->Initialize(execution_context);

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_initialize()\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n") +
			std::string("TRACE: RTLoggingObjectStub: attach_context()\n") +
			std::string("TRACE: RTLoggingObjectStub: finalize()\n");

		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto logger = new stubs::LoggerStub();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		auto execution_context = execution_context_service->Create("ec");
		rt_object->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");
		external_execution_context->AddComponent(rt_object);

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenIsNotInitialized)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: finalize()\n");

		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto logger = new stubs::LoggerStub();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTLoggingObjectShouldBeAliveWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_initialize()\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n") +
			std::string("TRACE: RTLoggingObjectStub: attach_context()\n") +
			std::string("TRACE: RTLoggingObjectStub: is_alive()\n");

		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto logger = new stubs::LoggerStub();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		auto execution_context = execution_context_service->Create("ec");
		rt_object->Initialize(execution_context);

		auto external_execution_context = execution_context_service->Create("external_ec");
		external_execution_context->AddComponent(rt_object);

		//WHEN
		rt_object->IsAlive(external_execution_context);

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenNotInitializedBefore)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: finalize()\n");

		auto execution_context_service = stubs::ExecutionContextServiceStub::CreateServiceStub();
		auto lightweight_rt_object_service = new stubs::LightweightRTObjectServiceStub();
		lightweight_rt_object_service->AttachExecutionContextService(execution_context_service);
		auto logger = new stubs::LoggerStub();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
		delete execution_context_service;
		delete lightweight_rt_object_service;
	}
};
}
}

