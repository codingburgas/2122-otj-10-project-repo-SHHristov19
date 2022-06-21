#pragma once
#include <string>

namespace pm::consoleApp::buttons
{
	namespace active
	{
		// Function for output painted button in a current position with set color
		void smallButton(int, int, std::string, int, int);

		// Function for output painted button in a current position with set color for admin panel
		void bigButton(int x, int y, std::string word, int nuance, int color);
	}

	namespace inactive
	{
		// Function for output button in a current position
		void smallButton(int, int, std::string);

		// Function for output button in a current position for admin panel
		void bigButton(int x, int y, std::string word);
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
}