#pragma once
#include "clsScreen.h"
#include "_clsCurrency.h";
class _clsFindCurrencyScreen : public clsScreen
{


public:
	static void ShowFindCurrencyScreen() 
	{

		_DrawScreenHeader("Find Currency Screen");
		short UserChoise=0;
		cout << "\n Find By [      Code[1]     ||     Country [2]      ] ? :  ";
		cin >> UserChoise;

		switch (UserChoise) 
		{

		case 1:
		{

			string CurrencyCode = "";
			bool Exist = true;
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

			break;

		};

		case 2:
		{
			string Country = "";
			bool Exist = true;
			do 
			{
				if (!Exist) 
				{

					cout << "\nWrong Country  ! Please Try Again ";

				}

				cout << "\nEnter Country  : ";
				cin >> Country;

				Exist = _clsCurrency::IsCurrencyExistByCountry(Country);

			} while (!Exist);

			_clsCurrency Currency = _clsCurrency::FindByCountry(Country);
			Currency.PrintCurrencyCard();

			break;

		}
		}
	}
};

