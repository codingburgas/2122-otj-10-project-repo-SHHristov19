#include "pch.h"
#include "..\pm.dal\UserStore.h"
#include "UserManager.h"

std::string pm::bll::UserManager::hashString(std::string str)
{
	return std::string();
}

void pm::bll::UserManager::registerUser(std::string firstName, std::string lastName, uint8_t age, std::string email, std::string password)
{
}

pm::types::User pm::bll::UserManager::loginUser(std::string username, std::string password)
{
	return pm::types::User();
}

std::vector<pm::types::User> pm::bll::UserManager::getRegisteredUsers()
{
	return std::vector<pm::types::User>();
}

void pm::bll::UserManager::seedDatabase()
{
}

void pm::bll::UserManager::removeUser(size_t id)
{
}

void pm::bll::UserManager::updateUser(pm::types::User)
{
}
