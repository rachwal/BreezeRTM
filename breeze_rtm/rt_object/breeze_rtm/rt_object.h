// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_RT_OBJECT_RT_OBJECT_H_
#define BREEZE_RTM_RT_OBJECT_RT_OBJECT_H_

#include <omg_rtc/rt_object.h>
#include <omg_rtc/port.h>
#include <omg_rtc/component_profile.h>
#include <omg_rtc/execution_context_service.h>
#include <omg_rtc/port_service.h>

namespace breeze_rtm
{
namespace rt_object
{
class RTObject : public omg_rtc::RTObject
{
	public:
	virtual ~RTObject();

	virtual omg_rtc::ComponentProfile *GetComponentProfile() override;
	virtual std::list<omg_rtc::PortInterface*> *GetPorts() override;

	virtual omg_rtc::ReturnCode_t Initialize(omg_rtc::ExecutionContext* execution_context) override;
	virtual omg_rtc::ReturnCode_t Finalize() override;
	virtual omg_rtc::ReturnCode_t Exit() override;

	virtual bool IsAlive(omg_rtc::ExecutionContext* exec_context) override;

	virtual omg_rtc::ExecutionContextHandle_t AttachContext(omg_rtc::ExecutionContext* exec_context) override;
	virtual omg_rtc::ReturnCode_t DetachContext(omg_rtc::ExecutionContextHandle_t handle) override;

	virtual omg_rtc::ExecutionContext *GetContext(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual std::list<omg_rtc::ExecutionContext*> *GetOwnedContexts() override;
	virtual std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::ExecutionContext*> *GetParticipatingContexts() override;
	virtual omg_rtc::ExecutionContextHandle_t GetContextHandle(omg_rtc::ExecutionContext& exec_context) override;

	virtual omg_rtc::ReturnCode_t OnInitialize() override;
	virtual omg_rtc::ReturnCode_t OnFinalize() override;
	virtual omg_rtc::ReturnCode_t OnStartup(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnShutdown(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnActivated(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnDeactivated(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnAborting(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnError(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t OnReset(omg_rtc::ExecutionContextHandle_t handle) override;

	protected:
	explicit RTObject(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service);

	omg_rtc::ComponentProfile profile_;

	std::list<omg_rtc::ExecutionContext*>* owned_contexts_;
	std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::ExecutionContext*>* participating_contexts_;

	bool initialized_;
	private:
	omg_rtc::ExecutionContextService* execution_context_service_;
	omg_rtc::PortService* port_service_;
};
}
}

#endif

