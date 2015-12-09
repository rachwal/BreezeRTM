// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "rt_object.h"

namespace breeze_rtm
{
namespace rt_object
{
RTObject::RTObject(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service) :
	execution_context_service_(execution_context_service), port_service_(port_service), initialized_(false)
{
	owned_contexts_ = new std::list<omg_rtc::ExecutionContext*>();
	participating_contexts_ = new std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::ExecutionContext*>();
}

RTObject::~RTObject()
{
	auto begin = owned_contexts_->begin();
	auto end = owned_contexts_->end();
	owned_contexts_->erase(begin, end);
	delete owned_contexts_;

	delete participating_contexts_;
}

omg_rtc::ComponentProfile *RTObject::get_component_profile()
{
	return &profile_;
}

omg_rtc::ListInterface<omg_rtc::ServiceInterface<omg_rtc::ConnectorProfile>> *RTObject::get_ports()
{
	return nullptr;
}

omg_rtc::ReturnCode_t RTObject::initialize()
{
	if (initialized_)
	{
		return omg_rtc::ReturnCode_t::PRECONDITION_NOT_MET;
	}

	if (execution_context_service_ == nullptr)
	{
		return omg_rtc::RTC_ERROR;
	}

	owned_contexts_->push_back(execution_context_service_);

	execution_context_service_->start();

	initialized_ = true;
	on_initialize();

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::finalize()
{
	if (!initialized_ || participating_contexts_->size() > 0)
	{
		return omg_rtc::ReturnCode_t::PRECONDITION_NOT_MET;
	}

	on_finalize();

	return omg_rtc::RTC_OK;
}

bool RTObject::is_alive(omg_rtc::ExecutionContext* exec_context)
{
	for (auto iterator = owned_contexts_->begin(); iterator != owned_contexts_->end(); ++iterator)
	{
		auto context = *iterator;
		if (context == exec_context)
		{
			return true;
		}
	}

	for (auto iterator = participating_contexts_->begin(); iterator != participating_contexts_->end(); ++iterator)
	{
		auto context = iterator->second;
		if (context == exec_context)
		{
			return true;
		}
	}
	return false;
}

omg_rtc::ReturnCode_t RTObject::exit()
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ExecutionContextHandle_t RTObject::attach_context(omg_rtc::ExecutionContext* exec_context)
{
	omg_rtc::ExecutionContextHandle_t new_handle = 1;

	for (auto iterator = participating_contexts_->begin(); iterator != participating_contexts_->end(); ++iterator)
	{
		auto context = iterator->second;
		auto handle = iterator->first;

		if (handle == new_handle)
		{
			new_handle++;
		}

		if (context == exec_context)
		{
			return handle;
		}
	}

	participating_contexts_->operator[](new_handle) = exec_context;
	return new_handle;
}

omg_rtc::ReturnCode_t RTObject::detach_context(omg_rtc::ExecutionContextHandle_t handle)
{
	participating_contexts_->erase(handle);

	return omg_rtc::RTC_OK;
}

omg_rtc::ExecutionContext *RTObject::get_context(omg_rtc::ExecutionContextHandle_t handle)
{
	return participating_contexts_->operator[](handle);
}

std::list<omg_rtc::ExecutionContext*> *RTObject::get_owned_contexts()
{
	return owned_contexts_;
}

std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::ExecutionContext*> *RTObject::get_participating_contexts()
{
	return participating_contexts_;
}

omg_rtc::ExecutionContextHandle_t RTObject::get_context_handle(omg_rtc::ExecutionContext& exec_context)
{
	for (auto iterator = participating_contexts_->begin(); iterator != participating_contexts_->end(); ++iterator)
	{
		auto context = iterator->second;
		auto handle = iterator->first;

		if (context == &exec_context)
		{
			return handle;
		}
	}

	omg_rtc::ExecutionContextHandle_t unknown_handle = -1;
	return unknown_handle;
}

omg_rtc::ReturnCode_t RTObject::on_initialize()
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::on_finalize()
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::on_startup(omg_rtc::ExecutionContextHandle_t handle)
{
	if (!initialized_)
	{
		return omg_rtc::PRECONDITION_NOT_MET;
	}

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::on_shutdown(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::on_activated(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::on_deactivated(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::on_aborting(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::on_error(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::on_reset(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}
}
}

