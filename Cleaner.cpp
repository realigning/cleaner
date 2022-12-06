#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <filesystem>
#include <strsafe.h>
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

BOOL RegDelnodeRecurse(HKEY hKeyRoot, LPTSTR lpSubKey)
{
    LPTSTR lpEnd;
    LONG lResult;
    DWORD dwSize;
    TCHAR szName[MAX_PATH];
    HKEY hKey;
    FILETIME ftWrite;

    // First, see if we can delete the key without having
    // to recurse.

    lResult = RegDeleteKey(hKeyRoot, lpSubKey);

    if (lResult == ERROR_SUCCESS)
        return TRUE;

    lResult = RegOpenKeyEx(hKeyRoot, lpSubKey, 0, KEY_READ, &hKey);

    if (lResult != ERROR_SUCCESS)
    {
        if (lResult == ERROR_FILE_NOT_FOUND) {
            printf("Key not found.\n");
            return TRUE;
        }
        else {
            printf("Error opening key.\n");
            return FALSE;
        }
    }

    // Check for an ending slash and add one if it is missing.

    lpEnd = lpSubKey + lstrlen(lpSubKey);

    if (*(lpEnd - 1) != TEXT('\\'))
    {
        *lpEnd = TEXT('\\');
        lpEnd++;
        *lpEnd = TEXT('\0');
    }

    // Enumerate the keys

    dwSize = MAX_PATH;
    lResult = RegEnumKeyEx(hKey, 0, szName, &dwSize, NULL,
        NULL, NULL, &ftWrite);

    if (lResult == ERROR_SUCCESS)
    {
        do {

            *lpEnd = TEXT('\0');
            StringCchCat(lpSubKey, MAX_PATH * 2, szName);

            if (!RegDelnodeRecurse(hKeyRoot, lpSubKey)) {
                break;
            }

            dwSize = MAX_PATH;

            lResult = RegEnumKeyEx(hKey, 0, szName, &dwSize, NULL,
                NULL, NULL, &ftWrite);

        } while (lResult == ERROR_SUCCESS);
    }

    lpEnd--;
    *lpEnd = TEXT('\0');

    RegCloseKey(hKey);

    // Try again to delete the key.

    lResult = RegDeleteKey(hKeyRoot, lpSubKey);

    if (lResult == ERROR_SUCCESS)
        return TRUE;

    return FALSE;
}

BOOL RegDelnode(HKEY hKeyRoot, LPCTSTR lpSubKey)
{
    TCHAR szDelKey[MAX_PATH * 2];

    StringCchCopy(szDelKey, MAX_PATH * 2, lpSubKey);
    return RegDelnodeRecurse(hKeyRoot, szDelKey);

}

int main()
{
    int x;
    SetConsoleTitle(TEXT("Realigns Cleaner"));
    //Ask what would like to be done
    logo();
    time(); cout << " REALIGNS CALL OF DUTY CLEANER" << endl;
    time(); cout << " discord: realign#7085 \n\n";
    time(); cout << " What Would You Like To Do?" << endl;
    time(); cout << " [1] Run Clean" << endl;
    time(); cout << " [Else] Close App" << endl;
    time(); cout << " Enter the corresponding number: ";
    //User Input
    cin >> x;
    //If User Inputs 1
    if (x == 1)
    {
        cout << "\n";

        system("taskkill /im battle.net.exe /f >nul 2>&1");
        system("taskkill /im Agent.exe /f >nul 2>&1");
        system("sc stop vgk");
        system("taskkill /im ModernWarfare.exe /f >nul 2>&1");

        Sleep(2000);

        //Gets USERPROFILE
        std::filesystem::path userprofile = std::getenv("USERPROFILE");
        //Deletes Battle.net Directory (Program Data)
        std::uintmax_t a = filesystem::remove_all("C:\\ProgramData\\Battle.net");
        std::cout << "Deleted " << a << " files or directories\n";
        //Deletes Battle.net_components Directory
        std::uintmax_t b = filesystem::remove_all("C:\\ProgramData\\Battle.net_components");
        std::cout << "Deleted " << b << " files or directories\n";
        //Deletes Blizzard Entertainment Directory (Program Data)
        std::uintmax_t c = filesystem::remove_all("C:\\ProgramData\\Blizzard Entertainment");
        std::cout << "Deleted " << c << " files or directories\n";
        //Deletes Blizzard Entertainment Directory (Appdata)
        std::uintmax_t d = filesystem::remove_all(userprofile / "AppData\\Roaming\\Battle.net");
        std::cout << "Deleted " << d << " files or directories\n";
        //Deletes Blizzard Entertainment Directory (Appdata)
        std::uintmax_t e = filesystem::remove_all(userprofile / "AppData\\Local\\Blizzard Entertainment");
        std::cout << "Deleted " << e << " files or directories\n";
        //Deletes CrashDumps Directory 
        std::uintmax_t f = filesystem::remove_all(userprofile / "AppData\\Local\\CrashDumps");
        std::cout << "Deleted " << f << " files or directories\n";

        RegDelnode(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Blizzard Entertainment"));
        RegDelnode(HKEY_LOCAL_MACHINE, TEXT("SOFTWARE\\WOW6432Node\\Blizzard Entertainment"));

        cout << "\n";
        system("pause");

        return 0;
    }
    else {
        return 0;
    }
}