// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "lightweight_rt_object_service_stub.h"
#include "rt_object_stub.h"

namespace breeze_rtm
{
namespace stubs
{
LightweightRTObjectServiceStub::LightweightRTObjectServiceStub(const omg_rtc::PortService* port_service) : port_service_(port_service)
{
	lightweight_rt_object_map_ = new std::map<omg_rtc::UniqueIdentifier, omg_rtc::LightweightRTObject*>();
}

LightweightRTObjectServiceStub::~LightweightRTObjectServiceStub()
{
	auto begin = lightweight_rt_object_map_->begin();
	auto end = lightweight_rt_object_map_->end();
	lightweight_rt_object_map_->erase(begin, end);
	delete lightweight_rt_object_map_;
}

omg_rtc::LightweightRTObject *LightweightRTObjectServiceStub::Create(const omg_rtc::UniqueIdentifier& lightweight_rt_object_id, const omg_rtc::UniqueIdentifier& port_id) const
{
	return nullptr;
}

omg_rtc::LightweightRTObject *LightweightRTObjectServiceStub::Retrieve(const omg_rtc::UniqueIdentifier& id) const
{
	return nullptr;
}

void LightweightRTObjectServiceStub::Update(const omg_rtc::UniqueIdentifier& id, const omg_rtc::LightweightRTObject& execution_context) const {}

void LightweightRTObjectServiceStub::Destroy(const omg_rtc::UniqueIdentifier& id) const { }
}
}

