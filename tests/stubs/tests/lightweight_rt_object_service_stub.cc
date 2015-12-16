// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include "lightweight_rt_object_service_stub.h"
#include "rt_object_stub.h"
#include "rt_logging_object_stub.h"

namespace breeze_rtm
{
namespace stubs
{
LightweightRTObjectServiceStub::LightweightRTObjectServiceStub() : port_service_(nullptr), execution_context_service_(nullptr)
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

omg_rtc::LightweightRTObject *LightweightRTObjectServiceStub::Create(const omg_rtc::UniqueIdentifier& lightweight_rt_object_id) const
{
	auto rt_object = new RTObjectStub(execution_context_service_, port_service_);
	lightweight_rt_object_map_->operator[](lightweight_rt_object_id) = rt_object;

	return Retrieve(lightweight_rt_object_id);
}

omg_rtc::LightweightRTObject *LightweightRTObjectServiceStub::Create(const omg_rtc::UniqueIdentifier& lightweight_rt_object_id, omg_rtc::Logger* logger) const
{
	auto rt_object = new RTLoggingObjectStub(execution_context_service_, port_service_, logger);
	lightweight_rt_object_map_->operator[](lightweight_rt_object_id) = rt_object;

	return Retrieve(lightweight_rt_object_id);
}

omg_rtc::LightweightRTObject *LightweightRTObjectServiceStub::Retrieve(const omg_rtc::UniqueIdentifier& id) const
{
	return lightweight_rt_object_map_->operator[](id);
}

void LightweightRTObjectServiceStub::Update(const omg_rtc::UniqueIdentifier& id, const omg_rtc::LightweightRTObject& execution_context) const {}

void LightweightRTObjectServiceStub::Destroy(const omg_rtc::UniqueIdentifier& id) const { }

void LightweightRTObjectServiceStub::AttachExecutionContextService(omg_rtc::ExecutionContextService* execution_context_service)
{
	execution_context_service_ = execution_context_service;
}

void LightweightRTObjectServiceStub::AttachPortService(omg_rtc::PortService* port_service)
{
	port_service_ = port_service;
}
}
}

