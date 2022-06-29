// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <time.h>
#include <string>
#include <vector>

#include "pm.bll.userManagement.h"
#include "pm.bll.teamManagement.h"
#include "pm.bll.projectManagement.h"
#include "pm.bll.taskManagement.h"
#include "pm.bll.workLogManagement.h"

#include "../pm.dal/pm.dal.tools.h"
#include "../pm.dal/pm.dal.login.h"
#include "../pm.dal/pm.dal.userManagement.h"
#include "../pm.dal/pm.dal.teamsManagement.h"
#include "../pm.dal/pm.dal.projectManagement.h"
#include "../pm.dal/pm.dal.taskManagement.h"
#include "../pm.dal/pm.dal.workLogManagement.h"

#include "../pm.tools/pm.tools.h"
#include "../pm.types/structures.h"
using namespace std;

#endif //PCH_H
