// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_EXECUTION_CONTEXT_EXECUTION_CONTEXT_H_
#define BREEZE_RTM_EXECUTION_CONTEXT_EXECUTION_CONTEXT_H_

#include <omg_rtc/execution_context.h>
#include <omg_rtc/lightweight_rt_object.h>
#include <omg_rtc/lightweight_rt_object_service.h>
#include <omg_rtc/execution_context_service.h>

#include <map>

namespace breeze_rtm
{
namespace execution_context
{
class ExecutionContext : public omg_rtc::ExecutionContext
{
	public:
	virtual ~ExecutionContext();

	virtual omg_rtc::ExecutionContextProfile *profile() override;

	virtual omg_rtc::ReturnCode_t Initialize(const omg_rtc::UniqueIdentifier& component_id) override;

	virtual bool IsRunning() override;

	virtual omg_rtc::ReturnCode_t Start() override;
	virtual omg_rtc::ReturnCode_t Stop() override;

	virtual omg_rtc::ReturnCode_t AddComponent(const omg_rtc::UniqueIdentifier& component_id) override;
	virtual omg_rtc::ReturnCode_t RemoveComponent(const omg_rtc::UniqueIdentifier& component_id) override;
	virtual omg_rtc::ReturnCode_t ActivateComponent(const omg_rtc::UniqueIdentifier& component_id) override;
	virtual omg_rtc::ReturnCode_t DeactivateComponent(const omg_rtc::UniqueIdentifier& component_id) override;
	virtual omg_rtc::ReturnCode_t ResetComponent(const omg_rtc::UniqueIdentifier& component_id) override;

	virtual double rate() override;
	virtual omg_rtc::ReturnCode_t rate(double rate) override;

	virtual omg_rtc::LifeCycleState GetComponentState(const omg_rtc::UniqueIdentifier& component_id) override;
	virtual omg_rtc::ExecutionKind kind() override;

	protected:
	ExecutionContext(const omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::LightweightRTObjectService* lightweight_rt_object_service);

	std::map<omg_rtc::UniqueIdentifier, omg_rtc::ExecutionContextHandle_t>* components_map_;
	std::map<omg_rtc::UniqueIdentifier, omg_rtc::LifeCycleState>* components_state_map_;
	omg_rtc::ExecutionContextProfile profile_;

	private:
	bool is_running_;

	omg_rtc::LightweightRTObjectService* lightweight_rt_object_service_;
	const omg_rtc::ExecutionContextService* execution_context_service_;
};
}
}

#endif

