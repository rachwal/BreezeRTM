// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_DATA_FLOW_COMPONENT_SERVICE_H_
#define OMG_RTC_DATA_FLOW_COMPONENT_SERVICE_H_

#include "unique_identifier.h"
#include "data_flow_component.h"
#include "lightweight_rt_object_service_partner.h"
#include "logger.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class DataFlowComponentService: public LightweightRTObjectServicePartner
{
	public:
	virtual ~DataFlowComponentService() {}

	virtual DataFlowComponent *Create(const UniqueIdentifier& id) const = 0;
	virtual DataFlowComponent *Create(const UniqueIdentifier& id, Logger* logger) const = 0;
};
}
}

#endif

