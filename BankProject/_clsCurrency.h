#pragma once
#include <iostream>
#include <vector>
#include "clsString.h"
#include <string>
#include <fstream>



class _clsCurrency
{


private :


					//Private VARS
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;
	string _Country;
    string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;

                    //Private Functions
    void _SetRate(float Rate)
    {

        _Rate = Rate;

    }

    string _ConvertCurrencyObjectToLine(_clsCurrency Currency, string Seperator = "#//#")
    {

        string CurrencyRecord = "";
        CurrencyRecord += Currency._Country + Seperator;
        CurrencyRecord += Currency._CurrencyCode + Seperator;
        CurrencyRecord += Currency._CurrencyName + Seperator;
        CurrencyRecord += to_string(Currency._Rate) + Seperator;

        return CurrencyRecord;

    }

    void _SaveCurrenciessToDataToFile(vector <_clsCurrency> vCurrenciess)
    {

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (_clsCurrency C : vCurrenciess)
            {

                DataLine = _ConvertCurrencyObjectToLine(C);
                MyFile << DataLine << endl;



            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <_clsCurrency> vclsCurrency = LoadCurrenciesDataFromFile();

        for (_clsCurrency& C : vclsCurrency)
            if (C.CurrencyCode() == CurrencyCode())
            {

                C = *this;

                break;

            }

        _SaveCurrenciessToDataToFile(vclsCurrency);

    }



    static _clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
    {

        vector<string> vCurrency;
        vCurrency = clsString::Split(Line, Seperator);

        return _clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));

    }

    static _clsCurrency _EmptyCurrencyObject()
    {

        return  _clsCurrency(enMode::EmptyMode, "", "", "", 0);

    }


public : 


					//Constructors
	_clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName,  float Rate)
	{

         _Mode = Mode;
		 _Country = Country;
         _CurrencyCode = CurrencyCode;
		 _CurrencyName = CurrencyName;
		 _Rate = Rate;

	}


                     //Set & Get 
    float Rate()
    {

        return _Rate;

    }

    string CurrencyCode()
    {

        return _CurrencyCode;

    }

    string CurrencyName()
    {

        return _CurrencyName;

    }

    string Country()
    {

        return _Country;

    }

    void UpdateRate(float Rate) 
    {

        _SetRate(Rate);

        _Update();

    }

    void PrintCurrencyCard()
    {

        cout << "\n===============================" << endl;

        cout << "Country        : " << Country() << endl;
        cout << "Currency Name  : " << CurrencyName() << endl;
        cout << "Currency Code  : " << CurrencyCode() << endl;
        cout << "Rate[$]        : " << Rate() << endl;

        cout << "\n===============================\n" << endl;

    }


                      // Functions 
   static vector <_clsCurrency> LoadCurrenciesDataFromFile()
    {

        vector <_clsCurrency> vclsCurrency;

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                _clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

                vclsCurrency.push_back(Currency);
            }

            MyFile.close();

        }

        return vclsCurrency;

    }

   bool IsEmpty() 
    {

        return (_Mode == enMode::EmptyMode);

    }

   static _clsCurrency FindByCode(string CurrencyCode)
    {

        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;

            while (getline(MyFile, Line))
            {

                _clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode)
                {

                    MyFile.close();
                    return Currency;

                }

            }


        }

        return _EmptyCurrencyObject();

    }


   static _clsCurrency FindByCountry(string Country)
   {

       Country = clsString::UpperAllString(Country);

       fstream MyFile;
       MyFile.open("Currencies.txt", ios::in);

       if (MyFile.is_open())
       {

           string Line;

           while (getline(MyFile, Line))
           {

               _clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
               if (clsString::UpperAllString(Currency.Country()) == Country)
               {

                   MyFile.close();
                   return Currency;

               }

           }


       }

       return _EmptyCurrencyObject();

   }



   static bool IsCurrencyExistByCode(string CurrencyCode) 
    {

        _clsCurrency C = FindByCode(CurrencyCode);

        return (!C.IsEmpty());

    }

   static bool IsCurrencyExistByCountry(string Country)
   {

       _clsCurrency C = FindByCountry(Country);

       return (!C.IsEmpty());

   }

   float ConvertToUSD(float Ammount)
   {
       return (float)(Ammount / Rate());
   }
   
   float ConvertToOtherCurrency(float Amount, _clsCurrency Currency2)
   {
       float AmountInUSD = ConvertToUSD(Amount);

       if (Currency2.CurrencyCode() == "USD")
       {
           return AmountInUSD;
       }

       return (float)(AmountInUSD * Currency2.Rate());

   }

};

