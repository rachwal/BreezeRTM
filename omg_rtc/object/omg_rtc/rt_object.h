// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_OBJECT_RT_OBJECT_H_
#define OMG_RTC_OBJECT_RT_OBJECT_H_

#include "lightweight_rt_object.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class PortInterface;
class ComponentProfile;

class RTObject : public LightweightRTObject
{
	public:
	virtual ComponentProfile *get_component_profile() = 0;
	virtual std::list<PortInterface*> *get_ports() = 0;
};
}
}

#endif

