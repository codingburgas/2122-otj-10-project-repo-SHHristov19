#include "pch.h"


namespace pm::bll
{
    namespace userManagement
    {
        // Function for edit user data
        void editUserById(string fileName, int idOfUser, int idOfEditData, string newData)
        {
            vector<vector<string>> temp = pm::dal::userManagement::pushFrontTitleOfUsersFile(temp);
            vector<vector<string>> data = pm::dal::userManagement::readDataFromUsersFile(fileName);
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i][0] == to_string(idOfUser))
                {
                    if (idOfEditData == 8)
                    {
                        if (data[i][idOfEditData] == "user")
                        {
                            data[i][idOfEditData] = "admin";
                        }
                        else if (data[i][idOfEditData] == "admin")
                        {
                            data[i][idOfEditData] = "user";
                        }
                    }
                    else
                    {
                        data[i][idOfEditData] = newData;
                    }
                }
            }
            for (auto row : data)
            {
                temp.push_back(row);
            }
            pm::dal::userManagement::addDataInUsersFile(fileName, temp);
        }
    }

    namespace teamsManagement
    {
        // Function for adding id of team that the user contain in team colaborators
        void checkForContainUserInTeam(vector<vector<string>> data, string idOfUser, vector<int>* idOfTeamContainsUser)
        {
            for (auto row : data)
            {
                string line = row[6], idOfContributor;
                for (size_t i = 0; i < line.size(); i++)
                {
                    if (line[i] == ',')
                    {
                        if (idOfContributor == idOfUser)
                        {
                            (*idOfTeamContainsUser).push_back(stoi(row[0]));
                        }
                        idOfContributor = "";
                    }
                    else if (line[i] != ',')
                    {
                        idOfContributor += line[i];
                    }
                    if (i == line.size() - 1)
                    {
                        if (idOfContributor == idOfUser)
                        {
                            (*idOfTeamContainsUser).push_back(stoi(row[0]));
                        }
                    }
                }
            }
        }

        // Function for edit team name or colaborators
        void editTeamById(string fileName, vector<vector<string>> data, int idOfTeam, int idOfEditData, string newData, string idOfUser)
        {
            vector<vector<string>> temp = pm::dal::teamsManagement::pushFrontTitleOfTeamsFile();
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i][0] == to_string(idOfTeam))
                {
                    data[i][idOfEditData] = newData;
                    data[i][4] = pm::tools::currentDateTime();
                    data[i][5] = idOfUser;
                }
            }
            for (auto row : temp)
            {
                for (auto row2 : data)
                {
                    temp.push_back(row2);
                }
            }
            pm::dal::teamsManagement::addDataInTeamsFile(fileName, temp);
        }
    }

    namespace projectManagement
    {
        // Function for adding id of project that the user contain in team colaborators
        void checkProjectForContainUserInTeam(vector<vector<string>> data, string idOfUser, vector<int>* idOfProjectContainsUser)
        {
            for (auto row : data)
            {
                if (row[4] == idOfUser)
                {
                    (*idOfProjectContainsUser).push_back(stoi(row[0]));
                }
                else
                {
                    if (stoi(row[7]) > 0)
                    {
                        vector<string> team = pm::dal::teamsManagement::getTeamDataById("../pm.data/teams.csv", stoi(row[7]));
                        string line = team[6], idOfContributor;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',')
                            {
                                if (idOfContributor == idOfUser)
                                {
                                    (*idOfProjectContainsUser).push_back(stoi(row[0]));
                                }
                                idOfContributor = "";
                            }
                            else if (line[i] != ',')
                            {
                                idOfContributor += line[i];
                            }
                            if (i == line.size() - 1)
                            {
                                if (idOfContributor == idOfUser)
                                {
                                    (*idOfProjectContainsUser).push_back(stoi(row[0]));
                                }
                            }
                        }
                    }
                }
            }
        }

        // Function for get data by id of projects
        vector<vector<string>> getDataById(vector<int> id, vector<vector<string>> data)
        {
            vector<vector<string>> temp;
            int i = 0;
            for (auto row : data)
            {
                if (i < id.size() && row[0] == to_string(id[i]))
                {
                    temp.push_back(row);
                    i++;
                }
            }
            return temp;
        }

        // Function for searching project without team
        void findProjectWithoutTeam(vector<vector<string>> data, string idOfUser, vector<int>* idOfProjectContainsUser)
        {
            for (auto row : data)
            {
                if (row[4] == idOfUser && stoi(row[7]) == 0)
                {
                    (*idOfProjectContainsUser).push_back(stoi(row[0]));
                }
            }
        }

        // Function for add team in project
        void editIdOfTeam(vector<vector<string>> data, vector<vector<string>> allData, int idOfProject, int idOfTeam, string fileName)
        {
            vector<vector<string>> temp = pm::dal::projectManagement::pushFrontTitleOfProjectsFile();
            for (int i = 0; i < allData.size(); i++)
            {
                if (allData[i][0] == to_string(idOfProject))
                {
                    allData[i][7] = to_string(idOfTeam);
                }
            }
            for (auto row1 : temp)
            {
                for (auto row2 : allData)
                {
                    temp.push_back(row2);
                }
            }
            pm::dal::projectManagement::addDataInProjectsFile(fileName, temp);
        }

        // Function for project data
        void editProjectById(string fileName, vector<vector<string>> data, int idOfProject, int idOfEditData, string newData, string idOfUser)
        {
            vector<vector<string>> temp = pm::dal::projectManagement::pushFrontTitleOfProjectsFile();
            for (int i = 0; i < data.size(); i++)
            {
                if (data[i][0] == to_string(idOfProject))
                {
                    data[i][idOfEditData] = newData;
                    data[i][5] = pm::tools::currentDateTime();
                    data[i][6] = idOfUser;
                }
            }
            for (auto row : data)
            {
                temp.push_back(row);
            }
            pm::dal::userManagement::addDataInUsersFile(fileName, temp);
        }
    }

    namespace taskManagement
    {

    }

    namespace workLogManagement
    {

    }
}