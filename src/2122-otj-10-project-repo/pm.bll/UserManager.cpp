#include "pch.h"
#include "..\pm.dal\UserStore.h"
#include "UserManager.h"

std::string pm::bll::USER_MANAGER::hashString(std::string str)
{
	return std::string();
}

void pm::bll::USER_MANAGER::registerUser(std::string firsName, std::string lastName, uint8_t age, std::string email, std::string password)
{
}

pm::types::USER pm::bll::USER_MANAGER::loginUser(std::string username, std::string password)
{
	return pm::types::USER();
}

std::vector<pm::types::USER> pm::bll::USER_MANAGER::getRegisteredUser()
{
	return std::vector<pm::types::USER>();
}

void pm::bll::USER_MANAGER::seedDatabase()
{
}

void pm::bll::USER_MANAGER::removeUser(size_t id)
{
}

void pm::bll::USER_MANAGER::updateUser(pm::types::USER)
{
}
