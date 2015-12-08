// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_OBJECT_RTC_LIST_H_
#define OMG_RTC_OBJECT_RTC_LIST_H_

#include "rt_object.h"

#include "../../common/omg_rtc/list_interface.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class RTCList : public ListInterface<RTObject> { };
}
}

#endif

