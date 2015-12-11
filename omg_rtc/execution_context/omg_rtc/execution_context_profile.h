// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_PROFILE_H_
#define OMG_RTC_EXECUTION_CONTEXT_EXECUTION_CONTEXT_PROFILE_H_

#include "execution_kind.h"

#include <list>

namespace breeze_rtm
{
namespace omg_rtc
{
class RTObject;

class ExecutionContextProfile
{
	public:
	explicit ExecutionContextProfile(ExecutionKind kind) : kind_(kind), rate_(0), owner(nullptr)
	{
		participants_ = new std::list<RTObject*>();
	};

	double rate() const
	{
		return rate_;
	}

	void rate(const double& value)
	{
		rate_ = value;
	}

	ExecutionKind kind() const
	{
		return kind_;
	};

	void kind(const ExecutionKind& value)
	{
		kind_ = value;
	}

	private:
	ExecutionKind kind_;
	double rate_;
	RTObject* owner;
	std::list<RTObject*>* participants_;
};
}
}

#endif

