#pragma once
#include <string>

namespace pm::consoleApp::buttons
{
	namespace active
	{
		// Function for output painted button in a current position with set color
		void smallButton(int x, int y, std::string word, int nuance, int color);

		// Function for output painted button in a current position with set color for admin panel
		void bigButton(int x, int y, std::string word, int nuance, int color);
	}

	namespace inactive
	{
		// Function for output button in a current position
		void smallButton(int x, int y, std::string word);

		// Function for output button in a current position for admin panel
		void bigButton(int x, int y, std::string word);
	}

	namespace loginPanel
	{
		// Function for output first active main menu button
		void firstActive();

		// Function for output second active main menu button
		void secondActive();

		// Function for output third active main menu button
		void thirdActive();
	}

	namespace adminPanel
	{
		// Function for output first active admin panel button
		void firstActive();

		// Function for output second active admin panel button
		void secondActive();

		// Function for output third active admin panel button
		void thirdActive();
	}

	namespace userPanel
	{
		// Function for output first active user panel button
		void firstActive();

		// Function for output second active user panel button
		void secondActive();

		// Function for output third active user panel button
		void thirdActive();

		// Function for output fourth active user panel button
		void fourthActive();
	}
}