#include "pch.h"
#include "pm.tools.h"

namespace pm::tools
{
    // Function for displaying text in given console coordinates
    void consoleCoordinates(int x, int y)
    {
        COORD c;
        c.X = x;
        c.Y = y;

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }

    // Function for outputing the console in given size
    void setConsoleSize()
    {
        HWND console = GetConsoleWindow();
        MoveWindow(console, 200, 10, 1100, 810, TRUE);
    }

    // Function for output border with set length
    void outputBorder(int x, int y, int end)
    {
        consoleCoordinates(x, y);
        cout << "_____________________________________________________________________________________________________" << endl;
        while (y != end)
        {
            y++;
            consoleCoordinates(x, y);
            cout << "|                                                                                                   |" << endl;
        }
        y++;
        consoleCoordinates(x, y);
        cout << "|___________________________________________________________________________________________________|" << endl;
    }
}
