// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_LIGHTWEIGHT_RT_OBJECT_SERVICE_H_
#define OMG_RTC_LIGHTWEIGHT_RT_OBJECT_SERVICE_H_

#include "lightweight_rt_object_service_partner.h"
#include "unique_identifier.h"
#include "logger.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class LightweightRTObjectService: public LightweightRTObjectServicePartner
{
	public:
	virtual ~LightweightRTObjectService() {}

	virtual LightweightRTObject *Create(const UniqueIdentifier& lightweight_rt_object_id) const = 0;
	virtual LightweightRTObject *Create(const UniqueIdentifier& lightweight_rt_object_id, Logger* logger) const = 0;

	virtual void Register(const UniqueIdentifier& id, const LightweightRTObjectServicePartner* lightweight_rt_object) const = 0;
};
}
}

#endif

