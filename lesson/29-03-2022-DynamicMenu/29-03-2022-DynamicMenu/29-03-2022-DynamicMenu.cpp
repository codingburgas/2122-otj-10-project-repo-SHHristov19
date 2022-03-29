#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef void(*MenuHandler)(void*);

struct MenuItem {
    char key;
    string text;
    MenuHandler handler;
};
void menuOption1(void* parms)
{
    cout << "MenuOption1 handler\n";
}

void menuOption2(void* parms)
{
    cout << "MenuOption2 handler\n";
}
void menuOption3(void* parms)
{
    cout << "MenuOption3 handler\n";
}

void displayMenu(std::vector<MenuItem>& menuItem)
{
    for (auto items : menuItem)
    {
        cout << items.key << ". " << items.text << endl;
    }

    cout << "Choose an option : ";
}

int handlerMenu(char& choice, std::vector<MenuItem>& menuItem)
{
    while (true)
    {
        cin >> choice;

        auto it = find_if(menuItem.begin(), menuItem.end(), [&choice](const MenuItem& item) {return item.key == choice; });

        if (it != menuItem.end())
        {
            auto handler = (*it).handler;
            if (handler != NULL)
            {
                handler(NULL);
            }
            else
            {
                return 0;
            }
        }
        else
        {
            cout << "Invalid option\n";
        }
    }
}

int main()
{
    vector<MenuItem> menuItem =
    {  
        { '1', "Start", menuOption1},
        { '2', "Help", menuOption2},
        { '3', "Exit", NULL}
    };
    displayMenu(menuItem);

    char choice;
    
    return handlerMenu(choice, menuItem);
    
}
