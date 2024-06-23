#pragma once
#include "clsScreen.h"
#include "_clsCurrency.h"

class _clsUpdateRateScreen : protected clsScreen
{


public:


	static void ShowUpdateRateScreen() 
	{
		_DrawScreenHeader("Update Rate Screen ");
		float NewRate = 0;
		string CurrencyCode = "";
		bool Exist = true;
		char UserChoise;

		do
		{
			if (!Exist)
			{

				cout << "\nWrong Currency Code ! Please Try Again ";

			}
			cout << "\nEnter Currency Code : ";
			cin >> CurrencyCode;

			Exist = _clsCurrency::IsCurrencyExistByCode(CurrencyCode);

		} while (!Exist);


		_clsCurrency Currency = _clsCurrency::FindByCode(CurrencyCode);
		Currency.PrintCurrencyCard();



		cout << "\nAre you Sure You Want To Ypdate The Rate Of This Currency [Y,N] : ";
		cin >> UserChoise;

		if (toupper(UserChoise) == 'Y') 
		{
			cout << "\nPlease Enter The New Rate : ";
			cin >> NewRate;

			Currency.UpdateRate(NewRate);
			cout << "\nUpdated Successfully\n";
			Currency.PrintCurrencyCard();

		}

		else 
		{

			cout << "\nNo Thing Is Changed ! \n" << endl;

		}

	}
};

