#include "pm.designApp.h"
#include "../pm.dal/pm.dal.h"
#include "../pm.bll/pm.bll.h"

namespace pm::designApp
{
	namespace titles
	{
		// Function for output main menu title in a current position
		void projectManagerMenu(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << "                  _                                                                " << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "                 (_)           _                                                   " << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << " ____   ____ ___  _  ____ ____| |_       ____   ____ ____   ____  ____  ____  ____ " << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "|  _ \\ / ___) _ \\| |/ _  ) ___)  _)     |    \\ / _  |  _ \\ / _  |/ _  |/ _  )/ ___)" << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "| | | | |  | |_| | ( (/ ( (___| |__     | | | ( ( | | | | ( ( | ( ( | ( (/ /| |    " << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << "| ||_/|_|   \\___/| |\\____)____)\\___)    |_|_|_|\\_||_|_| |_|\\_||_|\\_|| |\\____)_|    " << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "|_|            (__/                                             (_____|            " << endl;
		}

		// Function for output admin panel title in a current position
		void adminPanelMenu(int x, int y)
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
	}

	namespace buttons
	{
		namespace active
		{
			// Functions for output painted button in a current position with set color for login panel
			void buttonLogin(int x, int y, string word, int nuance, int color)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << "\x1b[" << nuance << ";3" << color << "m" << " .-----------------. " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "\x1b[" << nuance << ";3" << color << "m" << "(   " << word << "   )" << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << "\x1b[" << nuance << ";3" << color << "m" << " '-----------------' " << "\x1b[1;37m" << endl;
			}

			// Function for output painted button in a current position with set color for admin panel
			void buttonAdminPanel(int x, int y, string word, int nuance, int color)
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
			void buttonLogin(int x, int y, string word)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << " .-----------------. " << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "(   " << word << "   )" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << " '-----------------' " << endl;
			}

			// Function for output button in a current position for admin panel
			void buttonAdminPanel(int x, int y, string word)
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

		namespace mainMenu
		{
			// Function for output first activ main menu button
			void firstActive()
			{
				pm::tools::outputBorder(23, 3, 39);
				titles::projectManagerMenu(32, 7);
				buttons::active::buttonLogin(63, 19, "    LOGIN    ", 0, 3);
				buttons::inactive::buttonLogin(63, 25, " CHANGE PASS ");
				buttons::inactive::buttonLogin(63, 31, "     EXIT    ");
			}

			// Function for output second activ main menu button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 39);
				titles::projectManagerMenu(32, 7);
				buttons::inactive::buttonLogin(63, 19, "    LOGIN    ");
				buttons::active::buttonLogin(63, 25, " CHANGE PASS ", 0, 3);
				buttons::inactive::buttonLogin(63, 31, "     EXIT    ");
			}

