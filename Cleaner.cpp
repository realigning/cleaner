#include <iostream>
#include <windows.h>
#include <fstream>
using namespace std;

void time()
{
    const std::time_t now = std::time(nullptr);
    const std::tm calendar_time = *std::localtime(std::addressof(now));
    cout << "[" << calendar_time.tm_hour << ":" << calendar_time.tm_min << ":" << calendar_time.tm_sec << "]";
}

void logo()//YOUR LOGO HERE 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 5);
    cout << "" << endl;
    cout << "" << endl;
    cout << R"(  _____  ______          _      _____ _____ _   _ 
 |  __ \|  ____|   /\   | |    |_   _/ ____| \ | |
 | |__) | |__     /  \  | |      | || |  __|  \| |
 |  _  /|  __|   / /\ \ | |      | || | |_ | . ` |
 | | \ \| |____ / ____ \| |____ _| || |__| | |\  |
 |_|  \_\______/_/    \_\______|_____\_____|_| \_|
                                                  
                                                  )" << endl;
    cout << "" << endl;
    cout << "" << endl;

};

int main()
{
    int x;
    //Ask what would like to be done
    logo();
    time(); cout << " REALIGNS CALL OF DUTY CLEANER \n";
    time(); cout << " discord: realign#7085 \n\n";
    time(); cout << " What Would You Like To Do? \n";
    time(); cout << " [1] Run Clean \n";
    time(); cout << " [Else] Close App \n";
    time(); cout << " Enter the corresponding number: ";
    //User Input
    cin >> x;
    //If User Inputs 1
    if (x == 1)
    {
        system("taskkill /f /im battle.net.exe");
        system("taskkill /f /im Agent.exe");

        // Create and open a text file
        ofstream MyFile("C:\\temp\\Cleaner.bat");

        // Write to the file
        //These delete MW Tracer Files
        MyFile << "@echo off \n";
        MyFile << "rd /s /Q \"C:\\Users\\%USERNAME%\\AppData\\Roaming\\Battle.net\" \n";
        MyFile << "rd /s /Q \"C:\\Users\\%USERNAME%\\AppData\\Local\\Battle.net\" \n";
        MyFile << "rd /s /Q \"C:\\Users\\%USERNAME%\\AppData\\Local\\Blizzard Entertainment\" \n";
        MyFile << "rd /s /Q \"C:\\Users\\%USERNAME%\\AppData\\Local\\CrashDumps\" \n";
        MyFile << "rd /s /Q \"C:\\ProgramData\\Battle.net\" \n";
        MyFile << "rd /s /Q \"C:\\ProgramData\\Battle.net_components\" \n";
        MyFile << "rd /s /Q \"C:\\ProgramData\\Blizzard Entertainment\" \n";
        //These delete MW Tracer Reg Keys
        MyFile << "reg delete \"HKEY_CURRENT_USER\\SOFTWARE\\Blizzard Entertainment\" /f \n";
        MyFile << "reg delete \"HKEY_LOCAL_MACHINE\\SOFTWARE\\WOW6432Node\\Blizzard Entertainment\" /f \n";
        //This deletes the valorant anticheat (Riot Vanguard)
        MyFile << "rd /s /Q \"C:\\Program Files\\Riot Vanguard\" \n";

        // Close the file
        MyFile.close();

        //Run the BATCH file 
        system("C:\\temp\\Cleaner.bat");

        //Once finished, removes the BATCH file
        remove("C:\\temp\\Cleaner.bat");
        cout << "\n";
        system("pause");
        return 0;
    }
    else {
        return 0;
    }
}