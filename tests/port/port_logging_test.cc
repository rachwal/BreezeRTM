// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/logger_stub.h>
#include <tests/port_logging_stub.h>
#include <tests/port_service_stub.h>
#include <tests/system_builder_stub.h>

namespace breeze_rtm
{
namespace port_tests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace breeze_rtm;

TEST_CLASS(PortLoggingTest)
{
	public:
	PortLoggingTest() { }

	~PortLoggingTest() { }

	TEST_METHOD(PortLoggingShouldConnect)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: alpha: connect(c1)\n") +
			std::string("TRACE: alpha: notify_connect(c1)\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto port_service = system_builder->port_service();
		auto port = port_service->Create("alpha", "p1", logger);

		auto connector_profile_service = system_builder->connector_profile_service();
		connector_profile_service->Create("external", "c1");

		//WHEN
		port->Connect("c1");

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}

	TEST_METHOD(PortLoggingShouldNotifyAllPortsWhenConnected)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: Port 1: connect(c1)\n") +
			std::string("TRACE: Port 1: notify_connect(c1)\n") +
			std::string("TRACE: Port 0: connect(c1)\n") +
			std::string("TRACE: Port 0: notify_connect(c1)\n") +
			std::string("TRACE: Port 2: connect(c1)\n") +
			std::string("TRACE: Port 2: notify_connect(c1)\n") +
			std::string("TRACE: Port 3: connect(c1)\n") +
			std::string("TRACE: Port 3: notify_connect(c1)\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto port_service = system_builder->port_service();
		port_service->Create("Port 0", "p0", logger);
		port_service->Create("Port 1", "p1", logger);
		port_service->Create("Port 2", "p2", logger);
		port_service->Create("Port 3", "p3", logger);

		auto connector_profile_service = system_builder->connector_profile_service();
		auto external_connector = connector_profile_service->Create("external", "c1");

		//WHEN
		external_connector->AddPortId("p0");
		external_connector->AddPortId("p1");
		external_connector->AddPortId("p2");
		external_connector->AddPortId("p3");

		auto test_port = port_service->Retrieve("p1");
		test_port->Connect("c1");

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}

	TEST_METHOD(PortLoggingShouldNotifyAllPortsWhenDisconnected)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: Port 1: connect(c1)\n") +
			std::string("TRACE: Port 1: notify_connect(c1)\n") +
			std::string("TRACE: Port 0: connect(c1)\n") +
			std::string("TRACE: Port 0: notify_connect(c1)\n") +
			std::string("TRACE: Port 2: connect(c1)\n") +
			std::string("TRACE: Port 2: notify_connect(c1)\n") +
			std::string("TRACE: Port 3: connect(c1)\n") +
			std::string("TRACE: Port 3: notify_connect(c1)\n") +
			std::string("TRACE: Port 1: disconnect(c1)\n") +
			std::string("TRACE: Port 1: notify_disconnect(c1)\n") +
			std::string("TRACE: Port 0: disconnect(c1)\n") +
			std::string("TRACE: Port 0: notify_disconnect(c1)\n") +
			std::string("TRACE: Port 2: disconnect(c1)\n") +
			std::string("TRACE: Port 2: notify_disconnect(c1)\n") +
			std::string("TRACE: Port 3: disconnect(c1)\n") +
			std::string("TRACE: Port 3: notify_disconnect(c1)\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto port_service = system_builder->port_service();
		port_service->Create("Port 0", "p0", logger);
		port_service->Create("Port 1", "p1", logger);
		port_service->Create("Port 2", "p2", logger);
		port_service->Create("Port 3", "p3", logger);

		auto connector_profile_service = system_builder->connector_profile_service();
		auto external_connector = connector_profile_service->Create("external", "c1");
		external_connector->AddPortId("p0");
		external_connector->AddPortId("p1");
		external_connector->AddPortId("p2");
		external_connector->AddPortId("p3");

		//WHEN
		auto test_port = port_service->Retrieve("p1");
		test_port->Connect("c1");
		test_port->Disconnect("c1");

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}

	TEST_METHOD(PortLoggingShouldNotifyAllPortsWhenDisconnectedAll)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: Port 1: connect(c1)\n") +
			std::string("TRACE: Port 1: notify_connect(c1)\n") +
			std::string("TRACE: Port 0: connect(c1)\n") +
			std::string("TRACE: Port 0: notify_connect(c1)\n") +
			std::string("TRACE: Port 2: connect(c1)\n") +
			std::string("TRACE: Port 2: notify_connect(c1)\n") +
			std::string("TRACE: Port 3: connect(c1)\n") +
			std::string("TRACE: Port 3: notify_connect(c1)\n") +
			std::string("TRACE: Port 1: disconnect_all()\n") +
			std::string("TRACE: Port 1: disconnect(c1)\n") +
			std::string("TRACE: Port 1: notify_disconnect(c1)\n") +
			std::string("TRACE: Port 0: disconnect(c1)\n") +
			std::string("TRACE: Port 0: notify_disconnect(c1)\n") +
			std::string("TRACE: Port 2: disconnect(c1)\n") +
			std::string("TRACE: Port 2: notify_disconnect(c1)\n") +
			std::string("TRACE: Port 3: disconnect(c1)\n") +
			std::string("TRACE: Port 3: notify_disconnect(c1)\n");

		auto system_builder = new stubs::SystemBuilderStub();
		auto logger = new stubs::LoggerStub();

		auto port_service = system_builder->port_service();
		port_service->Create("Port 0", "p0", logger);
		port_service->Create("Port 1", "p1", logger);
		port_service->Create("Port 2", "p2", logger);
		port_service->Create("Port 3", "p3", logger);

		auto connector_profile_service = system_builder->connector_profile_service();
		auto external_connector = connector_profile_service->Create("external", "c1");
		external_connector->AddPortId("p0");
		external_connector->AddPortId("p1");
		external_connector->AddPortId("p2");
		external_connector->AddPortId("p3");

		//WHEN
		auto test_port = port_service->Retrieve("p1");
		test_port->Connect("c1");
		test_port->DisconnectAll();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete logger;
		delete system_builder;
	}
};
}
}

