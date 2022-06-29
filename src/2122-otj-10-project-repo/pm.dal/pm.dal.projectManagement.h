#pragma once
#include "pch.h"
#include "../pm.types/structures.h"

namespace pm::dal::projectManagement
{
    // Function for add new project in projects.csv file
    void createProject(std::string fileName, pm::types::PROJECT team);

    // Function for read data from project file and add it in vector
    std::vector<std::vector<std::string>> readDataFromProjectsFile(std::string fileName, std::vector<int>* identification = {});

    // Function for getting data by id of team
    std::vector<std::string> getProjetctDataById(std::string fileName, int idUser);

    // Function for add data infront of the matrix vector
    std::vector<std::vector<std::string>> pushFrontTitleOfProjectsFile();

    // Function for add data in project file
    void addDataInProjectsFile(std::string fileName, std::vector<std::vector<std::string>> data);

    // Function for deleting project by id
    void deleteProjectByIdInProjectsFile(std::string fileName, int idOfProject, std::string idOfUser);
}