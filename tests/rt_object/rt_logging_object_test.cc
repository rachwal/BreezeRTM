// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_stub.h>
#include <tests/rt_logging_object_stub.h>
#include <tests/logger_stub.h>

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

		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context, port, logger);

		//WHEN
		rt_object->Initialize();

		//THEN
		auto logger_content = logger->content();
		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context;
		delete port;
		delete logger;
	}


	TEST_METHOD(RTLoggingObjectShouldReturnErrorCodeTryToInitializeWithoutExecutionContext)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: initialize()\n");
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(nullptr, nullptr, logger);

		//WHEN
		rt_object->Initialize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
	}


	TEST_METHOD(RTLoggingObjectShouldNotInitializeMoreThanOnce)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_initialize()\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context\n") +
			std::string("TRACE: RTLoggingObjectStub: initialize()\n");

		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context, port, logger);

		//WHEN
		rt_object->Initialize();
		rt_object->Initialize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context;
		delete port;
		delete logger;
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

		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context, port, logger);

		rt_object->Initialize();

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context;
		delete port;
		delete logger;
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

		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context, port, logger);
		rt_object->Initialize();

		auto external_execution_context = new stubs::ExecutionContextStub();
		external_execution_context->AddComponent(rt_object);

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context;
		delete port;

		delete external_execution_context;
		delete logger;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenIsNotInitialized)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: finalize()\n");
		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context, port, logger);

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context;
		delete port;
		delete logger;
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

		auto execution_context = new stubs::ExecutionContextStub();
		omg_rtc::Port* port = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context, port, logger);
		rt_object->Initialize();

		auto external_execution_context = new stubs::ExecutionContextStub();
		external_execution_context->AddComponent(rt_object);

		//WHEN
		rt_object->IsAlive(external_execution_context);

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context;
		delete port;

		delete external_execution_context;
		delete logger;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenNotInitializedBefore)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: finalize()\n");
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(nullptr, nullptr, logger);

		//WHEN
		rt_object->Finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
	}
};
}
}

