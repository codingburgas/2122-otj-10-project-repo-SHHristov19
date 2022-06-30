#include "pch.h"

#include "pm.dal.tools.h"
#include "pm.dal.login.h"
#include "pm.dal.userManagement.h"
#include "pm.dal.teamsManagement.h"
#include "pm.dal.projectManagement.h"
#include "pm.dal.taskManagement.h"
#include "pm.dal.workLogManagement.h"

#include "../pm.tools/pm.tools.h"
#include "../pm.types/structures.h"

namespace pm::dal
{
    namespace tools
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

        // Function for read id from file and add it in vector<string>
        vector<string> readIdOfFile(string fileName)
        {
            vector<string> temp;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::USER data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 8)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                            }
                        }
                        temp.push_back(data.id);
                    }
                    counter++;
                }
                file.close();
            }
            return temp;
        }

        // Function for generate id
        int generateId(string fileName)
        {
            vector<string> data = readIdOfFile(fileName);
            return stoi(data[data.size() - 1]) + 1;
        }
    }

    namespace login
    {
        // Function for login for the first time like admin
        bool loginAsFirst(pm::types::USER user)
        {
            ifstream file("../pm.data/users.csv");
            if (file.is_open() && pm::dal::tools::getSizeOfFile("../pm.data/users.csv") == 82 && user.username == "admin" && user.password == "adminpass")
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

        // Function for check if usename and password are in the file
        bool login(string fileName, pm::types::USER* user, string* idOfUser)
        {
            ifstream file(fileName);
            vector<string> userAndPass = pm::dal::userManagement::getUsernameAndPassword(fileName);
            vector<vector<string>> data = pm::dal::userManagement::readDataFromUsersFile(fileName);
            for (auto check : userAndPass)
            {
                string checkUsername, checkPassword;
                int count = 0;
                for (size_t i = 0; i < check.size(); i++)
                {
                    if (check[i] == ' ')
                    {
                        count++;
                    }
                    else if (count == 0)
                    {
                        checkUsername += check[i];
                    }
                    else if (count == 1)
                    {
                        checkPassword += check[i];
                    }
                }

                if ((*user).username == checkUsername && pm::tools::hashPassword((*user).password) == checkPassword)
                {
                    (*user).lastLogin = pm::tools::currentDateTime();
                    pm::dal::userManagement::replaceLastLoginTime(&data, user);
                    data = pm::dal::userManagement::pushFrontTitleOfUsersFile(data);
                    pm::dal::userManagement::addDataInUsersFile(fileName, data);
                    *idOfUser = pm::dal::userManagement::getIdOfUserByUsername(fileName, *user);
                    file.close();
                    return true;
                }
            }
            file.close();
            return false;
        }

        // Function for replacing password in file 
        void cnagePassword(string fileName, pm::types::USER data, string newPassword)
        {
            vector<vector<string>> allDataInFile = pm::dal::userManagement::readDataFromUsersFile(fileName);
            pm::dal::userManagement::replaceDataInUsersFile(&allDataInFile, data, newPassword);
            allDataInFile = pm::dal::userManagement::pushFrontTitleOfUsersFile(allDataInFile);
            pm::dal::userManagement::addDataInUsersFile(fileName, allDataInFile);
        }
    }

    namespace userManagement
    {
        // Function for add data in file user.csv
        int registerUser(string fileName, pm::types::USER user)
        {
            ofstream file(fileName, ios_base::app);
            user.id = to_string(pm::dal::tools::generateId(fileName));
            user.timeOfRegistration = pm::tools::currentDateTime();
            if (pm::tools::checkPassword(user.password) &&
                pm::tools::checkStringForSpecialCharacters(user.firstName) &&
                pm::tools::checkStringForSpecialCharacters(user.lastName) &&
                pm::tools::checkStringForSpecialCharacters(user.username))
            {
                if (checkForExistedUser(fileName, user.username))
                {
                    file << "\"" << user.id << "\",\"" << user.firstName << "\",\"" << user.lastName << "\",\"" << user.username << "\",\"" << pm::tools::hashPassword(user.password) << "\",\"" << user.age << "\",\"" << user.timeOfRegistration << "\",\"" << 0 << "\",\"" << "user" << "\"\n";
                    file.close();
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
            else
            {
                return 3;
            }
        }

        // Function for read data from file and add it in vector<string>
        vector<vector<string>> readDataFromUsersFile(string fileName)
        {
            vector<vector<string>> allData;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::USER data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 8)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                data.firstName += line[i];
                            }
                            else if (counter == 2)
                            {
                                data.lastName += line[i];
                            }
                            else if (counter == 3)
                            {
                                data.username += line[i];
                            }
                            else if (counter == 4)
                            {
                                data.password += line[i];
                            }
                            else if (counter == 5)
                            {
                                data.age += line[i];
                            }
                            else if (counter == 6)
                            {
                                data.timeOfRegistration += line[i];
                            }
                            else if (counter == 7)
                            {
                                data.lastLogin += line[i];
                            }
                            else if (counter == 8)
                            {
                                data.role += line[i];
                            }
                        }
                        vector<string> temp;
                        temp.push_back(data.id);
                        temp.push_back(data.firstName);
                        temp.push_back(data.lastName);
                        temp.push_back(data.username);
                        temp.push_back(data.password);
                        temp.push_back(data.age);
                        temp.push_back(data.timeOfRegistration);
                        temp.push_back(data.lastLogin);
                        temp.push_back(data.role);
                        allData.push_back(temp);
                    }
                    counter++;
                }
                file.close();
            }
            return allData;
        }

        // Function for get username and password from file
        vector<string> getUsernameAndPassword(string fileName)
        {
            vector<string> userAndPass;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::USER data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 8)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 3)
                            {
                                data.username += line[i];
                            }
                            else if (counter == 4)
                            {
                                data.password += line[i];
                            }
                        }
                        userAndPass.push_back(data.username + " " + data.password);
                    }
                    counter++;
                }
                file.close();
            }
            return userAndPass;
        }

        // Function for read data from file for id, username, firstName and LastName
        vector<vector<string>> readDataForIdUsernameFirstAndLastName(string fileName, vector<int>* identification, string idOfUser)
        {
            vector<vector<string>> allData;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::USER data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 8)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                                (*identification).push_back(stoi(data.id));
                            }
                            else if (counter == 1)
                            {
                                data.firstName += line[i];
                            }
                            else if (counter == 2)
                            {
                                data.lastName += line[i];
                            }
                            else if (counter == 3)
                            {
                                data.username += line[i];
                            }
                        }
                        if (data.id != idOfUser)
                        {
                            vector<string> temp;
                            temp.push_back(data.id);
                            temp.push_back(data.username);
                            temp.push_back(data.firstName);
                            temp.push_back(data.lastName);
                            allData.push_back(temp);
                        }
                    }
                    counter++;
                }
                file.close();
            }
            return allData;
        }

        // Function for getting data by id of user
        vector<string> getUserDataById(string fileName, int idUser)
        {
            vector<string> data;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::USER user;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 8)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                user.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                user.firstName += line[i];
                            }
                            else if (counter == 2)
                            {
                                user.lastName += line[i];
                            }
                            else if (counter == 3)
                            {
                                user.username += line[i];
                            }
                            else if (counter == 4)
                            {
                                user.password += line[i];
                            }
                            else if (counter == 5)
                            {
                                user.age += line[i];
                            }
                            else if (counter == 6)
                            {
                                user.timeOfRegistration += line[i];
                            }
                            else if (counter == 7)
                            {
                                user.lastLogin += line[i];
                            }
                            else if (counter == 8)
                            {
                                user.role += line[i];
                            }
                        }
                        if (idUser == stoi(user.id))
                        {
                            data.push_back(user.id);
                            data.push_back(user.firstName);
                            data.push_back(user.lastName);
                            data.push_back(user.username);
                            data.push_back(user.password);
                            data.push_back(user.age);
                            data.push_back(user.timeOfRegistration);
                            data.push_back(user.lastLogin);
                            data.push_back(user.role);
                        }
                    }
                    counter++;
                }
                file.close();
            }
            return data;
        }

        // Function for replace time of last login
        void replaceLastLoginTime(vector<vector<string>>* data, pm::types::USER* user)
        {
            for (size_t i = 0; i < (*data).size(); i++)
            {
                if ((*data)[i][3] == (*user).username and (*data)[i][4] == pm::tools::hashPassword((*user).password))
                {
                    (*data)[i][7].replace(0, (*data)[i][7].size(), (*user).lastLogin);
                    (*user).role = (*data)[i][8];
                    return;
                }
            }
        }

        // Function for geting id of user by username
        string getIdOfUserByUsername(string fileName, pm::types::USER user)
        {
            vector<vector<string>> data = readDataFromUsersFile(fileName);
            int i = 0;
            while (true)
            {
                if (data[i][3] == user.username)
                {
                    return data[i][0];
                }
                i++;
            }
        }

        // Function for checking already existing username #
        bool checkForExistedUser(string fileName, string username)
        {
            vector<string> userAndPass = pm::dal::userManagement::getUsernameAndPassword(fileName);
            for (auto check : userAndPass)
            {
                string checkUsername;
                int count = 0;
                for (size_t i = 0; i < check.size(); i++)
                {
                    if (check[i] == ' ')
                    {
                        count++;
                    }
                    else if (count == 0)
                    {
                        checkUsername += check[i];
                    }
                }

                if (username == checkUsername)
                {
                    return false;
                }
            }
            return true;
        }

        // Function for checking already existing password #
        bool checkForExistsPassword(string fileName, string password)
        {
            vector<string> checkPassword = getUsernameAndPassword(fileName);
            for (auto check : checkPassword)
            {
                string checkPassword;
                int count = 0;
                for (size_t i = 0; i < check.size(); i++)
                {
                    if (check[i] == ' ')
                    {
                        count++;
                    }
                    else if (count == 1)
                    {
                        checkPassword += check[i];
                    }
                }

                if (pm::tools::hashPassword(password) == checkPassword)
                {
                    return true;
                }
            }
            return false;
        }

        // Function for replace password in vector #
        void replaceDataInUsersFile(vector<vector<string>>* data, pm::types::USER user, string newPassword)
        {
            for (size_t i = 0; i < (*data).size(); i++)
            {
                if ((*data)[i][3] == user.username and (*data)[i][4] == pm::tools::hashPassword(user.password))
                {
                    (*data)[i][4].replace(0, (*data)[i][4].size(), pm::tools::hashPassword(newPassword));
                    return;
                }
            }
        }

        // Function for add data infront of the matrix vector #
        vector<vector<string>> pushFrontTitleOfUsersFile(vector<vector<string>> data)
        {
            vector<vector<string>> output;
            vector<string> temp;
            temp.push_back("Id");
            temp.push_back("First name");
            temp.push_back("Last name");
            temp.push_back("Username");
            temp.push_back("Password");
            temp.push_back("Age");
            temp.push_back("Time of registration");
            temp.push_back("Last Login");
            temp.push_back("Role");
            output.push_back(temp);
            for (size_t i = 0; i < data.size(); i++)
            {
                vector<string> temp2;
                for (size_t j = 0; j < data[i].size(); j++)
                {
                    temp2.push_back(data[i][j]);
                }
                output.push_back(temp2);
            }
            return output;
        }

        // Function for add data in file
        void addDataInUsersFile(string fileName, vector<vector<string>> data)
        {
            ofstream out(fileName, ios_base::trunc);
            if (out.is_open())
            {
                for (int i = 0; i < data.size(); i++)
                {
                    for (int j = 0; j < data[i].size(); j++)
                    {
                        if (j == 8 && i > 0)
                        {
                            out << "\"" << data[i][j] << "\"\n";
                        }
                        else if (j == 8 && i == 0)
                        {
                            out << data[i][j] << "\n";
                        }
                        else if (j != 8 && i == 0)
                        {
                            out << data[i][j] << ",";
                        }
                        else
                        {
                            out << "\"" << data[i][j] << "\",";
                        }
                    }
                }
                out.close();
            }
        }



        // Function for deleting user by id
        void deleteUserByIdInUsersFile(string fileName, int idOfUser)
        {
            vector<vector<string>> data = pushFrontTitleOfUsersFile(data);
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::USER user;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 8)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                user.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                user.firstName += line[i];
                            }
                            else if (counter == 2)
                            {
                                user.lastName += line[i];
                            }
                            else if (counter == 3)
                            {
                                user.username += line[i];
                            }
                            else if (counter == 4)
                            {
                                user.password += line[i];
                            }
                            else if (counter == 5)
                            {
                                user.age += line[i];
                            }
                            else if (counter == 6)
                            {
                                user.timeOfRegistration += line[i];
                            }
                            else if (counter == 7)
                            {
                                user.lastLogin += line[i];
                            }
                            else if (counter == 8)
                            {
                                user.role += line[i];
                            }
                        }
                        vector<string> temp;
                        if (stoi(user.id) != idOfUser)
                        {
                            temp.push_back(user.id);
                            temp.push_back(user.firstName);
                            temp.push_back(user.lastName);
                            temp.push_back(user.username);
                            temp.push_back(user.password);
                            temp.push_back(user.age);
                            temp.push_back(user.timeOfRegistration);
                            temp.push_back(user.lastLogin);
                            temp.push_back(user.role);
                        }
                        data.push_back(temp);
                    }
                    counter++;
                }
                file.close();
            }
            addDataInUsersFile(fileName, data);
        }
    }

    namespace teamsManagement
    {
        // Function for add new team in teams.csv file
        void createTeam(string fileName, pm::types::TEAM team)
        {
            ofstream file(fileName, ios_base::app);
            if (pm::dal::tools::getSizeOfFile(fileName) == 91)
            {
                team.id = "1";
            }
            else
            {
                team.id = to_string(pm::dal::tools::generateId(fileName));
            }
            team.dataOfCreation = pm::tools::currentDateTime();
            team.dataOfLastChanges = pm::tools::currentDateTime();
            file << "\"" << team.id << "\",\"" << team.name << "\",\"" << team.idOfCreator << "\",\"" << team.dataOfCreation << "\",\"" << team.dataOfLastChanges << "\",\"" << team.idOfLastChanger << "\",\"" << team.contributors << "\"\n";
            file.close();
        }

        // Function for read data from teams file and add it in vector
        vector<vector<string>> readDataFromTeamsFile(string fileName, vector<int>* identification)
        {
            vector<vector<string>> allData;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::TEAM data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 6)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                                (*identification).push_back(stoi(data.id));
                            }
                            else if (counter == 1)
                            {
                                data.name += line[i];
                            }
                            else if (counter == 2)
                            {
                                data.idOfCreator += line[i];
                            }
                            else if (counter == 3)
                            {
                                data.dataOfCreation += line[i];
                            }
                            else if (counter == 4)
                            {
                                data.dataOfLastChanges += line[i];
                            }
                            else if (counter == 5)
                            {
                                data.idOfLastChanger += line[i];
                            }
                            else if (counter == 6)
                            {
                                data.contributors += line[i];
                            }
                        }
                        vector<string> temp;
                        temp.push_back(data.id);
                        temp.push_back(data.name);
                        temp.push_back(data.idOfCreator);
                        temp.push_back(data.dataOfCreation);
                        temp.push_back(data.dataOfLastChanges);
                        temp.push_back(data.idOfLastChanger);
                        temp.push_back(data.contributors);
                        allData.push_back(temp);
                    }
                    counter++;
                }
                file.close();
            }
            return allData;
        }

        // Function for getting data by id of team
        vector<string> getTeamDataById(string fileName, int idUser)
        {
            vector<string> data;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::TEAM choise;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 6)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                choise.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                choise.name += line[i];
                            }
                            else if (counter == 2)
                            {
                                choise.idOfCreator += line[i];
                            }
                            else if (counter == 3)
                            {
                                choise.dataOfCreation += line[i];
                            }
                            else if (counter == 4)
                            {
                                choise.dataOfLastChanges += line[i];
                            }
                            else if (counter == 5)
                            {
                                choise.idOfLastChanger += line[i];
                            }
                            else if (counter == 6)
                            {
                                choise.contributors += line[i];
                            }
                        }
                        if (idUser == stoi(choise.id))
                        {
                            data.push_back(choise.id);
                            data.push_back(choise.name);
                            data.push_back(choise.idOfCreator);
                            data.push_back(choise.dataOfCreation);
                            data.push_back(choise.dataOfLastChanges);
                            data.push_back(choise.idOfLastChanger);
                            data.push_back(choise.contributors);
                        }
                    }
                    counter++;
                }
                file.close();
            }
            return data;
        }

        // Function for add data infront of the matrix vector
        vector<vector<string>> pushFrontTitleOfTeamsFile()
        {
            vector<vector<string>> output;
            vector<string> temp;
            temp.push_back("Id");
            temp.push_back("Name");
            temp.push_back("Id of creator");
            temp.push_back("Data of creation");
            temp.push_back("Data of last changes");
            temp.push_back("Id Of last changer");
            temp.push_back("Contributors");
            output.push_back(temp);
            return output;
        }

        // Function for add data in file
        void addDataInTeamsFile(string fileName, vector<vector<string>> data)
        {
            ofstream out(fileName, ios_base::trunc);
            if (out.is_open())
            {
                for (int i = 0; i < data.size(); i++)
                {
                    for (int j = 0; j < data[i].size(); j++)
                    {
                        if (j == 6 && i > 0)
                        {
                            out << "\"" << data[i][j] << "\"\n";
                        }
                        else if (j == 6 && i == 0)
                        {
                            out << data[i][j] << "\n";
                        }
                        else if (j != 6 && i == 0)
                        {
                            out << data[i][j] << ",";
                        }
                        else
                        {
                            out << "\"" << data[i][j] << "\",";
                        }
                    }
                }
                out.close();
            }
        }

        // Function for deleting team by id
        void deleteTeamByIdInTeamsFile(string fileName, int idOfTeam)
        {
            vector<vector<string>> data = pushFrontTitleOfTeamsFile();
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::TEAM choise;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 6)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                choise.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                choise.name += line[i];
                            }
                            else if (counter == 2)
                            {
                                choise.idOfCreator += line[i];
                            }
                            else if (counter == 3)
                            {
                                choise.dataOfCreation += line[i];
                            }
                            else if (counter == 4)
                            {
                                choise.dataOfLastChanges += line[i];
                            }
                            else if (counter == 5)
                            {
                                choise.idOfLastChanger += line[i];
                            }
                            else if (counter == 6)
                            {
                                choise.contributors += line[i];
                            }
                        }
                        vector<string> temp;
                        if (stoi(choise.id) != idOfTeam)
                        {
                            temp.push_back(choise.id);
                            temp.push_back(choise.name);
                            temp.push_back(choise.idOfCreator);
                            temp.push_back(choise.dataOfCreation);
                            temp.push_back(choise.dataOfLastChanges);
                            temp.push_back(choise.idOfLastChanger);
                            temp.push_back(choise.contributors);
                        }
                        data.push_back(temp);
                    }
                    counter++;
                }
                file.close();
            }
            addDataInTeamsFile(fileName, data);
        }
    }
    
    namespace projectManagement
    {
        // Function for add new project in projects.csv file
        void createProject(string fileName, pm::types::PROJECT team)
        {
            ofstream file(fileName, ios_base::app);
            if (pm::dal::tools::getSizeOfFile(fileName) == 118)
            {
                team.id = "1";
            }
            else
            {
                team.id = to_string(pm::dal::tools::generateId(fileName));
            }
            team.dataOfCreation = pm::tools::currentDateTime();
            team.dataOfLastChanges = pm::tools::currentDateTime();
            file << "\"" << team.id << "\",\"" << team.title << "\",\"" << team.description << "\",\"" << team.dataOfCreation << "\",\"" << team.idOfCreator << "\",\"" << team.dataOfLastChanges << "\",\"" << team.idOfLastChanger << "\",\"" << team.idOfTeam << "\",\"" << 0 << "\"\n";
            file.close();
        }

        // Function for read data from project file and add it in vector
        vector<vector<string>> readDataFromProjectsFile(string fileName, vector<int>* identification)
        {
            vector<vector<string>> allData;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::PROJECT data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 8)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                                (*identification).push_back(stoi(data.id));
                            }
                            else if (counter == 1)
                            {
                                data.title += line[i];
                            }
                            else if (counter == 2)
                            {
                                data.description += line[i];
                            }
                            else if (counter == 3)
                            {
                                data.dataOfCreation += line[i];
                            }
                            else if (counter == 4)
                            {
                                data.idOfCreator += line[i];
                            }
                            else if (counter == 5)
                            {
                                data.dataOfLastChanges += line[i];
                            }
                            else if (counter == 6)
                            {
                                data.idOfLastChanger += line[i];
                            }
                            else if (counter == 7)
                            {
                                data.idOfTeam += line[i];
                            }
                            else if (counter == 8)
                            {
                                data.idOfTasks += line[i];
                            }
                        }
                        vector<string> temp;
                        temp.push_back(data.id);
                        temp.push_back(data.title);
                        temp.push_back(data.description);
                        temp.push_back(data.dataOfCreation);
                        temp.push_back(data.idOfCreator);
                        temp.push_back(data.dataOfLastChanges);
                        temp.push_back(data.idOfLastChanger);
                        temp.push_back(data.idOfTeam);
                        temp.push_back(data.idOfTasks);
                        allData.push_back(temp);
                    }
                    counter++;
                }
                file.close();
            }
            return allData;
        }

        // Function for getting data by id of team
        vector<string> getProjetctDataById(string fileName, int idUser)
        {
            vector<string> allData;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::PROJECT data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 8)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                data.title += line[i];
                            }
                            else if (counter == 2)
                            {
                                data.description += line[i];
                            }
                            else if (counter == 3)
                            {
                                data.dataOfCreation += line[i];
                            }
                            else if (counter == 4)
                            {
                                data.idOfCreator += line[i];
                            }
                            else if (counter == 5)
                            {
                                data.dataOfLastChanges += line[i];
                            }
                            else if (counter == 6)
                            {
                                data.idOfLastChanger += line[i];
                            }
                            else if (counter == 7)
                            {
                                data.idOfTeam += line[i];
                            }
                            else if (counter == 8)
                            {
                                data.idOfTasks += line[i];
                            }
                        }
                        if (stoi(data.id) == idUser)
                        {
                            allData.push_back(data.id);
                            allData.push_back(data.title);
                            allData.push_back(data.description);
                            allData.push_back(data.dataOfCreation);
                            allData.push_back(data.idOfCreator);
                            allData.push_back(data.dataOfLastChanges);
                            allData.push_back(data.idOfLastChanger);
                            allData.push_back(data.idOfTeam);
                            allData.push_back(data.idOfTasks);
                        }
                    }
                    counter++;
                }
                file.close();
            }
            return allData;
        }

        // Function for add data infront of the matrix vector
        vector<vector<string>> pushFrontTitleOfProjectsFile()
        {
            vector<vector<string>> output;
            vector<string> temp;
            temp.push_back("Id");
            temp.push_back("Title");
            temp.push_back("Description");
            temp.push_back("Date of creation");
            temp.push_back("Id of the creator");
            temp.push_back("Date of last changes");
            temp.push_back("Id of last changer");
            temp.push_back("Id of team");
            temp.push_back("Id of tasks");
            output.push_back(temp);
            return output;
        }

        // Function for add data in project file
        void addDataInProjectsFile(string fileName, vector<vector<string>> data)
        {
            ofstream out(fileName, ios_base::trunc);
            if (out.is_open())
            {
                for (int i = 0; i < data.size(); i++)
                {
                    for (int j = 0; j < data[i].size(); j++)
                    {
                        if (j == 8 && i > 0)
                        {
                            out << "\"" << data[i][j] << "\"\n";
                        }
                        else if (j == 8 && i == 0)
                        {
                            out << data[i][j] << "\n";
                        }
                        else if (j != 8 && i == 0)
                        {
                            out << data[i][j] << ",";
                        }
                        else
                        {
                            out << "\"" << data[i][j] << "\",";
                        }
                    }
                }
                out.close();
            }
        }

        // Function for deleting project by id
        void deleteProjectByIdInProjectsFile(string fileName, int idOfProject, string idOfUser)
        {
            vector<vector<string>> allData = pushFrontTitleOfProjectsFile();
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::PROJECT data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 8)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                data.title += line[i];
                            }
                            else if (counter == 2)
                            {
                                data.description += line[i];
                            }
                            else if (counter == 3)
                            {
                                data.dataOfCreation += line[i];
                            }
                            else if (counter == 4)
                            {
                                data.idOfCreator += line[i];
                            }
                            else if (counter == 5)
                            {
                                data.dataOfLastChanges += line[i];
                            }
                            else if (counter == 6)
                            {
                                data.idOfLastChanger += line[i];
                            }
                            else if (counter == 7)
                            {
                                data.idOfTeam += line[i];
                            }
                            else if (counter == 8)
                            {
                                data.idOfTasks += line[i];
                            }
                        }
                        vector<string> temp;
                        if (stoi(data.id) != idOfProject || data.idOfCreator != idOfUser)
                        {
                            temp.push_back(data.id);
                            temp.push_back(data.title);
                            temp.push_back(data.description);
                            temp.push_back(data.dataOfCreation);
                            temp.push_back(data.idOfCreator);
                            temp.push_back(data.dataOfLastChanges);
                            temp.push_back(data.idOfLastChanger);
                            temp.push_back(data.idOfTeam);
                            temp.push_back(data.idOfTasks);
                        }
                        allData.push_back(temp);
                    }
                    counter++;
                }
                file.close();
            }
            addDataInProjectsFile(fileName, allData);
        }
    }

    namespace taskManagement
    {
        // Function for add new task
        void createTask(string fileName, pm::types::TASK team, string *idOfTask)
        {
            if (pm::dal::tools::getSizeOfFile(fileName) == 142)
            {
                team.id = *idOfTask = "1";
            }
            else
            {
                team.id = *idOfTask = to_string(pm::dal::tools::generateId(fileName));
            }
            team.dataOfCreation = pm::tools::currentDateTime();
            team.dataOfLastChanges = pm::tools::currentDateTime();
            ofstream file(fileName, ios_base::app);
            file << "\"" << team.id << "\",\"" << team.idOfProject << "\",\"" << team.idOfAssignee << "\",\"" << team.title << "\",\"" << team.description << "\",\"" << "pending" << "\",\"" << team.dataOfCreation << "\",\"" << team.idOfCreator << "\",\"" << team.dataOfLastChanges << "\",\"" << team.idOfLastChanger << "\"\n";
            file.close();
        }

        // Function for read data from task file and add it in vector
        vector<vector<string>> readDataFromTaskFile(string fileName, string idOfProject, string idOfUser, vector<int>* identification)
        {
            vector<vector<string>> allData;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::TASK data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 10)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                data.idOfProject += line[i];
                            }
                            else if (counter == 2)
                            {
                                data.idOfAssignee += line[i];
                            }
                            else if (counter == 3)
                            {
                                data.title += line[i];
                            }
                            else if (counter == 4)
                            {
                                data.description += line[i];
                            }
                            else if (counter == 5)
                            {
                                data.status += line[i];
                            }
                            else if (counter == 6)
                            {
                                data.dataOfCreation += line[i];
                            }
                            else if (counter == 7)
                            {
                                data.idOfCreator += line[i];
                            }
                            else if (counter == 8)
                            {
                                data.dataOfLastChanges += line[i];
                            }
                            else if (counter == 9)
                            {
                                data.idOfLastChanger += line[i];
                            }
                        }
                        vector<string> temp;
                        if (data.idOfProject == idOfProject && (data.idOfCreator == idOfUser || data.idOfAssignee == idOfUser))
                        {
                            temp.push_back(data.id);
                            (*identification).push_back(stoi(data.id));
                            temp.push_back(data.idOfProject);
                            temp.push_back(data.idOfAssignee);
                            temp.push_back(data.title);
                            temp.push_back(data.description);
                            temp.push_back(data.status);
                            temp.push_back(data.dataOfCreation);
                            temp.push_back(data.idOfCreator);
                            temp.push_back(data.dataOfLastChanges);
                            temp.push_back(data.idOfLastChanger);
                            allData.push_back(temp);
                        }
                    }
                    counter++;
                }
                file.close();
            }
            return allData;
        }

        // Function for getting data by id of task
        vector<string> getTaskDataById(string fileName, int idOfTask)
        {
            vector<string> allData;
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::TASK data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 10)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                data.idOfProject += line[i];
                            }
                            else if (counter == 2)
                            {
                                data.idOfAssignee += line[i];
                            }
                            else if (counter == 3)
                            {
                                data.title += line[i];
                            }
                            else if (counter == 4)
                            {
                                data.description += line[i];
                            }
                            else if (counter == 5)
                            {
                                data.status += line[i];
                            }
                            else if (counter == 6)
                            {
                                data.dataOfCreation += line[i];
                            }
                            else if (counter == 7)
                            {
                                data.idOfCreator += line[i];
                            }
                            else if (counter == 8)
                            {
                                data.dataOfLastChanges += line[i];
                            }
                            else if (counter == 9)
                            {
                                data.idOfLastChanger += line[i];
                            }
                        }
                        if (stoi(data.id) == idOfTask)
                        {
                            allData.push_back(data.id);
                            allData.push_back(data.idOfProject);
                            allData.push_back(data.idOfAssignee);
                            allData.push_back(data.title);
                            allData.push_back(data.description);
                            allData.push_back(data.status);
                            allData.push_back(data.dataOfCreation);
                            allData.push_back(data.idOfCreator);
                            allData.push_back(data.dataOfLastChanges);
                            allData.push_back(data.idOfLastChanger);
                        }
                    }
                    counter++;
                }
                file.close();
            }
            return allData;
        }

        // Function for add titles of the file infront of the matrix vector
        vector<vector<string>> pushFrontTitleOfTaskFile()
        {
            vector<vector<string>> output;
            vector<string> temp;
            temp.push_back("Id");
            temp.push_back("Id of the Project");
            temp.push_back("Id of the Assignee");
            temp.push_back("Title");
            temp.push_back("Description");
            temp.push_back("Status");
            temp.push_back("Date of creation");
            temp.push_back("Id of the creator");
            temp.push_back("Date of last changes");
            temp.push_back("Id of last changer");
            output.push_back(temp);
            return output;
        }

        // Function for add data in project file
        void addDataInTaskFile(string fileName, vector<vector<string>> data)
        {
            ofstream out(fileName, ios_base::trunc);
            if (out.is_open())
            {
                for (int i = 0; i < data.size(); i++)
                {
                    for (int j = 0; j < data[i].size(); j++)
                    {
                        if (j == 9 && i > 0)
                        {
                            out << "\"" << data[i][j] << "\"\n";
                        }
                        else if (j == 9 && i == 0)
                        {
                            out << data[i][j] << "\n";
                        }
                        else if (j != 9 && i == 0)
                        {
                            out << data[i][j] << ",";
                        }
                        else
                        {
                            out << "\"" << data[i][j] << "\",";
                        }
                    }
                }
                out.close();
            }
        }

        // Function for deleting project by id
        void deleteTaskByIdInTaskFile(string fileName, int idOfTask, string idOfUser)
        {
            vector<vector<string>> allData = pushFrontTitleOfTaskFile();
            ifstream file(fileName);
            string line;
            int counter = -1;
            if (file.is_open())
            {
                while (getline(file, line))
                {
                    if (counter > -1)
                    {
                        counter = 0;
                        pm::types::TASK data;
                        for (size_t i = 0; i < line.size(); i++)
                        {
                            if (line[i] == ',' && counter < 10)
                            {
                                counter++;
                                line.erase(i, 0);
                            }
                            else if (line[i] == '"')
                            {
                                line.erase(i, 0);
                            }
                            else if (counter == 0)
                            {
                                data.id += line[i];
                            }
                            else if (counter == 1)
                            {
                                data.idOfProject += line[i];
                            }
                            else if (counter == 2)
                            {
                                data.idOfAssignee += line[i];
                            }
                            else if (counter == 3)
                            {
                                data.title += line[i];
                            }
                            else if (counter == 4)
                            {
                                data.description += line[i];
                            }
                            else if (counter == 5)
                            {
                                data.status += line[i];
                            }
                            else if (counter == 6)
                            {
                                data.dataOfCreation += line[i];
                            }
                            else if (counter == 7)
                            {
                                data.idOfCreator += line[i];
                            }
                            else if (counter == 8)
                            {
                                data.dataOfLastChanges += line[i];
                            }
                            else if (counter == 9)
                            {
                                data.idOfLastChanger += line[i];
                            }
                        }
                        vector<string> temp;
                        if (!(stoi(data.id) == idOfTask && (data.idOfCreator == idOfUser || data.idOfAssignee == idOfUser)))
                        {
                            temp.push_back(data.id);
                            temp.push_back(data.idOfProject);
                            temp.push_back(data.idOfAssignee);
                            temp.push_back(data.title);
                            temp.push_back(data.description);
                            temp.push_back(data.status);
                            temp.push_back(data.dataOfCreation);
                            temp.push_back(data.idOfCreator);
                            temp.push_back(data.dataOfLastChanges);
                            temp.push_back(data.idOfLastChanger);
                        }
                        allData.push_back(temp);
                    }
                    counter++;
                }
                file.close();
            }
            addDataInTaskFile(fileName, allData);
        }
    }
    
    namespace workLogManagement
    {

    }
}