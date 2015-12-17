// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_PORT_INTERFACE_H_
#define OMG_RTC_PORT_INTERFACE_H_

#include "return_code_t.h"
#include "unique_identifier.h"

namespace breeze_rtm
{
namespace omg_rtc
{
class PortInterface
{
	public:
	virtual ~PortInterface() {}

	virtual ReturnCode_t Connect(const UniqueIdentifier& connector_id) = 0;
	virtual ReturnCode_t Disconnect(const UniqueIdentifier& connector_id) = 0;
	virtual ReturnCode_t DisconnectAll() = 0;

	virtual ReturnCode_t NotifyConnect(const UniqueIdentifier& connector_id) = 0;
	virtual ReturnCode_t NotifyDisconnect(const UniqueIdentifier& connector_id) = 0;

	virtual bool IsConnected(const UniqueIdentifier& connector_id) = 0;
};
}
}

#endif

