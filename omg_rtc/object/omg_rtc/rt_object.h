// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_OBJECT_RT_OBJECT_H_
#define OMG_RTC_OBJECT_RT_OBJECT_H_

#include "rt_object_interface.h"
#include "lightweight_rt_object.h"

#include "../../component/omg_rtc/component_profile.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class RTObject : public RTObjectInterface, public LightweightRTObject
{
	public:
	virtual ComponentProfile *get_component_profile() = 0;
	virtual ListInterface<ServiceInterface<ConnectorProfile>> *get_ports() override = 0;
};
}
}

#endif

