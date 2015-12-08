// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_COMMON_SERVICE_INTERFACE_H_
#define OMG_RTC_COMMON_SERVICE_INTERFACE_H_

#include "../../types/omg_rtc/return_code_t.h"
#include "../../types/omg_rtc/unique_identifier.h"

namespace breeze_rtm
{
namespace omg_rtc
{
template<class type>
class ServiceInterface
{
	public:
	virtual ~ServiceInterface() {}

	virtual ReturnCode_t connect(type& connector_profile) = 0;
	virtual ReturnCode_t disconnect(const UniqueIdentifier connector_id) = 0;
	virtual ReturnCode_t notify_connect(type& connector_profile) = 0;
	virtual ReturnCode_t notify_disconnect(const UniqueIdentifier connector_id) = 0;
	virtual ReturnCode_t disconnect_all() = 0;
};
}
}

#endif

