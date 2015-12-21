// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "execution_context.h"

namespace breeze_rtm
{
namespace execution_context
{
ExecutionContext::ExecutionContext(const omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::LightweightRTObjectService* lightweight_rt_object_service)
	: lightweight_rt_object_service_(lightweight_rt_object_service), execution_context_service_(execution_context_service)
{
	profile_ = omg_rtc::ExecutionContextProfile();
	components_map_ = new std::map<omg_rtc::UniqueIdentifier, omg_rtc::ExecutionContextHandle_t>();
	components_state_map_ = new std::map<omg_rtc::UniqueIdentifier, omg_rtc::LifeCycleState>();
}

ExecutionContext::~ExecutionContext()
{
	delete components_map_;
	delete components_state_map_;
}

omg_rtc::ExecutionContextProfile *ExecutionContext::profile()
{
	return &profile_;
}

bool ExecutionContext::IsRunning()
{
	return components_state_map_->operator[](profile_.id);
}

omg_rtc::ReturnCode_t ExecutionContext::Start()
{
	for (auto entry = components_map_->begin(); entry != components_map_->end(); ++entry)
	{
		auto component_id = entry->first;
		auto execution_context_handle = entry->second;
		auto component = lightweight_rt_object_service_->Retrieve(component_id);
		component->OnStartup(execution_context_handle);

		ActivateComponent(component_id);
	}
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::Stop()
{
	for (auto entry = components_map_->begin(); entry != components_map_->end(); ++entry)
	{
		auto component_id = entry->first;
		DeactivateComponent(component_id);

		auto execution_context_handle = entry->second;
		auto component = lightweight_rt_object_service_->Retrieve(component_id);
		component->OnShutdown(execution_context_handle);
	}
	return omg_rtc::RTC_OK;
}

double ExecutionContext::rate()
{
	return profile_.rate;
}

omg_rtc::ReturnCode_t ExecutionContext::rate(double rate)
{
	profile_.rate = rate;
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::AddComponent(const omg_rtc::UniqueIdentifier& component_id)
{
	for (auto entry = components_map_->begin(); entry != components_map_->end(); ++entry)
	{
		auto component = entry->first;
		if (component == component_id)
		{
			return omg_rtc::PRECONDITION_NOT_MET;
		}
	}

	auto component = lightweight_rt_object_service_->Retrieve(component_id);
	auto component_owned_context_id_list = component->GetOwnedContexts();

	for (auto context_id = component_owned_context_id_list->begin(); context_id != component_owned_context_id_list->end(); ++context_id)
	{
		if (*context_id == profile_.id)
		{
			components_map_->operator[](component_id) = 0;
			components_state_map_->operator[](component_id) = omg_rtc::CREATED_STATE;
			return omg_rtc::RTC_OK;
		}
	}

	auto handle = component->AttachContext(profile_.id);
	components_map_->operator[](component_id) = handle;
	components_state_map_->operator[](component_id) = omg_rtc::CREATED_STATE;

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
		components_state_map_->erase(component_id);
		return omg_rtc::RTC_OK;
	}

	return omg_rtc::RTC_ERROR;
}

omg_rtc::ReturnCode_t ExecutionContext::ActivateComponent(const omg_rtc::UniqueIdentifier& component_id)
{
	components_state_map_->operator[](component_id) = omg_rtc::ACTIVE_STATE;

	auto handle = components_map_->operator[](component_id);
	auto component = lightweight_rt_object_service_->Retrieve(component_id);
	component->OnActivated(handle);

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::DeactivateComponent(const omg_rtc::UniqueIdentifier& component_id)
{
	components_state_map_->operator[](component_id) = omg_rtc::INACTIVE_STATE;

	auto handle = components_map_->operator[](component_id);
	auto component = lightweight_rt_object_service_->Retrieve(component_id);
	component->OnDeactivated(handle);

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::ResetComponent(const omg_rtc::UniqueIdentifier& component_id)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::LifeCycleState ExecutionContext::GetComponentState(const omg_rtc::UniqueIdentifier& component_id)
{
	return components_state_map_->operator[](component_id);
}

omg_rtc::ExecutionKind ExecutionContext::kind()
{
	return profile_.kind;
}
}
}

