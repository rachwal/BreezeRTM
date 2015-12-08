// BreezeRTM
// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#ifndef OPENRTM_UTILS_STRINGS_H_
#define OPENRTM_UTILS_STRINGS_H_

#include <sstream>
#include <vector>

namespace breeze_rtm
{
namespace utils
{
class Strings
{
	public:

	static std::vector<std::string> split(const std::string& s, char delimiter)
	{
		//ref http://stackoverflow.com/a/236803/5329823
		std::vector<std::string> strings;
		std::stringstream stringstream(s);
		std::string element;

		while (getline(stringstream, element, delimiter))
		{
			strings.push_back(element);
		}
		return strings;
	}
};
}
}

#endif

