#include <iostream>
#include <string>
#include <conio.h>

#include "../pm.consoleApp/pm.menus.h"
#include "../pm.consoleApp/pm.userManagement.h"
#include "../pm.consoleApp/pm.teamsManagement.h"
#include "../pm.consoleApp/pm.projectManagement.h"
#include "../pm.consoleApp/pm.titlesDesign.h"
#include "../pm.consoleApp/pm.userManagement.h"
#include "../pm.consoleApp/pm.buttonsDesign.h"

#include "../pm.tools/pm.tools.h"
#include "../pm.dal/pm.dal.h"
#include "../pm.bll/pm.bll.h"
#include "../pm.types/User.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define	KEY_ENTER 13

namespace pm::consoleApp
{
	namespace titles
	{
		// Function for output main menu title in a current position
		void loginPanel(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << " _                 _                                  _ " << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "| |               (_)                                | |" << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << "| |     ___   ____ _ ____     ____   ____ ____   ____| |" << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "| |    / _ \\ / _  | |  _ \\   |  _ \\ / _  |  _ \\ / _  ) |" << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "| |___| |_| ( ( | | | | | |  | | | ( ( | | | | ( (/ /| |" << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << "|______)___/ \\_|| |_|_| |_|  | ||_/ \\_||_|_| |_|\\____)_|" << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "            (_____|          |_|  						 " << endl;
		}

		// Function for output admin panel title in a current position
		void adminPanel(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << "   /\\       _       _                                  _ " << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "  /  \\     | |     (_)                                | |" << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << " / /\\ \\  _ | |____  _ ____     ____   ____ ____   ____| |" << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "| |__| |/ || |    \\| |  _ \\   |  _ \\ / _  |  _ \\ / _  ) |" << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "|  __  | (_| | | | | | | | |  | | | ( ( | | | | ( (/ /| |" << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << "|_|  |_|\\____|_|_|_|_|_| |_|  | ||_/ \\_||_|_| |_|\\____)_|" << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "                              |_|						  " << endl;
		}

		// Function for output user panel title in a current position
		void userPanel(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << " _    _                                             _ " << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "| |  | |                                           | |" << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << "| |  | | ___  ____  ____    ____   ____ ____   ____| |" << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "| |  | |/___)/ _  )/ ___)  |  _ \\ / _  |  _ \\ / _  ) |" << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "| |__| |___ ( (/ /| |      | | | ( ( | | | | ( (/ /| |" << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << " \\_____(___/ \\____)_|      | ||_/ \\_||_|_| |_|\\____)_|" << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "                           |_|          			   " << endl;
		}

		// Function for output user management title in current position
		void userManagement(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << " _    _                  																" << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "| |  | |                                                                          _    " << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << "| |  | | ___  ____  ____    ____   ____ ____   ____  ____  ____ ____   ____ ____ | |_  " << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "| |  | |/___)/ _  )/ ___)  |    \\ / _  |  _ \\ / _  |/ _  |/ _  )    \\ / _  )  _ \\|  _) " << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "| |__| |___ ( (/ /| |      | | | ( ( | | | | ( ( | ( ( | ( (/ /| | | ( (/ /| | | | |__ " << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << " \\_____(___/ \\____)_|      |_|_|_|\\_||_|_| |_|\\_||_|\\_|| |\\____)_|_|_|\\____)_| |_|\\___)" << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "                                                   (_____| 							" << endl;
		}

		// Function for output teams management title in current position
		void teamsManagement(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << " _______                      																 " << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "(_______)                                                                              _    " << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << "   | |  ____ ____ ____   ___     ____   ____ ____   ____  ____  ____ ____   ____ ____ | |_  " << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "   | | / _  ) _  |    \\ /___)   |    \\ / _  |  _ \\ / _  |/ _  |/ _  )    \\ / _  )  _ \\|  _) " << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "   | |( (/ ( ( | | | | |___ |   | | | ( ( | | | | ( ( | ( ( | ( (/ /| | | ( (/ /| | | | |__ " << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << "   |_| \\____)_||_|_|_|_(___/    |_|_|_|\\_||_|_| |_|\\_||_|\\_|| |\\____)_|_|_|\\____)_| |_|\\___)" << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "                                                        (_____| 							 " << endl;
		}

		// Function for output project management title in current position
		void projectManagement(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << " ______           _                 																   " << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "(_____ \\         (_)           _                                                                 _    " << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << " _____) )___ ___  _  ____ ____| |_         ____   ____ ____   ____  ____  ____ ____   ____ ____ | |_  " << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "|  ____/ ___) _ \\| |/ _  ) ___)  _)       |    \\ / _  |  _ \\ / _  |/ _  |/ _  )    \\ / _  )  _ \\|  _) " << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "| |   | |  | |_| | ( (/ ( (___| |__       | | | ( ( | | | | ( ( | ( ( | ( (/ /| | | ( (/ /| | | | |__ " << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << "|_|   |_|   \\___/| |\\____)____)\\___)      |_|_|_|\\_||_|_| |_|\\_||_|\\_|| |\\____)_|_|_|\\____)_| |_|\\___)" << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "               (__/                                               (_____| 							   " << endl;
		}
	}

	namespace buttons
	{
		namespace active
		{
			// Functions for output painted button in a current position with set color for login panel
			void smallButton(int x, int y, string word, int nuance, int color)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << "\x1b[" << nuance << ";3" << color << "m" << " .-----------------. " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "\x1b[" << nuance << ";3" << color << "m" << "(" << word << ")" << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << "\x1b[" << nuance << ";3" << color << "m" << " '-----------------' " << "\x1b[1;37m" << endl;
			}

