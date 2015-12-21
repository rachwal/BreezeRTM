// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "data_flow_component.h"

namespace breeze_rtm
{
namespace data_flow_component
{
DataFlowComponent::DataFlowComponent(omg_rtc::ExecutionContextService* execution_context_service, omg_rtc::PortService* port_service)
	: RTObject(execution_context_service, port_service) {}

omg_rtc::ReturnCode_t DataFlowComponent::Initialize(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	return RTObject::Initialize(execution_context_id);
}

omg_rtc::ReturnCode_t DataFlowComponent::Finalize()
{
	return RTObject::Finalize();
};

omg_rtc::ReturnCode_t DataFlowComponent::Exit()
{
	return RTObject::Exit();
};

bool DataFlowComponent::IsAlive(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	return RTObject::IsAlive(execution_context_id);
};

omg_rtc::ExecutionContextHandle_t DataFlowComponent::AttachContext(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	return RTObject::AttachContext(execution_context_id);
};

omg_rtc::ReturnCode_t DataFlowComponent::DetachContext(omg_rtc::ExecutionContextHandle_t handle)
{
	return RTObject::DetachContext(handle);
};

omg_rtc::ExecutionContext *DataFlowComponent::GetContext(omg_rtc::ExecutionContextHandle_t handle)
{
	return RTObject::GetContext(handle);
};

std::list<omg_rtc::UniqueIdentifier> *DataFlowComponent::GetOwnedContexts()
{
	return RTObject::GetOwnedContexts();
};

std::map<omg_rtc::ExecutionContextHandle_t, omg_rtc::UniqueIdentifier> *DataFlowComponent::GetParticipatingContexts()
{
	return RTObject::GetParticipatingContexts();
};

omg_rtc::ExecutionContextHandle_t DataFlowComponent::GetContextHandle(const omg_rtc::UniqueIdentifier& execution_context_id)
{
	return RTObject::GetContextHandle(execution_context_id);
};

omg_rtc::ReturnCode_t DataFlowComponent::OnInitialize()
{
	return RTObject::OnInitialize();
};

omg_rtc::ReturnCode_t DataFlowComponent::OnFinalize()
{
	return RTObject::OnFinalize();
};

omg_rtc::ReturnCode_t DataFlowComponent::OnStartup(omg_rtc::ExecutionContextHandle_t handle)
{
	return RTObject::OnStartup(handle);
};

omg_rtc::ReturnCode_t DataFlowComponent::OnShutdown(omg_rtc::ExecutionContextHandle_t handle)
{
	return RTObject::OnShutdown(handle);
};

omg_rtc::ReturnCode_t DataFlowComponent::OnActivated(omg_rtc::ExecutionContextHandle_t handle)
{
	return RTObject::OnActivated(handle);
};

omg_rtc::ReturnCode_t DataFlowComponent::OnDeactivated(omg_rtc::ExecutionContextHandle_t handle)
{
	return RTObject::OnDeactivated(handle);
};

omg_rtc::ReturnCode_t DataFlowComponent::OnAborting(omg_rtc::ExecutionContextHandle_t handle)
{
	return RTObject::OnAborting(handle);
};

omg_rtc::ReturnCode_t DataFlowComponent::OnError(omg_rtc::ExecutionContextHandle_t handle)
{
	return RTObject::OnError(handle);
};

omg_rtc::ReturnCode_t DataFlowComponent::OnReset(omg_rtc::ExecutionContextHandle_t handle)
{
	return RTObject::OnReset(handle);
};

omg_rtc::ReturnCode_t DataFlowComponent::OnExecute(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t DataFlowComponent::OnStateUpdate(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}

omg_rtc::ReturnCode_t DataFlowComponent::OnRateChanged(omg_rtc::ExecutionContextHandle_t handle)
{
	return omg_rtc::RTC_OK;
}
}
}

