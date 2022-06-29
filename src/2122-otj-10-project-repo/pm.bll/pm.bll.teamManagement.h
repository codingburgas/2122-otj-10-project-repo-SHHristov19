#pragma once
#include "pch.h"

namespace pm::bll::teamsManagement
{
    // Function for adding id of team that the user contain in team colaborators
    void checkForContainUserInTeam(std::vector<std::vector<std::string>> data, std::string idOfUser, std::vector<int>* idOfTeamContainsUser);

    // Function for edit team name or colaborators
    void editTeamById(std::string fileName, std::vector<std::vector<std::string>> data, int idOfTeam, int idOfEditData, std::string newData, std::string idOfUser);
}