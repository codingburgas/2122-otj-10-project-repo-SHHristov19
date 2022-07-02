#pragma once
#include "pch.h"

namespace pm::dal::workLogManagement
{
	// Function for add new work log
	void createWorkLog(std::string fileName, pm::types::WORK_LOG team);
}