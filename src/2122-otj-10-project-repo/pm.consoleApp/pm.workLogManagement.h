#pragma once
#include "string"

namespace pm::consoleApp
{
	namespace buttons::workLogManagement
	{
		// Function for output first activ work log management button
		void firstActive();

		// Function for output second activ work log management button
		void secondActive();

		// Function for output third activ work log management button
		void thirdActive();

		// Function for output fourth activ work log management button
		void fourthActive();

		// Function for output fifth activ work log management button
		void fifthActive();
	}

	namespace windows::workLogManagement
	{
		// Function for choose task that you want to see, add, edit and delete work log
		void chooseTaskForWorkLog(std::string idOfUser, int x, int y);
	}
}