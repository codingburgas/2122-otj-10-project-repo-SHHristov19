#include <iostream>
#include "pm.menus.h"
#include "../pm.dal/pm.dal.h"
#include "../pm.tools/pm.tools.h"
#include "../pm.consoleApp/pm.teamsManagement.h"

int main()
{
    pm::tools::setConsoleSize();
    pm::consoleApp::menus::menu();
}
