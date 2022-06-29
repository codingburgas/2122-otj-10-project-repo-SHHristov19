#pragma once
#include "pch.h"
#include "../pm.types/User.h"

namespace pm::dal::userManagement
{
    // Function for add data in file
    int registerUser(std::string fileName, pm::types::USER user);

    // Function for read data from file and add it in vector<string>
    std::vector<std::vector<std::string>>  readDataFromUsersFile(std::string fileName);

    // Function for get username and password from file
    std::vector<std::string> getUsernameAndPassword(std::string fileName);

    // Function for read data from file for id, username, firstName and LastName
    std::vector<std::vector<std::string>> readDataForIdUsernameFirstAndLastName(std::string fileName, std::vector<int>* identification, std::string idOfUser = "");

    // Function for getting data by id of user
    std::vector<std::string> getUserDataById(std::string fileName, int idUser);

    // Function for replace time of last login
    void replaceLastLoginTime(std::vector<std::vector<std::string>>* data, pm::types::USER* user);

    // Function for geting id of user by username
    std::string getIdOfUserByUsername(std::string fileName, pm::types::USER user);

    // Function for checking already existing username
    bool checkForExistedUser(std::string fileName, std::string username);

    // Function for checking already existing password
    bool checkForExistsPassword(std::string fileName, std::string password);

    // Function for replace password in vector
    void replaceDataInUsersFile(std::vector<std::vector<std::string>>* data, pm::types::USER user, std::string newPassword);

    // Function for add data infront of the matrix vector
    std::vector<std::vector<std::string>> pushFrontTitleOfUsersFile(std::vector<std::vector<std::string>> data);

    // Function for add data in file
    void addDataInUsersFile(std::string fileName, std::vector<std::vector<std::string>> data);

    // Function for geleting user by id
    void deleteUserByIdInUsersFile(std::string fileName, int id);
}