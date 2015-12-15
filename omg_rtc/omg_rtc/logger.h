// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_LOGGER_H_
#define OMG_RTC_LOGGER_H_

#include <string>

namespace breeze_rtm
{
namespace omg_rtc
{
class Logger
{
	public:
	virtual ~Logger() {};

	virtual void Fatal(const std::string& source, const std::string& message) = 0;
	virtual void Error(const std::string& source, const std::string& message) = 0;
	virtual void Warn(const std::string& source, const std::string& message) = 0;
	virtual void Info(const std::string& source, const std::string& message) = 0;
	virtual void Debug(const std::string& source, const std::string& message) = 0;
	virtual void Trace(const std::string& source, const std::string& message) = 0;
	virtual void Verbose(const std::string& source, const std::string& message) = 0;
	virtual void Paranoid(const std::string& source, const std::string& message) = 0;
};
}
}

#endif 

