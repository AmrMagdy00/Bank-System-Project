#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "_clsListCurrenciesScreen.h"
#include "_clsFindCurrencyScreen.h"
#include "_clsUpdateRateScreen.h"
#include "_clsCurrencyCalculatorScreen.h"
class _clsCurrencyMainScreen : protected clsScreen


{

private:

    enum enCurrencyExchangeMenuOptions 
    {

        ListCurrencies=1,
        FindCurrency=2,
        UpdateRate=3,
        CurrencyCalculator=4,
        MainMenu=5

    };

    static void _GoBackToExchangeMenue() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Exchange Menue...\n";

        system("pause>0");
        ShowCurrenciesMenu();
    }

    static short _ReadCurrencyExchangeMenuOption() 
    {

        cout << setw(37) << left << "" << "Choose What Do You Want To Do ? [1 To 5 ] : ";
        short choise = clsInputValidate::ReadShortNumberBetween(1, 5, "\nPlease Enter A Number Between [1-5]\n");
        return choise;
    }

   static void _PerfromCurrencyExchangeMenu(enCurrencyExchangeMenuOptions Option) 
    {

        switch (Option) 
        {

        case enCurrencyExchangeMenuOptions::ListCurrencies:
        {

            system("cls");
            _ShowListCurrenciesListScreen();
            _GoBackToExchangeMenue();
            break;

        }

        case enCurrencyExchangeMenuOptions::FindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToExchangeMenue();
            break;
        }

        case enCurrencyExchangeMenuOptions::UpdateRate:
        {

            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToExchangeMenue();
            break;

        }

        case enCurrencyExchangeMenuOptions::CurrencyCalculator:
        {

            system("cls");
            _ShowCurrencyCalculatorScreen();
             _GoBackToExchangeMenue();
            break;

        }

        case enCurrencyExchangeMenuOptions::MainMenu:
        {

            break;

        }

        }

    }

   static void _ShowListCurrenciesListScreen()
    {
       _clsListCurrenciesScreen::ShowListCurrenciesListScreen();

    }

   static void _ShowFindCurrencyScreen()
    {

       _clsFindCurrencyScreen::ShowFindCurrencyScreen();

    }

   static void _ShowUpdateRateScreen()
    {
       _clsUpdateRateScreen::ShowUpdateRateScreen();
    }

   static void _ShowCurrencyCalculatorScreen()
    {

       _clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }


public:


	static void ShowCurrenciesMenu() {


        system("cls");

        _DrawScreenHeader("   Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t       Currency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyExchangeMenu((enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption());


	}
};

