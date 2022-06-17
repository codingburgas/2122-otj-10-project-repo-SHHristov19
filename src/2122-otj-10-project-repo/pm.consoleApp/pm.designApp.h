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
		void loginPanel(int, int);

		// Function for output admin panel title in a current position
		void adminPanel(int x, int y);

		// Function for output user panel title in a current position
		void userPanel(int x, int y);

		// Function for output user management title in current position
		void userManagement(int x, int y);
	}

	namespace buttons
	{
		namespace active
		{
			// Function for output painted button in a current position with set color
			void smallButton(int, int, string, int, int);

			// Function for output painted button in a current position with set color for admin panel
			void bigButton(int x, int y, string word, int nuance, int color);
		}
		
		namespace inactive
		{
			// Function for output button in a current position
			void smallButton(int, int, string);

			// Function for output button in a current position for admin panel
			void bigButton(int x, int y, string word);
		}

		namespace loginPanel
		{
			// Function for output first activ main menu button
			void firstActive();

			// Function for output second activ main menu button
			void secondActive();

			// Function for output third activ main menu button
			void thirdActive();
		}

		namespace adminPanel
		{
			// Function for output first activ admin panel button
			void firstActive();

			// Function for output second activ admin panel button
			void secondActive();

			// Function for output third activ admin panel button
			void thirdActive();
		}

		namespace userPanel
		{
			// Function for output first activ user panel button
			void firstActive();

			// Function for output second activ user panel button
			void secondActive();

			// Function for output third activ user panel button
			void thirdActive();

			// Function for output fourt activ user panel button
			void fourthActive();
		}

		namespace userManagement
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

		// Function for output login window as user
		void registerUser();

		// Function for changing password
		void changePassword();
	}

	namespace menus
	{
		// Function for movement in user management
		void userManagement();

		// Function for movement in admin panel
		void adminPanel();

		// Function for movement in user panel
		void userPanel();

		// Function for movement in main Menu
		void menu();
	}
}