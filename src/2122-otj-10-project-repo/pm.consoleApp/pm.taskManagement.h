#pragma once
#include <string>

namespace pm::consoleApp
{
	namespace buttons::taskManagement
	{
		// Function for output first activ project management button
		void firstActive();

		// Function for output second activ project management button
		void secondActive();

		// Function for output third activ project management button
		void thirdActive();

		// Function for output fourth activ project management button
		void fourthActive();

		// Function for output fifth activ project management button
		void fifthActive();
	}

	namespace windows::taskManagement
	{
		// Function for add task in a project
		void createTask(std::string idOfUser, int x, int y);
	}
}