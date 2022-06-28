#include "pch.h"
#include "pm.bll.h"
#include "../pm.tools/md5.h"
#include "../pm.dal/pm.dal.h"
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
                    vector<string> team = pm::dal::getTeamDataById("../pm.data/teams.csv", stoi(row[7]));
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
        vector<vector<string>> temp = pm::dal::pushFrontTitleOfProjectsFile();
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
        pm::dal::addDataInProjectsFile(fileName, temp);
    }

    // Function for edit team name or colaborators
    void editTeamById(string fileName, vector<vector<string>> data, int idOfTeam, int idOfEditData, string newData, string idOfUser)
    {
        vector<vector<string>> temp = pm::dal::pushFrontTitleOfTeamsFile();
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i][0] == to_string(idOfTeam))
            {
                data[i][idOfEditData] = newData;
                data[i][4] = currentDateTime();
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
        pm::dal::addDataInTeamsFile(fileName, temp);
    }
}