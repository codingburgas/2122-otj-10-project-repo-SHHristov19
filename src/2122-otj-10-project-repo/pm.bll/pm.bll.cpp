#include "pch.h"
#include "pm.bll.h"
#include "../pm.tools/md5.h"
using namespace std;

namespace pm::bll
{
    // Function for get time
    string currentDateTime()
    {
        time_t now = time(0);
        char buffer[80];
        tm newtime;
        strftime(buffer, sizeof(buffer), "%Y-%m-%d  %X", localtime(&now));
        return buffer;
    }

    // Function for checks if the password contains the followin special characters
    bool checkPasswordForSpecialCharacters(char password[], size_t n)
    {
        bool isUpper = false, isLower = false, isDigit = false, isCharecter = false;
        char character[] = "!@#$%^&*()_+-=,.<>?/|:; \'\"";
        for (size_t i = 0; i < n; i++)
        {
            if (isupper(password[i]))
            {
                isUpper = true;
            }
            else if (islower(password[i]))
            {
                isLower = true;
            }
            else if (isdigit(password[i]))
            {
                isDigit = true;
            }
            else
            {
                for (size_t i = 0; i < n; i++)
                {
                    for (size_t j = 0; j < 26; j++)
                    {
                        if (character[j] == password[i])
                        {
                            isCharecter = true;
                        }
                    }
                }
            }
        }
        return (isUpper && isLower && isDigit && n >= 8 && n <= 20 && isCharecter);
    }

    // Function for checking if name contain charecters
    bool checkStringForSpecialCharacters(string name)
    {
        char character[] = "!@#$%^&*()_+-=,.<>?/|:;\" \'";
        unsigned short int count = 0;
        for (int i = 0; i < 26; i++)
        {
            if (!(name.find(character[i]) != string::npos))
            {
                count++;
            }
        }
        return count == 26;
    }

    // Function for converting the password from type string to type char and checks with checkPasswordForSpecialCharacters()
    bool checkPassword(string password)
    {
        char charecter[20];
        for (int i = 0; i < password.size(); i++)
        {
            charecter[i] = password.at(i);
        }
        return checkPasswordForSpecialCharacters(charecter, password.size());
    }

    // Function for hash password
    string hashPassword(string password)
    {
        return md5(password);
    }
}