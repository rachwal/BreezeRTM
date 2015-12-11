// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include <tests/logger_stub.h>
#include <tests/port_logging_stub.h>

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
		std::string expected_logger_content =
			std::string("TRACE: alpha: connect(1)\n") +
			std::string("TRACE: alpha: notify_connect(1)\n");

		auto logger = new stubs::LoggerStub();
		auto port = new stubs::PortLoggingStub("alpha", logger);

		auto connector_profile = new omg_rtc::ConnectorProfile("profile 1", "1");

		//WHEN
		port->connect(connector_profile);

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete port;
		delete logger;
		delete connector_profile;
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

		auto logger = new stubs::LoggerStub();

		auto alpha = new stubs::PortLoggingStub("Port 0", logger);
		auto beta = new stubs::PortLoggingStub("Port 1", logger);
		auto gamma = new stubs::PortLoggingStub("Port 2", logger);
		auto delta = new stubs::PortLoggingStub("Port 3", logger);

		//WHEN
		auto external_connector = new omg_rtc::ConnectorProfile("external", "1");
		external_connector->AddPort(alpha);
		external_connector->AddPort(beta);
		external_connector->AddPort(gamma);
		external_connector->AddPort(delta);

		beta->connect(external_connector);

		//THEN
		auto logger_content = logger->content();

		Assert::AreEqual(expected_logger_content, logger_content);

		delete alpha;
		delete beta;
		delete gamma;
		delete delta;

		delete external_connector;

		delete logger;
	}
};
}
}

