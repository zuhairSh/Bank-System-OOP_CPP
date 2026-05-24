#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsListUser.h"
#include "clsAddNewUser.h"
#include "clsDeletUser.h"
#include "clsUpdateUser.h"
#include "clsFindUser.h"
#include "Global.h"
#include <iomanip>
#include <limits>


using namespace std;

class clsManageUsersScreen:protected clsScreen
{


    private:
        enum enMainManageUsersptions 
        {
        eListUser = 1, eAddNewUser = 2,
        eDeleteUser = 3, eUpdateUser = 4,
        eFindUser = 5 ,eBackMainMenue = 6
        };

       static short _ReadMenueManageUsersOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 6]? ";
            short Choice = clsInputValidation::ReadIntNumberBetween(1,6,"Error!, Please Enter Number Between 1 / 6 : ");
            return Choice;
        }

        static void _GoBackToManageUsersMenue()
        {
            cout << "\n\tPress any key then Enter to go back to Main Menu...\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تنظيف الإدخال
            cin.get(); // انتظار أي إدخال
            ShowManageUserMenue();
        }

       static void _ShowAllUsersScreen()
       {
            clsUserListScreen::ShowUserList();
       }

       static void _ShowAddNewUserScreen()
       {
            clsAddNewUserScreen::ShowAddNewUserScreen();
       }

       static void _ShowDeleteUserScreen()
       {
            clsDeleteUser::DeleteUser();
       }

       static void _ShowUpdateUserScreen()
       {
            clsUpdateUser::UpdateUser();
       }

       static void _ShowFindUserScreen()
       {
            clsFindUserScreen::ShowFindUserScreen();
       }

       
       static void _Logut()
       {
            CurrentUser = clsUser::Find("","");
       }

       static void _PerfromManageUsersMenueOption(enMainManageUsersptions MangaUsersOption)
        {
            switch (MangaUsersOption)
            {
            case enMainManageUsersptions::eListUser :
            {
                system("clear");
                _ShowAllUsersScreen();
                _GoBackToManageUsersMenue();
                break;
            }
            case enMainManageUsersptions::eAddNewUser:
                system("clear");
               _ShowAddNewUserScreen();
                _GoBackToManageUsersMenue();
                break;

            case enMainManageUsersptions::eDeleteUser:
                system("clear");
                _ShowDeleteUserScreen();
                _GoBackToManageUsersMenue();

                break;

            case enMainManageUsersptions::eUpdateUser:
                system("clear");
                _ShowUpdateUserScreen();
                _GoBackToManageUsersMenue();

                break;

            case enMainManageUsersptions::eFindUser:
                system("clear");
                _ShowFindUserScreen();
                _GoBackToManageUsersMenue();

                break;


            case enMainManageUsersptions::eBackMainMenue:
                system("clear");
                _Logut();
                //Login();

                break;
            }

        }



	public:
       

       static void ShowManageUserMenue()
        {
            if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
            return;// this will exit the function and it will not continue
        }
           
            system("clear");
            _DrawScreenHeader("\tMain Manage Users Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\tManage User Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left <<""<< setw(7) << "[1] Show All User\n";
            cout << setw(37) << left <<""<< setw(7) << "[2] Add New User\n";
            cout << setw(37) << left <<""<< setw(7) << "[3] Delete User\n";
            cout << setw(37) << left <<""<< setw(7) << "[4] Updatw User info\n";
            cout << setw(37) << left <<""<< setw(7) << "[5] Find User\n";
            cout << setw(37) << left <<""<< setw(7) << "[6] Back to Main Menue\n";
            cout << setw(37) << left <<""<< "===========================================\n";

            _PerfromManageUsersMenueOption((enMainManageUsersptions)_ReadMenueManageUsersOption());
        }

};

