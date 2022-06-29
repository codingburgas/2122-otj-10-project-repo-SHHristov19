#pragma once
#include "pch.h"
#include "../pm.types/structures.h"

namespace pm::dal::login
{
    // Function for login for the first time like admin
    bool loginAsFirst(pm::types::USER user);

    // Function for check if usename and password are in the file
    bool login(std::string fileName, pm::types::USER* user, std::string* idOfUser);

    // Function for replacing password in file 
    void cnagePassword(std::string fileName, pm::types::USER data, std::string newPassword);
}