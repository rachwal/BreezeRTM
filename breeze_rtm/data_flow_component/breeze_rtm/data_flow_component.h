// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_DATA_FLOW_COMPONENT_DATA_FLOW_COMPONENT_H_
#define BREEZE_RTM_DATA_FLOW_COMPONENT_DATA_FLOW_COMPONENT_H_

#include <breeze_rtm/rt_object.h>
#include <omg_rtc/data_flow_component.h>

namespace breeze_rtm
{
namespace data_flow_component
{
class DataFlowComponent : public rt_object::RTObject, public omg_rtc::DataFlowComponent
{
	public:
	virtual omg_rtc::ReturnCode_t Initialize(const omg_rtc::UniqueIdentifier& execution_context_id) override;
	virtual omg_rtc::ReturnCode_t Finalize() override;
	virtual omg_rtc::ReturnCode_t Exit() override;

	virtual bool IsAlive(const omg_rtc::UniqueIdentifier& execution_context_id) override;

	virtual omg_rtc::ExecutionContextHandle_t AttachContext(const omg_rtc::UniqueIdentifier& execution_context_id) override;
	virtual omg_rtc::ReturnCode_t DetachContext(omg_rtc::ExecutionContextHandle_t handle) override;

	virtual omg_rtc::ExecutionContext *GetContext(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual std::list<omg_rtc::UniqueIdentifier> *GetOwnedContexts() override;
	virtual std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::UniqueIdentifier> *GetParticipatingContexts() override;
	virtual omg_rtc::ExecutionContextHandle_t GetContextHandle(const omg_rtc::UniqueIdentifier& execution_context_id) override;

	virtual omg_rtc::ReturnCode_t OnInitialize() override;
	virtual omg_rtc::ReturnCode_t OnFinalize() override;
	virtual omg_rtc::ReturnCode_t OnStartup(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnShutdown(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnActivated(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnDeactivated(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnAborting(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnError(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnReset(omg_rtc::ExecutionContextHandle_t handle) override;

	virtual omg_rtc::ReturnCode_t OnExecute(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnStateUpdate(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnRateChanged(omg_rtc::ExecutionContextHandle_t handle) override;

	protected:
	DataFlowComponent(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service);
};
}
}

#endif

