// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_MULTI_MODE_OBJECT_H_
#define OMG_RTC_MULTI_MODE_OBJECT_H_

#include "lightweight_rt_object.h"
#include "mode_capable.h"
#include "multi_mode_component_action.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class MultiModeObject : public LightweightRTObject, public ModeCapable, public MultiModeComponentAction { };
}
}

#endif

