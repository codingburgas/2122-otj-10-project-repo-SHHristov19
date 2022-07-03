#pragma once
#include <string>

namespace pm::consoleApp::windows::warnings
{
	// Function for output successfully Login windows on given position
	void successfullyLogin(int x, int y);

	// Function for output try again windows on given position
	void tryAgain(int x, int y);

	// Function for output windows for already exists username
	void theUsernameAlreadyExists(int x, int y);

	// Function for output error for incorrect or incomplete password
	void incorrectPassword(int x, int y);
}

namespace pm::consoleApp::windows
{
	// Function for output login window as user
	void login(std::string *idOfUser);

	// Function for changing password
	void changePassword();
}