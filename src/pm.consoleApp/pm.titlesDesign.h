#pragma once

namespace pm::consoleApp::titles
{
	// Function for output main menu title in a current position
	void loginPanel(int x, int y);

	// Function for output admin panel title in a current position
	void adminPanel(int x, int y);

	// Function for output user panel title in a current position
	void userPanel(int x, int y);

	// Function for output user management title in current position
	void userManagement(int x, int y);

	// Function for output teams management title in current position
	void teamsManagement(int x, int y);

	// Finction for output task management title in current position
	void taskManagement(int x, int y);

	// Function for output project management title in current position
	void projectManagement(int x, int y);

	// Finction for output work log management title in current position
	void workLogManagement(int x, int y);
}