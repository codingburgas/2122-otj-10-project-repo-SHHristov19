#pragma once
#include "pch.h"


namespace pm::dal
{
    // Function for count size of file
    size_t getSizeOfFile(string);

    // Function for login for the first time like admin
    bool loginAsFirst(string, string);
}