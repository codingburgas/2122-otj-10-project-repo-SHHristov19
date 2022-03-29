#include "pch.h"
#include "UserStore.h"
#include "../pm.types/User.h"
#include <vector>

std::vector<pm::type::User> users;

void pm::dal::UserStore::create(pm::type::User user)
{
	// If the user exists(check email) - throw exception 
	// ako nashiq potrebitel veche susteshtvyva
	users.push_back(user);
}

std::vector<pm::type::User> pm::dal::UserStore::getAll()
{
	return std::vector<pm::type::User>();
}

void pm::dal::UserStore::remove(size_t id)
{
}

void pm::dal::UserStore::update(pm::type::User user)
{
}

pm::type::User pm::dal::UserStore::getById(size_t id)
{
	return pm::type::User();
}

pm::type::User pm::dal::UserStore::getByEmail(std::string email)
{
	return pm::type::User();
}
