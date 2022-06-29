#pragma once
#include "pch.h"

namespace pm::dal::taskManagement
{
	// Function for add new task
	void createTask(std::string fileName, pm::types::TASK team, std::string* idOfTask);
}