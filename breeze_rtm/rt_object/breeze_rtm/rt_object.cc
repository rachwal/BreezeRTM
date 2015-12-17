// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "rt_object.h"

namespace breeze_rtm
{
namespace rt_object
{
RTObject::RTObject(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service) : initialized_(false), execution_context_service_(execution_context_service), port_service_(port_service)
{
	owned_contexts_ = new std::list<omg_rtc::UniqueIdentifier>();
	participating_contexts_ = new std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::UniqueIdentifier>();
}

RTObject::~RTObject()
{
	auto begin = owned_contexts_->begin();
	auto end = owned_contexts_->end();
	owned_contexts_->erase(begin, end);
	delete owned_contexts_;

	delete participating_contexts_;
}

omg_rtc::ComponentProfile *RTObject::GetComponentProfile()
{
	return &profile_;
}

std::list<omg_rtc::PortInterface*> *RTObject::GetPorts()
{
	return nullptr;
}

omg_rtc::ReturnCode_t RTObject::Initialize(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	if (initialized_)
	{
		return omg_rtc::ReturnCode_t::PRECONDITION_NOT_MET;
	}

	if (&execution_context_id == nullptr)
	{
		return omg_rtc::RTC_ERROR;
	}

	owned_contexts_->push_back(execution_context_id);

	initialized_ = true;
	OnInitialize();

	omg_rtc::ExecutionContext* execution_context;
	execution_context = execution_context_service_->Retrieve(execution_context_id);
	if (!execution_context)
	{
		execution_context = execution_context_service_->Create(execution_context_id);
	}

	execution_context->Start();

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::Finalize()
{
	if (!initialized_ || participating_contexts_->size() > 0)
	{
		return omg_rtc::ReturnCode_t::PRECONDITION_NOT_MET;
	}

	OnFinalize();

	return omg_rtc::RTC_OK;
}

bool RTObject::IsAlive(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	for (auto iterator = owned_contexts_->begin(); iterator != owned_contexts_->end(); ++iterator)
	{
		auto context = *iterator;
		if (context == execution_context_id)
		{
			return true;
		}
	}

	for (auto iterator = participating_contexts_->begin(); iterator != participating_contexts_->end(); ++iterator)
	{
		auto context = iterator->second;
		if (context == execution_context_id)
		{
			return true;
		}
	}
	return false;
}

omg_rtc::ReturnCode_t RTObject::Exit()
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ExecutionContextHandle_t RTObject::AttachContext(const omg_rtc::UniqueIdentifier& execution_context_id)
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

		if (context == execution_context_id)
		{
			return handle;
		}
	}

	participating_contexts_->operator[](new_handle) = execution_context_id;
	return new_handle;
}

omg_rtc::ReturnCode_t RTObject::DetachContext(omg_rtc::ExecutionContextHandle_t handle)
{
	participating_contexts_->erase(handle);

	return omg_rtc::RTC_OK;
}

omg_rtc::ExecutionContext *RTObject::GetContext(omg_rtc::ExecutionContextHandle_t handle)
{
	auto context_id = participating_contexts_->operator[](handle);
	auto execution_context = execution_context_service_->Retrieve(context_id);
	return execution_context;
}

std::list<omg_rtc::UniqueIdentifier> *RTObject::GetOwnedContexts()
{
	return owned_contexts_;
}

std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::UniqueIdentifier> *RTObject::GetParticipatingContexts()
{
	return participating_contexts_;
}

omg_rtc::ExecutionContextHandle_t RTObject::GetContextHandle(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	for (auto iterator = participating_contexts_->begin(); iterator != participating_contexts_->end(); ++iterator)
	{
		auto context = iterator->second;
		auto handle = iterator->first;

		if (context == execution_context_id)
		{
			return handle;
		}
	}

	omg_rtc::ExecutionContextHandle_t unknown_handle = -1;
	return unknown_handle;
}

omg_rtc::ReturnCode_t RTObject::OnInitialize()
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::OnFinalize()
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::OnStartup(omg_rtc::ExecutionContextHandle_t handle)
{
	if (!initialized_)
	{
		return omg_rtc::PRECONDITION_NOT_MET;
	}

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::OnShutdown(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::OnActivated(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::OnDeactivated(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::OnAborting(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::OnError(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t RTObject::OnReset(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}
}
}

