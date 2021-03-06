#pragma once

namespace pm::consoleApp
{
	namespace buttons::userManagement
	{
		// Function for output first active user management button
		void firstActive();

		// Function for output second active user management button
		void secondActive();

		// Function for output third active user management button
		void thirdActive();

		// Function for output fourth active user management button
		void fourthActive();

		// Function for output fifth active user management button
		void fifthActive();
	}

	namespace windows::userManagement
	{
		// Function for output login window as user
		void addNewUser();

		// Function for show users list
		void showUserList(int x, int y);

		// Function for output delete windows
		void deleteUser(std::string idOfUser, int x, int y);

		// Function for edit data of user
		void editUser(std::string idOfUser, int x, int y);
	}
}