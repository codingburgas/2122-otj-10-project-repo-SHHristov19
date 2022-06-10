#include "pm.designApp.h"
#include "../pm.dal/pm.dal.h"

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
	}

	namespace buttons
	{
		namespace active
		{
			// Function for output painted button in a current position with set color
			void buttonLogin(int x, int y, string word, int nuance, int color)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << "\x1b[" << nuance << ";3" << color << "m" << " .-----------------. " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "\x1b[" << nuance << ";3" << color << "m" << "(   " << word << "   )" << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << "\x1b[" << nuance << ";3" << color << "m" << " '-----------------' " << "\x1b[1;37m" << endl;
			}
		}

		// Function for output button in a current position
		namespace inactive
		{
			void buttonLogin(int x, int y, string word)
			{
				pm::tools::consoleCoordinates(x, y);
				cout << " .-----------------. " << endl;
				pm::tools::consoleCoordinates(x, y + 1);
				cout << "(   " << word << "   )" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << " '-----------------' " << endl;
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
				buttons::inactive::buttonLogin(63, 25, "   REGISTER  ");
				buttons::inactive::buttonLogin(63, 31, " CHANGE PASS ");
				buttons::inactive::buttonLogin(63, 37, "     EXIT    ");
			}

			// Function for output second activ main menu button
			void secondActive()
			{
				pm::tools::outputBorder(23, 3, 39);
				titles::projectManagerMenu(32, 7);
				buttons::inactive::buttonLogin(63, 19, "    LOGIN    ");
				buttons::active::buttonLogin(63, 25, "   REGISTER  ", 0, 3);
				buttons::inactive::buttonLogin(63, 31, " CHANGE PASS ");
				buttons::inactive::buttonLogin(63, 37, "     EXIT    ");
			}

			// Function for output third activ main menu button
			void thirdActive()
			{
				pm::tools::outputBorder(23, 3, 39);
				titles::projectManagerMenu(32, 7);
				buttons::inactive::buttonLogin(63, 19, "    LOGIN    ");
				buttons::inactive::buttonLogin(63, 25, "   REGISTER  ");
				buttons::active::buttonLogin(63, 31, " CHANGE PASS ", 0, 3);
				buttons::inactive::buttonLogin(63, 37, "     EXIT    ");
			}

			// Function for output fourth activ main menu button
			void fourthActive()
			{
				pm::tools::outputBorder(23, 3, 39);
				titles::projectManagerMenu(32, 7);
				buttons::inactive::buttonLogin(63, 19, "    LOGIN    ");
				buttons::inactive::buttonLogin(63, 25, "   REGISTER  ");
				buttons::inactive::buttonLogin(63, 31, " CHANGE PASS ");
				buttons::active::buttonLogin(63, 37, "     EXIT    ", 0, 3);
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
				cout << "\x1b[1;31m" << "           /  __   __   \\         " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 2);
				cout << "\x1b[1;31m" << "          |   \\ \\ / /    |        " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 3);
				cout << "\x1b[1;31m" << "         |     \\   /      |       " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 4);
				cout << "\x1b[1;31m" << "         |     / /\\ \\     |       " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 5);
				cout << "\x1b[1;31m" << "          |   /_/  \\_\\   |        " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 6);
				cout << "\x1b[1;31m" << "           \\____________/         " << "\x1b[1;37m" << endl << endl;
				pm::tools::consoleCoordinates(x, y + 7);
				cout << " _                          _     " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 8);
				cout << "| |_ ___ _ _    ___ ___ ___|_|___ " << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 9);
				cout << "|  _|  _| | |  | .'| . | .'| |   |" << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 10);
				cout << "|_| |_| |_  |  |__,|_  |__,|_|_|_|" << "\x1b[1;37m" << endl;
				pm::tools::consoleCoordinates(x, y + 11);
				cout << "        |___|      |___|          " << "\x1b[1;37m" << endl;
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
			if (pm::dal::loginAsFirst(username, password))
			{
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
		}
	}

	namespace menus
	{
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
						buttons::mainMenu::fourthActive();
						choice = 4;
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
					case 4:
					{
						system("CLS");
						buttons::mainMenu::thirdActive();
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
						buttons::mainMenu::fourthActive();
						choice = 4;
						break;
					}
					case 4:
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
							choice = 5;
							windows::login();
							break;
						}
						case 2:
						{
							system("CLS");
							choice = 5;
							windows::registerUser();
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