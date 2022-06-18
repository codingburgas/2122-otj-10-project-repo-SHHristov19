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

    // Enter number without printing
    int enterNumberWithoutPrintingOnConsole()
    {
        int j = 0;
        char arr[4];
        arr[j] = _getch();
        if (int(arr[j]) == 13)
        {
            return 0;
        }
        if (int(arr[j]) == 27)
        {
            return 0;
        }
        while (int(arr[j]) != 13)
        {
            j++;
            arr[j] = _getch();
        }
        if (j == 3)
        {
            return (int(arr[0]) - 48) * 100 + (int(arr[1]) - 48) * 10 + (int(arr[2]) - 48);
        }
        else if (j == 2)
        {

            return (int(arr[0]) - 48) * 10 + (int(arr[1]) - 48);
        }
        else
        {
            return int(arr[0]) - 48;
        }
    }
}
