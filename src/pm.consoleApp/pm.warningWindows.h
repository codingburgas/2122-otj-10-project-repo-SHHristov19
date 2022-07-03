#pragma once

namespace pm::consoleApp::windows::warnings
{
	// Function for output successfully Login windows on given position
	void successfullyLogin(int, int);

	// Function for output try again windows on given position
	void tryAgain(int, int);

	// Function for output windows for already exists username
	void theUsernameAlreadyExists(int, int);

	// Function for output error for incorrect or incomplete password
	void incorrectPassword(int, int);
}

namespace pm::consoleApp::windows
{
	// Function for output login window as user
	void login();

	// Function for changing password
	void changePassword();
}