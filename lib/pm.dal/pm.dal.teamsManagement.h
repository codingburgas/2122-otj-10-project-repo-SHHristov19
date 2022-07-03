#pragma once
#include "pch.h"

namespace pm::dal::teamsManagement
{
	// Function for add new team in teams.csv file
    void createTeam(std::string fileName, pm::types::TEAM team);

    // Function for read data from teams file and add it in vector
    std::vector<std::vector<std::string>> readDataFromTeamsFile(std::string fileName, std::vector<int>* identification = {});

    // Function for getting data by id of team
    std::vector<std::string> getTeamDataById(std::string fileName, int idUser);

    // Function for add data infront of the matrix vector
    std::vector<std::vector<std::string>> pushFrontTitleOfTeamsFile();

    // Function for add data in file
    void addDataInTeamsFile(std::string fileName, std::vector<std::vector<std::string>> data);

    // Function for deleting team by id
    void deleteTeamByIdInTeamsFile(std::string fileName, int idOfUser);
}