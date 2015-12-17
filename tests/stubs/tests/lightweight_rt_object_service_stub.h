// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_LIGHTWEIGHT_RT_SERVICE_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_LIGHTWEIGHT_RT_SERVICE_STUB_H_

#include <omg_rtc/lightweight_rt_object_service.h>
#include <omg_rtc/port_service.h>

#include <map>
#include <omg_rtc/execution_context_service.h>

namespace breeze_rtm
{
namespace stubs
{
class LightweightRTObjectServiceStub : public omg_rtc::LightweightRTObjectService
{
	public:
	LightweightRTObjectServiceStub();
	~LightweightRTObjectServiceStub();

	omg_rtc::LightweightRTObject *Create(const omg_rtc::UniqueIdentifier& lightweight_rt_object_id) const override;
	omg_rtc::LightweightRTObject *Create(const omg_rtc::UniqueIdentifier& lightweight_rt_object_id, omg_rtc::Logger* logger) const override;

	void Register(const omg_rtc::UniqueIdentifier& id, const LightweightRTObjectServicePartner* lightweight_rt_object) const override;

	omg_rtc::LightweightRTObject *Retrieve(const omg_rtc::UniqueIdentifier& id) const override;

	void AttachExecutionContextService(omg_rtc::ExecutionContextService* execution_context_service);
	void AttachPortService(omg_rtc::PortService* port_service);

	private:
	std::map<omg_rtc::UniqueIdentifier, const LightweightRTObjectServicePartner*>* register_;
	std::map<omg_rtc::UniqueIdentifier, omg_rtc::LightweightRTObject*>* lightweight_rt_object_map_;
	omg_rtc::PortService* port_service_;
	omg_rtc::ExecutionContextService* execution_context_service_;
};
}
}

#endif

