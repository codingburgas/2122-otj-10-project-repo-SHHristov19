#include <iostream>
#include "pm.designApp.h"
#include "../pm.dal/pm.dal.h"

int main()
{
    pm::tools::setConsoleSize();
    pm::designApp::menus::menu();
}
