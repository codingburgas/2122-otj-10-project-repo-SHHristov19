#pragma once

#include <iostream>
#include <string>
#include <conio.h>
#include "..\pm.tools\pm.tools.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define	KEY_ENTER 13

using namespace std;

namespace pm::designApp
{
	namespace titles
	{
		// Function for output main menu title in a current position
		void projectManagerMenu(int, int);
	}

	namespace buttons
	{
		namespace active
		{
			// Function for output painted button in a current position with set color
			void buttonLogin(int, int, string, int, int);
		}

		// Function for output button in a current position
		namespace inactive
		{
			void buttonLogin(int, int, string);
		}

		namespace mainMenu
		{
			// Function for output first activ main menu button
			void firstActive();

			// Function for output second activ main menu button
			void secondActive();

			// Function for output third activ main menu button
			void thirdActive();

			// Function for output fourth activ main menu button
			void fourthActive();
		}
	}

	namespace windows
	{
		namespace warnings
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

		// Function for output login window as user
		void login();

		// Function for checking already existing username
		bool checkForExistedUser(string, string);

		// Function for output login window as user
		void registerUser();
	}

	namespace menus
	{
		// Function for movement in main Menu
		void menu();
	}
}