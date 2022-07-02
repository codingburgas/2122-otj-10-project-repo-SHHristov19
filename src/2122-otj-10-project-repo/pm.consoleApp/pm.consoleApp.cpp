#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>

// Include header files from pm.consoleApp
#include "../pm.consoleApp/pm.menus.h"
#include "../pm.consoleApp/pm.userManagement.h"
#include "../pm.consoleApp/pm.teamsManagement.h"
#include "../pm.consoleApp/pm.projectManagement.h"
#include "../pm.consoleApp/pm.titlesDesign.h"
#include "../pm.consoleApp/pm.userManagement.h"
#include "../pm.consoleApp/pm.buttonsDesign.h"

// Include header files from pm.bll
#include "../pm.bll/pm.bll.userManagement.h"
#include "../pm.bll/pm.bll.teamManagement.h"
#include "../pm.bll/pm.bll.projectManagement.h"
#include "../pm.bll/pm.bll.taskManagement.h"
#include "../pm.bll/pm.bll.workLogManagement.h"

// Include header files from pm.dal
#include "../pm.dal/pm.dal.tools.h"
#include "../pm.dal/pm.dal.login.h"
#include "../pm.dal/pm.dal.userManagement.h"
#include "../pm.dal/pm.dal.teamsManagement.h"
#include "../pm.dal/pm.dal.projectManagement.h"
#include "../pm.dal/pm.dal.taskManagement.h"
#include "../pm.dal/pm.dal.workLogManagement.h"

