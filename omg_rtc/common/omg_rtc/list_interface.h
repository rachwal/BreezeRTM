// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_COMMON_LIST_INTERFACE_H_
#define OMG_RTC_COMMON_LIST_INTERFACE_H_

namespace breeze_rtm
{
namespace omg_rtc
{
template<class type>
class ListInterface
{
	public:
	virtual ~ListInterface() {}

	virtual unsigned long maximum() const = 0;
	virtual void length(unsigned long) = 0;
	virtual unsigned long length() const = 0;
	virtual type &operator[](unsigned long index) = 0;
	virtual const type &operator[](unsigned long index) const = 0;
	virtual bool release() const = 0;
	virtual void replace(unsigned long max, unsigned long length, type* data, bool release = false) = 0;
	virtual type *get_buffer(bool orphan = false) = 0;
	virtual const type *get_buffer() const = 0;
};
}
}

#endif

