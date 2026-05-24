#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClients.h"
#include "clsInputValidation.h"
#include <iomanip>
#include "Global.h"

class clsDeleteClient : protected clsScreen
{
private:
    static void _Print(clsBankClient &Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName();
        cout << "\nLastName    : " << Client.LastName();
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email();
        cout << "\nPhone       : " << Client.Phone();
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nPassword    : " << Client.getPinCode();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

public:

    static void DeleteClient()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t  Delete Client Screen");

        string AccountNumber = "";
        
        AccountNumber = clsInputValidation::ReadString("Enter Account Number for Client : ");

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValidation::ReadString("Account Number Is Not Fount !!, Enter Account Number for Client : ");

        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _Print(Client1);



        cout << "\nAre you sure you want to delete this client y/n? ";
        
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            Client1.Delete();
            cout << "\nClient Deleted Successfully! :)\n";
        }
        else
        {
            cout << "\nClient Was not Deleted\n";
        }
    


    }



};
