#pragma once
#include "pch.h"

namespace pm::bll::projectManagement
{
    // Function for adding id of project that the user contain in team colaborators
    void checkProjectForContainUserInTeam(std::vector<std::vector<std::string>> data, std::string idOfUser, std::vector<int>* idOfProjectContainsUser);

    // Function for get data by id of projects
    std::vector<std::vector<std::string>> getDataById(std::vector<int> id, std::vector<std::vector<std::string>> data);

    // Function for searching project without team
    void findProjectWithoutTeam(std::vector<std::vector<std::string>> data, std::string idOfUser, std::vector<int>* idOfProjectContainsUser);

    // Function for add team in project
    void editIdOfTeam(std::vector<std::vector<std::string>> data, std::vector<std::vector<std::string>> allData, int idOfProject, int idOfTeam, std::string fileName);

    // Function for project data
    void editProjectById(std::string fileName, std::vector<std::vector<std::string>> data, int idOfProject, int idOfEditData, std::string newData, std::string idOfUser);
}