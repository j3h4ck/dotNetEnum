# .NET Version Enumeration Tool

## Description
This C++ program allows users to enumerate .NET versions installed on a Windows system using two different methods: checking the registry key and examining the `Microsoft.NET` folder. It provides information about each detected .NET version, allowing users to identify the installed versions easily.

## Output
```
D:\projects\dotNetEnum\x64\Release>.\dotNetEnum.exe

______      _   _   _      _  ______
|  _  \    | | | \ | |    | | |  _  \
| | | |___ | |_|  \| | ___| |_| | | |_   _ _ __ ___  _ __   ___ _ __
| | | / _ \| __| . ` |/ _ \ __| | | | | | | '_ ` _ \| '_ \ / _ \ '__|
| |/ / (_) | |_| |\  |  __/ |_| |/ /| |_| | | | | | | |_) |  __/ |
|___/ \___/ \__\_| \_/\___|\__|___/  \__,_|_| |_| |_| .__/ \___|_|
                                                    | |
                                                    |_|

                                           by : @j3h4ck


[*] Checking using registry key

[*] Found .NET Versions :
[+]      .NET  CDF
[+]      .NET  v2.0.50727
[+]      .NET  v3.0
[+]      .NET  v3.5
[+]      .NET  v4
[+]      .NET  v4.0

[*] Checking using Microsoft.NET folder

[*] Found .NET Versions :
[+]      .Net v2.0.50727
[+]      .Net v3.0
[+]      .Net v3.5
[+]      .Net v4.0.30319
```

## Usage
1. Clone this repository to your local machine.
2. Compile the `dotNetEnum.cpp` file using a C++ compiler. For example:
   ```bash
   g++ dotNetEnum.cpp -o dotNetEnum.exe
3. Run the compiled executable:
   ```bash
   dotNetEnum.exe
4. The program will display a banner and then proceed to enumerate .NET versions using both methods.
5. Review the output to see the detected .NET version

# Methodology
## Checking Registry Key
* Accesses the Windows registry key SOFTWARE\Microsoft\NET Framework Setup\NDP to retrieve information about installed .NET versions.
* Iterates through the subkeys under NDP to identify the installed .NET versions.
* Prints information about each detected .NET version.
## Checking Microsoft.NET Folder
* Searches the C:\Windows\Microsoft.NET\Framework64 directory to identify installed .NET versions.
* Prints information about each detected .NET version found in the fol
