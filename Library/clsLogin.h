#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private :

  static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        short Counter = 0;
        
        do
        {
     
            if (LoginFaild)
            {
                Counter++;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "You have " << 3 - Counter << " out of 3 transformers\n";
                
            }

            if (Counter == 3)
            {
                cout << "The number of login attempts has expired." << endl;
                return false;
            }
            

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild && Counter <= 3);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;

    }

public:


    static bool ShowLoginScreen()
    {
        
        system("clear");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();

    }

};
