#pragma once
#include "pch.h"
#include "..\pm.dal\UserStore.h"

namespace pm::bll
{
	struct USER_MANAGER
	{
		pm::dal::USER_STORE m_userStore;
		std::string hashString(std::string str);

		void registerUser(std::string firsName, std::string lastName, uint8_t age,
			std::string email, std::string password);
		pm::types::USER loginUser(std::string username, std::string password);
		std::vector<pm::types::USER> getRegisteredUser();

		void seedDatabase();

		void removeUser(size_t id);

		void updateUser(pm::types::USER);
	};
}