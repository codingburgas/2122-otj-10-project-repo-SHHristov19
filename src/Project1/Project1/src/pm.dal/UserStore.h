#pragma once
#include "pch.h"
#include "../pm.types/User.h"
#include <vector>
#include <string>

namespace pm::dal
{
	struct UserStore
	{
		void create(pm::type::User user);
		std::vector <pm::type::User> getAll();
		void remove(size_t id);
		void update(pm::type::User user);
		pm::type::User getById(size_t id);
		pm::type::User getByEmail(std::string email);
	};
}