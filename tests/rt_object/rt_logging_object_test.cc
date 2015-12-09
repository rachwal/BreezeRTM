// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/execution_context_service_stub.h>
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
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context Service\n");

		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context_service, port_service, logger);

		//WHEN
		rt_object->initialize();

		//THEN
		auto logger_content = logger->content();
		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context_service;
		delete port_service;
		delete logger;
	}


	TEST_METHOD(RTLoggingObjectShouldReturnErrorCodeTryToInitializeWithoutExecutionContextService)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: initialize()\n");
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(nullptr, nullptr, logger);

		//WHEN
		rt_object->initialize();

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
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context Service\n") +
			std::string("TRACE: RTLoggingObjectStub: initialize()\n");

		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context_service, port_service, logger);

		//WHEN
		rt_object->initialize();
		rt_object->initialize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context_service;
		delete port_service;
		delete logger;
	}


	TEST_METHOD(RTLoggingObjectShouldFinalize)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_initialize()\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context Service\n") +
			std::string("TRACE: RTLoggingObjectStub: finalize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_finalize()\n");

		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context_service, port_service, logger);

		rt_object->initialize();

		//WHEN
		rt_object->finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context_service;
		delete port_service;
		delete logger;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_initialize()\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context Service\n") +
			std::string("TRACE: RTLoggingObjectStub: attach_context()\n") +
			std::string("TRACE: RTLoggingObjectStub: finalize()\n");

		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context_service, port_service, logger);
		rt_object->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();
		external_execution_context_service->add_component(rt_object);

		//WHEN
		rt_object->finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context_service;
		delete port_service;

		delete external_execution_context_service;
		delete logger;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenIsNotInitialized)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: finalize()\n");
		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context_service, port_service, logger);

		//WHEN
		rt_object->finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context_service;
		delete port_service;
		delete logger;
	}

	TEST_METHOD(RTLoggingObjectShouldBeAliveWhenParticipatingInExecutionContext)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: RTLoggingObjectStub: initialize()\n") +
			std::string("TRACE: RTLoggingObjectStub: on_initialize()\n") +
			std::string("DEBUG: RTLoggingObjectStub: Starting Execution Context Service\n") +
			std::string("TRACE: RTLoggingObjectStub: attach_context()\n") +
			std::string("TRACE: RTLoggingObjectStub: is_alive()\n");

		auto execution_context_service = new stubs::ExecutionContextServiceStub();
		omg_rtc::PortService* port_service = nullptr;
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(execution_context_service, port_service, logger);
		rt_object->initialize();

		auto external_execution_context_service = new stubs::ExecutionContextServiceStub();
		external_execution_context_service->add_component(rt_object);

		//WHEN
		rt_object->is_alive(external_execution_context_service);

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete execution_context_service;
		delete port_service;

		delete external_execution_context_service;
		delete logger;
	}

	TEST_METHOD(RTLoggingObjectShouldNotFinalizeWhenNotInitializedBefore)
	{
		//GIVEN
		auto expected_logger_content = std::string("TRACE: RTLoggingObjectStub: finalize()\n");
		auto logger = new stubs::LoggerStub();
		auto rt_object = new stubs::RTLoggingObjectStub(nullptr, nullptr, logger);

		//WHEN
		rt_object->finalize();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete rt_object;
		delete logger;
	}
};
}
}

