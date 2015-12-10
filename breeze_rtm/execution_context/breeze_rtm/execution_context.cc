// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "execution_context.h"

namespace breeze_rtm
{
namespace execution_context
{
ExecutionContext::ExecutionContext() : rate_(1)
{
	components_ = new std::map<omg_rtc::LightweightRTObject*, omg_rtc::ExecutionContextHandle_t>();
}

ExecutionContext::~ExecutionContext()
{
	delete components_;
}

omg_rtc::ExecutionContextProfile *ExecutionContext::get_profile()
{
	return &profile_;
}

bool ExecutionContext::is_running()
{
	return true;
}

omg_rtc::ReturnCode_t ExecutionContext::start()
{
	for (auto iterator = components_->begin(); iterator != components_->end(); ++iterator)
	{
		auto component = iterator->first;
		auto handle = iterator->second;
		component->on_startup(handle);
	}
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::stop()
{
	for (auto iterator = components_->begin(); iterator != components_->end(); ++iterator)
	{
		auto component = iterator->first;
		auto handle = iterator->second;
		component->on_shutdown(handle);
	}
	return omg_rtc::RTC_OK;
}

double ExecutionContext::get_rate()
{
	return rate_;
}

omg_rtc::ReturnCode_t ExecutionContext::set_rate(double rate)
{
	rate_ = rate;
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::add_component(omg_rtc::LightweightRTObject* comp)
{
	for (auto iterator = components_->begin(); iterator != components_->end(); ++iterator)
	{
		auto component = iterator->first;
		if (component == comp)
		{
			return omg_rtc::PRECONDITION_NOT_MET;
		}
	}

	auto handle = comp->attach_context(this);
	components_->operator[](comp) = handle;

	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::remove_component(omg_rtc::LightweightRTObject* comp)
{
	auto handle = components_->operator[](comp);

	auto detach_return_code = comp->detach_context(handle);
	if (detach_return_code == omg_rtc::RTC_OK)
	{
		components_->erase(comp);
		return omg_rtc::RTC_OK;
	}

	return omg_rtc::RTC_ERROR;
}

omg_rtc::ReturnCode_t ExecutionContext::activate_component(omg_rtc::LightweightRTObject* comp)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::deactivate_component(omg_rtc::LightweightRTObject* comp)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t ExecutionContext::reset_component(omg_rtc::LightweightRTObject* comp)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::LifeCycleState ExecutionContext::get_component_state(omg_rtc::LightweightRTObject* comp)
{
	return omg_rtc::LifeCycleState::CREATED_STATE;
}

omg_rtc::ExecutionKind ExecutionContext::get_kind()
{
	return profile_.kind;
}
}
}

