#pragma once
#include "pch.h"
#include "../pm.types/User.h"
#include <vector>

namespace pm::dal
{
    // Function for count size of file
    std::size_t getSizeOfFile(std::string fileName);

    // Function for login for the first time like admin
    bool loginAsFirst(pm::types::USER user);

    // Function for generate id
    int generateId(std::string fileName);

    // Function for add data in file
    int registerUser(string fileName, pm::types::USER user);

    // Function for read data from file and add it in vector<string>
    std::vector<std::vector<std::string>>  readDataFromUsersFile(std::string fileName);

    // Function for get username and password from file
    std::vector<std::string> getUsernameAndPassword(std::string fileName);

    // Function for read data from file for id, username, firstName and LastName
    std::vector<std::vector<std::string>> readDataForIdUsernameFirstAndLastName(std::string fileName, std::vector<int>* identification);

    // Function for getting data by id of user
    std::vector<std::string> getUserDataById(std::string fileName, int idUser);

    // Function for replace time of last login
    void replaceLastLoginTime(std::vector<std::vector<std::string>> *data, pm::types::USER* user);

    // Function for geting id of user by username
    std::string getIdOfUserByUsername(std::string fileName, pm::types::USER user);

    // Function for check if usename and password are in the file
    bool login(std::string fileName, pm::types::USER* user, std::string* idOfUser);

    // Function for checking already existing username
    bool checkForExistedUser(std::string fileName, std::string username);

    // Function for checking already existing password
    bool checkForExistsPassword(std::string fileName, std::string password);

    // Function for replace password in vector
    void replaceDataInUsersFile(std::vector<std::vector<std::string>>* data, pm::types::USER user, std::string newPassword);

    // Function for add data infront of the matrix vector
    std::vector<std::vector<std::string>> pushFrontTitleOfUsersFile(std::vector<std::vector<std::string>> data);

    // Function for add data in file
    void addDataInUsersFile(std::string fileName, std::vector<std::vector<std::string>> data);

    // Function for replacing password in file 
    void cnagePassword(std::string fileName, pm::types::USER data, std::string newPassword);

    // Function for geleting user by id
    void deleteUserByIdInUsersFile(std::string fileName, int id);

    // Function for edit user by id and data
    void editUserById(std::string fileName, int idOfUser, int idOfEditData, std::string newData);

    // Function for add new team in teams.csv file
    void createTeam(std::string fileName, pm::types::TEAM team);

    // Function for read data from teams file and add it in vector
    vector<vector<string>> readDataFromTeamsFile(string fileName, vector<int>* identification);

    // Function for getting data by id of team
    vector<string> getTeamDataById(string fileName, int idUser);

    // Function for add data infront of the matrix vector
    vector<vector<string>> pushFrontTitleOfTeamsFile(vector<vector<string>> data);

    // Function for add data in file
    void addDataInTeamsFile(string fileName, vector<vector<string>> data);

    // Function for deleting team by id
    void deleteTeamByIdInTeamsFile(string fileName, int idOfUser);

    // Function for edit data in teams file
    void editTeamById(string fileName, int idOfTeam, int idOfEditData, string newData, string idOfUser);
}