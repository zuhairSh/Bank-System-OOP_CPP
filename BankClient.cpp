#include <iostream>
#include <iomanip>
#include "Library/clsInputValidation.h"
#include "Library/clsBankClients.h"
#include "Library/clsUtil.h"


 void PrintClientRecordLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.getAccountNumber();
    cout << "| " << setw(20) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.Phone();
    cout << "| " << setw(20) << left << Client.Email();
    cout << "| " << setw(10) << left << Client.getPinCode();
    cout << "| " << setw(12) << left << Client.getAccountBalance();

}

void ShowClientsList()
{

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(20) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(20) << "Email";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}


void PrintClientRecordBalanceLine(clsBankClient Client)
{

    cout << "| " << setw(15) << left << Client.getAccountNumber();
    cout << "| " << setw(40) << left << Client.FullName();
    cout << "| " << setw(12) << left << Client.getAccountBalance();

}


void ShowTotalBalances()
{

    vector <clsBankClient> vClients = clsBankClient::GetClientsList();

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = clsBankClient::GetTotalBalances();

    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {
            PrintClientRecordBalanceLine(Client);
            cout << endl;
        }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
    cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")\n\n";
}




void ReadClientInfo(clsBankClient& Client)
{
    Client.setFirstName(clsInputValidation::ReadString("Enter FirstName: "));
    Client.setLastName(clsInputValidation::ReadString("Enter LastName: "));
    Client.setEmail(clsInputValidation::ReadString("Enter Email: "));
    Client.setPhone(clsInputValidation::ReadString("Enter Phone: "));
    Client.setPinCode(clsInputValidation::ReadString("Enter PinCode: "));
    Client.setAccountBalance(clsInputValidation::ReadDoubleNumber("No !, Pleas Enter Double Number : ", "Enter Account Balance: "));
}

void UpdateClient()
{
    string AccountNumber = "";
    
    AccountNumber = clsInputValidation::ReadString("Enter Account Number for Client : ");

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        AccountNumber = clsInputValidation::ReadString("Account Number Is Not Fount !!, Enter Account Number for Client : ");

    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();

    ReadClientInfo(Client1);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = Client1.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Updated Successfully :-)\n";
        Client1.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }

    }
    

}


void AddClient()
{
    string AccountNumber = "";
    
    AccountNumber = clsInputValidation::ReadString("Enter Account Number for Client : ");

    while (clsBankClient::IsClientExist(AccountNumber))
    {
        AccountNumber = clsInputValidation::ReadString("Account Number for the client already exists !!, Enter new Account Number for Client : ");

    }

    clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;
    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Added Successfully :-)\n";
        NewClient.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }

    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "Account Number for the client already exists !\n";
        NewClient.Print();
        break;
    }

    }
    
}


void DeleteClient()
{
    string AccountNumber = "";
    
    AccountNumber = clsInputValidation::ReadString("Enter Account Number for Client : ");

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        AccountNumber = clsInputValidation::ReadString("Account Number Is Not Fount !!, Enter Account Number for Client : ");

    }

    clsBankClient Client1 = clsBankClient::Find(AccountNumber);
    Client1.Print();



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


int main()

{

    ShowTotalBalances();
    
    return 0;
}