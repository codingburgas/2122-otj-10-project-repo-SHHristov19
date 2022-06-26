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

	struct TEAM
	{
		std::string id;
		std::string name;
		std::string idOfCreator;
		std::string dataOfCreation;
		std::string dataOfLastChanges;
		std::string idOfLastChanger;
		std::string contributors;
	};

	struct PROJECT
	{
		std::string id;
		std::string title;
		std::string description;
		std::string dataOfCreation;
		std::string idOfCreator;
		std::string dataOfLastChanges;
		std::string idOfLastChanger;
		std::string IdOfTeam;
		std::string IdOfTasks;
	};
}