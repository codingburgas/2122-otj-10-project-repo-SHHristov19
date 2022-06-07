#include "pch.h"
#include "UserStore.h"
#include "../pm.types/User.h"

std::vector<pm::types::USER> users;

void pm::dal::USER_STORE::create(pm::types::USER& user)
{
}

pm::types::USER pm::dal::USER_STORE::getById(size_t id)
{
	return pm::types::USER();
}

pm::types::USER pm::dal::USER_STORE::getByEmail(std::string email)
{
	return pm::types::USER();
}

std::vector<pm::types::USER> pm::dal::USER_STORE::getAll()
{
	return std::vector<pm::types::USER>();
}

void pm::dal::USER_STORE::remove(size_t)
{
}

void pm::dal::USER_STORE::update(pm::types::USER user)
{
}
