#pragma once
#include "pch.h"

namespace pm::types
{
	struct USER
	{
		size_t id;
		std::string username;
		std::string firstName;
		std::string lastName;
		uint8_t age;
		std::string passwordHash;
	};
}