			// Function for output third activ main menu button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 39);
				titles::projectManagerMenu(32, 7);
				buttons::inactive::buttonLogin(63, 19, "    LOGIN    ");
				buttons::inactive::buttonLogin(63, 25, " CHANGE PASS ");
				buttons::active::buttonLogin(63, 31, "     EXIT    ", 0, 3);
			}
		}

		namespace adminPanel
		{
			// Function for output first activ admin panel button
			void firstActive()
			{
				pm::tools::outputBorder(23, 3, 39);
				titles::adminPanelMenu(45, 8);
				buttons::active::buttonAdminPanel(60, 19, "      USER MANAGEMENT      ", 0, 6);
				buttons::inactive::buttonAdminPanel(60, 26, "      TEAMS MANAGEMENT     ");
				buttons::inactive::buttonAdminPanel(60, 33, "           EXIT            ");
			}

			// Function for output second activ admin panel button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 39);
				titles::adminPanelMenu(45, 8);
				buttons::inactive::buttonAdminPanel(60, 19, "      USER MANAGEMENT      ");
				buttons::active::buttonAdminPanel(60, 26, "      TEAMS MANAGEMENT     ", 0, 6);
				buttons::inactive::buttonAdminPanel(60, 33, "           EXIT            ");
			}

			// Function for output third activ admin panel button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 39);
				titles::adminPanelMenu(45, 8);
				buttons::inactive::buttonAdminPanel(60, 19, "      USER MANAGEMENT      ");
				buttons::inactive::buttonAdminPanel(60, 26, "      TEAMS MANAGEMENT     ");
				buttons::active::buttonAdminPanel(60, 33, "           EXIT            ", 0, 6);
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
		void login()
		{
			pm::tools::outputBorder(24, 17, 13);
			string username, password;
			pm::tools::consoleCoordinates(51, 22);
			cout << "Enter your username : ";
			pm::tools::consoleCoordinates(51, 25);
			cout << "Enter your password : ";
			pm::tools::consoleCoordinates(73, 22);
			cin >> username;
			pm::tools::consoleCoordinates(73, 25);
			cin >> password;
			if (pm::dal::login("../pm.data/users.csv", username, password))
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17);
				warnings::successfullyLogin(46, 17);
				Sleep(1500);
			}
			else if (pm::dal::loginAsFirst(username, password))
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17);
				warnings::successfullyLogin(46, 17);
				Sleep(1500);
				pm::designApp::menus::adminPanel();
			}
			else
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17);
				warnings::tryAgain(56, 18);
				Sleep(1500);
			}
		}

		// Function for output register windows
		void registerUser()
		{
			pm::tools::outputBorder(24, 13, 20);
			string username, firstName, lastName, password;
			int age;
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
			cin >> username;
			pm::tools::consoleCoordinates(64, 21);
			cin >> firstName;
			pm::tools::consoleCoordinates(63, 24);
			cin >> lastName;
			pm::tools::consoleCoordinates(57, 27);
			cin >> age;
			pm::tools::consoleCoordinates(62, 30);
			cin >> password;
			int check = pm::dal::registerUser("../pm.data/users.csv", firstName, lastName, username, password, to_string(age));
			if (check == 1)
			{
				system("CLS");
				pm::tools::outputBorder(24, 13, 20);
				warnings::successfullyLogin(46, 17);
				Sleep(1500);
			}
			else if (check == 2)
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17);
				pm::designApp::windows::warnings::theUsernameAlreadyExists(55, 18);
				Sleep(2000);
			}
			else
			{
				system("CLS");
				pm::tools::outputBorder(24, 13, 20);
				warnings::tryAgain(56, 18);
				Sleep(1500);
			}
		}

		// Function for changing password
		void changePassword()
		{	
			pm::tools::outputBorder(24, 15, 16);
			string username, password, newPassword;
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
			cin >> username;
			pm::tools::consoleCoordinates(73, 23);
			cin >> password;
			if (pm::dal::login("../pm.data/users.csv", username, password))
			{
				pm::tools::consoleCoordinates(77, 26);
				cin >> newPassword;
				if (pm::bll::checkPassword(newPassword))
				{
					pm::dal::cnagePassword("../pm.data/users.csv", username, password, newPassword);
					system("CLS");
					pm::tools::outputBorder(24, 14, 17);
					warnings::successfullyLogin(46, 17);
					Sleep(1500);
				}
				else
				{
					system("CLS");
					pm::tools::outputBorder(24, 14, 17);
					warnings::tryAgain(56, 18);
					Sleep(1500);
				}
			}
			else
			{
				system("CLS");
				pm::tools::outputBorder(24, 14, 17);
				warnings::tryAgain(56, 18);
				Sleep(1500);
			}
		}
	}

	namespace menus
	{
		// Function for movement in admin panel
		void adminPanel()
		{
			int choice;
			bool truth;
			system("CLS");
			buttons::adminPanel::firstActive();
			choice = 1;
			while (true) {
				truth = true;
				switch (_getch()) {
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
							choice = 4;
							break;
						}
						case 2:
						{
							system("CLS");
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

		// Function for movement in main Menu
		void menu()
		{
			int choice;
			bool truth;
			system("CLS");
			buttons::mainMenu::firstActive();
			choice = 1;
			while (true) {
				truth = true;
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::mainMenu::thirdActive();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::mainMenu::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::mainMenu::secondActive();
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
						buttons::mainMenu::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::mainMenu::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::mainMenu::firstActive();
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
							windows::login();
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
							buttons::mainMenu::firstActive();
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