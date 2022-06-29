#pragma once
#include "pch.h"

namespace pm::dal::tools
{
    // Function for count size of file
    std::size_t getSizeOfFile(std::string fileName);

    // Function for generate id
    int generateId(std::string fileName);
}