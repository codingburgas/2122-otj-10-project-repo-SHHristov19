#include "pch.h"
#include "pm.tools.h"
#include "../pm.types/User.h"

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

    // Function for choose users in team by id
    vector<string> chooseUsersById()
    { 
        char arr[50];
        vector<int> id;
        vector<string> temp;
        string num;
        int j = 0;
        arr[j] = _getch();
        if (int(arr[j]) == 13)
        {
            exit(0);
        }
        else if (int(arr[j]) == 27)
        {
            exit(0);
        }
        id.push_back(int(arr[j]) - 48);
        while (int(arr[j]) != 13)
        {
            j++;
            arr[j] = _getch();
            if (int(arr[j]) == 32)
            {
                id.push_back(0);
            }
            else if (int(arr[j]) != 13)
            {
                id.push_back(int(arr[j]) - 48);
            }
        }
        for (int i = 0; i < id.size(); i++)
        {
            if (id[i] != 0)
            {
                num += to_string(id[i]);
            }
            else
            {
                temp.push_back(num);
                num = "";
            }
            if (i == id.size() - 1)
            {
                temp.push_back(num);
            }
        }
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        return temp;
    }
}
