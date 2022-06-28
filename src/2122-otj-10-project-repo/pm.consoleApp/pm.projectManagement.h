#pragma once

namespace pm::consoleApp
{
	namespace buttons::projectManagement
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

		// Function for output sixth activ project management button
		void sixthActive();
	}

	namespace windows::projectsManagement
	{
		// Function for create project
		void createProject(std::string idOfUser, int x, int y);

		// Function for output list of projects
		void showAllProjects(std::string idOfUser, int x, int y);

		// Function for delete data from project file
		void deleteProject(std::string idOfUser, int x, int y);

		// Function for add team in projetc
		void addTeamInProject(std::string idOfUser, int x, int y);
	}
}