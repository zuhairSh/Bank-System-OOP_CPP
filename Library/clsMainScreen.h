#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidation.h"
#include "clsClientsListScreen.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegister.h"
#include "clsMainCurrency.h"
#include <iomanip>
#include <limits>


using namespace std;

class clsMainScreen:protected clsScreen
{


    private:
        enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7,eListLoginRegister = 8, eMainCurrency = 9, eExit = 10
        };

       static short _ReadMainMenueOption()
        {
            cout <<setw(37) << left << ""<< "Choose what do you want to do? [1 to 10]? ";
            short Choice = clsInputValidation::ReadIntNumberBetween(1,10,"Enter Number between 1 to 10? ");
            return Choice;
        }

        static void _GoBackToMainMenue()
        {
            cout << "\n\tPress any key then Enter to go back to Main Menu...\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // تنظيف الإدخال
            cin.get(); // انتظار أي إدخال

            ShowMainMenue();
        }

       static void _ShowAllClientsScreen()
       {
            clsClientListScreen::ShowClientsList();
       }

       static void _ShowAddNewClientsScreen()
       {
            clsAddNewClientScreen::ShowAddNewClientScreen();
       }

       static void _ShowDeleteClientScreen()
       {
            clsDeleteClient::DeleteClient();
       }

       static void _ShowUpdateClientScreen()
       {
           clsUpdateClient::UpdateClient();

       }

       static void _ShowFindClientScreen()
       {
           clsFindClientScreen::ShowFindClientScreen();
       }

       static void _ShowTransactionsMenue()
       {
           clsTransactionsScreen::ShowTransactionsMenue();

       }

       static void _ShowManageUsersMenue()
       {
            clsManageUsersScreen::ShowManageUserMenue();
       }

       static void _ShowLoginRegister()
       {
            clsLoginRegisterList::ShowLoginRegisterScreen();
       }

       static void _ShowMainCurrency()
       {
            clsCurrencyExchangeMainScreen::ShowCurrenciesMenue();
       }

       static void _ShowEndScreen()
           {
               cout << "\nEnd Screen Will be here...\n";

           }

       static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
        {
            switch (MainMenueOption)
            {
            case enMainMenueOptions::eListClients:
            {
                system("clear");
                _ShowAllClientsScreen();
                _GoBackToMainMenue();
                break;
            }
            case enMainMenueOptions::eAddNewClient:
                system("clear");
               _ShowAddNewClientsScreen();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eDeleteClient:
                system("clear");
                _ShowDeleteClientScreen();
                _GoBackToMainMenue();

                break;

            case enMainMenueOptions::eUpdateClient:
                system("clear");
                _ShowUpdateClientScreen();
                _GoBackToMainMenue();

                break;

            case enMainMenueOptions::eFindClient:
                system("clear");
                _ShowFindClientScreen();
                _GoBackToMainMenue();

                break;

            case enMainMenueOptions::eShowTransactionsMenue:
                system("clear");
                _ShowTransactionsMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eManageUsers:
                system("clear");
                _ShowManageUsersMenue();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eListLoginRegister:
                system("clear");
                _ShowLoginRegister();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eMainCurrency:
                system("clear");
                _ShowMainCurrency();
                _GoBackToMainMenue();
                break;

            case enMainMenueOptions::eExit:
                system("clear");
                _ShowEndScreen();
                //Login();

                break;
            }

        }



	public:
       

       static void ShowMainMenue()
        {
           
            system("clear");
            _DrawScreenHeader("\t\tMain Screen");

            cout << setw(37) << left <<""<< "===========================================\n";
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Show Login Register List.\n";
            cout << setw(37) << left << "" << "\t[9] Main Currency.\n";
            cout << setw(37) << left << "" << "\t[10] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";

            _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
        }

};

