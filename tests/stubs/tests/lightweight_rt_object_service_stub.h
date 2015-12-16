// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef BREEZE_RTM_TESTS_STUBS_LIGHTWEIGHT_RT_SERVICE_STUB_H_
#define BREEZE_RTM_TESTS_STUBS_LIGHTWEIGHT_RT_SERVICE_STUB_H_

#include <omg_rtc/lightweight_rt_object_service.h>
#include <omg_rtc/port_service.h>

#include <map>

namespace breeze_rtm
{
namespace stubs
{
class LightweightRTObjectServiceStub : public omg_rtc::LightweightRTObjectService
{
	public:
	explicit LightweightRTObjectServiceStub(const omg_rtc::PortService* port_service);
	~LightweightRTObjectServiceStub();

	omg_rtc::LightweightRTObject *Create(const omg_rtc::UniqueIdentifier& lightweight_rt_object_id, const omg_rtc::UniqueIdentifier& port_id) const override;
	omg_rtc::LightweightRTObject *Retrieve(const omg_rtc::UniqueIdentifier& id) const override;
	void Update(const omg_rtc::UniqueIdentifier& id, const omg_rtc::LightweightRTObject& execution_context) const override;
	void Destroy(const omg_rtc::UniqueIdentifier& id) const override;

	private:
	std::map<omg_rtc::UniqueIdentifier, omg_rtc::LightweightRTObject*>* lightweight_rt_object_map_;
	const omg_rtc::PortService* port_service_;
};
}
}

#endif

