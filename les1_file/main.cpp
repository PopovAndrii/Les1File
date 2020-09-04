#include <windows.h>

#include <iostream>

int main()
{
    /*
    std::wstring path_from = L"D:\\cpp_project\\NextLevel\\\Les1File\\.gitignore";
    std::wstring path_to = L"D:\\cpp_project\\NextLevel\\\Les1File\\.gitignore1";

    WIN32_FIND_DATA FileData;
    HANDLE          hSearch;
    TCHAR           szNewPath[MAX_PATH];

    // Start searching for text files in the current directory. 
    hSearch = FindFirstFile(TEXT("E:\\cpp_project\\NextLevel\\.gitignore"), &FileData);
    
    if (hSearch == INVALID_HANDLE_VALUE){
        printf("No text files found.\n");
    }

    if(CopyFile(path_from.c_str(), path_to.c_str(), FALSE)){
        printf("Copy file.\n");
    } else {
        printf("Could not copy file.\n");
    }

    FindClose(hSearch); */

    HANDLE hFile = 0;
    HANDLE hFile1 = 0;
    char DataBuffer[] = "This is some test data to write to the file.yu";
    DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
    DWORD dwBytesWritten = 0;
    BOOL bErrorFlag = FALSE;
    BOOL bErrorFlag1 = FALSE;

    hFile = CreateFileA("D:/cpp_project/NextLevel/Les1File/.gitignore", // name of the write
        GENERIC_WRITE | GENERIC_READ, // open for writing
        0,                      // do not share
        NULL,                   // default security
        OPEN_ALWAYS,            // create new file only
        FILE_ATTRIBUTE_NORMAL,  // normal file
        NULL);                  // no attr. template
 
    
    DWORD buf, tmp;
    bErrorFlag1 = ReadFile(
        hFile,
        &buf,
        sizeof(buf),
        &tmp,
        NULL
    );
    if (bErrorFlag1) { 
        std::cout << "Read \n"; 
    } else {
        std::cout << GetLastError() << "\n";
    }

    hFile1 = CreateFileA("D:/cpp_project/NextLevel/Les1File/.gitignore1",
        GENERIC_WRITE | GENERIC_READ,          // open for writing
        0,                      // do not share
        NULL,                   // default security
        CREATE_NEW,             // create new file only
        FILE_ATTRIBUTE_NORMAL,  // normal file
        NULL);                  // no attr. template

    bErrorFlag = WriteFile(
        hFile1,           // open file handle
        &buf,      // start of data to write
        sizeof(buf),  // number of bytes to write
        &dwBytesWritten, // number of bytes that were written
        NULL
    );
    if (bErrorFlag) std::cout << "Write \n";

    CloseHandle(hFile);
    CloseHandle(hFile1);


}
