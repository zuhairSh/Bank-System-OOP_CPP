#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidation.h"

class clsUpdateCurrencyRateScreen :protected clsScreen

{
private:

    static float _ReadRate()
    {

        double NewRate = 0;

        NewRate = clsInputValidation::ReadDoubleNumber("\nEnter New Rate: ","\nEnter New Rate: ");
        return NewRate;
    }

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

public:

    static void ShowUpdateCurrencyRateScreen()
    {

        _DrawScreenHeader("\tUpdate Currency Screen");

        string CurrencyCode = "";

        CurrencyCode = clsInputValidation::ReadString("\nPlease Enter Currency Code: ");

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            CurrencyCode = clsInputValidation::ReadString("\nCurrency is not found, choose another one: ");
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency.UpdateRate( _ReadRate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
          

        }

    }
};
