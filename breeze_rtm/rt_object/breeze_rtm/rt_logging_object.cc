// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "rt_logging_object.h"

#include <sstream>

namespace breeze_rtm
{
namespace rt_object
{
RTLoggingObject::RTLoggingObject(omg_rtc::ExecutionContext* execution_context, omg_rtc::Port* port, omg_rtc::Logger* logger) : RTObject(execution_context, port), logger_(logger) {}

omg_rtc::ComponentProfile *RTLoggingObject::get_component_profile()
{
	logger_->Paranoid(profile_.instance_name(), "get_component_profile()");

	return RTObject::get_component_profile();
}

std::list<omg_rtc::PortInterface*> *RTLoggingObject::get_ports()
{
	logger_->Paranoid(profile_.instance_name(), "get_ports()");

	return RTObject::get_ports();
}

omg_rtc::ReturnCode_t RTLoggingObject::initialize()
{
	logger_->Trace(profile_.instance_name(), "initialize()");

	auto initialization_result = RTObject::initialize();

	if (initialization_result == omg_rtc::RTC_OK)
	{
		logger_->Debug(profile_.instance_name(), "Starting Execution Context");
	}

	return initialization_result;
}

omg_rtc::ReturnCode_t RTLoggingObject::finalize()
{
	logger_->Trace(profile_.instance_name(), "finalize()");

	return RTObject::finalize();
}

bool RTLoggingObject::is_alive(omg_rtc::ExecutionContext* exec_context)
{
	logger_->Trace(profile_.instance_name(), "is_alive()");

	return RTObject::is_alive(exec_context);
}

omg_rtc::ReturnCode_t RTLoggingObject::exit()
{
	logger_->Paranoid(profile_.instance_name(), "exit()");

	return RTObject::exit();
}

omg_rtc::ExecutionContextHandle_t RTLoggingObject::attach_context(omg_rtc::ExecutionContext* exec_context)
{
	logger_->Trace(profile_.instance_name(), "attach_context()");

	return RTObject::attach_context(exec_context);
}

omg_rtc::ReturnCode_t RTLoggingObject::detach_context(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "detach_context" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name(), stream.str());

	return RTObject::detach_context(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::on_initialize()
{
	logger_->Trace(profile_.instance_name(), "on_initialize()");

	return RTObject::on_initialize();
}

omg_rtc::ReturnCode_t RTLoggingObject::on_finalize()
{
	logger_->Trace(profile_.instance_name(), "on_finalize()");

	return RTObject::on_finalize();
}

omg_rtc::ReturnCode_t RTLoggingObject::on_startup(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "on_startup" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name(), stream.str());

	return RTObject::on_startup(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::on_shutdown(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "on_shutdown" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name(), stream.str());

	return RTObject::on_shutdown(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::on_activated(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "on_activated" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name(), stream.str());

	return RTObject::on_activated(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::on_deactivated(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "on_deactivated" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name(), stream.str());

	return RTObject::on_deactivated(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::on_aborting(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "on_aborting" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name(), stream.str());

	return RTObject::on_aborting(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::on_error(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "on_error" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name(), stream.str());

	return RTObject::on_error(handle);
}

omg_rtc::ReturnCode_t RTLoggingObject::on_reset(omg_rtc::ExecutionContextHandle_t handle)
{
	std::stringstream stream;
	stream << "on_reset" << "(" << handle << ")";
	logger_->Trace(profile_.instance_name(), stream.str());

	return RTObject::on_reset(handle);
}
}
}

