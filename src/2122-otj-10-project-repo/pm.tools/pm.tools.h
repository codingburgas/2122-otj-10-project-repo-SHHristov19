#pragma once
#include "pch.h"
#include "../pm.types/User.h"
namespace pm::tools
{
    // Function for displaying text in given console coordinates
    void consoleCoordinates(int x, int y);

    // Function for outputing the console in given size
    void setConsoleSize();

    // Function for output border with set length
    void outputBorder(int x, int y, int height, int length);

    // Enter number without printing
    int enterNumberWithoutPrintingOnConsole();

    // Function for choose users in team by id
    vector<string>  chooseUsersById();
}