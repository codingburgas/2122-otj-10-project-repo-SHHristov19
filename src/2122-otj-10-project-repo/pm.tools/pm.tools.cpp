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
    void outputBorder(int x, int y, int height, int length)
    {
        string line;
        line += "|";
        for (int j = 0; j < length; j++)
        {
            line += " ";
        }
        line += "|";
        consoleCoordinates(x, y);
        for (int i = 0; i <= length; i++)
        {
            cout << "_";
        }
        cout << '\n';
        for(int i = 0; i < height; i++)
        {
            y++;
            consoleCoordinates(x, y);
            cout << line << '\n';
        }
        y++;
        consoleCoordinates(x, y);
        cout << "|";
        for (int i = 0; i < length; i++)
        {
            cout << "_";
        }
        cout << "|" << '\n';
    }
}