			// Function for output painted button in a current position with set color for admin panel
			void bigButton(int x, int y, string word, int nuance, int color)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << "\x1b[" << nuance << ";3" << color << "m" << "  _________________________ " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "\x1b[" << nuance << ";3" << color << "m" << " /                         \\" << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << "\x1b[" << nuance << ";3" << color << "m" << "<" << word << ">" << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 3);
				cout << "\x1b[" << nuance << ";3" << color << "m" << " \\_________________________/ " << "\x1b[1;37m" << endl;
			}
		}

		namespace inactive
		{
			// Function for output button in a current position for login panel
			void smallButton(int x, int y, string word)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << " .-----------------. " << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "(" << word << ")" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << " '-----------------' " << endl;
			}

			// Function for output button in a current position for admin panel
			void bigButton(int x, int y, string word)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << "  _________________________ " << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << " /                         \\" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << "<" << word << ">" << endl;
				pm::tools::consoleCoordinates(x, y + 3);
				cout << " \\_________________________/ " << endl;
			}
		}

		namespace loginPanel
		{
			// Function for output first activ main menu button
			void firstActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::loginPanel(45, 7);
				buttons::active::bigButton(60, 19,   "           LOGIN           ", 0, 3);
				buttons::inactive::bigButton(60, 26, "        CHANGE PASS        ");
				buttons::inactive::bigButton(60, 33, "            EXIT           ");
			}

			// Function for output second activ main menu button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::loginPanel(45, 7);
				buttons::inactive::bigButton(60, 19, "           LOGIN           ");
				buttons::active::bigButton(60, 26,   "        CHANGE PASS        ", 0, 3);
				buttons::inactive::bigButton(60, 33, "            EXIT           ");
			}

			// Function for output third activ main menu button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::loginPanel(45, 7);
				buttons::inactive::bigButton(60, 19, "           LOGIN           ");
				buttons::inactive::bigButton(60, 26, "        CHANGE PASS        ");
				buttons::active::bigButton(60, 33,   "            EXIT           ", 0, 3);
			}
		}

		namespace adminPanel
		{
			// Function for output first activ admin panel button
			void firstActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::adminPanel(45, 8);
				buttons::active::bigButton(60, 19,   "      USER MANAGEMENT      ", 0, 6);
				buttons::inactive::bigButton(60, 26, "      TEAMS MANAGEMENT     ");
				buttons::inactive::bigButton(60, 33, "           EXIT            ");
			}

			// Function for output second activ admin panel button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::adminPanel(45, 8);
				buttons::inactive::bigButton(60, 19, "      USER MANAGEMENT      ");
				buttons::active::bigButton(60, 26,   "      TEAMS MANAGEMENT     ", 0, 6);
				buttons::inactive::bigButton(60, 33, "           EXIT            ");
			}

			// Function for output third activ admin panel button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::adminPanel(45, 8);
				buttons::inactive::bigButton(60, 19, "      USER MANAGEMENT      ");
				buttons::inactive::bigButton(60, 26, "      TEAMS MANAGEMENT     ");
				buttons::active::bigButton(60, 33,   "           EXIT            ", 0, 6);
			}
		}

		namespace userPanel
		{
			// Function for output first activ admin panel button
			void firstActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::userPanel(47, 8);
				buttons::active::bigButton(60, 19,   "     PROJECT MANAGEMENT    ", 1, 2);
				buttons::inactive::bigButton(60, 25, "      TASK MANAGEMENT      ");
				buttons::inactive::bigButton(60, 31, "     WORK LOG MANAGEMENT   ");
				buttons::inactive::bigButton(60, 37, "           EXIT            ");
			}

			// Function for output second activ admin panel button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::userPanel(47, 8);
				buttons::inactive::bigButton(60, 19, "     PROJECT MANAGEMENT    ");
				buttons::active::bigButton(60, 25,   "      TASK MANAGEMENT      ", 1, 2);
				buttons::inactive::bigButton(60, 31, "     WORK LOG MANAGEMENT   ");
				buttons::inactive::bigButton(60, 37, "           EXIT            ");
			}

			// Function for output third activ admin panel button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::userPanel(47, 8);
				buttons::inactive::bigButton(60, 19, "     PROJECT MANAGEMENT    ");
				buttons::inactive::bigButton(60, 25, "      TASK MANAGEMENT      ");
				buttons::active::bigButton(60, 31,   "     WORK LOG MANAGEMENT   ", 1, 2);
				buttons::inactive::bigButton(60, 37, "           EXIT            ");
			}

			// Function for output fourt activ admin panel button
			void fourthActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::userPanel(47, 8);
				buttons::inactive::bigButton(60, 19, "     PROJECT MANAGEMENT    ");
				buttons::inactive::bigButton(60, 25, "      TASK MANAGEMENT      ");
				buttons::inactive::bigButton(60, 31, "     WORK LOG MANAGEMENT   ");
				buttons::active::bigButton(60, 37,   "           EXIT            ", 1, 2);
			}
		}

		namespace userManagement
		{
			// Function for output first activ user management button
			void firstActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::userManagement(30, 7);
				buttons::active::smallButton(63, 17,   "     VIEW ALL      ", 1, 5);
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output second activ user management button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::userManagement(30, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::active::smallButton(63, 22,   "       CREATE      ", 1, 5);
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output third activ user management button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::userManagement(30, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::active::smallButton(63, 27,   "        EDIT       ", 1, 5);
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output fourth activ user management button
			void fourthActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::userManagement(30, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::active::smallButton(63, 32,   "       DELETE      ", 1, 5);
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output fifth activ user management button
			void fifthActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::userManagement(30, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::active::smallButton(63, 37,   "        EXIT       ", 1, 5);
			}
		}

		namespace teamsManagement
		{
			// Function for output first activ teams management button
			void firstActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::teamsManagement(28, 7);
				buttons::active::smallButton(63, 17,   "     VIEW ALL      ", 1, 1);
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output second activ teams management button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::teamsManagement(28, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::active::smallButton(63, 22,   "       CREATE      ", 1, 1);
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output third activ teams management button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::teamsManagement(28, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::active::smallButton(63, 27,   "        EDIT       ", 1, 1);
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output fourth activ teams management button
			void fourthActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::teamsManagement(28, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::active::smallButton(63, 32,   "       DELETE      ", 1, 1);
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output fifth activ teams management button
			void fifthActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::teamsManagement(28, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::active::smallButton(63, 37,   "        EXIT       ", 1, 1);
			}
		}

		namespace projectManagement
		{
			// Function for output first activ project management button
			void firstActive()
			{
				pm::tools::outputBorder(20, 3, 39, 108);
				titles::projectManagement(24, 5);
				buttons::active::smallButton(64, 14,   "     VIEW ALL      ", 0, 4);
				buttons::inactive::smallButton(64, 19, "       CREATE      ");
				buttons::inactive::smallButton(64, 24, "        EDIT       ");
				buttons::inactive::smallButton(64, 29, "       DELETE      ");
				buttons::inactive::smallButton(64, 34, "      ADD TEAM     ");
				buttons::inactive::smallButton(64, 39, "        EXIT       ");
			}

			// Function for output second activ project management button
			void secondActive()
			{
				pm::tools::outputBorder(20, 3, 39, 108);
				titles::projectManagement(24, 5);
				buttons::inactive::smallButton(64, 14, "     VIEW ALL      ");
				buttons::active::smallButton(64, 19,   "       CREATE      ", 0, 4);
				buttons::inactive::smallButton(64, 24, "        EDIT       ");
				buttons::inactive::smallButton(64, 29, "       DELETE      ");
				buttons::inactive::smallButton(64, 34, "      ADD TEAM     ");
				buttons::inactive::smallButton(64, 39, "        EXIT       ");
			}

			// Function for output third activ project management button
			void thirdActive()
			{
				pm::tools::outputBorder(20, 3, 39, 108);
				titles::projectManagement(24, 5);
				buttons::inactive::smallButton(64, 14, "     VIEW ALL      ");
				buttons::inactive::smallButton(64, 19, "       CREATE      ");
				buttons::active::smallButton(64, 24,   "        EDIT       ", 0, 4);
				buttons::inactive::smallButton(64, 29, "       DELETE      ");
				buttons::inactive::smallButton(64, 34, "      ADD TEAM     ");
				buttons::inactive::smallButton(64, 39, "        EXIT       ");
			}

			// Function for output fourth activ project management button
			void fourthActive()
			{
				pm::tools::outputBorder(20, 3, 39, 108);
				titles::projectManagement(24, 5);
				buttons::inactive::smallButton(64, 14, "     VIEW ALL      ");
				buttons::inactive::smallButton(64, 19, "       CREATE      ");
				buttons::inactive::smallButton(64, 24, "        EDIT       ");
				buttons::active::smallButton(64, 29,   "       DELETE      ", 0, 4);
				buttons::inactive::smallButton(64, 34, "      ADD TEAM     ");
				buttons::inactive::smallButton(64, 39, "        EXIT       ");
			}

			// Function for output fifth activ project management button
			void fifthActive()
			{
				pm::tools::outputBorder(20, 3, 39, 108);
				titles::projectManagement(24, 5);
				buttons::inactive::smallButton(64, 14, "     VIEW ALL      ");
				buttons::inactive::smallButton(64, 19, "       CREATE      ");
				buttons::inactive::smallButton(64, 24, "        EDIT       ");
				buttons::inactive::smallButton(64, 29, "       DELETE      ");
				buttons::active::smallButton(64, 34,   "      ADD TEAM     ", 0, 4);
				buttons::inactive::smallButton(64, 39, "        EXIT       ");
			}

			// Function for output sixth activ project management button
			void sixthActive()
			{
				pm::tools::outputBorder(20, 3, 39, 108);
				titles::projectManagement(24, 5);
				buttons::inactive::smallButton(64, 14, "     VIEW ALL      ");
				buttons::inactive::smallButton(64, 19, "       CREATE      ");
				buttons::inactive::smallButton(64, 24, "        EDIT       ");
				buttons::inactive::smallButton(64, 29, "       DELETE      ");
				buttons::inactive::smallButton(64, 34, "      ADD TEAM     ");
				buttons::active::smallButton(64, 39,   "        EXIT       ", 0, 4);
			}
		}
	}

	namespace windows
	{
		namespace warnings
		{
			// Function for output successfully Login windows on given position
			void successfullyLogin(int x, int y)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << "\x1b[0;32m" << "                       ___________                        " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "\x1b[0;32m" << "                     /         __  \\                      " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << "\x1b[0;32m" << "                    |         / /   |                     " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 3);
				cout << "\x1b[0;32m" << "                   |   __    / /     |                    " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 4);
				cout << "\x1b[0;32m" << "                  |    \\ \\  / /       |                   " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 5);
				cout << "\x1b[0;32m" << "                   |    \\ \\/ /       |                    " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 6);
				cout << "\x1b[0;32m" << "                    |    \\__/       |                     " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 7);
				cout << "\x1b[0;32m" << "                     \\ ___________ /                      " << "\x1b[1;37m" << endl << endl;
				pm::tools::consoleCoordinates(x, y + 9);
				cout << " _         _                                    ___     _ " << endl;
				pm::tools::consoleCoordinates(x, y + 10);
				cout << "| |___ ___|_|___    ___ _ _ ___ ___ ___ ___ ___|  _|_ _| |" << endl;
				pm::tools::consoleCoordinates(x, y + 11);
				cout << "| | . | . | |   |  |_ -| | |  _|  _| -_|_ -|_ -|  _| | | |" << endl;
				pm::tools::consoleCoordinates(x, y + 12);
				cout << "|_|___|_  |_|_|_|  |___|___|___|___|___|___|___|_| |___|_|" << endl;
				pm::tools::consoleCoordinates(x, y + 13);
				cout << "      |___|                                               " << endl;
			}

			// Function for output try again windows on given position
			void tryAgain(int x, int y)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << "\x1b[1;31m" << "            ____________          " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "\x1b[1;31m" << "           /  __    __  \\         " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << "\x1b[1;31m" << "          |   \\ \\  / /   |        " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 3);
				cout << "\x1b[1;31m" << "         |     \\ \\/ /     |       " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 4);
				cout << "\x1b[1;31m" << "         |     / /\\ \\     |       " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 5);
				cout << "\x1b[1;31m" << "          |   /_/  \\_\\   |        " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 6);
				cout << "\x1b[1;31m" << "           \\____________/         " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 8);
				cout << " _                          _     " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 9);
				cout << "| |_ ___ _ _    ___ ___ ___|_|___ " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 10);
				cout << "|  _|  _| | |  | .'| . | .'| |   |" << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 11);
				cout << "|_| |_| |_  |  |__,|_  |__,|_|_|_|" << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 12);
				cout << "        |___|      |___|          " << "\x1b[1;37m" << endl;
			}

			// Function for output windows for already exists username
			void theUsernameAlreadyExists(int x, int y)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << "\x1b[1;31m" << "            ____________          " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "\x1b[1;31m" << "           /  __    __  \\         " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 2); 
				cout << "\x1b[1;31m" << "          |   \\ \\  / /   |        " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 3);		    
				cout << "\x1b[1;31m" << "         |     \\ \\/ /     |       " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 4);		    
				cout << "\x1b[1;31m" << "         |     / /\\ \\     |       " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 5);		    
				cout << "\x1b[1;31m" << "          |   /_/  \\_\\   |        " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 6);
				cout << "\x1b[1;31m" << "           \\____________/         " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x - 5, y + 10);
				cout << "! THIS USERNAME ALREADY EXISTS PLEASE TRY AGAIN !" << endl;
			}

			// Function for output error for incorrect or incomplete password
			void incorrectPassword(int x, int y)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << "\x1b[1;31m" << "            ____________          " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "\x1b[1;31m" << "           /  __    __  \\         " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << "\x1b[1;31m" << "          |   \\ \\  / /   |        " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 3);
				cout << "\x1b[1;31m" << "         |     \\ \\/ /     |       " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 4);
				cout << "\x1b[1;31m" << "         |     / /\\ \\     |       " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 5);
				cout << "\x1b[1;31m" << "          |   /_/  \\_\\   |        " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 6);
				cout << "\x1b[1;31m" << "           \\____________/         " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 9);
				cout << "! THIS PASSWORD IS INCORRECT OR INCOPLETE PLEASE TRY AGAIN !" << endl;
				pm::tools::consoleCoordinates(x, y + 10);
				cout << "The password must contain uppercase, lowercase letters and special characters." << endl
					 << "         It must be not less than 8 and not more than 20 characters!";
			}
		}

		// Function for output login window as user
		void login(string* idOfUser)
		{
			pm::tools::outputBorder(24, 17, 13, 101);
			pm::types::USER user;
			pm::tools::consoleCoordinates(51, 22);
			cout << "Enter your username : ";
			pm::tools::consoleCoordinates(51, 25);
			cout << "Enter your password : ";
			pm::tools::consoleCoordinates(73, 22);
			cin >> user.username;
			pm::tools::consoleCoordinates(73, 25);
			cin >> user.password;
			if (pm::dal::loginAsFirst(user))
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17, 101);
				warnings::successfullyLogin(46, 17);
				Sleep(1500);
				user.role = "admin";
			}
			else if (pm::dal::login("../pm.data/users.csv", &user, idOfUser))
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17, 101);
				warnings::successfullyLogin(46, 17);
				Sleep(1500);
			}
			else
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17, 101);
				warnings::tryAgain(56, 18);
				Sleep(1500);
			}
			if (user.role == "user")
			{
				pm::consoleApp::menus::userPanel(idOfUser);
			}
			else if (user.role == "admin")
			{
				pm::consoleApp::menus::adminPanel(idOfUser);
			}
		}

		// Function for changing password
		void changePassword()
		{
			pm::tools::outputBorder(24, 15, 16, 101);
			pm::types::USER user;
			string newPassword, idOfUser;
			pm::tools::consoleCoordinates(51, 20);
			cout << "Enter your username : ";
			pm::tools::consoleCoordinates(51, 23);
			cout << "Enter your password : ";
			pm::tools::consoleCoordinates(51, 26);
			cout << "Enter your NEW password : ";
			pm::tools::consoleCoordinates(36, 29);
			cout << "\x1b[1;31m" << "The password must contain uppercase, lowercase letters and special characters." << endl
				<< "\t\t\t\t\t     It must be not less than 8 and not more than 20 characters!" << "\x1b[1;37m";
			pm::tools::consoleCoordinates(73, 20);
			cin >> user.username;
			pm::tools::consoleCoordinates(73, 23);
			cin >> user.password;
			if (pm::dal::login("../pm.data/users.csv", &user, &idOfUser))
			{
				pm::tools::consoleCoordinates(77, 26);
				cin >> newPassword;
				if (pm::bll::checkPassword(newPassword))
				{
					pm::dal::cnagePassword("../pm.data/users.csv", user, newPassword);
					system("CLS");
					pm::tools::outputBorder(24, 14, 17, 101);
					warnings::successfullyLogin(46, 17);
					Sleep(1500);
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 14, 17, 101);
					warnings::tryAgain(56, 18);
					Sleep(1500);
				}
			}
			else
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17, 101);
				warnings::tryAgain(56, 18);
				Sleep(1500);
			}
		}

		namespace userManagement
		{
			// Function for output register windows
			void addNewUser()
			{
				pm::tools::outputBorder(24, 13, 20, 101);
				pm::types::USER user;
				pm::tools::consoleCoordinates(51, 18);
				cout << "Username : ";
				pm::tools::consoleCoordinates(51, 21);
				cout << "First name : ";
				pm::tools::consoleCoordinates(51, 24);
				cout << "Last name : ";
				pm::tools::consoleCoordinates(51, 27);
				cout << "Age : ";
				pm::tools::consoleCoordinates(51, 30);
				cout << "Password : ";
				pm::tools::consoleCoordinates(36, 32);
				cout << "\x1b[1;31m" << "The password must contain uppercase, lowercase letters and special characters." << endl
					<< "\t\t\t\t\t     It must be not less than 8 and not more than 20 characters!" << "\x1b[1;37m";
				pm::tools::consoleCoordinates(62, 18);
				cin >> user.username;
				pm::tools::consoleCoordinates(64, 21);
				cin >> user.firstName;
				pm::tools::consoleCoordinates(63, 24);
				cin >> user.lastName;
				pm::tools::consoleCoordinates(57, 27);
				cin >> user.age;
				pm::tools::consoleCoordinates(62, 30);
				cin >> user.password;
				int check = pm::dal::registerUser("../pm.data/users.csv", user);
				if (check == 1)
				{
					system("CLS");
					pm::tools::outputBorder(24, 13, 20, 101);
					warnings::successfullyLogin(46, 17);
					Sleep(1500);
				}
				else if (check == 2)
				{
					system("CLS");
					pm::tools::outputBorder(24, 14, 17, 101);
					pm::consoleApp::windows::warnings::theUsernameAlreadyExists(55, 18);
					Sleep(2000);
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 13, 20, 101);
					warnings::tryAgain(56, 18);
					Sleep(1500);
				}
			}

			// Function for show users list
			void showUserList(int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/users.csv") * 3 + pm::dal::generateId("../pm.data/users.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : data)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 16;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 4)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int choise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < id.size(); i++)
				{
					if (choise == id[i])
					{
						exist = true;
					}
				}
				if (choise == 0 || !exist)
				{
					return;
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 13, 20, 101);
					vector<string> user = pm::dal::getUserDataById("../pm.data/users.csv", choise);
					x = 40; y = 15;
					pm::tools::consoleCoordinates(x, y + 1);
					cout << "Id of the user : " << user[0];
					pm::tools::consoleCoordinates(x, y + 3);
					cout << "First name of the user : " << user[1];
					pm::tools::consoleCoordinates(x, y + 5);
					cout << "Last name of the user : " << user[2];
					pm::tools::consoleCoordinates(x, y + 7);
					cout << "Username of the user : " << user[3];
					pm::tools::consoleCoordinates(x, y + 9);
					cout << "Hashing password of the user : " << user[4];
					pm::tools::consoleCoordinates(x, y + 11);
					cout << "Age of the user : " << user[5];
					pm::tools::consoleCoordinates(x, y + 13);
					cout << "Time of registration of the user : " << user[6];
					pm::tools::consoleCoordinates(x, y + 15);
					cout << "Last login data of the user : " << user[7];
					pm::tools::consoleCoordinates(x, y + 17);
					cout << "Role of the user : " << user[8];
					pm::tools::consoleCoordinates(x + 20, y + 20);
					system("pause");
					showUserList(tempX, tempY);
				}
			}

			// Function for output delete windows
			void deleteUser(int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/users.csv") * 3 + pm::dal::generateId("../pm.data/users.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : data)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 16;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 4)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int choise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < id.size(); i++)
				{
					if (choise == id[i])
					{
						exist = true;
					}
				}
				if (choise == 0 || !exist)
				{
					return;
				}
				else
				{
					pm::dal::deleteUserByIdInUsersFile("../pm.data/users.csv", choise);
					return;
				}
			}

			// Function for edit data of user
			void editUser(int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/users.csv") * 3 + pm::dal::generateId("../pm.data/users.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id);
				vector<vector<string>> allData = pm::dal::readDataFromUsersFile("../pm.data/users.csv");
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : data)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 16;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 4)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int chosenID = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < id.size(); i++)
				{
					if (chosenID == id[i])
					{
						exist = true;
					}
				}
				if (chosenID == 0 || !exist)
				{
					return;
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 10, 23, 101);
					pm::tools::consoleCoordinates(55, 13);
					cout << "1. Username";
					pm::tools::consoleCoordinates(55, 16);
					cout << "2. First name";
					pm::tools::consoleCoordinates(55, 19);
					cout << "3. Last name";
					pm::tools::consoleCoordinates(55, 22);
					cout << "4. Age";
					pm::tools::consoleCoordinates(55, 25);
					cout << "5. Password";
					pm::tools::consoleCoordinates(55, 28);
					cout << "6. Role";
					int choise = pm::tools::enterNumberWithoutPrintingOnConsole();
					if (choise <= 0 || choise > 6)
					{
						return;
					}
					else
					{
						string newData;
						
						switch (choise)
						{
						case 1:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DATA THAT YOU WANT TO CHANGE : ";
							cin.ignore();
							getline(cin, newData);
							pm::bll::editUserById("../pm.data/users.csv", allData, chosenID, 3, newData);
							break;
						}
						case 2:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DATA THAT YOU WANT TO CHANGE : ";
							cin.ignore();
							getline(cin, newData);
							pm::bll::editUserById("../pm.data/users.csv", allData, chosenID, 1, newData);
							break;
						}
						case 3:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DATA THAT YOU WANT TO CHANGE : ";
							cin.ignore();
							getline(cin, newData);
							pm::bll::editUserById("../pm.data/users.csv", allData, chosenID, 2, newData);
							break;
						}
						case 4:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DATA THAT YOU WANT TO CHANGE : ";
							cin.ignore();
							getline(cin, newData);
							pm::bll::editUserById("../pm.data/users.csv", allData, chosenID, 5, newData);
							break;
						}
						case 5:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DATA THAT YOU WANT TO CHANGE : ";
							cin.ignore();
							getline(cin, newData);
							pm::bll::editUserById("../pm.data/users.csv", allData, chosenID, 6, newData);
							break;
						}
						case 6:
						{
							pm::bll::editUserById("../pm.data/users.csv", allData, chosenID, 8, newData);
							break;
						}
						}
						editUser(tempX, tempY);
					}
				}
			}
		}

		namespace teamsManagement
		{
			// Function for add new team
			void createNewTeam(string idOfUser, int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 15, 16, 101);
				pm::types::TEAM team;
				pm::tools::consoleCoordinates(51, 22);
				cout << "Name of team : ";
				pm::tools::consoleCoordinates(66, 22);
				cin >> team.name;
				team.idOfCreator = team.idOfLastChanger = idOfUser;
				pm::tools::consoleCoordinates(51, 28);
				system("pause");
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/users.csv") * 3 + pm::dal::generateId("../pm.data/users.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : data)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 16;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 4)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				vector<string> vec = pm::tools::chooseUsersById();
				int count = 0;
				for (auto i : vec)
				{
					for (auto j : id)
					{
						if (i == to_string(j))
						{
							count++;
						}
					}
				}
				if (count == vec.size())
				{
					for (auto it : vec)
					{
						if (it == vec[vec.size() - 1])
						{
							team.contributors += it;
						}
						else
						{
							team.contributors += it + ",";
						}
					}
					pm::dal::createTeam("../pm.data/teams.csv", team);
				}
				
			}

			// Function for output list of teams
			void showAllTeams(int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/teams.csv") * 3 + pm::dal::generateId("../pm.data/teams.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tName of team\t\t\tCreator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::readDataFromTeamsFile("../pm.data/teams.csv", &id);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : data)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 40;
							cout << col;
						}
						counter++;
					}
				}
				int choise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < id.size(); i++)
				{
					if (choise == id[i])
					{
						exist = true;
					}
				}
				if (choise == 0 || !exist)
				{
					return;
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 13, 20, 101);
					vector<string> team = pm::dal::getTeamDataById("../pm.data/teams.csv", choise);
					x = 40; y = 17;
					pm::tools::consoleCoordinates(x, y + 1);
					cout << "Id of the team : " << team[0];
					pm::tools::consoleCoordinates(x, y + 3);
					cout << "Name of the team : " << team[1];
					pm::tools::consoleCoordinates(x, y + 5);
					cout << "Id of creator : " << team[2];
					pm::tools::consoleCoordinates(x, y + 7);
					cout << "Data of creation : " << team[3];
					pm::tools::consoleCoordinates(x, y + 9);
					cout << "Data of last changes : " << team[4];
					pm::tools::consoleCoordinates(x, y + 11);
					cout << "Id Of last changer : " << team[5];
					pm::tools::consoleCoordinates(x, y + 13);
					cout << "Id of contributors : " << team[6];
					pm::tools::consoleCoordinates(x + 20, y + 20);
					system("pause");
					showAllTeams(tempX, tempY);
				}
			}

			// Function for deleting team
			void deleteTeam(int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/teams.csv") * 3 + pm::dal::generateId("../pm.data/teams.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tName of team\t\t\tCreator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::readDataFromTeamsFile("../pm.data/teams.csv", &id);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : data)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 40;
							cout << col;
						}
						counter++;
					}
				}
				int choise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < id.size(); i++)
				{
					if (choise == id[i])
					{
						exist = true;
					}
				}
				if (choise == 0 || !exist)
				{
					return;
				}
				else
				{
					pm::dal::deleteTeamByIdInTeamsFile("../pm.data/teams.csv", choise);
					return;
				}
			}

			// Function for edit data in teams.csv file
			void editTeam(string idOfUser, int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/teams.csv") * 3 + pm::dal::generateId("../pm.data/teams.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tName of team\t\t\tCreator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> allData = pm::dal::readDataFromTeamsFile("../pm.data/teams.csv", &id);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : allData)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 40;
							cout << col;
						}
						counter++;
					}
				}
				int chosenID = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < id.size(); i++)
				{
					if (chosenID == id[i])
					{
						exist = true;
					}
				}
				if (chosenID == 0 || !exist)
				{
					return;
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 13, 20, 101);
					x = 40; y = 16;
					pm::tools::consoleCoordinates(x, y + 3);
					cout << "1. Name of the team";
					pm::tools::consoleCoordinates(x, y + 8);
					cout << "2. Id of contributors";
					int choise = pm::tools::enterNumberWithoutPrintingOnConsole();
					if (choise <= 0 || choise > 2)
					{
						return;
					}
					else
					{
						string newData;
						switch (choise)
						{
						case 1:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW NAME : ";
							cin.ignore();
							getline(cin, newData);
							pm::bll::editTeamById("../pm.data/teams.csv", allData, chosenID, 1, newData, idOfUser);
							break;
						}
						case 2:
						{
							system("CLS");
							pm::tools::outputBorder(24, 13, pm::dal::generateId("../pm.data/users.csv") * 3 + pm::dal::generateId("../pm.data/users.csv") / 2, 101);
							pm::tools::consoleCoordinates(x, y);
							cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
							pm::tools::consoleCoordinates(26, y + 1);
							cout << "___________________________________________________________________________________________________";
							vector<int> id;
							vector<vector<string>> data = pm::dal::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id);
							int tempX = x, tempY = y;
							y += 2;
							for (auto row : data)
							{
								int counter = 1;
								y += 3;
								x = tempX;
								for (auto col : row)
								{
									if (counter == 1)
									{
										pm::tools::consoleCoordinates(x, y);
										x += 16;
										cout << col;
									}
									else if (counter == 2)
									{
										pm::tools::consoleCoordinates(x, y);
										x += 24;
										cout << col;
									}
									else if (counter == 3)
									{
										pm::tools::consoleCoordinates(x, y);
										x += 24;
										cout << col;
									}
									else if (counter == 4)
									{
										pm::tools::consoleCoordinates(x, y);
										cout << col;
									}
									counter++;
								}
							}
							vector<string> vec = pm::tools::chooseUsersById();
							int count = 0;
							for (auto i : vec)
							{
								for (auto j : id)
								{
									if (i == to_string(j))
									{
										count++;
									}
								}
							}
							if (count == vec.size())
							{
								for (auto i : vec)
								{

									if (i == vec[vec.size() - 1])
									{
										newData += i;
									}
									else
									{
										newData += i + ",";
									}
								}
								pm::bll::editTeamById("../pm.data/teams.csv", allData, chosenID, 6, newData, idOfUser);
							}
							break;
						}
						}
					}
				}
			}
		}

		namespace projectsManagement
		{
			// Function for create project
			void createProject(string idOfUser, int x, int y)
			{
				pm::tools::outputBorder(24, 13, 20, 101);
				pm::types::PROJECT project;
				pm::tools::consoleCoordinates(43, 18);
				cout << "Title : ";
				pm::tools::consoleCoordinates(43, 21);
				cout << "Description : ";
				pm::tools::consoleCoordinates(51, 18);
				cin.ignore();
				getline(cin, project.title);
				pm::tools::consoleCoordinates(57, 21);
				getline(cin, project.description);
				project.idOfCreator = project.idOfLastChanger = idOfUser;
				pm::tools::consoleCoordinates(43, 28);
				system("pause");
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/teams.csv") * 3 + pm::dal::generateId("../pm.data/teams.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tName of team\t\t\tCreator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::readDataFromTeamsFile("../pm.data/teams.csv", &id);
				id = {};
				pm::bll::checkForContainUserInTeam(data, idOfUser, &id);
				data = pm::bll::getDataById(id, data);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : data)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int choise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < id.size(); i++)
				{
					if (choise == id[i])
					{
						exist = true;
					}
				}
				if (choise <= 0 || !exist)
				{
					project.idOfTeam = "0";
				}
				else
				{
					project.idOfTeam = to_string(choise);
				}
				pm::dal::createProject("../pm.data/projects.csv", project);
			}

			// Function for output list of projects
			void showAllProjects(string idOfUser, int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/projects.csv") * 3 + pm::dal::generateId("../pm.data/projects.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tTitle of project\t\t\tId of creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> idOfProject;
				vector<vector<string>> projectData = pm::dal::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				idOfProject = {};
				pm::bll::checkProjectForContainUserInTeam(projectData, idOfUser, &idOfProject);
				projectData = pm::bll::getDataById(idOfProject, projectData);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : projectData)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 45;
							cout << col;
						}
						else if (counter == 5)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int choise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < idOfProject.size(); i++)
				{
					if (choise == idOfProject[i])
					{
						exist = true;
					}
				}
				if (choise == 0 || !exist)
				{
					return;
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 13, 20, 101);
					vector<string> project = pm::dal::getProjetctDataById("../pm.data/projects.csv", choise);
					x = 40; y = 15;
					pm::tools::consoleCoordinates(x, y + 1);
					cout << "Id of the project : " << project[0];
					pm::tools::consoleCoordinates(x, y + 3);
					cout << "Title of the project : " << project[1];
					pm::tools::consoleCoordinates(x, y + 5);
					cout << "Description of the project : " << project[2];
					pm::tools::consoleCoordinates(x, y + 7);
					cout << "Data of creation : " << project[3];
					pm::tools::consoleCoordinates(x, y + 9);
					cout << "Id of the creator : " << project[4];
					pm::tools::consoleCoordinates(x, y + 11);
					cout << "Date of last changes : " << project[5];
					pm::tools::consoleCoordinates(x, y + 13);
					cout << "Id of last changer : " << project[6];
					pm::tools::consoleCoordinates(x, y + 15);
					cout << "Id of team : " << project[7];
					pm::tools::consoleCoordinates(x, y + 17);
					cout << "Id of tasks : " << project[8];
					pm::tools::consoleCoordinates(x + 20, y + 20);
					system("pause");
					showAllProjects(idOfUser, tempX, tempY);
				}
			}

			// Function for delete data from project file
			void deleteProject(string idOfUser, int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/projects.csv") * 3 + pm::dal::generateId("../pm.data/projects.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tTitle of project\t\t\tId of creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::readDataFromProjectsFile("../pm.data/projects.csv", &id);
				id = {};
				pm::bll::checkProjectForContainUserInTeam(data, idOfUser, &id);
				data = pm::bll::getDataById(id, data);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : data)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 45;
							cout << col;
						}
						else if (counter == 5)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int choise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < id.size(); i++)
				{
					if (choise == id[i])
					{
						exist = true;
					}
				}
				if (choise == 0 || !exist)
				{
					return;
				}
				else
				{
					pm::dal::deleteProjectByIdInProjectsFile("../pm.data/projects.csv", choise, idOfUser);
					return;
				}
			}

			// Function to add team in a project
			void addTeamInProject(std::string idOfUser, int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/projects.csv") * 3 + pm::dal::generateId("../pm.data/projects.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tTitle of project\t\t\tId of creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> idOfProject;
				vector<vector<string>> projectData = pm::dal::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				vector<vector<string>> allProjectData = pm::dal::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				idOfProject = {};
				pm::bll::findProjectWithoutTeam(projectData, idOfUser, &idOfProject);
				projectData = pm::bll::getDataById(idOfProject, projectData);
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : projectData)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 24;
							cout << col;
						}
						else if (counter == 2)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 45;
							cout << col;
						}
						else if (counter == 5)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int choiseOfProject = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < idOfProject.size(); i++)
				{
					if (choiseOfProject == idOfProject[i])
					{
						exist = true;
					}
				}
				if (choiseOfProject == 0 || !exist)
				{
					return;
				}
				else
				{
					system("CLS");
					x = tempX; y = tempY;
					pm::tools::outputBorder(24, 7, pm::dal::generateId("../pm.data/teams.csv") * 3 + pm::dal::generateId("../pm.data/teams.csv") / 2, 101);
					pm::tools::consoleCoordinates(x, y);
					cout << "Id\t\t\tName of team\t\t\tCreator";
					pm::tools::consoleCoordinates(26, y + 1);
					cout << "___________________________________________________________________________________________________";
					vector<int> idOfTeam;
					vector<vector<string>> dataOfTeam = pm::dal::readDataFromTeamsFile("../pm.data/teams.csv", &idOfTeam);
					idOfTeam = {};
					pm::bll::checkForContainUserInTeam(dataOfTeam, idOfUser, &idOfTeam);
					dataOfTeam = pm::bll::getDataById(idOfTeam, dataOfTeam);
					int temp1 = tempX, temp2 = tempY;
					y += 2;
					for (auto row : dataOfTeam)
					{
						int counter = 1;
						y += 3;
						x = temp1;
						for (auto col : row)
						{
							if (counter == 1)
							{
								pm::tools::consoleCoordinates(x, y);
								x += 24;
								cout << col;
							}
							else if (counter == 2)
							{
								pm::tools::consoleCoordinates(x, y);
								x += 32;
								cout << col;
							}
							else if (counter == 3)
							{
								pm::tools::consoleCoordinates(x, y);
								cout << col;
							}
							counter++;
						}
					}
					int choiseOfTeam = pm::tools::enterNumberWithoutPrintingOnConsole();
					bool exist = false;
					for (int i = 0; i < idOfTeam.size(); i++)
					{
						if (choiseOfTeam == idOfTeam[i])
						{
							exist = true;
						}
					}
					pm::bll::editIdOfTeam(projectData, allProjectData, choiseOfProject, choiseOfTeam, "../pm.data/projects.csv");
				}
			}

			// Function for edit informtion in the project
			void editProject(std::string idOfUser, int x, int y)
			{

			}
		}
	}

	namespace menus
	{
		// Function for movement in project management
		void projectManagement(string idOfUser)
		{
			int choice;
			bool truth;
			system("CLS");
			buttons::projectManagement::firstActive();
			choice = 1;
			while (true)
			{
				truth = true;
				switch (_getch())
				{
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::projectManagement::sixthActive();
						choice = 6;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::projectManagement::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::projectManagement::secondActive();
						choice = 2;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::projectManagement::thirdActive();
						choice = 3;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::projectManagement::fourthActive();
						choice = 4;
						break;
					}
					case 6:
					{
						system("CLS");
						buttons::projectManagement::fifthActive();
						choice = 5;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::projectManagement::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::projectManagement::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::projectManagement::fourthActive();
						choice = 4;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::projectManagement::fifthActive();
						choice = 5;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::projectManagement::sixthActive();
						choice = 6;
						break;
					}
					case 6:
					{
						system("CLS");
						buttons::projectManagement::firstActive();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					while (truth)
					{
						switch (choice)
						{
						case 1:
						{
							system("CLS");
							windows::projectsManagement::showAllProjects(idOfUser, 40, 9);
							choice = 7;
							break;
						}
						case 2:
						{
							system("CLS");
							windows::projectsManagement::createProject(idOfUser, 40, 9);
							choice = 7;
							break;
						}
						case 3:
						{
							system("CLS");
							choice = 7;
							break;
						}
						case 4:
						{
							system("CLS");
							windows::projectsManagement::deleteProject(idOfUser, 40, 9);
							choice = 7;
							break;
						}
						case 5:
						{
							system("CLS");
							windows::projectsManagement::addTeamInProject(idOfUser, 40, 9);
							choice = 7;
							break;
						}
						case 6:
						{
							truth = false;
							return;
							break;
						}
						case 7:
						{
							system("CLS");
							buttons::projectManagement::firstActive();
							truth = false;
							choice = 1;
							break;
						}
						}
					}
					break;
				default:
					break;
				}
			}
		}

		// Function for movement in teams management
		void teamsManagement(string idOfUser)
		{
			int choice;
			bool truth;
			system("CLS");
			buttons::teamsManagement::firstActive();
			choice = 1;
			while (true)
			{
				truth = true;
				switch (_getch())
				{
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::teamsManagement::fifthActive();
						choice = 5;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::teamsManagement::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::teamsManagement::secondActive();
						choice = 2;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::teamsManagement::thirdActive();
						choice = 3;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::teamsManagement::fourthActive();
						choice = 4;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::teamsManagement::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::teamsManagement::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::teamsManagement::fourthActive();
						choice = 4;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::teamsManagement::fifthActive();
						choice = 5;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::teamsManagement::firstActive();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					while (truth)
					{
						switch (choice)
						{
						case 1:
						{
							system("CLS");
							windows::teamsManagement::showAllTeams(40, 9);
							choice = 6;
							break;
						}
						case 2:
						{
							system("CLS");
							windows::teamsManagement::createNewTeam(idOfUser, 40, 9);
							choice = 6;
							break;
						}
						case 3:
						{
							system("CLS");
							windows::teamsManagement::editTeam(idOfUser, 40, 9);
							choice = 6;
							break;
						}
						case 4:
						{
							system("CLS");
							windows::teamsManagement::deleteTeam(40, 9);
							choice = 6;
							break;
						}
						case 5:
						{
							truth = false;
							return;
							break;
						}
						case 6:
						{
							system("CLS");
							buttons::teamsManagement::firstActive();
							truth = false;
							choice = 1;
							break;
						}
						}
					}
					break;
				default:
					break;
				}
			}
		}

		// Function for movement in user management
		void userManagement()
		{
			int choice;
			bool truth;
			system("CLS");
			buttons::userManagement::firstActive();
			choice = 1;
			while (true) 
			{
				truth = true;
				switch (_getch()) 
				{
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::userManagement::fifthActive();
						choice = 5;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::userManagement::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::userManagement::secondActive();
						choice = 2;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::userManagement::thirdActive();
						choice = 3;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::userManagement::fourthActive();
						choice = 4;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::userManagement::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::userManagement::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::userManagement::fourthActive();
						choice = 4;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::userManagement::fifthActive();
						choice = 5;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::userManagement::firstActive();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					while (truth)
					{
						switch (choice)
						{
						case 1:
						{
							system("CLS");
							windows::userManagement::showUserList(40, 9);
							choice = 6;
							break;
						}
						case 2:
						{
							system("CLS");
							windows::userManagement::addNewUser();
							choice = 6;
							break;
						}
						case 3:
						{
							system("CLS");
							windows::userManagement::editUser(40, 9);
							choice = 6;
							break;
						}
						case 4:
						{
							system("CLS");
							windows::userManagement::deleteUser(40, 9);
							choice = 6;
							break;
						}
						case 5:
						{
							truth = false;
							return;
							break;
						}
						case 6:
						{
							system("CLS");
							buttons::userManagement::firstActive();
							truth = false;
							choice = 1;
							break;
						}
						}
					}
					break;
				default:
					break;
				}
			}
		}

		// Function for movement in admin panel
		void adminPanel(string* idOfUser)
		{
			int choice;
			bool truth;
			system("CLS");
			buttons::adminPanel::firstActive();
			choice = 1;
			while (true) 
			{
				truth = true;
				switch (_getch()) 
				{
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::adminPanel::thirdActive();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::adminPanel::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::adminPanel::secondActive();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::adminPanel::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::adminPanel::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::adminPanel::firstActive();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					while (truth)
					{
						switch (choice)
						{
						case 1:
						{
							system("CLS");
							userManagement();
							choice = 4;
							break;
						}
						case 2:
						{
							system("CLS");
							teamsManagement(*idOfUser);
							choice = 4;
							break;
						}
						case 3:
						{
							truth = false;
							return;
							break;
						}
						case 4:
						{
							system("CLS");
							buttons::adminPanel::firstActive();
							truth = false;
							choice = 1;
							break;
						}
						}
					}
					break;
				default:
					break;
				}
			}
		}

		// Function for movement in user panel
		void userPanel(string *idOfUser)
		{
			int choice;
			bool truth;
			system("CLS");
			buttons::userPanel::firstActive();
			choice = 1;
			while (true) 
			{
				truth = true;
				switch (_getch()) 
				{
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::userPanel::fourthActive();
						choice = 4;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::userPanel::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::userPanel::secondActive();
						choice = 2;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::userPanel::thirdActive();
						choice = 3;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::userPanel::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::userPanel::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::userPanel::fourthActive();
						choice = 4;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::userPanel::firstActive();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					while (truth)
					{
						switch (choice)
						{
						case 1:
						{
							system("CLS");
							projectManagement(*idOfUser);
							choice = 5;
							break;
						}
						case 2:
						{
							system("CLS");
							choice = 5;
							break;
						}
						case 3:
						{
							system("CLS");
							choice = 5;
							break;
						}
						case 4:
						{
							truth = false;
							return;
							break;
						}
						case 5:
						{
							system("CLS");
							buttons::userPanel::firstActive();
							truth = false;
							choice = 1;
							break;
						}
						}
					}
					break;
				default:
					break;
				}
			}
		}

		// Function for movement in main Menu
		void menu()
		{
			int choice;
			bool truth;
			string idOfUser;
			system("CLS");
			buttons::loginPanel::firstActive();
			choice = 1;
			while (true) 
			{
				truth = true;
				switch (_getch()) 
				{
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::loginPanel::thirdActive();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::loginPanel::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::loginPanel::secondActive();
						choice = 2;
						break;
					}
					}
					break;
				case KEY_DOWN:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::loginPanel::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::loginPanel::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::loginPanel::firstActive();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					while (truth)
					{
						switch (choice)
						{
						case 1:
						{
							system("CLS");
							choice = 4;
							windows::login(&idOfUser);
							break;
						}
						case 2:
						{
							system("CLS");
							choice = 4;
							windows::changePassword();
							break;
						}
						case 3:
						{
							truth = false;
							return;
							break;
						}
						case 4:
						{
							system("CLS");
							buttons::loginPanel::firstActive();
							truth = false;
							choice = 1;
							break;
						}
						}
					}
					break;
				default:
					break;
				}
			}
		}
	}
}