#pragma once
#include <string>

namespace pm::consoleApp::menus
{
	// Function for movement in work log management
	void workLogManagement(std::string idOfUser, std::string idOfTask);

	// Function for movement in task management
	void taskManagement(std::string idOfUser, std::string idOfProject);

	// Function for movement in project management
	void projectManagement(std::string idOfUser);

	// Function for movement in teams management
	void teamsManagement(std::string idOfUser);

	// Function for movement in user management
	void userManagement(std::string idOfUser);

	// Function for movement in admin panel
	void adminPanel(std::string idOfUser);

	// Function for movement in user panel
	void userPanel(std::string idOfUser);

	// Function for movement in main Menu
	void menu();
}