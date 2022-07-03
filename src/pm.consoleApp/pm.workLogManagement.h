#pragma once
#include "string"

namespace pm::consoleApp
{
	namespace buttons::workLogManagement
	{
		// Function for output first active work log management button
		void firstActive();

		// Function for output second active work log management button
		void secondActive();

		// Function for output third active work log management button
		void thirdActive();

		// Function for output fourth active work log management button
		void fourthActive();

		// Function for output fifth active work log management button
		void fifthActive();
	}

	namespace windows::workLogManagement
	{
		// Function for choose task that you want to see, add, edit and delete work log
		void chooseTaskForWorkLog(std::string idOfUser, int x, int y);

		// Function for add work log in a task
		void createWorkLog(std::string idOfUser, std::string idOfTask);

		// Function for show all work log in a task
		void showAllWorkLog(std::string idOfUser, std::string idOfTask, int x, int y);

		// Function for delete work log in the task
		void deleteWorkLog(std::string idOfUser, std::string idOfTask, int x, int y);

		// Function for edit data in work log
		void editWorkLog(std::string idOfUser, std::string idOfTask, int x, int y);
	}
}