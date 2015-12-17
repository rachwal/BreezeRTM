// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "execution_context.h"

namespace breeze_rtm
{
namespace execution_context
{
ExecutionContext::ExecutionContext(const omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::LightweightRTObjectService* lightweight_rt_object_service) : rate_(1), lightweight_rt_object_service_(lightweight_rt_object_service), execution_context_service_(execution_context_service)
{
	profile_ = omg_rtc::ExecutionContextProfile();
	profile_.kind = omg_rtc::OTHER;

	components_map_ = new std::map<omg_rtc::UniqueIdentifier, omg_rtc::ExecutionContextHandle_t>();
}

ExecutionContext::~ExecutionContext()
{
	delete components_map_;
}

omg_rtc::ExecutionContextProfile *ExecutionContext::profile()
{
	return &profile_;
}

bool ExecutionContext::IsRunning()
{
	return true;
}

omg_rtc::ReturnCode_t ExecutionContext::Start()
{
	for (auto entry = components_map_->begin(); entry != components_map_->end(); ++entry)
	{
		auto component_id = entry->first;
		auto execution_context_handle = entry->second;
		auto component = lightweight_rt_object_service_->Retrieve(component_id);
		component->OnStartup(execution_context_handle);
	}
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::Stop()
{
	for (auto entry = components_map_->begin(); entry != components_map_->end(); ++entry)
	{
		auto component_id = entry->first;
		auto execution_context_handle = entry->second;
		auto component = lightweight_rt_object_service_->Retrieve(component_id);
		component->OnShutdown(execution_context_handle);
	}
	return omg_rtc::RTC_OK;
}

double ExecutionContext::rate()
{
	return rate_;
}

omg_rtc::ReturnCode_t ExecutionContext::rate(double rate)
{
	rate_ = rate;
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::AddComponent(const omg_rtc::UniqueIdentifier& component_id)
{
	for (auto iterator = components_map_->begin(); iterator != components_map_->end(); ++iterator)
	{
		auto component = iterator->first;
		if (component == component_id)
		{
			return omg_rtc::PRECONDITION_NOT_MET;
		}
	}
	auto component = lightweight_rt_object_service_->Retrieve(component_id);

	auto handle = component->AttachContext(profile_.id);
	components_map_->operator[](component_id) = handle;

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::RemoveComponent(const omg_rtc::UniqueIdentifier& component_id)
{
	auto handle = components_map_->operator[](component_id);

	auto component = lightweight_rt_object_service_->Retrieve(component_id);
	auto detach_return_code = component->DetachContext(handle);

	if (detach_return_code == omg_rtc::RTC_OK)
	{
		components_map_->erase(component_id);
		return omg_rtc::RTC_OK;
	}

	return omg_rtc::RTC_ERROR;
}

omg_rtc::ReturnCode_t ExecutionContext::ActivateComponent(const omg_rtc::UniqueIdentifier& component_id)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::DeactivateComponent(const omg_rtc::UniqueIdentifier& component_id)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::ResetComponent(const omg_rtc::UniqueIdentifier& component_id)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::LifeCycleState ExecutionContext::component_state(const omg_rtc::UniqueIdentifier& component_id)
{
	return omg_rtc::LifeCycleState::CREATED_STATE;
}

omg_rtc::ExecutionKind ExecutionContext::kind()
{
	return profile_.kind;
}
}
}

