// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_COMPONENT_PROFILE_H_
#define OMG_RTC_COMPONENT_PROFILE_H_

#include <string>

namespace breeze_rtm
{
namespace omg_rtc
{
struct ComponentProfile
{
	std::string instance_name;
	std::string type_name;
	std::string description;
	std::string version;
	std::string vendor;
	std::string category;
	UniqueIdentifier id;
};
}
}

#endif

