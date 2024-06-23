#pragma once
#include <iostream>
#include  <string>
#include<vector>

using namespace std;
class clsString
{

public:
	static vector <string> Split(string Str, string Seprator) {
		vector <string> Vstring;
		short Position;
		string Word;

		while ((Position = Str.find(Seprator)) != std::string::npos)
		{
			Word = Str.substr(0, Position);
			Vstring.push_back(Word);
			Str.erase(0, Position + Seprator.length());
		}
		Vstring.push_back(Str);
		return Vstring;

	}

	static string IncryptPassword(string Str,short Key= 99) 
	{

		for (short i = 0; i < Str.length(); i++) 
		{

			Str[i] = char((int)Str[i] + Key);


		}

		return Str;

	}

	static string DecryptPassword(string Str, short Key = 99)
	{

		for (short i = 0; i < Str.length(); i++)
		{

			Str[i] = char((int)Str[i] - Key);


		}

		return Str;

	}

	static string UpperAllString(string Str) 
	{
		for (short i = 0; i < Str.size(); i++) {
			Str[i] = toupper(Str[i]);
	}
		return Str;
	}

	static string UpperFirstLetterOnly(string Str) 
	{
		Str[0] = toupper(Str[0]);

		for (short i = 1; i < Str.size(); i++) 
		{

			Str[i] = tolower(Str[i]);

		}

		return Str;
	}
};

