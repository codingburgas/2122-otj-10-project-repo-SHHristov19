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

    // Function for checking already existing username
    bool checkForExistedUser(std::string fileName, std::string username);

    // Function for checking already existing password
    bool checkForExistsPassword(std::string fileName, std::string password);

    // Function for replace password in vector
    void replaceData(std::vector<std::vector<std::string>>*data, std::string password, std::string username, std::string newPassword);

    // Function for add data infront of the matrix vector
    std::vector<std::vector<std::string>> pushFrontTitleOfFile(std::vector<std::vector<std::string>> data);

    // Function for add data in file
    void printDataInFile(std::string fileName, std::vector<std::vector<std::string>> data);

    // Function for replacing password in file 
    void cnagePassword(std::string fileName, std::string password, std::string username, std::string newPassword);
}