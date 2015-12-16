// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_RT_OBJECT_H_
#define OMG_RTC_RT_OBJECT_H_

#include "lightweight_rt_object.h"
#include "component_profile.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class PortInterface;

class RTObject : public LightweightRTObject
{
	public:
	virtual ComponentProfile *GetComponentProfile() = 0;
	virtual std::list<PortInterface*> *GetPorts() = 0;
};
}
}

#endif

