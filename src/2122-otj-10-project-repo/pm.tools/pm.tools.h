#pragma once
#include "pch.h"

namespace pm::tools
{
    // Function for displaying text in given console coordinates
    void consoleCoordinates(int x, int y);

    // Function for outputing the console in given size
    void setConsoleSize();

    // Function for output border with set length
    void outputBorder(int x, int y, int height, int length);
}