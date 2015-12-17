// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_LIGHTWEIGHT_RT_OBJECT_SERVICE_PARTNER_H_
#define OMG_RTC_LIGHTWEIGHT_RT_OBJECT_SERVICE_PARTNER_H_

#include "unique_identifier.h"
#include "lightweight_rt_object.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class LightweightRTObjectServicePartner
{
	public:
	virtual ~LightweightRTObjectServicePartner() {}

	virtual LightweightRTObject *Retrieve(const UniqueIdentifier& id) const = 0;
};
}
}

#endif

