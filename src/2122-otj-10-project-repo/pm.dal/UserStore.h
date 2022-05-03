#pragma once
#include "pch.h"
#include "../pm.types/User.h"
#include <vector>
#include <string>

namespace pm::dal
{
	struct UserStore
	{
		void create(pm::types::User user);
		std::vector <pm::types::User> getAll();
		void remove(size_t id);
		void update(pm::types::User user);
		pm::types::User getById(size_t id);
		pm::types::User getByEmail(std::string email);
	};
}