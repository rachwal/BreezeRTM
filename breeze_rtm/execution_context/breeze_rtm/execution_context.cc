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
	profile_ = new omg_rtc::ExecutionContextProfile();
	profile_->kind = omg_rtc::OTHER;

	components_ = new std::map<omg_rtc::LightweightRTObject*, omg_rtc::ExecutionContextHandle_t>();
}

ExecutionContext::~ExecutionContext()
{
	delete components_;
}

omg_rtc::ExecutionContextProfile *ExecutionContext::profile()
{
	return profile_;
}

bool ExecutionContext::IsRunning()
{
	return true;
}

omg_rtc::ReturnCode_t ExecutionContext::Start()
{
	for (auto iterator = components_->begin(); iterator != components_->end(); ++iterator)
	{
		auto component = iterator->first;
		auto handle = iterator->second;
		component->OnStartup(handle);
	}
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::Stop()
{
	for (auto iterator = components_->begin(); iterator != components_->end(); ++iterator)
	{
		auto component = iterator->first;
		auto handle = iterator->second;
		component->OnShutdown(handle);
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

omg_rtc::ReturnCode_t ExecutionContext::AddComponent(omg_rtc::LightweightRTObject* comp)
{
	for (auto iterator = components_->begin(); iterator != components_->end(); ++iterator)
	{
		auto component = iterator->first;
		if (component == comp)
		{
			return omg_rtc::PRECONDITION_NOT_MET;
		}
	}

	auto handle = comp->AttachContext(profile_->id);
	components_->operator[](comp) = handle;

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::RemoveComponent(omg_rtc::LightweightRTObject* comp)
{
	auto handle = components_->operator[](comp);

	auto detach_return_code = comp->DetachContext(handle);
	if (detach_return_code == omg_rtc::RTC_OK)
	{
		components_->erase(comp);
		return omg_rtc::RTC_OK;
	}

	return omg_rtc::RTC_ERROR;
}

omg_rtc::ReturnCode_t ExecutionContext::ActivateComponent(omg_rtc::LightweightRTObject* comp)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::DeactivateComponent(omg_rtc::LightweightRTObject* comp)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::ResetComponent(omg_rtc::LightweightRTObject* comp)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::LifeCycleState ExecutionContext::component_state(omg_rtc::LightweightRTObject* comp)
{
	return omg_rtc::LifeCycleState::CREATED_STATE;
}

omg_rtc::ExecutionKind ExecutionContext::kind()
{
	return profile_->kind;
}
}
}

