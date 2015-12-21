// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/logger_stub.h>
#include <tests/system_builder_stub.h>

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
			std::string("TRACE: RTLoggingObjectStub: Initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnInitialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnStartup(0)\n") +
			std::string("TRACE: RTLoggingObjectStub: OnActivated(0)\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		//WHEN
		rt_object->Initialize("ec");

		//THEN
		auto logger_content = logger->content();
		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}

	TEST_METHOD(RTLoggingObjectShouldNotInitializeMoreThanOnce)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: Initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnInitialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnStartup(0)\n") +
			std::string("TRACE: RTLoggingObjectStub: OnActivated(0)\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n") +
			std::string("TRACE: RTLoggingObjectStub: Initialize()\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		//WHEN
		rt_object->Initialize("ec");
		rt_object->Initialize("ec");

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}


	TEST_METHOD(RTLoggingObjectShouldFinalize)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: Initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnInitialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnStartup(0)\n") +
			std::string("TRACE: RTLoggingObjectStub: OnActivated(0)\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n") +
			std::string("TRACE: RTLoggingObjectStub: Finalize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnFinalize()\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		rt_object->Initialize("ec");

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: Initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnInitialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnStartup(0)\n") +
			std::string("TRACE: RTLoggingObjectStub: OnActivated(0)\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n") +
			std::string("TRACE: RTLoggingObjectStub: AttachContext()\n") +
			std::string("TRACE: RTLoggingObjectStub: Finalize()\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		rt_object->Initialize("ec");

		auto execution_context_service = system_builder->execution_context_service();
		auto external_execution_context = execution_context_service->Create("external_ec");
		external_execution_context->AddComponent("rto1");

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenIsNotInitialized)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: Finalize()\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}

	TEST_METHOD(RTLoggingObjectShouldBeAliveWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: Initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnInitialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: OnStartup(0)\n") +
			std::string("TRACE: RTLoggingObjectStub: OnActivated(0)\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n") +
			std::string("TRACE: RTLoggingObjectStub: AttachContext()\n") +
			std::string("TRACE: RTLoggingObjectStub: IsAlive()\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		rt_object->Initialize("ec");

		auto execution_context_service = system_builder->execution_context_service();
		auto external_execution_context = execution_context_service->Create("external_ec");
		external_execution_context->AddComponent("rto1");

		//WHEN
		rt_object->IsAlive("external_ec");

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenNotInitializedBefore)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: Finalize()\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto lightweight_rt_object_service = system_builder->lightweight_rt_object_service();
		auto rt_object = lightweight_rt_object_service->Create("rto1", logger);

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}
};
}
}

