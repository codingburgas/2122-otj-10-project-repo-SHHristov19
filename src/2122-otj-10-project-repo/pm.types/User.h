#pragma once
#include "pch.h"

namespace pm::types
{
	struct USER
	{
		std::string id;
		std::string firstName;
		std::string lastName;
		std::string username;
		std::string password;
		std::string age;
		std::string timeOfRegistration;
		std::string lastLogin;
		std::string role;
	};
}