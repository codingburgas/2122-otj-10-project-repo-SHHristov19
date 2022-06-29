#pragma once
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "../pm.types/User.h"

namespace pm::tools
{
    // Function for displaying text in given console coordinates
    void consoleCoordinates(int x, int y);

    // Function for outputing the console in given size
    void setConsoleSize();

    // Function for get time
    std::string currentDateTime();

    // Function for checks if the password contains the followin special characters
    bool checkPasswordForSpecialCharacters(char[], std::size_t);

    // Function for checking if name contain charecters
    bool checkStringForSpecialCharacters(std::string);

    // Function for converting the password from type string to type char and checks with checkPasswordForSpecialCharacters()
    bool checkPassword(std::string);

    // Function for hash password
    std::string hashPassword(std::string password);

    // Function for output border with set length
    void outputBorder(int x, int y, int height, int length);

    // Enter number without printing
    int enterNumberWithoutPrintingOnConsole();

    // Function for choose users in team by id
    std::vector<std::string>  chooseUsersById();
}