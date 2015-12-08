// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "logger_stub.h"

#include <mutex>

namespace breeze_rtm
{
namespace stubs
{
void LoggerStub::Update(const std::string& level, const std::string& source, const std::string& message)
{
	std::mutex m;
	m.lock();
	std::stringstream stream;
	stream << content_ << level << ": " << source << ": " << message << std::endl;
	content_ = stream.str();
	m.unlock();
}

void LoggerStub::Fatal(const std::string& source, const std::string& message)
{
	Update("FATAL", source, message);
}

void LoggerStub::Error(const std::string& source, const std::string& message)
{
	Update("ERROR", source, message);
}

void LoggerStub::Warn(const std::string& source, const std::string& message)
{
	Update("WARN", source, message);
}

void LoggerStub::Info(const std::string& source, const std::string& message)
{
	Update("INFO", source, message);
}

void LoggerStub::Debug(const std::string& source, const std::string& message)
{
	Update("DEBUG", source, message);
}

void LoggerStub::Trace(const std::string& source, const std::string& message)
{
	Update("TRACE", source, message);
}

void LoggerStub::Verbose(const std::string& source, const std::string& message)
{
	Update("VERBOSE", source, message);
}

void LoggerStub::Paranoid(const std::string& source, const std::string& message)
{
	Update("PARANOID", source, message);
}

std::string LoggerStub::content() const
{
	return content_;
}
}
}

