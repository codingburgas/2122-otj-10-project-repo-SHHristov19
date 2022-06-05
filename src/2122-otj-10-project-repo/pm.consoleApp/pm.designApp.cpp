#include "pm.designApp.h"

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
				pm::tools::outputBorder(16, 3, 42);
				titles::projectManagerMenu(25, 7);
				buttons::active::buttonLogin(56, 19, "    LOGIN    ", 0, 3);
				buttons::inactive::buttonLogin(56, 25, "   REGISTER  ");
				buttons::inactive::buttonLogin(56, 31, " CHANGE PASS ");
				buttons::inactive::buttonLogin(56, 37, "     EXIT    ");
			}

			// Function for output second activ main menu button
			void secondActive()
			{
				pm::tools::outputBorder(16, 3, 42);
				titles::projectManagerMenu(25, 7);
				buttons::inactive::buttonLogin(56, 19, "    LOGIN    ");
				buttons::active::buttonLogin(56, 25, "   REGISTER  ", 0, 3);
				buttons::inactive::buttonLogin(56, 31, " CHANGE PASS ");
				buttons::inactive::buttonLogin(56, 37, "     EXIT    ");
			}

			// Function for output third activ main menu button
			void thirdActive()
			{
				pm::tools::outputBorder(16, 3, 42);
				titles::projectManagerMenu(25, 7);
				buttons::inactive::buttonLogin(56, 19, "    LOGIN    ");
				buttons::inactive::buttonLogin(56, 25, "   REGISTER  ");
				buttons::active::buttonLogin(56, 31, " CHANGE PASS ", 0, 3);
				buttons::inactive::buttonLogin(56, 37, "     EXIT    ");
			}

			// Function for output fourth activ main menu button
			void fourthActive()
			{
				pm::tools::outputBorder(16, 3, 42);
				titles::projectManagerMenu(25, 7);
				buttons::inactive::buttonLogin(56, 19, "    LOGIN    ");
				buttons::inactive::buttonLogin(56, 25, "   REGISTER  ");
				buttons::inactive::buttonLogin(56, 31, " CHANGE PASS ");
				buttons::active::buttonLogin(56, 37, "     EXIT    ", 0, 3);
			}
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