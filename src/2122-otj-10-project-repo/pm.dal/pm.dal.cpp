#include "pch.h"
#include "pm.dal.h"
#include "../pm.bll/pm.bll.h"
#include "../pm.consoleApp/pm.designApp.h"

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
    bool loginAsFirst(string username, string password)
    {
        ifstream file("../pm.data/users.csv");
        if (file.is_open() && getSizeOfFile("../pm.data/users.csv") == 77 && username == "admin" && password == "adminpass")
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
        vector<vector<string>> data = readDataFromFile(fileName);
        return stoi(data[data.size() - 1][0]) + 1;
    }

    bool checkForExistedUser(string fileName, string username);

    // Function for add data in file
    int registerUser(string fileName, string firstName, string lastName, string username, string password, string age)
    {
        ofstream file(fileName, ios_base::app);
        string id, timeOfRegistration;
        id = to_string(generateId(fileName));
        timeOfRegistration = pm::bll::currentDateTime();
        if (pm::bll::checkPassword(password) &&
            pm::bll::checkStringForSpecialCharacters(firstName) &&
            pm::bll::checkStringForSpecialCharacters(lastName) &&
            pm::bll::checkStringForSpecialCharacters(username))
        {
            if (checkForExistedUser(fileName, username))
            {
                file << "\"" << id << "\",\"" << firstName << "\",\"" << lastName << "\",\"" << username << "\",\"" << pm::bll::hashPassword(password) << "\",\"" << age << "\",\"" << timeOfRegistration << "\",\"" << 0 << "\",\"" << "user" << "\"\n" ;
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
    vector<vector<string>> readDataFromFile(string fileName)
    {
        vector<vector<string>> data;
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
                    string id, firstName, lastName, username, password, age, timeOfRegistration, lastLogin, role;
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
                            id += line[i];
                        }
                        else if (counter == 1)
                        {
                            firstName += line[i];
                        }
                        else if (counter == 2)
                        {
                            lastName += line[i];
                        }
                        else if (counter == 3)
                        {
                            username += line[i];
                        }
                        else if (counter == 4)
                        {
                            password += line[i];
                        }
                        else if (counter == 5)
                        {
                            age += line[i];
                        }
                        else if (counter == 6)
                        {
                            timeOfRegistration += line[i];
                        }
                        else if (counter == 7)
                        {
                            lastLogin += line[i];
                        }
                        else if (counter == 8)
                        {
                            role += line[i];
                        }
                    }
                     vector<string> temp;
                     temp.push_back(id);
                     temp.push_back(firstName);
                     temp.push_back(lastName);
                     temp.push_back(username);
                     temp.push_back(password);
                     temp.push_back(age);
                     temp.push_back(timeOfRegistration);
                     temp.push_back(lastLogin);
                     temp.push_back(role);
                     data.push_back(temp);
                }
                counter++;
            }
            file.close();
        }
        return data;
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
                    string username, password;
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
                            username += line[i];
                        }
                        else if (counter == 4)
                        {
                            password += line[i];
                        }
                    }
                    userAndPass.push_back(username + " " + password);
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
        vector<vector<string>> data;
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
                    string id, firstName, lastName, username;
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
                            id += line[i];
                            (*identification).push_back(stoi(id));
                        }
                        else if (counter == 1)
                        {
                            firstName += line[i];
                        }
                        else if (counter == 2)
                        {
                            lastName += line[i];
                        }
                        else if (counter == 3)
                        {
                            username += line[i];
                        }
                    }
                    vector<string> temp;
                    temp.push_back(id);
                    temp.push_back(username);
                    temp.push_back(firstName);
                    temp.push_back(lastName);
                    data.push_back(temp);
                }
                counter++;
            }
            file.close();
        }
        return data;
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
                    string id, firstName, lastName, username, password, age, timeOfRegistration, lastLogin, role;
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
                            id += line[i];
                        }
                        else if (counter == 1)
                        {
                            firstName += line[i];
                        }
                        else if (counter == 2)
                        {
                            lastName += line[i];
                        }
                        else if (counter == 3)
                        {
                            username += line[i];
                        }
                        else if (counter == 4)
                        {
                            password += line[i];
                        }
                        else if (counter == 5)
                        {
                            age += line[i];
                        }
                        else if (counter == 6)
                        {
                            timeOfRegistration += line[i];
                        }
                        else if (counter == 7)
                        {
                            lastLogin += line[i];
                        }
                        else if (counter == 8)
                        {
                            role += line[i];
                        }
                    }
                    if (idUser == stoi(id))
                    {
                        data.push_back(id);
                        data.push_back(firstName);
                        data.push_back(lastName);
                        data.push_back(username);
                        data.push_back(password);
                        data.push_back(age);
                        data.push_back(timeOfRegistration);
                        data.push_back(lastLogin);
                        data.push_back(role);
                    }
                }
                counter++;
            }
            file.close();
        }
        return data;
    }

    // Function for replace time of last login
    void replaceLoginTime(vector<vector<string>>* data, string username, string password, string time, string* role)
    {
        for (size_t i = 0; i < (*data).size(); i++)
        {
            if ((*data)[i][3] == username and (*data)[i][4] == pm::bll::hashPassword(password))
            {
                (*data)[i][7].replace(0, (*data)[i][7].size(), time);
                *role = (*data)[i][8];
                return;
            }
        }
    }

    // Function for check if usename and password are in the file
    bool login(string fileName, string username, string password, string* role)
    {
        ifstream file(fileName);
        vector<string> userAndPass = getUsernameAndPassword(fileName);
        vector<vector<string>> data = readDataFromFile(fileName);
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

            if (username == checkUsername && pm::bll::hashPassword(password) == checkPassword)
            {
                replaceLoginTime(&data, username, password, pm::bll::currentDateTime(), role);
                data = pm::dal::pushFrontTitleOfFile(data);
                pm::dal::printDataInFile(fileName, data);
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
    void replaceData(vector<vector<string>>* data, string username, string password, string newPassword)
    {
        for (size_t i = 0; i < (*data).size(); i++)
        {
            if ((*data)[i][3] == username and (*data)[i][4] == pm::bll::hashPassword(password))
            {
                (*data)[i][4].replace(0, (*data)[i][4].size(), pm::bll::hashPassword(newPassword));
                return;
            }
        }
    }

    // Function for add data infront of the matrix vector
    vector<vector<string>> pushFrontTitleOfFile(vector<vector<string>> data)
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
    void printDataInFile(string fileName, vector<vector<string>> data)
    {
        ofstream file(fileName, ios::trunc);
        if (file.is_open())
        {
            for (size_t i = 0; i < data.size(); i++)
            {
                for (size_t j = 0; j < data[i].size(); j++)
                {
                    if (i == 0 && j < data[i].size() - 1)
                    {
                        file << data[i][j] << ",";
                    }
                    else if (i == 0 && j == data[i].size() - 1)
                    {
                        file << data[i][j];
                    }
                    else if (j == data[i].size() - 1)
                    {
                        file << "\"" << data[i][j] << "\"";
                    }
                    else
                    {
                        file << "\"" << data[i][j] << "\",";
                    }
                }
                file << "\n";
            }
        }
        file.close();
    }

    // Function for replacing password in file 
    void cnagePassword(string fileName, string password, string username, string newPassword)
    {
        vector<vector<string>> allDataInFile = readDataFromFile(fileName);
        replaceData(&allDataInFile, password, username, newPassword);
        allDataInFile = pushFrontTitleOfFile(allDataInFile);
        printDataInFile(fileName, allDataInFile);
    }

    // Function for geleting user by id
    void deleteUserById(string fileName, int idOfUser)
    {
        vector<vector<string>> data = pushFrontTitleOfFile(data);
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
                    string id, firstName, lastName, username, password, age, timeOfRegistration, lastLogin, role;
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
                            id += line[i];
                        }
                        else if (counter == 1)
                        {
                            firstName += line[i];
                        }
                        else if (counter == 2)
                        {
                            lastName += line[i];
                        }
                        else if (counter == 3)
                        {
                            username += line[i];
                        }
                        else if (counter == 4)
                        {
                            password += line[i];
                        }
                        else if (counter == 5)
                        {
                            age += line[i];
                        }
                        else if (counter == 6)
                        {
                            timeOfRegistration += line[i];
                        }
                        else if (counter == 7)
                        {
                            lastLogin += line[i];
                        }
                        else if (counter == 8)
                        {
                            role += line[i];
                        }
                    }
                    vector<string> temp;
                    if (stoi(id) != idOfUser)
                    {
                        temp.push_back(id);
                        temp.push_back(firstName);
                        temp.push_back(lastName);
                        temp.push_back(username);
                        temp.push_back(password);
                        temp.push_back(age);
                        temp.push_back(timeOfRegistration);
                        temp.push_back(lastLogin);
                        temp.push_back(role);
                    }
                    data.push_back(temp);
                }
                counter++;
            }
            file.close();
        }
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

    // Function for edit user by id and data
    void editUserById(string fileName, int idOfUser, int idOfEditData, string newData)
    {
        vector<vector<string>> data = pushFrontTitleOfFile(data);
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
                    string id, firstName, lastName, username, password, age, timeOfRegistration, lastLogin, role;
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
                            id += line[i];
                        }
                        else if (counter == 1)
                        {
                            firstName += line[i];
                        }
                        else if (counter == 2)
                        {
                            lastName += line[i];
                        }
                        else if (counter == 3)
                        {
                            username += line[i];
                        }
                        else if (counter == 4)
                        {
                            password += line[i];
                        }
                        else if (counter == 5)
                        {
                            age += line[i];
                        }
                        else if (counter == 6)
                        {
                            timeOfRegistration += line[i];
                        }
                        else if (counter == 7)
                        {
                            lastLogin += line[i];
                        }
                        else if (counter == 8)
                        {
                            role += line[i];
                        }
                    }
                    vector<string> temp;
                    if (idOfEditData > 0 && stoi(id) == idOfUser)
                    {
                        temp.push_back(id);
                        switch (idOfEditData)
                        {
                        case 2:
                        {
                            temp.push_back(newData);
                            temp.push_back(lastName);
                            temp.push_back(username);
                            temp.push_back(password);
                            temp.push_back(age);
                            temp.push_back(timeOfRegistration);
                            temp.push_back(lastLogin);
                            temp.push_back(role);
                            break;
                        }
                        case 3:
                        {
                            temp.push_back(firstName);
                            temp.push_back(newData);
                            temp.push_back(username);
                            temp.push_back(password);
                            temp.push_back(age);
                            temp.push_back(timeOfRegistration);
                            temp.push_back(lastLogin);
                            temp.push_back(role);
                            break;
                        }
                        case 4:
                        {
                            temp.push_back(firstName);
                            temp.push_back(lastName);
                            temp.push_back(newData);
                            temp.push_back(password);
                            temp.push_back(age);
                            temp.push_back(timeOfRegistration);
                            temp.push_back(lastLogin);
                            temp.push_back(role);
                            break;
                        }
                        case 5:
                        {
                            temp.push_back(firstName);
                            temp.push_back(lastName);
                            temp.push_back(username);
                            temp.push_back(pm::bll::hashPassword(newData));
                            temp.push_back(age);
                            temp.push_back(timeOfRegistration);
                            temp.push_back(lastLogin);
                            temp.push_back(role);
                            break;
                        }
                        case 6:
                        {
                            temp.push_back(firstName);
                            temp.push_back(lastName);
                            temp.push_back(username);
                            temp.push_back(password);
                            temp.push_back(newData);
                            temp.push_back(timeOfRegistration);
                            temp.push_back(lastLogin);
                            temp.push_back(role);
                            break;
                        }
                        case 9:
                        {
                            if (role == "user")
                            {
                                temp.push_back(firstName);
                                temp.push_back(lastName);
                                temp.push_back(username);
                                temp.push_back(password);
                                temp.push_back(age);
                                temp.push_back(timeOfRegistration);
                                temp.push_back(lastLogin);
                                temp.push_back("admin");
                            }
                            else
                            {
                                temp.push_back(firstName);
                                temp.push_back(lastName);
                                temp.push_back(username);
                                temp.push_back(password);
                                temp.push_back(age);
                                temp.push_back(timeOfRegistration);
                                temp.push_back(lastLogin);
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
                        temp.push_back(id);
                        temp.push_back(firstName);
                        temp.push_back(lastName);
                        temp.push_back(username);
                        temp.push_back(password);
                        temp.push_back(age);
                        temp.push_back(timeOfRegistration);
                        temp.push_back(lastLogin);
                        temp.push_back(role);
                        data.push_back(temp);
                    }
                }
                counter++;
            }
            file.close();
        }
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
}