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

	virtual omg_rtc::ExecutionContextProfile *profile() override;

	virtual bool IsRunning() override;

	virtual omg_rtc::ReturnCode_t Start() override;
	virtual omg_rtc::ReturnCode_t Stop() override;

	virtual omg_rtc::ReturnCode_t AddComponent(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ReturnCode_t RemoveComponent(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ReturnCode_t ActivateComponent(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ReturnCode_t DeactivateComponent(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ReturnCode_t ResetComponent(omg_rtc::LightweightRTObject* comp) override;

	virtual double rate() override;
	virtual omg_rtc::ReturnCode_t rate(double rate) override;

	virtual omg_rtc::LifeCycleState component_state(omg_rtc::LightweightRTObject* comp) override;
	virtual omg_rtc::ExecutionKind kind() override;

	protected:
	ExecutionContext();

	std::map<omg_rtc::LightweightRTObject*, omg_rtc::ExecutionContextHandle_t>* components_;
	omg_rtc::ExecutionContextProfile* profile_;

	private:
	double rate_;
};
}
}

#endif

