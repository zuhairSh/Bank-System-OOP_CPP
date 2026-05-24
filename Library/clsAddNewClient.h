#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClients.h"
#include "clsInputValidation.h"
#include "Global.h"
#include <iomanip>

class clsAddNewClientScreen : protected clsScreen
{
private:
    static void _ReadClientInfo(clsBankClient& Client)
    {
        Client.setFirstName(clsInputValidation::ReadString("Enter FirstName: "));
        Client.setLastName(clsInputValidation::ReadString("Enter LastName: "));
        Client.setEmail(clsInputValidation::ReadString("Enter Email: "));
        Client.setPhone(clsInputValidation::ReadString("Enter Phone: "));
        Client.setPinCode(clsInputValidation::ReadString("Enter PinCode: "));
        Client.setAccountBalance(clsInputValidation::ReadDoubleNumber("No !, Pleas Enter Double Number : ", "Enter Account Balance: "));
    }

    static void _PrintClient(clsBankClient Client)
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

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t  Add New Client Screen");

        string AccountNumber = "";

        AccountNumber = clsInputValidation::ReadString("\nPlease Enter Account Number: ");
        while (clsBankClient::IsClientExist(AccountNumber))
        {

            AccountNumber = clsInputValidation::ReadString("\nAccount Number Is Already Used, Choose another one: ");
        }

        clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);


        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResult;

        SaveResult = NewClient.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Addeded Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;

        }
        }
    }



};
