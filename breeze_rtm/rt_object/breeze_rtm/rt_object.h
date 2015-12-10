// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_RT_OBJECT_RT_OBJECT_H_
#define BREEZE_RTM_RT_OBJECT_RT_OBJECT_H_

#include <omg_rtc/rt_object.h>
#include <omg_rtc/port.h>
#include <omg_rtc/component_profile.h>

namespace breeze_rtm
{
namespace rt_object
{
class RTObject : public omg_rtc::RTObject
{
	public:
	virtual ~RTObject();

	virtual omg_rtc::ComponentProfile *get_component_profile() override;
	virtual std::list<omg_rtc::PortInterface*> *get_ports() override;

	virtual omg_rtc::ReturnCode_t initialize() override;
	virtual omg_rtc::ReturnCode_t finalize() override;

	virtual bool is_alive(omg_rtc::ExecutionContext* exec_context) override;

	virtual omg_rtc::ReturnCode_t exit() override;
	virtual omg_rtc::ExecutionContextHandle_t attach_context(omg_rtc::ExecutionContext* exec_context) override;
	virtual omg_rtc::ReturnCode_t detach_context(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ExecutionContext *get_context(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual std::list<omg_rtc::ExecutionContext*> *get_owned_contexts() override;
	virtual std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::ExecutionContext*> *get_participating_contexts() override;
	virtual omg_rtc::ExecutionContextHandle_t get_context_handle(omg_rtc::ExecutionContext& exec_context) override;

	virtual omg_rtc::ReturnCode_t on_initialize() override;
	virtual omg_rtc::ReturnCode_t on_finalize() override;
	virtual omg_rtc::ReturnCode_t on_startup(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t on_shutdown(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t on_activated(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t on_deactivated(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t on_aborting(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t on_error(omg_rtc::ExecutionContextHandle_t handle) override;
	virtual omg_rtc::ReturnCode_t on_reset(omg_rtc::ExecutionContextHandle_t handle) override;

	protected:
	RTObject(omg_rtc::ExecutionContext* execution_context, omg_rtc::Port* port);

	omg_rtc::ExecutionContext* execution_context_;
	omg_rtc::Port* port_;

	omg_rtc::ComponentProfile profile_;

	std::list<omg_rtc::ExecutionContext*>* owned_contexts_;
	std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::ExecutionContext*>* participating_contexts_;

	bool initialized_;
};
}
}

#endif

