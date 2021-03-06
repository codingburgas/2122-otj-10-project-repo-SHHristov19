#pragma once
#include <string>

namespace pm::consoleApp
{
	namespace buttons::taskManagement
	{
		// Function for output first active task management button
		void firstActive();

		// Function for output second active task management button
		void secondActive();

		// Function for output third active task management button
		void thirdActive();

		// Function for output fourth active task management button
		void fourthActive();

		// Function for output fifth active task management button
		void fifthActive();
	}

	namespace windows::taskManagement
	{
		// Function for add task in a project
		void chooseProjectForWorkWithTask(std::string idOfUser, int x, int y);

		// Function for create task in a project
		void createTask(std::string idOfUser, std::string idOfProject, int x, int y);

		// Function for show all task in a project
		void showAllTask(std::string idOfUser, std::string idOfProject, int x, int y);

		// Function for delete task
		void deleteTask(std::string idOfUser, std::string idOfProject, int x, int y);

		// Function for edit data in a task
		void editTask(std::string idOfUser, std::string idOfProject, int x, int y);
	}
}