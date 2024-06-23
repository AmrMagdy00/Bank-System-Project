#pragma once
#include "clsScreen.h"
#include "_clsCurrency.h"

class _clsListCurrenciesScreen : protected clsScreen
{

private : 

    static void PrintCurrencyRecordLine(_clsCurrency Currency)
    {

        cout << setw(8) <<""<< "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(15) << left << Currency.CurrencyCode() ;
        cout << "| " << setw(30) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate();


    }



public:

	static void ShowListCurrenciesListScreen() 
	{

        vector <_clsCurrency> vCurrencies = _clsCurrency::LoadCurrenciesDataFromFile();

        string Title = "List Currencies Screen";
        string SubTitle = "[ " + to_string(vCurrencies.size()) + " ] Currency.";
		_DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(15) << "Country Code";
        cout << "| " << left << setw(30) << "Currency Name";
        cout << "| " << left << setw(10) << "Rate [$]";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (_clsCurrency &Currency : vCurrencies)
            {

                PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

	}
};

