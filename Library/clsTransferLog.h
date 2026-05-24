#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsDate.h"
#include "clsBankClients.h"
#include <string>
#include <iomanip>
#include "Global.h"

class clsLogTransferList:protected clsScreen
{

private:
   
    static void PrintLoginTransferLine(clsBankClient::stLogTransfer LoginTransfer)
    {

        cout << setw(8) << left << "" << "| " << setw(38) << left << LoginTransfer.DateTime;
        cout << "| " << setw(8) << left << LoginTransfer.AccFrom;
        cout << "| " << setw(10) << left << LoginTransfer.BalancAccFrom;
        cout << "| " << setw(8) << left << LoginTransfer.AccTo;
        cout << "| " << setw(10) << left << LoginTransfer.BalancAccTo;
        cout << "| " << setw(8) << left << LoginTransfer.Amout;
        cout << "| " << setw(8) << left << LoginTransfer.User;
    }

public:
  
    static void ShowLogTransferScreen()
    {

        vector <clsBankClient::stLogTransfer> vLoginTransfer = clsBankClient::GetLogTransferList();
  
        string Title = "\tLog Transfer List Screen";
        string SubTitle =  "\t\t(" + to_string(vLoginTransfer.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(38) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acc";
        cout << "| " << left << setw(10) << "s,Balance";
        cout << "| " << left << setw(8) << "d.Acc";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "Amout";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vLoginTransfer.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stLogTransfer Record : vLoginTransfer)
            {

                PrintLoginTransferLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};