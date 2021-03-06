// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "rt_logging_object.h"

#include <sstream>

namespace breeze_rtm
{
namespace rt_object
{
RTLoggingObject::RTLoggingObject(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service, omg_rtc::Logger* logger)
	: RTObject(execution_context_service, port_service), logger_(logger) {}

std::list<omg_rtc::PortInterface*> *RTLoggingObject::GetPorts()
{
	logger_->Paranoid(profile_.instance_name, "GetPorts()");

	return RTObject::GetPorts();
}

omg_rtc::ReturnCode_t RTLoggingObject::Initialize(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	logger_->Trace(profile_.instance_name, "Initialize()");

	auto initialization_result = RTObject::Initialize(execution_context_id);

	if (initialization_result == omg_rtc::RTC_OK)
	{
		logger_->Debug(profile_.instance_name, "Starting Execution Context");
	}

	return initialization_result;
}

omg_rtc::ReturnCode_t RTLoggingObject::Finalize()
{
	logger_->Trace(profile_.instance_name, "Finalize()");

	return RTObject::Finalize();
}

bool RTLoggingObject::IsAlive(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	logger_->Trace(profile_.instance_name, "IsAlive()");

	return RTObject::IsAlive(execution_context_id);
}

omg_rtc::ReturnCode_t RTLoggingObject::Exit()
{
	logger_->Paranoid(profile_.instance_name, "Exit()");

	return RTObject::Exit();
}

omg_rtc::ExecutionContextHandle_t RTLoggingObject::AttachContext(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	logger_->Trace(profile_.instance_name, "AttachContext()");

	return RTObject::AttachContext(execution_context_id);
}

omg_rtc::ReturnCode_t RTLoggingObject::DetachContext(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "DetachContext" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return RTObject::DetachContext(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::OnInitialize()
{
	logger_->Trace(profile_.instance_name, "OnInitialize()");

	return RTObject::OnInitialize();
}

omg_rtc::ReturnCode_t RTLoggingObject::OnFinalize()
{
	logger_->Trace(profile_.instance_name, "OnFinalize()");

	return RTObject::OnFinalize();
}

omg_rtc::ReturnCode_t RTLoggingObject::OnStartup(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnStartup" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return RTObject::OnStartup(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::OnShutdown(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnShutdown" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return RTObject::OnShutdown(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::OnActivated(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnActivated" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return RTObject::OnActivated(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::OnDeactivated(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnDeactivated" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return RTObject::OnDeactivated(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::OnAborting(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnAborting" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return RTObject::OnAborting(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::OnError(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnError" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return RTObject::OnError(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::OnReset(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "OnReset" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name, stream.str());

	return RTObject::OnReset(handle);
}
}
}

