#include <iostream>
#include "Library/clsDate.h"
#include "Library/clsInputValidation.h"

using namespace std;

int main()
{
    cout << clsInputValidation::IsNumberBetween(10,5,20) << endl;

    cout << clsInputValidation::IsNumberBetween(10.5,5.8,20.7) << endl;

    cout << clsInputValidation::IsDateBetween(clsDate(), clsDate("2/3/2024"), clsDate(20,8,2026))
     << endl;

    //int NumInt = clsInputValidation::ReadIntNumber("Error, Your Number is Not int");
    //cout << NumInt << endl;

    //double NumInt = clsInputValidation::ReadDoubleNumber("Error, Your Number is Not double");
    //cout << NumInt << endl;

    //int IntNumberBetween = clsInputValidation::ReadIntNumberBetween(1,10,"Error, Your Number is Not Between 1 / 10");
    //cout << IntNumberBetween << endl;

    //double doubleNumberBetween = clsInputValidation::ReadDoubleNumberBetween(1.7,10.5,"Error, Your Number is Not Between 1.7 / 10.5");
    //cout << doubleNumberBetween << endl;

    cout << clsInputValidation::IsValidDate(clsDate("2/12/2022")) << endl;

    string str = clsInputValidation::ReadString("Enter your String : ");
    cout << str << endl;


}