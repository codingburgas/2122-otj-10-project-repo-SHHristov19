#pragma once
#include "pch.h"

namespace pm::bll::taskManagement
{
    // Fimction for add task in the project
    void addTaskInProject(std::string idOfProject, std::string idOfTask);

    // Function for edit task data
    void editTaskById(std::string fileName, int idOfTask, int idOfEditData, std::string newData, std::string idOfUser);
}