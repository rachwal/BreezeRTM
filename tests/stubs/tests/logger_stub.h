// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_LOGGER_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_LOGGER_STUB_H_

#include <sstream>

#include <omg_rtc/logger.h>

namespace breeze_rtm
{
namespace stubs
{
class LoggerStub : public omg_rtc::Logger
{
	public:
	void Fatal(const std::string& source, const std::string& message) override;
	void Error(const std::string& source, const std::string& message) override;
	void Warn(const std::string& source, const std::string& message) override;
	void Info(const std::string& source, const std::string& message) override;
	void Debug(const std::string& source, const std::string& message) override;
	void Trace(const std::string& source, const std::string& message) override;
	void Verbose(const std::string& source, const std::string& message) override;
	void Paranoid(const std::string& source, const std::string& message) override;

	std::string content() const;

	private:
	void Update(const std::string& level, const std::string& source, const std::string& message);

	std::string content_;
};
}
}

#endif

