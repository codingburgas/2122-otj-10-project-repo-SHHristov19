#include "pch.h"
#include "pm.dal.h"
#include "../pm.bll/pm.bll.h"
#include "../pm.types/User.h"

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
    bool loginAsFirst(pm::types::USER user)
    {
        ifstream file("../pm.data/users.csv");
        if (file.is_open() && getSizeOfFile("../pm.data/users.csv") == 82 && user.username == "admin" && user.password == "adminpass")
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

    // Function for generate id
    int generateId(string fileName)
    {
        vector<vector<string>> data = readDataFromUsersFile(fileName);
        return stoi(data[data.size() - 1][0]) + 1;
    }

    bool checkForExistedUser(string, string); // Function Prototype

    // Function for add data in file user.csv
    int registerUser(string fileName, pm::types::USER user)
    {
        ofstream file(fileName, ios_base::app);
        user.id = to_string(generateId(fileName));
        user.timeOfRegistration = pm::bll::currentDateTime();
        if (pm::bll::checkPassword(user.password) &&
            pm::bll::checkStringForSpecialCharacters(user.firstName) &&
            pm::bll::checkStringForSpecialCharacters(user.lastName) &&
            pm::bll::checkStringForSpecialCharacters(user.username))
        {
            if (checkForExistedUser(fileName, user.username))
            {
                file << "\"" << user.id << "\",\"" << user.firstName << "\",\"" << user.lastName << "\",\"" << user.username << "\",\"" << pm::bll::hashPassword(user.password) << "\",\"" << user.age << "\",\"" << user.timeOfRegistration << "\",\"" << 0 << "\",\"" << "user" << "\"\n" ;
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
    vector<vector<string>> readDataForIdUsernameFirstAndLastName(string fileName, vector<int> *identification)
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
                    vector<string> temp;
                    temp.push_back(data.id);
                    temp.push_back(data.username);
                    temp.push_back(data.firstName);
                    temp.push_back(data.lastName);
                    allData.push_back(temp);
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
            if ((*data)[i][3] == (*user).username and (*data)[i][4] == pm::bll::hashPassword((*user).password))
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
        while(true)
        {
            if (data[i][3] == user.username)
            {
                return data[i][0];
            }
            i++;
        }
    }

    // Function for check if usename and password are in the file
    bool login(string fileName, pm::types::USER *user, string* idOfUser)
    {
        ifstream file(fileName);
        vector<string> userAndPass = getUsernameAndPassword(fileName);
        vector<vector<string>> data = readDataFromUsersFile(fileName);
        *idOfUser = getIdOfUserByUsername(fileName, *user);
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

            if ((*user).username == checkUsername && pm::bll::hashPassword((*user).password) == checkPassword)
            {
                (*user).lastLogin = pm::bll::currentDateTime();
                replaceLastLoginTime(&data, user);
                data = pm::dal::pushFrontTitleOfUsersFile(data);
                pm::dal::addDataInUsersFile(fileName, data);
                file.close();
                return true;
            }
        }
        file.close();
        return false;
    }

    // Function for checking already existing username
    bool checkForExistedUser(string fileName, string username)
    {
        vector<string> userAndPass = pm::dal::getUsernameAndPassword(fileName);
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

    // Function for checking already existing password
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

            if (pm::bll::hashPassword(password) == checkPassword)
            {
                return true;
            }
        }
        return false;
    }

    // Function for replace password in vector
    void replaceDataInUsersFile(vector<vector<string>>* data, pm::types::USER user, string newPassword)
    {
        for (size_t i = 0; i < (*data).size(); i++)
        {
            if ((*data)[i][3] == user.username and (*data)[i][4] == pm::bll::hashPassword(user.password))
            {
                (*data)[i][4].replace(0, (*data)[i][4].size(), pm::bll::hashPassword(newPassword));
                return;
            }
        }
    }

    // Function for add data infront of the matrix vector
    vector<vector<string>> pushFrontTitleOfUsersFile(vector<vector<string>> data)
    {
        vector<vector<string>> output;
        vector<string> temp;
        temp.push_back("id");
        temp.push_back("firstName");
        temp.push_back("lastName");
        temp.push_back("username");
        temp.push_back("password");
        temp.push_back("age");
        temp.push_back("timeOfRegistration");
        temp.push_back("lastLogin");
        temp.push_back("role");
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

    // Function for replacing password in file 
    void cnagePassword(string fileName, pm::types::USER data, string newPassword)
    {
        vector<vector<string>> allDataInFile = readDataFromUsersFile(fileName);
        replaceDataInUsersFile(&allDataInFile, data, newPassword);
        allDataInFile = pushFrontTitleOfUsersFile(allDataInFile);
        addDataInUsersFile(fileName, allDataInFile);
    }

    // Function for geleting user by id
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

    // Function for edit user by id and data
    void editUserById(string fileName, int idOfUser, int idOfEditData, string newData)
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
                    if (idOfEditData > 0 && stoi(user.id) == idOfUser)
                    {
                        temp.push_back(user.id);
                        switch (idOfEditData)
                        {
                        case 2:
                        {
                            temp.push_back(newData);
                            temp.push_back(user.lastName);
                            temp.push_back(user.username);
                            temp.push_back(user.password);
                            temp.push_back(user.age);
                            temp.push_back(user.timeOfRegistration);
                            temp.push_back(user.lastLogin);
                            temp.push_back(user.role);
                            break;
                        }
                        case 3:
                        {
                            temp.push_back(user.firstName);
                            temp.push_back(newData);
                            temp.push_back(user.username);
                            temp.push_back(user.password);
                            temp.push_back(user.age);
                            temp.push_back(user.timeOfRegistration);
                            temp.push_back(user.lastLogin);
                            temp.push_back(user.role);
                            break;
                        }
                        case 4:
                        {
                            temp.push_back(user.firstName);
                            temp.push_back(user.lastName);
                            temp.push_back(newData);
                            temp.push_back(user.password);
                            temp.push_back(user.age);
                            temp.push_back(user.timeOfRegistration);
                            temp.push_back(user.lastLogin);
                            temp.push_back(user.role);
                            break;
                        }
                        case 5:
                        {
                            temp.push_back(user.firstName);
                            temp.push_back(user.lastName);
                            temp.push_back(user.username);
                            temp.push_back(pm::bll::hashPassword(newData));
                            temp.push_back(user.age);
                            temp.push_back(user.timeOfRegistration);
                            temp.push_back(user.lastLogin);
                            temp.push_back(user.role);
                            break;
                        }
                        case 6:
                        {
                            temp.push_back(user.firstName);
                            temp.push_back(user.lastName);
                            temp.push_back(user.username);
                            temp.push_back(user.password);
                            temp.push_back(newData);
                            temp.push_back(user.timeOfRegistration);
                            temp.push_back(user.lastLogin);
                            temp.push_back(user.role);
                            break;
                        }
                        case 9:
                        {
                            if (user.role == "user")
                            {
                                temp.push_back(user.firstName);
                                temp.push_back(user.lastName);
                                temp.push_back(user.username);
                                temp.push_back(user.password);
                                temp.push_back(user.age);
                                temp.push_back(user.timeOfRegistration);
                                temp.push_back(user.lastLogin);
                                temp.push_back("admin");
                            }
                            else
                            {
                                temp.push_back(user.firstName);
                                temp.push_back(user.lastName);
                                temp.push_back(user.username);
                                temp.push_back(user.password);
                                temp.push_back(user.age);
                                temp.push_back(user.timeOfRegistration);
                                temp.push_back(user.lastLogin);
                                temp.push_back("user");
                            }
                            break;
                        }
                        }
                        data.push_back(temp);
                        idOfEditData = 0;
                    }
                    else
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
                        data.push_back(temp);
                    }
                }
                counter++;
            }
            file.close();
        }
        addDataInUsersFile(fileName, data);
    }

    // Function for add new team in teams.csv file
    void createTeam(string fileName, pm::types::TEAM team)
    {
        ofstream file(fileName, ios_base::app);
        if (getSizeOfFile(fileName) == 91)
        {
            team.id = "1";
        }
        else
        {
            team.id = to_string(generateId(fileName));
        }
        team.dataOfCreation = pm::bll::currentDateTime();
        team.dataOfLastChanges = pm::bll::currentDateTime();
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
}