#pragma once
#include "pch.h"

namespace pm::dal::taskManagement
{
	// Function for add new task
	void createTask(std::string fileName, pm::types::TASK team, std::string* idOfTask);

	// Function for read data from task file and add it in vector
	std::vector<std::vector<std::string>> readDataFromTaskFile(std::string fileName, std::string idOfProject, std::vector<int>* identification = {});

	// Function for getting data by id of task
	std::vector<std::string> getTaskDataById(std::string fileName, int idOfTask);
}