#include "../pm.tools/pm.tools.h"
#include "../pm.types/structures.h"

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

		// Finction for output task management title in current position
		void taskManagement(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << " _______          _     																	  " << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "(_______)        | |                                                                    _    " << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << "   | |  ____  ___| |  _           ____   ____ ____   ____  ____  ____ ____   ____ ____ | |_  " << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "   | | / _  |/___) | / )         |    \\ / _  |  _ \\ / _  |/ _  |/ _  )    \\ / _  )  _ \\|  _) " << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "   | |( ( | |___ | |< (          | | | ( ( | | | | ( ( | ( ( | ( (/ /| | | ( (/ /| | | | |__ " << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << "   |_| \\_||_(___/|_| \\_)         |_|_|_|\\_||_|_| |_|\\_||_|\\_|| |\\____)_|_|_|\\____)_| |_|\\___)" << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "                                                         (_____| 							  " << endl;
		}

		// Finction for output work log management title in current position
		void workLogManagement(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << "        _  _  _            _        _                		 " << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "       | || || |          | |      | |               		 " << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << "       | || || | ___   ___| |  _   | |    ___   ____ 		 " << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "       | ||_|| |/ _ \\ / __) | / )  | |   / _ \\ / _  |		 " << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "       | |___| | |_| | |  | |< (   | |__| |_| ( ( | |		 " << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << "        \\______|\\___/|_|  |_| \\_)  |_____)___/ \\_|| |		 " << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "                                              (_____|		 " << endl;
			pm::tools::consoleCoordinates(x, y + 7);
			cout << "                                                       _    " << endl;
			pm::tools::consoleCoordinates(x, y + 8);
			cout << " ____   ____ ____   ____  ____  ____ ____   ____ ____ | |_  " << endl;
			pm::tools::consoleCoordinates(x, y + 9);
			cout << "|    \\ / _  |  _ \\ / _  |/ _  |/ _  )    \\ / _  )  _ \\|  _) " << endl;
			pm::tools::consoleCoordinates(x, y + 10);
			cout << "| | | ( ( | | | | ( ( | ( ( | ( (/ /| | | ( (/ /| | | | |__ " << endl;
			pm::tools::consoleCoordinates(x, y + 11);
			cout << "|_|_|_|\\_||_|_| |_|\\_||_|\\_|| |\\____)_|_|_|\\____)_| |_|\\___)" << endl;
			pm::tools::consoleCoordinates(x, y + 12);
			cout << "                        (_____| 							 " << endl;
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

		namespace taskManagement
		{
			// Function for output first activ task management button
			void firstActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::taskManagement(30, 7);
				buttons::active::smallButton(63, 17, "     VIEW ALL      ", 1, 0);
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output second activ task management button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::taskManagement(30, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::active::smallButton(63, 22, "       CREATE      ", 1, 0);
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output third activ task management button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::taskManagement(30, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::active::smallButton(63, 27, "        EDIT       ", 1, 0);
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output fourth activ task management button
			void fourthActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::taskManagement(30, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::active::smallButton(63, 32, "       DELETE      ", 1, 0);
				buttons::inactive::smallButton(63, 37, "        EXIT       ");
			}

			// Function for output fifth activ task management button
			void fifthActive()
			{
				pm::tools::outputBorder(23, 3, 39, 101);
				titles::taskManagement(30, 7);
				buttons::inactive::smallButton(63, 17, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 22, "       CREATE      ");
				buttons::inactive::smallButton(63, 27, "        EDIT       ");
				buttons::inactive::smallButton(63, 32, "       DELETE      ");
				buttons::active::smallButton(63, 37, "        EXIT       ", 1, 0);
			}
		}

		namespace workLogManagement
		{
			// Function for output first activ work log management button
			void firstActive()
			{
				pm::tools::outputBorder(23, 3, 40, 101);
				titles::workLogManagement(44, 5);
				buttons::active::smallButton(63, 20, "     VIEW ALL      ", 1, 4);
				buttons::inactive::smallButton(63, 25, "       CREATE      ");
				buttons::inactive::smallButton(63, 30, "        EDIT       ");
				buttons::inactive::smallButton(63, 35, "       DELETE      ");
				buttons::inactive::smallButton(63, 40, "        EXIT       ");
			}

			// Function for output second activ work log management button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 40, 101);
				titles::workLogManagement(44, 5);
				buttons::inactive::smallButton(63, 20, "     VIEW ALL      ");
				buttons::active::smallButton(63, 25, "       CREATE      ", 1, 4);
				buttons::inactive::smallButton(63, 30, "        EDIT       ");
				buttons::inactive::smallButton(63, 35, "       DELETE      ");
				buttons::inactive::smallButton(63, 40, "        EXIT       ");
			}

			// Function for output third activ work log management button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 40, 101);
				titles::workLogManagement(44, 5);
				buttons::inactive::smallButton(63, 20, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 25, "       CREATE      ");
				buttons::active::smallButton(63, 30, "        EDIT       ", 1, 4);
				buttons::inactive::smallButton(63, 35, "       DELETE      ");
				buttons::inactive::smallButton(63, 40, "        EXIT       ");
			}

			// Function for output fourth activ work log management button
			void fourthActive()
			{
				pm::tools::outputBorder(23, 3, 40, 101);
				titles::workLogManagement(44, 5);
				buttons::inactive::smallButton(63, 20, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 25, "       CREATE      ");
				buttons::inactive::smallButton(63, 30, "        EDIT       ");
				buttons::active::smallButton(63, 35, "       DELETE      ", 1, 4);
				buttons::inactive::smallButton(63, 40, "        EXIT       ");
			}

			// Function for output fifth activ work log management button
			void fifthActive()
			{
				pm::tools::outputBorder(23, 3, 40, 101);
				titles::workLogManagement(44, 5);
				buttons::inactive::smallButton(63, 20, "     VIEW ALL      ");
				buttons::inactive::smallButton(63, 25, "       CREATE      ");
				buttons::inactive::smallButton(63, 30, "        EDIT       ");
				buttons::inactive::smallButton(63, 35, "       DELETE      ");
				buttons::active::smallButton(63, 40, "        EXIT       ", 1, 4);
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
			getline(cin, user.username);
			pm::tools::consoleCoordinates(73, 25);
			getline(cin, user.password);
			if (pm::dal::login::loginAsFirst(user))
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17, 101);
				warnings::successfullyLogin(46, 17);
				Sleep(1500);
				user.role = "admin";
			}
			else if (pm::dal::login::login("../pm.data/users.csv", &user, idOfUser))
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
				pm::consoleApp::menus::userPanel(*idOfUser);
			}
			else if (user.role == "admin")
			{
				pm::consoleApp::menus::adminPanel(*idOfUser);
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
			getline(cin, user.username);
			pm::tools::consoleCoordinates(73, 23);
			getline(cin, user.password);
			if (pm::dal::login::login("../pm.data/users.csv", &user, &idOfUser))
			{
				pm::tools::consoleCoordinates(77, 26);
				getline(cin, newPassword);
				if (pm::tools::checkPassword(newPassword))
				{
					pm::dal::login::cnagePassword("../pm.data/users.csv", user, newPassword);
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
				getline(cin, user.username);
				pm::tools::consoleCoordinates(64, 21);
				getline(cin, user.firstName);
				pm::tools::consoleCoordinates(63, 24);
				getline(cin, user.lastName);
				pm::tools::consoleCoordinates(57, 27);
				getline(cin, user.age);
				pm::tools::consoleCoordinates(62, 30);
				getline(cin, user.password);
				int check = pm::dal::userManagement::registerUser("../pm.data/users.csv", user);
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
				vector<int> id;
				vector<vector<string>> data = pm::dal::userManagement::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id);

				pm::tools::outputBorder(24, 7, data.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
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
					vector<string> user = pm::dal::userManagement::getUserDataById("../pm.data/users.csv", choise);
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
			void deleteUser(string idOfUser, int x, int y)
			{
				system("CLS");
				vector<int> id;
				vector<vector<string>> data = pm::dal::userManagement::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id, idOfUser);

				pm::tools::outputBorder(24, 7, data.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
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
					pm::dal::userManagement::deleteUserByIdInUsersFile("../pm.data/users.csv", choise);
					return;
				}
			}

			// Function for edit data of user
			void editUser(string idOfUser, int x, int y)
			{
				system("CLS");
				vector<int> id;
				vector<vector<string>> data = pm::dal::userManagement::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id, idOfUser);

				pm::tools::outputBorder(24, 7, data.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
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
							 
							getline(cin, newData);
							pm::bll::userManagement::editUserById("../pm.data/users.csv", chosenID, 3, newData);
							break;
						}
						case 2:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DATA THAT YOU WANT TO CHANGE : ";
							 
							getline(cin, newData);
							pm::bll::userManagement::editUserById("../pm.data/users.csv", chosenID, 1, newData);
							break;
						}
						case 3:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DATA THAT YOU WANT TO CHANGE : ";
							 
							getline(cin, newData);
							pm::bll::userManagement::editUserById("../pm.data/users.csv", chosenID, 2, newData);
							break;
						}
						case 4:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DATA THAT YOU WANT TO CHANGE : ";
							 
							getline(cin, newData);
							pm::bll::userManagement::editUserById("../pm.data/users.csv", chosenID, 5, newData);
							break;
						}
						case 5:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DATA THAT YOU WANT TO CHANGE : ";
							 
							getline(cin, newData);
							pm::bll::userManagement::editUserById("../pm.data/users.csv", chosenID, 6, newData);
							break;
						}
						case 6:
						{
							pm::bll::userManagement::editUserById("../pm.data/users.csv", chosenID, 8, newData);
							break;
						}
						}
						editUser(idOfUser, tempX, tempY);
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
				getline(cin, team.name);
				team.idOfCreator = team.idOfLastChanger = idOfUser;
				pm::tools::consoleCoordinates(51, 28);
				system("pause");
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::tools::generateId("../pm.data/users.csv") * 3 + pm::dal::tools::generateId("../pm.data/users.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::userManagement::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id);
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
					pm::dal::teamsManagement::createTeam("../pm.data/teams.csv", team);
				}
				
			}

			// Function for output list of teams
			void showAllTeams(int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::tools::generateId("../pm.data/teams.csv") * 3 + pm::dal::tools::generateId("../pm.data/teams.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tName of team\t\t\tCreator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::teamsManagement::readDataFromTeamsFile("../pm.data/teams.csv", &id);
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
					vector<string> team = pm::dal::teamsManagement::getTeamDataById("../pm.data/teams.csv", choise);
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
				pm::tools::outputBorder(24, 7, pm::dal::tools::generateId("../pm.data/teams.csv") * 3 + pm::dal::tools::generateId("../pm.data/teams.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tName of team\t\t\tCreator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> data = pm::dal::teamsManagement::readDataFromTeamsFile("../pm.data/teams.csv", &id);
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
					pm::dal::teamsManagement::deleteTeamByIdInTeamsFile("../pm.data/teams.csv", choise);
					return;
				}
			}

			// Function for edit data in teams.csv file
			void editTeam(string idOfUser, int x, int y)
			{
				system("CLS");
				pm::tools::outputBorder(24, 7, pm::dal::tools::generateId("../pm.data/teams.csv") * 3 + pm::dal::tools::generateId("../pm.data/teams.csv") / 2, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tName of team\t\t\tCreator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				vector<int> id;
				vector<vector<string>> allData = pm::dal::teamsManagement::readDataFromTeamsFile("../pm.data/teams.csv", &id);
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
							 
							getline(cin, newData);
							pm::bll::teamsManagement::editTeamById("../pm.data/teams.csv", allData, chosenID, 1, newData, idOfUser);
							break;
						}
						case 2:
						{
							system("CLS");
							pm::tools::outputBorder(24, 13, pm::dal::tools::generateId("../pm.data/users.csv") * 3 + pm::dal::tools::generateId("../pm.data/users.csv") / 2, 101);
							pm::tools::consoleCoordinates(x, y);
							cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
							pm::tools::consoleCoordinates(26, y + 1);
							cout << "___________________________________________________________________________________________________";
							vector<int> id;
							vector<vector<string>> data = pm::dal::userManagement::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id);
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
								pm::bll::teamsManagement::editTeamById("../pm.data/teams.csv", allData, chosenID, 6, newData, idOfUser);
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
				 
				getline(cin, project.title);
				pm::tools::consoleCoordinates(57, 21);
				getline(cin, project.description);
				project.idOfCreator = project.idOfLastChanger = idOfUser;
				pm::tools::consoleCoordinates(43, 28);
				system("pause");

				system("CLS");
				vector<int> id;
				vector<vector<string>> data = pm::dal::teamsManagement::readDataFromTeamsFile("../pm.data/teams.csv", &id);
				id = {};
				pm::bll::teamsManagement::checkForContainUserInTeam(data, idOfUser, &id);
				data = pm::bll::projectManagement::getDataById(id, data);

				pm::tools::outputBorder(24, 7, data.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tName of team\t\t\tCreator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
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
				pm::dal::projectManagement::createProject("../pm.data/projects.csv", project);
			}

			// Function for output list of projects
			void showAllProjects(string idOfUser, int x, int y)
			{
				system("CLS");
				vector<int> idOfProject;
				vector<vector<string>> projectData = pm::dal::projectManagement::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				idOfProject = {};
				pm::bll::projectManagement::checkProjectForContainUserInTeam(projectData, idOfUser, &idOfProject);
				projectData = pm::bll::projectManagement::getDataById(idOfProject, projectData);

				pm::tools::outputBorder(24, 7, projectData.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tTitle of project\t\t\tId of creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
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
					vector<string> project = pm::dal::projectManagement::getProjetctDataById("../pm.data/projects.csv", choise);
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
				vector<int> id;
				vector<vector<string>> data = pm::dal::projectManagement::readDataFromProjectsFile("../pm.data/projects.csv", &id);
				id = {};
				pm::bll::projectManagement::checkProjectForContainUserInTeam(data, idOfUser, &id);
				data = pm::bll::projectManagement::getDataById(id, data);

				pm::tools::outputBorder(24, 7, data.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tTitle of project\t\t\tId of creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
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
					pm::dal::projectManagement::deleteProjectByIdInProjectsFile("../pm.data/projects.csv", choise, idOfUser);
					return;
				}
			}

			// Function to add team in a project
			void addTeamInProject(std::string idOfUser, int x, int y)
			{
				system("CLS");
				vector<int> idOfProject;
				vector<vector<string>> projectData = pm::dal::projectManagement::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				vector<vector<string>> allProjectData = pm::dal::projectManagement::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				idOfProject = {};
				pm::bll::projectManagement::findProjectWithoutTeam(projectData, idOfUser, &idOfProject);
				projectData = pm::bll::projectManagement::getDataById(idOfProject, projectData);

				pm::tools::outputBorder(24, 7, projectData.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tTitle of project\t\t\tId of creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
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
					vector<int> idOfTeam;
					vector<vector<string>> dataOfTeam = pm::dal::teamsManagement::readDataFromTeamsFile("../pm.data/teams.csv", &idOfTeam);
					idOfTeam = {};
					pm::bll::teamsManagement::checkForContainUserInTeam(dataOfTeam, idOfUser, &idOfTeam);
					dataOfTeam = pm::bll::projectManagement::getDataById(idOfTeam, dataOfTeam);

					pm::tools::outputBorder(24, 7, dataOfTeam.size() * 3 + 6, 101);
					pm::tools::consoleCoordinates(x, y);
					cout << "Id\t\t\tName of team\t\t\tCreator";
					pm::tools::consoleCoordinates(26, y + 1);
					cout << "___________________________________________________________________________________________________";
					
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
					pm::bll::projectManagement::editIdOfTeam(projectData, allProjectData, choiseOfProject, choiseOfTeam, "../pm.data/projects.csv");
				}
			}

			// Function for edit informtion in the project
			void editProject(std::string idOfUser, int x, int y)
			{
				system("CLS");
				vector<int> idOfProject;
				vector<vector<string>> projectData = pm::dal::projectManagement::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				vector<vector<string>> allProjectData = pm::dal::projectManagement::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				idOfProject = {};
				pm::bll::projectManagement::checkProjectForContainUserInTeam(projectData, idOfUser, &idOfProject);
				projectData = pm::bll::projectManagement::getDataById(idOfProject, projectData);

				pm::tools::outputBorder(24, 7, projectData.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tTitle of project\t\t\tId of creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
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
					pm::tools::outputBorder(24, 13, 20, 101);
					x = 40; y = 16;
					pm::tools::consoleCoordinates(x, y + 2);
					cout << "1. Title of the project";
					pm::tools::consoleCoordinates(x, y + 5);
					cout << "2. Description of the project";
					pm::tools::consoleCoordinates(x, y + 8);
					cout << "3. Id of team";
					int choiseEditInfo = pm::tools::enterNumberWithoutPrintingOnConsole();
					if (choiseEditInfo <= 0 || choiseEditInfo > 4)
					{
						return;
					}
					else
					{
						string newData;

						switch (choiseEditInfo)
						{
						case 1:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW TITLE OF PROJECT : ";
							 
							getline(cin, newData);
							pm::bll::projectManagement::editProjectById("../pm.data/projects.csv", allProjectData, choiseOfProject, 1, newData, idOfUser);
							break;
						}
						case 2:
						{
							pm::tools::consoleCoordinates(35, 31);
							cout << "ENTER THE NEW DESCRIPTION : ";
							 
							getline(cin, newData);
							pm::bll::projectManagement::editProjectById("../pm.data/projects.csv", allProjectData, choiseOfProject, 2, newData, idOfUser);
							break;
						}
						case 3:
						{
							system("CLS");
							x = tempX; y = tempY;
							pm::tools::outputBorder(24, 7, pm::dal::tools::generateId("../pm.data/teams.csv") * 3 + pm::dal::tools::generateId("../pm.data/teams.csv") / 2, 101);
							pm::tools::consoleCoordinates(x, y);
							cout << "Id\t\t\tName of team\t\t\tCreator";
							pm::tools::consoleCoordinates(26, y + 1);
							cout << "___________________________________________________________________________________________________";
							vector<int> idOfTeam;
							vector<vector<string>> dataOfTeam = pm::dal::teamsManagement::readDataFromTeamsFile("../pm.data/teams.csv", &idOfTeam);
							idOfTeam = {};
							pm::bll::teamsManagement::checkForContainUserInTeam(dataOfTeam, idOfUser, &idOfTeam);
							dataOfTeam = pm::bll::projectManagement::getDataById(idOfTeam, dataOfTeam);
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
							pm::bll::projectManagement::editIdOfTeam(projectData, allProjectData, choiseOfProject, choiseOfTeam, "../pm.data/projects.csv");
							break;
						}
						}
					}
				}
			}
		}

		namespace taskManagement
		{
			// Function for choose project that you want to see, add, edit and delete tasks
			void chooseProjectForWorkWithTask(string idOfUser, int x, int y)
			{
				system("CLS");
				vector<int> idOfProject;
				vector<vector<string>> projectData = pm::dal::projectManagement::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				idOfProject = {};
				pm::bll::projectManagement::checkProjectForContainUserInTeam(projectData, idOfUser, &idOfProject);
				projectData = pm::bll::projectManagement::getDataById(idOfProject, projectData);

				pm::tools::outputBorder(24, 7, projectData.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tTitle of project\t\t\tId of creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
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
					pm::consoleApp::menus::taskManagement(idOfUser, to_string(choise));
				}
			}

			// Function for add task in a project
			void createTask(string idOfUser, string idOfProject, int x, int y)
			{
				pm::tools::outputBorder(24, 13, 20, 101);
				pm::types::TASK task;
				pm::tools::consoleCoordinates(43, 18);
				cout << "Title : ";
				pm::tools::consoleCoordinates(43, 21);
				cout << "Description : ";
				pm::tools::consoleCoordinates(51, 18);
				 
				getline(cin, task.title);
				pm::tools::consoleCoordinates(57, 21);
				getline(cin, task.description);
				task.idOfCreator = task.idOfLastChanger = idOfUser;
				task.idOfProject = idOfProject;
				// Choose the user that have to make the task (Id of the Assignee)
				system("CLS");
				vector<int> id;
				vector<vector<string>> data = pm::dal::userManagement::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id, idOfUser);
				pm::tools::outputBorder(24, 7, data.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
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
					string idOfTask;
					task.idOfAssignee = to_string(choise);
					pm::dal::taskManagement::createTask("../pm.data/tasks.csv", task, &idOfTask);
					pm::bll::taskManagement::addTaskInProject(idOfProject, idOfTask);
				}
			}

			// Function for show all task in a project
			void showAllTask(string idOfUser, string idOfProject, int x, int y)
			{
				system("CLS");
				vector<int> idOfTask;
				vector<vector<string>> taskData = pm::dal::taskManagement::readDataFromTaskFile("../pm.data/tasks.csv", idOfProject, idOfUser, &idOfTask);
				pm::tools::outputBorder(24, 7, taskData.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tId of the Assignee\t\tId of the creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";
				
				int tempX = x, tempY = y;
				y += 2;
				for (auto row : taskData)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 8)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int taskChoise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < idOfTask.size(); i++)
				{
					if (taskChoise == idOfTask[i])
					{
						exist = true;
					}
				}
				if (taskChoise == 0 || !exist)
				{
					return;
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 13, 21, 101);
					vector<string> task = pm::dal::taskManagement::getTaskDataById("../pm.data/tasks.csv", taskChoise);
					x = 40; y = 15;
					pm::tools::consoleCoordinates(x, y + 1);
					cout << "Id of the task : " << task[0];
					pm::tools::consoleCoordinates(x, y + 3);
					cout << "Id of the project : " << task[1];
					pm::tools::consoleCoordinates(x, y + 5);
					cout << "Id of the Assignee : " << task[2];
					pm::tools::consoleCoordinates(x, y + 7);
					cout << "Title of the task : " << task[3];
					pm::tools::consoleCoordinates(x, y + 9);
					cout << "Description of the task : " << task[4];
					pm::tools::consoleCoordinates(x, y + 11);
					cout << "Status of the task : " << task[5];
					pm::tools::consoleCoordinates(x, y + 13);
					cout << "Data of creation : " << task[6];
					pm::tools::consoleCoordinates(x, y + 15);
					cout << "Id of the creator : " << task[7];
					pm::tools::consoleCoordinates(x, y + 17);
					cout << "Date of last changes : " << task[8];
					pm::tools::consoleCoordinates(x, y + 19);
					cout << "Id of last changer : " << task[9];
					pm::tools::consoleCoordinates(x + 20, y + 21);
					system("pause");
				}
			}

			// Function for delete task
			void deleteTask(string idOfUser, string idOfProject, int x, int y)
			{
				system("CLS");
				vector<int> idOfTask;
				vector<vector<string>> taskData = pm::dal::taskManagement::readDataFromTaskFile("../pm.data/tasks.csv", idOfProject, idOfUser, &idOfTask);
				pm::tools::outputBorder(24, 7, taskData.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tId of the Assignee\t\tId of the creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";

				int tempX = x, tempY = y;
				y += 2;
				for (auto row : taskData)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 8)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int taskChoise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < idOfTask.size(); i++)
				{
					if (taskChoise == idOfTask[i])
					{
						exist = true;
					}
				}
				if (taskChoise == 0 || !exist)
				{
					return;
				}
				else
				{
					pm::dal::taskManagement::deleteTaskByIdInTaskFile("../pm.data/tasks.csv", taskChoise, idOfUser);
				}
			}

			// Function for edit data in a task
			void editTask(string idOfUser, string idOfProject, int x, int y)
			{
				system("CLS");
				vector<int> idOfTask;
				vector<vector<string>> taskData = pm::dal::taskManagement::readDataFromTaskFile("../pm.data/tasks.csv", idOfProject, idOfUser, &idOfTask);
				pm::tools::outputBorder(24, 7, taskData.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tId of the Assignee\t\tId of the creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";

				int tempX = x, tempY = y;
				y += 2;
				for (auto row : taskData)
				{
					int counter = 1;
					y += 3;
					x = tempX;
					for (auto col : row)
					{
						if (counter == 1)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 3)
						{
							pm::tools::consoleCoordinates(x, y);
							x += 32;
							cout << col;
						}
						else if (counter == 8)
						{
							pm::tools::consoleCoordinates(x, y);
							cout << col;
						}
						counter++;
					}
				}
				int taskChoise = pm::tools::enterNumberWithoutPrintingOnConsole();
				bool exist = false;
				for (int i = 0; i < idOfTask.size(); i++)
				{
					if (taskChoise == idOfTask[i])
					{
						exist = true;
					}
				}
				if (taskChoise == 0 || !exist)
				{
					return;
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 13, 22, 101);
					x = 40; y = 15;
					pm::tools::consoleCoordinates(x, y + 2);
					cout << "1. Title of the task";
					pm::tools::consoleCoordinates(x, y + 5);
					cout << "2. Description of the task";
					pm::tools::consoleCoordinates(x, y + 8);
					cout << "3. Id of project";
					pm::tools::consoleCoordinates(x, y + 11);
					cout << "4. Id of the Assignee";
					pm::tools::consoleCoordinates(x, y + 14);
					cout << "5. Status";
					int choiseEditInfo = pm::tools::enterNumberWithoutPrintingOnConsole();
					if (choiseEditInfo <= 0 || choiseEditInfo > 5)
					{
						return;
					}
					else
					{
						string newData;

						switch (choiseEditInfo)
						{
						case 1:
						{
							pm::tools::consoleCoordinates(35, 33);
							cout << "ENTER THE NEW TITLE : ";
							getline(cin, newData);
							pm::bll::taskManagement::editTaskById("../pm.data/tasks.csv", taskChoise, 3, newData, idOfUser);
							break;
						}
						case 2:
						{
							pm::tools::consoleCoordinates(35, 33);
							cout << "ENTER THE NEW DESCRIPTION : ";
							getline(cin, newData);
							pm::bll::taskManagement::editTaskById("../pm.data/tasks.csv", taskChoise, 4, newData, idOfUser);
							break;
						}
						case 3:
						{
							system("CLS");
							vector<int> idOfProject;
							vector<vector<string>> projectData = pm::dal::projectManagement::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
							idOfProject = {};
							pm::bll::projectManagement::checkProjectForContainUserInTeam(projectData, idOfUser, &idOfProject);
							projectData = pm::bll::projectManagement::getDataById(idOfProject, projectData);

							pm::tools::outputBorder(24, 13, projectData.size() * 3 + 6, 101);
							pm::tools::consoleCoordinates(x, y);
							cout << "Id\t\t\tTitle of project\t\t\tId of creator";
							pm::tools::consoleCoordinates(26, y + 1);
							cout << "___________________________________________________________________________________________________";

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
								pm::bll::taskManagement::editTaskById("../pm.data/tasks.csv", taskChoise, 1, to_string(choise), idOfUser);
							}
							break;
						}
						case 4:
						{
							system("CLS");
							vector<int> id;
							vector<vector<string>> data = pm::dal::userManagement::readDataForIdUsernameFirstAndLastName("../pm.data/users.csv", &id, idOfUser);

							pm::tools::outputBorder(24, 13, data.size() * 3 + 6, 101);
							pm::tools::consoleCoordinates(x, y);
							cout << "Id\t\tUsername\t\tFirstName\t\tLastName";
							pm::tools::consoleCoordinates(26, y + 1);
							cout << "___________________________________________________________________________________________________";

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
								pm::bll::taskManagement::editTaskById("../pm.data/tasks.csv", taskChoise, 2, to_string(choise), idOfUser);
							}
							break;
						}
						case 5:
						{
							pm::tools::consoleCoordinates(35, 33);
							cout << "ENTER THE NEW STATUS [pending/inProgress/completed] : ";
							getline(cin, newData);
							for (auto row : taskData)
							{
								if (row[0] == to_string(taskChoise) && row[5] == "pending" && (newData == "inProgress" || newData == "completed"))
								{
									pm::bll::taskManagement::editTaskById("../pm.data/tasks.csv", taskChoise, 5, newData, idOfUser);
								}
								else if (row[0] == to_string(taskChoise) && row[5] == "inProgress" && (newData == "pending" || newData == "completed"))
								{
									pm::bll::taskManagement::editTaskById("../pm.data/tasks.csv", taskChoise, 5, newData, idOfUser);
								}
								else if (row[0] == to_string(taskChoise) && row[5] == "completed" && (newData == "inProgress" || newData == "pending"))
								{
									pm::bll::taskManagement::editTaskById("../pm.data/tasks.csv", taskChoise, 5, newData, idOfUser);
								}
							}
							break;
						}
						}
					}
				}
			}
		}

		namespace workLogManagement
		{
			// Function for choose task that you want to see, add, edit and delete work log
			void chooseTaskForWorkLog(string idOfUser, int x, int y)
			{
				system("CLS");
				vector<int> idOfProject;
				vector<vector<string>> projectData = pm::dal::projectManagement::readDataFromProjectsFile("../pm.data/projects.csv", &idOfProject);
				idOfProject = {};
				pm::bll::projectManagement::checkProjectForContainUserInTeam(projectData, idOfUser, &idOfProject);
				projectData = pm::bll::projectManagement::getDataById(idOfProject, projectData);

				pm::tools::outputBorder(24, 7, projectData.size() * 3 + 6, 101);
				pm::tools::consoleCoordinates(x, y);
				cout << "Id\t\t\tTitle of project\t\t\tId of creator";
				pm::tools::consoleCoordinates(26, y + 1);
				cout << "___________________________________________________________________________________________________";

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
					x = tempX; y = tempY;
					system("CLS");
					vector<int> idOfTask;
					vector<vector<string>> taskData = pm::dal::taskManagement::readDataFromTaskFile("../pm.data/tasks.csv", to_string(choise), idOfUser, &idOfTask);
					pm::tools::outputBorder(24, 7, taskData.size() * 3 + 6, 101);
					pm::tools::consoleCoordinates(x, y);
					cout << "Id\t\t\tId of the Assignee\t\tId of the creator";
					pm::tools::consoleCoordinates(26, y + 1);
					cout << "___________________________________________________________________________________________________";
					
					y += 2;
					for (auto row : taskData)
					{
						int counter = 1;
						y += 3;
						x = tempX;
						for (auto col : row)
						{
							if (counter == 1)
							{
								pm::tools::consoleCoordinates(x, y);
								x += 32;
								cout << col;
							}
							else if (counter == 3)
							{
								pm::tools::consoleCoordinates(x, y);
								x += 32;
								cout << col;
							}
							else if (counter == 8)
							{
								pm::tools::consoleCoordinates(x, y);
								cout << col;
							}
							counter++;
						}
					}
					int taskChoise = pm::tools::enterNumberWithoutPrintingOnConsole();
					bool exist = false;
					for (int i = 0; i < idOfTask.size(); i++)
					{
						if (taskChoise == idOfTask[i])
						{
							exist = true;
						}
					}
					if (taskChoise == 0 || !exist)
					{
						return;
					}
					else
					{
						pm::consoleApp::menus::workLogManagement(idOfUser, to_string(taskChoise));
					}
				}
			}

			// Function for add work log in a task
			void createWorkLog(string idOfUser, string idOfTask)
			{
				pm::tools::outputBorder(24, 13, 20, 101);
				pm::types::WORK_LOG workLog;
				pm::tools::consoleCoordinates(43, 22);
				cout << "How many hours did you spent on task #" << idOfTask << " : ";
				pm::tools::consoleCoordinates(84 + idOfTask.size(), 22);
				getline(cin, workLog.workTime);
				workLog.idOfUser = idOfUser;
				workLog.idOfTask = idOfTask;
				pm::dal::workLogManagement::createWorkLog("../pm.data/workLogs.csv", workLog);
			}
		}
	}

	namespace menus
	{
		// Function for movement in work log management
		void workLogManagement(string idOfUser, string idOfTask)
		{
			int choice;
			bool truth;
			system("CLS");
			buttons::workLogManagement::firstActive();
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
						buttons::workLogManagement::fifthActive();
						choice = 5;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::workLogManagement::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::workLogManagement::secondActive();
						choice = 2;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::workLogManagement::thirdActive();
						choice = 3;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::workLogManagement::fourthActive();
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
						buttons::workLogManagement::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::workLogManagement::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::workLogManagement::fourthActive();
						choice = 4;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::workLogManagement::fifthActive();
						choice = 5;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::workLogManagement::firstActive();
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
							choice = 6;
							break;
						}
						case 2:
						{
							system("CLS");
							windows::workLogManagement::createWorkLog(idOfUser, idOfTask);
							choice = 6;
							break;
						}
						case 3:
						{
							system("CLS");
							choice = 6;
							break;
						}
						case 4:
						{
							system("CLS");
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
							buttons::workLogManagement::firstActive();
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

		// Function for movement in task management
		void taskManagement(string idOfUser, string idOfProject)
		{
			int choice;
			bool truth;
			system("CLS");
			buttons::taskManagement::firstActive();
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
						buttons::taskManagement::fifthActive();
						choice = 5;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::taskManagement::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::taskManagement::secondActive();
						choice = 2;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::taskManagement::thirdActive();
						choice = 3;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::taskManagement::fourthActive();
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
						buttons::taskManagement::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::taskManagement::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::taskManagement::fourthActive();
						choice = 4;
						break;
					}
					case 4:
					{
						system("CLS");
						buttons::taskManagement::fifthActive();
						choice = 5;
						break;
					}
					case 5:
					{
						system("CLS");
						buttons::taskManagement::firstActive();
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
							pm::consoleApp::windows::taskManagement::showAllTask(idOfUser, idOfProject, 40, 9);
							choice = 6;
							break;
						}
						case 2:
						{
							system("CLS");
							pm::consoleApp::windows::taskManagement::createTask(idOfUser, idOfProject, 40, 9);
							choice = 6;
							break;
						}
						case 3:
						{
							system("CLS");
							pm::consoleApp::windows::taskManagement::editTask(idOfUser, idOfProject, 40, 9);
							choice = 6;
							break;
						}
						case 4:
						{
							system("CLS");
							pm::consoleApp::windows::taskManagement::deleteTask(idOfUser, idOfProject, 40, 9);
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
							buttons::taskManagement::firstActive();
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
							windows::projectsManagement::editProject(idOfUser, 40, 9);
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
		void userManagement(string idOfUser)
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
							windows::userManagement::editUser(idOfUser, 40, 9);
							choice = 6;
							break;
						}
						case 4:
						{
							system("CLS");
							windows::userManagement::deleteUser(idOfUser, 40, 9);
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
		void adminPanel(string idOfUser)
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
							userManagement(idOfUser);
							choice = 4;
							break;
						}
						case 2:
						{
							system("CLS");
							teamsManagement(idOfUser);
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
		void userPanel(string idOfUser)
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
							projectManagement(idOfUser);
							choice = 5;
							break;
						}
						case 2:
						{
							system("CLS");
							pm::consoleApp::windows::taskManagement::chooseProjectForWorkWithTask(idOfUser, 40, 9);
							choice = 5;
							break;
						}
						case 3:
						{
							system("CLS");
							pm::consoleApp::windows::workLogManagement::chooseTaskForWorkLog(idOfUser, 40, 9);
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
			pm::tools::setConsoleSize();
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