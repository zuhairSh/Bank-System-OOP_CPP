#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClients.h"
#include "clsUtil.h"
#include <iomanip>

class clsTotalBalances :protected clsScreen
{

private:
   static void PrintClientRecordLine(clsBankClient Client)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Client.getAccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.getAccountBalance();

    }

public:
  

   static void ShowTotalBalancesClientsList()
    {

        
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "\t Total Balance Client List Screen";
        string SubTitle ="\t    (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        float TotalBalances = clsBankClient::GetTotalBalances();

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }
            
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "_________________________________________\n" << endl;

            cout << setw(8) << left << "Sum All Total Balances = ( " << TotalBalances << " )\n";

            cout << setw(8) << left << "Sum All Total Balances to Text = ( " << clsUtil::NumberToText(TotalBalances) << " )";

    }

};
