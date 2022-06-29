#pragma once
#include "pch.h"

namespace pm::dal::tools
{
    // Function for count size of file
    std::size_t getSizeOfFile(std::string fileName);

    // Function for read id from file and add it in vector<string>
    std::vector<std::string> readIdOfFile(std::string fileName);

    // Function for generate id
    int generateId(std::string fileName);
}