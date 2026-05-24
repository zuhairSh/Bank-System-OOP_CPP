#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClients.h"
#include "clsInputValidation.h"

class clsTransferScreen : protected clsScreen
{

private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.getAccountNumber();
        cout << "\nBalance     : " << Client.getAccountBalance();
        cout << "\n___________________\n";

    }

    static string _ReadAccountNumberFrom()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter the Account Number from which you wish to transfer funds ? ";
        cin >> AccountNumber;
        return AccountNumber;
    }

    static string _ReadAccountNumberTO()
    {
        string AccountNumber = "";
        cout << "\nPlease Enter the Account Number TO which you wish to transfer funds ? ";
        cin >> AccountNumber;
        return AccountNumber;
    }


public:

    static void ShowTransferScreen()
    {
        _DrawScreenHeader("\t   Transfer Screen");

        string AccountNumberFrom = _ReadAccountNumberFrom();


        while (!clsBankClient::IsClientExist(AccountNumberFrom))
        {
            cout << "\nClient with [" << AccountNumberFrom << "] does not exist.\n";
            AccountNumberFrom = _ReadAccountNumberFrom();
        }

        clsBankClient ClientFrom = clsBankClient::Find(AccountNumberFrom);
        _PrintClient(ClientFrom);




         string AccountNumberTo = _ReadAccountNumberTO();
        while (!clsBankClient::IsClientExist(AccountNumberTo))
        {
            cout << "\nClient with [" << AccountNumberTo << "] does not exist.\n";
            AccountNumberTo = _ReadAccountNumberFrom();
        }

        clsBankClient ClientTo = clsBankClient::Find(AccountNumberTo);
        _PrintClient(ClientTo);


        double Amount = 0;
    
        Amount = clsInputValidation::ReadDoubleNumber("Error!!,Enter the amount you wish to transfer : ","\nPlease Enter the amount you wish to transfer : ");

        cout << "\nAre you sure you want to perform this transfer? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            ClientFrom._Transfer(Amount,ClientTo);

            cout << "\nAmount Transfered Successfully.\n";

            _PrintClient(ClientFrom);
            _PrintClient(ClientTo);
        }
        else
        {
            cout << "\nOperation was cancelled.\n";
        }

    }

};
