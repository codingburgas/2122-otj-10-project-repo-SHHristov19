#pragma once
#include "pch.h"

namespace pm::types
{
	struct User
	{
		size_t id;
		std::string firstName;
		std::string lastName;
		std::string email;
		unsigned short age;
		std::string passwordHash;
		std::tm createdOn;
	};
}