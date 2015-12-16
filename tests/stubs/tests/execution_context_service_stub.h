// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_EXECUTION_CONTEXT_SERVICE_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_EXECUTION_CONTEXT_SERVICE_STUB_H_

#include <omg_rtc/execution_context_service.h>
#include <omg_rtc/lightweight_rt_object_service.h>

#include <map>

namespace breeze_rtm
{
namespace stubs
{
class ExecutionContextServiceStub : public omg_rtc::ExecutionContextService
{
	public:
	explicit ExecutionContextServiceStub(const omg_rtc::LightweightRTObjectService* lightweight_rt_object_service);
	~ExecutionContextServiceStub();

	static ExecutionContextServiceStub *CreateServiceStub();

	omg_rtc::ExecutionContext *Create(const omg_rtc::UniqueIdentifier& id) const override;
	omg_rtc::ExecutionContext *Retrieve(const omg_rtc::UniqueIdentifier& id) const override;
	void Update(const omg_rtc::UniqueIdentifier& id, const omg_rtc::ExecutionContext& execution_context) const override;
	void Destroy(const omg_rtc::UniqueIdentifier& id) const override;

	private:
	std::map<omg_rtc::UniqueIdentifier, omg_rtc::ExecutionContext*>* execution_context_map_;

	const omg_rtc::LightweightRTObjectService* lightweight_rt_object_service_;
};
}
}

#endif

