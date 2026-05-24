#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "clsDate.h"

using namespace std;

class clsInputValidation
{
private:

    static bool IsLeapYear(short Year)
    {
        return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
    }

    // عدد أيام الشهر
    static short NumberOfDaysInAMonth(short Year, short Month)
    {
        if (Month < 1 || Month > 12)
            return 0;

        short Days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        if (Month == 2)
            return IsLeapYear(Year) ? 29 : 28;

        return Days[Month - 1];
    }

public:

    static bool IsNumberBetween(int Num1, int Num2, int Num3)
    {
        return ((Num1 >= Num2 && Num1 <= Num3) || (Num1 <= Num2 && Num1 >= Num3)) ? true : false; 
    }

    static bool IsNumberBetween(short Num1, short Num2, short Num3)
    {
        return (Num1 >= Num2 && Num1 <= Num3) || (Num1 <= Num2 && Num1 >= Num3); 
    }

    static bool IsNumberBetween(float Num1, float Num2, float Num3)
    {
        return (Num1 >= Num2 && Num1 <= Num3) || (Num1 <= Num2 && Num1 >= Num3); 
    }

    static bool IsNumberBetween(double Num1, double Num2, double Num3)
    {
        return (Num1 >= Num2 && Num1 <= Num3) || (Num1 <= Num2 && Num1 >= Num3); 
    }



    static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.GetYear() < Date2.GetYear()) ? true :
            ((Date1.GetYear() == Date2.GetYear()) ?
            (Date1.GetMonth() < Date2.GetMonth() ? true :
            (Date1.GetMonth() == Date2.GetMonth() ?
                Date1.GetDay() < Date2.GetDay() : false))
            : false);
    }

    static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
    {
        return (Date1.GetYear() == Date2.GetYear()) ? ((Date1.GetMonth() == Date2.GetMonth())
        ? ((Date1.GetDay() == Date2.GetDay()) ? true : false) : false) : false;
    }

    static bool IsDate1AfterDte2(clsDate Date1, clsDate Date2)
    {
        return (!IsDate1BeforeDate2(Date1,Date2) && !IsDate1EqualDate2(Date1,Date2));
    }

    static bool IsDateBetween(clsDate Date1, clsDate Date2, clsDate Date3)
    {
        return (IsDate1BeforeDate2(Date1,Date2) && IsDate1AfterDte2(Date1,Date3))
        || (IsDate1BeforeDate2(Date1,Date3) && IsDate1AfterDte2(Date1,Date2));
    }
    

    static string ReadString(string Masseg)
    {
        string str= " ";

        cout << Masseg;
        getline(cin >> ws,str);
        
        return str;
        
    }


    static int ReadIntNumber(string ErrorMasseg)
    {
        int Number;

        cout << "Please Enter int Number: ";

        while (!(cin >> Number))
        {
            cin.clear(); //لـ حذف (تجاهل) باقي الإدخال الخاطئ
            cin.ignore(10000, '\n'); //لـ حذف (تجاهل) باقي الإدخال الخاطئ

            cout << ErrorMasseg << endl;
            cout << "Please Enter int Number: ";
        }

        return Number;
        
    }

     static double ReadDoubleNumber(string ErrorMasseg, string Masseg)
    {
        double Number;

        cout << Masseg;

        while (!(cin >> Number))
        {
            cin.clear(); //لـ حذف (تجاهل) باقي الإدخال الخاطئ
            cin.ignore(10000, '\n'); //لـ حذف (تجاهل) باقي الإدخال الخاطئ

            cout << ErrorMasseg << endl;
            cout << Masseg;
        }

        return Number;
        
    }



    static int ReadIntNumberBetween(int Num1, int Num2 ,string ErrorMasseg)
    {
        int Number;

        cout << "Please Enter int Number Between " << Num1 << " / " << Num2 << " : ";

        while (!(cin >> Number) || !(IsNumberBetween(Number,Num1,Num2)))
        {
            cin.clear(); //لـ حذف (تجاهل) باقي الإدخال الخاطئ
            cin.ignore(10000, '\n'); //لـ حذف (تجاهل) باقي الإدخال الخاطئ

            cout << ErrorMasseg << endl;
        }

        return Number;
        
    }

    static double ReadDoubleNumberBetween(double Num1, double Num2 ,string ErrorMasseg)
    {
        double Number;

        cout << "Please Enter double Number Between " << Num1 << " / " << Num2 << " : ";

        while (!(cin >> Number) || !(IsNumberBetween(Number,Num1,Num2)))
        {
            cin.clear(); //لـ حذف (تجاهل) باقي الإدخال الخاطئ
            cin.ignore(10000, '\n'); //لـ حذف (تجاهل) باقي الإدخال الخاطئ

            cout << ErrorMasseg << endl;
            cout << "Please Enter double Number Between ";
        }

        return Number;
        
    }


    static bool IsValidDate(clsDate Date)
    {
        if (Date.GetYear() < 1)
            return false;

        if (Date.GetMonth() < 1 || Date.GetMonth() > 12)
            return false;

        short Days = NumberOfDaysInAMonth(Date.GetYear(), Date.GetMonth());

        if (Date.GetDay() < 1 || Date.GetDay() > Days)
            return false;

        return true;
    }

};