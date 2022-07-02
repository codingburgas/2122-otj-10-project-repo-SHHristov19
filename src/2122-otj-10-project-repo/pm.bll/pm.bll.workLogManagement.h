#pragma once
#include "pch.h"

namespace pm::bll::workLogManagement
{
	// Function for edit work log data
	void editWorkLogById(std::string fileName, int idOfWorkLog, int idOfEditData, std::string newData);
}