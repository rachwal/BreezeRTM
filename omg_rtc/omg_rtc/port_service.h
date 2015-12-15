// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_PORT_SERVICE_H_
#define OMG_RTC_PORT_SERVICE_H_

#include "port.h"

#include "logger.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class PortService
{
	public:
	virtual ~PortService() {}

	virtual Port *Create(const UniqueIdentifier& id) const = 0;
	virtual Port *Create(const std::string&, const UniqueIdentifier& id, Logger*) const = 0;
	virtual Port *Retrieve(const UniqueIdentifier& id) const = 0;
	virtual void Update(const UniqueIdentifier& id, const Port& port) const = 0;
	virtual void Destroy(const UniqueIdentifier& id) const = 0;
};
}
}

#endif

