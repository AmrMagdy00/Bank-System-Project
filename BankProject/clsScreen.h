#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
#include <iomanip>
#include "clsDate.h"

using namespace std;

class clsScreen
{

protected:


    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {

        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;

        if (SubTitle != "")
        {

            cout << "\n\t\t\t\t\t  " << SubTitle;

        }

        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << setw(40) << "" << "User : " << CurrentUser.UserName << endl;
        cout << setw(40) << "" << "Date : " << clsDate::GetSystemDateTimeString() <<"\n\n" << endl;

    }

    static bool CheckAccessRights(clsUser::enPermissions Permissions) 
    {

        if (!CurrentUser.CheckPermissions(Permissions)) 
        {

            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  " << "Access Denied! Contact [MR: Amr-DB]";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
            return true;
        
    }


};
