#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClients.h"
#include "clsInputValidation.h"
#include "Global.h"
#include <iomanip>

class clsUpdateClient : protected clsScreen
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

    static void _ReadClientInfo(clsBankClient& Client)
    {
        Client.setFirstName(clsInputValidation::ReadString("Enter FirstName: "));
        Client.setLastName(clsInputValidation::ReadString("Enter LastName: "));
        Client.setEmail(clsInputValidation::ReadString("Enter Email: "));
        Client.setPhone(clsInputValidation::ReadString("Enter Phone: "));
        Client.setPinCode(clsInputValidation::ReadString("Enter PinCode: "));
        Client.setAccountBalance(clsInputValidation::ReadDoubleNumber("No !, Pleas Enter Double Number : ", "Enter Account Balance: "));
    }

public:

    static void UpdateClient()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return;// this will exit the function and it will not continue
        }

        _DrawScreenHeader("\t  Update Client Screen");

        string AccountNumber = "";
        
        AccountNumber = clsInputValidation::ReadString("Enter Account Number for Client : ");

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            AccountNumber = clsInputValidation::ReadString("Account Number Is Not Fount !!, Enter Account Number for Client : ");

        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _Print(Client1);

        _ReadClientInfo(Client1);

        clsBankClient::enSaveResults SaveResult;
        SaveResult = Client1.Save();

        switch (SaveResult)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _Print(Client1);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;

        }

        }
        

    }


};
