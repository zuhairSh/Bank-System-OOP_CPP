#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsUserListScreen:protected clsScreen
{

private:
   static void PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.GetUserName();
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone();
        cout << "| " << setw(20) << left << User.Email();
        cout << "| " << setw(10) << left << User.GetPassword();
        cout << "| " << setw(12) << left << User.GetPermissions();
    }

public:
  

   static void ShowUserList()
    {

        
        vector <clsUser> vUser = clsUser::GetUsersList();
        string Title = "\t  User List Screen";
        string SubTitle ="\t    (" + to_string(vUser.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);
        

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUser.size() == 0)
            cout << "\t\t\t\tNo User Available In the System!";
        else

            for (clsUser User : vUser)
            {

                PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};
