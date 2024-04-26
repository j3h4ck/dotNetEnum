#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>

const char* banner = R"(
______      _   _   _      _  ______                                 
|  _  \    | | | \ | |    | | |  _  \                                
| | | |___ | |_|  \| | ___| |_| | | |_   _ _ __ ___  _ __   ___ _ __ 
| | | / _ \| __| . ` |/ _ \ __| | | | | | | '_ ` _ \| '_ \ / _ \ '__|
| |/ / (_) | |_| |\  |  __/ |_| |/ /| |_| | | | | | | |_) |  __/ |   
|___/ \___/ \__\_| \_/\___|\__|___/  \__,_|_| |_| |_| .__/ \___|_|   
                                                    | |              
                                                    |_|              

                                           by : @j3h4ck
)";

int checkDotNetReg() {
    HKEY hKey;
    std::wstring dotNetSetupKey = L"SOFTWARE\\Microsoft\\NET Framework Setup\\NDP";
    // Attempt to open the main .NET Framework Setup key
    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, dotNetSetupKey.c_str(), 0, KEY_READ, &hKey) != ERROR_SUCCESS) {
        std::cerr << "Error: Cannot open registry key.\n";
        return 1;
    }

    std::vector<std::wstring> dotNetVersions;

    // Enumerate subkeys under the main .NET Framework Setup key
    DWORD index = 0;
    printf("[*] Found .NET Versions : \n");
    while (true) {
        wchar_t subKeyName[MAX_PATH];
        DWORD subKeyNameSize = MAX_PATH;
        // Get the name of the subkey at the current index
        if (RegEnumKeyEx(hKey, index, subKeyName, &subKeyNameSize, NULL, NULL, NULL, NULL) != ERROR_SUCCESS) {
            break; // No more subkeys
        }
        // Null-terminate the subKeyName buffer
        subKeyName[subKeyNameSize] = L'\0';
        std::wstring versionKey = dotNetSetupKey + L"\\" + subKeyName;
        printf("[+]\t .NET  %S \n", subKeyName);
        dotNetVersions.push_back(versionKey);
        index++;
    }

    // Close the main .NET Framework Setup key
    RegCloseKey(hKey);

}
int checkDotNetFolder() {
    printf("[*] Found .NET Versions : \n");
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA("C:\\Windows\\Microsoft.NET\\Framework64\\*", &findData);
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("[-] Cannot get a handle to the folder");
        return 1;
    }
    do {
        if ((findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && strcmp(findData.cFileName, ".") != 0 && strcmp(findData.cFileName, "..") != 0) {
            printf("[+]\t .Net %s\n", findData.cFileName);
        }
    } while (FindNextFileA(hFind, &findData) != 0);
    FindClose(hFind);
    return 0;
}

int main() {
    printf("%s\n\n", banner);
    printf("[*] Checking using registry key\n\n");
    checkDotNetReg();
    printf("\n");
    printf("[*] Checking using Microsoft.NET folder\n\n");
    checkDotNetFolder();
}
