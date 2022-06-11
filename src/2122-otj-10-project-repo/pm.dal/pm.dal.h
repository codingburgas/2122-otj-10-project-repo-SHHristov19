#pragma once
#include "pch.h"
#include <vector>

namespace pm::dal
{
    // Function for count size of file
    std::size_t getSizeOfFile(std::string);

    // Function for login for the first time like admin
    bool loginAsFirst(std::string, std::string);

    // Function for generate id
    std::string getId(std::string);

    // Function for add data in file
    int registerUser(std::string, std::string, std::string, std::string, std::string, std::string);

    // Function for read data from file and add it in vector<string>
    std::vector<std::vector<std::string>>  readDataForUsersFromFile(std::string);

    // Function for get username and password from file
    std::vector<std::string> getUsernameAndPassword(std::string);

    // Function for check if usename and password are in the file
    bool login(std::string, std::string, std::string);
}