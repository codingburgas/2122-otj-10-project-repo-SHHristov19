#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "pch.h"

namespace pm::bll
{
    // Function for get time
    std::string currentDateTime();

    // Function for checks if the password contains the followin special characters
    bool checkPasswordForSpecialCharacters(char[], std::size_t);

    // Function for checking if name contain charecters
    bool checkStringForSpecialCharacters(std::string);

    // Function for converting the password from type string to type char and checks with checkPasswordForSpecialCharacters()
    bool checkPassword(std::string);

    // Function for hash password
    std::string hashPassword(std::string password);

    // Function for adding id of team that the user contain in team colaborators
    void checkForContainUserInTeam(std::vector<std::vector<std::string>> data, std::string idOfUser, std::vector<int>* idOfProjectContainsUser);

    // Function for adding id of project that the user contain in team colaborators
    void checkProjectForContainUserInTeam(std::vector<std::vector<std::string>> data, std::string idOfUser, std::vector<int>* idOfProjectContainsUser);

    // Function for get data by id of projects
    std::vector<std::vector<std::string>> getDataById(std::vector<int> idOfProject, std::vector<std::vector<std::string>> data);
}