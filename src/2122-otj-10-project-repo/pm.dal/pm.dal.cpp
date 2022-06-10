#include "pch.h"
#include "pm.dal.h"

namespace pm::dal
{
    // Function for count size of file
    size_t getSizeOfFile(string fileName)
    {
        ifstream file(fileName);
        string line;
        size_t counter = 0;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                counter += line.size();
            }
            file.close();
        }
        return counter;
    }

    // Function for login for the first time like admin
    bool loginAsFirst(string username, string password)
    {
        ifstream file("../pm.data/users.csv");
        if (file.is_open() && getSizeOfFile("../pm.data/users.csv") == 0 && username == "admin" && password == "adminpass")
        {
            file.close();
            return true;
        }
        else
        {
            file.close();
            return false;
        }
    } 
}