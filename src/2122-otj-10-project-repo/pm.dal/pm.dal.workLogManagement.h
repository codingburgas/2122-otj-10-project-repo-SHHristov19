#pragma once
#include "pch.h"

namespace pm::dal::workLogManagement
{
	// Function for add new work log
	void createWorkLog(std::string fileName, pm::types::WORK_LOG team);

	// Function for read data from workLog file
	std::vector<std::vector<std::string>> readDataFromWorkLogFile(std::string fileName, std::string idOfUser, std::vector<int>* identification);

	// Function for getting data by id of work log
	std::vector<std::string> getWorkLogDataById(std::string fileName, int idOfWorkLog);
}