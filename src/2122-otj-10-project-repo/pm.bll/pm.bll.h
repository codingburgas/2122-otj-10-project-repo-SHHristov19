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

    // Function for searching project without team
    void findProjectWithoutTeam(std::vector<std::vector<std::string>> data, std::string idOfUser, std::vector<int>* idOfProjectContainsUser);

    // Function for add team in project
    void editIdOfTeam(std::vector<std::vector<std::string>> data, std::vector<std::vector<std::string>> allData, int idOfProject, int idOfTeam, std::string fileName);

    // Function for edit team name or colaborators
    void editTeamById(std::string fileName, std::vector<std::vector<std::string>> data, int idOfTeam, int idOfEditData, std::string newData, std::string idOfUser);

    // Function for edit user data
    void editUserById(std::string fileName, std::vector<std::vector<std::string>> data, int idOfUser, int idOfEditData, std::string newData);
}