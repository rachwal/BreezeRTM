// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_RT_OBJECT_RT_LOGGING_OBJECT_H_
#define BREEZE_RTM_RT_OBJECT_RT_LOGGING_OBJECT_H_

#include "rt_object.h"

#include <omg_rtc/logger.h>

namespace breeze_rtm
{
namespace rt_object
{
class RTLoggingObject : public RTObject
{
	public:
	virtual omg_rtc::ComponentProfile *GetComponentProfile() override;
	virtual std::list<omg_rtc::PortInterface*> *GetPorts() override;

	virtual omg_rtc::ReturnCode_t Initialize(omg_rtc::ExecutionContext* execution_context) override;
	virtual omg_rtc::ReturnCode_t Finalize() override;
	virtual omg_rtc::ReturnCode_t Exit() override;

	virtual bool IsAlive(omg_rtc::ExecutionContext* exec_context) override;

	virtual omg_rtc::ExecutionContextHandle_t AttachContext(omg_rtc::ExecutionContext* exec_context) override;
	virtual omg_rtc::ReturnCode_t DetachContext(omg_rtc::ExecutionContextHandle_t handle) override;

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
	RTLoggingObject(omg_rtc::Logger* logger);
	omg_rtc::Logger* logger_;
};
}
}

#endif

