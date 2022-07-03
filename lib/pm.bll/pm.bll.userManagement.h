#pragma once
#include "pch.h"

namespace pm::bll::userManagement
{
    // Function for edit user data
    void editUserById(std::string fileName, int idOfUser, int idOfEditData, std::string newData);
}