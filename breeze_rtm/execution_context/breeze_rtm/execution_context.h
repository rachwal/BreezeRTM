// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_EXECUTION_CONTEXT_EXECUTION_CONTEXT_H_
#define BREEZE_RTM_EXECUTION_CONTEXT_EXECUTION_CONTEXT_H_

#include <map>

#include <omg_rtc/execution_context.h>
#include <omg_rtc/lightweight_rt_object.h>

namespace breeze_rtm
{
namespace execution_context
{
class ExecutionContext : public omg_rtc::ExecutionContext
{
	public:
	virtual ~ExecutionContext();

	virtual omg_rtc::ExecutionContextProfile *get_profile() override;

	virtual bool is_running() override;

	virtual omg_rtc::ReturnCode_t start() override;
	virtual omg_rtc::ReturnCode_t stop() override;

	virtual double get_rate() override;

	virtual omg_rtc::ReturnCode_t set_rate(double rate) override;
	virtual omg_rtc::ReturnCode_t add_component(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ReturnCode_t remove_component(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ReturnCode_t activate_component(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ReturnCode_t deactivate_component(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ReturnCode_t reset_component(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::LifeCycleState get_component_state(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ExecutionKind get_kind() override;

	protected:
	ExecutionContext();

	std::map<omg_rtc::LightweightRTObject*, omg_rtc::ExecutionContextHandle_t>* components_;
	omg_rtc::ExecutionContextProfile profile_;

	private:
	double rate_;
};
}
}

#endif

