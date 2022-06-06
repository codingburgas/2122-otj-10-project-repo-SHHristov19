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

		// Function for output login menu title in a current position
		void loginTitle(int x, int y)
		{
			pm::tools::consoleCoordinates(x, y);
			cout << " _             _                      " << endl;
			pm::tools::consoleCoordinates(x, y + 1);
			cout << "| |           (_)                     " << endl;
			pm::tools::consoleCoordinates(x, y + 2);
			cout << "| | ___   ____ _ ____      ____  ___  " << endl;
			pm::tools::consoleCoordinates(x, y + 3);
			cout << "| |/ _ \\ / _  | |  _ \\    / _  |/___) " << endl;
			pm::tools::consoleCoordinates(x, y + 4);
			cout << "| | |_| ( ( | | | | | |  ( ( | |___ | " << endl;
			pm::tools::consoleCoordinates(x, y + 5);
			cout << "|_|\\___/ \\_|| |_|_| |_|   \\_||_(___/  " << endl;
			pm::tools::consoleCoordinates(x, y + 6);
			cout << "        (_____|                       " << endl;
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
				pm::tools::outputBorder(16, 3, 39);
				titles::projectManagerMenu(25, 7);
				buttons::active::buttonLogin(56, 19, "    LOGIN    ", 0, 3);
				buttons::inactive::buttonLogin(56, 25, "   REGISTER  ");
				buttons::inactive::buttonLogin(56, 31, " CHANGE PASS ");
				buttons::inactive::buttonLogin(56, 37, "     EXIT    ");
			}

			// Function for output second activ main menu button
			void secondActive()
			{
				pm::tools::outputBorder(16, 3, 39);
				titles::projectManagerMenu(25, 7);
				buttons::inactive::buttonLogin(56, 19, "    LOGIN    ");
				buttons::active::buttonLogin(56, 25, "   REGISTER  ", 0, 3);
				buttons::inactive::buttonLogin(56, 31, " CHANGE PASS ");
				buttons::inactive::buttonLogin(56, 37, "     EXIT    ");
			}

			// Function for output third activ main menu button
			void thirdActive()
			{
				pm::tools::outputBorder(16, 3, 39);
				titles::projectManagerMenu(25, 7);
				buttons::inactive::buttonLogin(56, 19, "    LOGIN    ");
				buttons::inactive::buttonLogin(56, 25, "   REGISTER  ");
				buttons::active::buttonLogin(56, 31, " CHANGE PASS ", 0, 3);
				buttons::inactive::buttonLogin(56, 37, "     EXIT    ");
			}

			// Function for output fourth activ main menu button
			void fourthActive()
			{
				pm::tools::outputBorder(16, 3, 39);
				titles::projectManagerMenu(25, 7);
				buttons::inactive::buttonLogin(56, 19, "    LOGIN    ");
				buttons::inactive::buttonLogin(56, 25, "   REGISTER  ");
				buttons::inactive::buttonLogin(56, 31, " CHANGE PASS ");
				buttons::active::buttonLogin(56, 37, "     EXIT    ", 0, 3);
			}
		}

		namespace login
		{
			// Function for output first activ login menu button
			void firstActive()
			{
				pm::tools::outputBorder(16, 8, 29);
				titles::loginTitle(47, 13);
				buttons::active::buttonLogin(55, 23, "    ADMIN    ", 0, 6);
				buttons::inactive::buttonLogin(55, 28, "     USER    ");
				buttons::inactive::buttonLogin(55, 33, "     EXIT    ");
			}

			// Function for output second activ login menu button
			void secondActive()
			{
				pm::tools::outputBorder(16, 8, 29);
				titles::loginTitle(47, 13);
				buttons::inactive::buttonLogin(55, 23, "    ADMIN    ");
				buttons::active::buttonLogin(55, 28, "     USER    ", 0, 6);
				buttons::inactive::buttonLogin(55, 33, "     EXIT    ");
			}

			// Function for output third activ login menu button
			void thirdActive()
			{
				pm::tools::outputBorder(16, 8, 29);
				titles::loginTitle(47, 13);
				buttons::inactive::buttonLogin(55, 23, "    ADMIN    ");
				buttons::inactive::buttonLogin(55, 28, "     USER    ");
				buttons::active::buttonLogin(55, 33, "     EXIT    ", 0, 6);
			}
		}
	}

	namespace windows
	{
		// Function for output login window as user
		void loginAsUser()
		{
			pm::tools::outputBorder(16, 13, 20);
			string username, firstName, lastName, password;
			int age;
			pm::tools::consoleCoordinates(50, 18);
			cout << "Username : ";
			pm::tools::consoleCoordinates(50, 21);
			cout << "First name : ";
			pm::tools::consoleCoordinates(50, 24);
			cout << "Last name : ";
			pm::tools::consoleCoordinates(50, 27);
			cout << "Age : ";
			pm::tools::consoleCoordinates(50, 30);
			cout << "Password : ";
			pm::tools::consoleCoordinates(61, 18);
			cin >> username;
			pm::tools::consoleCoordinates(63, 21);
			cin >> firstName;
			pm::tools::consoleCoordinates(62, 24);
			cin >> lastName;
			pm::tools::consoleCoordinates(56, 27);
			cin >> age;
			pm::tools::consoleCoordinates(61, 30);
			cin >> password;
		}
	}

	namespace menus
	{
		void loginMenu(); // Function prototype

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
							loginMenu();
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

		// Function for movement login menu
		void loginMenu()
		{
			int choice;
			system("CLS");
			buttons::login::firstActive();
			choice = 1;
			while (true) {
				switch (_getch()) {
				case KEY_UP:
					switch (choice)
					{
					case 1:
					{
						system("CLS");
						buttons::login::thirdActive();
						choice = 3;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::login::firstActive();
						choice = 1;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::login::secondActive();
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
						buttons::login::secondActive();
						choice = 2;
						break;
					}
					case 2:
					{
						system("CLS");
						buttons::login::thirdActive();
						choice = 3;
						break;
					}
					case 3:
					{
						system("CLS");
						buttons::login::firstActive();
						choice = 1;
						break;
					}
					}
					break;
				case KEY_ENTER:
					switch (choice)
					{
					case 1:
					{
						Sleep(200);
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
						return;
						break;
					}
					case 4:
					{
						system("CLS");
						choice = 1;
						buttons::login::firstActive();
						break;
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