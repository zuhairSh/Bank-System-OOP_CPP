#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "Global.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:

    enum enMode {EmptyMode = 0, UpdateMode = 1, AddNew = 2};
    enMode _eMode;

    string _AccountNumber;
    string _PinCode;
    double _AccountBalance;
    bool _MarkedForDelete = false;


    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "//")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static string _ConverClientObjectToLine(clsBankClient &Client, string Seperator = "//")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName() + Seperator;
        stClientRecord += Client.LastName() + Seperator;
        stClientRecord += Client.Email() + Seperator;
        stClientRecord += Client.Phone() + Seperator;
        stClientRecord += Client.getAccountNumber() + Seperator;
        stClientRecord += Client.getPinCode() + Seperator;
        stClientRecord += to_string(Client.getAccountBalance());
        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Library/Data_Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Library/Data_Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                if (C._MarkedForDelete == false)
                {
                    DataLine = _ConverClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
                
                

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.getAccountNumber() == getAccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Library/Data_Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConverClientObjectToLine(*this));

    }


    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }


    string _PrepareLogTransfer(clsBankClient AccTo ,double Amout, string Seperator = " // ")
    {
        string LoginRecord = "";

        LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        LoginRecord += AccTo.getAccountNumber() + Seperator;
        LoginRecord += to_string(AccTo.getAccountBalance()) + Seperator;
        LoginRecord += getAccountNumber() + Seperator;
        LoginRecord += to_string(getAccountBalance()) + Seperator;
        LoginRecord += to_string(Amout) + Seperator;
        LoginRecord += CurrentUser.GetUserName();

        return LoginRecord;
    }
    
    void _RegisterLogTransfer(double Amount,clsBankClient& ClientTo)
    {

        string stDataLine = _PrepareLogTransfer(ClientTo, Amount);

        fstream MyFile;
        MyFile.open("Library/TransferData.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    
    
    public:
    
    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone
        ,string AccountNumber, string PinCode, double AccountBalance) 
         : clsPerson(FirstName,LastName,Email,Phone)
    {
        _eMode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmptyMode()
    {
        return (_eMode == enMode::EmptyMode);
    }

    string getAccountNumber()
    {
        return _AccountNumber;
    }

    void setPinCode(string Pincode)
    {
        _PinCode = Pincode;
    }

    string getPinCode()
    {
        return _PinCode;
    }

    void setAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    double getAccountBalance()
    {
        return _AccountBalance;
    }


    struct stLogTransfer
    {
        string DateTime;
        string AccFrom;
        double BalancAccFrom;
        string AccTo;  
        double BalancAccTo;
        double Amout;
        string User;

    };


    static stLogTransfer _ConvertLogTransferLineToRecord(string Line, string Seperator = " // ")
    {
        stLogTransfer LogTransfer;

        vector<string> LogTransferrDataLine = clsString::Split(Line, Seperator);

        LogTransfer.DateTime      = LogTransferrDataLine[0];
        LogTransfer.AccFrom       = LogTransferrDataLine[1];
        LogTransfer.BalancAccFrom = stod(LogTransferrDataLine[2]);
        LogTransfer.AccTo         = LogTransferrDataLine[3];
        LogTransfer.BalancAccTo   = stod(LogTransferrDataLine[4]);
        LogTransfer.Amout         = stod(LogTransferrDataLine[5]);
        LogTransfer.User          = LogTransferrDataLine[6]; // (ناقص عندك)

        return LogTransfer;
    }





    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Library/Data_Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
        
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.getAccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();
            
        }
        
        return _GetEmptyClientObject();
    }


    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Library/Data_Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
    
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.getAccountNumber() == AccountNumber && Client.getPinCode() == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
              
            }

            MyFile.close();
            
        }
        
        return _GetEmptyClientObject();
    }


    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmptyMode());
    }

    
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

    enSaveResults Save()
    {

        switch (_eMode)
        {
        case enMode::EmptyMode:
        {
        
                return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNew:
        {

            if (clsBankClient::IsClientExist(getAccountNumber()))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();
                
                _eMode = enMode::UpdateMode;

                return enSaveResults::svSucceeded;
            }

            break;
        }
        
        }

        return enSaveResults::svFaildEmptyObject;

    }



    static clsBankClient GetAddNewClient(string AccountNumber)
    {
        return clsBankClient(enMode::AddNew,"","","","",AccountNumber,"",0);
    }

    bool Delete()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.getAccountNumber() == _AccountNumber)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

        *this = _GetEmptyClientObject();

        return true;

    }


    static vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();

        double TotalBalances = 0;

            for (clsBankClient Client : vClients)
            {

                TotalBalances += Client._AccountBalance;
            }

            return TotalBalances;

    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    void Withdraw(double Amount)
    {
        _AccountBalance -= Amount;
        Save();
    }


    void _Transfer(double Amount,clsBankClient& ClientTo)
    {
        while (getAccountBalance() < Amount)
        {
            cout << "The amount is higher than your balance. Please select an appropriate amount : ";
            cin >> Amount;
        }

        Withdraw(Amount);
        ClientTo.Deposit(Amount);
        _RegisterLogTransfer(Amount,ClientTo);
    }


    static  vector <stLogTransfer> GetLogTransferList()
     {
         vector <stLogTransfer> vLogTransfer;

         fstream MyFile;
         MyFile.open("Library/TransferData.txt", ios::in);//read Mode

         if (MyFile.is_open())
         {

             string Line;

             stLogTransfer LogTransfer;

             while (getline(MyFile, Line))
             {

                 LogTransfer = _ConvertLogTransferLineToRecord(Line);

                 vLogTransfer.push_back(LogTransfer);

             }

             MyFile.close();

         }

         return vLogTransfer;

     }


};