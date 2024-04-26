# .NET Version Enumeration Tool

## Description
This C++ program allows users to enumerate .NET versions installed on a Windows system using two different methods: checking the registry key and examining the `Microsoft.NET` folder. It provides information about each detected .NET version, allowing users to identify the installed versions easily.

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
