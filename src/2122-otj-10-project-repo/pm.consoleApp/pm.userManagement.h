#pragma once

namespace pm::consoleApp
{
	namespace buttons::userManagement
	{
		// Function for output first activ user management button
		void firstActive();

		// Function for output second activ user management button
		void secondActive();

		// Function for output third activ user management button
		void thirdActive();

		// Function for output fourth activ user management button
		void fourthActive();

		// Function for output fifth activ user management button
		void fifthActive();
	}

	namespace windows::userManagement
	{
		// Function for output login window as user
		void addNewUser();

		// Function for show users list
		void showUserList(int x, int y);

		// Function for output delete windows
		void deleteUser(int x, int y);

		// Function for edit data of user
		void editUser(std::string idOfUser, int x, int y);
	}
}