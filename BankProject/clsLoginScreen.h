#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"
class clsLoginScreen : private clsScreen
{

	static void ReadUserNameAndPassword(string &UserName , string &Password) 
	{

		cout << setw(40)<<""<<"Enter User Name : ";
		UserName = clsInputValidate::ReadString();

		cout << setw(40) << "" << "Enter Password : ";
		Password = clsInputValidate::ReadString();
	}



public:


	static bool ShowLoginScreen() 
	{

		string UserName, Password;
		bool LoginFailed= false;
		short FailedLoginCount = 0;
		do {

			system("cls");
			_DrawScreenHeader("\t     Login Screen");

			if (LoginFailed)
			{
				FailedLoginCount++;

				cout << "\n" << setw(40) << "" << "Wrong User/Password Try Again\n\n" << endl;
				cout << setw(40) << "" << "You Have [" << 3 - FailedLoginCount << "] Tries !\n" << endl;
			}
			if (FailedLoginCount == 3) {
				cout << "\n" << setw(40) << "" << "Your Account IS Locked ! \n";
				system("pause>0");
				return false;
			}

			ReadUserNameAndPassword(UserName, Password);

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();

		return true;
	
	}
};

