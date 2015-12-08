// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_DATA_FLOW_COMPONENT_DATA_FLOW_COMPONENT_H_
#define OMG_RTC_DATA_FLOW_COMPONENT_DATA_FLOW_COMPONENT_H_

#include "data_flow_component_action.h"

#include "../../object/omg_rtc/lightweight_rt_object.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class DataFlowComponent : public DataFlowComponentAction, public LightweightRTObject { };
}
}

#endif

