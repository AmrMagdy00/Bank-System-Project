#pragma once
class clsLoginRegisterScreen : protected clsScreen
{
private : 
    struct stLoginRegisterRecord {
        string Date_Time;
        string UserName;
        string Password;
        string Permissions;
    };

    static stLoginRegisterRecord ConvertLoginRegisterLineToRecord(string Line, string Seprator = "#//#")
    {

        vector <string> vString = clsString::Split(Line, Seprator);
        stLoginRegisterRecord LoginRegister;
        LoginRegister.Date_Time = vString[0];
        LoginRegister.UserName = vString[1];
        LoginRegister.Password = clsString::DecryptPassword(vString[2]);
        LoginRegister.Permissions = vString[3];

        return LoginRegister;

    }

    static vector <stLoginRegisterRecord> _GetDataFromFileToStruct(string FileName = "LoginRegister.txt") {
        vector <string> vString;
        vector< stLoginRegisterRecord >vLoginRegisterRecord;
        fstream MyFile;
        MyFile.open(FileName, ios::in);
        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line)) {
                vLoginRegisterRecord.push_back(ConvertLoginRegisterLineToRecord(Line));


            }

            MyFile.close();
        }
        return vLoginRegisterRecord;
    }


    static void PrintLoginRegister(stLoginRegisterRecord LoginRegister)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegister.Date_Time;
        cout << "| " << setw(20) << left << LoginRegister.UserName;
        cout << "| " << setw(12) << left << LoginRegister.Password;
        cout << "| " << setw(20) << left << LoginRegister.Permissions;


    }
public:



    static void ShowLoginRegisterScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister)) {
            return;
        };

        vector<stLoginRegisterRecord>vsLoginRegister = _GetDataFromFileToStruct();
        string Title = "\t  Login Register List Screen";
        string SubTitle = "\t    (" + to_string(vsLoginRegister.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(20) << "UserName";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(20) << "Permissions";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vsLoginRegister.size() == 0)
            cout << "\t\t\t\tNo Records Available In the System!";
        else

            for (stLoginRegisterRecord S : vsLoginRegister)
            {

                PrintLoginRegister(S);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

