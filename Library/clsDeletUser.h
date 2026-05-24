#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidation.h"
#include <iomanip>

class clsDeleteUser : protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName();
        cout << "\nLastName    : " << User.LastName();
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email();
        cout << "\nPhone       : " << User.Phone();
        cout << "\nUser Name   : " << User.GetUserName();
        cout << "\nPassword    : " << User.GetPassword();
        cout << "\nPermissions : " << User.GetPermissions();
        cout << "\n___________________\n";

    }
public:

    static void DeleteUser()
    {

        _DrawScreenHeader("\t Delete User Screen");

        string UserName = "";
        
        UserName = clsInputValidation::ReadString("Enter User Name for User : ");

        while (!clsUser::IsUserExist(UserName))
        {
            UserName = clsInputValidation::ReadString("User Name Is Not Fount !!, Enter User Name for User : ");

        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);



        cout << "\nAre you sure you want to delete this User y/n? ";
        
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            User1.Delete();
            cout << "\nUser Deleted Successfully! :)\n";
        }
        else
        {
            cout << "\nUser Was not Deleted\n";
        }
    


    }



};
