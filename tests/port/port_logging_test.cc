// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/logger_stub.h>
#include <tests/port_logging_stub.h>
#include <tests/port_service_stub.h>
#include <tests/connector_profile_service_stub.h>

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
			std::string("TRACE: alpha: connect(1)\n") +
			std::string("TRACE: alpha: notify_connect(1)\n");

		auto connector_profile_service = new stubs::ConnectorProfileServiceStub();
		auto port_service = new stubs::PortServiceStub(connector_profile_service);
		auto logger = new stubs::LoggerStub();
		auto port = port_service->Create("alpha", "p1", logger);

		auto external_connector = connector_profile_service->Create("external", "1");

		//WHEN
		port->Connect(external_connector);

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete port;
		delete port_service;
		delete connector_profile_service;
		delete logger;

		delete external_connector;
	}

	TEST_METHOD(PortLoggingShouldNotifyAllPortsWhenConnected)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: Port 1: connect(1)\n") +
			std::string("TRACE: Port 1: notify_connect(1)\n") +
			std::string("TRACE: Port 0: connect(1)\n") +
			std::string("TRACE: Port 0: notify_connect(1)\n") +
			std::string("TRACE: Port 2: connect(1)\n") +
			std::string("TRACE: Port 2: notify_connect(1)\n") +
			std::string("TRACE: Port 3: connect(1)\n") +
			std::string("TRACE: Port 3: notify_connect(1)\n");

		auto connector_profile_service = new stubs::ConnectorProfileServiceStub();
		auto port_service = new stubs::PortServiceStub(connector_profile_service);
		auto logger = new stubs::LoggerStub();

		auto alpha = port_service->Create("Port 0", "p0", logger);
		auto beta = port_service->Create("Port 1", "p1", logger);
		auto gamma = port_service->Create("Port 2", "p2", logger);
		auto delta = port_service->Create("Port 3", "p3", logger);

		//WHEN
		auto external_connector = connector_profile_service->Create("external", "1");
		external_connector->AddPortId("p0");
		external_connector->AddPortId("p1");
		external_connector->AddPortId("p2");
		external_connector->AddPortId("p3");

		beta->Connect(external_connector);

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete alpha;
		delete beta;
		delete gamma;
		delete delta;

		delete port_service;
		delete connector_profile_service;

		delete external_connector;

		delete logger;
	}

	TEST_METHOD(PortLoggingShouldNotifyAllPortsWhenDisconnected)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: Port 1: connect(1)\n") +
			std::string("TRACE: Port 1: notify_connect(1)\n") +
			std::string("TRACE: Port 0: connect(1)\n") +
			std::string("TRACE: Port 0: notify_connect(1)\n") +
			std::string("TRACE: Port 2: connect(1)\n") +
			std::string("TRACE: Port 2: notify_connect(1)\n") +
			std::string("TRACE: Port 3: connect(1)\n") +
			std::string("TRACE: Port 3: notify_connect(1)\n") +
			std::string("TRACE: Port 1: disconnect(1)\n") +
			std::string("TRACE: Port 1: notify_disconnect(1)\n") +
			std::string("TRACE: Port 0: disconnect(1)\n") +
			std::string("TRACE: Port 0: notify_disconnect(1)\n") +
			std::string("TRACE: Port 2: disconnect(1)\n") +
			std::string("TRACE: Port 2: notify_disconnect(1)\n") +
			std::string("TRACE: Port 3: disconnect(1)\n") +
			std::string("TRACE: Port 3: notify_disconnect(1)\n");

		auto connector_profile_service = new stubs::ConnectorProfileServiceStub();
		auto port_service = new stubs::PortServiceStub(connector_profile_service);
		auto logger = new stubs::LoggerStub();

		auto alpha = port_service->Create("Port 0", "p0", logger);
		auto beta = port_service->Create("Port 1", "p1", logger);
		auto gamma = port_service->Create("Port 2", "p2", logger);
		auto delta = port_service->Create("Port 3", "p3", logger);

		auto external_connector = connector_profile_service->Create("external", "1");
		external_connector->AddPortId("p0");
		external_connector->AddPortId("p1");
		external_connector->AddPortId("p2");
		external_connector->AddPortId("p3");

		beta->Connect(external_connector);

		//WHEN
		beta->Disconnect("1");

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete alpha;
		delete beta;
		delete gamma;
		delete delta;

		delete port_service;
		delete connector_profile_service;

		delete external_connector;

		delete logger;
	}

	TEST_METHOD(PortLoggingShouldNotifyAllPortsWhenDisconnectedAll)
	{
		//GIVEN
		auto expected_logger_content =
			std::string("TRACE: Port 1: connect(1)\n") +
			std::string("TRACE: Port 1: notify_connect(1)\n") +
			std::string("TRACE: Port 0: connect(1)\n") +
			std::string("TRACE: Port 0: notify_connect(1)\n") +
			std::string("TRACE: Port 2: connect(1)\n") +
			std::string("TRACE: Port 2: notify_connect(1)\n") +
			std::string("TRACE: Port 3: connect(1)\n") +
			std::string("TRACE: Port 3: notify_connect(1)\n") +
			std::string("TRACE: Port 1: disconnect_all()\n") +
			std::string("TRACE: Port 1: disconnect(1)\n") +
			std::string("TRACE: Port 1: notify_disconnect(1)\n") +
			std::string("TRACE: Port 0: disconnect(1)\n") +
			std::string("TRACE: Port 0: notify_disconnect(1)\n") +
			std::string("TRACE: Port 2: disconnect(1)\n") +
			std::string("TRACE: Port 2: notify_disconnect(1)\n") +
			std::string("TRACE: Port 3: disconnect(1)\n") +
			std::string("TRACE: Port 3: notify_disconnect(1)\n");

		auto connector_profile_service = new stubs::ConnectorProfileServiceStub();
		auto port_service = new stubs::PortServiceStub(connector_profile_service);
		auto logger = new stubs::LoggerStub();

		auto alpha = port_service->Create("Port 0", "p0", logger);
		auto beta = port_service->Create("Port 1", "p1", logger);
		auto gamma = port_service->Create("Port 2", "p2", logger);
		auto delta = port_service->Create("Port 3", "p3", logger);

		auto external_connector = connector_profile_service->Create("external", "1");
		external_connector->AddPortId("p0");
		external_connector->AddPortId("p1");
		external_connector->AddPortId("p2");
		external_connector->AddPortId("p3");

		beta->Connect(external_connector);

		//WHEN
		beta->DisconnectAll();

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete alpha;
		delete beta;
		delete gamma;
		delete delta;

		delete port_service;
		delete connector_profile_service;

		delete external_connector;

		delete logger;
	}
};
}
}

