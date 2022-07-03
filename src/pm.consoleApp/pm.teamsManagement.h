#pragma once

namespace pm::consoleApp
{
	namespace buttons::teamsManagement
	{
		// Function for output first active teams management button
		void firstActive();

		// Function for output second active teams management button
		void secondActive();

		// Function for output third active teams management button
		void thirdActive();

		// Function for output fourth active teams management button
		void fourthActive();

		// Function for output fifth active teams management button
		void fifthActive();
	}

	namespace windows::teamsManagement
	{
		// Function for add new team
		void createNewTeam(std::string idOfUser, int x, int y);

		// Function for output list of teams
		void showAllTeams(int x, int y);

		// Function for deleting team
		void deleteTeam(int x, int y);

		// Function for edit data in teams.csv file
		void editTeam(std::string idOfUser, int x, int y);
	}
}